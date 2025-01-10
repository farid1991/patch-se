#ifndef K800_R8BF003
#define K800_R8BF003

#define A1
#define DB2020
#define USE_JAVA
#define HAS_ELF
#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"

#define F_PATH (wchar_t *)0x45836DC8

// Menu
#define TITLE_TXT 0x8C2        // L"Goto"
#define MENU_ADD_TXT 0x93A     // L"New shortcut"
#define MENU_MODIFY_TXT 0x18F8 // L"Edit shortcut"
#define EMPTY_LIST_TXT 0x2155  // L"No shortcuts"
#define MENU_ABOUT_TXT 0xBC6   // L"About"

// Editing
#define EDITOR_TITLE_TXT 0x16A     // L"Editor"
#define EDITOR_LABEL_TXT 0xC4C     // L"Name"
#define EDITOR_SHORTCUT_TXT 0x18FC // L"Shortcut"
#define TYPES_TITLE_TXT 0x1624     // L"Type"

#define SHC_SET_MM 0x1903
#define SHC_SET_SHORTCUT_SK 0x1904
#define DELETEQ_TXT 0x93C

#define OPEN_TXT 0x8ED
#define SELECT_TXT 0x906

#define JAVA_APP_TXT 0x4CA
#define EVENT_TXT 0x1550
#define FOLDER_TXT 0x511
#define SELECT_FOLDER_TXT 0x1251

#define HPB_OTHER_ICN 0xEB66
#define MENU_SETTINGS_ICN 0xEC4B
#define ANIMALS_MOUSE_ICN 0xE5D2

#define SHORTCUT_LIST_ICN 0xEDF4
#define ENTERTAINMENT_ICN 0xEAC6
#define DB_LIST_JAVA_ICN 0xEA0A
#define GUI_UNAVAILABLE_ICN 0xEB42
#define DB_LIST_FOLDER_ICN 0xEA07

#define NIL_EVENT 0x0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0x7
#define PAGE_EXIT_EVENT 0x8
#define RETURN_TO_STANDBY_EVENT 0x848

#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
//#define ACTION_CLIPBOARD_COPYALL UNDEFINED
//#define ACTION_CLIPBOARD_MARKANDCOPY UNDEFINED
//#define ACTION_CLIPBOARD_PASTE UNDEFINED
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
//#define ACTION_DB_MANAGEFILE UNDEFINED
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

#define DB_CMD_DELETE 0x9
#define DB_CMD_LAST 0x4D
#define DB_CMD_RUN 0x1

#endif
