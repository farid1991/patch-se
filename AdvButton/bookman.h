#ifndef _BOOKMAN_H_
#define _BOOKMAN_H_

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

static const wchar_t *INI_BOOK_NAMES = L"booknames.ini";
static const wchar_t *INI_SHORTCUTS = L"shortcuts.ini";
static const wchar_t *BOOKMAN_CFG = L"bookman.cfg";
static const wchar_t *BOOKNAME_FMT = L"%*[^:]: %l[^\r]";

static char *BOOKNAME = "BookManager";
static char *KEY_MASK = "[KEY_%d]:";
static char *JAVA_MASK = "java:";

enum JAVA_APP_ID
{
  JAVA_APP_NAME,
  JAVA_APP_UNK,
  JAVA_APP_VENDOR,
  JAVA_APP_CERT,
  JAVA_APP_HASH,
  JAVA_APP_FULLPATH,
  JAVA_APP_SEMCLET,
  LAST_ID
};

typedef enum
{
  TAB_BOOKS_RENAME_SOFTKEY,
  TAB_BOOKS_SETTINGS_SOFTKEY,
  TAB_BOOKS_SHORTCUTS_SOFTKEY,
  TAB_BOOKS_COPYRIGHT_SOFTKEY,
} TAB_BOOKS_SOFTKEYS;

typedef enum
{
  TAB_BOOKS,
  TAB_ELFS,
  LAST_TAB,
} TAB_MENU_BAR;

typedef enum
{
  TAB_ACTIVE,
  TAB_INACTIVE,
} TAB_STATE;

typedef enum
{
  BOOKLIST,
  ELFLIST,
  LAST_LIST,
} MY_LIST;

typedef enum
{
  TAB_ELFS_RENAME_SOFTKEY,
  TAB_ELFS_CONFIG_SOFTKEY,
  TAB_ELFS_AUTHOR_SOFTKEY,
} TAB_ELFS_SOFTKEYS;

typedef enum
{
  BCFG_DEFAULT,
  BCFG_NOTFOUND,
  BCFG_FOUND,
} BCFG_STATE;

typedef struct
{
  BOOK *book;
  char *book_name;
  IMAGEID book_icon;
  int gui_count;
  bool isJava;
} BOOK_LIST_ITEM;

typedef struct
{
  UI_APP_SESSION *session;
  LIST *books_list;
  wchar_t pos_subitem;
} SESSION_LIST_ITEM;

typedef struct
{
  BOOK *book;
} MSG;

typedef struct
{
  BOOK *book;
  wchar_t *bcfg_p;
  wchar_t *bcfg_n;
} MSG_BCFG;

typedef struct
{
  bool minimize_to_session;
  char active_tab;
} BOOKMAN_BCFG;

typedef struct BookManager : BOOK
{
  GUI_TABMENUBAR *gui;
  GUI_LIST *books_list_menu;
  GUI_LIST *elf_list_menu;
  GUI_LIST *button_list_menu;
  GUI_LIST *java_list_menu;
  GUI_LIST *mode_list_menu;
  GUI *string_input;
  DISP_OBJ_ONKEY_METHOD oldOnKey;
  LIST *java_list;
  LIST *sessions_list;
  LIST *books_list;
  LIST *elfs_list;
  u16 books_count;
  u16 book_index;
  u16 elfs_count;
  u16 elf_index;
  u16 active_tab;
  wchar_t *booknames_buf;
  int booknames_buf_size;
  char *shortcuts_buf;
  int shortcuts_buf_size;
  int MainMenuID;
  bool minimize_to_session;
} BookManager;

void NextBook();
void LoadShortcuts(BOOK *book);
BOOL IsBookManager(BOOK *book);
void BookManager_onClose(BOOK *book);
BookManager *Create_BookManager();
void Call_BookManager();
void LoadBookNames(BOOK *book);
wchar_t *GetUserBookName(wchar_t *ini, wchar_t *orig_name, wchar_t *cur_name);
TEXTID GetUserBookNameTEXTID(char *name);
BOOK_LIST_ITEM *GetBookListItem(BOOK *book, int list);
void CreateBookAndElfsLists(BOOK *book);
void DestroyBookAndElfsLists(BOOK *book);
int GetActiveTab(BOOK *book);

int BookManager_Cancel_Event(void *data, BOOK *book);
int BookManager_Enter_Event(void *data, BOOK *book);
int BookManager_BookDestroyed_Event(void *data, BOOK *book);
int BookManager_Accept_Event(void *data, BOOK *book);

int ChangeMode_Enter_Event(void *data, BOOK *book);
int ChangeMode_Exit_Event(void *data, BOOK *book);

static const char BookManager_ChangeModePage[] = "BookManager_ChangeMode_Page";
static const char BookManager_BasePage[] = "BookManager_Base_Page";
static const char BookManager_MainPage[] = "BookManager_Main_Page";

const PAGE_MSG ChangeMode_PageEvents[] = {
    PAGE_ENTER_EVENT, ChangeMode_Enter_Event,
    PAGE_EXIT_EVENT, ChangeMode_Exit_Event,
    NIL_EVENT, 0};

const PAGE_DESC BookManager_ChangeMode_Page = {BookManager_ChangeModePage, NULL, ChangeMode_PageEvents};

const PAGE_MSG BM_Base_PageEvents[] = {
    CANCEL_EVENT, BookManager_Cancel_Event,
    RETURN_TO_STANDBY_EVENT, BookManager_Cancel_Event,
    NIL_EVENT, NULL};

const PAGE_DESC BookManager_Base_Page = {BookManager_BasePage, NULL, BM_Base_PageEvents};

const PAGE_MSG BM_Main_PageEvents[] = {
    PAGE_ENTER_EVENT, BookManager_Enter_Event,
    BOOK_DESTROYED_EVENT, BookManager_BookDestroyed_Event,
    ACCEPT_EVENT, BookManager_Accept_Event,
    NIL_EVENT, NULL};

const PAGE_DESC BookManager_Main_Page = {BookManager_MainPage, NULL, BM_Main_PageEvents};

#endif
