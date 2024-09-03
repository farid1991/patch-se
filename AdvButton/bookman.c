#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "book_names.h"
#include "bookman.h"
#include "edit_shortcut.h"
#include "main.h"

__arm void openWithBcfgEdit(wchar_t *bcfgedit_path, const wchar_t *filepath, const wchar_t *filename)
{
  elfload(bcfgedit_path, (void *)filepath, (void *)filename, NULL);
}

void LoadMode(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  int file = _fopen(BOOKMAN_PATH, BOOKMAN_CFG, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= NULL)
  {
    BOOKMAN_BCFG *fdata = (BOOKMAN_BCFG *)malloc(sizeof(BOOKMAN_BCFG));
    memset(fdata, NULL, sizeof(BOOKMAN_BCFG));
    fread(file, fdata, sizeof(BOOKMAN_BCFG));
    bookman->active_tab = fdata->active_tab;
    bookman->minimize_to_session = fdata->minimize_to_session;
    fclose(file);
    mfree(fdata);
  }
}

void SaveMode(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  int file = _fopen(BOOKMAN_PATH, BOOKMAN_CFG, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= NULL)
  {
    BOOKMAN_BCFG *fdata = (BOOKMAN_BCFG *)malloc(sizeof(BOOKMAN_BCFG));
    memset(fdata, NULL, sizeof(BOOKMAN_BCFG));
    fdata->active_tab = bookman->active_tab;
    fdata->minimize_to_session = bookman->minimize_to_session;
    fwrite(file, fdata, sizeof(BOOKMAN_BCFG));
    fclose(file);
    mfree(fdata);
  }
}

void onCancel_ChangeMode(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
}

void onPrevious_ChangeMode(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
}

void onSelect_ChangeMode(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  int item = OneOfMany_GetSelected(bookman->mode_list_menu);
  bookman->minimize_to_session = item;
  SaveMode(bookman);
  DestroyBookAndElfsLists(bookman);
  CreateBookAndElfsLists(bookman);
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
}

int ChangeMode_Enter_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->mode_list_menu);

  if (bookman->mode_list_menu = CreateOneOfMany(bookman))
  {
    TEXTID items_text[2] = {STR("As Book"), STR("As Session")};

    OneOfMany_SetItemCount(bookman->mode_list_menu, 2);
    OneOfMany_SetChecked(bookman->mode_list_menu, bookman->minimize_to_session);
    OneOfMany_SetTexts(bookman->mode_list_menu, items_text, 2);
    GUIObject_SetTitleText(bookman->mode_list_menu, BOOKMAN_MODE_TXT);
    GUIObject_SoftKeys_SetAction(bookman->mode_list_menu, ACTION_BACK, onPrevious_ChangeMode);
    GUIObject_SoftKeys_SetAction(bookman->mode_list_menu, ACTION_LONG_BACK, onCancel_ChangeMode);
    GUIObject_SoftKeys_SetAction(bookman->mode_list_menu, ACTION_SELECT1, onSelect_ChangeMode);
    GUIObject_Show(bookman->mode_list_menu);
  }
  return 1;
}

int ChangeMode_Exit_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->mode_list_menu);
  return 1;
}

void BookMan_ChangeMode(BOOK *book, GUI *)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_CallPage(bookman, &BookManager_ChangeMode_Page);
}

int LIST_ITEM_Filter(void *elem)
{
  return (elem ? TRUE : FALSE);
}

void BOOK_LIST_ITEM_Destroy(void *data)
{
  BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)data;
  if (elem)
  {
    mfree(elem->book_name);
    if (elem->isJava)
    {
      ImageID_Free(elem->book_icon);
    }
    mfree(elem);
  }
}

void DestroyBookLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->books_list)
  {
    List_DestroyElements(bookman->books_list, LIST_ITEM_Filter, BOOK_LIST_ITEM_Destroy);
    List_Destroy(bookman->books_list);
    bookman->books_list = NULL;
  }
}

void DestroyElfLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->elfs_list)
  {
    List_DestroyElements(bookman->elfs_list, LIST_ITEM_Filter, BOOK_LIST_ITEM_Destroy);
    List_Destroy(bookman->elfs_list);
    bookman->elfs_list = NULL;
  }
}

void SESSION_LIST_ITEM_Destroy(void *data)
{
  SESSION_LIST_ITEM *elem = (SESSION_LIST_ITEM *)data;
  if (elem)
  {
    List_DestroyElements(elem->books_list, LIST_ITEM_Filter, BOOK_LIST_ITEM_Destroy);
    List_Destroy(elem->books_list);
    mfree(elem);
  }
}

void DestroySessionLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->sessions_list)
  {
    List_DestroyElements(bookman->sessions_list, LIST_ITEM_Filter, SESSION_LIST_ITEM_Destroy);
    List_Destroy(bookman->sessions_list);
    bookman->sessions_list = NULL;
  }
}

void DestroyBookAndElfsLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  DestroySessionLists(bookman);
  DestroyBookLists(bookman);
  DestroyElfLists(bookman);
}

void DestroyAllList(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  DestroyBookAndElfsLists(bookman);
  DestroyJavaList(bookman);
}

void DestroyAllGUIs(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->java_list_menu);
  FREE_GUI(bookman->button_list_menu);
  FREE_GUI(bookman->books_list_menu);
  FREE_GUI(bookman->elf_list_menu);
  FREE_GUI(bookman->mode_list_menu);
  FREE_GUI(bookman->gui);

  if (bookman->MainMenuID != NO_BOOK_ID)
  {
    BOOK *MainMenu = FindBookByID(bookman->MainMenuID);

    if (MainMenu)
      FreeBook(MainMenu);

    bookman->MainMenuID = NO_BOOK_ID;
  }

  bookman->oldOnKey = 0;
}

int read_config_file(const wchar_t *name, void **cfg_buffer)
{
  void *buffer = NULL;
  int size = NULL;
  FSTAT _fstat;
  if (!fstat(BOOKMAN_PATH, name, &_fstat))
  {
    int file = _fopen(BOOKMAN_PATH, name, FSX_O_RDWR | FSX_O_APPEND, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (file >= NULL)
    {
      size = _fstat.fsize;
      buffer = (char *)malloc(size + 1);
      fread(file, buffer, size);
      fclose(file);
    }
  }
  *cfg_buffer = buffer;
  return size;
}

void DestroyIniBuffers(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  mfree(bookman->booknames_buf);
  mfree(bookman->shortcuts_buf);
}

void LoadBookNames(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  mfree(bookman->booknames_buf);

  void *buffer;
  bookman->booknames_buf_size = read_config_file(INI_BOOK_NAMES, &buffer);
  bookman->booknames_buf = (wchar_t *)buffer;
}

void LoadShortcuts(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  mfree(bookman->shortcuts_buf);

  void *buffer;
  bookman->shortcuts_buf_size = read_config_file(INI_SHORTCUTS, &buffer);
  bookman->shortcuts_buf = (char *)buffer;
}

TEXTID GetJavaName(BOOK *book)
{
#ifndef W700_R1CA021
#ifndef W800_R1BD001
  char str[100];
  TextID_GetString(BookObj_GetSession(book)->name, str, MAXELEMS(str));

  if (!strncmp(str, FOREIGNAPP, 11))
  {
    return JavaSession_GetName();
  }

  if (!strcmp(str, JAVA_STR))
  {
    return JavaSession_GetName();
  }
#endif
#endif
  return EMPTY_TEXTID;
}

BOOL IsBookManager(BOOK *book)
{
  return (book->onClose == BookManager_onClose ? TRUE : FALSE);
}

int GetActiveTab(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  return TabMenuBar_GetFocusedTab(bookman->gui);
}

int GetBooksFromSession(UI_APP_SESSION *session, LIST *books_list, LIST *elfs_list)
{
  int list_index;
  int res = 0;
  int mask = ((int)LastExtDB) & FLASH_MASK;

  for (list_index = 0; list_index < List_GetCount(session->listbook); list_index++)
  {
    BOOK *book = (BOOK *)List_Get(session->listbook, list_index);

    if (!IsBookManager(book))
    {
      char str[MAX_BOOK_NAME_LEN + 1];
      BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)malloc(sizeof(BOOK_LIST_ITEM));
      elem->book = book;
      elem->gui_count = List_GetCount(book->xguilist->guilist);

      if (strcmp(book->xbook->name, JAVA_STR))
      {
        char *bookname = (char *)malloc(strlen(book->xbook->name) + 1);
        strcpy(bookname, book->xbook->name);
        elem->book_name = bookname;
        elem->book_icon = DB_LIST_APPS_ICN;
        elem->isJava = FALSE;
      }
      else
      {
        TextID_GetString(BookObj_GetSession(book)->name, str, MAXELEMS(str));
        char *bookname = (char *)malloc(strlen(str) + 1);
        strcpy(bookname, str);
        elem->book_name = bookname;
        elem->book_icon = DB_LIST_JAVA_ICN;
        elem->isJava = TRUE;
      }

      TEXTID java_id = GetJavaName(book);
#ifndef W700_R1CA021
#ifndef W800_R1BD001
      if (elem->isJava)
      {
        void *JavaDesc;
        char jdialog;
        wchar_t *javaname;
        wchar_t *javapath;
        JavaDialog_Open(0, &jdialog, &JavaDesc);

        if (!JavaAppDesc_GetFirstApp(JavaDesc))
        {
          wchar_t book_name[100];
          TextID_GetWString(java_id, book_name, MAXELEMS(book_name));

          int result = 0;
          while (!result)
          {
            JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_NAME, &javaname);
            int cmp_res = wstrcmp(book_name, javaname);
            mfree(javaname);
            if (cmp_res)
            {
              result = JavaAppDesc_GetNextApp(JavaDesc);
            }
            else
            {
              JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_FULLPATH, &javapath);
              JavaApp_LogoImageID_Get(javapath, &elem->book_icon);
              mfree(javapath);
              break;
            }
          }
        }
        JavaDialog_Close(jdialog);
      }
#endif
#endif
      if (java_id != EMPTY_TEXTID)
      {
        mfree(elem->book_name);
        TextID_GetString(java_id, str, MAXELEMS(str));
        char *java_name = (char *)malloc(strlen(str) + 1);
        strcpy(java_name, str);
        elem->book_name = java_name;
        TextID_Destroy(java_id);
      }

      if ((((int)book->onClose) & FLASH_MASK) == mask)
      {
        if (!elem->gui_count)
          BOOK_LIST_ITEM_Destroy(elem);
        else
          List_InsertFirst(books_list, elem);
      }
      else
      {
        List_InsertFirst(elfs_list, elem);
        res = 1;
      }
    }
  }
  return res;
}

