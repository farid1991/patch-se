#include "temp\target.h"

#include "..\\include\Types.h"

#ifdef A1
#include "..\\include\book\RightNowBook.h"
#else
#include "..\\include\book\ActivityMenuBook.h"
#endif

#include "Lib.h"
#include "main.h"

__arm void openWithBcfgEdit(wchar_t *bcfgedit_path, const wchar_t *filepath, const wchar_t *filename)
{
  elfload(bcfgedit_path, (void *)filepath, (void *)filename, NULL);
}

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, MEM_NAME, 0);
#elif defined(A2)
  return memalloc(-1, size, 1, 5, MEM_NAME, 0);
#else
  return memalloc(size, 1, 5, MEM_NAME, 0);
#endif
}

void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, MEM_NAME, 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, MEM_NAME, 0);
#else
  if (mem)
    memfree(mem, MEM_NAME, 0);
#endif
}

BOOK_MANAGER *CreateData()
{
  BOOK_MANAGER *data = (BOOK_MANAGER *)malloc(sizeof(BOOK_MANAGER));
  memset(data, NULL, sizeof(BOOK_MANAGER));
  data->tab_pos = TAB_BOOKS;
  set_envp(NULL, EMP_NAME, (OSADDRESS)data);
  return data;
}

BOOK_MANAGER *GetData()
{
  BOOK_MANAGER *data = (BOOK_MANAGER *)get_envp(NULL, EMP_NAME);
  if (data)
    return data;
  return CreateData();
}

#if defined(A1) || defined(DB3150v1)
#define dll_ConnectionManager_Connection_GetState() ConnectionManager_Connection_GetState()
#else
int dll_ConnectionManager_Connection_GetState()
{
  char buf = NULL;
  ConnectionManager_Connection_GetState_int(&buf);
  return (buf ? TRUE : FALSE);
}
#endif

void win12512unicode(wchar_t *ws, char *s, int len)
{
  int c;
  while ((c = *s++) && ((len--) > 0))
  {
    if (c == 0xA8)
      c = 0x401;
    if (c == 0xAA)
      c = 0x404;
    if (c == 0xAF)
      c = 0x407;
    if (c == 0xB8)
      c = 0x451;
    if (c == 0xBA)
      c = 0x454;
    if (c == 0xBF)
      c = 0x457;
    if ((c >= 0xC0) && (c < 0x100))
      c += 0x350;
    *ws++ = c;
  }
  *ws = 0;
}

int wcharh2int(wchar_t n)
{
  int r = 0;
  if (n >= '0' && n <= '9')
    r = n - 0x30;
  if (n == 'a' || n == 'A')
    r = 10;
  if (n == 'b' || n == 'B')
    r = 11;
  if (n == 'c' || n == 'C')
    r = 12;
  if (n == 'd' || n == 'D')
    r = 13;
  if (n == 'e' || n == 'E')
    r = 14;
  if (n == 'f' || n == 'F')
    r = 15;
  return r;
}

void GetIconByName(wchar_t *name, int &imageid)
{
  if (name[0] == '0' && name[1] == 'x')
  {
    imageid = 0;
    int N = 0x1000;
    for (int i = 0; i < 4; i++)
    {
      imageid += wcharh2int(name[2 + i]) * N;
      N = N >> 4;
    }
  }
  else
  {
    iconidname2id(name, -1, &imageid);
  }
}

TEXTID GetJavaName(BOOK *book)
{
#ifdef DB2010
  wchar_t ws[100];
  TextID_GetWString(BookObj_GetSession(book)->name, ws, MAXELEMS(ws));

  if (!wstrncmp(ws, L"Foreign app", 11))
  {
    return JavaSession_GetName();
  }

  if (!wstrcmp(ws, L"Java"))
  {
    return JavaSession_GetName();
  }
#endif
  return EMPTY_TEXTID;
}

