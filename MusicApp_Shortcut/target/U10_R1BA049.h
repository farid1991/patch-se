#ifndef U10_R1BA049
#define U10_R1BA049

#define A2
#define DB3350
#define CLEARAUDIO

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x40EC

#define page_MusicApplication_ShowMessage (PAGE_DESC*)0x15BCF794

#define KEY_DIGITAL_0 0x18
#define KEY_DIGITAL_1 0x19
#define KEY_DIGITAL_2 0x1A
#define KEY_DIGITAL_3 0x1B
#define KEY_DIGITAL_4 0x1C
#define KEY_DIGITAL_5 0x1D
#define KEY_DIGITAL_6 0x1E
#define KEY_DIGITAL_7 0x1F
#define KEY_DIGITAL_8 0x20
#define KEY_DIGITAL_9 0x21

#define KEY_STAR 0x22
#define KEY_DIEZ 0x23
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define ACTION_MP_SETTINGS 0xE
#define ACTION_MP_SHORTCUT 0x18

#define SHORTCUT_TXT 0x2228

#define FILE_PATH (wchar_t *)0x15C1E0C4

#endif
