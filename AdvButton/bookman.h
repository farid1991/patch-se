#ifndef Bookman_H
#define Bookman_H

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

#define BOOKMAN_PATH L"/tpa/user/other/ini"

#define INI_BOOK_NAMES L"booknames.ini"
#define INI_SHORTCUTS L"shortcuts.ini"

#define JAVA_BOOK_NAME "CUIDisplayableBook"

static const char *BOOKMANAGER = "BookManager";

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
  u16 ActiveTAB;
  wchar_t *booknames_buf;
  int booknames_buf_size;
  char *shortcuts_buf;
  int shortcuts_buf_size;
  int MainMenuID;
  int minimize_to_session;
} BookManager;

void NextBook();
void LoadShortcuts(BOOK *book);
BOOL isBookManager(BOOK *book);
void Create_BookManager();
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

const PAGE_MSG ChangeMode_PageEvents[] = {
    PAGE_ENTER_EVENT, ChangeMode_Enter_Event,
    PAGE_EXIT_EVENT, ChangeMode_Exit_Event,
    NIL_EVENT, 0};

const PAGE_DESC BookManager_ChangeMode_page = {"BookManager_ChangeMode_Page", NULL, ChangeMode_PageEvents};

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
