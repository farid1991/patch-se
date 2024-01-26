#ifndef K600_R2BB001
#define K600_R2BB001

#define A1
#define DB2000
#define USE_JAVA
#define HAS_ELF
#define ELFS_INT_PATH L"/tpa/user/other/ZBin"

#define SYNC (int *)0x20F3F914
#define F_PATH (wchar_t *)0x21161C44

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 5
#define PAGE_EXIT_EVENT 6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define ONOFFKEY_SHORT_PRESS_EVENT 0x1B
#define RETURN_TO_STANDBY_EVENT 0x7B2

#define TITLE_TXT 0x63E            // L"Goto"
#define MENU_ADD_TXT 0x6A9         // L"New shortcut"
#define MENU_MODIFY_TXT 0x10AA     // L"Edit shortcut"
#define EMPTY_LIST_TXT 0x10AF      // L"No shortcuts"
#define MENU_ABOUT_TXT 0x167C      // L"About"
#define EDITOR_TITLE_TXT 0x10AA    // L"Edit shortcuts"
#define EDITOR_LABEL_TXT 0x1490    // L"Edit name"
#define EDITOR_SHORTCUT_TXT 0x10A9 // L"Shortcut"
#define TYPES_TITLE_TXT 0xF88      // L"Type"
#define SHC_SET_MM 0x10B2
#define SHC_SET_SHORTCUT_SK 0x10B3
#define DELETEQ_TXT 0x6AB
#define OPEN_TXT 0xEF3
#define SELECT_TXT 0x142C
#define JAVA_APP_TXT 0xAA3
#define EVENT_TXT 0x748
#define FOLDER_TXT 0xE97
#define SELECT_FOLDER_TXT 0xE97

#define HPB_OTHER_ICN 0xE698
#define MENU_SETTINGS_ICN 0xE7A6
#define ANIMALS_MOUSE_ICN 0xE816
#define SHORTCUT_LIST_ICN 0xE8FE
#define ENTERTAINMENT_ICN 0xE8F8
#define DB_LIST_JAVA_ICN 0xE771
#define GUI_UNAVAILABLE_ICN 0xE568
#define DB_LIST_FOLDER_ICN 0xE770

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
