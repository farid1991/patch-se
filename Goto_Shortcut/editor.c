#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "main.h"
#include "editor.h"
#include "utils.h"
#include "strlib.h"
#include "FileFolder.h"

void Action_Back(BOOK *book, GUI *gui)
{
  BookObj_ReturnPage(book, NIL_EVENT);
}

void AcceptShortcut(BOOK *book)
{
  BookObj_ReturnPage(book, NIL_EVENT);
  BookObj_ReturnPage(book, ACCEPT_EVENT);
}

void Menu_SetMainMenu(BOOK *MainMenu, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsMyBook);

  wchar_t *Data = L"MainMenu";
  WStringRealloc(Data, &mbk->ShortcutItem->ShortcutLink);
  WStringFree(Data);
  mbk->ShortcutItem->ShortcutType = TYPE_SHORTCUT;

  void *ShortcutDesc;
#ifdef A1
  ShortcutDesc = SHORTCUT_DESC_Init(mbk->ShortcutItem->ShortcutLink);
#else
  ShortcutDesc = SHORTCUT_DESC_A2_Init(mbk->ShortcutItem->ShortcutLink);
#endif
  mbk->ShortcutItem->ShortcutIcon = Shortcut_Get_MenuItemIconID(ShortcutDesc);

  if (!mbk->ShortcutItem->ShortcutText)
  {
    wchar_t Text[20] = L"MainMenu";
    mbk->ShortcutItem->ShortcutText = WStringAlloc(WStringLength(Text));
    wstrcpy(mbk->ShortcutItem->ShortcutText, Text);
  }
  mfree(ShortcutDesc);
  FreeBook(MainMenu);
  AcceptShortcut(mbk);
}

void Menu_SetShortcut(BOOK *MainMenu, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsMyBook);
  wchar_t *Data = MenuBook_Desktop_GetSelectedItemID(MainMenu);
  WStringRealloc(Data, &mbk->ShortcutItem->ShortcutLink);
  WStringFree(Data);

  mbk->ShortcutItem->ShortcutType = TYPE_SHORTCUT;

  void *ShortcutDesc;
#ifdef A1
  ShortcutDesc = SHORTCUT_DESC_Init(mbk->ShortcutItem->ShortcutLink);
#else
  ShortcutDesc = SHORTCUT_DESC_A2_Init(mbk->ShortcutItem->ShortcutLink);
#endif

  mbk->ShortcutItem->ShortcutIcon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
  if (!mbk->ShortcutItem->ShortcutText)
  {
    wchar_t text[64];
    TextID_GetWString(Shortcut_Get_MenuItemName(ShortcutDesc), text, MAXELEMS(text));
    mbk->ShortcutItem->ShortcutText = WStringAlloc(WStringLength(text));
    wstrcpy(mbk->ShortcutItem->ShortcutText, text);
  }
  mfree(ShortcutDesc);
  FreeBook(MainMenu);
  AcceptShortcut(mbk);
}

int pg_SC_Editor_SelectShortcut_CancelAction(void *data, BOOK *book)
{
  BookObj_ReturnPage(book, NIL_EVENT);
  return (1);
}

int pg_SC_Editor_SelectShortcut_EnterAction(void *data, BOOK *book)
{
  BOOK *MainMenu = MenuBook_Desktop(1, BookObj_GetBookID(book));
  if (MainMenu)
  {
    BookObj_SoftKeys_SetAction(MainMenu, 0x0, Menu_SetShortcut);
    BookObj_SoftKeys_SetText(MainMenu, 0x0, SHC_SET_SHORTCUT_SK);

    BookObj_SoftKeys_SetAction(MainMenu, 0x1, Menu_SetMainMenu);
    BookObj_SoftKeys_SetText(MainMenu, 0x1, SHC_SET_MM);

    return TRUE;
  }
  return FALSE;
}

const PAGE_MSG Goto_Editor_MainMenu_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_SelectShortcut_EnterAction,
        PREVIOUS_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
        CANCEL_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_MainMenu_PageDesc = {EDITOR_MAINMENU_BASEPAGE_NAME, 0, Goto_Editor_MainMenu_PageEvents};

//------------------------------------------------------------------------------
#ifndef DB3350
int JavaMenu_Callback(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);
    JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)List_Get(mbk->JavaList, GUIonMessage_GetCreatedItemIndex(msg));
    GUIonMessage_SetMenuItemText(msg, TextID_Get(elem->Name));
    GUIonMessage_SetMenuItemIcon(msg, 0, elem->ImageID);
  }
  return 1;
}

