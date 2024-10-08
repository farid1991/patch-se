#ifndef Z520_R3J017
#define Z520_R3J017

#define A1
#define DB2010
#define USE_LIBPNG
#define USE_IDISPLAY_MANAGER

#define BOOKMAN_PATH L"/tpa/user/other/ini"
#define BCFGEDIT_PATH L"/tpa/user/other/ZBin/BcfgEdit.elf"

#define CID_CDisplayManager (PUUID)0x44149D20
#define IID_IDisplayManager (PUUID)0x4416CD48

#define get_VBUFFER (int *)0x4C064BA0
#define LastExtDB (DB_EXT *)0x4422B8C4
#define SYNC (int *)0x4424C3E8

#define DEF_LIBPNG_VER_STRING (char *)0x443CFE38 // "1.2.4"
#define CONFIG_PATH (wchar_t *)0x443F5F6E        // L"/tpa/system/settings"
#define JAVA_STR (char *)0x4466456B              // "Java"
#define FOREIGNAPP (char *)0x44415A6C            // "Foreign app "
#define MAINMENU_ID (wchar_t *)0x44296F7E        // L"MainMenu"
#define SELECT_PROFILE_ID (wchar_t *)0x4429BF6A  // L"SelectProfile_Id"
#define SETTINGS_BT_ID (wchar_t *)0x4420C290     // L"MenuItem_Bt_Activation"
#define SETTINGS_IR_ID (wchar_t *)0x4429DEC6     // L"Settings_IR_Id"

#define NIL_EVENT 0
#define BOOK_DESTROYED_EVENT 4
#define PAGE_ENTER_EVENT 5
#define PAGE_EXIT_EVENT 6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define ONOFFKEY_SHORT_PRESS_EVENT 0x1B
#define RETURN_TO_STANDBY_EVENT 0x7B2
#define RETURN_TO_STANDBY_REFUSED_EVENT 0x7B3
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
#define KEY_OPERATOR 0x1D
#define KEY_CAMERA 0x21

#define RESTART_TXT 0x6B6
#define RESTART_ICN 0xE963
#define SHUTDOWN_TXT 0x620
#define SHUTDOWN_ICN 0xE956
#define FLIGHTMODE_ICN 0xE8AD
#define SILENTMODE_TXT 0xAF2
#define SILENTMODE_ICN 0xE93D
#define POPUP_SILENT_ICN 0xE8D8
#define BLUETOOTH_TXT 0xA2F
#define BLUETOOTH_ICN 0xE90B
#define IRDA_TXT 0xA87
#define IRDA_ICN 0xE911
#define PROFILES_TXT 0x101C
#define PROFILES_ICN 0xE8E5
#define STANDBY_ICN 0xE683

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

#define EMPTY_LIST_TXT 0xD29
#define BOOKMAN_MODE_TXT 0x49A
#define MODE_SOFTKEYS_TXT 0x49A
#define BOOKMAN_RENAME_TXT 0x1506

#define SHORTCUT_TXT 0x119D
#define SHORTCUTS_TXT 0x1193
#define EDIT_SHORTCUTS_TXT 0x1194
#define SET_MAINMENU_TXT 0x119C
#define DB_APPLICATIONS_TXT 0xEDE
#define ABOUT_TXT 0x17D8

#define BOOK_ITEM_ICON 0xE917
#define DB_LIST_APPS_ICN 0xE89f
#define DB_LIST_JAVA_ICN 0xE627
#define RN_VERT_MY_SHORTCUTS_ICN 0xE92F

#define TAB_BOOK_ACTIVE_ICN 0xE7CB
#define TAB_BOOK_INACTIVE_ICN 0xE7CC
#define TAB_ELF_ACTIVE_ICN 0xE7CD
#define TAB_ELF_INACTIVE_ICN 0xE7CE

#define IDN_DIGIT_0_ICON 0xE6CA
#define IDN_DIGIT_1_ICON 0xE6CB
#define IDN_DIGIT_2_ICON 0xE6CC
#define IDN_DIGIT_3_ICON 0xE6CD
#define IDN_DIGIT_4_ICON 0xE6CE
#define IDN_DIGIT_5_ICON 0xE6CF
#define IDN_DIGIT_6_ICON 0xE6D0
#define IDN_DIGIT_7_ICON 0xE6D1
#define IDN_DIGIT_8_ICON 0xE6D2
#define IDN_DIGIT_9_ICON 0xE6D3

#define VAR_ARG_BOOK (char *)0x4467092C
#define VAR_ARG_CALL_BACK_LONG_BACK (char *)0x44670936
#define VAR_ARG_CALL_BACK_OK (char *)0x44670912
#define VAR_ARG_CALL_BACK_PREV_ACT (char *)0x446709BA
#define VAR_ARG_HTEXT (char *)0x446709D8
#define VAR_ARG_STRINP_EMPTY_STR_EN (char *)0x44670974
#define VAR_ARG_STRINP_MAX_LEN (char *)0x44670988
#define VAR_ARG_STRINP_MIN_LEN (char *)0x44670994
#define VAR_ARG_STRINP_MODE (char *)0x44670976
#define VAR_ARG_STRINP_NEW_LINE (char *)0x44670960
#define VAR_ARG_STRINP_TEXT (char *)0x44670956

#endif
