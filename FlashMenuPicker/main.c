#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "file_list.h"
#include "main.h"

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, MEM_NAME, NULL);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, MEM_NAME, NULL);
#else
  return memalloc(size, 1, 5, MEM_NAME, NULL);
#endif
}

void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, MEM_NAME, NULL);
#elif defined(A2)
    memfree(NULL, mem, MEM_NAME, NULL);
#else
    memfree(mem, MEM_NAME, NULL);
#endif
}

#if defined(W550_R4CB020) || defined(W900_R5BC004)
BOOL FSX_IsFileExists(const wchar_t *fpath, const wchar_t *fname)
{
  FSTAT fs;
  return fstat(fpath, fname, &fs) == 0;
}
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void Set_SWF_AsFlashMenu(const wchar_t *fpath, const wchar_t *fname, int *error)
{
  FileDelete(SETTINGS_PATH, FD_IMAGE, NULL);
  ThemeImage_Apply(fpath, fname, SETTINGS_PATH, FD_IMAGE, NULL, NULL);
}
#endif

int FlashMenuPicker_Pick_OnMessage(GUI_MESSAGE *msg)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    FILELIST_ELEM *flist = (FILELIST_ELEM *)List_Get(fmbk->flist, index);
    TEXTID text_id = TextID_Create(flist->name, ENC_UCS2, TEXTID_ANY_LEN);
    GUIonMessage_SetMenuItemText(msg, text_id);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_FLASH_ICN);
    break;
  }
  return 1;
}

void FlashMenuPicker_Pick_Select(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  int item = ListMenu_GetSelectedItem(fmbk->sub_menu);
  TEXTID text_id;

  FILELIST_ELEM *flist = (FILELIST_ELEM *)List_Get(fmbk->flist, item);
  if (flist)
  {
    if (FSX_IsFileExists(DEFAULT_FLASH_PATH, CUSTOM_NAME))
    {
      FileDelete(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }

    if (fmbk->type == ITEM_SYS)
    {
      FileCopy(DEFAULT_FLASH_PATH, flist->filename, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }
    else if (fmbk->type == ITEM_INT)
    {
      FileCopy(INT_FLASH_PATH, flist->filename, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }
#ifdef EXT_FLASH_PATH
    else if (fmbk->type == ITEM_EXT)
    {
      FileCopy(EXT_FLASH_PATH, flist->filename, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }
#endif

    Set_SWF_AsFlashMenu(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
    MainMenu_SetFromUserTheme(TRUE);
#endif

    text_id = TextID_Create(flist->name, ENC_UCS2, TEXTID_ANY_LEN);
    MessageBox(EMPTY_TEXTID, text_id, DB_FLASH_ICN, 1, 1000, fmbk);
  }
  else
  {
    text_id = TextID_Create(L"Can not set SWF as Flash Menu", ENC_UCS2, TEXTID_ANY_LEN);
    MessageBox(EMPTY_TEXTID, text_id, DB_FLASH_ICN, 1, 1000, fmbk);
  }
  FreeBook(fmbk);
}

void FlashMenuPicker_Pick_Preview(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  int item = ListMenu_GetSelectedItem(fmbk->sub_menu);

  FILELIST_ELEM *flist = (FILELIST_ELEM *)List_Get(fmbk->flist, item);
  if (flist)
  {
    char *uri;
    char *uri_scheme = GetURIScheme(file);
    if (fmbk->type == ITEM_SYS)
    {
      uri = CreateURI(DEFAULT_FLASH_PATH, flist->filename, uri_scheme);
    }
    else if (fmbk->type == ITEM_INT)
    {
      uri = CreateURI(INT_FLASH_PATH, flist->filename, uri_scheme);
    }
#ifdef EXT_FLASH_PATH
    else if (fmbk->type == ITEM_EXT)
    {
      uri = CreateURI(EXT_FLASH_PATH, flist->filename, uri_scheme);
    }
#endif
    if (Browser_OpenURI(NULL, uri, URI_MODE))
    {
      BookObj_ReturnPage(fmbk, PREVIOUS_EVENT);
    }
    FreeURI(uri);
  }
}

void FlashMenuPicker_Pick_Exit(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  file_list_destroy(fmbk->flist, file_list_remove_item);
  BookObj_ReturnPage(fmbk, PREVIOUS_EVENT);
}

int pg_FlashMenuPicker_Pick_EnterEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->sub_menu);

  if (fmbk->flist)
  {
    file_list_destroy(fmbk->flist, file_list_remove_item);
  }

  if (fmbk->type == ITEM_SYS)
  {
    fmbk->flist = file_list_create(DEFAULT_FLASH_PATH);
  }
  else if (fmbk->type == ITEM_INT)
  {
    fmbk->flist = file_list_create(INT_FLASH_PATH);
  }
#ifdef EXT_FLASH_PATH
  else if (fmbk->type == ITEM_EXT)
  {
    fmbk->flist = file_list_create(EXT_FLASH_PATH);
  }
#endif
  int count = List_GetCount(fmbk->flist);

  if (fmbk->sub_menu = CreateListMenu(fmbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(fmbk->sub_menu, SUBMENU_TXT);
    ListMenu_SetItemCount(fmbk->sub_menu, count);
    ListMenu_SetCursorToItem(fmbk->sub_menu, 0);
    ListMenu_SetOnMessage(fmbk->sub_menu, FlashMenuPicker_Pick_OnMessage);
    ListMenu_SetHotkeyMode(fmbk->sub_menu, LKHM_SHORTCUT);
    ListMenu_SetItemTextScroll(fmbk->sub_menu, 1);
#if defined(DB2020) || defined(A2)
    ListMenu_SetNoItemText(fmbk->sub_menu, EMPTY_LIST_TXT);
#endif
    if (count)
    {
      GUIObject_SoftKeys_SetText(fmbk->sub_menu, 0, PREVIEW_SK_TXT);
      GUIObject_SoftKeys_SetAction(fmbk->sub_menu, 0, FlashMenuPicker_Pick_Preview);
      GUIObject_SoftKeys_SetAction(fmbk->sub_menu, ACTION_SELECT1, FlashMenuPicker_Pick_Select);
    }
    GUIObject_SoftKeys_SetAction(fmbk->sub_menu, ACTION_BACK, FlashMenuPicker_Pick_Exit);
    GUIObject_SoftKeys_SetAction(fmbk->sub_menu, ACTION_LONG_BACK, FlashMenuPicker_Pick_Exit);
    GUIObject_Show(fmbk->sub_menu);
  }
  return 1;
}

int pg_FlashMenuPicker_Pick_ExitEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->sub_menu);
  return 1;
}

//--------------------------------------------------------------

void FlashMenuPicker_SelectAction(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  fmbk->type = ListMenu_GetSelectedItem(fmbk->main_menu);

  BookObj_CallPage(fmbk, &FlashMenuPicker_Pick_Page);
}

void FlashMenuPicker_ExitAction(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FreeBook(fmbk);
}

int FlashMenuPicker_onMessage(GUI_MESSAGE *msg)
{
  int item = GUIonMessage_GetCreatedItemIndex(msg);
  if (item == ITEM_SYS)
  {
    GUIonMessage_SetMenuItemText(msg, ITEM_SYS_TXT);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ITEM_SYS_ICN);
  }
  else if (item == ITEM_INT)
  {
    GUIonMessage_SetMenuItemText(msg, ITEM_INT_TXT);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ITEM_INT_ICN);
  }
#ifdef EXT_FLASH_PATH
  else if (item == ITEM_EXT)
  {
    GUIonMessage_SetMenuItemText(msg, ITEM_EXT_TXT);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ITEM_EXT_ICN);
  }
