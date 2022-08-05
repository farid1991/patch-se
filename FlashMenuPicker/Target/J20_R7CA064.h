#ifndef J20_R7CA064
#define J20_R7CA064

#define A2
#define DB3350
#define REV2

#define INT_FLASH_PATH L"/usb/picture/flash"
#define EXT_FLASH_PATH L"/card/picture/flash"

#define FD_IMAGE (wchar_t *)0x14C91314
#define SETTINGS_PATH (wchar_t *)0x157F4D18
#define DEFAULT_FLASH_PATH (wchar_t*)0x157A69BC

#define MAINMENU_TXT 0xEB4
#define SUBMENU_TXT 0x227F
#define PREVIEW_SK_TXT 0xF14

#define ITEM_SYS_TXT 0x69F
#define ITEM_INT_TXT 0x3DE
#define ITEM_EXT_TXT 0x3DD

#define ITEM_SYS_ICN 0x1C58 //0xAA3
#define ITEM_INT_ICN 0xFF2
#define ITEM_EXT_ICN 0xFEE

#define DB_FLASH_ICN 0xF84C

#define KBD_LONG_PRESS    0x1
#define KBD_LONG_RELEASE  0x4
#define KBD_REPEAT        0x2
#define KBD_SHORT_PRESS   0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_STAR      0x22
#define KEY_DIEZ      0x23
#define KEY_ESC       0x4
#define KEY_UP        0x9
#define KEY_DOWN      0xD
#define KEY_LEFT      0xF
#define KEY_RIGHT     0xB
#define KEY_ENTER     0x8
#define KEY_DIGITAL_0 0x18

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
#define PAGE_ENTER_EVENT  0x10
#define PAGE_EXIT_EVENT   0x11

#define RETURN_TO_STANDBY_EVENT   0x840

#endif
