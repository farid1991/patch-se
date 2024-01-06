#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
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

MM_DATA *CreateData()
{
  MM_DATA *data = (MM_DATA *)malloc(sizeof(MM_DATA));
  memset(data, NULL, sizeof(MM_DATA));
  set_envp(NULL, EMP_NAME, (OSADDRESS)data);
  return data;
}

MM_DATA *GetData()
{
  MM_DATA *data = (MM_DATA *)get_envp(NULL, EMP_NAME);
  if (data)
    return data;
  return CreateData();
}

#if defined(W550_R4CB020)
BOOL FSX_IsFileExists(wchar_t *fpath, wchar_t *fname)
{
  FSTAT fs;
  if (!fstat(fpath, fname, &fs))
    return TRUE;
  return FALSE;
}
#endif

BOOL isDirectory(wchar_t *name)
{
  W_FSTAT fs;
  if (w_fstat(name, &fs) != -1)
    return fs.attr & FSX_O_CHKPATH;
  else
    return FALSE;
}

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, NULL, size);
  return (wstr);
}

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void Set_SWF_AsFlashMenu(const wchar_t *fpath, const wchar_t *fname, int *error)
{
  FileDelete(SETTINGS_PATH, FD_IMAGE, NULL);
  ThemeImage_Apply(fpath, fname, SETTINGS_PATH, FD_IMAGE, NULL, NULL);
}
#endif

void Free_FLIST(void)
{
  MM_DATA *fdata = GetData();
  FILELIST *flist = (FILELIST *)fdata->fltop;
  fdata->fltop = NULL;

  while (flist)
  {
    FILELIST *fl_prev = flist;
    mfree(fl_prev->fullname);
    mfree(fl_prev->name);
    flist = (FILELIST *)flist->next;
    mfree(fl_prev);
  }
}

FILELIST *AddToFList(const wchar_t *full_name, const wchar_t *name, int is_folder)
{
  MM_DATA *fdata = GetData();

  FILELIST *flist;
  FILELIST *fl_next = (FILELIST *)malloc(sizeof(FILELIST));

  fl_next->fullname = WStringAlloc(wstrlen(full_name));
  fl_next->name = WStringAlloc(wstrlen(name));

  wstrcpy(fl_next->fullname, full_name);
  wstrcpy(fl_next->name, name);
  fl_next->is_folder = is_folder;
  fl_next->next = NULL;
  flist = (FILELIST *)fdata->fltop;
  if (flist)
  {
    FILELIST *fl_prev;
    fl_prev = (FILELIST *)&fdata->fltop;
    while (wstrcmpi(flist->name, fl_next->name) < 0)
    {
      fl_prev = flist;
      flist = (FILELIST *)flist->next;

      if (!flist)
        break;
    }
    fl_next->next = flist;
    fl_prev->next = fl_next;
  }
  else
  {
    fdata->fltop = fl_next;
  }
  return fl_next;
}

int FindFiles(wchar_t *str, int type) // type == 0 SelectFolder, type == 1 SelectFile
{
  Free_FLIST();

  int i, c, n = 0;

  wchar_t *path = WStringAlloc(255);
  wchar_t *name = WStringAlloc(255);

  wchar_t *rev = NULL, *d = name, *s = str;

  while ((c = *s++))
  {
    *d = c;
    if (c == '/' && *s != '\0')
      rev = d;
    d++;
  }
  if (rev)
  {
    if (rev == name)
      *(rev + 1) = 0;
    else
      *rev = 0;
  }
  void *dir = w_diropen(str);
  if (dir)
  {
    wchar_t *next;
    w_chdir(str);
    while (next = w_dirread(dir))
    {
      W_FSTAT fstat;
      w_fstat(next, &fstat);
      i = wstrlen(str);
      wstrcpy(path, str);
      if (rev)
      {
        path[i++] = '/';
      }
      wstrcpy(path + i, next);
      if (fstat.attr & FSX_O_CHKPATH)
      {
        snwprintf(name, 63, L"%ls", next);
        AddToFList(path, name, ITEM_FOLDER);
        n++;
      }
      else
      {
        if (type == SEL_FILE)
        {
          if (wstrcmp(CUSTOM_NAME, next))
          {
            AddToFList(path, next, ITEM_FILE);
            n++;
          }
        }
      }
    }
    w_dirclose(dir);
  }
  mfree(path);
  mfree(name);
  return n;
}