#endif
  return 1;
}

int pg_FlashMenuPicker_EnterEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->main_menu);

  if (fmbk->main_menu = CreateListMenu(fmbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(fmbk->main_menu, MAINMENU_TXT);
    ListMenu_SetItemCount(fmbk->main_menu, ITEM_LAST);
    ListMenu_SetOnMessage(fmbk->main_menu, FlashMenuPicker_onMessage);
    ListMenu_SetCursorToItem(fmbk->main_menu, ITEM_SYS);
    ListMenu_SetHotkeyMode(fmbk->main_menu, LKHM_SHORTCUT);

    GUIObject_SoftKeys_SetAction(fmbk->main_menu, ACTION_SELECT1, FlashMenuPicker_SelectAction);
    GUIObject_SoftKeys_SetAction(fmbk->main_menu, ACTION_BACK, FlashMenuPicker_ExitAction);
    GUIObject_SoftKeys_SetAction(fmbk->main_menu, ACTION_LONG_BACK, FlashMenuPicker_ExitAction);
    GUIObject_Show(fmbk->main_menu);
  }
  return 1;
}

int pg_FlashMenuPicker_ExitEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->main_menu);
  return 1;
}

int pg_FlashMenuPicker_CancelEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FreeBook(fmbk);
  return 1;
}

void FlashMenuPicker_onClose(BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->main_menu);
  FREE_GUI(fmbk->sub_menu);
  file_list_destroy(fmbk->flist, file_list_remove_item);
}

BOOL IsFlashMenuPickerBook(BOOK *book)
{
  return book->onClose == FlashMenuPicker_onClose;
}

FlashMenuPickerBook *Create_FlashMenuPickerBook()
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)malloc(sizeof(FlashMenuPickerBook));
  memset(fmbk, NULL, sizeof(FlashMenuPickerBook));
  if (!CreateBook(fmbk, FlashMenuPicker_onClose, &FlashMenuPicker_Base_Page, BOOKNAME, NO_BOOK_ID, NULL))
  {
    mfree(fmbk);
    return NULL;
  }
  fmbk->main_menu = NULL;
  fmbk->sub_menu = NULL;
  fmbk->flist = NULL;
  fmbk->type = NULL;
  return fmbk;
}

extern "C" void FlashmenuPicker(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)FindBook(IsFlashMenuPickerBook);
  if (fmbk)
  {
    BookObj_SetFocus(fmbk, UIDisplay_Main);
  }
  else
  {
    fmbk = Create_FlashMenuPickerBook();
    BookObj_GotoPage(fmbk, &FlashMenuPicker_Main_Page);
  }
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
  FreeBook(book);
#endif
}