int read_ini_file(const wchar_t *filename, char **ini_data)
{
  char *data = NULL;
  int fsize = 0;
  FSTAT _fstat;
  if (!fstat(INI_PATH, filename, &_fstat))
  {
    int file = _fopen(INI_PATH, filename, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (file >= 0)
    {
      fsize = _fstat.fsize;
      data = (char *)malloc(fsize + 1);
      fread(file, data, fsize);
      fclose(file);
    }
  }
  *ini_data = data;
  return fsize;
}

void Load_booknames(BOOK_MANAGER *data)
{
  char *buffer;
  if (data->books_name_size = read_ini_file(BOOKMAN_INI, &buffer))
  {
    if (data->books_name_buf)
      mfree(data->books_name_buf);

    data->books_name_buf = buffer;
  }
}

void Load_shortcuts(BOOK_MANAGER *data)
{
  char *buffer;
  if (data->shortcut_size = read_ini_file(SHORTCUT_INI, &buffer))
  {
    if (data->shortcut_buf)
      mfree(data->shortcut_buf);

    data->shortcut_buf = buffer;
  }
}

int GetActiveTab(BOOK *book)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  return TabMenuBar_GetFocusedTab(pActBook->main_tab);
}

BOOK_LIST_ELEM *GetBookListItem(int tab_num)
{
  BOOK_MANAGER *data = GetData();
  data->tab_pos = tab_num;

  BOOK_LIST_ELEM *elem;
  if (tab_num == TAB_BOOKS)
  {
    data->book_index = ListMenu_GetSelectedItem(data->books_menu);
    elem = (BOOK_LIST_ELEM *)List_Get(data->books_list, data->book_index);
  }
  else
  {
    if (data->elfs_count)
      elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, data->elf_index);
    else
      return NULL;
  }
  return elem;
}

BOOK *GetBook(int tab_num)
{
  BOOK_LIST_ELEM *elem = GetBookListItem(tab_num);
  return (elem ? elem->book : NULL);
}

BOOL CheckEvent(BOOK *book, int event)
{
  if (book->base_page)
  {
    const PAGE_MSG *pm = book->base_page->msg_lst;
    if (pm)
    {
      while (pm->msg && pm->proc)
      {
        if (pm->msg == event)
          return TRUE;
        pm++;
      }
    }
  }
  return FALSE;
}

void Delete_book_and_elf(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK_MANAGER *data = GetData();
  int active_tab = GetActiveTab(pActBook);
  data->tab_pos = active_tab;

  if (active_tab == TAB_BOOKS)
  {
    BOOK_LIST_ELEM *elem = GetBookListItem(TAB_BOOKS);
    if (!elem)
      return;

    BOOK *selected_book = elem->book;
    if (selected_book != Find_StandbyBook())
    {
      if (elem->isJava)
      {
        UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(selected_book));
      }
      else
      {
        if (CheckEvent(selected_book, TERMINATE_SESSION_EVENT))
        {
          UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID((BOOK *)List_Get(selected_book->xbook->app_session->listbook, List_GetCount(selected_book->xbook->app_session->listbook) - 1)));
        }
        else if (CheckEvent(selected_book, RETURN_TO_STANDBY_EVENT))
        {
          UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID((BOOK *)List_Get(selected_book->xbook->app_session->listbook, List_GetCount(selected_book->xbook->app_session->listbook) - 1)));
        }
      }
      UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
    }
  }
  else
  {
    if (!data->elfs_count)
      return;

    BOOK *selected_book = GetBook(TAB_ELFS);
    if (selected_book)
    {
      if (CheckEvent(selected_book, RETURN_TO_STANDBY_EVENT))
      {
        UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID(selected_book));
      }
      else
      {
        if (CheckEvent(selected_book, ELF_TERMINATE_EVENT))
        {
          UI_Event_toBookID(ELF_TERMINATE_EVENT, BookObj_GetBookID(selected_book));
        }
        else
        {
          wchar_t buf[128];
          snwprintf(buf, MAXELEMS(buf), L"TerminateEvent not supported by %s", selected_book->xbook->name);
          MessageBox(EMPTY_TEXTID, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN), NOIMAGE, 1, 0, selected_book);
        }
      }
      UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
    }
  }
}

void Close_Activitymenu(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  BOOK_MANAGER *data = GetData();
  data->tab_pos = GetActiveTab(pActBook);

  FreeBook(pActBook);
}

