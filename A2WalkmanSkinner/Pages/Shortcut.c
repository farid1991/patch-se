#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\FilesList.h"
#include "..\\Function.h"
#include "..\\LNG.h"
#include "..\\main.h"

#include "Shortcut.h"

void SoftkeyFree(void *item)
{
  SOFTKEY_LIST_ELEM *elem = (SOFTKEY_LIST_ELEM *)item;
  if (elem)
  {
    elem->action = NULL;
    elem->textid = NULL;
    mfree(elem);
  }
}

SOFTKEY_LIST_ELEM *CreateElem(SOFTKEY_DESC_A2 *SoftkeyDesc)
{
  SOFTKEY_LIST_ELEM *elem = (SOFTKEY_LIST_ELEM *)malloc(sizeof(SOFTKEY_LIST_ELEM));
  elem->action = SoftkeyDesc->action;
  elem->textid = SoftkeyDesc->ButtonText;
  return elem;
}

LIST *Create_SoftkeyList(LIST *slist)
{
  LIST *SoftkeyList = List_Create();

  for (int index = 0; index < List_GetCount(slist); index++)
  {
    SOFTKEY_DESC_A2 *SoftkeyDesc = (SOFTKEY_DESC_A2 *)List_Get(slist, index);

    if (SoftkeyDesc->visible && SoftkeyDesc->enable &&
        SoftkeyDesc->ButtonText != EMPTY_TEXTID &&
        SoftkeyDesc->ButtonText != TEXTID_SPACE)
    {
      List_InsertLast(SoftkeyList, CreateElem(SoftkeyDesc));
    }
  }

  return SoftkeyList;
}

void GetData(void *mydata, int size)
{
  int file = _fopen(FILE_PATH, SC_CONFIG_NAME, FSX_O_CREAT | FSX_O_APPEND, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
  if (file >= 0)
  {
    fread(file, mydata, size);
    fclose(file);
  }
}

void WriteData(u16 key_id, u16 action_id)
{
  FILE_DATA *fdata = (FILE_DATA *)malloc(sizeof(FILE_DATA));
  memset(fdata, 0xFF, sizeof(FILE_DATA));
  GetData(fdata, sizeof(FILE_DATA));

  fdata->action[key_id] = action_id;

  int file = _fopen(FILE_PATH, SC_CONFIG_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
  if (file >= 0)
  {
    fwrite(file, fdata, sizeof(FILE_DATA));
    fclose(file);
  }
  mfree(fdata);
}

int GetChecked(LIST *list, int item_pos)
{
  int ret = 0;

  FSTAT _fstat;
  int file = fstat(FILE_PATH, SC_CONFIG_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA *)malloc(size);
    GetData(mydata, size);

    for (int i = 0; i < List_GetCount(list); i++)
    {
      SOFTKEY_LIST_ELEM *elem = (SOFTKEY_LIST_ELEM *)List_Get(list, i);
      if (mydata->action[item_pos] == elem->action)
      {
        ret = i;
        break;
      }
    }
    mfree(mydata);
  }
  return ret;
}

TEXTID GetSecondLine(LIST *list, int item_num)
{
  int index = GetChecked(list, item_num);
  SOFTKEY_LIST_ELEM *elem = (SOFTKEY_LIST_ELEM *)List_Get(list, index);
  if (elem)
    return elem->textid;
  return EMPTY_TEXTID;
}

int GetKeyID(int key)
{
  return key - KEY_DIGITAL_0;
}

TEXTID Get_Menu_Text(int item)
{
  TEXTID txt[3];
  txt[0] = STR(TXT_BUTTON);
  txt[1] = TEXTID_SPACE;
  txt[2] = TextID_CreateIntegerID(item);

  return TextID_Create(txt, ENC_TEXTID, 3);
}

void SelectShortcut_onSelect_Item(BOOK *book, GUI *gui)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  int item = OneOfMany_GetSelected(pShortcutBook->SubMenu);

  SOFTKEY_LIST_ELEM *elem = (SOFTKEY_LIST_ELEM *)List_Get(pShortcutBook->SoftkeyList, item);
  WriteData(pShortcutBook->CurrentItem, elem->action);

  BookObj_ReturnPage(pShortcutBook, ACCEPT_EVENT);
  ListMenu_DestroyItems(pShortcutBook->MainMenu);
  pg_MusicApplication_Shortcut_EnterAction(NULL, pShortcutBook);
}

