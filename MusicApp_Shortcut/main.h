#ifndef _MAIN_H_
  #define _MAIN_H_

#define FILE_NAME L"msc.bin"

#define BOOKNAME "MusicShortcut_Book"
#define BASE_PAGE_NAME "MusicShortcut_Base_Page"
#define MAIN_PAGE_NAME "MusicShortcut_Main_Page"

#define FREE_GUI(gui) if (gui) { GUIObject_Destroy(gui); gui = NULL; }
#define TextID_Get(str) TextID_Create(str, ENC_UCS2, 0xFF)

enum Modes
{
  SHORT_PRESS = 1,
  LONG_PRESS = 2
};

enum KeyList
{
  Item_Key_0 = 0,
  Item_Key_1,
  Item_Key_2,
  Item_Key_3,
  Item_Key_4,
  Item_Key_5,
  Item_Key_6,
  Item_Key_7,
  Item_Key_8,
  Item_Key_9,
  Item_Key_Last
};

typedef struct
{
  u16 action;
  TEXTID textid;
}SOFTKEY_LIST_ELEM;

typedef struct
{
  u16 action[Item_Key_Last];
}FILE_DATA;

typedef struct MusicShortcut_Book : BOOK
{
  GUI_LIST* MainMenu;
  GUI_LIST* SubMenu;
  
  LIST* SoftkeyList;
  
  char CurrentItem;

} MusicShortcut_Book;

__thumb void* malloc (int size);
__thumb void mfree (void * mem);

#endif