void CreateBookAndElfsLists(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;

  int session_total, session_index, isElf;
  UI_APP_SESSION *session;

  if (bookman->minimize_to_session)
  {
    bookman->sessions_list = List_Create();
  }
  else
  {
    bookman->books_list = List_Create();
  }

  bookman->elfs_list = List_Create();

  session_total = root_list_get_session_count();

  for (session_index = 0; session_index < session_total; session_index++)
  {
    session = root_list_get_session(session_index);

    if (bookman->minimize_to_session)
    {
      SESSION_LIST_ITEM *elem = (SESSION_LIST_ITEM *)malloc(sizeof(SESSION_LIST_ITEM));
      elem->session = session;
      elem->books_list = List_Create();
      elem->pos_subitem = 0;

      isElf = GetBooksFromSession(session, elem->books_list, bookman->elfs_list);

      if (!List_GetCount(elem->books_list) || isElf)
      {
        SESSION_LIST_ITEM_Destroy(elem);
      }
      else
      {
        List_InsertFirst(bookman->sessions_list, elem);
      }
    }
    else
    {
      GetBooksFromSession(session, bookman->books_list, bookman->elfs_list);
    }
  }

  if (bookman->minimize_to_session)
  {
    bookman->books_count = List_GetCount(bookman->sessions_list);
  }
  else
  {
    bookman->books_count = List_GetCount(bookman->books_list);
  }

  bookman->elfs_count = List_GetCount(bookman->elfs_list);
}

BOOK_LIST_ITEM *GetBookListItem(BOOK *book, int list)
{
  BookManager *bookman = (BookManager *)book;
  BOOK_LIST_ITEM *elem;
  switch (list)
  {
  case BOOKLIST:
    if (bookman->books_count)
    {
      if (bookman->minimize_to_session)
      {
        SESSION_LIST_ITEM *ses_elem = (SESSION_LIST_ITEM *)List_Get(bookman->sessions_list, bookman->book_index);
        elem = (BOOK_LIST_ITEM *)List_Get(ses_elem->books_list, ses_elem->pos_subitem);
      }
      else
      {
        elem = (BOOK_LIST_ITEM *)List_Get(bookman->books_list, bookman->book_index);
      }
    }
    else
      return NULL;
    break;

  case ELFLIST:
    if (bookman->elfs_count)
      elem = (BOOK_LIST_ITEM *)List_Get(bookman->elfs_list, bookman->elf_index);
    else
      return 0;
    break;
  }
  return elem;
}

BOOK *GetBook(BOOK *bookman, int list)
{
  BOOK_LIST_ITEM *elem = GetBookListItem(bookman, list);
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
  FreeBook(bookman);

  BookObj_SetFocus(Find_StandbyBook(), UIDisplay_Main);
}

void Close_AllBooks(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FreeBook(bookman);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void onDelPressed_Books(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;

  BOOK_LIST_ITEM *elem = GetBookListItem(bookman, BOOKLIST);

  if (elem)
  {
    BOOK *selected_book = elem->book;

    if (selected_book != Find_StandbyBook())
    {
      if (elem->isJava)
      {
#if defined(W800_R1BD001) || defined(W700_R1CA021)
        UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(selected_book));
#else
        JavaSession_Manager(0x0E);
#endif
      }
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
            DispObject_SoftKeys_ExecuteAction(GUIObject_GetDispObject(gui), ACTION_LONG_BACK);
            BookObj_SetFocus(bookman, UIDisplay_Main);
          }
        }
      }
    }
  }
}

