#ifndef W900_R5BC004
#define W900_R5BC004

#define A1
#define DB2000
#define USE_LIBPNG
#define USE_IDISPLAY_MANAGER

#define BOOKMAN_PATH L"/usb/other/ini"
#define BCFGEDIT_PATH L"/usb/other/ZBin/BcfgEdit.elf"

#define CID_CDisplayManager (PUUID)0x211FDE80
#define IID_IDisplayManager (PUUID)0x21229110

#define LastExtDB (DB_EXT *)0x2140E5FC
#define SYNC (int *)0x2142D1B8

#define DEF_LIBPNG_VER_STRING (char *)0x2156D354 // "1.2.4"
#define CONFIG_PATH (wchar_t *)0x215D944C        // L"/tpa/system/settings"
#define JAVA_STR (char *)0x21A47BF0              // "Java"
#define FOREIGNAPP (char *)0x215F85F0            // "Foreign app "
#define MAINMENU_ID (wchar_t *)0x2148A6D0        // L"MainMenu"
#define SELECT_PROFILE_ID (wchar_t *)0x2148E5D8  // L"SelectProfile_Id"
#define SETTINGS_IR_ID (wchar_t *)0x21490222     // L"Settings_IR_Id"
#define SETTINGS_BT_ID (wchar_t *)0x213EF68C     // L"MenuItem_Bt_Activation"

#define NIL_EVENT 0
#define BOOK_DESTROYED_EVENT 4
#define PAGE_ENTER_EVENT 5
#define PAGE_EXIT_EVENT 6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define ONOFFKEY_SHORT_PRESS_EVENT 0x1B
#define RETURN_TO_STANDBY_EVENT 0x7B2
#define TERMINATE_SESSION_EVENT 0x7B4

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_POWER 0x0
#define KEY_LEFT_SOFT 0x1
#define KEY_RIGHT_SOFT 0x2
#define KEY_ESC 0x3
#define KEY_DEL 0x4
#define KEY_ENTER 0x5
#define KEY_UP 0x6
#define KEY_RIGHT 0x8
#define KEY_DOWN 0xA
#define KEY_LEFT 0xC
#define KEY_VOL_UP 0xE
#define KEY_VOL_DOWN 0xF
#define KEY_DIGITAL_0 0x10
#define KEY_DIGITAL_1 0x11
#define KEY_DIGITAL_2 0x12
#define KEY_DIGITAL_3 0x13
#define KEY_DIGITAL_4 0x14
#define KEY_DIGITAL_5 0x15
#define KEY_DIGITAL_6 0x16
#define KEY_DIGITAL_7 0x17
#define KEY_DIGITAL_8 0x18
#define KEY_DIGITAL_9 0x19
#define KEY_STAR 0x1A
#define KEY_DIEZ 0x1B
#define KEY_TASK 0x1C
#define KEY_INTERNET 0x1D
#define KEY_VIDEOCALL 0x1E
#define KEY_WALKMAN 0x1F
#define KEY_CAMERA_FOCUS 0x22
#define KEY_CAMERA_SHOT 0x23
#define KEY_LOCK 0x26
#define KEY_LENS_COVER_OPEN 0x31
#define KEY_LENS_COVER_CLOSE 0x32

#define RESTART_TXT 0x671
#define RESTART_ICN 0xE9CB
#define SHUTDOWN_TXT 0x5DA
#define SHUTDOWN_ICN 0xE96A
#define FLIGHTMODE_ICN 0xE9B7
#define SILENTMODE_TXT 0xA96
#define SILENTMODE_ICN 0xE72C
#define POPUP_SILENT_ICN 0xE673
#define BLUETOOTH_TXT 0x9D9
#define BLUETOOTH_ICN 0xE8F3
#define IRDA_TXT 0xA2F
#define IRDA_ICN 0xE8F9
#define PROFILES_TXT 0xFAF
#define PROFILES_ICN 0xE72E
#define STANDBY_ICN 0xE8E1

#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
#define ACTION_DELETE 0xFB4
#define ACTION_DONE 0xFB5
#define ACTION_EDIT 0xFB6
#define ACTION_EXPAND 0xFA2
#define ACTION_HELP 0xFB7
#define ACTION_INFO 0xFB9
#define ACTION_LONG_BACK 0xFAF
#define ACTION_MORE 0xFA0
#define ACTION_MORE1 0xFA1
#define ACTION_MORELIST 0xFB2
#define ACTION_NO 0xFBE
#define ACTION_NOT_EMPTY 0xFBB
#define ACTION_OK 0xFBF
#define ACTION_SAVE 0xFC1
#define ACTION_SELECT 0xFB8
#define ACTION_SELECT1 0xFC2
#define ACTION_UNCHECK 0xFC3
#define ACTION_YES 0xFC5

#define EMPTY_LIST_TXT 0x63F
#define BOOKMAN_MODE_TXT 0x4A2
#define MODE_SOFTKEYS_TXT 0x4A2
#define BOOKMAN_RENAME_TXT 0x164F

#define SHORTCUT_TXT 0x1286
#define SHORTCUTS_TXT 0x1286
#define EDIT_SHORTCUTS_TXT 0x1287
#define SET_MAINMENU_TXT 0x128F
#define DB_APPLICATIONS_TXT 0xBA9
#define ABOUT_TXT 0x19BA

#define DB_LIST_APPS_ICN 0xE8F1
#define DB_LIST_JAVA_ICN 0xE624
#define RN_VERT_MY_SHORTCUTS_ICN 0xE983

#define TAB_BOOK_ACTIVE_ICN 0xE7D7
#define TAB_BOOK_INACTIVE_ICN 0xE7D8
#define TAB_ELF_ACTIVE_ICN 0xE979
#define TAB_ELF_INACTIVE_ICN 0xE978

#define IDN_DIGIT_0_ICON 0xE540
#define IDN_DIGIT_1_ICON 0xE541
#define IDN_DIGIT_2_ICON 0xE542
#define IDN_DIGIT_3_ICON 0xE543
#define IDN_DIGIT_4_ICON 0xE544
#define IDN_DIGIT_5_ICON 0xE545
#define IDN_DIGIT_6_ICON 0xE546
#define IDN_DIGIT_7_ICON 0xE547
#define IDN_DIGIT_8_ICON 0xE548
#define IDN_DIGIT_9_ICON 0xE549

#define VAR_ARG_BOOK (char *)0x21A51531
#define VAR_ARG_CALL_BACK_LONG_BACK (char *)0x21A5153B
#define VAR_ARG_CALL_BACK_OK (char *)0x21A51519
#define VAR_ARG_CALL_BACK_PREV_ACT (char *)0x21A515A3
#define VAR_ARG_HTEXT (char *)0x21A515BD
#define VAR_ARG_STRINP_EMPTY_STR_EN (char *)0x21A5156B
#define VAR_ARG_STRINP_MAX_LEN (char *)0x21A5157B
#define VAR_ARG_STRINP_MIN_LEN (char *)0x21A51583
#define VAR_ARG_STRINP_MODE (char *)0x21A5156D
#define VAR_ARG_STRINP_NEW_LINE (char *)0x21A5155F
#define VAR_ARG_STRINP_TEXT (char *)0x21A51555

#endif
