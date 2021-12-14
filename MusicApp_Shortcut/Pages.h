#ifndef _PAGES_H_
#define _PAGES_H_

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

const PAGE_DESC MusicApplication_SelectShortcut_Page = {"MusicApplication_SelectShortcut_Page", NULL, bk_msglst_sc};

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        RETURN_TO_STANDBY_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        NIL_EVENT, NULL};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_Shortcut_EnterAction,
        PAGE_EXIT_EVENT, pg_MusicApplication_Shortcut_ExitAction,
        PREVIOUS_EVENT, pg_MusicApplication_Shortcut_PrevAction,
        CANCEL_EVENT, pg_MusicApplication_Shortcut_CancelAction,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_Shortcut_Base_Page = {"MusicApplication_Shortcut_Base_Page", NULL, bk_msglst_base};
const PAGE_DESC MusicApplication_Shortcut_Main_Page = {"MusicApplication_Shortcut_Main_Page", NULL, bk_msglst_main};

#endif
