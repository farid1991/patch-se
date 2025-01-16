#ifndef K800_R8BF003
#define K800_R8BF003

#define A1
#define DB2020

#define STATUSBAR_H 24
#define SOFTKEYS_H 30

#define SKIN_CFG_NAME L"skin.cfg"
#define SKIN_CFG_PATH L"/usb/other/WALKMAN"
#define SKIN_PATH L"/usb/other/WALKMAN/skins"
#define SKIN_NAME L"walkman.ini"
#define DEFAULT_SKIN_PATH L"/usb/other/WALKMAN/skins/Default"

#define ZBIN_PATH L"/usb/other/ZBin"

#define FILETYPE_MP3 (wchar_t *)0x45C835D8
#define FILETYPE_mp3 (wchar_t *)0x45C1F9FC

#define MIMETYPE_BMP (char *)0x45C1C590
#define MIMETYPE_GIF (char *)0x45C1C59C
#define MIMETYPE_JPG (char *)0x45C1C5B4
#define MIMETYPE_JPEG (char *)0x45C1C5C0
#define MIMETYPE_PNG (char *)0x45C1C5A8

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x45B834DC
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x45C21444
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x45C21420
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x45C2142C
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x45C21438
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x45C2154C

#define MEDIAPLAYER_VIDEO (wchar_t *)0x45C6CCB0

#define THEMEITEM_BACKGROUND 0x1

#define MP_ACTION_SETTINGS 0x14
#define MP_ACTION_FILE 0x15
#define MP_ACTION_MYMUSIC 0x16
#define MP_ACTION_SKINS 0x17
#define MP_ACTION_SAVECOVER 0x18
#define MP_ACTION_EDITTAG 0x19

#define MP_ACTION_SHORTCUT 0x18
#define MP_ACTION_LYRIC 0x19
#define MP_ACTION_USE_AS 0x1A

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 7
#define PAGE_EXIT_EVENT 8
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x47
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x319D
#define MM_BRW_TOPLEVEL_EVENT 0x31A1
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x31AD

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

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

#define SKINSELECT_LIST_ICN 0xEA26
#define SKINSELECT_ARROW_ICN 0xEB32

#define UNKNOWN_ARTIST 0x10C1
#define UNKNOWN_ALBUM 0x10C0
#define UNKNOWN_TXT 0x10C2

#define MP_BRW_TOPW_ICN 0xECD2

#define MP_BR_LISTNOWPLAYING_ICN 0xECC7
#define MP_BR_LISTARTIST_ICN 0xECCD
#define MP_BR_LISTALBUM_ICN 0xECCC
#define MP_BR_LISTTRACK_ICN 0xECC9
#define MP_BR_LISTPLAYLIST_ICN 0xECC8
#define MP_BR_LISTVIDEO_ICN 0xECCA

#define MP_BR_LISTNOWPLAYING_TXT 0x108C
#define MP_BR_LISTARTIST_TXT 0x103A
#define MP_BR_LISTALBUM_TXT 0x1035
#define MP_BR_LISTTRACK_TXT 0x10BE
#define MP_BR_LISTPLAYLIST_TXT 0x109C
#define MP_BR_LISTVIDEO_TXT 0x1A1E

#endif
