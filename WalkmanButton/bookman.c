#include "temp\target.h"

#include "..\\include\Types.h"

#include "bookman.h"
#include "main.h"
#include "Lib.h"
#include "StrLib.h"

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

int BOOK_LIST_ELEM_Filter(void *elem)
{
  return (elem ? TRUE : FALSE);
}

void BOOK_LIST_ELEM_Destroy(void *data)
{
  BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)data;
  if (elem)
  {
    FREE(elem->book_name);
    mfree(elem);
  }
}

void DestroyBookLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->books_list)
  {
    List_DestroyElements(bookman->books_list, BOOK_LIST_ELEM_Filter, BOOK_LIST_ELEM_Destroy);
    List_Destroy(bookman->books_list);
    bookman->books_list = NULL;
  }
}

int read_config_file(char **cfg_buffer)
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

void DestroyConfig(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE(bookman->cfg_buffer);
}

void LoadConfig(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  char *buffer;
  bookman->buffer_size = read_config_file(&buffer);
  if (bookman->cfg_buffer)
    mfree(bookman->cfg_buffer);
  bookman->cfg_buffer = buffer;
}

int GetJavaName(BOOK *book)
{
  char str[100];
  TextID_GetString(BookObj_GetSession(book)->name, str, MAXELEMS(str));

  if (!strncmp(str, "Foreign app", 11))
  {
    return JavaSession_GetName();
  }

  if (!strcmp(str, JAVA_STR))
  {
    return JavaSession_GetName();
  }
  return 0;
}

BOOL isBookManager(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, "BookManager");
}

void CreateBookLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  DestroyConfig(bookman);
  LoadConfig(bookman);

  int total_gui;

  int mask = ((int)LastExtDB) & FLASH_MASK;

  bookman->books_list = List_Create();

  int session_total = root_list_get_session_count();

  for (int session_index = 0; session_index < session_total; session_index++)
  {
    UI_APP_SESSION *session = root_list_get_session(session_index);
    for (int listbook_index = 0; listbook_index < List_GetCount(session->listbook); listbook_index++)
    {
      BOOK *book = (BOOK *)List_Get(session->listbook, listbook_index);
      if ((total_gui = List_GetCount(book->xguilist->guilist)) || (((int)book->onClose) & FLASH_MASK) != mask)
      {
        if (!IsVolumeControllerBook(book) && !IsRightNowBook(book) && !isBookManager(book))
        {
          char str[MAX_BOOK_NAME_LEN + 1];
          BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)malloc(sizeof(BOOK_LIST_ITEM));
          elem->book = book;
          elem->gui_count = total_gui;
          elem->isJava = FALSE;

          if (strcmp(book->xbook->name, CUIDisplayableBook))
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
            List_InsertFirst(bookman->books_list, elem);
          }
        }
      }
    }
  }
  bookman->books_count = List_GetCount(bookman->books_list);
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

