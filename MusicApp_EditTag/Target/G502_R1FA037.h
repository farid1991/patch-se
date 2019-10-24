#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define PATH                    0x11989974 // "/usb/other"
#define _SYNC_              	0x11A8331C

#define DB_UPDATE_EVENT         0x1770

#define ACTION_MP_FILE          0x8
#define ACTION_MP_SETTINGS      0xF
#define ACTION_MP_MYMUSIC       0x12
#define ACTION_MP_SKINEDITOR    0x13
#define ACTION_MP_VISUALISATION 0x14
#define ACTION_MP_USE_AS        0x15
#define ACTION_MP_EDITTAG       0x16

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_ACCEPT           0xFAC
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define UI_MEDIAPLAYER_UPDATE_EVENT 0x3C36
#define RETURN_TO_STANDBY_EVENT 0x841
#define PAGE_EXIT_EVENT         0xF
#define PAGE_ENTER_EVENT        0xE
#define CANCEL_EVENT            0x4
#define PREVIOUS_EVENT          0x3
#define ACCEPT_EVENT            0x2
#define NIL_EVENT               0

#define USE_AS_TXT	        0x78E
#define RING_CHANGED_TXT        0x71B
#define MESSAGE_CHANGED_TXT     0x6C3

#define RINGTONE_TXT        0x752
#define MESSAGEALERT_TXT    0x757
#define ALARMSIGNAL_TXT     0x750
#define CONTACTSIGNAL_TXT   0x662

#endif
#endif
