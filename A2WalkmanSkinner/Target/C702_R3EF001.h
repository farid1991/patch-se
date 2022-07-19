#ifndef C702_R3EF001
#define C702_R3EF001

#define A2
#define DB3150v2

#define GetFontDesc (FONT_DESC *)0x2AFA1B04
#define GetFontCount (int *)0x2AFA1E74

#define page_MusicApplication_Main (PAGE_DESC *)0x11C171B4
#define FILE_PATH (wchar_t *)0x11E4D64C

#define CID_CUIImageManager (PUUID)0x11E7EDB0
#define IID_IUIImageManager (PUUID)0x11EA8BB8
#define CID_CMetaData (PUUID)0x11E631DC
#define IID_IMetaData (PUUID)0x11E97394

#define TEXT_MINUTES 0x956
#define TEXT_SECONDS 0x966

#define TEXT_RINGTONE 0x728
#define TEXT_MESSAGEALERT 0x762
#define TEXT_ALARMSIGNAL 0x75B
#define TEXT_CONTACTSIGNAL 0x66B
#define TEXT_RING_CHANGED 0x726
#define TEXT_MESSAGE_CHANGED 0x6CD

#define TEXT_FONT_SIZE 0x17D0
#define TEXT_OK 0x8E3
#define TEXT_COLOR 0x23AA

#define TEXT_USE 0x26C
#define TEXT_USE_NOW 0x112
#define TEXT_EDIT 0x172

#define TEXT_ON 0x32C
#define TEXT_OFF 0x32B

#define TEXT_SKINS STR(TXT_SKINS)
#define TEXT_VIZ 0x164F
#define TEXT_GO_TO 0xC48
#define TEXT_TIMER 0x395
#define TEXT_SHORTCUT 0x22CE
#define TEXT_LYRIC STR(TXT_LYRIC)
#define TEXT_USE_AS 0x799
#define TEXT_EDIT_TAG STR(TXT_EDIT_TAG)

#define TEXT_YES 0x63
#define TEXT_NO 0x61
#define TEXT_ENABLE 0x869
#define TEXT_DISABLE 0x867
#define TEXT_ENABLED 0xA84
#define TEXT_DISABLED 0xA82
#define TEXT_SAVE 0x121

#define TEXT_CHANGES_MADE 0x21E
#define TEXT_SAVE_BEFORE_EXIT 0x21F

#define TEXT_ALIGN 0x23FE
#define TEXT_LEFT 0x17E8
#define TEXT_RIGHT 0x17E9

#define TEXT_PORTRAIT 0x313
#define TEXT_LANDSCAPE 0x311

#define TEXT_POSITION 0x11AF

#define TEXT_TITLE STR(TXT_TITLE)
#define TEXT_ARTIST 0x154B
#define TEXT_ALBUM 0x1542
#define TEXT_GENRE 0x1596
#define TEXT_ALBUM_ART 0x164C

#define TEXT_FULLSCREEN 0x5A5
#define TEXT_TEXT_COLOR 0x23FA
#define TEXT_BACKGROUND_COLOR 0x23A6

#define TEXT_EQUALIZER 0x157C
#define TEXT_MANUAL 0x15A4
#define TEXT_PRESET 0x15E6
#define TEXT_SELECT 0x251D

#define PB_REC_ICN 0xF34B
#define MC_LANDSCAPE_ICN 0xECB8
#define MC_PORTRAIT_ICN 0xECD0
#define RN_TAB_SESSION_MANAGER_SELECTED_ICN 0xF384
#define RN_TAB_SESSION_MANAGER_DESELECTED_ICN 0xF383

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x40E7

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

#define KEY_CAMERA_FOCUS 0x2F
#define KEY_CAMERA_SHOT 0x30
#define KEY_DEL 0x5
#define KEY_DIEZ 0x23
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
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4
#define KEY_FLIP_CLOSE 0x4A
#define KEY_FLIP_OPEN 0x49
#define KEY_GAME_A 0x47
#define KEY_GAME_B 0x48
#define KEY_JACKKNIFE_CLOSE 0x4C
#define KEY_JACKKNIFE_OPEN 0x4B
#define KEY_LEFT 0xF
#define KEY_LEFT_SOFT 0x2
#define KEY_LENS_COVER_CLOSE 0x50
#define KEY_LENS_COVER_OPEN 0x4F
#define KEY_MEDIAPLAYER 0x28
#define KEY_OPERATOR 0x25
#define KEY_PHF 0x52
#define KEY_PHF1 0x53
#define KEY_PHF_ENDOF 0x54
#define KEY_POWER 0x1
#define KEY_RIGHT 0xB
#define KEY_RIGHT_SOFT 0x3
#define KEY_SLIDER_CLOSE 0x4E
#define KEY_SLIDER_OPEN 0x4D
#define KEY_STAR 0x22
#define KEY_TASK 0x24
#define KEY_UP 0x9
#define KEY_VOL_DOWN 0x17
#define KEY_VOL_UP 0x16

#define FONT_D_24B 0x3F
#define FONT_D_29B 0x40
#define FONT_D_7R 0x1
#define FONT_E_100R 0x5E
#define FONT_E_12B 0xE
#define FONT_E_12R 0xD
#define FONT_E_14B 0x13
#define FONT_E_14R 0x12
#define FONT_E_16B 0x1A
#define FONT_E_16BI 0x1C
#define FONT_E_16I 0x1B
#define FONT_E_16R 0x19
#define FONT_E_18R 0x22
#define FONT_E_20B 0x2C
#define FONT_E_20BI 0x2E
#define FONT_E_20I 0x2D
#define FONT_E_20R 0x2B
#define FONT_E_24B 0x36
#define FONT_E_24BI 0x38
#define FONT_E_24I 0x37
#define FONT_E_24R 0x35
#define FONT_E_30R 0x55
#define FONT_E_40R 0x57
#define FONT_E_60R 0x5B
#define FONT_E_75R 0x5C
#define FONT_E_8R 0x2

#endif
