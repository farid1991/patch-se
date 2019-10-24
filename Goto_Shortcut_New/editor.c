#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "editor.h"
#include "utils.h"
#include "strlib.h"
#include "FileFolder.h"

void Action_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(book, NIL_EVENT);    
}

void AcceptShortcut(BOOK* book)
{
  BookObj_ReturnPage(book, NIL_EVENT);
  BookObj_ReturnPage(book, ACCEPT_EVENT);
}

void Menu_SetMainMenu( BOOK* MainMenu, GUI* gui )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)FindBook(IsMyBook);
  
  wchar_t* Data = L"MainMenu";
  StringRealloc(Data, &mbk->Current->sData);
  StringFree(Data);
  mbk->Current->Type = TYPE_SHORTCUT;
  
  void* ShortcutDesc;
#ifdef A1
  ShortcutDesc = SHORTCUT_DESC_Init(mbk->Current->sData);
#elif A2
  ShortcutDesc = SHORTCUT_DESC_A2_Init(mbk->Current->sData);
#endif
  mbk->Current->Icon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
  
  if (!mbk->Current->Caption)
  {
    wchar_t Text[20] = L"MainMenu";
    mbk->Current->Caption = StringAlloc(StringLength(Text));
    wstrcpy(mbk->Current->Caption, Text);
  }
  mfree(ShortcutDesc);
  FreeBook(MainMenu);
  AcceptShortcut(mbk);
}

void Menu_SetShortcut(BOOK* MainMenu, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)FindBook(IsMyBook);
  wchar_t* Data = MenuBook_Desktop_GetSelectedItemID(MainMenu);
  StringRealloc(Data, &mbk->Current->sData);
  StringFree(Data);
  
  mbk->Current->Type = TYPE_SHORTCUT;
  
  void* ShortcutDesc;
#ifdef A1
  ShortcutDesc = SHORTCUT_DESC_Init(mbk->Current->sData);
#elif A2
  ShortcutDesc = SHORTCUT_DESC_A2_Init(mbk->Current->sData);
#endif
  
  mbk->Current->Icon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
  if (!mbk->Current->Caption)
  {
    wchar_t text[64];
    TextID_GetWString(Shortcut_Get_MenuItemName(ShortcutDesc), text, MAXELEMS(text));
    mbk->Current->Caption = StringAlloc(StringLength(text));
    wstrcpy(mbk->Current->Caption, text);
  }
  mfree(ShortcutDesc);
  FreeBook(MainMenu);
  AcceptShortcut(mbk);
}

int Cancel_MainMenu_DB(void* data, BOOK* book)
{
  BookObj_ReturnPage(book, NIL_EVENT);
  return(1);
}

int CreateMainMenu(void* data, BOOK* book)
{
  BOOK* MainMenu = MenuBook_Desktop(1, BookObj_GetBookID(book));
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
  PAGE_ENTER_EVENT, CreateMainMenu,
  PREVIOUS_EVENT,   Cancel_MainMenu_DB,
  CANCEL_EVENT,     Cancel_MainMenu_DB,
  NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_MainMenu_PageDesc = {EDITOR_MAINMENU_BASEPAGE_NAME, 0, Goto_Editor_MainMenu_PageEvents};

//------------------------------------------------------------------------------

int JavaMenu_Callback(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    GotoShortcut_Book* mbk = (GotoShortcut_Book*)GUIonMessage_GetBook(msg);
    JAVA_LIST_ELEM* elem = (JAVA_LIST_ELEM*)List_Get(mbk->JavaList, GUIonMessage_GetCreatedItemIndex(msg));
    GUIonMessage_SetMenuItemText(msg, TextID_Get(elem->Name));
    GUIonMessage_SetMenuItemIcon(msg, 0, elem->ImageID);
  }
  return 1;
}

