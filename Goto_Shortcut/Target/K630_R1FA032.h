#ifndef K630_R1FA032
#define K630_R1FA032

#define A2
#define DB3150v1

#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"
#define ELFS_PATH_COUNT 2

#define F_PATH 		  (wchar_t*)0x1192056C

#define ACTION_BACK       0xFC0
#define ACTION_LONG_BACK  0xFAF
#define ACTION_SELECT1    0xFC2
#define ACTION_DELETE     0xFB4
#define ACTION_YES        0xFC5
#define ACTION_NO         0xFBE

#define NIL_EVENT         0
#define ACCEPT_EVENT      0x2
#define PREVIOUS_EVENT    0x3
#define CANCEL_EVENT      0x4
#define PAGE_ENTER_EVENT  0xE
#define PAGE_EXIT_EVENT   0xF

#define RETURN_TO_STANDBY_EVENT 0x841
#define TERMINATE_SESSION_EVENT 0x843

#define RN_VERT_MY_SHORTCUTS_ICN  0xF3A2
#define POPUP_WARNING_ICN         0xF831

#define VAR_BOOK 		0x1205FDE7
#define VAR_STRINP_MODE 	0x1205FE0F
#define VAR_STRINP_NEW_LINE	0x1205FE05
#define VAR_STRINP_MAX_LEN 	0x1205FE19
#define VAR_STRINP_MIN_LEN 	0x1205FE21
#define VAR_STRINP_SET_INT_VAL 	0x1205FDF9
#define VAR_STRINP_FIXED_TEXT 	0x1205FE35
#define VAR_OK_PROC 		0x1205FDD5
#define VAR_BACK_PROC 		0x1205FE37
#define VAR_LONG_BACK_PROC 	0x1205FDE9
#define VAR_HEADER_TEXT 	0x1205FE4F
#define VAR_YESNO_PRE_QUESTION 	0x1205FE01
#define VAR_YESNO_QUESTION 	0x1205FE39
#define VAR_YESNO_YES_ACTION 	0x1205FE55
#define VAR_YESNO_NO_ACTION 	0x1205FE2D
#define VAR_STRINP_TEXT         0x1205FDFB
#define VAR_STRINP_ENABLE_EMPTY_STR 0x1205FE0D

// Menu
#define TITLE_TXT           0x2CB0 // L"Goto"
#define MENU_ADD_TXT        0x22B3 // L"New shortcut"
#define MENU_MODIFY_TXT     0x22AE // L"Edit shortcut"
#define EMPTY_LIST_TXT      0x1544 // L"No shortcuts"
#define MENU_ABOUT_TXT      0x19ED // L"About"
  
// Editing
#define EDITOR_TITLE_TXT    0x22AE // L"Editor"
#define EDITOR_LABEL_TXT    0x1EC8 // L"Name"
#define EDITOR_SHORTCUT_TXT 0x22AD // L"Shortcut"
#define TYPES_TITLE_TXT     0x2B21 // L"Type"

#define SHC_SET_MM          0x22B9
#define SHC_SET_SHORTCUT_SK 0x22BA
#define DELETEQ_TXT         0x2727

#define OPEN_TXT            0x6ED
#define SELECT_TXT          0x96C

#define JAVA_APP_TXT        0x69C
#define EVENT_TXT           0x1BA5
#define FOLDER_TXT          0x16DA
#define SELECT_FOLDER_TXT   0x1820

#define HPB_OTHER_ICN       0xEBB8
#define MENU_SETTINGS_ICN   0xED13
#define ANIMALS_MOUSE_ICN   0xE5CB

#define SHORTCUT_LIST_ICN   0xF32A
#define ENTERTAINMENT_ICN   0xF329
#define DB_LIST_JAVA_ICN    0xEA70
#define GUI_UNAVAILABLE_ICN 0xF8A6
#define DB_LIST_FOLDER_ICN  0xEA6F

#endif