void SelectShortcut_onPrevAction(BOOK *book, GUI *gui)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  BookObj_ReturnPage(pShortcutBook, ACCEPT_EVENT);
}

void Shortcut_CancelAction(BOOK *book, GUI *gui)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  FreeBook(pShortcutBook);
}

int SelectShortcut_onMessage(GUI_MESSAGE *msg)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    SOFTKEY_LIST_ELEM *elem = (SOFTKEY_LIST_ELEM *)List_Get(pShortcutBook->SoftkeyList, index);
    GUIonMessage_SetMenuItemText(msg, elem->textid);
  }
  return 1;
}

int pg_MusicApplication_SelectShortcut_PrevAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  BookObj_ReturnPage(pShortcutBook, ACCEPT_EVENT);
  return 1;
}

int pg_MusicApplication_SelectShortcut_EnterAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;

  if (pShortcutBook->SubMenu = CreateOneOfMany(pShortcutBook))
  {
    GUIObject_SetTitleText(pShortcutBook->SubMenu, Get_Menu_Text(pShortcutBook->CurrentItem));
    GUIObject_SetStyle(pShortcutBook->SubMenu, UI_OverlayStyle_PopupFrame);
    OneOfMany_SetChecked(pShortcutBook->SubMenu, GetChecked(pShortcutBook->SoftkeyList, pShortcutBook->CurrentItem));
    OneOfMany_SetItemCount(pShortcutBook->SubMenu, List_GetCount(pShortcutBook->SoftkeyList));
    OneOfMany_SetOnMessage(pShortcutBook->SubMenu, SelectShortcut_onMessage);
    GUIObject_SoftKeys_SetAction(pShortcutBook->SubMenu, ACTION_SELECT1, SelectShortcut_onSelect_Item);
    GUIObject_SoftKeys_SetAction(pShortcutBook->SubMenu, ACTION_BACK, SelectShortcut_onPrevAction);
    GUIObject_SoftKeys_SetAction(pShortcutBook->SubMenu, ACTION_LONG_BACK, Shortcut_CancelAction);
    GUIObject_Show(pShortcutBook->SubMenu);
  }
  return 1;
}

int pg_MusicApplication_SelectShortcut_ExitAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  DESTROY_GUI(pShortcutBook->SubMenu);
  return 1;
}

void Shortcut_EnterAction(BOOK *book, GUI *gui)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  pShortcutBook->CurrentItem = ListMenu_GetSelectedItem(pShortcutBook->MainMenu);
  BookObj_CallPage(pShortcutBook, &MusicApplication_SelectShortcut_Page);
}

int Shortcut_OnMessage(GUI_MESSAGE *msg)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, Get_Menu_Text(index));
    GUIonMessage_SetMenuItemSecondLineText(msg, GetSecondLine(pShortcutBook->SoftkeyList, index));
    break;
  }
  return 1;
}

int pg_MusicApplication_Shortcut_EnterAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;

  if (pShortcutBook->MainMenu = CreateListMenu(pShortcutBook, UIDisplay_Main))
  {
    GUIObject_SetTitleText(pShortcutBook->MainMenu, TEXT_SHORTCUT);
    GUIObject_SetStyle(pShortcutBook->MainMenu, UI_OverlayStyle_Default);
    ListMenu_SetItemCount(pShortcutBook->MainMenu, Item_Key_Last);
    ListMenu_SetItemStyle(pShortcutBook->MainMenu, 3);
    ListMenu_SetCursorToItem(pShortcutBook->MainMenu, pShortcutBook->CurrentItem);
    ListMenu_SetHotkeyMode(pShortcutBook->MainMenu, LKHM_SHORTCUT);
    ListMenu_SetOnMessage(pShortcutBook->MainMenu, Shortcut_OnMessage);
    GUIObject_SoftKeys_SetAction(pShortcutBook->MainMenu, ACTION_SELECT1, Shortcut_EnterAction);
    GUIObject_SoftKeys_SetAction(pShortcutBook->MainMenu, ACTION_BACK, Shortcut_CancelAction);
    GUIObject_SoftKeys_SetAction(pShortcutBook->MainMenu, ACTION_LONG_BACK, Shortcut_CancelAction);
    GUIObject_Show(pShortcutBook->MainMenu);
  }
  return 1;
}

