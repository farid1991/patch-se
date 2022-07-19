
#ifndef W890_R1FA035
#define W890_R1FA035

#define A2
#define DB3150v1

#define GetFontDesc (FONT_DESC *)0x2A2858DC
#define GetFontCount (int *)0x2A285C4C

#define IID_IMetaData (PUUID)0x11A10370
#define CID_CMetaData (PUUID)0x119E3514
#define CID_CMusicServerManager (PUUID)0x119EEEB0
#define IID_IMusicServerManager (PUUID)0x11A17108

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

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

#define PB_REC_ICN 0xF345
#define MC_LANDSCAPE_ICN 0xEC9D
#define MC_PORTRAIT_ICN 0xECBA
#define RN_TAB_SESSION_MANAGER_SELECTED_ICN 0xF376
#define RN_TAB_SESSION_MANAGER_DESELECTED_ICN 0xF375

#define FILE_PATH (wchar_t *)0x119D06E0
#define page_MusicApplication_Main (PAGE_DESC *)0x11BB14EC

#define MEDIAPLAYER_PAUSE_ICN 0xF850
#define MEDIAPLAYER_REWIND_ICN 0xF851
#define MEDIAPLAYER_PLAY_ICN 0xF852
#define MEDIAPLAYER_FAST_FORWARD_ICN 0xF853

#define MEDIAPLAYER_MODE_RANDOM_ICN 0xECE2
#define MEDIAPLAYER_MODE_LOOP_ICN 0xECE0

#define MP_EQ_STATUS_ICN 0xED89
#define MP_EQ_BASS_ICN 0xED86
#define MP_EQ_MANUAL_ICN 0xED87
#define MP_EQ_MEGABASS_ICN 0xED88
#define MP_EQ_NORMAL_ICN 0xED89
#define MP_EQ_TREBLEBOOST_ICN 0xED8A
#define MP_EQ_VOICE_ICN 0xED8B

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

// W890 fonts
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

#define VAR_BOOK 0x120AD02D
#define VAR_STRINP_MODE 0x120AD055
#define VAR_STRINP_NEW_LINE 0x120AD04B
#define VAR_STRINP_MAX_LEN 0x120AD05F
#define VAR_STRINP_MIN_LEN 0x120AD067
#define VAR_STRINP_SET_INT_VAL 0x120AD03F
#define VAR_STRINP_FIXED_TEXT 0x120AD07B
#define VAR_OK_PROC 0x120AD01B
#define VAR_HEADER_TEXT 0x120AD095
#define VAR_YESNO_PRE_QUESTION 0x120AD047
#define VAR_YESNO_QUESTION 0x120AD07F
#define VAR_YESNO_YES_ACTION 0x120AD09B
#define VAR_YESNO_NO_ACTION 0x120AD073

#endif
