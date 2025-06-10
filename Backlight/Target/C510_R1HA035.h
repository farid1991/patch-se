#ifndef C510_R1HA035
#define C510_R1HA035

#define A2
#define DB3210

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x840

#define StandbyBook 0x15A29D90
#define ScreensaverBook 0x158D2DD8

#define REQUEST_ICN 0xF463

#define TEXT0_ICN 0x478
#define TIMEINPUT_ICN 0x32B

#define SOFTKEY_TEXTID 0x14B
#define SOFTKEY1_TEXTID 0x5E6
#define SOFTKEY2_TEXTID 0x189

#define FILE_PATH (wchar_t *)0x15A86E38

#define VAR_BOOK (char *)0x15CAB83E
#define VAR_OK_PROC (char *)0x15CAB82C
#define VAR_BACK_PROC (char *)0x15CAB888
#define VAR_LONG_BACK_PROC (char *)0x15CAB840
#define VAR_HEADER_TEXT (char *)0x15CAB89E
#define VAR_PERINP_ROWNUM (char *)0x15CAB892
#define VAR_PERINP_CURPERC (char *)0x15CAB856
#define VAR_STRINP_MODE (char *)0x15CAB866
#define VAR_STRINP_MAX_LEN (char *)0x15CAB86E
#define VAR_STRINP_MIN_LEN (char *)0x15CAB876
#define VAR_STRINP_SET_INT_VAL (char *)0x15CAB850
#define VAR_STRINP_FIXED_TEXT (char *)0x15CAB886
#define VAR_STRINP_MIN_INT_VAL (char *)0x15CAB87A
#define VAR_STRINP_MAX_INT_VAL (char *)0x15CAB872
#define VAR_STRINP_NEW_LINE (char *)0x15CAB85C
#define VAR_TIMEINP_TIME (char *)0x15CAB854
#define VAR_TIMEINP_TIMEFORMAT (char *)0x15CAB89A
#define VAR_TIMEINP_TIMEFORMAT_SEC (char *)0x15CAB898

#define LASTEXTDB (DB_EXT *)0x15B5CE04

#endif
