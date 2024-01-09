#ifndef _MAIN_H_
#define _MAIN_H_

static char *MEM_NAME = "bm_mem";
static char *EMP_NAME = "bm_emp";

enum
{
  TAB_EVENTS,
  TAB_BOOKS,
  TAB_ELFS,
  TAB_SHORTCUTS
};

enum
{
  SHC_ITEM_1,
  SHC_ITEM_2,
  SHC_ITEM_3,
  SHC_ITEM_4,
  SHC_ITEM_5,
  SHC_ITEM_LAST,
};

enum
{
  BCFG_NULL,
  BCFG_NOTFOUND,
  BCFG_SUCCESS
};

#define ELF_BCFG_CONFIG_EVENT 994

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

static wchar_t *INI_PATH = L"/usb/other/ini";
static wchar_t *BOOKMAN_INI = L"bookman.ini";
static wchar_t *SHORTCUT_INI = L"shortcut.ini";
static wchar_t *BCFGEDIT_PATH = L"/usb/other/ZBin/BcfgEdit.elf";

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define mfree_adr() mfree

typedef struct _BOOK_MANAGER
{
  BOOK *ActivityMenu;
  DISP_OBJ_ONKEY_METHOD oldOnKey;
  GUI_LIST *books_menu;
  GUI_LIST *elf_menu;
  GUI_LIST *sc_menu;
  LIST *books_list;
  LIST *elfs_list;
  u16 book_index;
  u16 elf_index;
  u16 books_count;
  u16 elfs_count;
  char tab_pos;
  int books_name_size;
  char *books_name_buf;
  int shortcut_size;
  char *shortcut_buf;
} BOOK_MANAGER;

typedef struct
{
  BOOK *book;
  char *book_name;
  IMAGEID book_icon;
  u16 gui_count;
  bool isJava;
} BOOK_LIST_ELEM;

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
} MSG;

typedef struct
{
  BOOK *book;
  wchar_t *bcfg_p;
  wchar_t *bcfg_n;
} MSG_BCFG;

void Init_ConfigFile(BOOK_MANAGER *data);
__thumb void *malloc(int size);
__thumb void mfree(void *mem);

#endif
