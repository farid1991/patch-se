#ifndef W200_R4HA014
#define W200_R4HA014

#define A1
#define DB2010
#define USE_JAVA

#define HAS_ELF
#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/MSSEMC/Media files/other/ZBin"

#define F_PATH (wchar_t *)0x445B7544

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

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x7B2

#define TITLE_TXT 0x6E3            // L"Goto"
#define EMPTY_LIST_TXT 0x5D1       // L"No shortcuts"
#define MENU_ADD_TXT 0x74E         // L"New shortcut"
#define MENU_MODIFY_TXT 0x1219     // L"Edit shortcut"
#define MENU_ABOUT_TXT 0x1981      // L"About"
#define EDITOR_TITLE_TXT 0x75D     // L"Edit shortcuts"
#define EDITOR_LABEL_TXT 0x9E0     // L"Edit name"
#define EDITOR_SHORTCUT_TXT 0x123F // L"Shortcut"
#define TYPES_TITLE_TXT 0x5F3      // L"Type"
#define SHC_SET_MM 0x123E
#define SHC_SET_SHORTCUT_SK 0x123F
#define DELETEQ_TXT 0x750
#define OPEN_TXT 0xEB1
#define SELECT_TXT 0x1634
#define JAVA_APP_TXT 0x34A
#define EVENT_TXT 0x751
#define FOLDER_TXT 0x360
#define SELECT_FOLDER_TXT 0xE48

#define HPB_OTHER_ICN 0xE717
#define MENU_SETTINGS_ICN 0xE91C
#define ANIMALS_MOUSE_ICN 0xE5A2
#define SHORTCUT_LIST_ICN 0xE930
#define ENTERTAINMENT_ICN 0xE5F7
#define DB_LIST_JAVA_ICN 0xE601
#define GUI_UNAVAILABLE_ICN 0xE6F8
#define DB_LIST_FOLDER_ICN 0xE5FE

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

#define DB_CMD_DELETE 0x3
#define DB_CMD_LAST 0x44
#define DB_CMD_RUN 0x1

#endif
