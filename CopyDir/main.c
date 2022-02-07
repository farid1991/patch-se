#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\book\DataBrowserBook.h"

#include "main.h"

__arm void StartElf(wchar_t *Name)
{
  elfload(Name, NULL, NULL, NULL);
}

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "CD", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "CD", 0);
#else
  return memalloc(size, 1, 5, "CD", 0);
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "CD", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "CD", 0);
#else
  if (mem)
    memfree(mem, "CD", 0);
#endif
}

BOOL isDirectory(wchar_t *name)
{
  W_FSTAT fs;
  if (w_fstat(name, &fs) != -1)
    return (fs.attr & FSX_O_CHKPATH);
  else
    return FALSE;
}

void CopyDir(wchar_t *src, wchar_t *dest)
{
  if (wstrwstr(dest, src))
    return;

  wchar_t destdir[256];
  wstrcpy(destdir, dest);
  wstrcat(destdir, wstrrchr(src, L'/'));
  w_mkdir(destdir, 0x1FF);
  void *dir = w_diropen(src);
  if (dir)
  {
    wchar_t *next;
    w_chdir(src);
    while ((next = w_dirread(dir)))
    {
      wchar_t filename[256];
      wstrcpy(filename, src);
      wstrcat(filename, L"/");
      wstrcat(filename, next);
      if (isDirectory(filename))
        CopyDir(filename, destdir);
      else
      {
        wchar_t des[256];
        wstrcpy(des, destdir);
        wstrcat(des, L"/");
        wstrcat(des, next);
        FileCopy(src, next, destdir, next, 0);
      }
    }
    w_dirclose(dir);
  }
}

int DB_FileFilter(const wchar_t *ExtList, const wchar_t *ItemPath, const wchar_t *ItemName)
{
  FSTAT fs;
  fstat(ItemPath, ItemName, &fs);
  if ((fs.st_mode & FSX_S_IFDIR))
    return TRUE;
  return FALSE;
}

int pg_CopyDir_AcceptEvent(void *data, BOOK *book)
{
  wchar_t *dest_path = FILEITEM_GetPath((FILEITEM *)data);
  CopyDir_book *mbk = (CopyDir_book *)book;
  if (isDirectory(dest_path))
  {
    CopyDir(mbk->src_path, dest_path);
  }
  CreateMessageBox(TextID_Create(mbk->src_path, ENC_UCS2, wstrlen(mbk->src_path)), TEXT_COPIED_TXT, 1, 1000, mbk);
  FreeBook(mbk);
  UI_Event(DB_UPDATE_EVENT);
  return 1;
}

int pg_CopyDir_EnterEvent(void *mess, BOOK *book)
{
  CopyDir_book *mbk = (CopyDir_book *)book;

  TEXTID HeaderText;
  const wchar_t *folder_list[2];

  switch (mbk->dest)
  {
  case ITEM_1:
    folder_list[0] = DIR_CARD;
    HeaderText = MEMORY_STICK_TXT;
    break;
  case ITEM_2:
    folder_list[0] = DIR_USB;
    HeaderText = MEMORY_PHONE_TXT;
    break;
  case ITEM_3:
    folder_list[0] = DIR_TPA;
    HeaderText = STR("TPA");
    break;
  case ITEM_4:
    folder_list[0] = L"/IFS";
    HeaderText = STR("IFS");
    break;
  }
  folder_list[1] = 0;

  void *DB_Desc = DataBrowserDesc_Create();

  if (DB_Desc)
  {
    DataBrowserDesc_SetHeaderText(DB_Desc, HeaderText);
    DataBrowserDesc_SetBookID(DB_Desc, BookObj_GetBookID(mbk));
    DataBrowserDesc_SetFolders(DB_Desc, folder_list);
    DataBrowserDesc_SetFoldersNumber(DB_Desc, 1);
    DataBrowserDesc_SetSelectAction(DB_Desc, 1);
    DataBrowserDesc_SetSelectActionOnFolders(DB_Desc, 1);
    DataBrowserDesc_SetOption(DB_Desc, semcdir);
    DataBrowserDesc_SetItemFilter(DB_Desc, DB_FileFilter);
    DataBrowserDesc_SetOpenEmptyFolder(DB_Desc, 1);
    DataBrowserDesc_SetOKSoftKeyText(DB_Desc, PASTE_TXT);
    DataBrowser_Create(DB_Desc);
    DataBrowserDesc_Destroy(DB_Desc);
  }
  return 1;
}

const PAGE_MSG pg_Copy[] =
    {
        PAGE_ENTER_EVENT, pg_CopyDir_EnterEvent,
        ACCEPT_EVENT, pg_CopyDir_AcceptEvent,
        NIL_EVENT, 0};
const PAGE_DESC pg_Generic_Copy = {"DataBrowser_CopyDir_Page", 0, pg_Copy};

