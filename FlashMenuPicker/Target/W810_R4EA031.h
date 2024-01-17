#ifndef W810_R4EA031
#define W810_R4EA031

#define A1
#define DB2010

#define DEFAULT_FLASH_PATH (wchar_t*)0x44519AE8
#define INT_FLASH_PATH L"/usb/image/flash"
#define EXT_FLASH_PATH L"/card/MSSEMC/Media files/image/flash"

#define MAINMENU_TXT 0xB03
#define SUBMENU_TXT 0x122C
#define PREVIEW_SK_TXT 0x11CB

#define ITEM_SYS_TXT 0xA77
#define ITEM_INT_TXT 0x214
#define ITEM_EXT_TXT 0x213

#define ITEM_SYS_ICN 0xE859
#define ITEM_INT_ICN 0xE648
#define ITEM_EXT_ICN 0xE62E
#define DB_FLASH_ICN 0xE65D

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

#endif
