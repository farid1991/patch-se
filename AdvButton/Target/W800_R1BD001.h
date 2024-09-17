#ifndef W800_R1BD001
#define W800_R1BD001

#define A1
#define DB2010
#define USE_LIBPNG

#define BOOKMAN_PATH L"/tpa/user/other/ini"
#define BCFGEDIT_PATH L"/tpa/user/other/ZBin/BcfgEdit.elf"

#define CID_CDisplayManager (PUUID)0x441588D8
#define IID_IDisplayManager (PUUID)0x4417C728

#define get_VBUFFER (int *)0x4C08EA4C
#define LastExtDB (DB_EXT *)0x4422C7A0
#define SYNC (int *)0x4424CAF0

#define DEF_LIBPNG_VER_STRING (char *)0x443D8882 // "1.2.4"
#define CONFIG_PATH (wchar_t *)0x443FB238        // L"/tpa/system/settings"
#define JAVA_STR (char *)0x446917F8              // "Java"
#define FOREIGNAPP (char *)0x4441AF2C            // "Foreign app "
#define MAINMENU_ID (wchar_t *)0x4441A8F0        // L"MainMenu"
#define SELECT_PROFILE_ID (wchar_t *)0x442A1116  // L"SelectProfile_Id"
#define SETTINGS_BT_ID (wchar_t *)0x4420D724     // L"MenuItem_Bt_Activation"
#define SETTINGS_IR_ID (wchar_t *)0x442A2E8A     // L"Settings_IR_Id"

#define NIL_EVENT 0
#define BOOK_DESTROYED_EVENT 4
#define PAGE_ENTER_EVENT 5
#define PAGE_EXIT_EVENT 6
#define MAIN_WINDOW_GOT_FOCUS_EVENT 0x7
#define MAIN_WINDOW_LOST_FOCUS_EVENT 0x8
#define MAIN_WINDOW_MINIMIZED_EVENT 0xB
#define MAIN_WINDOW_RESTORED_EVENT 0xC
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
#define KEY_MEDIAPLAYER 0x1F
#define KEY_PLAY 0x20
#define KEY_CAMERA 0x21
#define KEY_CAMERA_FOCUS 0x22
#define KEY_CAMERA_SHOT 0x23

#define RESTART_TXT 0x667
#define RESTART_ICN 0xE63D
#define SHUTDOWN_TXT 0x129B
#define SHUTDOWN_ICN 0xE7AB
#define FLIGHTMODE_ICN 0xE9B7
#define SILENTMODE_TXT 0xA7D
#define SILENTMODE_ICN 0xE72C
#define POPUP_SILENT_ICN 0xE673
#define BLUETOOTH_TXT 0xEBF
#define BLUETOOTH_ICN 0xE8F3
#define IRDA_TXT 0xA16
#define IRDA_ICN 0xE740
#define PROFILES_TXT 0xA5B
#define PROFILES_ICN 0xE72E
#define STANDBY_ICN 0xE6A1

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

#define EMPTY_LIST_TXT 0xC8F
#define BOOKMAN_MODE_TXT 0x454
#define MODE_SOFTKEYS_TXT 0x454
#define BOOKMAN_RENAME_TXT 0x13D6

#define SHORTCUT_TXT 0x1072
#define SHORTCUTS_TXT 0x1068
#define EDIT_SHORTCUTS_TXT 0x1069
#define SET_MAINMENU_TXT 0x1071
#define DB_APPLICATIONS_TXT 0xE42
#define ABOUT_TXT 0x163E

#define BOOK_ITEM_ICON 0xE8FF
#define DB_LIST_APPS_ICN 0xE8E1
#define DB_LIST_JAVA_ICN 0xE771
#define RN_VERT_MY_SHORTCUTS_ICN 0xE916

#define TAB_BOOK_ACTIVE_ICN 0xE613
#define TAB_BOOK_INACTIVE_ICN 0xE614
#define TAB_ELF_ACTIVE_ICN 0xE60F
#define TAB_ELF_INACTIVE_ICN 0xE610

#define IDN_DIGIT_0_ICON 0xE7BB

#define VAR_ARG_BOOK (char *)0x4469DB5C
#define VAR_ARG_CALL_BACK_LONG_BACK (char *)0x4469DB66
#define VAR_ARG_CALL_BACK_OK (char *)0x4469DB42
#define VAR_ARG_CALL_BACK_PREV_ACT (char *)0x4469DBEC
#define VAR_ARG_HTEXT (char *)0x4469DC0A
#define VAR_ARG_STRINP_EMPTY_STR_EN (char *)0x4469DBA4
#define VAR_ARG_STRINP_MAX_LEN (char *)0x4469DBBA
#define VAR_ARG_STRINP_MIN_LEN (char *)0x4469DBC6
#define VAR_ARG_STRINP_MODE (char *)0x4469DBA6
#define VAR_ARG_STRINP_NEW_LINE (char *)0x4469DB90
#define VAR_ARG_STRINP_TEXT (char *)0x4469DB86

#endif