void Exit_to_Standby(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  BOOK_MANAGER *data = GetData();
  data->tab_pos = GetActiveTab(pActBook);

  FreeBook(pActBook);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void onEnterPressed_Books(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *selected_book = GetBook(TAB_BOOKS);
  if (selected_book)
  {
    BookObj_SetFocus(selected_book, UIDisplay_Main);
    FreeBook(pActBook);
  }
}

void Minimise_all_books(BOOK *book)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  BOOK *standbyBook = Find_StandbyBook();
  if (standbyBook)
  {
    BookObj_SetFocus(standbyBook, UIDisplay_Main);
    FreeBook(pActBook);
  }
}

void Close_all_books(BOOK *book)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  UI_Event(RETURN_TO_STANDBY_EVENT);
  FreeBook(pActBook);
}

void Parse_and_Run_Shortcut(BOOK_MANAGER *data, int key)
{
  if (!data->shortcut_buf)
    return;

  char mask[64];
  sprintf(mask, "[KEY_%d]:", key - KEY_DIGITAL_0);

  char *param = manifest_GetParam(data->shortcut_buf, mask, NULL);
  if (param)
  {
    wchar_t name[128];
    str2wstr(name, param);
    Shortcut_Run(name);

    mfree(param);
    FreeBook(data->ActivityMenu);
  }
}

void myOnKey_Unified(DISP_OBJ *disp_obj, int key, int count, int repeat, int mode)
{
  BOOK_MANAGER *data = GetData();

  data->oldOnKey(disp_obj, key, count, repeat, mode);

  if (mode == KBD_SHORT_RELEASE)
  {
    if (key == KEY_DIEZ)
    {
      Minimise_all_books(data->ActivityMenu);
    }
    else if (key == KEY_STAR)
    {
      Close_all_books(data->ActivityMenu);
    }
    else if (key == KEY_DEL)
    {
      Delete_book_and_elf(data->ActivityMenu, NULL);
    }
    else if ((key - KEY_DIGITAL_0) <= 9)
    {
      Parse_and_Run_Shortcut(data, key);
    }
  }
}

TEXTID Get_BookName(BOOK_MANAGER *data, char *book_name)
{
  wchar_t ws[MAX_BOOK_NAME_LEN];
  TEXTID ret = 0;

  if (data->books_name_buf)
  {
    char *param;
    if (param = manifest_GetParam(data->books_name_buf, book_name, NULL))
    {
      win12512unicode(ws, param, (MAX_BOOK_NAME_LEN - 1));
      ret = TextID_Create(ws, ENC_UCS2, TEXTID_ANY_LEN);
      mfree(param);
      return ret;
    }
  }
  if (!ret)
  {
    win12512unicode(ws, book_name, (MAX_BOOK_NAME_LEN - 1));
    ret = TextID_Create(ws, ENC_UCS2, wstrlen(ws));
  }
  return ret;
}

IMAGEID Get_BookIcon(BOOK_MANAGER *data, char *book_name, int iconid)
{
  char *pos;
  char *end_pos;
  wchar_t ws[MAX_BOOK_NAME_LEN];

  int ret = 0;

  if (data->books_name_buf)
  {
    char *param;
    pos = strstr(data->books_name_buf, book_name);
    end_pos = pos + strlen(book_name) + sizeof("\r\n") - sizeof("");
    if (param = manifest_GetParam(end_pos, "ICON", 0))
    {
      win12512unicode(ws, param, (MAX_BOOK_NAME_LEN - 1));
      GetIconByName(ws, ret);
      mfree(param);
    }
  }
  if (!ret)
    ret = iconid;
  return ret;
}

int BookMenu_onMessage(GUI_MESSAGE *msg)
{
  BOOK_MANAGER *data = GetData();
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:

    int index = GUIonMessage_GetCreatedItemIndex(msg);
    BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)List_Get(data->books_list, index);
    GUIonMessage_SetMenuItemText(msg, Get_BookName(data, elem->book_name));

    if (elem->isJava)
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->book_icon);
    else
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, Get_BookIcon(data, elem->book_name, BOOK_ITEM_ICON));

    break;
  }
  return 1;
}