TEXTID GetBookName(BOOK *book, char *book_name)
{
  BookManager *bookman = (BookManager *)book;

  wchar_t ws[MAX_BOOK_NAME_LEN];
  TEXTID ret = 0;

  if (bookman->cfg_buffer)
  {
    char *param;
    if (param = manifest_GetParam(bookman->cfg_buffer, book_name, NULL))
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

IMAGEID GetBookIcon(BOOK *book, char *book_name, int iconid)
{
  BookManager *bookman = (BookManager *)book;

  char *pos;
  char *end_pos;
  wchar_t ws[MAX_BOOK_NAME_LEN];

  int ret = 0;
  int len = strlen(book_name);

  if (bookman->cfg_buffer)
  {
    char *param;
    pos = strstr(bookman->cfg_buffer, book_name);
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

BOOK_LIST_ITEM *GetBookListItem(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  bookman->book_index = ListMenu_GetSelectedItem(bookman->mainmenu);
  BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)List_Get(bookman->books_list, bookman->book_index);
  return elem;
}

BOOK *GetBOOK(BOOK *bookman)
{
  BOOK_LIST_ITEM *elem = GetBookListItem(bookman);
  return (elem ? elem->book : NULL);
}

BOOL CheckEv(BOOK *book, int event)
{
  if (book->base_page)
  {
    const PAGE_MSG *pm = book->base_page->msg_lst;

    if (pm)
    {
      while (pm->msg && pm->proc)
      {
        if (pm->msg == event)
        {
          return TRUE;
        }
        pm++;
      }
    }
  }
  return FALSE;
}

void Minimize_AllBooks(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *standbyBook = Find_StandbyBook();
  if (standbyBook)
  {
    FreeBook(bookman);
    BookObj_SetFocus(standbyBook, UIDisplay_Main);
  }
}

void Close_AllBooks(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FreeBook(bookman);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void BookMan_CloseSelectedBook(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;

  BOOK_LIST_ITEM *elem = GetBookListItem(bookman);

  if (elem)
  {
    BOOK *selected_book = elem->book;

    if (selected_book != Find_StandbyBook())
    {
      if (elem->isJava == TRUE)
        UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(selected_book));
      else
      {
        if (CheckEv(selected_book, TERMINATE_SESSION_EVENT))
        {
          UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID((BOOK *)List_Get(selected_book->xbook->app_session->listbook, List_GetCount(selected_book->xbook->app_session->listbook) - 1)));
        }
        else if (CheckEv(selected_book, RETURN_TO_STANDBY_EVENT))
        {
          UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID((BOOK *)List_Get(selected_book->xbook->app_session->listbook, List_GetCount(selected_book->xbook->app_session->listbook) - 1)));
        }
        else
        {
          if (elem->gui_count)
          {
            BookObj_SetFocus(selected_book, UIDisplay_Main);
            GUI *gui = (GUI *)List_Get(selected_book->xguilist->guilist, elem->gui_count - 1);
            GUIObject_SoftKeys_ExecuteAction(gui, ACTION_LONG_BACK);
            BookObj_SetFocus(bookman, UIDisplay_Main);
          }
        }
      }
      FreeBook(bookman);
    }
  }
}

void myOnKey_Unified(DISP_OBJ *disp_obj, int keyID, int r2, int r3, int press_mode)
{
  GUI *MainMenu = DispObject_GetGUI(disp_obj);
  BookManager *bookman = (BookManager *)GUIObject_GetBook(MainMenu);

  bookman->oldOnKey(disp_obj, keyID, r2, r3, press_mode);

  if (keyID == KEY_DEL && press_mode == KBD_SHORT_RELEASE)
  {
    BookMan_CloseSelectedBook(bookman);
  }
  else if (keyID == KEY_DIEZ && press_mode == KBD_SHORT_RELEASE)
  {
    Minimize_AllBooks(bookman);
  }
  else if (keyID == KEY_STAR && press_mode == KBD_SHORT_RELEASE)
  {
    Close_AllBooks(bookman);
  }
}

void RefreshBookSoftkeys(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->books_count)
  {
    BOOK_LIST_ITEM *elem = GetBookListItem(bookman);

    if (elem->gui_count)
      GUIObject_SoftKeys_SetVisible(bookman->mainmenu, ACTION_SELECT1, TRUE);

    else
      GUIObject_SoftKeys_SetVisible(bookman->mainmenu, ACTION_SELECT1, FALSE);
  }
  else
  {
    ListMenu_SetNoItemText(bookman->mainmenu, STR("No books in memory"));
    GUIObject_SoftKeys_SetVisible(bookman->mainmenu, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetVisible(bookman->mainmenu, ACTION_DELETE, FALSE);

    bookman->book_index = 0;
  }
}

void BookMan_LClose(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  Minimize_AllBooks(bookman);
}

void BookMan_Close(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  FreeBook(bookman);
}

void BookMan_SelectItem(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *selected_book = GetBOOK(bookman);
  if (selected_book)
  {
    BookObj_SetFocus(selected_book, UIDisplay_Main);
    FreeBook(bookman);
  }
}

int BookMan_onMessage(GUI_MESSAGE *msg)
{
  BookManager *bookman = (BookManager *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    if (bookman->books_count)
    {
      int index = GUIonMessage_GetCreatedItemIndex(msg);
      BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)List_Get(bookman->books_list, index);
      GUIonMessage_SetMenuItemText(msg, GetBookName(bookman, elem->book_name));

      if (elem->isJava)
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->book_icon);
      else
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, GetBookIcon(bookman, elem->book_name, BOOK_ITEM_ICON));
    }
    break;
  case LISTMSG_HighlightChanged:
    bookman->book_index = GUIonMessage_GetSelectedItem(msg);
    RefreshBookSoftkeys(bookman);
    break;
  }
  return 1;
}