void onDelPressed_Elfs(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *selected_book = GetBook(bookman, ELFLIST);
  if (selected_book)
  {
    if (CheckEv(selected_book, RETURN_TO_STANDBY_EVENT))
    {
      UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID(selected_book));
    }
    else
    {
      if (CheckEv(selected_book, ELF_TERMINATE_EVENT))
      {
        UI_Event_toBookID(ELF_TERMINATE_EVENT, BookObj_GetBookID(selected_book));
      }
      else
      {
        CreateMessageBox(EMPTY_TEXTID, STR("TerminateEvent not supported by elf..."), 1, 3000, bookman);
      }
    }
  }
}

void onDelPressed(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (GetActiveTab(bookman) == BOOKLIST)
    onDelPressed_Books(bookman);
  else
    onDelPressed_Elfs(bookman);
}

int JavaShortcut_GetID(wchar_t *java_shortcut)
{
  int appID = -1;
  wchar_t *apphash = wstrwstr(java_shortcut, L"//") + 2;

  // Find app
  char jdialog;
  wchar_t *javahash;
  void *JavaDesc;
  JavaDialog_Open(0, &jdialog, &JavaDesc);
  if (!JavaAppDesc_GetFirstApp(JavaDesc))
  {
    int result = 0;
    while (!result)
    {
      JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_HASH, &javahash);
      int cmp_res = wstrcmp(apphash, javahash);
      mfree(javahash);
      if (cmp_res)
        result = JavaAppDesc_GetNextApp(JavaDesc);
      else
      {
        appID = JavaAppDesc_GetJavaAppID(JavaDesc);
        break;
      }
    }
  }
  JavaDialog_Close(jdialog);
  return appID;
}

void StartShortcut_Internal(char *param)
{
  wchar_t name[256];
  str2wstr(name, param);
  if (strstr(param, JAVA_MASK))
  {
    int _ASYNC = 1;
    int *ASYNC = &_ASYNC;
    char sp_flag;
    int appID = JavaShortcut_GetID(name);
    REQUEST_UI_OAF_START_APPLICATION(ASYNC, appID + 0x10000, &sp_flag);
  }
  else
  {
    Shortcut_Run(name);
  }
}

void Parse_and_Run_Shortcut(BOOK *book, int keyID)
{
  BookManager *bookman = (BookManager *)book;

  if (!bookman->shortcuts_buf)
    return;

  char param_name[16];
  sprintf(param_name, KEY_MASK, keyID - KEY_DIGITAL_0);

  char *param = manifest_GetParam(bookman->shortcuts_buf, param_name, NULL);
  if (param)
  {
    StartShortcut_Internal(param);
    mfree(param);
    FreeBook(bookman);
  }
}

void myOnKey_Unified(DISP_OBJ *disp_obj, int keyID, int repeat, int count, int mode)
{
  GUI *gui = DispObject_GetGUI(disp_obj);
  BookManager *bookman = (BookManager *)GUIObject_GetBook(gui);

  bookman->oldOnKey(disp_obj, keyID, repeat, count, mode);

  if (mode == KBD_SHORT_RELEASE)
  {
    if (keyID == KEY_DEL)
    {
      onDelPressed(bookman);
    }
    else if (keyID == KEY_DIEZ)
    {
      Minimize_AllBooks(bookman);
    }
    else if (keyID == KEY_STAR)
    {
      Close_AllBooks(bookman);
    }
    else if ((keyID - KEY_DIGITAL_0) <= 9)
    {
      if (GetActiveTab(bookman) == BOOKLIST)
        Parse_and_Run_Shortcut(bookman, keyID);
    }
  }
}

void ElfTab_SetTitle(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;

  wchar_t buf[16];
  snwprintf(buf, MAXELEMS(buf), L"Started ELF: %d", bookman->elfs_count);
  TabMenuBar_SetTabTitle(bookman->gui, TAB_ELFS, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}

void RefreshElfSoftkeys(BOOK *book, int item)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->elfs_count)
  {
    BOOK_LIST_ITEM *elem = (BOOK_LIST_ITEM *)List_Get(bookman->elfs_list, item);
    if (!elem->gui_count)
      GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, ACTION_SELECT1, FALSE);
    else
      GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, ACTION_SELECT1, TRUE);

    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, TAB_ELFS_RENAME_SOFTKEY, TRUE);
    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, TAB_ELFS_CONFIG_SOFTKEY, TRUE);
    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, TAB_ELFS_AUTHOR_SOFTKEY, TRUE);
  }
  else
  {
    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, TAB_ELFS_RENAME_SOFTKEY, FALSE);
    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, TAB_ELFS_CONFIG_SOFTKEY, FALSE);
    GUIObject_SoftKeys_SetVisible(bookman->elf_list_menu, TAB_ELFS_AUTHOR_SOFTKEY, FALSE);
    bookman->elf_index = 0;
  }
  ElfTab_SetTitle(bookman);
}

