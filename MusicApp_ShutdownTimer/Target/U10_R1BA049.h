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
#define INTERNAL_TIME_START (TIME*)0x15B37C22

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define ACTION_MP_SETTINGS 0xE
#define ACTION_MP_SHUTDOWNTIMER 0x17

#define TIMER_TXT 0x2F2

#define SELECT_TXT 0xD99
#define TURNOFF_TXT 0x21C
#define TURNEDON_TXT 0x418
#define TURNEDOFF_TXT 0x417
#define INPUT_ICN 0xFFFF

#endif
