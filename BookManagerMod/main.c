#include "temp\target.h"

#include "..\\include\Types.h"

#ifdef A1
#include "..\\include\book\RightNowBook.h"
#else
#include "..\\include\book\ActivityMenuBook.h"
#endif

#include "Lib.h"
#include "main.h"

__arm void _elfload(const wchar_t *filepath, const wchar_t *filename)
{
  elfload(L"/usb/other/ZBin/BcfgEdit.elf", (void *)filepath, (void *)filename, 0);
}

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "bm_mem", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "bm_mem", 0);
#else
  return memalloc(size, 1, 5, "bm_mem", 0);
#endif
}

void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "bm_mem", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "bm_mem", 0);
#else
  if (mem)
    memfree(mem, "bm_mem", 0);
#endif
}

BOOK_MANAGER *CreateData()
{
  BOOK_MANAGER *data = (BOOK_MANAGER *)malloc(sizeof(BOOK_MANAGER));
  memset(data, NULL, sizeof(BOOK_MANAGER));
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
int dll_ConnectionManager_Connection_GetState()
{
  return ConnectionManager_Connection_GetState();
}
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

int GetJavaName(BOOK *book)
{
  char s[100];
  TextID_GetString(BookObj_GetSession(book)->name, s, MAXELEMS(s));

  if (!strncmp(s, "Foreign app", 11))
  {
    return JavaSession_GetName();
  }

  if (!strcmp(s, "Java"))
  {
    return JavaSession_GetName();
  }
  return 0;
}

int get_file(char **cfg_buffer)
{
  int file;
  char *buffer = NULL;
  int size = NULL;
  FSTAT _fstat;
  if (fstat(BOOKMAN_PATH, BOOKMAN_INI, &_fstat) == 0)
  {
    if ((file = _fopen(BOOKMAN_PATH, BOOKMAN_INI, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
    {
      buffer = (char *)malloc(_fstat.fsize + 1);
      fread(file, buffer, _fstat.fsize);
      fclose(file);
      size = _fstat.fsize;
    }
  }
  cfg_buffer[0] = buffer;
  return size;
}

void Init_ConfigFile(BOOK_MANAGER *data)
{
  char *buffer;
  data->buffer_size = get_file(&buffer);
  if (data->cfg_buffer)
    mfree(data->cfg_buffer);
  data->cfg_buffer = buffer;
}

int GetActiveTab(BOOK *book)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  return TabMenuBar_GetFocusedTab(pActBook->main_tab);
}

BOOK_LIST_ELEM *GetBookListItem(int tab_num)
{
  BOOK_MANAGER *data = GetData();
  BOOK_LIST_ELEM *elem;
  switch (tab_num)
  {
  case TAB_BOOKS:
    data->book_index = ListMenu_GetSelectedItem(data->books_menu);
    elem = (BOOK_LIST_ELEM *)List_Get(data->books_list, data->book_index);
    break;
  case TAB_ELFS:
    if (data->elfs_count)
      elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, data->elf_index);
    else
      return NULL;
    break;
  }
  return elem;
}

BOOK *GetBook(int tab_num)
{
  BOOK_LIST_ELEM *elem = GetBookListItem(tab_num);
  return (elem ? elem->book : NULL);
}

int CheckEvent(BOOK *book, int event)
{
  if (book->base_page)
  {
    const PAGE_MSG *pm = book->base_page->msg_lst;
    if (pm)
    {
      while (pm->msg && pm->proc)
      {
        if (pm->msg == event)
          return 1;
        pm++;
      }
    }
  }
  return 0;
}

void onDelete_BookAndElfs(BOOK *rbook, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)rbook;

  BOOK_MANAGER *data = GetData();
  if (GetActiveTab(pActBook) == TAB_BOOKS)
  {
    BOOK_LIST_ELEM *elem = GetBookListItem(TAB_BOOKS);
    if (elem)
    {
      BOOK *book = elem->book;
      if (book != Find_StandbyBook())
      {
        if (elem->isJava == TRUE)
          UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(book));
        else
        {
          if (CheckEvent(book, TERMINATE_SESSION_EVENT))
            UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID((BOOK *)List_Get(book->xbook->app_session->listbook, List_GetCount(book->xbook->app_session->listbook) - 1)));
          else if (CheckEvent(book, RETURN_TO_STANDBY_EVENT))
            UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID((BOOK *)List_Get(book->xbook->app_session->listbook, List_GetCount(book->xbook->app_session->listbook) - 1)));
        }
        UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
        data->elf = FALSE;
      }
    }
  }
  else
  {
    if (data->elfs_count)
    {
      BOOK *book = GetBook(TAB_ELFS);
      if (book)
      {
        if (CheckEvent(book, RETURN_TO_STANDBY_EVENT))
          UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID(book));
        else
        {
          if (CheckEvent(book, ELF_TERMINATE_EVENT))
            UI_Event_toBookID(ELF_TERMINATE_EVENT, BookObj_GetBookID(book));
          else
            MessageBox(EMPTY_TEXTID, STR("TerminateEvent not supported by elf..."), NOIMAGE, 1, 2500, book);
        }
        UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
        data->elf = TRUE;
      }
    }
  }
}