void RefreshBookSoftkeys(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  if (bookman->books_count)
  {
    BOOK_LIST_ITEM *elem = GetBookListItem(bookman, BOOKLIST);

    if (elem->gui_count)
      GUIObject_SoftKeys_SetVisible(bookman->books_list_menu, ACTION_SELECT1, TRUE);
    else
      GUIObject_SoftKeys_SetVisible(bookman->books_list_menu, ACTION_SELECT1, FALSE);

    GUIObject_SoftKeys_SetVisible(bookman->books_list_menu, TAB_BOOKS_RENAME_SOFTKEY, TRUE);
  }
  else
  {
    GUIObject_SoftKeys_SetVisible(bookman->books_list_menu, TAB_BOOKS_RENAME_SOFTKEY, FALSE);
    GUIObject_SoftKeys_SetVisible(bookman->books_list_menu, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetVisible(bookman->books_list_menu, ACTION_DELETE, FALSE);

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

void onAuthor(BOOK *book, GUI *g)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *selected_book = GetBook(bookman, ELFLIST);
  if (selected_book)
  {
    if (CheckEv(selected_book, ELF_SHOW_INFO_EVENT))
    {
      MSG *msg = (MSG *)malloc(sizeof(MSG));
      msg->book = bookman;
      UI_Event_toBookIDwData(ELF_SHOW_INFO_EVENT, BookObj_GetBookID(selected_book), msg, (void (*)(void *))mfree);
    }
    else
    {
      CreateMessageBox(EMPTY_TEXTID, STR("Unknown Author"), 1, 3000, bookman);
    }
  }
}

int Elf_OpenFile(const wchar_t *filepath, const wchar_t *filename)
{
  W_FSTAT _wstat;

  if (!w_fstat(BCFG_PATH, &_wstat))
  {
  }
  else
  {
    return BCFG_NOTFOUND; // BcfgEdit not found
  }

  if (!filepath || !filename)
    return BCFG_FOUND; // success

  openWithBcfgEdit(BCFG_PATH, filepath, filename);
  return BCFG_DEFAULT;
}

void onBcfgConfig(BOOK *book, GUI *g)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *selected_book = GetBook(bookman, ELFLIST);

  if (selected_book)
  {
    if (CheckEv(selected_book, ELF_BCFG_CONFIG_EVENT))
    {
      int res = Elf_OpenFile(NULL, NULL);
      if (res == BCFG_FOUND)
      {
        wchar_t bcfg_path[256];
        wchar_t bcfg_name[256];

        MSG_BCFG *msg = (MSG_BCFG *)malloc(sizeof(MSG_BCFG));
        msg->book = bookman;
        msg->bcfg_p = bcfg_path;
        msg->bcfg_n = bcfg_name;
        UI_Event_toBookIDwData(ELF_BCFG_CONFIG_EVENT, BookObj_GetBookID(selected_book), msg, (void (*)(void *))mfree);
      }
      else if (res == BCFG_NOTFOUND)
      {
        CreateMessageBox(EMPTY_TEXTID, STR("BcfgEdit.elf not found!"), 1, 3000, bookman);
      }
    }
    else
    {
      CreateMessageBox(EMPTY_TEXTID, STR("ELF doesn't support BcfgConfigEvent"), 1, 3000, bookman);
    }
  }
}

void onEnterPressed(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BOOK *selected_book = GetBook(bookman, GetActiveTab(bookman));
  if (selected_book)
  {
    BookObj_SetFocus(selected_book, UIDisplay_Main);
    FreeBook(bookman);
  }
}

void BookMan_EditShortcut(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  BookObj_CallPage(bookman, &BookManager_ChangeShortcuts_page);
}

void BookMan_AboutInfo(BOOK *book, GUI *gui)
{
  BookManager *bookman = (BookManager *)book;
  CreateMessageBox(EMPTY_TEXTID, STR("Book Manager\n(c) Hussein\n(e) farid\n\n2024"), 1, 0, bookman);
}

wchar_t *GetUserBookName(wchar_t *ini, wchar_t *orig_name, wchar_t *cur_name)
{
  wchar_t *pos;

  if (ini)
  {
    wchar_t uni_pair[MAX_BOOK_NAME_LEN + sizeof(": ")];
    uni_pair[0] = 0;
    wstrcpy(uni_pair, orig_name);
    wstrcat(uni_pair, L": ");

    pos = wstrwstr(ini, uni_pair);

    if (pos)
    {
      swscanf(pos, BOOKNAME_FMT, cur_name);
      return pos;
    }
  }

  wstrcpy(cur_name, orig_name);
  return NULL;
}

TEXTID GetUserBookNameTEXTID(char *name)
{
  wchar_t cur_name[MAX_BOOK_NAME_LEN + 1];
  wchar_t orig_name[MAX_BOOK_NAME_LEN + 1];

  BookManager *bookman = (BookManager *)FindBook(IsBookManager);

  str2wstr(orig_name, name);

  GetUserBookName(bookman->booknames_buf, orig_name, cur_name);

  return TextID_Create(cur_name, ENC_UCS2, TEXTID_ANY_LEN);
}

int Books_onMessage(GUI_MESSAGE *msg)
{
  BookManager *bookman = (BookManager *)GUIonMessage_GetBook(msg);

  int item;
  int parent_item;
  SESSION_LIST_ITEM *ses_elem;
  BOOK_LIST_ITEM *elem;

  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    if (bookman->books_count)
    {
      item = GUIonMessage_GetCreatedItemIndex(msg);

      if (bookman->minimize_to_session)
      {
        ses_elem = (SESSION_LIST_ITEM *)List_Get(bookman->sessions_list, item);

        GUIonMessage_SetNumberOfSubItems(msg, 0, List_GetCount(ses_elem->books_list));
        GUIonMessage_SetMenuItemText(msg, TextID_Copy(ses_elem->session->name));
      }
      else
      {
        elem = (BOOK_LIST_ITEM *)List_Get(bookman->books_list, item);

        GUIonMessage_SetMenuItemText(msg, GetUserBookNameTEXTID(elem->book_name));
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->book_icon);

        if (!elem->gui_count)
        {
          GUIonMessage_SetItemDisabled(msg, TRUE);
          GUIonMessage_SetMenuItemUnavailableText(msg, STR("Can't set focus to book without GUI..."));
        }
      }
    }
    break;
  case LISTMSG_HighlightChanged:
    bookman->book_index = GUIonMessage_GetSelectedItem(msg);
    RefreshBookSoftkeys(bookman);
    break;
  case LISTMSG_GetSubItem:
    parent_item = GUIonMessage_SubItem_GetCreatedParentIndex(msg);
    item = GUIonMessage_SubItem_GetCreatedIndex(msg);
    ses_elem = (SESSION_LIST_ITEM *)List_Get(bookman->sessions_list, parent_item);
    elem = (BOOK_LIST_ITEM *)List_Get(ses_elem->books_list, item);

    GUIonMessage_SubItem_SetText(msg, GetUserBookNameTEXTID(elem->book_name));
    if (!elem->gui_count)
    {
      GUIonMessage_SubItem_SetDisabled(msg, TRUE);
    }
    break;
  case LISTMSG_SubItemHighlightChanged:
    ses_elem = (SESSION_LIST_ITEM *)List_Get(bookman->sessions_list, bookman->book_index);
    ses_elem->pos_subitem = GUIonMessage_SubItem_GetSelectedIndex(msg);

    elem = (BOOK_LIST_ITEM *)List_Get(ses_elem->books_list, ses_elem->pos_subitem);
    if (!elem->gui_count)
      GUIonMessage_SetMenuItemUnavailableText(msg, STR("Can't set focus to book without GUI..."));

    RefreshBookSoftkeys(bookman);
    break;
  }
  return 1;
}