void JavaMenu_Ok(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  JAVA_LIST_ELEM* Elem = (JAVA_LIST_ELEM*)List_Get(mbk->JavaList, ListMenu_GetSelectedItem(mbk->JavaMenu));
  
  StringRealloc(Elem->Name, &mbk->Current->sData);
  mbk->Current->Icon = DB_LIST_JAVA_ICN;
  mbk->Current->Type = TYPE_JAVA;
  
  if (!mbk->Current->Caption)
    StringRealloc(Elem->Name, &mbk->Current->Caption);
  
  AcceptShortcut(mbk);
}

/*
void JavaMenu_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(mbk, NIL_EVENT);
}
*/

int CreateJavaList(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;   
  FREE_GUI(mbk->JavaMenu);
  
  mbk->JavaList = Create_JavaList();
  mbk->JavaMenu = CreateListMenu(mbk, UIDisplay_Main);
  
  GUIObject_SetTitleText(mbk->JavaMenu, JAVA_APP_TXT);
  ListMenu_SetItemCount(mbk->JavaMenu, List_GetCount(mbk->JavaList));
  ListMenu_SetOnMessage(mbk->JavaMenu, JavaMenu_Callback);
  ListMenu_SetCursorToItem(mbk->JavaMenu, 0);
  GUIObject_SoftKeys_SetAction(mbk->JavaMenu, ACTION_BACK, Action_Back);
  GUIObject_SoftKeys_SetAction(mbk->JavaMenu, ACTION_SELECT1, JavaMenu_Ok);
  GUIObject_Show(mbk->JavaMenu);
  return 0;
}

int CloseJavaList(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_JAVAGUI(mbk->JavaMenu, mbk->JavaList, JavaFree);
  return 0;
}

const PAGE_MSG Goto_Editor_JavaList_PageEvents[] = 
{
  PAGE_ENTER_EVENT,   CreateJavaList,
  PAGE_EXIT_EVENT,    CloseJavaList,
  NIL_EVENT, NULL
};
const PAGE_DESC Goto_Editor_JavaList_PageDesc = {EDITOR_JAVALIST_BASEPAGE_NAME, 0, Goto_Editor_JavaList_PageEvents};

//------------------------------------------------------------------------------

int Select_DB(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)FindBook(IsMyBook);
  FILEITEM* file_item = (FILEITEM*)data;
  
  mbk->Current->sData = FSX_MakeFullPath(FILEITEM_GetPath(file_item), FILEITEM_GetFname(file_item)); 
  mbk->Current->Icon = TypesIcons[TYPE_ELF];
  mbk->Current->Type = TYPE_ELF;

  if(!mbk->Current->Caption)
    StringRealloc(FILEITEM_GetFname(file_item), &mbk->Current->Caption);

  AcceptShortcut(mbk);
  return 0;
}

int DB_Filter(const wchar_t *ExtTable, const wchar_t* fpath, const wchar_t* fname)
{
  FSTAT fs;
  if (DataBrowser_isFileInListExt(ExtTable, fpath, fname))
    return 1;
  
  fstat(fpath, fname, &fs);
  return 0 != (fs.st_mode&FSX_S_IFDIR);
}

int CreateDataBrowser(void* data, BOOK* book)
{
  void* DB_Desc = DataBrowserDesc_Create();
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
  return 0;
}

const PAGE_MSG Goto_Editor_DataBrowser_PageEvents[] = 
{
  PAGE_ENTER_EVENT, CreateDataBrowser,
  ACCEPT_EVENT,     Select_DB,
  PREVIOUS_EVENT,   Cancel_MainMenu_DB,
  CANCEL_EVENT,     Cancel_MainMenu_DB,
  NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_DataBrowser_PageDesc = {EDITOR_DATABROWSER_BASEPAGE_NAME, 0, Goto_Editor_DataBrowser_PageEvents};

//------------------------------------------------------------------------------

void OnOkEventInput(BOOK* book, wchar_t *string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;

  if (len > 0)
  {
    StringRealloc(string, &mbk->Current->sData);
    mbk->Current->Icon = TypesIcons[TYPE_EVENT];
    mbk->Current->Type = TYPE_EVENT;
    
    int event = wstr2h(string,len);
    
    //wchar_t *EventName = StringAlloc(len); 
    //str2wstr(EventName,UIEventName(event));
    
    if(!mbk->Current->Caption)
      StringRealloc(string, &mbk->Current->Caption);
    
    //StringFree(EventName);
  }
  AcceptShortcut(mbk);
}

void OnBackEventInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->EventInput);
  BookObj_ReturnPage(mbk, NIL_EVENT);
}

