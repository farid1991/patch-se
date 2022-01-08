/*
;Book Manager
;Support for custom names of the books, on file bookman.ini (/usb/other/ini/bookman.ini)
;Hotkeys:
;* - close all the books and goto Standby
;# - Minimize all the books and goto Standby
;C - Kill the book
;(c) Hussein
;(r) IronMaster, den_po
;(p) farid
*/
#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\QuickAccessBook.h"

#include "Lib.h"
#include "main.h"
#include "string.h"

//===========================================================

void *malloc(int size)
{
#if defined(DB2010)
  return (memalloc(size, 1, 5, "bm", 0));
#elif defined(DB2020)
  return (memalloc(0, size, 1, 5, "bm", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "bm", 0));
#endif
}

void mfree(void *mem)
{
#if defined(DB2010)
  memfree(mem, "bm", 0);
#elif defined(DB2020)
  if (mem)
    memfree(0, mem, "bm", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "bm", 0);
#endif
}

//===========================================================

BOOK_MANAGER *CreateData()
{
  BOOK_MANAGER *data = (BOOK_MANAGER *)malloc(sizeof(BOOK_MANAGER));
  memset(data, NULL, sizeof(BOOK_MANAGER));
  set_envp(get_bid(current_process()), EMP_NAME, (OSADDRESS)data);
  return data;
}

BOOK_MANAGER *GetData()
{
  BOOK_MANAGER *data = (BOOK_MANAGER *)get_envp(get_bid(current_process()), EMP_NAME);
  if (data)
    return data;
  return CreateData();
}

BOOK_LIST_ITEM *GetBookListItem(BOOK *book)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  BOOK_MANAGER *data = GetData();

  BOOK_LIST_ITEM *elem;
  data->blistpos = ListMenu_GetSelectedItem(qa_book->menu);
  elem = (BOOK_LIST_ITEM *)List_Get(data->books_list, data->blistpos);

  return elem;
}

BOOK *GetBook(BOOK *book)
{
  BOOK_LIST_ITEM *elem = GetBookListItem(book);
  if (!elem)
    return NULL;
  else
    return elem->book;
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
          return TRUE;
        pm++;
      }
    }
  }
  return FALSE;
}

void GetIconByName(wchar_t *name, int &id)
{
  if (name[0] == '0' && name[1] == 'x')
  {
    id = 0;
    int N = 0x1000;
    for (int i = 0; i < 4; i++)
    {
      id += wcharh2int(name[2 + i]) * N;
      N = N / 0x10;
    }
  }
  else
  {
    iconidname2id(name, -1, &id);
  }
}

TEXTID GetBookName(char *section)
{
  BOOK_MANAGER *data = GetData();

  wchar_t buffer[50];
  TEXTID text_id = 0;

  if (data->buf_ini)
  {
    char *param;
    if (param = manifest_GetParam(data->buf_ini, section, 0))
    {
      win12512unicode(buffer, param, 49);
      text_id = TextID_Create(buffer, ENC_UCS2, TEXTID_ANY_LEN);
      mfree(param);
    }
  }
  if (!text_id)
  {
    win12512unicode(buffer, section, 49);
    text_id = TextID_Create(buffer, ENC_UCS2, wstrlen(buffer));
  }
  return text_id;
}

IMAGEID GetBookIcon(char *book_name, int default_img)
{
  BOOK_MANAGER *data = GetData();

  char *pos;
  char *end_pos;
  wchar_t ws[50];

  int image_id = 0;
  int len = strlen(book_name);

  if (data->buf_ini)
  {
    char *param;
    pos = strstr(data->buf_ini, book_name);
    end_pos = pos + len + sizeof("\r\n") - sizeof("");
    if (param = manifest_GetParam(end_pos, "ICON", 0))
    {
      win12512unicode(ws, param, 49);
      GetIconByName(ws, image_id);
      mfree(param);
    }
  }
  if (!image_id)
    image_id = default_img;
  return image_id;
}

//----------------------------------------------------------------------------------------------//

int LIST_ITEM_Filter(void *elem)
{
  return (elem ? TRUE : FALSE);
}

void BOOK_LIST_ITEM_Destroy(void *data)
{
  BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)data;
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
    List_DestroyElements(data->books_list, LIST_ITEM_Filter, BOOK_LIST_ITEM_Destroy);
    List_Destroy(data->books_list);
    data->books_list = NULL;
  }
}

void DestroyConfigBuffers(BOOK_MANAGER *data)
{
  if (data->buf_ini)
  {
    mfree(data->buf_ini);
    data->buf_ini = NULL;
  }
}

BOOL IsRSSTickerBook(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, RSSTicker_Book);
}

BOOL IsQuickAccessBook(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, QuickAccessBk);
}

