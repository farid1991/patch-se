#ifndef _MAIN_H_
  #define _MAIN_H_

#define EMP_NAME "bm_emp"

#define BOOKLIST  1
#define ELFLIST   2
//#define JAVALIST  3
//#define SHORTCUTS 3

#define ELF_BCFG_CONFIG_EVENT 994

#define FLASH_MASK            0xF8000000
#define MAX_BOOK_NAME_LEN     50
#define JAVA_BOOK_NAME        "CUIDisplayableBook"

#define BOOKMAN_PATH          L"/usb/other/ini"
#define BOOKMAN_INI           L"bookman.ini"

typedef struct _BOOK_MANAGER
{  
  GUI_LIST* tab_books;
  GUI_LIST* tab_elfs;
  GUI_LIST* tab_shortcut;
  
  LIST* books_list;
  LIST* elfs_list;
  LIST* shortcut_list;
 
  FSint8 blistpos;
  FSint8 elistpos;
  FSint8 slistpos;
  
  FSint8 blistcnt;
  FSint8 elistcnt;
  FSint8 slistcnt;
  
  FSint32 buf_size;
  TAscii* buf_ini;
  
  bool elf;
}BOOK_MANAGER;

typedef struct
{
  BOOK* book;
  char* book_name;
  wchar_t book_icon;
  int gui_count;
  bool isJava;
}BOOK_LIST_ITEM;

typedef struct
{
  wchar_t* name;
  wchar_t* path;
  int appID;
  IMAGEID iconID;
}JAVA_LIST_ITEM;

typedef struct
{
  BOOK* book;
}MSG;

typedef struct
{
  BOOK* book;
  wchar_t* bcfg_p;
  wchar_t* bcfg_n;
}MSG_BCFG;

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
  char Type;
  wchar_t* sData;
  wchar_t* Caption;
  IMAGEID Icon;
}SHORTCUT;

#define FREE_GUI(a) if(a) { a=GUIObject_Destroy(a); a=NULL; }
#define FREE_IMAGE(a) if(a!=NOIMAGE) { ImageID_Free(a); a=NULL; }

__thumb void * malloc (int size);
__thumb void mfree (void * mem);

BOOK_MANAGER* GetData(); 

void onCloseBook(BOOK* book, GUI* gui);
void onCloseAllBook(BOOK* book, GUI* gui);

BOOK* GetBook(BOOK* book, int list);
BOOK_LIST_ITEM* GetBookListItem(int list);
void onDelete_BookAndElfs(BOOK* book, GUI* gui);
int CheckEv(BOOK* book, int event);

TEXTID GetBookName(char* book_name);
IMAGEID  GetBookIcon(char* book_name, int icon);

#endif
