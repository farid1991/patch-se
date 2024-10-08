#ifndef K600_R2BB001
#define K600_R2BB001

#define A1
#define DB2000
#define USE_LIBPNG
#define USE_IDISPLAY_MANAGER

#define BOOKMAN_PATH L"/tpa/user/other/ini"
#define BCFGEDIT_PATH L"/tpa/user/other/ZBin/BcfgEdit.elf"

#define CID_CDisplayManager (PUUID)0x20D76558
#define IID_IDisplayManager (PUUID)0x20DAF3FC

#define LastExtDB (DB_EXT *)0x20F1E174
#define SYNC (int *)0x20F3F914

#define DEF_LIBPNG_VER_STRING (char *)0x20DBF398 // "1.2.4"
#define CONFIG_PATH (wchar_t *)0x21161C44        // L"/tpa/system/settings"
#define JAVA_STR (char *)0x2143620C              // "Java"
#define FOREIGNAPP (char *)0x2117F060            // "Foreign app "
#define MAINMENU_ID (wchar_t *)0x20F89C4A        // L"MainMenu"
#define SELECT_PROFILE_ID (wchar_t *)0x21184A6E  // L"SelectProfile_Id"
#define SETTINGS_BT_ID (wchar_t *)0x2118380C     // L"MenuItem_Bt_Activation"
#define SETTINGS_IR_ID (wchar_t *)0x21184C2E     // L"Settings_IR_Id"

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

#define KEY_CAMERA_FOCUS 0x21
#define KEY_CAMERA_SHOT 0x21
#define KEY_DEL 0x4
#define KEY_DIEZ 0x1B
#define KEY_DIGITAL_0 0x10
#define KEY_DOWN 0xA
#define KEY_ENTER 0x5
#define KEY_ESC 0x3
#define KEY_LEFT 0xC
#define KEY_LEFT_SOFT 0x1
#define KEY_LENS_COVER_CLOSE 0x32
#define KEY_LENS_COVER_OPEN 0x31
#define KEY_VIDEOCALL 0x1E
#define KEY_POWER 0x0
#define KEY_RIGHT 0x8
#define KEY_RIGHT_SOFT 0x2
#define KEY_STAR 0x1A
#define KEY_TASK 0x1C
#define KEY_UP 0x6
#define KEY_VOL_DOWN 0xF
#define KEY_VOL_UP 0xE

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
#define ACTION_BACK 0xFC1
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_DELETE 0xFB4
#define ACTION_DONE 0xFB5
#define ACTION_EDIT 0xFB6
#define ACTION_EXPAND 0xFA2
#define ACTION_HELP 0xFB7
#define ACTION_INFO 0xFBA
#define ACTION_LONG_BACK 0xFAF
#define ACTION_MORE 0xFA0
#define ACTION_MORE1 0xFA1
#define ACTION_MORELIST 0xFB2
#define ACTION_NO 0xFBF
#define ACTION_NOT_EMPTY 0xFBC
#define ACTION_OK 0xFC0
#define ACTION_SAVE 0xFC2
#define ACTION_SELECT 0xFB9
#define ACTION_SELECT1 0xFC3
#define ACTION_UNCHECK 0xFC4
#define ACTION_YES 0xFC6

#define EMPTY_LIST_TXT 0xCCF
#define BOOKMAN_MODE_TXT 0x455
#define MODE_SOFTKEYS_TXT 0x455
#define BOOKMAN_RENAME_TXT 0x1414

#define SHORTCUT_TXT 0x10B3
#define SHORTCUTS_TXT 0x10A9
#define EDIT_SHORTCUTS_TXT 0x10AA
#define SET_MAINMENU_TXT 0x10B2
#define DB_APPLICATIONS_TXT 0xE82
#define ABOUT_TXT 0x167C

#define BOOK_ITEM_ICON 0xE8FF
#define DB_LIST_APPS_ICN 0xE8E1
#define DB_LIST_JAVA_ICN 0xE771
#define RN_VERT_MY_SHORTCUTS_ICN 0xE916

#define TAB_BOOK_ACTIVE_ICN 0xE613
#define TAB_BOOK_INACTIVE_ICN 0xE614
#define TAB_ELF_ACTIVE_ICN 0xE60F
#define TAB_ELF_INACTIVE_ICN 0xE610

#define IDN_DIGIT_0_ICON 0xE7B0
#define IDN_DIGIT_1_ICON 0xE7B1
#define IDN_DIGIT_2_ICON 0xE7B2
#define IDN_DIGIT_3_ICON 0xE7B3
#define IDN_DIGIT_4_ICON 0xE7B4
#define IDN_DIGIT_5_ICON 0xE7B5
#define IDN_DIGIT_6_ICON 0xE7B6
#define IDN_DIGIT_7_ICON 0xE7B7
#define IDN_DIGIT_8_ICON 0xE7B8
#define IDN_DIGIT_9_ICON 0xE7B9

#define VAR_ARG_BOOK (char *)0x21442570
#define VAR_ARG_CALL_BACK_LONG_BACK (char *)0x2144257A
#define VAR_ARG_CALL_BACK_OK (char *)0x21442556
#define VAR_ARG_CALL_BACK_PREV_ACT (char *)0x21442600
#define VAR_ARG_HTEXT (char *)0x2144261E
#define VAR_ARG_STRINP_EMPTY_STR_EN (char *)0x214425B8
#define VAR_ARG_STRINP_MAX_LEN (char *)0x214425CE
#define VAR_ARG_STRINP_MIN_LEN (char *)0x214425DA
#define VAR_ARG_STRINP_MODE (char *)0x214425BA
#define VAR_ARG_STRINP_NEW_LINE (char *)0x214425A4
#define VAR_ARG_STRINP_TEXT (char *)0x2144259A

#endif
