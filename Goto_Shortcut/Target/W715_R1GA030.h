#ifndef W715_R1GA030
#define W715_R1GA030

#define A2
#define DB3210

#define F_PATH (wchar_t *)0x15AFABA4

#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"
#define ELFS_PATH_COUNT 2

// Menu
#define TITLE_TXT 0xAA2        // L"Goto"
#define MENU_ADD_TXT 0x1939    // L"New shortcut"
#define MENU_MODIFY_TXT 0x1753 // L"Edit shortcut"
#define EMPTY_LIST_TXT 0x89A   // L"No shortcuts"
#define MENU_ABOUT_TXT 0x251B  // L"About"

// Editing
#define EDITOR_TITLE_TXT 0x2754    // L"Editor"
#define EDITOR_LABEL_TXT 0xEA0     // L"Name"
#define EDITOR_SHORTCUT_TXT 0x198E // L"Shortcut"
#define TYPES_TITLE_TXT 0x103E     // L"Type"

#define SHC_SET_MM 0x1C5B
#define SHC_SET_SHORTCUT_SK 0x192F
#define DELETEQ_TXT 0x198B

#define OPEN_TXT 0x531
#define SELECT_TXT 0xB5C

#define JAVA_APP_TXT 0x5D8
#define EVENT_TXT 0x103C
#define FOLDER_TXT 0x610
#define SELECT_FOLDER_TXT 0x610

#define HPB_OTHER_ICN 0xF761
#define MENU_SETTINGS_ICN 0x0519
#define ANIMALS_MOUSE_ICN 0x00BA

#define SHORTCUT_LIST_ICN 0x0808
#define ENTERTAINMENT_ICN 0x0807
#define DB_LIST_JAVA_ICN 0xF875
#define GUI_UNAVAILABLE_ICN 0xF8A6
#define DB_LIST_FOLDER_ICN 0x016A

#define SHC_DESKTOP_WATERMARK_ICN 0x0861

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
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840

#endif
