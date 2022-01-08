#ifndef G502_R1FA037
#define G502_R1FA037

#define A2
#define DB3150v1

#define ACTION_ACCEPT 0xFAC
#define ACTION_LONG_BACK 0xFAF
#define ACTION_DELETE 0xFB4
#define ACTION_NO 0xFBE
#define ACTION_BACK 0xFC0
#define ACTION_SELECT1 0xFC2
#define ACTION_YES 0xFC5

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xE
#define PAGE_EXIT_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x841

#define VAR_BOOK (char *)0x1205FDE7
#define VAR_OK_PROC (char *)0x1205FDD5
#define VAR_BACK_PROC (char *)0x1205FE37
#define VAR_HEADER_TEXT (char *)0x1205FE4F
#define VAR_PERINP_ROWNUM (char *)0x1205FE43
#define VAR_PERINP_CURPERC (char *)0x1205FDFF
#define VAR_STRINP_MODE (char *)0x1205FE0F
#define VAR_STRINP_MAX_LEN (char *)0x1205FE19
#define VAR_STRINP_MIN_LEN (char *)0x1205FE21
#define VAR_STRINP_SET_INT_VAL (char *)0x1205FDF9
#define VAR_STRINP_FIXED_TEXT (char *)0x1205FE35
#define VAR_STRINP_MIN_INT_VAL (char *)0x1205FE25
#define VAR_STRINP_MAX_INT_VAL (char *)0x1205FE1D
#define VAR_STRINP_NEW_LINE (char *)0x1205FE05
#define VAR_TIMEINP_TIME (char *)0x1205FDFD
#define VAR_TIMEINP_TIMEFORMAT (char *)0x1205FE4B
#define VAR_TIMEINP_TIMEFORMAT_SEC (char *)0x1205FE49
#define VAR_PREV_ACTION_PROC (char *)0xAC
#define VAR_LONG_BACK_PROC (char *)0x56

//#define StandbyBook             0x11B6FD30	//StandbyBook
//#define ScreensaverBook         0x11B83938	//ScreensaverBook

#define FILE_PATH (wchar_t *)0x11987FC4

#define REQUEST_ICN 0xF2F3 //POPUP_BIGWARNING_ICN

#define TEXT0_ICN 0xEC95     //JAVA_RUNNING_ICN
#define TIMEINPUT_ICN 0xEB82 //FR_INPUT_GUI_SET_TIME_ICN

#define SOFTKEY_TEXTID 0x645  //Add
#define SOFTKEY1_TEXTID 0x6AB //List
#define SOFTKEY2_TEXTID 0x679 //Edit

#define LASTEXTDB (DB_EXT *)0x11A364D8

#endif