int Elfs_onMessage(GUI_MESSAGE *msg)
{
  BookManager *bookman = (BookManager *)GUIonMessage_GetBook(msg);
  int item;
  BOOK_LIST_ITEM *elem;
  TEXTID name;

  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    if (bookman->elfs_count)
    {
      item = GUIonMessage_GetCreatedItemIndex(msg);
      elem = (BOOK_LIST_ITEM *)List_Get(bookman->elfs_list, item);
      name = GetUserBookNameTEXTID(elem->book_name);
      GUIonMessage_SetMenuItemText(msg, name);

      if (!elem->gui_count)
      {
        GUIonMessage_SetItemDisabled(msg, TRUE);
        GUIonMessage_SetMenuItemUnavailableText(msg, STR("Can't set focus to elf without GUI..."));
      }
    }
    break;
  case LISTMSG_HighlightChanged:
    bookman->elf_index = GUIonMessage_GetSelectedItem(msg);
    RefreshElfSoftkeys(bookman, bookman->elf_index);
    break;
  }
  return 1;
}

void CreateBookManagerGUI(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  DestroyBookAndElfsLists(bookman);
  CreateBookAndElfsLists(bookman);

  if (!bookman->gui)
  {
    bookman->gui = CreateTabMenuBar(bookman);
    TabMenuBar_SetTabCount(bookman->gui, LAST_TAB);
    TabMenuBar_SetTabIcon(bookman->gui, TAB_BOOKS, TAB_BOOK_ACTIVE_ICN, TAB_ACTIVE);
    TabMenuBar_SetTabIcon(bookman->gui, TAB_BOOKS, TAB_BOOK_INACTIVE_ICN, TAB_INACTIVE);
    TabMenuBar_SetTabIcon(bookman->gui, TAB_ELFS, TAB_ELF_ACTIVE_ICN, TAB_ACTIVE);
    TabMenuBar_SetTabIcon(bookman->gui, TAB_ELFS, TAB_ELF_INACTIVE_ICN, TAB_ACTIVE);
  }

  if (bookman->book_index > bookman->books_count - 1)
    bookman->book_index = bookman->books_count - 1;

  if (bookman->books_list_menu)
  {
    ListMenu_DestroyItems(bookman->books_list_menu);
    ListMenu_SetItemCount(bookman->books_list_menu, bookman->books_count);
    if (bookman->minimize_to_session)
    {
      ListMenu_SetItemStyle(bookman->books_list_menu, 3);
    }
    else
    {
      ListMenu_SetItemStyle(bookman->books_list_menu, 0);
    }
    ListMenu_SetCursorToItem(bookman->books_list_menu, bookman->book_index);
    RefreshBookSoftkeys(bookman);
  }
  else
  {
    bookman->books_list_menu = CreateListMenu(bookman, UIDisplay_Main);
    ListMenu_SetOnMessage(bookman->books_list_menu, Books_onMessage);
    ListMenu_SetItemCount(bookman->books_list_menu, bookman->books_count);
    ListMenu_SetCursorToItem(bookman->books_list_menu, bookman->book_index);
    if (bookman->minimize_to_session)
    {
      ListMenu_SetItemStyle(bookman->books_list_menu, 3);
    }
    else
    {
      ListMenu_SetItemStyle(bookman->books_list_menu, 0);
    }
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, ACTION_BACK, BookMan_Close);
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, ACTION_LONG_BACK, BookMan_LClose);
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, ACTION_SELECT1, onEnterPressed);
    GUIObject_SoftKeys_SetText(bookman->books_list_menu, TAB_BOOKS_RENAME_SOFTKEY, BOOKMAN_RENAME_TXT);
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, TAB_BOOKS_RENAME_SOFTKEY, BookMan_RenameBook);
    GUIObject_SoftKeys_SetText(bookman->books_list_menu, TAB_BOOKS_SETTINGS_SOFTKEY, MODE_SOFTKEYS_TXT);
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, TAB_BOOKS_SETTINGS_SOFTKEY, BookMan_ChangeMode);
    GUIObject_SoftKeys_SetText(bookman->books_list_menu, TAB_BOOKS_SHORTCUTS_SOFTKEY, EDIT_SHORTCUTS_TXT);
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, TAB_BOOKS_SHORTCUTS_SOFTKEY, BookMan_EditShortcut);
    GUIObject_SoftKeys_SetText(bookman->books_list_menu, TAB_BOOKS_COPYRIGHT_SOFTKEY, ABOUT_TXT);
    GUIObject_SoftKeys_SetAction(bookman->books_list_menu, TAB_BOOKS_COPYRIGHT_SOFTKEY, BookMan_AboutInfo);

    DISP_OBJ *books_list_menu = GUIObject_GetDispObject(bookman->books_list_menu);
    bookman->oldOnKey = DispObject_GetOnKey(books_list_menu);
    DISP_DESC_SetOnKey(DispObject_GetDESC(books_list_menu), myOnKey_Unified);

    RefreshBookSoftkeys(bookman);
    TabMenuBar_SetTabGui(bookman->gui, TAB_BOOKS, bookman->books_list_menu);
    TabMenuBar_SetTabTitle(bookman->gui, TAB_BOOKS, GetFreeHeap());
  }

  //---------------

  if (bookman->elf_index > bookman->elfs_count - 1)
    bookman->elf_index = bookman->elfs_count - 1;

  if (bookman->elf_list_menu)
  {
    ListMenu_DestroyItems(bookman->elf_list_menu);
    ListMenu_SetItemCount(bookman->elf_list_menu, bookman->elfs_count);
    ListMenu_SetCursorToItem(bookman->elf_list_menu, bookman->elf_index);
    RefreshElfSoftkeys(bookman, bookman->elf_index);
  }
  else
  {
    bookman->elf_list_menu = CreateListMenu(bookman, UIDisplay_Main);
    ListMenu_SetCursorToItem(bookman->elf_list_menu, 0);
    ListMenu_SetOnMessage(bookman->elf_list_menu, Elfs_onMessage);
    ListMenu_SetItemCount(bookman->elf_list_menu, bookman->elfs_count);
    ListMenu_SetCursorToItem(bookman->elf_list_menu, bookman->elf_index);
    GUIObject_SoftKeys_SetAction(bookman->elf_list_menu, ACTION_BACK, BookMan_Close);
    GUIObject_SoftKeys_SetAction(bookman->elf_list_menu, ACTION_LONG_BACK, BookMan_LClose);
    GUIObject_SoftKeys_SetAction(bookman->elf_list_menu, ACTION_SELECT1, onEnterPressed);
    GUIObject_SoftKeys_SetAction(bookman->elf_list_menu, TAB_ELFS_RENAME_SOFTKEY, BookMan_RenameBook);
    GUIObject_SoftKeys_SetText(bookman->elf_list_menu, TAB_ELFS_RENAME_SOFTKEY, BOOKMAN_RENAME_TXT);
    GUIObject_SoftKeys_SetAction(bookman->elf_list_menu, TAB_ELFS_CONFIG_SOFTKEY, onBcfgConfig);
    GUIObject_SoftKeys_SetText(bookman->elf_list_menu, TAB_ELFS_CONFIG_SOFTKEY, STR("Config"));
    GUIObject_SoftKeys_SetAction(bookman->elf_list_menu, TAB_ELFS_AUTHOR_SOFTKEY, onAuthor);
    GUIObject_SoftKeys_SetText(bookman->elf_list_menu, TAB_ELFS_AUTHOR_SOFTKEY, STR("Author"));

    DISP_DESC_SetOnKey(DispObject_GetDESC(GUIObject_GetDispObject(bookman->elf_list_menu)), myOnKey_Unified);

    RefreshElfSoftkeys(bookman, bookman->elf_index);
    TabMenuBar_SetTabGui(bookman->gui, TAB_ELFS, bookman->elf_list_menu);
    ElfTab_SetTitle(bookman);
  }

  TabMenuBar_SetFocusedTab(bookman->gui, bookman->active_tab);
  GUIObject_Show(bookman->gui);
}