void JavaMenu_Ok(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  JAVA_LIST_ELEM *Elem = (JAVA_LIST_ELEM *)List_Get(mbk->JavaList, ListMenu_GetSelectedItem(mbk->JavaMenu));

  WStringRealloc(Elem->Name, &mbk->ShortcutItem->ShortcutLink);
  mbk->ShortcutItem->ShortcutIcon = DB_LIST_JAVA_ICN;
  mbk->ShortcutItem->ShortcutType = TYPE_JAVA;

  if (!mbk->ShortcutItem->ShortcutText)
    WStringRealloc(Elem->Name, &mbk->ShortcutItem->ShortcutText);

  AcceptShortcut(mbk);
}

/*
void JavaMenu_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(mbk, NIL_EVENT);
}
*/

int CreateJavaList(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->JavaMenu);

  mbk->JavaList = Create_JavaList();
  if (mbk->JavaList)
  {
    if (mbk->JavaMenu = CreateListMenu(mbk, UIDisplay_Main))
    {
      GUIObject_SetTitleText(mbk->JavaMenu, JAVA_APP_TXT);
      ListMenu_SetItemCount(mbk->JavaMenu, List_GetCount(mbk->JavaList));
      ListMenu_SetOnMessage(mbk->JavaMenu, JavaMenu_Callback);
      ListMenu_SetCursorToItem(mbk->JavaMenu, 0);
      GUIObject_SoftKeys_SetAction(mbk->JavaMenu, ACTION_BACK, Action_Back);
      GUIObject_SoftKeys_SetAction(mbk->JavaMenu, ACTION_SELECT1, JavaMenu_Ok);
      GUIObject_Show(mbk->JavaMenu);
    }
  }
  return 0;
}

int CloseJavaList(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_JAVAGUI(mbk->JavaMenu, mbk->JavaList, JavaFree);
  return 0;
}

const PAGE_MSG Goto_Editor_JavaList_PageEvents[] =
    {
        PAGE_ENTER_EVENT, CreateJavaList,
        PAGE_EXIT_EVENT, CloseJavaList,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_JavaList_PageDesc = {EDITOR_JAVALIST_BASEPAGE_NAME, 0, Goto_Editor_JavaList_PageEvents};

//------------------------------------------------------------------------------

int pg_SC_Editor_SelectElf_AcceptAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsMyBook);
  FILEITEM *file_item = (FILEITEM *)data;

  mbk->ShortcutItem->ShortcutLink = FSX_MakeFullPath(FILEITEM_GetPath(file_item), FILEITEM_GetFname(file_item));
  mbk->ShortcutItem->ShortcutIcon = TypesIcons[TYPE_ELF];
  mbk->ShortcutItem->ShortcutType = TYPE_ELF;

  if (!mbk->ShortcutItem->ShortcutText)
    WStringRealloc(FILEITEM_GetFname(file_item), &mbk->ShortcutItem->ShortcutText);

  AcceptShortcut(mbk);
  return 0;
}

int DB_Filter(const wchar_t *ExtTable, const wchar_t *fpath, const wchar_t *fname)
{
  FSTAT fs;
  if (DataBrowser_isFileInListExt(ExtTable, fpath, fname))
    return 1;

  fstat(fpath, fname, &fs);
  return 0 != (fs.st_mode & FSX_S_IFDIR);
}

int pg_SC_Editor_SelectElf_EnterAction(void *data, BOOK *book)
{
  void *DB_Desc = DataBrowserDesc_Create();
  if (DB_Desc)
  {
    const wchar_t *Folders[3];
    Folders[0] = L"/usb/other/ZBin";
    Folders[1] = L"/card/other/ZBin";
    Folders[2] = NULL;
    DataBrowserDesc_SetHeaderText(DB_Desc, TextID_Get(L"ELFs"));
    DataBrowserDesc_SetBookID(DB_Desc, BookObj_GetBookID(book));
    DataBrowserDesc_SetFolders(DB_Desc, Folders);
    DataBrowserDesc_SetFileExtList(DB_Desc, L"*.elf");
    DataBrowserDesc_SetItemFilter(DB_Desc, DB_Filter);
    DataBrowserDesc_SetFoldersNumber(DB_Desc, 2);
    DataBrowserDesc_SetSelectAction(DB_Desc, 1);
    DataBrowser_Create(DB_Desc);
    DataBrowserDesc_Destroy(DB_Desc);
  }
  return 1;
}