void onCloseBook(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  FreeBook(pActBook);
}

void onLongCloseBook(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  FreeBook(pActBook);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void onEnterPressed_Books(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *bk = GetBook(TAB_BOOKS);
  if (bk)
  {
    BookObj_SetFocus(bk, UIDisplay_Main);
    FreeBook(pActBook);
  }
}

void Minimize_AllBooks(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  BOOK *standbyBook = Find_StandbyBook();
  if (standbyBook)
  {
    BookObj_SetFocus(standbyBook, UIDisplay_Main);
    FreeBook(pActBook);
  }
}

void Close_AllBooks(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;
  UI_Event(RETURN_TO_STANDBY_EVENT);
  FreeBook(pActBook);
}

void myOnKey_Unified(DISP_OBJ *disp_obj, int keyID, int i2, int i3, int press_mode)
{
  BOOK_MANAGER *data = GetData();

  data->oldOnKey(disp_obj, keyID, i2, i3, press_mode);

  if (keyID == KEY_DIEZ && press_mode == KBD_SHORT_RELEASE)
  {
    Minimize_AllBooks(data->RightNowBook, NULL);
  }
  else if (keyID == KEY_STAR && press_mode == KBD_SHORT_RELEASE)
  {
    Close_AllBooks(data->RightNowBook, NULL);
  }
}

TEXTID GetBookName(char *book_name)
{
  wchar_t ws[MAX_BOOK_NAME_LEN];
  TEXTID ret = 0;
  BOOK_MANAGER *data = GetData();

  if (data->cfg_buffer)
  {
    char *param;
    if (param = manifest_GetParam(data->cfg_buffer, book_name, NULL))
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

IMAGEID GetBookIcon(char *book_name, int iconid)
{
  BOOK_MANAGER *data = GetData();

  char *pos;
  char *end_pos;
  wchar_t ws[MAX_BOOK_NAME_LEN];

  int ret = 0;
  int len = strlen(book_name);

  if (data->cfg_buffer)
  {
    char *param;
    pos = strstr(data->cfg_buffer, book_name);
    end_pos = pos + len + sizeof("\r\n") - sizeof("");
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
    GUIonMessage_SetMenuItemText(msg, GetBookName(elem->book_name));

    if (elem->isJava)
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->book_icon);
    else
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, GetBookIcon(elem->book_name, BOOK_ITEM_ICON));

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
  data->RightNowBook = book;
  data->elf = FALSE;

  if (data->book_index > data->books_count - 1)
    data->book_index = data->books_count - 1;

  data->books_menu = CreateListMenu(pActBook, UIDisplay_Main);
  ListMenu_SetOnMessage(data->books_menu, BookMenu_onMessage);
  ListMenu_SetItemCount(data->books_menu, data->books_count);
  ListMenu_SetCursorToItem(data->books_menu, data->book_index);
  GUIObject_SetStyle(data->books_menu, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->books_menu, 1);
  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_BACK, onCloseBook);
  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_LONG_BACK, onLongCloseBook);
  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_SELECT1, onEnterPressed_Books);

  GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_DELETE, onDelete_BookAndElfs);
  GUIObject_SoftKeys_SetVisible(data->books_menu, ACTION_DELETE, FALSE);

  data->oldOnKey = DispObject_GetOnKey(GUIObject_GetDispObject(data->books_menu));
  DISP_DESC_SetOnKey(DispObject_GetDESC(GUIObject_GetDispObject(data->books_menu)), myOnKey_Unified);

  TabMenuBar_SetTabGui(pActBook->main_tab, tab_num, data->books_menu);
  TabMenuBar_SetTabTitle(pActBook->main_tab, tab_num, Get_FreeHeap());
}

void onEnterPressed_Elfs(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *bk = GetBook(TAB_ELFS);
  if (bk)
  {
    BookObj_SetFocus(bk, UIDisplay_Main);
    FreeBook(pActBook);
  }
}

void onAuthor(BOOK *book, GUI *gui)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK *bk = GetBook(TAB_ELFS);
  if (bk)
  {
    if (CheckEvent(bk, ELF_SHOW_INFO_EVENT))
    {
      MSG *msg = (MSG *)malloc(sizeof(MSG));
      msg->book = pActBook;
      UI_Event_toBookIDwData(ELF_SHOW_INFO_EVENT, BookObj_GetBookID(bk), msg, (void (*)(void *))mfree_adr());
    }
    else
      MessageBox(EMPTY_TEXTID, STR("Unknown Author"), NOIMAGE, 1, 2500, pActBook);
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
    ListMenu_SetNoItemText(data->elf_menu, STR("No elfs in memory"));
    GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetEnable(data->elf_menu, ACTION_DELETE, FALSE);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, 0, FALSE);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, 1, FALSE);
    data->elf_index = NULL;
  }
}

