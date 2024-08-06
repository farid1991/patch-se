#ifndef _Main_H_
#define _Main_H_

extern "C"
{
  void MusicApplication_CancelAction(BOOK *book, GUI *gui);
  void MusicApplication_PrevAction(BOOK *book, GUI *gui);

  int pg_MusicApplication_PreviousEvent(void* data, BOOK *book);
  int pg_MusicApplication_CancelEvent(void* data, BOOK *book);
  int pg_MusicApplication_ExitEvent(void* data, BOOK *book);
}

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

static const char MusicApplication_ManualEQ_PageName[] = "Select_Album_Art_Page";

int pg_MusicApplication_ManualEQ__EnterEvent(void *data, BOOK *book);

const PAGE_MSG bk_MusicApplication_ManualEQ[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_ManualEQ__EnterEvent,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
        CANCEL_EVENT, pg_MusicApplication_CancelEvent,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
        NIL_EVENT, NULL};
const PAGE_DESC page_MusicApplication_ManualEQ = {MusicApplication_ManualEQ_PageName, NULL, bk_MusicApplication_ManualEQ};

#endif
