#ifndef G502_R1FA037
#define G502_R1FA037

#define A2
#define DB3150v1

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define PAGE_ENTER_EVENT 0xE
#define CANCEL_EVENT 0x4
#define PAGE_EXIT_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x841
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x3C36

#define KBD_LONG_RELEASE 0x4

#define ACTION_VIEW 0x34
#define ACTION_REPL 0x3B
#define ACTION_FORWARD 0x3D
#define ACTION_DETAIL 0x44
#define ACTION_CALL 0x9F
#define ACTION_VIDEOCALL 0xA0

#define ACTION_MP_SETTINGS 0xF
#define ACTION_MP_SHUTDOWNTIMER 0x17

#define TIMER_TXT 0x38C

#define TURNEDOFF_TXT 0x85C // Turn off
#define TURNEDON_TXT 0x7A2
#define TURNOFF_TXT 0x7A1

#define INPUT_ICN 0xEB82
#define INFO_ICN 0xF8F0
#define DISABLE_ICN 0xF787
#define MODIFY_ICN 0xED21

#define FILE_PATH (wchar_t *)0x11987FC4

#define VAR_BOOK (char *)0x1205FDE7
#define VAR_STRINP_MODE (char *)0x1205FE0F
#define VAR_STRINP_NEW_LINE (char *)0x1205FE05
#define VAR_STRINP_MAX_LEN (char *)0x1205FE19
#define VAR_STRINP_MIN_LEN (char *)0x1205FE21
#define VAR_STRINP_SET_INT_VAL (char *)0x1205FDF9
#define VAR_STRINP_FIXED_TEXT (char *)0x1205FE35
#define VAR_OK_PROC (char *)0x1205FDD5
#define VAR_HEADER_TEXT (char *)0x1205FE4F
#define VAR_YESNO_PRE_QUESTION (char *)0x1205FE01
#define VAR_YESNO_QUESTION (char *)0x1205FE39
#define VAR_YESNO_YES_ACTION (char *)0x1205FE55
#define VAR_YESNO_NO_ACTION (char *)0x1205FE2D
#define VAR_TIMEINP_TIME (char *)0x1205FDFD
#define VAR_TIMEINP_TIMEFORMAT (char *)0x1205FE4B

#endif