int CreateInputEvent(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->EventInput);

  mbk->EventInput = CreateStringInput( mbk );
  StringInput_SetMode( mbk->EventInput, IT_ABC_AND_DIGIT);
  StringInput_SetEnableEmptyText( mbk->EventInput, TRUE );
  
  if(mbk->Current->sData && (mbk->Current->Type == TYPE_EVENT))
    StringInput_SetText( mbk->EventInput, TextID_Get(mbk->Current->sData) );

  StringInput_SetMinLen( mbk->EventInput, 1 );
  StringInput_SetMaxLen( mbk->EventInput, 4 );  
  StringInput_SetActionOK( mbk->EventInput, OnOkEventInput );
  StringInput_SetActionNo( mbk->EventInput, OnBackEventInput );
  
  GUIObject_SetTitleText(mbk->EventInput, EVENT_TXT );
  GUIObject_Show(mbk->EventInput);
  return 0;
}

int CloseInputEvent(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->EventInput);
  return 0;
}

const PAGE_MSG Goto_Editor_EventInput_PageEvents[] = 
{
  PAGE_ENTER_EVENT, CreateInputEvent,
  PAGE_EXIT_EVENT,  CloseInputEvent,
  NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_EventInput_PageDesc = {EDITOR_EVENTINPUT_BASEPAGE_NAME, 0, Goto_Editor_EventInput_PageEvents};

//------------------------------------------------------------------------------

void SelFolder_Enter( BOOK* book, GUI* gui )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  mbk->FType = SFOLDER;
  wchar_t* str;
  u16 len;
  StringInput_GetStringAndLen( mbk->FolderInput, &str, &len );
  mbk->SelectFolder = CreateFileFolderSelect( mbk, str );
}

void OnBackFolderInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->FolderInput);
  BookObj_ReturnPage(mbk, NIL_EVENT);
}

void OnOkFolderInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  
  if (len > 0)
  {
    StringRealloc(string, &mbk->Current->sData);
    mbk->Current->Icon = TypesIcons[TYPE_FOLDER];
    mbk->Current->Type = TYPE_FOLDER;
    
    if(!mbk->Current->Caption)
      StringExtractFileName(string, &mbk->Current->Caption);
  }
  AcceptShortcut(mbk);
}

int CreateSelectFolder(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->FolderInput);
  
  mbk->FolderInput =  CreateStringInput( mbk );
  StringInput_SetMode( mbk->FolderInput, IT_STRING);
  StringInput_SetEnableEmptyText( mbk->FolderInput, FALSE );
  
  if(mbk->Current->sData && (mbk->Current->Type == TYPE_FOLDER))
    StringInput_SetText( mbk->FolderInput, TextID_Get(mbk->Current->sData) );
  
  //StringInput_SetMinLen( mbk->FolderInput, 1 );
  StringInput_SetMaxLen( mbk->FolderInput, 255 );  
  StringInput_SetActionOK( mbk->FolderInput, OnOkFolderInput );
  StringInput_SetActionNo( mbk->FolderInput, OnBackFolderInput );
  
  GUIObject_SoftKeys_SetActionAndText( mbk->FolderInput, 0, SelFolder_Enter, SELECT_FOLDER_TXT );
  StringInput_MenuItem_SetPriority( mbk->FolderInput, 0, 0 );
  
  GUIObject_Show(mbk->FolderInput);
  return 0;
}

int CloseSelectFolder(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->SelectFolder);
  return 0;
}

