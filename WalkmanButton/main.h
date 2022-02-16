#ifndef Main_H_
#define Main_H_

#define CONFIG_NAME L"wbutton.bin"

#define SUBITEM_COUNT 7

#define FREE(mem) \
  if (mem)        \
  {               \
    mfree(mem);   \
    mem = NULL;   \
  }

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

__thumb void *malloc(int size);
__thumb void mfree(void *mem);

int pg_WalkmanShortcut_EnterEvent(void *data, BOOK *book);
int pg_WalkmanShortcut_CancelEvent(void *data, BOOK *book);

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_WalkmanShortcut_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_WalkmanShortcut_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC WalkmanShortcut_Base_Page = {"WalkmanShortcut_Base_Page", NULL, bk_msglst_base};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_WalkmanShortcut_EnterEvent,
        NIL_EVENT, NULL};
const PAGE_DESC WalkmanShortcut_Main_Page = {"WalkmanShortcut_Main_Page", NULL, bk_msglst_main};

#endif
