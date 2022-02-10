#ifndef TopLevel_h
#define TopLevel_h

enum MM_TOPLEVEL_BRW
{
  MENU_NOW_PLAYING,
  MENU_ARTIST,
  MENU_ALBUMS,
  MENU_TRACKS,
  MENU_PLAYLIST,
  MENU_VIDEOS,
  MENU_LAST,
};

int pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent(void *data, BOOK *book);

const PAGE_MSG bk_msglst_mm[] =
    {
        PAGE_ENTER_EVENT, pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent,
        ACCEPT_EVENT, pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Start,
        PREVIOUS_EVENT, pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Start,
        CANCEL_EVENT, pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Cancel,
        MM_BRW_TOPLEVEL_STARTED_EVENT, pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Start,
        MM_BRW_TOPLEVEL_DESTROYED_EVENT, pg_MM_Browser_Toplevel_Bk_Videos,
        NIL_EVENT, NULL};

const PAGE_DESC page_MM_Browser_Toplevel_Bk_Albums = {"MM_Browser_Toplevel_Bk_AlbumsPage", NULL, bk_msglst_mm};

#endif