TEXTID Get_FreeHeap()
{
  wchar_t buf[64];
  snwprintf(buf, MAXELEMS(buf), L"Heap: %dKB", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" void CreateBookMenu(BOOK *book, int tab_num)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK_MANAGER *data = GetData();
  data->ActivityMenu = pActBook;

  if (data->book_index > data->books_count - 1)
    data->book_index = data->books_count - 1;

  data->books_menu = CreateListMenu(pActBook, UIDisplay_Main);
  ListMenu_SetOnMessage(data->books_menu, BookMenu_onMessage);
  ListMenu_SetItemCount(data->books_menu, data->books_count);
  ListMenu_SetCursorToItem(data->books_menu, data->book_index);
  GUIObject_SetStyle(data->books_menu, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->books_menu, 1);
  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_BACK, Close_Activitymenu);
  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_LONG_BACK, Exit_to_Standby);
  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_SELECT1, onEnterPressed_Books);

  data->oldOnKey = DispObject_GetOnKey(GUIObject_GetDispObject(data->books_menu));
  DISP_DESC_SetOnKey(DispObject_GetDESC(GUIObject_GetDispObject(data->books_menu)), myOnKey_Unified);

  TabMenuBar_SetTabGui(pActBook->main_tab, tab_num, data->books_menu);
  TabMenuBar_SetTabTitle(pActBook->main_tab, tab_num, Get_FreeHeap());
}

void onEnterPressed_Elfs(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *selected_book = GetBook(TAB_ELFS);
  if (selected_book)
  {
    BookObj_SetFocus(selected_book, UIDisplay_Main);
    FreeBook(pActBook);
  }
}

void onAuthor(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *selected_book = GetBook(TAB_ELFS);
  if (selected_book)
  {
    if (CheckEvent(selected_book, ELF_SHOW_INFO_EVENT))
    {
      MSG *msg = (MSG *)malloc(sizeof(MSG));
      msg->book = pActBook;
      UI_Event_toBookIDwData(ELF_SHOW_INFO_EVENT, BookObj_GetBookID(selected_book), msg, (void (*)(void *))mfree_adr());
    }
    else
    {
      MessageBox(EMPTY_TEXTID, STR("Unknown Author"), NOIMAGE, 1, 0, pActBook);
    }
  }
}

void RefreshElfSoftkeys(BOOK_MANAGER *data)
{
  if (data->elfs_count)
  {
    BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, data->elf_index);
    if (!elem->gui_count)
      GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, FALSE);
    else
      GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, TRUE);
    GUIObject_SoftKeys_SetEnable(data->elf_menu, ACTION_DELETE, TRUE);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, 0, TRUE);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, 1, TRUE);
  }
  else
  {
    ListMenu_SetNoItemText(data->elf_menu, STR("No ELF in memory"));
    GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetEnable(data->elf_menu, ACTION_DELETE, FALSE);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, 0, FALSE);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, 1, FALSE);
    data->elf_index = NULL;
  }
}

int Elf_OpenFile(const wchar_t *filepath, const wchar_t *filename)
{
  W_FSTAT _wstat;
  if (!w_fstat(BCFGEDIT_PATH, &_wstat))
  {
  }
  else
  {
    return BCFG_NOTFOUND; // BcfgEdit not found
  }

  if (!filepath || !filename)
    return BCFG_SUCCESS; // success

  openWithBcfgEdit(BCFGEDIT_PATH, filepath, filename);
  return BCFG_NULL;
}

void onBcfgConfig(BOOK *book, GUI *lt)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *selected_book = GetBook(TAB_ELFS);
  if (selected_book)
  {
    if (CheckEvent(selected_book, ELF_BCFG_CONFIG_EVENT))
    {
      int err = Elf_OpenFile(NULL, NULL);
      if (err == BCFG_SUCCESS)
      {
        wchar_t bcfg_path[256];
        wchar_t bcfg_name[256];

        MSG_BCFG *msg = (MSG_BCFG *)malloc(sizeof(MSG_BCFG));
        msg->book = pActBook;
        msg->bcfg_p = bcfg_path;
        msg->bcfg_n = bcfg_name;
        UI_Event_toBookIDwData(ELF_BCFG_CONFIG_EVENT, BookObj_GetBookID(selected_book), msg, (void (*)(void *))mfree);
      }
      else if (err == BCFG_NOTFOUND)
      {
        MessageBox(EMPTY_TEXTID, STR("BcfgEdit.elf not found!"), NOIMAGE, 1, 0, pActBook);
      }
    }
    else
    {
      MessageBox(EMPTY_TEXTID, STR("ELF doesn't support BcfgConfigEvent"), NOIMAGE, 1, 0, pActBook);
    }
  }
}

