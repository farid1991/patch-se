#ifndef J105_R1HA035
#define J105_R1HA035

#define A2
#define DB3200

#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"
#define ELFS_PATH_COUNT 2

#define NIL_EVENT 0
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x840

#define _TITLE_TXT_ 0x00000C48 // L"Goto"

#define _EVENT_NUM_ 0x0000005D // MEDIAPLAYERKEY_PRESSED_EVENT_TAG

#define _SYNC_ 0x158C4FF8

#define _SHORTCUT1_ 0x15A3AE44 // L"Msg_Inbox"
#define _SHORTCUT2_ 0x15A3BC34 // L"MenuItem_Bt_Activation"
#define _SHORTCUT3_ 0x15A3AC98 // L"MenuItem_SetTemporaryAlarm"
#define _SHORTCUT4_ 0x15A3ABB8 // L"Menu_CalendarMain"
#define _SHORTCUT5_ 0x15933D70 // L"SelectProfile_Id"

#define _ITEM_TXT1_ 0x11BC //Inbox
#define _ITEM_TXT2_ 0x11B1 //Music Player
#define _ITEM_TXT3_ 0x1238 //ALarm
#define _ITEM_TXT4_ 0x113C //Calendar
#define _ITEM_TXT5_ 0x11F2 //Profiles
#define _ITEM_TXT6_ 0x1136 //Bluetooth

//GFX ID for item
#define _ITEM_ICN1_ 0x02C6
#define _ITEM_ICN2a 0x02D9
#define _ITEM_ICN2b 0x03B9
#define _ITEM_ICN3_ 0x0921
#define _ITEM_ICN4_ 0xF886
#define _ITEM_ICN5_ 0x07DD
#define _ITEM_ICN6a 0x002B
#define _ITEM_ICN6b 0x000C

//LNG ID Weekday
#define TEXTID_1 0x225D // Mon
#define TEXTID_2 0x2562 // Tue
#define TEXTID_3 0x2564 // Wed
#define TEXTID_4 0x2560 // Thu
#define TEXTID_5 0x255C // Fri
#define TEXTID_6 0x255E // Sat
#define TEXTID_7 0x255F // SUn

#endif