int Elf_OpenFile(const wchar_t *filepath, const wchar_t *filename)
{
  FSTAT _fstat;
  wchar_t *bcfg_path = L"/usb/other/ZBin";
  wchar_t *bcfg_name = L"BcfgEdit.elf";

  if (!fstat(bcfg_path, bcfg_name, &_fstat))
  {
  }
  else
  {
    return 1; // BcfgEdit not found
  }
  if (!filepath || !filename)
    return 2; // success

  _elfload(filepath, filename);
  return 0;
}

void onBcfgConfig(BOOK *book, GUI *lt)
{
  BOOK *bk = GetBook(TAB_ELFS);

  if (bk)
  {
    if (CheckEvent(bk, ELF_BCFG_CONFIG_EVENT))
    {
      int err = Elf_OpenFile(NULL, NULL);
      if (err == 2)
      {
        wchar_t bcfg_path[256];
        wchar_t bcfg_name[256];

        MSG_BCFG *msg = (MSG_BCFG *)malloc(sizeof(MSG_BCFG));
        msg->book = book;
        msg->bcfg_p = bcfg_path;
        msg->bcfg_n = bcfg_name;
        UI_Event_toBookIDwData(ELF_BCFG_CONFIG_EVENT, BookObj_GetBookID(bk), msg, (void (*)(void *))mfree_adr());
      }
      else if (err == 1)
      {
        MessageBox(EMPTY_TEXTID, STR("BcfgEdit.elf not found!"), NOIMAGE, 1, 2500, book);
      }
    }
    else
    {
      MessageBox(EMPTY_TEXTID, STR("ELF doesn't support BcfgConfigEvent"), NOIMAGE, 1, 2500, book);
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
      GUIonMessage_SetMenuItemText(msg, GetBookName(elem->book_name));

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

TEXTID GetElfCount(BOOK_MANAGER *data)
{
  wchar_t buf[64];
  snwprintf(buf, MAXELEMS(buf), L"Active ELFs: %d", data->elfs_count);
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" void CreateElfMenu(BOOK *book, int tab_num)
{
  ActivityMenuBook *pActBook = (ActivityMenuBook *)book;

  BOOK_MANAGER *data = GetData();
  data->elf = TRUE;

  if (data->elf_index > data->elfs_count - 1)
    data->elf_index = data->elfs_count - 1;

  data->elf_menu = CreateListMenu(pActBook, UIDisplay_Main);
  ListMenu_SetOnMessage(data->elf_menu, ElfMenu_onMessage);
  ListMenu_SetItemCount(data->elf_menu, data->elfs_count);
  ListMenu_SetCursorToItem(data->elf_menu, data->elf_index);
  GUIObject_SetStyle(data->elf_menu, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->elf_menu, 1);
  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_BACK, onCloseBook);
  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_LONG_BACK, onLongCloseBook);
  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_SELECT1, onEnterPressed_Elfs);

  GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_DELETE, onDelete_BookAndElfs);
  GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_DELETE, FALSE);
  GUIObject_SoftKeys_SetAction(data->elf_menu, 0, onBcfgConfig);
  GUIObject_SoftKeys_SetText(data->elf_menu, 0, STR("Config"));
  GUIObject_SoftKeys_SetAction(data->elf_menu, 1, onAuthor);
  GUIObject_SoftKeys_SetText(data->elf_menu, 1, STR("Author"));

  RefreshElfSoftkeys(data);

  TabMenuBar_SetTabGui(pActBook->main_tab, tab_num, data->elf_menu);
  TabMenuBar_SetTabTitle(pActBook->main_tab, tab_num, GetElfCount(data));
}

void ShortcutMenu_onEnterPressed(BOOK *book, GUI *gui)
{
  BOOK_MANAGER *data = GetData();
  int item = ListMenu_GetSelectedItem(data->sc_menu);
  if (item == 0)
  {
    REQUEST_SYSTEM_SHUTDOWN();
  }
  else if (item == 1)
  {
    REQUEST_SYSTEM_RESTART();
  }
  else if (item == 2)
  {
    Shortcut_Run(L"Settings_Brightness_Id");
  }
  else if (item == 3)
  {
    if (FlightMode_GetState())
      FlightMode_SetState(FALSE);
    else
      FlightMode_SetState(TRUE);
  }
  else if (item == 4)
  {
    int _SYNC = 0;
    int *SYNC = &_SYNC;
    Request_ICA_ShutdownAllConnections(SYNC);
  }
  FreeBook(book);
}

