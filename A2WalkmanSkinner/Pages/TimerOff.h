#ifndef _TIMEROFF_H_
#define _TIMEROFF_H_

static const char Music_TimerOff_PageName[] = "MusicApplication_TimerOff";

void Call_TimerOff(BOOK *book, GUI *gui);
int pg_MusicApplication_TimerOff_EnterEvent(void *data, BOOK *book);

const PAGE_MSG bk_Music_TimerOff[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_TimerOff_EnterEvent,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
        CANCEL_EVENT, pg_MusicApplication_CancelEvent,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC page_Music_TimerOff = {Music_TimerOff_PageName, NULL, bk_Music_TimerOff};

#endif