FILELIST *FindFLISTtByNS(int *index, int type)
{
  MM_DATA *fdata = GetData();

  FILELIST *flist;
  flist = (FILELIST *)fdata->fltop;
  while (flist)
  {
    if (flist->is_folder == type)
    {
      if (!(*index))
        return flist;
      (*index)--;
    }
    flist = (FILELIST *)flist->next;
  }
  return flist;
}

FILELIST *FindFLISTtByN(int index)
{
  FILELIST *flist;

  flist = FindFLISTtByNS(&index, ITEM_FOLDER);
  if (!index && flist)
    return flist;

  flist = FindFLISTtByNS(&index, ITEM_FILE);

  if (!index && flist)
    return flist;

  return flist;
}

int Generate_Flist(wchar_t *path)
{
  wchar_t *ustr = WStringAlloc(wstrlen(path));
  wchar_t *wchar;

  wstrcpy(ustr, path);
  path = ustr;

  int f = 0;
  do
  {
    if (isDirectory(ustr))
    {
      f = 1;
      break;
    }
    wchar = wstrrchr(ustr, L'/');

    if (wchar == ustr)
      break;

    if (wchar)
      *wchar = NULL;
  } while (wchar);

  if (!f)
    path = L"/";

  int count = FindFiles(path, SEL_FILE);
  mfree(ustr);

  return count;
}

int FlashMenuPicker_Pick_OnMessage(GUI_MESSAGE *msg)
{
  FILELIST *flist;
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    flist = FindFLISTtByN(index);
    TEXTID Textid = TextID_Create(flist->name, ENC_UCS2, TEXTID_ANY_LEN);
    GUIonMessage_SetMenuItemText(msg, Textid);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_FLASH_ICN);
    break;
  }
  return 1;
}

