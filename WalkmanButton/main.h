#ifndef _Main_H_
#define _Main_H_

#define CONFIG_NAME L"wbutton.bin"

#define SUBITEM_COUNT 4

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

enum KEYMODE
{
  SHORT_PRESS,
  LONG_PRESS,
  KEY_LAST
};

typedef struct
{
  int short_press;
  int long_press;
} CFG_DATA;

typedef struct WalkmanShortcutBook : BOOK
{
  GUI *MainMenu;
  GUI *SubMenu;
  int KeyMode;
  int short_press;
  int long_press;
} WalkmanShortcutBook;

#endif
