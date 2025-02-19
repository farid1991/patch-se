#ifndef J20_R7CA064
#define J20_R7CA064

#define A2
#define DB3350
#define USE_JAVA

#define HAS_ELF
#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"

#define F_PATH (wchar_t *)0x157F4D18

#define TITLE_TXT 0xD13            // L"Goto"
#define MENU_ADD_TXT 0x176         // L"New shortcut"
#define MENU_MODIFY_TXT 0x1BD      // L"Edit shortcut"
#define EMPTY_LIST_TXT 0xBA8       // L"No shortcuts"
#define MENU_ABOUT_TXT 0x1A57      // L"About"
#define EDITOR_TITLE_TXT 0x2AC6    // L"Editor"
#define EDITOR_LABEL_TXT 0x1151    // L"Name"
#define EDITOR_SHORTCUT_TXT 0x1DB8 // L"Shortcut"
#define TYPES_TITLE_TXT 0x12C6     // L"Type"
#define SHC_SET_MM 0x227F          // Set to main menu
#define SHC_SET_SHORTCUT_SK 0x1D7E // add shortcut
#define DELETEQ_TXT 0x2276         // delete shortcut
#define JAVA_APP_TXT 0x7AC         // Java

#define OPEN_TXT 0x702
#define SELECT_TXT 0xDCE

#define EVENT_TXT 0x12F5
#define FOLDER_TXT 0xA8C
#define SELECT_FOLDER_TXT 0x1CF6

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

#define DB_CMD_DELETE 0x8
#define DB_CMD_LAST 0x45
#define DB_CMD_RUN 0x1

#endif
