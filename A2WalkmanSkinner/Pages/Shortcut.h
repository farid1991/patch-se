#ifndef _SHORTCUT_H_
#define _SHORTCUT_H_

#define CONFIG_NAME L"msc.bin"
#define TEXTID_SPACE 0x78000020

static const char *MusicShortcutBookName = "MusicApplicationShortcut_Book";
static const char MusicShortcut_Base_Page_Name[] = "MusicApplication_Shortcut_Base_Page";
static const char MusicShortcut_Main_Page_Name[] = "MusicApplication_Shortcut_Main_Page";
static const char MusicShortcut_Page_Select_Name[] = "MusicApplication_Shortcut_SelectAction_Page";

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
  uint16_t action;
  TEXTID textid;
} SOFTKEY_LIST_ELEM;

typedef struct
{
  uint16_t action[Item_Key_Last];
} FILE_DATA;

typedef struct MusicApplication_Shortcut_Book : BOOK
{
  GUI_LIST *MainMenu;
  GUI_LIST *SubMenu;
  LIST *SoftkeyList;
  uint8_t CurrentItem;
} MusicApplication_Shortcut_Book;

void Call_ShortcutPage(BOOK *book, GUI *gui);

int pg_MusicApplication_Shortcut_EnterAction(void *data, BOOK *book);
int pg_MusicApplication_Shortcut_CancelAction(void *data, BOOK *book);
int pg_MusicApplication_Shortcut_PrevAction(void *data, BOOK *book);
int pg_MusicApplication_Shortcut_ExitAction(void *data, BOOK *book);
int pg_MusicApplication_SelectShortcut_EnterAction(void *data, BOOK *book);
int pg_MusicApplication_SelectShortcut_ExitAction(void *data, BOOK *book);
int pg_MusicApplication_SelectShortcut_PrevAction(void *data, BOOK *book);
int pg_MusicApplication_SelectShortcut_CancelAction(void *data, BOOK *book);

const PAGE_MSG bk_msglst_sc[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_SelectShortcut_EnterAction,
        PAGE_EXIT_EVENT, pg_MusicApplication_SelectShortcut_ExitAction,
        PREVIOUS_EVENT, pg_MusicApplication_SelectShortcut_PrevAction,
        CANCEL_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_SelectShortcut_Page = {MusicShortcut_Page_Select_Name, NULL, bk_msglst_sc};

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        RETURN_TO_STANDBY_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        NIL_EVENT, NULL};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_Shortcut_EnterAction,
        PREVIOUS_EVENT, pg_MusicApplication_Shortcut_PrevAction,
        CANCEL_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        PAGE_EXIT_EVENT, pg_MusicApplication_Shortcut_ExitAction,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_Shortcut_Base_Page = {MusicShortcut_Base_Page_Name, NULL, bk_msglst_base};
const PAGE_DESC MusicApplication_Shortcut_Main_Page = {MusicShortcut_Main_Page_Name, NULL, bk_msglst_main};

#endif
