#ifndef SkinSelect_h
#define SkinSelect_h

enum FILEFOLDERTYPES
{
  ITEM_BACK,
  ITEM_FOLDER,
  ITEM_FILE
};

enum SELF
{
  SFOLDER,
  SFILE
};

int pg_MediaPlayer_SkinSelector_EnterEvent(void *data, BOOK *book);
int pg_MediaPlayer_SkinSelector_ExitEvent(void *data, BOOK *book);

const PAGE_MSG bk_msglst_skin[] =
    {
        PAGE_ENTER_EVENT, pg_MediaPlayer_SkinSelector_EnterEvent,
        PAGE_EXIT_EVENT, pg_MediaPlayer_SkinSelector_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC page_MediaPlayer_SkinSelectorPage = {"page_MediaPlayer_SkinSelectorPage", NULL, bk_msglst_skin};

#endif
