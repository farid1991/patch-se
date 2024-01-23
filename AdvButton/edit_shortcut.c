#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "bookman.h"
#include "edit_shortcut.h"
#include "main.h"

IMAGEID GetDigitIcon(int index)
{
  return (IDN_DIGIT_0_ICON + index);
}

void Shortcut_Append(wchar_t *name_buf, char *mask_buf, wchar_t *path)
{
  int file = _fopen(path, INI_SHORTCUTS, FSX_O_CREAT | FSX_O_APPEND, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= NULL)
  {
    int size = strlen(mask_buf) + wstrlen(name_buf) + 4;
    char *temp_buf = (char *)malloc(size);
    strcpy(temp_buf, mask_buf);
    strcat(temp_buf, " ");
    wstr2strn(temp_buf + strlen(temp_buf), name_buf, wstrlen(name_buf));
    strcat(temp_buf, "\r\n");
    fwrite(file, temp_buf, strlen(temp_buf));
    fclose(file);
    mfree(temp_buf);
  }
}

void ReWriteShortcut(BOOK *book, wchar_t *name_buf, char *mask_buf, wchar_t *path)
{
  BookManager *bookman = (BookManager *)FindBook(IsBookManager);
  int file;
  char *pos;

  if (bookman->shortcuts_buf)
  {
    char *param = manifest_GetParam(bookman->shortcuts_buf, mask_buf, NULL);

    int len = wstrlen(name_buf);
    char *str_buf = (char *)malloc(len + 1);
    wstr2strn(str_buf, name_buf, len);
    int len_prefix = strlen(mask_buf) + 1;
    if (param)
    {
      pos = strstr(bookman->shortcuts_buf, mask_buf);
      if ((file = _fopen(path, INI_SHORTCUTS, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= NULL)
      {
        int len_minus = strlen(param);                                                                                                       //????? ??????? ??????
        fwrite(file, bookman->shortcuts_buf, pos - bookman->shortcuts_buf + len_prefix);                                                     //????? ?????? ?????
        fwrite(file, str_buf, len);                                                                                                          //????? ????? ?????
        fwrite(file, pos + len_prefix + len_minus, (bookman->shortcuts_buf_size - (pos - bookman->shortcuts_buf + len_prefix)) - len_minus); //????? ??????? ?????
        fclose(file);
      }
      mfree(param);
    }
    else
    {
      if (pos = strstr(bookman->shortcuts_buf, mask_buf))
      {
        if ((file = _fopen(path, INI_SHORTCUTS, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= NULL)
        {
          fwrite(file, bookman->shortcuts_buf, pos - bookman->shortcuts_buf + len_prefix);
          fwrite(file, str_buf, len);
          fwrite(file, pos + len_prefix, bookman->shortcuts_buf_size - (pos - bookman->shortcuts_buf + len_prefix));
          fclose(file);
        }
      }
      else
      {
        Shortcut_Append(name_buf, mask_buf, path);
      }
    }
    mfree(str_buf);
  }
  else
  {
    Shortcut_Append(name_buf, mask_buf, path);
  }
}

void WriteShortcut(wchar_t *name_buf)
{
  BookManager *bookman = (BookManager *)FindBook(IsBookManager);

  int dig_num = ListMenu_GetSelectedItem(bookman->button_list_menu);

  char mask_buf[16];
  sprintf(mask_buf, KEY_MASK, dig_num);
  ReWriteShortcut(bookman, name_buf, mask_buf, BOOKMAN_PATH);

  LoadShortcuts(bookman);
}

void JAVA_LIST_ITEM_Destroy(void *item)
{
  JAVA_LIST_ITEM *elem = (JAVA_LIST_ITEM *)item;
  if (!elem)
    return;

  mfree(elem->name);
  mfree(elem->vendor);
  mfree(elem->fullpath);
  mfree(elem->hash_name);
  if (elem->imageID != NOIMAGE)
    ImageID_Free(elem->imageID);
  mfree(elem);
}

BOOL JAVA_LIST_ITEM_Filter(void *elem)
{
  return (elem ? TRUE : FALSE);
}

JAVA_LIST_ITEM *CreateElem(void *JavaDesc)
{
  JAVA_LIST_ITEM *elem = (JAVA_LIST_ITEM *)malloc(sizeof(JAVA_LIST_ITEM));
  wchar_t *buf;
  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_NAME, &buf);
  elem->name = buf;
  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_VENDOR, &buf);
  elem->vendor = buf;
  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_FULLPATH, &buf);
  elem->fullpath = buf;
  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_HASH, &buf);
  elem->hash_name = buf;
  return elem;
}