int BookManager_Enter_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  CreateBookManagerGUI(bookman);
  return 1;
}

int BookManager_BookDestroyed_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;

  if (!bookman->button_list_menu)
  {
    bookman->active_tab = GetActiveTab(bookman);
    CreateBookManagerGUI(bookman);
  }
  return 1;
}

int BookManager_Accept_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  CreateBookManagerGUI(bookman);
  return 1;
}

int BookManager_Cancel_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->books_list_menu);
  return 1;
}

void BookManager_onClose(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  bookman->active_tab = GetActiveTab(bookman);
  SaveMode(bookman);
  DestroyIniBuffers(bookman);
  DestroyAllGUIs(bookman);
  DestroyAllList(bookman);
}

BookManager *Create_BookManager()
{
  BookManager *bookman = (BookManager *)malloc(sizeof(BookManager));
  memset(bookman, NULL, sizeof(BookManager));
  if (!CreateBook(bookman, BookManager_onClose, &BookManager_Base_Page, BOOKNAME, NO_BOOK_ID, NULL))
  {
    mfree(bookman);
    return NULL;
  }

  bookman->booknames_buf = NULL;
  bookman->booknames_buf_size = NULL;
  bookman->shortcuts_buf = NULL;
  bookman->shortcuts_buf_size = NULL;
  bookman->books_list_menu = NULL;
  bookman->button_list_menu = NULL;
  bookman->java_list_menu = NULL;
  bookman->mode_list_menu = NULL;
  bookman->string_input = NULL;
  bookman->oldOnKey = NULL;
  bookman->java_list = NULL;
  bookman->sessions_list = NULL;
  bookman->books_list = NULL;
  bookman->books_count = NULL;
  bookman->book_index = NULL;
  bookman->MainMenuID = NO_BOOK_ID;
  bookman->active_tab = NULL;
  bookman->minimize_to_session = NULL;
  return bookman;
}

