#ifndef W200_R4HA014
#define W200_R4HA014

#define A1
#define DB2010
#define USE_LIBPNG
#define SAVE_AT_USB

#define BOOKMAN_PATH L"/usb/other/ini"
#define BCFGEDIT_PATH L"/usb/other/ZBin/BcfgEdit.elf"

#define CID_CDisplayManager (PUUID)0x443430D0
#define IID_IDisplayManager (PUUID)0x443616D0

#define get_VBUFFER (int *)0x4C0671B4
#define LastExtDB (DB_EXT *)0x4445937C
#define SYNC (int *)0x44476E00

#define DEF_LIBPNG_VER_STRING (char *)0x4452F0C8 // "1.2.4"
#define CONFIG_PATH (wchar_t *)0x445B7544        // L"/tpa/system/settings"
#define JAVA_STR (char *)0x44842483              // "Java"
#define FOREIGNAPP (char *)0x445D6EB6            // "Foreign app "
#define MAINMENU_ID (wchar_t *)0x444CAC66        // L"MainMenu"
#define SELECT_PROFILE_ID (wchar_t *)0x445DC5D0  // L"SelectProfile_Id"
#define SETTINGS_IR_ID (wchar_t *)0x445DCA9C     // L"Settings_IR_Id"

#define NIL_EVENT 0
#define BOOK_DESTROYED_EVENT 4
#define PAGE_ENTER_EVENT 5
#define PAGE_EXIT_EVENT 6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define ONOFFKEY_SHORT_PRESS_EVENT 0x1C
#define RETURN_TO_STANDBY_EVENT 0x7B2
#define RETURN_TO_STANDBY_REFUSED_EVENT 0x7B3
#define TERMINATE_SESSION_EVENT 0x7B4

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_POWER 0x0
#define KEY_CAMERA_FOCUS 0x22
#define KEY_CAMERA_SHOT 0x23
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
#define KEY_MEDIAPLAYER 0x1F
#define KEY_PHF 0x36
#define KEY_PHF1 0x37
#define KEY_PHF_ENDOF 0x38
#define KEY_PLAY 0x20
#define KEY_POWER 0x0
#define KEY_RIGHT 0x8
#define KEY_RIGHT_SOFT 0x2
#define KEY_STAR 0x1A
#define KEY_TASK 0x1C
#define KEY_UP 0x6
#define KEY_VOL_DOWN 0xF
#define KEY_VOL_UP 0xE
#define LAMPKEY_LONG_PRESS_EVENT 0x4E
#define LAMPKEY_PRESSED_EVENT 0x4D

#define RESTART_TXT 0
#define RESTART_ICN 0
#define SHUTDOWN_TXT 0
#define SHUTDOWN_ICN 0
#define FLIGHTMODE_ICN 0
#define SILENTMODE_TXT 0
#define SILENTMODE_ICN 0
#define POPUP_SILENT_ICN 0
#define BLUETOOTH_TXT 0
#define BLUETOOTH_ICN 0
#define IRDA_TXT 0
#define IRDA_ICN 0
#define PROFILES_TXT 0
#define PROFILES_ICN 0
#define STANDBY_ICN 0

#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CLIPBOARD_COPYALL 0xFD6
#define ACTION_CLIPBOARD_MARKANDCOPY 0xFD7
#define ACTION_CLIPBOARD_PASTE 0xFD8
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
#define ACTION_DB_MANAGEFILE 0x46
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

#define EMPTY_LIST_TXT 0x64B
#define BOOKMAN_MODE_TXT 0x4B1
#define MODE_SOFTKEYS_TXT 0x4B1
#define BOOKMAN_RENAME_TXT 0x10FB

#define SHORTCUT_TXT 0x123F
#define SHORTCUTS_TXT 0x1235
#define EDIT_SHORTCUTS_TXT 0x1236
#define SET_MAINMENU_TXT 0x123E
#define DB_APPLICATIONS_TXT 0xFD2
#define ABOUT_TXT 0x1981

#define BOOK_ITEM_ICON 0xE918
#define DB_LIST_APPS_ICN 0xE8A2
#define DB_LIST_JAVA_ICN 0xE601
#define RN_VERT_MY_SHORTCUTS_ICN 0xE930

#define TAB_BOOK_ACTIVE_ICN 0xE9C3
#define TAB_BOOK_INACTIVE_ICN 0xE9C4
#define TAB_ELF_ACTIVE_ICN 0xE922
#define TAB_ELF_INACTIVE_ICN 0xE923

#define IDN_DIGIT_0_ICON 0xE6B2

#define VAR_ARG_BOOK (char *)0x4484BD93
#define VAR_ARG_CALL_BACK_LONG_BACK (char *)0x4484BD9D
#define VAR_ARG_CALL_BACK_OK (char *)0x4484BD7B
#define VAR_ARG_CALL_BACK_PREV_ACT (char *)0x4484BE05
#define VAR_ARG_HTEXT (char *)0x4484BE1F
#define VAR_ARG_STRINP_EMPTY_STR_EN (char *)0x4484BDCD
#define VAR_ARG_STRINP_MAX_LEN (char *)0x4484BDDD
#define VAR_ARG_STRINP_MIN_LEN (char *)0x4484BDE5
#define VAR_ARG_STRINP_MODE (char *)0x4484BDCF
#define VAR_ARG_STRINP_NEW_LINE (char *)0x4484BDC1
#define VAR_ARG_STRINP_TEXT (char *)0x4484BDB7

#endif
