#ifndef _ALBUMART_H_
#define _ALBUMART_H_

static const char SelectAlbum_Art_PageName[] = "Select_Album_Art_Page";

typedef enum
{
  ITEM_ALBUMART,
  ITEM_OFF,
  ITEM_LAST
} SelectViz;

void Enter_SelectAlbumArt(BOOK *book, GUI *gui);

int pg_MusicApplication_Select_AlbumArt__EnterEvent(void *data, BOOK *book);

const PAGE_MSG bk_Select_Album_Art[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_Select_AlbumArt__EnterEvent,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
        CANCEL_EVENT, pg_MusicApplication_CancelEvent,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
        NIL_EVENT, NULL};
const PAGE_DESC page_Select_Album_Art = {SelectAlbum_Art_PageName, NULL, bk_Select_Album_Art};

#endif
