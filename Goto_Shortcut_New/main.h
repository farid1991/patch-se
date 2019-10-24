#ifndef _MAIN_H_
  #define _MAIN_H_

#define BOOKNAME "GotoShortcut_Book"
#define BASE_PAGE_NAME "Goto_Shortcut_Base_Page"
#define MAIN_PAGE_NAME "Goto_Shortcut_Main_Page"

#define FREE_GUI(gui) if (gui) { GUIObject_Destroy(gui); gui = NULL; }
#define TextID_Get(str) TextID_Create(str, ENC_UCS2, 0xFF)

enum Modes
{
  EDITING_MODE = 1,
  ADDING_MODE = 2
};

#define F_NAME L"sc.bin"

//#define F_READ 0x001
//#define F_RIGHTS 0x180
//#define F_WRITE 0x204

enum Types
{
  TYPE_SHORTCUT,
  TYPE_JAVA,
  TYPE_ELF,
  TYPE_EVENT,
  TYPE_FOLDER,
  TYPE_LAST
};

enum STYPES 
{ 
  IS_BACK,
  IS_FOLDER,
  IS_FILE
};

enum SELF 
{
  SFOLDER,
  SFILE
};

typedef struct
{
  wchar_t* Name;
  wchar_t* Fullpath;
  IMAGEID ImageID;
}JAVA_LIST_ELEM;

#define SHORTCUT_TYPES_MAX_LEN 0x1D
#define CAPTION_MAX_LEN 0x1F

typedef struct
{
  char Type_f;
  wchar_t sData_f[SHORTCUT_TYPES_MAX_LEN];
  wchar_t Caption_f[CAPTION_MAX_LEN]; 
  int Icon_f;
}SHORTCUT_FILE;

typedef struct
{
    char Type;
    wchar_t* sData;
    wchar_t* Caption; 
    IMAGEID Icon;
}SHORTCUT;

typedef struct GotoShortcut_Book : BOOK
{
  GUI_LIST* MainMenu;
  GUI_LIST* Editor;
  GUI_LIST* JavaMenu;
  GUI_LIST* TypesList;
  GUI* CaptionInput;
  GUI* YesNoQuestion;
  GUI* EventInput;
  
  GUI* FolderInput;
  GUI_LIST* SelectFolder;
  
  LIST* Items;
  LIST* JavaList; 
  
  char CurrentPos;
  char FType;
  
  SHORTCUT* Current;
  //IMAGEID item_icn[2];
} GotoShortcut_Book;

int IsMyBook(BOOK* bk);
int UpdateMainPage(void* r0, BOOK* bk);
void ShortcutFree(void *Item);

__thumb void* malloc (int size);
__thumb void mfree (void * mem);

#endif