void CopyDir_Main_onLongBack(BOOK *book, GUI *gui)
{
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void CopyDir_Main_onBack(BOOK *book, GUI *gui)
{
  FreeBook(book);
}

void CopyDir_Main_onSelect(BOOK *book, GUI *gui)
{
  CopyDir_book *mbk = (CopyDir_book *)book;
  mbk->dest = ListMenu_GetSelectedItem(mbk->MainMenu);
  BookObj_GotoPage(mbk, &pg_Generic_Copy);
}

int CopyDir_Main_onMessage(GUI_MESSAGE *msg)
{
  if (GUIonMessage_GetMsg(msg))
  {
    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case ITEM_1:
      GUIonMessage_SetMenuItemText(msg, MEMORY_STICK_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_MS_ICN);
      break;
    case ITEM_2:
      GUIonMessage_SetMenuItemText(msg, MEMORY_PHONE_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_PHONE_ICN);
      break;
    case ITEM_3:
      GUIonMessage_SetMenuItemText(msg, STR("TPA"));
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_LIST_FOLDER_ICN);
      break;
    case ITEM_4:
      GUIonMessage_SetMenuItemText(msg, STR("IFS"));
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_LIST_FOLDER_ICN);
      break;
    }
  }
  return 1;
}

int pg_CopyDir_Main_EnterEvent(void *data, BOOK *book)
{
  CopyDir_book *mbk = (CopyDir_book *)book;
  if (mbk->MainMenu = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->MainMenu, SELECT_FOLDER_TXT);
    ListMenu_SetItemCount(mbk->MainMenu, ITEM_COUNT);
    ListMenu_SetOnMessage(mbk->MainMenu, CopyDir_Main_onMessage);
    ListMenu_SetCursorToItem(mbk->MainMenu, ITEM_1);
    GUIObject_SetStyle(mbk->MainMenu, UI_OverlayStyle_PopupNoFrame);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_BACK, CopyDir_Main_onBack);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_LONG_BACK, CopyDir_Main_onLongBack);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_SELECT1, CopyDir_Main_onSelect);
    GUIObject_Show(mbk->MainMenu);
  }
  return 1;
};

int pg_CopyDir_Base_CancelEvent(void *mess, BOOK *book)
{
  CopyDir_book *mbk = (CopyDir_book *)book;
  FREE_GUI(mbk->MainMenu);
  return 1;
}

const PAGE_MSG pg_msglist_Base[] =
    {
        CANCEL_EVENT, pg_CopyDir_Base_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_CopyDir_Base_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC mbk_Base_Page = {"DataBrowser_CopyDir_Base_Page", 0, pg_msglist_Base};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_CopyDir_Main_EnterEvent,
        NIL_EVENT, NULL};
const PAGE_DESC mbk_Main_Page = {"DataBrowser_CopyDir_Main_Page", 0, bk_msglst_main};

void CopyDir_onClose(BOOK *book)
{
  CopyDir_book *mbk = (CopyDir_book *)book;
  FREE_GUI(mbk->MainMenu);
}

void DB_Action_CopyDirectory(BOOK *bk, GUI *gui)
{
  DataBrowserBook *DBBook = (DataBrowserBook *)bk;
  FILEITEM *file = DBBook->sub_exec->file_item;
  wchar_t *path = FILEITEM_GetPath(file);
  wchar_t *name = FILEITEM_GetFname(file);
  wchar_t *fullpath = FSX_MakeFullPath(path, name);

  if (isDirectory(fullpath))
  {
    CopyDir_book *mbk = (CopyDir_book *)malloc(sizeof(CopyDir_book));
    memset(mbk, NULL, sizeof(CopyDir_book));
    if (!CreateBook(mbk, CopyDir_onClose, &mbk_Base_Page, "CopyDirBook", -1, 0))
    {
      FSX_FreeFullPath(fullpath);
      mfree(mbk);
    }
    else
    {
      wstrcpy(mbk->src_path, fullpath);
      FSX_FreeFullPath(fullpath);
      BookObj_GotoPage(mbk, &mbk_Main_Page);
    }
  }
  else
  {
    FSX_FreeFullPath(fullpath);
    CreateMessageBox(EMPTY_TEXTID, STR("This is not Directory"), 1, 1000, DBBook);
  }
}

void DB_Action_CopyAsPath(BOOK *book, GUI *gui)
{
  DataBrowserBook *DBBook = (DataBrowserBook *)book;
  FILEITEM *file = DBBook->sub_exec->file_item;
  wchar_t *path = FILEITEM_GetPath(file);
  wchar_t *name = FILEITEM_GetFname(file);
  wchar_t *fullpath = FSX_MakeFullPath(path, name);
  int len = wstrlen(fullpath);
  Clipboard_SetText(fullpath, len);
  CreateMessageBox(TextID_Create(fullpath, ENC_UCS2, len), TEXT_COPIED_TXT, 1, 1000, DBBook);
  FSX_FreeFullPath(fullpath);
}

