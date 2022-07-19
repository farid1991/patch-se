#ifndef K660_R1FA037
#define K660_R1FA037

#define A2
#define DB3150v1

#define GetFontDesc (FONT_DESC *)0x2A2846A4
#define GetFontCount (int *)0x2A284A14

#define CID_CMetaData (PUUID)0x1199C888
#define IID_IMetaData (PUUID)0x119C95AC
#define CID_CMusicServerManager (PUUID)0x119A8224
#define IID_IMusicServerManager (PUUID)0x119D0344

#define page_MusicApplication_Main (PAGE_DESC *)0x11B67854
#define FILE_PATH (wchar_t *)0x11989FF8

#define TEXT_MINUTES 0x946
#define TEXT_SECONDS 0x956

#define TEXT_RINGTONE 0x71D
#define TEXT_MESSAGEALERT 0x757
#define TEXT_ALARMSIGNAL 0x750
#define TEXT_CONTACTSIGNAL 0x662
#define TEXT_RING_CHANGED 0x71B
#define TEXT_MESSAGE_CHANGED 0x6C3

#define TEXT_FONT_SIZE 0xB4B
#define TEXT_OK 0xC6C
#define TEXT_COLOR 0x23D9

#define TEXT_USE 0x266
#define TEXT_USE_NOW 0x112
#define TEXT_EDIT 0x171

#define TEXT_ON 0x1E1
#define TEXT_OFF 0x1DF

#define TEXT_SKINS STR(TXT_SKINS)
#define TEXT_VIZ 0x163A
#define TEXT_GO_TO 0xC38
#define TEXT_TIMER 0x38C
#define TEXT_SHORTCUT 0x22AD
#define TEXT_LYRIC STR(TXT_LYRIC)
#define TEXT_USE_AS 0x78E
#define TEXT_EDIT_TAG STR(TXT_EDIT_TAG)

#define TEXT_YES 0x63
#define TEXT_NO 0x61
#define TEXT_ENABLE 0x85E
#define TEXT_DISABLE 0x85C
#define TEXT_ENABLED 0xA74
#define TEXT_DISABLED 0xA72
#define TEXT_SAVE 0x121

#define TEXT_CHANGES_MADE 0x218
#define TEXT_SAVE_BEFORE_EXIT 0x219

#define TEXT_ALIGN 0xAD4
#define TEXT_LEFT 0x17D3
#define TEXT_RIGHT 0x17D4

#define TEXT_PORTRAIT 0x30A
#define TEXT_LANDSCAPE 0x309

#define TEXT_POSITION 0x23DD

#define TEXT_TITLE STR(TXT_TITLE)
#define TEXT_ARTIST 0x153B
#define TEXT_ALBUM 0x1532
#define TEXT_GENRE 0x1586
#define TEXT_ALBUM_ART 0x1639

#define TEXT_FULLSCREEN 0x59C
#define TEXT_TEXT_COLOR 0x2E51
#define TEXT_BACKGROUND_COLOR 0x2385

#define TEXT_EQUALIZER 0x156C
#define TEXT_MANUAL 0x1593
#define TEXT_PRESET 0x15D5
#define TEXT_SELECT 0x24FC

#define PB_REC_ICN 0xF368
#define MC_LANDSCAPE_ICN 0xECBA
#define MC_PORTRAIT_ICN 0xECD5
#define RN_TAB_SESSION_MANAGER_SELECTED_ICN 0xF39E
#define RN_TAB_SESSION_MANAGER_DESELECTED_ICN 0xF39D

#define ACTION_MP_FILE 0x8
#define ACTION_MP_SETTINGS 0xF

#define ACTION_MP_SKINEDITOR 0x13
#define ACTION_MP_ALBUM_ART 0x14
#define ACTION_MP_SETTIME 0x15
#define ACTION_MP_TIMEROFF 0x16
#define ACTION_MP_SHORTCUT 0x17
#define ACTION_MP_LYRIC 0x18
#define ACTION_MP_USE_AS 0x19
#define ACTION_MP_EDITTAG 0x1A

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xE
#define PAGE_EXIT_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x841
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x3C36

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

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DEL 0x5
#define KEY_DIEZ 0x1E
#define KEY_DIGITAL_0 0x13
#define KEY_DIGITAL_1 0x14
#define KEY_DIGITAL_2 0x15
#define KEY_DIGITAL_3 0x16
#define KEY_DIGITAL_4 0x17
#define KEY_DIGITAL_5 0x18
#define KEY_DIGITAL_6 0x19
#define KEY_DIGITAL_7 0x1A
#define KEY_DIGITAL_8 0x1B
#define KEY_DIGITAL_9 0x1C
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4

#define KEY_LEFT 0xF
#define KEY_LEFT_SOFT 0x2

#define KEY_RIGHT 0xB
#define KEY_RIGHT_SOFT 0x3
#define KEY_STAR 0x1D
#define KEY_TASK 0x1F
#define KEY_UP 0x9
#define KEY_VOL_DOWN 0x12
#define KEY_VOL_UP 0x11

#define FONT_D_7R 0x01
#define FONT_E_8R 0x02
#define FONT_E_12R 0x0D
#define FONT_E_12B 0x0E
#define FONT_E_14R 0x12
#define FONT_E_14B 0x13
#define FONT_E_16R 0x19
#define FONT_E_16B 0x1A
#define FONT_E_16I 0x1B
#define FONT_E_16BI 0x1C
#define FONT_E_18R 0x22
#define FONT_E_20R 0x2B
#define FONT_E_20B 0x2C
#define FONT_E_20I 0x2D
#define FONT_E_20BI 0x2E
#define FONT_E_24R 0x35
#define FONT_E_24B 0x36
#define FONT_E_24I 0x37
#define FONT_E_24BI 0x38
#define FONT_D_24B 0x3F
#define FONT_D_29B 0x40
#define ICON_16BI 0x48
#define FONT_E_30R 0x55
#define FONT_E_40R 0x57
#define FONT_E_60R 0x5B
#define FONT_E_75R 0x5C
#define FONT_E_100R 0x5E

#endif