int GetConfig(char **ini_set)
{
  int file;
  char *ini = NULL;
  int size = 0;
  FSTAT _fstat;
  if (fstat(BOOKMAN_PATH, BOOKMAN_INI, &_fstat) == 0)
  {
    if ((file = _fopen(BOOKMAN_PATH, BOOKMAN_INI, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
    {
      ini = StringAlloc(_fstat.fsize);
      fread(file, ini, _fstat.fsize);
      fclose(file);
      size = _fstat.fsize;
    }
  }
  ini_set[0] = ini;
  return size;
}

void Init_ConfigFile(BOOK_MANAGER *data)
{
  char *sp;
  data->buf_size = GetConfig(&sp);
  data->buf_ini = sp;
}

extern "C" void CreateBooksList()
{
  BOOK_MANAGER *data = GetData();
  //===============================Clear Buffer================================

  DestroyConfigBuffers(data);
  DestroyLists(data);

  //=============================Ini initializaton=============================

  Init_ConfigFile(data);

  //===============================Create List=================================

  data->books_list = List_Create();

  //=============================GUI Counter===================================

  int gui_count;

  //===========================Start List Counter==============================

  // int books_cnt = NULL;
  // int elfs_cnt = NULL;

  //======================Add item to  Books and Elfs List=====================

  char buf_name[MAX_BOOK_NAME_LEN + 1];

  DB_EXT *_mask = LastExtDB;
  int mask = ((int)_mask) & FLASH_MASK;

  int i = root_list_get_session_count();
  for (int j = 0; j < i; j++)
  {
    UI_APP_SESSION *session = root_list_get_session(j);
    for (int k = 0; k < List_GetCount(session->listbook); k++)
    {
      BOOK *book = (BOOK *)List_Get(session->listbook, k);
      if ((gui_count = List_GetCount(book->xguilist->guilist) || ((int)book->onClose) & FLASH_MASK) != mask)
      {
        if (!IsVolumeControllerBook(book) && !IsRightNowBook(book) && !IsRSSTickerBook(book))
        {
          BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)malloc(sizeof(BOOK_LIST_ITEM));
          elem->book = book;
          elem->gui_count = gui_count;
          elem->isJava = FALSE;

          if (strcmp(book->xbook->name, JAVA_BOOK_NAME))
          {
            char *bookname = StringAlloc(strlen(book->xbook->name));
            strcpy(bookname, book->xbook->name);
            elem->book_name = bookname;
          }
          else
          {
            TextID_GetString(BookObj_GetSession(book)->name, buf_name, MAXELEMS(buf_name));
            char *bookname = StringAlloc(strlen(buf_name));
            strcpy(bookname, buf_name);
            elem->book_name = bookname;
            elem->isJava = TRUE;
          }

          if (elem->isJava)
          {
            elem->book_icon = DB_LIST_JAVA_ICN;
            char sp1;
            void *JavaDesc;
            JavaDialog_Open(0, &sp1, &JavaDesc);
            if (!JavaAppDesc_GetFirstApp(JavaDesc))
            {
              wchar_t *book_name = WStringAlloc(strlen(elem->book_name));
              str2wstr(book_name, elem->book_name);
              bool next = true;
              while (next)
              {
                wchar_t *JavaAppName;
                JavaAppDesc_GetJavaAppInfo(JavaDesc, 0, &JavaAppName);

                if (!wstrncmp(book_name, JavaAppName, 8))
                {
                  wchar_t *JavaAppPath;
                  JavaAppDesc_GetJavaAppInfo(JavaDesc, 5, &JavaAppPath);
                  JavaApp_LogoImageID_Get(JavaAppPath, &elem->book_icon);
                  mfree(JavaAppPath);
                  next = false;
                }
                mfree(JavaAppName);

                if (JavaAppDesc_GetNextApp(JavaDesc))
                  next = false;
              }
              mfree(book_name);
            }
            JavaDialog_Close(sp1);
          }

          if ((((int)book->onClose) & FLASH_MASK) == mask)
          {
            List_InsertFirst(data->books_list, elem);
            // books_cnt++;
          }
          // else
          // {
          //   List_InsertFirst(data->elfs_list, elem);
          //   elfs_cnt++;
          // }
        }
      }
    }
  }
  //========================Add item to shortcut list===========================

  // data->shortcut_list = LoadShortcut();

  //============================ List Counter ==================================

  data->blistcnt = List_GetCount(data->books_list);
  // data->blistcnt = books_cnt;
}

extern "C" void DestroyBookMenu(BOOK *book)
{
  BOOK_MANAGER *data = GetData();
  DestroyConfigBuffers(data);
  DestroyLists(data);

  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  FREE_GUI(qa_book->menu);
}

//===========================================================

TEXTID GetTitleText()
{
  wchar_t buf[64];
  snwprintf(buf, MAXELEMS(buf), L"Heap: %dKB", GetFreeBytesOnHeap() / 1024);
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

void BookMenu_onDelete_BookAndElfs(BOOK *book, GUI *gui)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;

  BOOK_LIST_ITEM *elem = GetBookListItem(qa_book);
  if (elem)
  {
    BOOK *SelectedBook = elem->book;
    if (SelectedBook != Find_StandbyBook())
    {
      if (elem->isJava)
      {
        UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(SelectedBook));
      }
      else
      {
        if (CheckEv(SelectedBook, TERMINATE_SESSION_EVENT))
        {
          UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID((BOOK *)List_Get(SelectedBook->xbook->app_session->listbook, List_GetCount(SelectedBook->xbook->app_session->listbook) - 1)));
        }
        else if (CheckEv(SelectedBook, RETURN_TO_STANDBY_EVENT))
        {
          UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID((BOOK *)List_Get(SelectedBook->xbook->app_session->listbook, List_GetCount(SelectedBook->xbook->app_session->listbook) - 1)));
        }
        else
        {
          if (elem->gui_count)
          {
            BookObj_SetFocus(SelectedBook, 0);
            GUI *gui = (GUI *)List_Get(SelectedBook->xguilist->guilist, elem->gui_count - 1);
            GUIObject_SoftKeys_ExecuteAction(gui, ACTION_LONG_BACK);
            BookObj_SetFocus(qa_book, 0);
          }
        }
      }
      //UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
      restart_BookMenu(qa_book);
    }
  }
}

