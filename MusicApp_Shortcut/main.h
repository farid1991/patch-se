#ifndef _MAIN_H_
#define _MAIN_H_

#define FILE_NAME L"msc.bin"
#define TEXTID_SPACE 0x78000020
#define BOOKNAME "MusicApplication_Shortcut_Book"

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

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

typedef struct SOFTKEY_LIST_ELEM
{
  u16 action;
  TEXTID textid;
} SOFTKEY_LIST_ELEM;

typedef struct FILE_DATA
{
  u16 action[Item_Key_Last];
} FILE_DATA;

typedef struct MusicApplication_Shortcut_Book : BOOK
{
  GUI_LIST *MainMenu;
  GUI_LIST *SubMenu;
  LIST *SoftkeyList;
  char CurrentItem;
} MusicApplication_Shortcut_Book;

extern "C"
{
  void MusicApplication_Keyboard(BOOK *book, int key, int repeat, int mode, void *unk);
  int MusicApplication_FastForward(BOOK *book);
  int MusicApplication_Rewind(BOOK *book);
  int MusicApplication_NextTrack(BOOK *book, BOOL);
  int MusicApplication_PreviousTrack(BOOK *book);
}

#endif
