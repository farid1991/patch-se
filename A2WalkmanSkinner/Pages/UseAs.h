#ifndef _USEAS_H_
#define _USEAS_H_

static const int items_text[4] =
    {
        TEXT_RINGTONE,
        TEXT_MESSAGEALERT,
        TEXT_ALARMSIGNAL,
        TEXT_CONTACTSIGNAL};

static const char MusicApplication_UseAsFile_PageName[] = "MusicApplication_UseAsFile_Page";

void Enter_UseAs(BOOK *book, GUI *gui);
int pg_MusicApplication_UseAsFile__EnterEvent(void *Data, BOOK *book);

const PAGE_MSG MusicApplication_UseAsFile[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_UseAsFile__EnterEvent,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
        CANCEL_EVENT, pg_MusicApplication_CancelEvent,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_UseAsFile_Page = {MusicApplication_UseAsFile_PageName, NULL, MusicApplication_UseAsFile};

#endif