const PAGE_MSG Goto_Editor_SelectFolder_PageEvents[] = 
{
  PAGE_ENTER_EVENT, CreateSelectFolder,
  PAGE_EXIT_EVENT,  CloseSelectFolder,
  NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_SelectFolder_PageDesc = {EDITOR_SELECTFOLDER_BASEPAGE_NAME, 0, Goto_Editor_SelectFolder_PageEvents};

//------------------------------------------------------------------------------

TEXTID Get_SCTypes_Text(int item)
{
  const wchar_t* TypesCaptions[TYPE_LAST] =
  {
    L"Shortcut",
    L"Java",
    L"Elf",
    L"Event",
    L"Folder"
  };
  return TextID_Get(TypesCaptions[item]);
}

void Types_Ok(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  switch(ListMenu_GetSelectedItem(mbk->TypesList))
  {
  case TYPE_SHORTCUT:            
    BookObj_CallPage(mbk, &Goto_Editor_MainMenu_PageDesc);
    break;
  case TYPE_JAVA:
    BookObj_CallPage(mbk, &Goto_Editor_JavaList_PageDesc);
    break;
  case TYPE_ELF:
    BookObj_CallPage(mbk, &Goto_Editor_DataBrowser_PageDesc);
    break;
  case TYPE_EVENT:
    BookObj_CallPage(mbk, &Goto_Editor_EventInput_PageDesc);
    break;
  case TYPE_FOLDER:
    BookObj_CallPage(mbk, &Goto_Editor_SelectFolder_PageDesc);
    break;
  }
}

int Types_Callback(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
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

int CreateTypesList(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  mbk->TypesList = CreateListMenu(mbk, UIDisplay_Main);
  GUIObject_SetTitleText(mbk->TypesList, TYPES_TITLE_TXT);
  ListMenu_SetItemCount(mbk->TypesList, TYPE_LAST);
  ListMenu_SetCursorToItem(mbk->TypesList, 0);
  ListMenu_SetOnMessage(mbk->TypesList, Types_Callback); 
  GUIObject_SoftKeys_SetAction(mbk->TypesList, ACTION_SELECT1, Types_Ok);
  GUIObject_SoftKeys_SetAction(mbk->TypesList, ACTION_BACK, Action_Back);
  GUIObject_Show(mbk->TypesList);
  return 1;
}

int CloseTypesList(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->TypesList);
  return 0;
}

const PAGE_MSG Goto_Editor_TypesList_PageEvents[] = 
{
    PAGE_ENTER_EVENT, CreateTypesList,
    PAGE_EXIT_EVENT,  CloseTypesList,
    NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_TypesList_PageDesc = {EDITOR_TYPESLIST_BASEPAGE_NAME, 0, Goto_Editor_TypesList_PageEvents};

//------------------------------------------------------------------------------

void OnOkCaptionInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;

  if (len > 0) StringReallocEx(string, &mbk->Current->Caption, len);
    
  BookObj_ReturnPage(mbk, ACCEPT_EVENT);
}
/*
void OnBackCaptionInput(BOOK* book, wchar_t* string, int len)
{
  BookObj_ReturnPage(book, NIL_EVENT);
}
*/   
int CreateCaptionInput(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->CaptionInput);

  mbk->CaptionInput = CreateStringInput( mbk );
  StringInput_SetMode( mbk->CaptionInput, IT_STRING);
  StringInput_SetEnableEmptyText( mbk->CaptionInput, TRUE );
  StringInput_SetText( mbk->CaptionInput, TextID_Get(mbk->Current->Caption) );
  StringInput_SetMinLen( mbk->CaptionInput, 1 );
  StringInput_SetMaxLen( mbk->CaptionInput, 63 );  
  StringInput_SetActionOK( mbk->CaptionInput, OnOkCaptionInput );
  //StringInput_SetActionNo( mbk->CaptionInput, OnBackCaptionInput );
  GUIObject_SoftKeys_SetAction(mbk->CaptionInput, ACTION_BACK, Action_Back);
  GUIObject_Show(mbk->CaptionInput);
  return 0;
}

int CloseCaptionInput(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->CaptionInput);
  return 0;
}

