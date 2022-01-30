#ifndef _MAIN_H_
#define _MAIN_H_

#define EMP_NAME "bm_emp"

#define TAB_BOOKS 1
#define TAB_ELFS 2

#define ELF_BCFG_CONFIG_EVENT 994

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

#define BOOKMAN_PATH L"/usb/other/ini"
#define BOOKMAN_INI L"bookman.ini"

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define mfree_adr() mfree

typedef struct _BOOK_MANAGER
{
  BOOK* RightNowBook;
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
  bool elf;
  int buffer_size;
  char *cfg_buffer;
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
  UNK_1,
  UNK_2,
  UNK_3,
  UNK_4,
  JAVAAPP_FULLPATH,
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

// #pragma swi_number = 0x10D
// __swi __arm int elfload(const wchar_t *filename, void *param1, void *param2, void *param3);

#endif
