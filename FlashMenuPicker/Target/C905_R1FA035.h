#ifndef C905_R1FA035
#define C905_R1FA035

#define A2
#define DB3210

#define INT_FLASH_PATH L"/usb/picture/flash"
#define EXT_FLASH_PATH L"/card/picture/flash"

#define FD_IMAGE (wchar_t *)0x15C2798C
#define SETTINGS_PATH (wchar_t *)0x15B50370
#define DEFAULT_FLASH_PATH (wchar_t *)0x15AE2A40

#define MAINMENU_TXT 0x790
#define SUBMENU_TXT 0x1C5B
#define PREVIEW_SK_TXT 0x8FD
#define EMPTY_LIST_TXT 0x612

#define ITEM_SYS_TXT 0x1862
#define ITEM_INT_TXT 0x2D0
#define ITEM_EXT_TXT 0x2CF

#define ITEM_SYS_ICN 0x24D
#define ITEM_INT_ICN 0x657
#define ITEM_EXT_ICN 0x64A

#define DB_FLASH_ICN 0x184

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_STAR 0x22
#define KEY_DIEZ 0x23
#define KEY_ESC 0x4
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB
#define KEY_ENTER 0x8
#define KEY_DIGITAL_0 0x18

#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10

#define RETURN_TO_STANDBY_EVENT 0x840

#endif
