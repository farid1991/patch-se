#ifndef _MAIN_H_
#define _MAIN_H_

#define EMP_NAME "bm_emp"

#define BOOKLIST 1
#define ELFLIST 2
#define JAVALIST 3
#define SHORTCUTS 3

#define ELF_BCFG_CONFIG_EVENT 994

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50
#define JAVA_BOOK_NAME "CUIDisplayableBook"
#define RSSTicker_Book "RSSTicker_Book"
#define QuickAccessBk "QuickAccessBook"

#define BOOKMAN_PATH L"/usb/other/ini"
#define BOOKMAN_INI L"bookman.ini"

typedef struct _BOOK_MANAGER
{
  // GUI_LIST *tab_books;
  // GUI_LIST* tab_elfs;
  // GUI_LIST* tab_shortcut;

  LIST *books_list;
  // LIST* elfs_list;
  // LIST* shortcut_list;

  uint8_t blistpos;
  // uint8_t elistpos;
  // uint8_t slistpos;

  uint8_t blistcnt;
  // uint8_t elistcnt;
  // uint8_t slistcnt;

  int buf_size;
  char *buf_ini;

  // bool elf;
} BOOK_MANAGER;

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
  wchar_t *name;
  wchar_t *path;
  int appID;
  IMAGEID iconID;
} JAVA_LIST_ITEM;

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

enum SHORTCUT_TYPES
{
  TYPE_SHORTCUT,
  TYPE_JAVA,
  TYPE_ELF,
  TYPE_EVENT,
  TYPE_FOLDER,
  TYPE_LAST
};

typedef struct
{
  uint8_t Type;
  wchar_t *sData;
  wchar_t *Caption;
  IMAGEID Icon;
} SHORTCUT_LIST_ITEM;

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define FREE_IMAGE(i) \
  if (i != NOIMAGE)   \
  {                   \
    ImageID_Free(i);  \
    i = NULL;         \
  }

void *malloc(int size);
void mfree(void *mem);


void restart_BookMenu(BOOK *book);

// BOOK_MANAGER *GetData();

// void onCloseBook(BOOK *book, GUI *gui);
// void onCloseAllBook(BOOK *book, GUI *gui);

// BOOK *GetBook(BOOK *book, int list);
// BOOK_LIST_ITEM *GetBookListItem(BOOK *book);
// void onDelete_BookAndElfs(BOOK *book, GUI *gui);
// int CheckEv(BOOK *book, int event);

// TEXTID GetBookName(char *book_name);
// IMAGEID GetBookIcon(char *book_name, int icon);

#endif
