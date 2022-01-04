#ifndef U10_R7AA071
#define U10_R7AA071

#define A2
#define DB3350

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x40EC

#define page_MusicApplication_ShowMessage (PAGE_DESC*)0x15BE0CF0

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define ACTION_MP_FILE 0x8
#define ACTION_MP_USE_AS 0x15

#define USE_AS_TXT 0x862
#define RING_CHANGED_TXT 0x7F6
#define MESSAGE_CHANGED_TXT 0x7A0
#define RINGTONE_TXT 0x82F
#define MESSAGEALERT_TXT 0x834
#define ALARMSIGNAL_TXT 0x82D
#define CONTACTSIGNAL_TXT 0x746

#define ERROR_TXT 0x1648

#endif