void DestroyJavaList(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->java_list)
  {
    List_DestroyElements(bookman->java_list, JAVA_LIST_ITEM_Filter, JAVA_LIST_ITEM_Destroy);
    List_Destroy(bookman->java_list);
    bookman->java_list = NULL;
  }
}

void CreateJavaList(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  bookman->java_list = List_Create();
  char jdialog;
  wchar_t *semclet;
  void *JavaDesc;
  JavaDialog_Open(0, &jdialog, &JavaDesc);

  if (!JavaAppDesc_GetFirstApp(JavaDesc))
  {
    int result = 0;
    while (!result)
    {
      // check if semclet
      JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_SEMCLET, &semclet);
      if (semclet[0])
      {
        List_InsertLast(bookman->java_list, CreateElem(JavaDesc));
      }
      mfree(semclet);
      result = JavaAppDesc_GetNextApp(JavaDesc);
    }
  }

  JavaDialog_Close(jdialog);
}

void JavaList_GetInfo(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;

  int index = ListMenu_GetSelectedItem(bookman->java_list_menu);
  JAVA_LIST_ITEM *elem = (JAVA_LIST_ITEM *)List_Get(bookman->java_list, index);

  wchar_t buf[128];
  snwprintf(buf, MAXELEMS(buf), L"Name: %ls\nVendor: %ls\nPath: %ls", elem->name, elem->vendor, elem->fullpath);
  CreateMessageBox(STR("Java Info"), TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN), 2, 0, bookman);
}

void JavaList_Prev_Action(BOOK *book, GUI *gui)
{
  BookObj_ReturnPage(book, NIL_EVENT);
}

void JavaList_Cancel_Action(BOOK *book, GUI *gui)
{
  BookObj_ReturnPage(book, CANCEL_EVENT);
}

void JavaList_Select_Action(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  int index = ListMenu_GetSelectedItem(bookman->java_list_menu);
  JAVA_LIST_ITEM *elem = (JAVA_LIST_ITEM *)List_Get(bookman->java_list, index);

  int java_buf_len = wstrlen(elem->name) + wstrlen(elem->hash_name) + 10;
  wchar_t *java_buf = (wchar_t *)malloc(sizeof(wchar_t) * java_buf_len);
  snwprintf(java_buf, java_buf_len, L"java:%ls//%ls", elem->name, elem->hash_name);

  WriteShortcut(java_buf);
  mfree(java_buf);
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
}

int SelectJavaApps_onMessage(GUI_MESSAGE *msg)
{
  BookManager *bookman = (BookManager *)GUIonMessage_GetBook(msg);

  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    JAVA_LIST_ITEM *elem = (JAVA_LIST_ITEM *)List_Get(bookman->java_list, index);
    JavaApp_LogoImageID_Get(elem->fullpath, &elem->imageID);
    GUIonMessage_SetMenuItemText(msg, TextID_Create(elem->name, ENC_UCS2, TEXTID_ANY_LEN));
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->imageID);
  }
  return 1;
}

int SelectJavaApps_Enter_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  DestroyJavaList(bookman);
  CreateJavaList(bookman);
  FREE_GUI(bookman->java_list_menu);

  if (bookman->java_list_menu = CreateListMenu(bookman, UIDisplay_Main))
  {
    GUIObject_SetTitleText(bookman->java_list_menu, DB_APPLICATIONS_TXT);
    ListMenu_SetItemCount(bookman->java_list_menu, List_GetCount(bookman->java_list));
    ListMenu_SetOnMessage(bookman->java_list_menu, SelectJavaApps_onMessage);
    ListMenu_SetCursorToItem(bookman->java_list_menu, 0);
    GUIObject_SoftKeys_SetText(bookman->java_list_menu, 0, STR("JavaInfo"));
    GUIObject_SoftKeys_SetAction(bookman->java_list_menu, 0, JavaList_GetInfo);
    GUIObject_SoftKeys_SetAction(bookman->java_list_menu, ACTION_BACK, JavaList_Prev_Action);
    GUIObject_SoftKeys_SetAction(bookman->java_list_menu, ACTION_LONG_BACK, JavaList_Cancel_Action);
    GUIObject_SoftKeys_SetAction(bookman->java_list_menu, ACTION_SELECT1, JavaList_Select_Action);
    GUIObject_Show(bookman->java_list_menu);
  }
  return 1;
}

