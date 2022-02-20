#ifndef Bookman_H
#define Bookman_H

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

#define BOOKMAN_PATH L"/tpa/user/other/ini"

#define INI_BOOK_NAMES L"booknames.ini"
#define INI_SHORTCUTS L"shortcuts.ini"

enum JAVA_APP_ID
{
  JAVAAPP_NAME,
  JAVAAPP_UNK,
  JAVAAPP_VENDOR,
  JAVAAPP_CERT,
  JAVAAPP_HASH,
  JAVAAPP_FULLPATH,
  JAVAAPP_SEMCLET,
  LAST_ID
};

typedef struct
{
  BOOK *book;
  char *book_name;
  IMAGEID book_icon;
  int gui_count;
  BOOL isJava;
} BOOK_LIST_ITEM;

typedef struct
{
  UI_APP_SESSION *session;
  LIST *books_list;
  wchar_t pos_subitem;
} SESSION_LIST_ITEM;

typedef struct BookManager : BOOK
{
  GUI *books_list_menu;
  GUI *button_list_menu;
  GUI *java_list_menu;
  GUI *mode_list_menu;
  GUI *string_input;
  DISP_OBJ_ONKEY_METHOD oldOnKey;
  LIST *java_list;
  LIST *sessions_list;
  LIST *books_list;
  int books_count;
  int book_index;
  wchar_t *booknames_buf;
  int booknames_buf_size;
  char *shortcuts_buf;
  int shortcuts_buf_size;
  int MainMenuID;
  int minimize_to_session;
} BookManager;

int NextBook();
void LoadShortcuts(BOOK *book);
BOOL isBookManager(BOOK *book);
void Create_BookManager();
void LoadBookNames(BOOK *book);
wchar_t *GetUserBookName(wchar_t *ini, wchar_t *orig_name, wchar_t *cur_name);
TEXTID GetUserBookNameTEXTID(char *name);
BOOK_LIST_ITEM *GetBookListItem(BOOK *book);
void CreateSessionAndBookList(BOOK *book);
void DestroySessionAndBookList(BOOK *book);

int BookManager_Cancel_Event(void *data, BOOK *book);
int BookManager_Enter_Event(void *data, BOOK *book);
int BookManager_BookDestroyed_Event(void *data, BOOK *book);
int BookManager_Accept_Event(void *data, BOOK *book);

int ChangeMode_Enter_Event(void *data, BOOK *book);
int ChangeMode_Exit_Event(void *data, BOOK *book);

const PAGE_MSG ChangeMode_PageEvents[] = {
    PAGE_ENTER_EVENT, ChangeMode_Enter_Event,
    PAGE_EXIT_EVENT, ChangeMode_Exit_Event,
    NIL_EVENT, 0};

const PAGE_DESC BookManager_ChangeMode_page = {"BookManager_ChangeMode_Page", 0, ChangeMode_PageEvents};

const PAGE_MSG BM_Base_PageEvents[] = {
    CANCEL_EVENT, BookManager_Cancel_Event,
    RETURN_TO_STANDBY_EVENT, BookManager_Cancel_Event,
    NIL_EVENT, NULL};

const PAGE_DESC BookManager_Base_Page = {"BookManager_Base_Page", NULL, BM_Base_PageEvents};

const PAGE_MSG BM_Main_PageEvents[] = {
    PAGE_ENTER_EVENT, BookManager_Enter_Event,
    BOOK_DESTROYED_EVENT, BookManager_BookDestroyed_Event,
    ACCEPT_EVENT, BookManager_Accept_Event,
    NIL_EVENT, NULL};

const PAGE_DESC BookManager_Main_Page = {"BookManager_Main_Page", NULL, BM_Main_PageEvents};

#endif