int ElfMenu_onMessage(GUI_MESSAGE *msg)
{
  BOOK_MANAGER *data = GetData();
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    if (data->elfs_count)
    {
      int index = GUIonMessage_GetCreatedItemIndex(msg);
      BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, index);
      GUIonMessage_SetMenuItemText(msg, Get_BookName(data, elem->book_name));
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ELFS_ITEM_ICON);
      if (!elem->gui_count)
      {
        GUIonMessage_SetItemDisabled(msg, TRUE);
        GUIonMessage_SetMenuItemUnavailableText(msg, STR("Can't set focus to ELF without GUI..."));
      }
    }
    break;
  case LISTMSG_HighlightChanged:
    data->elf_index = GUIonMessage_GetSelectedItem(msg);
    RefreshElfSoftkeys(data);
    break;
  }
  return 1;
}

TEXTID GetElfCountTextID(BOOK_MANAGER *data)
{
  wchar_t buf[64];
  snwprintf(buf, MAXELEMS(buf), L"Active ELFs: %d", data->elfs_count);
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" void CreateElfMenu(BOOK *book, int tab_num)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK_MANAGER *data = GetData();

  if (data->elf_index > data->elfs_count - 1)
    data->elf_index = data->elfs_count - 1;

  data->elf_menu = CreateListMenu(pActBook, UIDisplay_Main);
  ListMenu_SetOnMessage(data->elf_menu, ElfMenu_onMessage);
  ListMenu_SetItemCount(data->elf_menu, data->elfs_count);
  ListMenu_SetCursorToItem(data->elf_menu, data->elf_index);
  GUIObject_SetStyle(data->elf_menu, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->elf_menu, 1);
  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_BACK, Close_Activitymenu);
  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_LONG_BACK, Exit_to_Standby);
  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_SELECT1, onEnterPressed_Elfs);

  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_DELETE, Delete_book_and_elf);
  GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_DELETE, FALSE);
  GUIObject_SoftKeys_SetAction(data->elf_menu, 0, onBcfgConfig);
  GUIObject_SoftKeys_SetText(data->elf_menu, 0, STR("Config"));
  GUIObject_SoftKeys_SetAction(data->elf_menu, 1, onAuthor);
  GUIObject_SoftKeys_SetText(data->elf_menu, 1, STR("Author"));

  RefreshElfSoftkeys(data);

  TabMenuBar_SetTabGui(pActBook->main_tab, tab_num, data->elf_menu);
  TabMenuBar_SetTabTitle(pActBook->main_tab, tab_num, GetElfCountTextID(data));
}

#ifndef DB2010
void ShortcutMenu_onEnterPressed(BOOK *book, GUI *gui)
{
  BOOK_MANAGER *data = GetData();
  int item = ListMenu_GetSelectedItem(data->sc_menu);
  if (item == SHC_ITEM_1)
  {
    REQUEST_SYSTEM_SHUTDOWN();
  }
  else if (item == SHC_ITEM_2)
  {
    REQUEST_SYSTEM_RESTART();
  }
  else if (item == SHC_ITEM_3)
  {
    Shortcut_Run(BRIGHTNESS_SHC);
  }
  else if (item == SHC_ITEM_4)
  {
    if (FlightMode_GetState())
      FlightMode_SetState(ON);
    else
      FlightMode_SetState(OFF);
  }
  else if (item == SHC_ITEM_5)
  {
    int _SYNC = NULL;
    int *SYNC = &_SYNC;
    Request_ICA_ShutdownAllConnections(SYNC);
  }
  FreeBook(book);
}

