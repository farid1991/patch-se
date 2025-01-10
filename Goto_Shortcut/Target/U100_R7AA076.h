#ifndef U100_R7AA076
#define U100_R7AA076

#define A2
#define DB3350
#define REV1

#define HAS_ELF
#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"

#define F_PATH (wchar_t *)0x159E0804

#define TITLE_TXT 0xCE2            // L"Goto"
#define MENU_ADD_TXT 0x176         // L"New shortcut"
#define MENU_MODIFY_TXT 0x1BD      // L"Edit shortcut"
#define EMPTY_LIST_TXT 0xB77       // L"No shortcuts"
#define MENU_ABOUT_TXT 0x2B93      // L"About"
#define EDITOR_TITLE_TXT 0x2A7C    // L"Editor"
#define EDITOR_LABEL_TXT 0x1120    // L"Name"
#define EDITOR_SHORTCUT_TXT 0x1D73 // L"Shortcut"
#define TYPES_TITLE_TXT 0x12C6     // L"Type"
#define SHC_SET_MM 0x2238          // Set to main menu
#define SHC_SET_SHORTCUT_SK 0x1D39 // add shortcut
#define DELETEQ_TXT 0x222F         // delete shortcut

#define OPEN_TXT 0x6D1
#define SELECT_TXT 0xD9D

#define JAVA_APP_TXT 0x5D8
#define EVENT_TXT 0x12C4
#define FOLDER_TXT 0xA5B
#define SELECT_FOLDER_TXT 0xA6B

#define HPB_OTHER_ICN 0xF761
#define MENU_SETTINGS_ICN 0x1015
#define ANIMALS_MOUSE_ICN 0x3F5

#define SHORTCUT_LIST_ICN 0x1C49
#define ENTERTAINMENT_ICN 0xB8D
#define DB_LIST_JAVA_ICN 0xF875
#define GUI_UNAVAILABLE_ICN 0xF8A6
#define DB_LIST_FOLDER_ICN 0xFEB

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x840

#define DB_CMD_DELETE 0x9
#define DB_CMD_INFO 0x1E
#define DB_CMD_LAST 0x4A
#define DB_CMD_EDIT 0x7
#define DB_CMD_RENAME 0xD
#define DB_CMD_RUN 0x1

#endif