int pg_MusicApplication_Shortcut_ExitAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  DESTROY_GUI(pShortcutBook->MainMenu);
  return 1;
}

int pg_MusicApplication_Shortcut_PrevAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  BookObj_ReturnPage(pShortcutBook, PREVIOUS_EVENT);
  return 1;
}

int pg_MusicApplication_Shortcut_CancelAction(void *data, BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;
  BookObj_ReturnPage(pShortcutBook, CANCEL_EVENT);
  return 1;
}

void MusicApplication_Shortcut_Destroy(BOOK *book)
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)book;

  FreeList(pShortcutBook->SoftkeyList, SoftkeyFree);
  pShortcutBook->CurrentItem = NULL;

  DESTROY_GUI(pShortcutBook->MainMenu);
  DESTROY_GUI(pShortcutBook->SubMenu);
}

MusicApplication_Shortcut_Book *Create_MusicApplication_Shortcut_Book()
{
  MusicApplication_Shortcut_Book *pShortcutBook = (MusicApplication_Shortcut_Book *)malloc(sizeof(MusicApplication_Shortcut_Book));
  memset(pShortcutBook, NULL, sizeof(MusicApplication_Shortcut_Book));

  int mbk = CreateBook(pShortcutBook, MusicApplication_Shortcut_Destroy, &MusicApplication_Shortcut_Base_Page, MusicShortcutBookName, NO_BOOK_ID, NULL);
  if (!mbk)
  {
    mfree(pShortcutBook);
    return NULL;
  }
  pShortcutBook->MainMenu = NULL;
  pShortcutBook->SubMenu = NULL;
  pShortcutBook->SoftkeyList = NULL;
  pShortcutBook->CurrentItem = NULL;
  return pShortcutBook;
}

void Call_ShortcutPage(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  pMusicBook->Callpage = TRUE;
  DISP_OBJ *disp_obj = GUIObject_GetDispObject(pMusicBook->Gui_NowPlaying);
  MusicApplication_Shortcut_Book *pShortcutBook = Create_MusicApplication_Shortcut_Book();
  if (pShortcutBook)
  {
    LIST *SoftkeyList = DispObject_SoftKeys_GetList(disp_obj, pMusicBook, NULL);
    pShortcutBook->SoftkeyList = Create_SoftkeyList(SoftkeyList);
    BookObj_GotoPage(pShortcutBook, &MusicApplication_Shortcut_Main_Page);
  }
}

void execute_shortcut(BOOK *book, char key, int mode)
{
  if (mode == KBD_SHORT_RELEASE)
  {
    MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
    u16 actionID = NO_ACTION;
    char key_id = GetKeyID(key);

    FSTAT _fstat;
    int file = fstat(FILE_PATH, SC_CONFIG_NAME, &_fstat);
    if (file >= 0)
    {
      int size = _fstat.fsize;
      FILE_DATA *mydata = (FILE_DATA *)malloc(size);
      GetData(mydata, size);
      actionID = mydata->action[key_id];
      mfree(mydata);
    }
    if (actionID != NO_ACTION)
    {
      GUIObject_SoftKeys_ExecuteAction(pMusicBook->Gui_NowPlaying, actionID);
    }
  }
}

extern "C" void New_Music_Gui_NowPlaying_OnKey(BOOK *book, int key, int repeat, int mode, void *unk)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  switch (key)
  {
  case KEY_DIGITAL_0:
  case KEY_DIGITAL_1:
  case KEY_DIGITAL_2:
  case KEY_DIGITAL_3:
  case KEY_DIGITAL_4:
  case KEY_DIGITAL_5:
  case KEY_DIGITAL_6:
  case KEY_DIGITAL_7:
  case KEY_DIGITAL_8:
  case KEY_DIGITAL_9:
    execute_shortcut(pMusicBook, key, mode);
    break;
  case KEY_DIEZ:
    if (mode == KBD_SHORT_RELEASE)
    {
      MusicApplication_Minimize(pMusicBook, NULL);
    }
    else if (mode == KBD_LONG_PRESS)
    {
      MusicApplication_CancelAction(pMusicBook, NULL);
    }
    break;
  default:
    MusicApplication_Keyboard(pMusicBook, key, repeat, mode, unk);
    break;
  }
}