const PAGE_MSG Goto_Editor_DataBrowser_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_SelectElf_EnterAction,
        ACCEPT_EVENT, pg_SC_Editor_SelectElf_AcceptAction,
        PREVIOUS_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
        CANCEL_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_DataBrowser_PageDesc = {EDITOR_DATABROWSER_BASEPAGE_NAME, 0, Goto_Editor_DataBrowser_PageEvents};
#endif
//------------------------------------------------------------------------------

void OnOkEventInput(BOOK *book, wchar_t *string, int len)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

  if (len > 0)
  {
    WStringRealloc(string, &mbk->ShortcutItem->ShortcutLink);
    mbk->ShortcutItem->ShortcutIcon = TypesIcons[TYPE_EVENT];
    mbk->ShortcutItem->ShortcutType = TYPE_EVENT;

    int event = wstr2h(string, len);

    //wchar_t *EventName = WStringAlloc(len);
    //str2wstr(EventName,UIEventName(event));

    if (!mbk->ShortcutItem->ShortcutText)
      WStringRealloc(string, &mbk->ShortcutItem->ShortcutText);

    //WStringFree(EventName);
  }
  AcceptShortcut(mbk);
}

void OnBackEventInput(BOOK *book, wchar_t *string, int len)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->EventInput);
  BookObj_ReturnPage(mbk, NIL_EVENT);
}

int pg_SC_Editor_EventInput_EnterAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->EventInput);

  if (mbk->EventInput = CreateStringInput(mbk))
  {
    StringInput_SetMode(mbk->EventInput, IT_ABC_AND_DIGIT);
    StringInput_SetEnableEmptyText(mbk->EventInput, TRUE);

    if (mbk->ShortcutItem->ShortcutLink && (mbk->ShortcutItem->ShortcutType == TYPE_EVENT))
      StringInput_SetText(mbk->EventInput, TextID_Get(mbk->ShortcutItem->ShortcutLink));

    StringInput_SetMinLen(mbk->EventInput, 1);
    StringInput_SetMaxLen(mbk->EventInput, 4);
    StringInput_SetActionOK(mbk->EventInput, OnOkEventInput);
    StringInput_SetActionBack(mbk->EventInput, OnBackEventInput);

    GUIObject_SetTitleText(mbk->EventInput, EVENT_TXT);
    GUIObject_Show(mbk->EventInput);
  }
  return 0;
}

int pg_SC_Editor_EventInput_ExitAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->EventInput);
  return 0;
}

const PAGE_MSG Goto_Editor_EventInput_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_EventInput_EnterAction,
        PAGE_EXIT_EVENT, pg_SC_Editor_EventInput_ExitAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_EventInput_PageDesc = {EDITOR_EVENTINPUT_BASEPAGE_NAME, 0, Goto_Editor_EventInput_PageEvents};

//------------------------------------------------------------------------------

void SelFolder_Enter(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  mbk->FType = SFOLDER;
  wchar_t *str;
  uint16_t len;
  StringInput_GetStringAndLen(mbk->FolderInput, &str, &len);
  mbk->SelectFolder = CreateFileFolderSelect(mbk, str);
}

void SC_Editor_SelectFolder_onBack(BOOK *book, wchar_t *string, int len)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->FolderInput);
  BookObj_ReturnPage(mbk, NIL_EVENT);
}

void SC_Editor_SelectFolder_onEnter(BOOK *book, wchar_t *string, int len)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

  if (len > 0)
  {
    WStringRealloc(string, &mbk->ShortcutItem->ShortcutLink);
    mbk->ShortcutItem->ShortcutIcon = TypesIcons[TYPE_FOLDER];
    mbk->ShortcutItem->ShortcutType = TYPE_FOLDER;

    if (!mbk->ShortcutItem->ShortcutText)
      WStringExtractFileName(string, &mbk->ShortcutItem->ShortcutText);
  }
  AcceptShortcut(mbk);
}

int pg_SC_Editor_SelectFolder_EnterAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->FolderInput);

  if (mbk->FolderInput = CreateStringInput(mbk))
  {
    StringInput_SetMode(mbk->FolderInput, IT_STRING);
    StringInput_SetEnableEmptyText(mbk->FolderInput, FALSE);

    if (mbk->ShortcutItem->ShortcutLink && (mbk->ShortcutItem->ShortcutType == TYPE_FOLDER))
      StringInput_SetText(mbk->FolderInput, TextID_Get(mbk->ShortcutItem->ShortcutLink));

    //StringInput_SetMinLen( mbk->FolderInput, 1 );
    StringInput_SetMaxLen(mbk->FolderInput, 0xFF);
    StringInput_SetActionOK(mbk->FolderInput, SC_Editor_SelectFolder_onEnter);
    StringInput_SetActionBack(mbk->FolderInput, SC_Editor_SelectFolder_onBack);

    GUIObject_SoftKeys_SetActionAndText(mbk->FolderInput, 0, SelFolder_Enter, SELECT_FOLDER_TXT);
    StringInput_MenuItem_SetPriority(mbk->FolderInput, 0, 0);

    GUIObject_Show(mbk->FolderInput);
  }
  return 0;
}

