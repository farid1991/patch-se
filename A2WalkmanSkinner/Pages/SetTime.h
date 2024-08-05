#ifndef _SETTIME_H_
#define _SETTIME_H_

#if defined(DB3200) || defined(DB3210)
void Enter_SetTime(BOOK *book, GUI *gui);
int pg_MusicApplication_SetTime_EnterEvent(void *data, BOOK *book);

const char Music_Time_PageName[] = "MusicApplication_SetTime";

const PAGE_MSG bk_Music_Time[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_SetTime_EnterEvent,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
        CANCEL_EVENT, pg_MusicApplication_CancelEvent,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC page_Music_Time = {Music_Time_PageName, NULL, bk_Music_Time};
#endif

#endif
