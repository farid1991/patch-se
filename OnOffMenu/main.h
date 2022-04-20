#ifndef _Main_H_
#define _Main_H_

static const char* BOOKNAME = "QuickAccessBook";

#define BASE_PAGE_NAME "QuickAccess_Book_Base_Page"
#define MAIN_PAGE_NAME "QuickAccess_Book_Main_Page"

int pg_QuickAccess_Book_CancelEvent(void *data, BOOK *book);
int pg_QuickAccess_Book_EnterEvent(void *data, BOOK *book);
int pg_QuickAccess_Book_ExitEvent(void *data, BOOK *book);

const PAGE_MSG bk_msglst_base[] =
    {
        RETURN_TO_STANDBY_EVENT, pg_QuickAccess_Book_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC QuickAccess_Book_Base_Page = {BASE_PAGE_NAME, NULL, bk_msglst_base};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_QuickAccess_Book_EnterEvent,
        PAGE_EXIT_EVENT, pg_QuickAccess_Book_ExitEvent,
        NIL_EVENT, NULL};
const PAGE_DESC QuickAccess_Book_Main_Page = {MAIN_PAGE_NAME, NULL, bk_msglst_main};

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

typedef struct QuickAccess_Book : BOOK
{
  GUI_LIST *MainMenu;
} QuickAccess_Book;

enum MENU_ITEMS
{
  ITEM_RESTART,
  ITEM_SHUTDOWN,
  ITEM_SILENT,
  ITEM_BLUETOOTH,
  ITEM_IRDA,
  ITEM_PROFILES,
  ITEM_STANDBY,
  ITEM_LAST
};

#endif
