#ifndef W800_R1BD001
#define W800_R1BD001

#define A1
#define DB2010
#define OLD_PLAYER
#define MEGABASS

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
#define ACTION_BACK 0xFC1
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CONTACTS 0xFBB
#define ACTION_CONTINUE 0xFB1
#define ACTION_DELETE 0xFB4
#define ACTION_DONE 0xFB5
#define ACTION_EDIT 0xFB6
#define ACTION_EXPAND 0xFA2
#define ACTION_HELP 0xFB7
#define ACTION_INFO 0xFBA
#define ACTION_LONG_BACK 0xFAF
#define ACTION_MORE 0xFA0
#define ACTION_MORE1 0xFA1
#define ACTION_MORELIST 0xFB2
#define ACTION_NO 0xFBF
#define ACTION_NOT_EMPTY 0xFBC
#define ACTION_OK 0xFC0
#define ACTION_SAVE 0xFC2
#define ACTION_SELECT 0xFB9
#define ACTION_SELECT1 0xFC3
#define ACTION_UNCHECK 0xFC4
#define ACTION_YES 0xFC6

#define MP_ACTION_MYMUSIC 0x15
#define MP_ACTION_SKINS 0x16
#define MP_ACTION_SAVECOVER 0x17
#define MP_ACTION_EDITTAG 0x18

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x39
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x222F
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x223E

#define MM_BRW_TOPLEVEL_TITLE_TXT 0x99A
#define MP_BRW_TOPW_ICN 0xE9F2

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x442415B8
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x4428747C
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x4428744C
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x44287458
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x44287464
#define page_MM_Browser_Toplevel_Bk_Videos (PAGE_DESC *)0x44287470
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x44287494

#define FILETYPE_MP3 (wchar_t *)0x441EB54C
#define FILETYPE_mp3 (wchar_t *)0x4425E3F4

#define MIMETYPE_BMP (char *)0x441CEEEE
#define MIMETYPE_GIF (char *)0x441CED3E
#define MIMETYPE_JPG (char *)"image/jpg"
#define MIMETYPE_JPEG (char *)0x441CEDAA
#define MIMETYPE_PNG (char *)0x441CEE16

#define UNKNOWN_TXT 0xE4
#define SKINSELECT_LIST_ICN 0xE9C9
#define SKINSELECT_ARROW_ICN 0xE9E5

#define MP_BR_LISTNOWPLAYING_ICN 0xEA04
#define MP_BR_LISTARTIST_ICN 0xE9E6
#define MP_BR_LISTALBUM_ICN 0xE9EC
#define MP_BR_LISTTRACK_ICN 0xE9E9
#define MP_BR_LISTPLAYLIST_ICN 0xE9E8
#define MP_BR_LISTVIDEO_ICN 0xE9EA

#define MP_BR_LISTNOWPLAYING_TXT 0xB91
#define MP_BR_LISTARTIST_TXT 0xB5D
#define MP_BR_LISTALBUM_TXT TextID_Create("Albums", ENC_LAT1, 6)
#define MP_BR_LISTTRACK_TXT 0xBB2
#define MP_BR_LISTPLAYLIST_TXT 0xB9C
#define MP_BR_LISTVIDEO_TXT 0xBBA

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