int ShortcutMenu_onMessage(GUI_MESSAGE *msg)
{
  int item = GUIonMessage_GetCreatedItemIndex(msg);
  if (item == 0)
  {
    GUIonMessage_SetMenuItemText(msg, STR("Shutdown"));
  }
  else if (item == 1)
  {
    GUIonMessage_SetMenuItemText(msg, STR("Restart"));
  }
  else if (item == 2)
  {
    wchar_t buf[32];
    snwprintf(buf, MAXELEMS(buf), L"Brightness: %d%%", Display_GetBrightness(UIDisplay_Main));
    GUIonMessage_SetMenuItemText(msg, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
  }
  else if (item == 3)
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
  else if (item == 4)
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
  ListMenu_SetItemCount(data->sc_menu, 5);
  ListMenu_SetCursorToItem(data->sc_menu, 0);
  GUIObject_SetStyle(data->sc_menu, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->sc_menu, 1);
  GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_BACK, onCloseBook);
  GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_LONG_BACK, onLongCloseBook);
  GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_SELECT1, ShortcutMenu_onEnterPressed);

  TabMenuBar_SetTabGui(pActBook->main_tab, tab_num, data->sc_menu);
  TabMenuBar_SetTabTitle(pActBook->main_tab, tab_num, STR("My shortcut"));
}

int BOOK_LIST_ELEM_Filter(void *elem)
{
  return (elem ? TRUE : FALSE);
}

void BOOK_LIST_ELEM_Destroy(void *data)
{
  BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)data;
  if (elem)
  {
    if (elem->book_name)
      mfree(elem->book_name);
    mfree(elem);
  }
}

void DestroyLists(BOOK_MANAGER *data)
{
  if (data->books_list)
  {
    List_DestroyElements(data->books_list, BOOK_LIST_ELEM_Filter, BOOK_LIST_ELEM_Destroy);
    List_Destroy(data->books_list);
    data->books_list = NULL;
  }
  if (data->elfs_list)
  {
    List_DestroyElements(data->elfs_list, BOOK_LIST_ELEM_Filter, BOOK_LIST_ELEM_Destroy);
    List_Destroy(data->elfs_list);
    data->elfs_list = NULL;
  }
}

void DestroyConfigBuffer(BOOK_MANAGER *data)
{
  if (data->cfg_buffer)
  {
    mfree(data->cfg_buffer);
    data->cfg_buffer = NULL;
  }
}

#ifndef DB2010
int isRSSTickerBook(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, "RSSTicker_Book");
}
#endif

extern "C" void CreateBookAndElfsLists()
{
  BOOK_MANAGER *data = GetData();

  DestroyConfigBuffer(data);
  DestroyLists(data);

  Init_ConfigFile(data);

  int total_gui;
  int books_count = NULL;
  int elfs_count = NULL;

  DB_EXT *_mask = (DB_EXT *)LastExtDB;
  int mask = ((int)_mask) & FLASH_MASK;

  data->books_list = List_Create();
  data->elfs_list = List_Create();

  int session_total = root_list_get_session_count();

  for (int session_index = 0; session_index < session_total; session_index++)
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
          char str[MAX_BOOK_NAME_LEN + 1];
          BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)malloc(sizeof(BOOK_LIST_ELEM));
          elem->book = book;
          elem->gui_count = total_gui;
          elem->isJava = FALSE;

          if (strcmp(book->xbook->name, "CUIDisplayableBook"))
          {
            int len = strlen(book->xbook->name) + 1;
            char *bookname = (char *)malloc(len);
            strcpy(bookname, book->xbook->name);
            elem->book_name = bookname;
          }
          else
          {
            TextID_GetString(BookObj_GetSession(book)->name, str, MAXELEMS(str));
            int len = strlen(str) + 1;
            char *bookname = (char *)malloc(len);
            strcpy(bookname, str);
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
          if (javaname)
          {
            mfree(elem->book_name);
            TextID_GetString(javaname, str, MAXELEMS(str));
            int len = strlen(str) + 1;
            char *java_name = (char *)malloc(len);
            strcpy(java_name, str);
            elem->book_name = java_name;
          }

          if ((((int)book->onClose) & FLASH_MASK) == mask)
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
  DestroyConfigBuffer(data);
  DestroyAllGUIs(data);
  DestroyLists(data);
}

extern "C" TEXTID EventsTitleText()
{
  int total_evt = NewEvents_GetCount();
  wchar_t buf[32];
  snwprintf(buf, MAXELEMS(buf), L"New event: %d", total_evt);
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" int GetFocusTab()
{
  BOOK_MANAGER *data = GetData();
  return (data->elf ? TAB_ELFS : TAB_BOOKS);
}
