#ifndef W710_R1JC002
#define W710_R1JC002

#define A1
#define DB2020
#define MEGABASS
#define ENABLE_VISUALIZER

#define STATUSBAR_H 20
#define SOFTKEYS_H 24

#define SKIN_CFG_NAME L"skin.cfg"
#define SKIN_CFG_PATH L"/tpa/user/other/WALKMAN"
#define SKIN_PATH L"/tpa/user/other/WALKMAN/skins"
#define SKIN_NAME L"walkman.ini"
#define DEFAULT_SKIN_PATH L"/tpa/user/other/WALKMAN/skins/WALKMAN"

#define ZBIN_PATH L"/tpa/user/other/ZBin"

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

#define FONT_D_24B 0x3F
#define FONT_D_29B 0x40
#define FONT_D_7R 0x1
#define FONT_E_100R 0x5E
#define FONT_E_12B 0xD
#define FONT_E_12R 0xC
#define FONT_E_14B 0x12
#define FONT_E_14R 0x11
#define FONT_E_16B 0x19
#define FONT_E_16BI 0x1B
#define FONT_E_16I 0x1A
#define FONT_E_16R 0x18
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
#define FONT_ICON_16BIT_V2 0x48

#define THEMEITEM_BACKGROUND 0x1

#define NIL_EVENT 0x0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0x7
#define PAGE_EXIT_EVENT 0x8
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x46
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x319D
#define MM_BRW_TOPLEVEL_EVENT 0x31A1
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x31AD

#define MP_ACTION_SETTINGS 0x14
#define MP_ACTION_FILE 0x15
#define MP_ACTION_MYMUSIC 0x16
#define MP_ACTION_SKINS 0x17
#define MP_ACTION_SAVECOVER 0x18
#define MP_ACTION_EDITTAG 0x19

#define MP_ACTION_SHORTCUT 0x18
#define MP_ACTION_LYRIC 0x19
#define MP_ACTION_USE_AS 0x1A

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x4599A964
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x45A27A80
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x45A27A5C
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x45A27A68
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x45A27A74
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x45A27B90

#define MEDIAPLAYER_VIDEO (wchar_t *)0x45A72268

#define FILETYPE_MP3 (wchar_t *)0x45965FB4
#define FILETYPE_mp3 (wchar_t *)0x4592BAAC

#define MIMETYPE_BMP (char *)0x4557D00C
#define MIMETYPE_GIF (char *)0x4557C8F0
#define MIMETYPE_JPG (char *)0x4563DD74
#define MIMETYPE_JPEG (char *)0x455EA0CC
#define MIMETYPE_PNG (char *)0x4557C914

#define MM_BRW_TOPLEVEL_TITLE_TXT 0xAA2
#define MP_BRW_TOPW_ICN 0xECAE

#define UNKNOWN_TXT 0x10BD
#define SKINSELECT_LIST_ICN 0xECA2
#define SKINSELECT_ARROW_ICN 0xECA0

#define MP_BR_LISTNOWPLAYING_ICN 0xECA3
#define MP_BR_LISTARTIST_ICN 0xECA1
#define MP_BR_LISTALBUM_ICN 0xECA8
#define MP_BR_LISTTRACK_ICN 0xECA5
#define MP_BR_LISTPLAYLIST_ICN 0xECA7
#define MP_BR_LISTVIDEO_ICN 0xECA6

#define MP_BR_LISTNOWPLAYING_TXT 0x108B
#define MP_BR_LISTARTIST_TXT 0x103F
#define MP_BR_LISTALBUM_TXT 0x103A
#define MP_BR_LISTTRACK_TXT 0x10BA
#define MP_BR_LISTPLAYLIST_TXT 0x1099
#define MP_BR_LISTVIDEO_TXT 0x10D2

#endif
