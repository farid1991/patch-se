#ifndef G502_R1FA037
#define G502_R1FA037

#define A2
#define DB150v1

#define PATH_INTERNAL L"/usb/other/RECYCLER"
#define PATH_EXTERNAL L"/card/system/RECYCLER"
#define TEXTID_LOCK 0x123C // Locked

#define KBD_SHORT_PRESS 0x0
#define KBD_LONG_PRESS 0x1
#define KBD_REPEAT 0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE 0x4

#define KEY_DIEZ 0x1E
#define KEY_STAR 0x1D
#define KEY_ESC 0x4
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB
#define KEY_ENTER 0x8
#define KEY_DIGITAL_0 0x13

#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xE
#define PAGE_EXIT_EVENT 0xF
#define DB_UPDATE_EVENT 0x1770

#define RETURN_TO_STANDBY_EVENT 0x841
#define TERMINATE_SESSION_EVENT 0x843

#endif
