#ifndef U10_R7AA071
#define U10_R7AA071

#define A2
#define DB3350

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
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x840

#define VAR_BOOK (char *)0x15BEF9C6
#define VAR_OK_PROC (char *)0x15BEF9B4
#define VAR_BACK_PROC (char *)0x15BEFA10
#define VAR_LONG_BACK_PROC (char *)0x15BEF9C8
#define VAR_HEADER_TEXT (char *)0x15BEFA24
#define VAR_PERINP_ROWNUM (char *)0x15BEFA1A
#define VAR_PERINP_CURPERC (char *)0x15BEF9DE
#define VAR_STRINP_MODE (char *)0x15BEF9EE
#define VAR_STRINP_MAX_LEN (char *)0x15BEF9F6
#define VAR_STRINP_MIN_LEN (char *)0x15BEF9FE
#define VAR_STRINP_SET_INT_VAL (char *)0x15BEF9D8
#define VAR_STRINP_FIXED_TEXT (char *)0x15BEFA0E
#define VAR_STRINP_MIN_INT_VAL (char *)0x15BEFA02
#define VAR_STRINP_MAX_INT_VAL (char *)0x15BEF9FA
#define VAR_STRINP_NEW_LINE (char *)0x15BEF9EC
#define VAR_TIMEINP_TIME (char *)0x15BEF9DC
#define VAR_TIMEINP_TIMEFORMAT (char *)0x15BEFA22
#define VAR_TIMEINP_TIMEFORMAT_SEC (char *)0x15BEFA20


#define FILE_PATH (wchar_t *)0x15C32E78

#define REQUEST_ICN 0xF2F3   //POPUP_BIGWARNING_ICN
#define TEXT0_ICN 0xEC95     //JAVA_RUNNING_ICN
#define TIMEINPUT_ICN 0xEB82 //FR_INPUT_GUI_SET_TIME_ICN

#define SOFTKEY_TEXTID 0x645  //Add
#define SOFTKEY1_TEXTID 0x6AB //List
#define SOFTKEY2_TEXTID 0x679 //Edit

#define LASTEXTDB (DB_EXT *)0x15CEDFC0

#endif