TEXTID GetFreeHeap()
{
  wchar_t buff[64];
  snwprintf(buff, MAXELEMS(buff), L"Heap: %d Kb", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

int pg_BookManager_EnterEvent(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  DestroyBookLists(bookman);
  CreateBookLists(bookman);

  if (bookman->book_index > bookman->books_count - 1)
    bookman->book_index = bookman->books_count - 1;

  if (bookman->mainmenu = CreateListMenu(bookman, UIDisplay_Main))
  {
    GUIObject_SetTitleType(bookman->mainmenu, UI_TitleMode_Large);
    GUIObject_SetTitleText(bookman->mainmenu, TextID_Create(bookman->xbook->name, ENC_LAT1, TEXTID_ANY_LEN));
    GUIObject_SetSecondRowTitleText(bookman->mainmenu, GetFreeHeap());
    GUIObject_SetStyle(bookman->mainmenu, UI_OverlayStyle_FullScreen);
    ListMenu_SetItemCount(bookman->mainmenu, bookman->books_count);
    ListMenu_SetOnMessage(bookman->mainmenu, BookMan_onMessage);
    ListMenu_SetCursorToItem(bookman->mainmenu, bookman->book_index);
    GUIObject_SoftKeys_SetAction(bookman->mainmenu, ACTION_BACK, BookMan_Close);
    GUIObject_SoftKeys_SetAction(bookman->mainmenu, ACTION_LONG_BACK, BookMan_LClose);
    GUIObject_SoftKeys_SetAction(bookman->mainmenu, ACTION_SELECT1, BookMan_SelectItem);

    DISP_OBJ *mainmenu = GUIObject_GetDispObject(bookman->mainmenu);
    bookman->oldOnKey = DispObject_GetOnKey(mainmenu);
    DISP_DESC_SetOnKey(DispObject_GetDESC(mainmenu), myOnKey_Unified);

    RefreshBookSoftkeys(bookman);
    GUIObject_Show(bookman->mainmenu);
  }
  return 1;
}

int pg_BookManager_CancelEvent(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->mainmenu);
  return 1;
}

void BookManager_onClose(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->mainmenu);
  DestroyConfig(bookman);
  DestroyBookLists(bookman);
}

void Create_BookManager()
{
  BookManager *bookman = (BookManager *)FindBook(isBookManager);
  if (!bookman)
  {
    BookManager *bookman = (BookManager *)malloc(sizeof(BookManager));
    memset(bookman, NULL, sizeof(BookManager));
    if (CreateBook(bookman, BookManager_onClose, &BookManager_Base_Page, "BookManager", NO_BOOK_ID, NULL))
    {
      bookman->mainmenu = 0;
      bookman->oldOnKey = 0;
      bookman->books_list = 0;
      bookman->books_count = 0;
      bookman->book_index = 0;
      bookman->buffer_size = 0;
      bookman->cfg_buffer = 0;
      BookObj_GotoPage(bookman, &BookManager_Main_Page);
    }
    else
    {
      mfree(bookman);
    }
  }
  else
  {
    FreeBook(bookman);
  }
}

int NextBook()
{
  int i, j;
  int root_list_count = root_list_get_session_count();
  for (i = 0; i < root_list_count; i++)
  {
    UI_APP_SESSION *session = root_list_get_session(i);
    int m = List_GetCount(session->listbook);
    for (j = 0; j < m; j++)
    {
      BOOK *book = (BOOK *)List_Get(session->listbook, j);
      if (List_GetCount(book->xguilist->guilist) && !IsVolumeControllerBook(book) && !IsRightNowBook(book))
      {
        if (!strcmp(book->xbook->name, CUIDisplayableBook))
        {
          LIST *listbook = book->xguilist->guilist;
          for (int x = 0; x < List_GetCount(listbook); x++)
          {
            GUI *gui = (GUI *)List_Get(listbook, x);
            DispObject_SetAnimation(GUIObject_GetDispObject(gui), 0x60021000);
          }
        }
        BookObj_SetFocus(book, UIDisplay_Main);
        return 1;
      }
    }
  }
  return 0;
}