int GetFileAttribute(wchar_t *path, wchar_t *name)
{
  W_FSTAT fs;
  wchar_t *fullpath = FSX_MakeFullPath(path, name);
  w_fstat(fullpath, &fs);

  int i = 0x100;
  i >>= 1;
  if (((fs.attr & ~0x1000) & i))
    i = 0; // ro
  else
    i = 1; //rw

  FSX_FreeFullPath(fullpath);
  return i;
}

void SetPermission_onBack(BOOK *book, GUI *gui)
{
  DataBrowserBook *DBBook = (DataBrowserBook *)book;
  FREE_GUI(DBBook->DB_GUI);
}

void SetPermission_onLongBack(BOOK *book, GUI *gui)
{
  DataBrowserBook *DBBook = (DataBrowserBook *)book;
  FREE_GUI(DBBook->DB_GUI);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void SetPermission_onSelect(BOOK *book, GUI *gui)
{
  DataBrowserBook *DBBook = (DataBrowserBook *)book;
  FILEITEM *file = DBBook->sub_exec->file_item;
  wchar_t *path = FILEITEM_GetPath(file);
  wchar_t *name = FILEITEM_GetFname(file);

  switch (OnOffList_GetSelected(gui))
  {
  case FALSE:
    chmod(path, name, -1);
    break;
  case TRUE:
    chmod(path, name, 1);
    break;
  }
  FREE_GUI(DBBook->DB_GUI);
  UI_Event_toBookID(DB_UPDATE_EVENT, BookObj_GetBookID(DBBook));
}

void DB_Action_SetPermission(BOOK *book, GUI *gui)
{
  DataBrowserBook *DBBook = (DataBrowserBook *)book;
  FILEITEM *file = DBBook->sub_exec->file_item;
  wchar_t *path = FILEITEM_GetPath(file);
  wchar_t *name = FILEITEM_GetFname(file);

  if (DBBook->DB_GUI = CreateOnOffList(DBBook))
  {
    GUIObject_SetTitleText(DBBook->DB_GUI, STR("Read Only"));
    GUIObject_SetStyle(DBBook->DB_GUI, UI_OverlayStyle_PopupNoFrame);
    OnOffList_SetChecked(DBBook->DB_GUI, GetFileAttribute(path, name));
    GUIObject_SoftKeys_SetAction(DBBook->DB_GUI, ACTION_BACK, SetPermission_onBack);
    GUIObject_SoftKeys_SetAction(DBBook->DB_GUI, ACTION_LONG_BACK, SetPermission_onLongBack);
    GUIObject_SoftKeys_SetAction(DBBook->DB_GUI, ACTION_SELECT1, SetPermission_onSelect);
    GUIObject_Show(DBBook->DB_GUI);
  }
}

void DB_Action_FindFiles(BOOK *bk, GUI *gui)
{
  StartElf(L"/usb/other/Zbin/FindFiles.elf");
}

extern "C" void SoftKeys_SubItem(GUI *gui, u16 DB_MANAGEFILE)
{
  GUIObject_SoftKeys_SetAction(gui, ACTION_DB_FINDFILES, DB_Action_FindFiles);
  GUIObject_SoftKeys_SetText(gui, ACTION_DB_FINDFILES, FINDFILES_TXT);
  GUIObject_SoftKeys_SetItemAsSubItem(gui, DB_MANAGEFILE, ACTION_DB_FINDFILES);

  GUIObject_SoftKeys_SetAction(gui, ACTION_DB_COPYDIR, DB_Action_CopyDirectory);
  GUIObject_SoftKeys_SetText(gui, ACTION_DB_COPYDIR, STR("Copy Dir"));
  GUIObject_SoftKeys_SetItemAsSubItem(gui, DB_MANAGEFILE, ACTION_DB_COPYDIR);

  GUIObject_SoftKeys_SetAction(gui, ACTION_DB_COPYASPATH, DB_Action_CopyAsPath);
  GUIObject_SoftKeys_SetText(gui, ACTION_DB_COPYASPATH, STR("Copy as path"));
  GUIObject_SoftKeys_SetItemAsSubItem(gui, DB_MANAGEFILE, ACTION_DB_COPYASPATH);

  GUIObject_SoftKeys_SetAction(gui, ACTION_DB_PERMISSION, DB_Action_SetPermission);
  GUIObject_SoftKeys_SetText(gui, ACTION_DB_PERMISSION, STR("Permission"));
  GUIObject_SoftKeys_SetItemAsSubItem(gui, DB_MANAGEFILE, ACTION_DB_PERMISSION);
}

extern "C" void SoftKeys_Visible(GUI *gui, BOOL visible)
{
  GUIObject_SoftKeys_SetVisible(gui, ACTION_DB_MANAGEFILE, visible);
  GUIObject_SoftKeys_SetVisible(gui, ACTION_DB_FINDFILES, visible);
  GUIObject_SoftKeys_SetVisible(gui, ACTION_DB_COPYDIR, visible);
  GUIObject_SoftKeys_SetVisible(gui, ACTION_DB_COPYASPATH, visible);
  GUIObject_SoftKeys_SetVisible(gui, ACTION_DB_PERMISSION, visible);
}