int ShortcutMenu_onMessage(GUI_MESSAGE *msg)
{
  int item = GUIonMessage_GetCreatedItemIndex(msg);
  if (item == SHC_ITEM_1)
  {
    GUIonMessage_SetMenuItemText(msg, STR("Shutdown"));
  }
  else if (item == SHC_ITEM_2)
  {
    GUIonMessage_SetMenuItemText(msg, STR("Restart"));
  }
  else if (item == SHC_ITEM_3)
  {
    wchar_t buf[32];
    snwprintf(buf, MAXELEMS(buf), L"Brightness: %d%%", Display_GetBrightness(UIDisplay_Main));
    GUIonMessage_SetMenuItemText(msg, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
  }
  else if (item == SHC_ITEM_4)
  {
    if (!FlightMode_GetState())
    {
      if (dll_ConnectionManager_Connection_GetState())
      {
        GUIonMessage_SetMenuItemText(msg, STR("Flightmode: not available"));
        GUIonMessage_SetItemDisabled(msg, TRUE);
      }
      else
        GUIonMessage_SetMenuItemText(msg, STR("Flightmode: off"));
    }
    else
      GUIonMessage_SetMenuItemText(msg, STR("Flightmode: on"));
  }
  else if (item == SHC_ITEM_5)
  {
    if (!dll_ConnectionManager_Connection_GetState())
      GUIonMessage_SetItemDisabled(msg, TRUE);
    GUIonMessage_SetMenuItemText(msg, STR("Close connection"));
  }
  return 1;
}

extern "C" void CreateShortcutMenu(BOOK *book, int tab_num)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK_MANAGER *data = GetData();
  data->sc_menu = CreateListMenu(pActBook, UIDisplay_Main);
  ListMenu_SetOnMessage(data->sc_menu, ShortcutMenu_onMessage);
  ListMenu_SetItemCount(data->sc_menu, SHC_ITEM_LAST);
  ListMenu_SetCursorToItem(data->sc_menu, SHC_ITEM_1);
  GUIObject_SetStyle(data->sc_menu, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->sc_menu, 1);
  GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_BACK, Close_Activitymenu);
  GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_LONG_BACK, Exit_to_Standby);
  GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_SELECT1, ShortcutMenu_onEnterPressed);

  TabMenuBar_SetTabGui(pActBook->main_tab, tab_num, data->sc_menu);
  TabMenuBar_SetTabTitle(pActBook->main_tab, tab_num, STR("My shortcut"));
}
#endif

int LIST_ELEM_Filter(void *elem)
{
  return (elem ? TRUE : FALSE);
}

void LIST_ELEM_Destroy(void *data)
{
  BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)data;
  if (elem)
  {
    mfree(elem->book_name);
    elem->book_name = NULL;
    mfree(elem);
  }
}

void DestroyLists(BOOK_MANAGER *data)
{
  if (data->books_list)
  {
    List_DestroyElements(data->books_list, LIST_ELEM_Filter, LIST_ELEM_Destroy);
    List_Destroy(data->books_list);
    data->books_list = NULL;
  }
  if (data->elfs_list)
  {
    List_DestroyElements(data->elfs_list, LIST_ELEM_Filter, LIST_ELEM_Destroy);
    List_Destroy(data->elfs_list);
    data->elfs_list = NULL;
  }
}

void Destroy_ini_Buffer(BOOK_MANAGER *data)
{
  if (data->books_name_buf)
  {
    mfree(data->books_name_buf);
    data->books_name_buf = NULL;
  }
  if (data->shortcut_buf)
  {
    mfree(data->shortcut_buf);
    data->shortcut_buf = NULL;
  }
}

#ifndef DB2010
int isRSSTickerBook(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, RSSTicker_Book);
}
#endif