int pg_SC_Editor_SelectFolder_ExitAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->SelectFolder);
  return 0;
}

const PAGE_MSG Goto_Editor_SelectFolder_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_SelectFolder_EnterAction,
        PAGE_EXIT_EVENT, pg_SC_Editor_SelectFolder_ExitAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_SelectFolder_PageDesc = {EDITOR_SELECTFOLDER_BASEPAGE_NAME, 0, Goto_Editor_SelectFolder_PageEvents};

//------------------------------------------------------------------------------

TEXTID Get_SCTypes_Text(int item)
{
  const wchar_t *TypesCaptions[TYPE_LAST] =
      {
          L"Menu Item",
#ifndef DB3350
          L"Java",
          L"Elf",
#endif
          L"Event",
          L"Folder"};
  return TextID_Get(TypesCaptions[item]);
}

void TypesList_onSelect(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  switch (ListMenu_GetSelectedItem(mbk->TypesList))
  {
  case TYPE_SHORTCUT:
    BookObj_CallPage(mbk, &Goto_Editor_MainMenu_PageDesc);
    break;
#ifndef DB3350
  case TYPE_JAVA:
    BookObj_CallPage(mbk, &Goto_Editor_JavaList_PageDesc);
    break;
  case TYPE_ELF:
    BookObj_CallPage(mbk, &Goto_Editor_DataBrowser_PageDesc);
    break;
#endif
  case TYPE_EVENT:
    BookObj_CallPage(mbk, &Goto_Editor_EventInput_PageDesc);
    break;
  case TYPE_FOLDER:
    BookObj_CallPage(mbk, &Goto_Editor_SelectFolder_PageDesc);
    break;
  }
}

int TypesList_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, Get_SCTypes_Text(index));
    GUIonMessage_SetMenuItemIcon(msg, 0, TypesIcons[index]);
    break;
  }
  return 1;
}
/*
void Types_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(book, NIL_EVENT);    
}
*/

int pg_SC_Editor_TypesList_EnterAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  if (mbk->TypesList = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->TypesList, TYPES_TITLE_TXT);
    ListMenu_SetItemCount(mbk->TypesList, TYPE_LAST);
    ListMenu_SetCursorToItem(mbk->TypesList, 0);
    ListMenu_SetOnMessage(mbk->TypesList, TypesList_onMessage);
    GUIObject_SoftKeys_SetAction(mbk->TypesList, ACTION_SELECT1, TypesList_onSelect);
    GUIObject_SoftKeys_SetAction(mbk->TypesList, ACTION_BACK, Action_Back);
    GUIObject_Show(mbk->TypesList);
  }
  return 1;
}

int pg_SC_Editor_TypesList_ExitAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->TypesList);
  return 0;
}

const PAGE_MSG Goto_Editor_TypesList_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_TypesList_EnterAction,
        PAGE_EXIT_EVENT, pg_SC_Editor_TypesList_ExitAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_TypesList_PageDesc = {EDITOR_TYPESLIST_BASEPAGE_NAME, 0, Goto_Editor_TypesList_PageEvents};

//------------------------------------------------------------------------------

void OnOkCaptionInput(BOOK *book, wchar_t *string, int len)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

  if (len > 0)
    WStringReallocEx(string, &mbk->ShortcutItem->ShortcutText, len);

  BookObj_ReturnPage(mbk, ACCEPT_EVENT);
}
/*
void OnBackCaptionInput(BOOK* book, wchar_t* string, int len)
{
  BookObj_ReturnPage(book, NIL_EVENT);
}
*/
int pg_SC_Editor_LabelInput_EnterAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->CaptionInput);

  if (mbk->CaptionInput = CreateStringInput(mbk))
  {
    StringInput_SetMode(mbk->CaptionInput, IT_STRING);
    StringInput_SetEnableEmptyText(mbk->CaptionInput, TRUE);
    StringInput_SetText(mbk->CaptionInput, TextID_Get(mbk->ShortcutItem->ShortcutText));
    StringInput_SetMinLen(mbk->CaptionInput, 1);
    StringInput_SetMaxLen(mbk->CaptionInput, 63);
    StringInput_SetActionOK(mbk->CaptionInput, OnOkCaptionInput);
    //StringInput_SetActionNo( mbk->CaptionInput, OnBackCaptionInput );
    GUIObject_SoftKeys_SetAction(mbk->CaptionInput, ACTION_BACK, Action_Back);
    GUIObject_Show(mbk->CaptionInput);
  }
  return 0;
}

