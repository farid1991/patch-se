#ifndef _QUICKACCESS_H_
#define _QUICKACCESS_H_

static const char *QuickAccessBook = "QuickAccessMenuBook";

static const char BASE_PAGE_NAME[] = "QuickAccess_Book_Base_Page";
static const char MAIN_PAGE_NAME[] = "QuickAccess_Book_Main_Page";

enum MENU_ITEMS
{
  ITEM_RESTART,
  ITEM_SHUTDOWN,
  ITEM_SILENT,
#ifdef SETTINGS_BT_ID
  ITEM_BLUETOOTH,
#endif
  ITEM_IRDA,
  ITEM_PROFILES,
  ITEM_STANDBY,
  ITEM_LAST
};

typedef struct QuickAccess_Book : BOOK
{
  GUI_LIST *MainMenu;
} QuickAccess_Book;

BOOL IsQuickAccessBook(BOOK *book);
void QuickAccess_Book_onClose(BOOK *book);
QuickAccess_Book *Create_QuickAccess_Book();
void Call_QuickAccess_Book();

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

#endif
