#ifndef _TopLevel_h_
#define _TopLevel_h_

enum MM_TOPLEVEL_BRW
{
  MENU_NOWPLAYING,
  MENU_ARTIST,
  MENU_ALBUMS,
  MENU_TRACKS,
  MENU_PLAYLIST,
  MENU_VIDEOS,
  MENU_LAST,
};

enum WINDOW_ANIM
{
  LEFT_IN_LEFT_OUT,
  LEFT_IN_RIGHT_OUT,
  RIGHT_IN_LEFT_OUT
};

int pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent(void *data, BOOK *book);

const PAGE_MSG bk_msglst_mm[] =
    {
        PAGE_ENTER_EVENT, pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent,
        ACCEPT_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
#ifdef DB2020
        MM_BRW_TOPLEVEL_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
#endif
        PREVIOUS_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
        CANCEL_EVENT, pg_MM_Browser_Toplevel_Bk_Cancel,
        MM_BRW_TOPLEVEL_STARTED_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
        MM_BRW_TOPLEVEL_DESTROYED_EVENT, pg_MM_Browser_Toplevel_Bk_Destroy,
        NIL_EVENT, NULL};

const PAGE_DESC page_MM_Browser_Toplevel_Bk_Albums = {"MM_Browser_Toplevel_Bk_AlbumsPage", NULL, bk_msglst_mm};

#endif
