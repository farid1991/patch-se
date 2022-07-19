#ifndef W508_R1FA035
#define W508_R1FA035

#define A2
#define DB3200

#define CID_CMetaData (PUUID)0x159D5350
#define IID_IMetaData (PUUID)0x15A193A0
#define CID_CUIImageManager (PUUID)0x159FB308
#define IID_IUIImageManager (PUUID)0x15A33748
#define CID_CUIFontManager (PUUID)0x159F8668
#define IID_IUIFontManager (PUUID)0x15A3138C
#define CID_CTextRenderingManager (PUUID)0x159FFDFC
#define IID_ITextRenderingManager (PUUID)0x15A362B4

#define TEXT_MINUTES 0x77D
#define TEXT_SECONDS 0x787

#define TEXT_RINGTONE 0x161C
#define TEXT_MESSAGEALERT 0x687
#define TEXT_ALARMSIGNAL 0x680
#define TEXT_CONTACTSIGNAL 0x5A4
#define TEXT_RING_CHANGED 0x64E
#define TEXT_MESSAGE_CHANGED 0x5FC

#define TEXT_FONT_SIZE 0x1542
#define TEXT_OK 0xA80
#define TEXT_COLOR 0x1D17

#define TEXT_USE 0x257
#define TEXT_USE_NOW 0x10C
#define TEXT_EDIT 0x189

#define TEXT_ON 0x19D1
#define TEXT_OFF 0x18D8

#define TEXT_SKINS STR(TXT_SKINS)
#define TEXT_VIZ 0x13EF
#define TEXT_GO_TO 0xC48
#define TEXT_TIMER 0x34A
#define TEXT_SHORTCUT 0x192D
#define TEXT_LYRIC STR(TXT_LYRIC)
#define TEXT_USE_AS 0x6B8
#define TEXT_EDIT_TAG STR(TXT_EDIT_TAG)

#define TEXT_YES 0x59
#define TEXT_NO 0x58
#define TEXT_ENABLE 0x869
#define TEXT_DISABLE 0x867
#define TEXT_ENABLED 0x869
#define TEXT_DISABLED 0x867
#define TEXT_SAVE 0x120

#define TEXT_CHANGES_MADE 0x218
#define TEXT_SAVE_BEFORE_EXIT 0x219

#define TEXT_ALIGN 0x1D67
#define TEXT_LEFT 0x1557
#define TEXT_RIGHT 0x1558

#define TEXT_PORTRAIT 0x2DB
#define TEXT_LANDSCAPE 0x2D9

#define TEXT_POSITION 0x105A

#define TEXT_TITLE STR(TXT_TITLE)
#define TEXT_ARTIST 0x743
#define TEXT_ALBUM 0x740
#define TEXT_GENRE 0x745
#define TEXT_ALBUM_ART 0x13EE

#define TEXT_FULLSCREEN 0x4ED
#define TEXT_TEXT_COLOR 0x1D63
#define TEXT_BACKGROUND_COLOR 0x1D13

#define TEXT_EQUALIZER 0x1359
#define TEXT_MANUAL 0x1378
#define TEXT_PRESET 0x13A0
#define TEXT_SELECT 0x23F9

#define PB_REC_ICN 0x7F2
#define MC_LANDSCAPE_ICN 0x4A9
#define MC_PORTRAIT_ICN 0x4C4
#define RN_TAB_SESSION_MANAGER_SELECTED_ICN 0x838
#define RN_TAB_SESSION_MANAGER_DESELECTED_ICN 0x837

#define LAST_ACTION_MP 0x12
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

#define page_MusicApplication_Main (PAGE_DESC *)0x1593F8F4
#define FILE_PATH (wchar_t *)0x159BD090

#define MEDIAPLAYER_PAUSE_ICN 0xF850
#define MEDIAPLAYER_REWIND_ICN 0xF851
#define MEDIAPLAYER_PLAY_ICN 0xF852
#define MEDIAPLAYER_FAST_FORWARD_ICN 0xF853
#define MP_EQ_STATUS_ICN 0x0087
#define MEDIAPLAYER_MODE_RANDOM_ICN 0x04F4
#define MEDIAPLAYER_MODE_LOOP_ICN 0x04F2

#define MP_EQ_BASS_ICN 0x0596
#define MP_EQ_MANUAL_ICN 0x0598
#define MP_EQ_MEGABASS_ICN 0x0599
#define MP_EQ_NORMAL_ICN 0x059A
#define MP_EQ_TREBLEBOOST_ICN 0x059C
#define MP_EQ_VOICE_ICN 0x059D

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
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x40E8

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_LEFT_SOFT 0x2
#define KEY_ESC 0x4
#define KEY_DEL 0x5
#define KEY_ENTER 0x8
#define KEY_UP 0x9
#define KEY_RIGHT 0xB
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF

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

#define FONT_D_18B 0x112
#define FONT_D_24B 0x118
#define FONT_D_29B 0x11D
#define FONT_D_7R 0x7
#define FONT_E_100R 0x64
#define FONT_E_12B 0x10C
#define FONT_E_12R 0xC
#define FONT_E_14B 0x10E
#define FONT_E_14BI 0x30E
#define FONT_E_14I 0x20E
#define FONT_E_14R 0xE
#define FONT_E_16B 0x110
#define FONT_E_16BI 0x310
#define FONT_E_16I 0x210
#define FONT_E_16R 0x10
#define FONT_E_18B 0x112
#define FONT_E_18BI 0x312
#define FONT_E_18I 0x212
#define FONT_E_18R 0x12
#define FONT_E_20B 0x114
#define FONT_E_20BI 0x314
#define FONT_E_20I 0x214
#define FONT_E_20R 0x14
#define FONT_E_22B 0x116
#define FONT_E_22BI 0x316
#define FONT_E_22I 0x216
#define FONT_E_22R 0x16
#define FONT_E_24B 0x118
#define FONT_E_24BI 0x318
#define FONT_E_24I 0x218
#define FONT_E_24R 0x18
#define FONT_E_25B 0x119
#define FONT_E_25BI 0x319
#define FONT_E_25I 0x219
#define FONT_E_25R 0x19
#define FONT_E_30R 0x1E
#define FONT_E_36R 0x24
#define FONT_E_40R 0x28
#define FONT_E_60R 0x3C
#define FONT_E_75R 0x49
#define FONT_E_8R 0x8

#endif
