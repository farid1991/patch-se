#ifndef W580_R8BE001
#error W580_R8BE001 configuration needed for this header!
#else
#ifndef _W580_R8BE001_
#define _W580_R8BE001_

#define DB_UPDATE_EVENT         0x13EC

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_ACCEPT           0xFAC
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define RETURN_TO_STANDBY_EVENT 0x848
#define PAGE_ENTER_EVENT        7
#define CANCEL_EVENT            4
#define ACCEPT_EVENT            2
#define NIL_EVENT               0

#define FILE_TXT                0x48E 
#define MARK_TXT                0x4E2 
#define DIR_TXT                 0x47E

#define PATH 			0x457186D8
#define TURN_ON_TXT             0xBAD
#define TURN_OFF_TXT            0xBAE
#define ON_OFF_TXT              0x231B
#define DELETE_TXT              0x193E
#define ABOUT_TXT               0x3E9
#define PROTECT_TXT             0x350
#define CANT_DELETE_TXT         0x34E

#endif
#endif