void FlashMenuPicker_Pick_Select(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  int item = ListMenu_GetSelectedItem(fmbk->SubMenu);

  FILELIST *flist = FindFLISTtByN(item);
  if (flist)
  {
    if (FSX_IsFileExists(DEFAULT_FLASH_PATH, CUSTOM_NAME))
    {
      FileDelete(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }

    if (fmbk->type == ITEM_SYS)
    {
      FileCopy(DEFAULT_FLASH_PATH, flist->name, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }
    else if (fmbk->type == ITEM_INT)
    {
      FileCopy(INT_FLASH_PATH, flist->name, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }
#ifdef EXT_FLASH_PATH
    else if (fmbk->type == ITEM_EXT)
    {
      FileCopy(EXT_FLASH_PATH, flist->name, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
    }
#endif

    Set_SWF_AsFlashMenu(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
    MainMenu_SetFromUserTheme(TRUE);
#endif

    wchar_t buf[256];
    snwprintf(buf, MAXELEMS(buf), L"%ls", flist->name);
    TEXTID Textid = TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
    MessageBox(EMPTY_TEXTID, Textid, DB_FLASH_ICN, 1, 1000, fmbk);

    FreeBook(fmbk);
  }
}

void FlashMenuPicker_Pick_Preview(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  int item = ListMenu_GetSelectedItem(fmbk->SubMenu);

  FILELIST *flist = FindFLISTtByN(item);
  if (flist)
  {
    char *uri;
    char *uri_scheme = GetURIScheme(file);
    if (fmbk->type == ITEM_SYS)
    {
      uri = CreateURI(DEFAULT_FLASH_PATH, flist->name, uri_scheme);
    }
    else if (fmbk->type == ITEM_INT)
    {
      uri = CreateURI(INT_FLASH_PATH, flist->name, uri_scheme);
    }
#ifdef EXT_FLASH_PATH
    else if (fmbk->type == ITEM_EXT)
    {
      uri = CreateURI(EXT_FLASH_PATH, flist->name, uri_scheme);
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
  BookObj_ReturnPage(fmbk, PREVIOUS_EVENT);
}

int pg_FlashMenuPicker_Pick_EnterEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->SubMenu);

  int count;
  if (fmbk->type == ITEM_SYS)
  {
    count = Generate_Flist(DEFAULT_FLASH_PATH);
  }
  else if (fmbk->type == ITEM_INT)
  {
    count = Generate_Flist(INT_FLASH_PATH);
  }
#ifdef EXT_FLASH_PATH
  else if (fmbk->type == ITEM_EXT)
  {
    count = Generate_Flist(EXT_FLASH_PATH);
  }
#endif
  if (fmbk->SubMenu = CreateListMenu(fmbk, UIDisplay_Main))
  {
    ListMenu_SetItemCount(fmbk->SubMenu, count);
    ListMenu_SetCursorToItem(fmbk->SubMenu, 0);
    ListMenu_SetOnMessage(fmbk->SubMenu, FlashMenuPicker_Pick_OnMessage);
    ListMenu_SetHotkeyMode(fmbk->SubMenu, LKHM_SHORTCUT);
    GUIObject_SetTitleText(fmbk->SubMenu, SUBMENU_TXT);
    ListMenu_SetItemTextScroll(fmbk->SubMenu, 1);
    ListMenu_SetNoItemText(fmbk->SubMenu, EMPTY_LIST_TXT);
    if (count)
    {
      GUIObject_SoftKeys_SetText(fmbk->SubMenu, 0, PREVIEW_SK_TXT);
      GUIObject_SoftKeys_SetAction(fmbk->SubMenu, 0, FlashMenuPicker_Pick_Preview);
      GUIObject_SoftKeys_SetAction(fmbk->SubMenu, ACTION_SELECT1, FlashMenuPicker_Pick_Select);
    }
    GUIObject_SoftKeys_SetAction(fmbk->SubMenu, ACTION_BACK, FlashMenuPicker_Pick_Exit);
    GUIObject_SoftKeys_SetAction(fmbk->SubMenu, ACTION_LONG_BACK, FlashMenuPicker_Pick_Exit);
    GUIObject_Show(fmbk->SubMenu);
  }
  return 1;
}

int pg_FlashMenuPicker_Pick_ExitEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->SubMenu);
  return 1;
}

//--------------------------------------------------------------

void FlashMenuPicker_SelectAction(BOOK *book, GUI *gui)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  fmbk->type = ListMenu_GetSelectedItem(fmbk->MainMenu);

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
  FREE_GUI(fmbk->MainMenu);

  if (fmbk->MainMenu = CreateListMenu(fmbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(fmbk->MainMenu, MAINMENU_TXT);
    ListMenu_SetItemCount(fmbk->MainMenu, ITEM_LAST);
    ListMenu_SetOnMessage(fmbk->MainMenu, FlashMenuPicker_onMessage);
    ListMenu_SetCursorToItem(fmbk->MainMenu, ITEM_SYS);
    ListMenu_SetHotkeyMode(fmbk->MainMenu, LKHM_SHORTCUT);

    GUIObject_SoftKeys_SetAction(fmbk->MainMenu, ACTION_SELECT1, FlashMenuPicker_SelectAction);
    GUIObject_SoftKeys_SetAction(fmbk->MainMenu, ACTION_BACK, FlashMenuPicker_ExitAction);
    GUIObject_SoftKeys_SetAction(fmbk->MainMenu, ACTION_LONG_BACK, FlashMenuPicker_ExitAction);
    GUIObject_Show(fmbk->MainMenu);
  }
  return 1;
}

int pg_FlashMenuPicker_ExitEvent(void *data, BOOK *book)
{
  FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
  FREE_GUI(fmbk->MainMenu);
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
  FlashMenuPickerBook *mbk = (FlashMenuPickerBook *)book;
  FREE_GUI(mbk->MainMenu);
  FREE_GUI(mbk->SubMenu);
  Free_FLIST();
}

BOOL IsFlashMenuPickerBook(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, BOOKNAME);
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
  fmbk->MainMenu = NULL;
  fmbk->SubMenu = NULL;
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
  else if (fmbk = Create_FlashMenuPickerBook())
  {
      BookObj_GotoPage(fmbk, &FlashMenuPicker_Main_Page);
  }
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
  FreeBook(book);
#endif
}