int pg_SC_Editor_LabelInput_ExitAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->CaptionInput);
  return 0;
}

const PAGE_MSG Goto_Editor_CaptionInput_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_LabelInput_EnterAction,
        PAGE_EXIT_EVENT, pg_SC_Editor_LabelInput_ExitAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_CaptionInput_PageDesc = {EDITOR_CAPTIONINPUT_BASEPAGE_NAME, 0, Goto_Editor_CaptionInput_PageEvents};

//------------------------------------------------------------------------------

void Editor_onSelect(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  switch (ListMenu_GetSelectedItem(mbk->Editor))
  {
  case 0:
    BookObj_CallPage(mbk, &Goto_Editor_CaptionInput_PageDesc);
    break;
  case 1:
    BookObj_CallPage(mbk, &Goto_Editor_TypesList_PageDesc);
    break;
  }
}

void Editor_onBack(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  if (!mbk->ShortcutItem->ShortcutLink || !mbk->ShortcutItem->ShortcutText)
  {
    void *Item = List_RemoveFirst(mbk->ShortcutList);
    ShortcutFree(Item);
    //UpdateMainPage(NULL, mbk);
  }
  BookObj_ReturnPage(book, ACCEPT_EVENT);
}

int Editor_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemIcon(msg, 0, EditorIcons[index]);
    if (index == 0)
    {
      GUIonMessage_SetMenuItemText(msg, EDITOR_LABEL_TXT);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Get(mbk->ShortcutItem->ShortcutText));
    }
    if (index == 1)
    {
      GUIonMessage_SetMenuItemText(msg, EDITOR_SHORTCUT_TXT);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Get(mbk->ShortcutItem->ShortcutLink));
    }
  }
  return 1;
}
int pg_SC_Editor_Main_EnterAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->Editor);
  if (mbk->Editor = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->Editor, EDITOR_TITLE_TXT);
    ListMenu_SetItemCount(mbk->Editor, 2);
    ListMenu_SetCursorToItem(mbk->Editor, 0);
    ListMenu_SetItemStyle(mbk->Editor, 3);
    ListMenu_SetOnMessage(mbk->Editor, Editor_onMessage);
    GUIObject_SoftKeys_SetAction(mbk->Editor, ACTION_SELECT1, Editor_onSelect);
    GUIObject_SoftKeys_SetAction(mbk->Editor, ACTION_BACK, Editor_onBack);
    GUIObject_Show(mbk->Editor);
  }
  return 1;
}

int CloseEditorMenu(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);
  FREE_GUI(mbk->Editor);
  return 1;
}

const PAGE_MSG Goto_Editor_Main_PageEvents[] =
    {
        PAGE_ENTER_EVENT, pg_SC_Editor_Main_EnterAction,
        ACCEPT_EVENT, pg_SC_Editor_Main_AcceptAction,
        PAGE_EXIT_EVENT, CloseEditorMenu,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Editor_Main_PageDesc = {EDITOR_MAIN_BASEPAGE_NAME, 0, Goto_Editor_Main_PageEvents};

int pg_SC_Editor_Main_AcceptAction(void *data, BOOK *book)
{
  BookObj_GotoPage(book, &Goto_Editor_Main_PageDesc);
  return 0;
}

void EditorRun(BOOK *book, int mode)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  if (mode == ADDING_MODE)
  {
    SHORTCUT *Shortcut = (SHORTCUT *)malloc(sizeof(SHORTCUT));
    memset(Shortcut, NULL, sizeof(SHORTCUT));
    List_InsertFirst(mbk->ShortcutList, Shortcut);
    mbk->ShortcutItem = (SHORTCUT *)List_Get(mbk->ShortcutList, 0);
  }
  else
    mbk->ShortcutItem = (SHORTCUT *)List_Get(mbk->ShortcutList, ListMenu_GetSelectedItem(mbk->MainMenu));

  BookObj_CallPage(mbk, &Goto_Editor_Main_PageDesc);
}