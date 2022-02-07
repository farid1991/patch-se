#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = 0;                \
  }

enum
{
  ITEM_1,
  ITEM_2,
  ITEM_3,
  ITEM_4,
  ITEM_COUNT
};

typedef struct _MyBOOK : BOOK
{
  GUI_LIST *MainMenu;
  int dest;
  wchar_t src_path[256];
} CopyDir_book;

#define ACTION_DB_FINDFILES 0x70
#define ACTION_DB_COPYDIR 0x71
#define ACTION_DB_COPYASPATH 0x72
#define ACTION_DB_PERMISSION 0x73

extern __thumb int DataBrowser_Book_GetItemCount(BOOK *bk);
extern __thumb GUI *DataBrowser_Book_GetGui(BOOK *bk);

#endif