void Call_BookManager()
{
  BookManager *bookman = (BookManager *)FindBook(IsBookManager);

  if (!bookman)
  {
    bookman = Create_BookManager();
    LoadMode(bookman);
    LoadBookNames(bookman);
    LoadShortcuts(bookman);
    BookObj_GotoPage(bookman, &BookManager_Main_Page);
  }
  else if (bookman != Display_GetTopBook(UIDisplay_Main))
  {
    BookObj_SetFocus(bookman, UIDisplay_Main);
  }
  else if (bookman == Display_GetTopBook(UIDisplay_Main))
  {
    FreeBook(bookman);
  }
}

void NextBook()
{
  int root_list_index, listbook_index;
  int root_list_count = root_list_get_session_count();
  for (root_list_index = 0; root_list_index < root_list_count; root_list_index++)
  {
    UI_APP_SESSION *session = root_list_get_session(root_list_index);
    int listbook_count = List_GetCount(session->listbook);
    for (listbook_index = 0; listbook_index < listbook_count; listbook_index++)
    {
      BOOK *book = (BOOK *)List_Get(session->listbook, listbook_index);
      if (List_GetCount(book->xguilist->guilist) && !IsVolumeControllerBook(book) && !IsRightNowBook(book))
      {
        BookObj_SetFocus(book, UIDisplay_Main);
      }
    }
  }
}