int SelectJavaApps_Exit_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->java_list_menu);
  DestroyJavaList(bookman);
  return 1;
}

void *SHORTCUT_DESC_Init(char *param)
{
  SHORTCUT_DESC *w_buf = (SHORTCUT_DESC *)malloc(sizeof(SHORTCUT_DESC));
  memset(w_buf, NULL, sizeof(w_buf));
  w_buf->shortcut_state = SC_State_Activated;

  if (strlen(param) < 0x32)
  {
    str2wstr(w_buf->name, param);
  }
  else
  {
    char temp_buf[0x32];
    strncpy(temp_buf, param, MAXELEMS(temp_buf) - 1);
    temp_buf[MAXELEMS(temp_buf) - 1] = NULL;
    str2wstr(w_buf->name, temp_buf);
  }
  if (!wstrcmp(w_buf->name, MAINMENU_ID))
    w_buf->shortcut_state = SC_State_MainMenu;
  return (w_buf);
}

void SelectShortcut_SetAction(BOOK *MainMenu, GUI *gui)
{
  BookManager *bookman = (BookManager *)FindBook(IsBookManager);
  wchar_t *name_buf = MenuBook_Desktop_GetSelectedItemID(MainMenu);
  if (name_buf)
  {
    WriteShortcut(name_buf);
    mfree(name_buf);
  }
  FreeBook(MainMenu);
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
}

int SelectShortcut_Prev_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, NIL_EVENT);
  return 1;
}

int SelectShortcut_Cancel_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, CANCEL_EVENT);
  return 1;
}

int SelectShortcut_Enter_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *MainMenu = MenuBook_Desktop(1, BookObj_GetBookID(bookman));
  if (MainMenu)
  {
    bookman->MainMenuID = BookObj_GetBookID(MainMenu);
    BookObj_SoftKeys_SetAction(MainMenu, 0, SelectShortcut_SetAction);
    BookObj_SoftKeys_SetText(MainMenu, 0, SHORTCUT_TXT);
    return 1;
  }
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
  return 0;
}

void ButtonList_SetMainMenu(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  wchar_t name_buf[20];
  wstrcpy(name_buf, MAINMENU_ID);
  WriteShortcut(name_buf);
  ButtonList_Enter_Event(NULL, bookman);
}

void ButtonList_SetJava(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_CallPage(bookman, &ChangeShortcuts_SelectJavaApps_Page);
}

void ButtonList_SelectAction(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_CallPage(bookman, &ChangeShortcuts_SelectShortcut_Page);
}

void ButtonList_CancelAction(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, CANCEL_EVENT);
}

void ButtonList_PreviousAction(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, PREVIOUS_EVENT);
}

int GetShortcutNameData(BOOK *book, int item_num, SC_DATA *scdata)
{
  BookManager *bookman = (BookManager *)book;

  char *param = 0;
  char mask_buf[10];
  sprintf(mask_buf, KEY_MASK, item_num);
  param = manifest_GetParam(bookman->shortcuts_buf, mask_buf, NULL);

  if (param)
  {
    if (strlen(param))
    {
      if (!scdata)
      {
        mfree(param);
        return 1;
      }

      if (strstr(param, JAVA_MASK))
      {
        scdata->str_id = TextID_Create(param + 5, ENC_LAT1, strstr(param, "//") - (param + 5));
        scdata->icon_id = DB_LIST_JAVA_ICN;
      }
      else
      {
        void *w_buf = SHORTCUT_DESC_Init(param);

        scdata->str_id = Shortcut_Get_MenuItemName(w_buf);

#if defined(W700_R1CA021) || defined(W800_R1BD001)
        scdata->icon_id = RN_VERT_MY_SHORTCUTS_ICN;
#else
        scdata->icon_id = Shortcut_Get_MenuItemIconID(w_buf);
#endif
        if (scdata->str_id == EMPTY_TEXTID)
          scdata->str_id = TextID_Create(param, ENC_LAT1, TEXTID_ANY_LEN);

        mfree(w_buf);
      }
    }
    mfree(param);
  }
  else
  {
    if (!scdata)
      return 0;
    scdata->str_id = EMPTY_LIST_TXT;
  }
  return 0;
}