void BookMenu_CloseMenu(BOOK *book, GUI *gui)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  FreeBook(qa_book);
}

void BookMenu_SelectBook(BOOK *book, GUI *gui)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  BookObj_SetFocus(GetBook(qa_book), UIDisplay_Main);
  FreeBook(qa_book);
}

void BookMenu_MinimizeAllBooks(BOOK *book, GUI *gui)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;

  BOOK *StandbyBook = Find_StandbyBook();
  if (StandbyBook)
    BookObj_SetFocus(StandbyBook, UIDisplay_Main);

  FreeBook(qa_book);
}

void BookMenu_KillAllBooks(BOOK *book, GUI *gui)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  UI_Event(RETURN_TO_STANDBY_EVENT);
  FreeBook(qa_book);
}

int BookMenu_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    BOOK_MANAGER *data = GetData();
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)List_Get(data->books_list, item);
    GUIonMessage_SetMenuItemText(msg, GetBookName(elem->book_name));
    if (elem->isJava)
      GUIonMessage_SetMenuItemIcon(msg, 0, elem->book_icon);
    else
      GUIonMessage_SetMenuItemIcon(msg, 0, GetBookIcon(elem->book_name, BOOK_ITEM_ICON));
    break;
  }
  return 1;
}

extern "C" int CreateBookMenu(void *wdata, BOOK *book)
{
  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  BOOK_MANAGER *data = GetData();

  if (data->blistpos > (data->blistcnt - 1))
    data->blistpos = data->blistcnt - 1;

  FREE_GUI(qa_book->menu);

  if (qa_book->menu = CreateListMenu(qa_book, UIDisplay_Main))
  {
    GUIObject_SetStyle(qa_book->menu, UI_OverlayStyle_FullScreenNoStatus);
    GUIObject_SetTitleType(qa_book->menu, UI_TitleMode_Large);
    GUIObject_SetTitleText(qa_book->menu, STR("Book Manager"));
    GUIObject_SetSecondRowTitleText(qa_book->menu, GetTitleText());

    ListMenu_SetOnMessage(qa_book->menu, BookMenu_onMessage);
    ListMenu_SetItemCount(qa_book->menu, data->blistcnt);
    ListMenu_SetCursorToItem(qa_book->menu, data->blistpos);
    ListMenu_SetBackgroundImage(qa_book->menu, 0x1E2C);

    GUIObject_SoftKeys_SetAction(qa_book->menu, ACTION_SELECT1, BookMenu_SelectBook);
    GUIObject_SoftKeys_SetAction(qa_book->menu, ACTION_BACK, BookMenu_CloseMenu);
    GUIObject_SoftKeys_SetAction(qa_book->menu, ACTION_LONG_BACK, BookMenu_KillAllBooks);

    GUIObject_SoftKeys_SetAction(qa_book->menu, ACTION_DELETE, BookMenu_onDelete_BookAndElfs);
    GUIObject_SoftKeys_SetVisible(qa_book->menu, ACTION_DELETE, FALSE);
    GUIObject_SoftKeys_SetAction(qa_book->menu, 0, BookMenu_MinimizeAllBooks);
    GUIObject_SoftKeys_SetItemOnKey(qa_book->menu, 0, KEY_DIEZ, KBD_SHORT_PRESS);
    GUIObject_SoftKeys_SetAction(qa_book->menu, 1, BookMenu_KillAllBooks);
    GUIObject_SoftKeys_SetItemOnKey(qa_book->menu, 1, KEY_STAR, KBD_SHORT_PRESS);

    GUIObject_Show(qa_book->menu);
  }

  return 1;
}

void restart_BookMenu(BOOK *book)
{
  BOOK_MANAGER *data = GetData();

  QuickAccessBook *qa_book = (QuickAccessBook *)book;
  
  ListMenu_DestroyItems(qa_book->menu);
  CreateBooksList();
  CreateBookMenu(NULL, qa_book);
}
