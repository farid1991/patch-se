#ifndef _U10_R1BA049_
#define _U10_R1BA049_

#define A2
#define DB3350

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x40EC

#define page_MusicApplication_ShowMessage (PAGE_DESC*)0x15BCF794

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define ACTION_MP_FILE 0x8
#define ACTION_MP_USE_AS 0x15

#define USE_AS_TXT 0x861
#define RING_CHANGED_TXT 0x7F5
#define MESSAGE_CHANGED_TXT 0x79F
#define RINGTONE_TXT 0x82E
#define MESSAGEALERT_TXT 0x833
#define ALARMSIGNAL_TXT 0x82C
#define CONTACTSIGNAL_TXT 0x745

#endif