int DeleteShortcut(BOOK *book, char *mask_buf, int file)
{
  BookManager *bookman = (BookManager *)book;
  char *pos;
  char *param = 0;
  int res = 0;

  if (bookman->shortcuts_buf)
  {
    param = manifest_GetParam(bookman->shortcuts_buf, mask_buf, NULL);
    if (param)
    {
      int len_minus = strlen(param);
      if (len_minus > 0)
      {
        pos = strstr(bookman->shortcuts_buf, mask_buf);
        int len_prefix = strlen(mask_buf) + 1;
        fwrite(file, bookman->shortcuts_buf, pos - bookman->shortcuts_buf + len_prefix);
        fwrite(file, pos + len_prefix + len_minus, bookman->shortcuts_buf_size - (pos - bookman->shortcuts_buf + len_prefix) - len_minus);
        res = 1;
      }
      mfree(param);
    }
  }
  return res;
}

void ButtonList_DeleteAction(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  int file;
  int res;
  int dig_num = ListMenu_GetSelectedItem(bookman->button_list_menu);
  if (!GetShortcutNameData(bookman, dig_num, NULL))
    return;

  if ((file = _fopen(BOOKMAN_PATH, INI_SHORTCUTS, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= NULL)
  {
    char mask_buf[16];
    sprintf(mask_buf, KEY_MASK, dig_num);
    res = DeleteShortcut(bookman, mask_buf, file);
    fclose(file);
    if (res)
    {
      LoadShortcuts(bookman);
      ButtonList_Enter_Event(NULL, bookman);
    }
  }
}

int ButtonList_onMessage(GUI_MESSAGE *msg)
{
  SC_DATA scdata;
  scdata.str_id = EMPTY_TEXTID;
  scdata.icon_id = NOIMAGE;
  int item_num;
  BookManager *bookman = (BookManager *)GUIonMessage_GetBook(msg);

  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    item_num = GUIonMessage_GetCreatedItemIndex(msg);
    GetShortcutNameData(bookman, item_num, &scdata);

    GUIonMessage_SetMenuItemText(msg, scdata.str_id);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, GetDigitIcon(item_num));
    GUIonMessage_SetMenuItemIcon(msg, AlignCenter, scdata.icon_id);
    break;
  }
  return 1;
}

int ButtonList_Enter_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  int index = 0;

  if (bookman->button_list_menu)
  {
    index = ListMenu_GetSelectedItem(bookman->button_list_menu);
    FREE_GUI(bookman->button_list_menu);
  }

  if (bookman->button_list_menu = CreateListMenu(bookman, UIDisplay_Main))
  {
    GUIObject_SetTitleText(bookman->button_list_menu, SHORTCUTS_TXT);
    ListMenu_SetItemCount(bookman->button_list_menu, 10);
    ListMenu_SetOnMessage(bookman->button_list_menu, ButtonList_onMessage);
    ListMenu_SetCursorToItem(bookman->button_list_menu, index);
    GUIObject_SoftKeys_SetAction(bookman->button_list_menu, ACTION_BACK, ButtonList_PreviousAction);
    GUIObject_SoftKeys_SetAction(bookman->button_list_menu, ACTION_LONG_BACK, ButtonList_CancelAction);
    GUIObject_SoftKeys_SetAction(bookman->button_list_menu, ACTION_SELECT1, ButtonList_SelectAction);
    GUIObject_SoftKeys_SetAction(bookman->button_list_menu, ACTION_DELETE, ButtonList_DeleteAction);
    GUIObject_SoftKeys_SetVisible(bookman->button_list_menu, ACTION_DELETE, FALSE);

    GUIObject_SoftKeys_SetAction(bookman->button_list_menu, 0, ButtonList_SetMainMenu);
    GUIObject_SoftKeys_SetText(bookman->button_list_menu, 0, SET_MAINMENU_TXT);
    GUIObject_SoftKeys_SetAction(bookman->button_list_menu, 1, ButtonList_SetJava);
    GUIObject_SoftKeys_SetText(bookman->button_list_menu, 1, DB_APPLICATIONS_TXT);

    GUIObject_Show(bookman->button_list_menu);
  }
  return 1;
}

int ButtonList_Exit_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->button_list_menu);
  if (bookman->MainMenuID != NO_BOOK_ID)
  {
    BOOK *MainMenu = FindBookByID(bookman->MainMenuID);
    if (MainMenu)
      FreeBook(MainMenu);
    bookman->MainMenuID = NO_BOOK_ID;
  }
  return 1;
}

int ButtonList_Cancel_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
  return 1;
}
