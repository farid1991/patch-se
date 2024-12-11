#ifndef W810_R4EA031
#define W810_R4EA031

#define A1
#define DB2010
#define MEGABASS
#define ENABLE_VISUALIZER

#define STATUSBAR_H 20
#define SOFTKEYS_H 24

#define SKIN_CFG_NAME L"skin.cfg"
#define SKIN_CFG_PATH L"/usb/other/WALKMAN"
#define SKIN_PATH L"/usb/other/WALKMAN/skins"
#define SKIN_NAME L"walkman.ini"
#define DEFAULT_SKIN_PATH L"/usb/other/WALKMAN/skins/WALKMAN"

#define ZBIN_PATH L"/usb/other/ZBin"

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

#define MP_ACTION_MYMUSIC 0x14
#define MP_ACTION_SKINS 0x15
#define MP_ACTION_SAVECOVER 0x16
#define MP_ACTION_EDITTAG 0x17

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x3B
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x2329
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x2338

#define MM_BRW_TOPLEVEL_TITLE_TXT 0xAA2
#define MP_BRW_TOPW_ICN 0xE865

#define FILETYPE_MP3 (wchar_t *)0x4450273C
#define FILETYPE_mp3 (wchar_t *)0x444BB4A8

#define MIMETYPE_BMP (char *)0x44409BCE
#define MIMETYPE_GIF (char *)0x44409A1E
#define MIMETYPE_JPG (char *)"image/jpg"
#define MIMETYPE_JPEG (char *)0x44440978
#define MIMETYPE_PNG (char *)0x44409AF6

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x44501424
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x44548534
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x44548504
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x44548510
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x4454851C
#define page_MM_Browser_Toplevel_Bk_Videos (PAGE_DESC *)0x44548528
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x44548674

#define UNKNOWN_TXT 0xE4
#define SKINSELECT_LIST_ICN 0xE961
#define SKINSELECT_ARROW_ICN 0xE857

#define MP_BR_LISTNOWPLAYING_ICN 0xE85A
#define MP_BR_LISTARTIST_ICN 0xE858
#define MP_BR_LISTALBUM_ICN 0xE85F
#define MP_BR_LISTTRACK_ICN 0xE85C
#define MP_BR_LISTPLAYLIST_ICN 0xE85B
#define MP_BR_LISTVIDEO_ICN 0xE85D

#define MP_BR_LISTNOWPLAYING_TXT 0xCC2
#define MP_BR_LISTARTIST_TXT 0xC8C
#define MP_BR_LISTALBUM_TXT TextID_Create("Albums", ENC_LAT1, 6)
#define MP_BR_LISTTRACK_TXT 0xCE5
#define MP_BR_LISTPLAYLIST_TXT 0xCCD
#define MP_BR_LISTVIDEO_TXT 0xCEE

#define FONT_D_18B 0x2D
#define FONT_D_24B 0x2F
#define FONT_D_29B 0x30
#define FONT_E_14B 0x11
#define FONT_E_14BI 0x13
#define FONT_E_14I 0x12
#define FONT_E_14R 0x10
#define FONT_E_16B 0x18
#define FONT_E_16BI 0x1A
#define FONT_E_16I 0x19
#define FONT_E_16R 0x17
#define FONT_E_20B 0x25
#define FONT_E_20BI 0x27
#define FONT_E_20I 0x26
#define FONT_E_20R 0x24
#define FONT_ICON_16BIT_V2 0x38

#define THEMEITEM_BACKGROUND 0x1

#endif