extern "C" void CreateBookAndElfsLists()
{
  BOOK_MANAGER *data = GetData();

  Destroy_ini_Buffer(data);
  DestroyLists(data);

  Load_booknames(data);
  Load_shortcuts(data);

  int total_gui = NULL;
  int books_count = NULL;
  int elfs_count = NULL;

  DB_EXT *dbExt = (DB_EXT *)LastExtDB;
  int mask = ((int)dbExt) & FLASH_MASK;

  data->books_list = List_Create();
  data->elfs_list = List_Create();

  int total_session = root_list_get_session_count();

  for (int session_index = 0; session_index < total_session; session_index++)
  {
    UI_APP_SESSION *session = root_list_get_session(session_index);
    for (int listbook_index = 0; listbook_index < List_GetCount(session->listbook); listbook_index++)
    {
      BOOK *book = (BOOK *)List_Get(session->listbook, listbook_index);
      if ((total_gui = List_GetCount(book->xguilist->guilist)) || (((int)book->onClose) & FLASH_MASK) != mask)
      {
#ifdef DB2010
        if (!IsVolumeControllerBook(book) && !IsRightNowBook(book))
#else
        if (!IsVolumeControllerBook(book) && !IsRightNowBook(book) && !isRSSTickerBook(book))
#endif
        {
          char str_tmp[MAX_BOOK_NAME_LEN + 1];
          BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)malloc(sizeof(BOOK_LIST_ELEM));
          elem->book = book;
          elem->gui_count = total_gui;
          elem->isJava = FALSE;

          if (strcmp(book->xbook->name, "CUIDisplayableBook"))
          {
            char *bookname = (char *)malloc(strlen(book->xbook->name) + 1);
            strcpy(bookname, book->xbook->name);
            elem->book_name = bookname;
          }
          else
          {
            TextID_GetString(BookObj_GetSession(book)->name, str_tmp, MAXELEMS(str_tmp));
            char *bookname = (char *)malloc(strlen(str_tmp) + 1);
            strcpy(bookname, str_tmp);
            elem->book_name = bookname;
            elem->isJava = TRUE;
          }

          if (elem->isJava)
          {
            elem->book_icon = DB_LIST_JAVA_ICN;
            void *JavaDesc;
            char sp1;
            JavaDialog_Open(0, &sp1, &JavaDesc);

            if (!JavaAppDesc_GetFirstApp(JavaDesc))
            {
              int len = strlen(elem->book_name) + 1;
              wchar_t *book_name = (wchar_t *)malloc(sizeof(wchar_t) * len);
              str2wstr(book_name, elem->book_name);
              bool next = true;
              while (next)
              {
                wchar_t *name;
                JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVAAPP_NAME, &name);

                if (!wstrncmp(book_name, name, 8))
                {
                  wchar_t *fullpath;
                  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVAAPP_FULLPATH, &fullpath);
                  JavaApp_LogoImageID_Get(fullpath, &elem->book_icon);
                  mfree(fullpath);
                  next = false;
                }
                mfree(name);

                if (JavaAppDesc_GetNextApp(JavaDesc))
                  next = false;
              }
              mfree(book_name);
            }
            JavaDialog_Close(sp1);
          }

          TEXTID javaname = GetJavaName(book);
          if (javaname != EMPTY_TEXTID)
          {
            mfree(elem->book_name);
            TextID_GetString(javaname, str_tmp, MAXELEMS(str_tmp));
            int len = strlen(str_tmp) + 1;
            char *java_name = (char *)malloc(len);
            strcpy(java_name, str_tmp);
            elem->book_name = java_name;
            TextID_Destroy(javaname);
          }

          else if ((((int)book->onClose) & FLASH_MASK) == mask)
          {
            List_InsertFirst(data->books_list, elem);
            books_count++;
          }
          else
          {
            List_InsertFirst(data->elfs_list, elem);
            elfs_count++;
          }
        }
      }
    }
  }
  data->books_count = books_count;
  data->elfs_count = elfs_count;
}

void DestroyAllGUIs(BOOK_MANAGER *data)
{
  FREE_GUI(data->books_menu);
  data->book_index = NULL;
  FREE_GUI(data->elf_menu)
  data->elf_index = NULL;
  FREE_GUI(data->sc_menu)
}

extern "C" void ActivityBook_onClose()
{
  BOOK_MANAGER *data = GetData();
  Destroy_ini_Buffer(data);
  DestroyAllGUIs(data);
  DestroyLists(data);
}

extern "C" TEXTID EventsTitleText()
{
  wchar_t buf[32];
  snwprintf(buf, MAXELEMS(buf), L"New event: %d", NewEvents_GetCount());
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" int GetFocusTab()
{
  BOOK_MANAGER *data = GetData();
  return data->tab_pos;
}