const PAGE_MSG Goto_Editor_CaptionInput_PageEvents[] = 
{
    PAGE_ENTER_EVENT, CreateCaptionInput,
    PAGE_EXIT_EVENT,  CloseCaptionInput,
    NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_CaptionInput_PageDesc = {EDITOR_CAPTIONINPUT_BASEPAGE_NAME, 0, Goto_Editor_CaptionInput_PageEvents};


//------------------------------------------------------------------------------

void Editor_Ok(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  switch(ListMenu_GetSelectedItem(mbk->Editor))
  {
  case 0:
    BookObj_CallPage(mbk, &Goto_Editor_CaptionInput_PageDesc);
    break;
  case 1:
    BookObj_CallPage(mbk, &Goto_Editor_TypesList_PageDesc);
    break;
  }
}

void Editor_Back(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if(!mbk->Current->sData || !mbk->Current->Caption)
  {
    void* Item = List_RemoveFirst(mbk->Items);
    ShortcutFree(Item);
    //UpdateMainPage(NULL, mbk);
  }
  BookObj_ReturnPage(book, ACCEPT_EVENT);
}

int Editor_Callback(GUI_MESSAGE *msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    GotoShortcut_Book* mbk = (GotoShortcut_Book*)GUIonMessage_GetBook(msg);
    int index = GUIonMessage_GetCreatedItemIndex(msg); 
    GUIonMessage_SetMenuItemIcon(msg, 0, EditorIcons[index]);
    if (index == 0)
    {
      GUIonMessage_SetMenuItemText(msg, EDITOR_LABEL_TXT);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Get(mbk->Current->Caption));
    }
    if (index == 1)
    {
      GUIonMessage_SetMenuItemText(msg, EDITOR_SHORTCUT_TXT);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Get(mbk->Current->sData)); 
    }
  }
  return 1;
}
int CreateEditorMenu(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_GUI(mbk->Editor);
  mbk->Editor = CreateListMenu(mbk, UIDisplay_Main);
  GUIObject_SetTitleText(mbk->Editor, EDITOR_TITLE_TXT);
  ListMenu_SetItemCount(mbk->Editor, 2);
  ListMenu_SetCursorToItem(mbk->Editor, 0);
  ListMenu_SetItemStyle(mbk->Editor, 3);
  ListMenu_SetOnMessage(mbk->Editor, Editor_Callback); 
  GUIObject_SoftKeys_SetAction(mbk->Editor, ACTION_SELECT1, Editor_Ok);
  GUIObject_SoftKeys_SetAction(mbk->Editor, ACTION_BACK, Editor_Back);
  GUIObject_Show(mbk->Editor);
  return 1;
}

int CloseEditorMenu(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  mbk->CurrentPos = ListMenu_GetSelectedItem(mbk->MainMenu);
  FREE_GUI(mbk->Editor);
  return 1;
}

const PAGE_MSG Goto_Editor_Main_PageEvents[] = 
{
  PAGE_ENTER_EVENT, CreateEditorMenu,
  ACCEPT_EVENT,     UpdateEditor,
  PAGE_EXIT_EVENT,  CloseEditorMenu,
  NIL_EVENT,        NULL
};
const PAGE_DESC Goto_Editor_Main_PageDesc = {EDITOR_MAIN_BASEPAGE_NAME, 0, Goto_Editor_Main_PageEvents};

int UpdateEditor(void* data, BOOK* book)
{
  BookObj_GotoPage(book, &Goto_Editor_Main_PageDesc);
  return 0;
}

void EditorRun(BOOK* book, int mode)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mode == ADDING_MODE)
  {
    SHORTCUT* Shortcut = (SHORTCUT *)malloc(sizeof(SHORTCUT));
    memset(Shortcut, NULL, sizeof(SHORTCUT));
    List_InsertFirst(mbk->Items, Shortcut);
    mbk->Current = (SHORTCUT*)List_Get(mbk->Items, 0);
  }
  else mbk->Current = (SHORTCUT*) List_Get(mbk->Items, ListMenu_GetSelectedItem(mbk->MainMenu));
  
  BookObj_CallPage(mbk, &Goto_Editor_Main_PageDesc);
}
