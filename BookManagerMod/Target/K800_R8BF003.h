#ifndef K800_R8BF003
#error K800_R8BF003 configuration needed for this header!
#else
#ifndef _K800_R8BF003_
#define _K800_R8BF003_

#define _LastExtDB			0x45B62488
#define mfree_adr()			mfree

#define RESTARTED_ACTIVITY_MENU_EVENT	0x0

#define _ASYNC_           0x0

#define Java              (char*)"Java"
#define Foreign_app       (char*)"Foreign app"
#define RSSTicker_Book    (char*)"RSSTicker_Book"
#define MainMenu          (wchar_t*)L"MainMenu"

//#define Phone (wchar_t*)
//#define Card (wchar_t*)

#define NEW_SHORTCUT_TXT  0xDB7
#define MY_SHORTCUT_TXT   0xDC7
#define SHORTCUT_TXT      0x22BA
#define DELETE_TXT        0x7A7

#define POPUP_WARNING_ICN 0xF831
#define ELFS_ITEM_ICON    0xF393
#define BOOK_ITEM_ICON    0xF3A3
#define DB_LIST_JAVA_ICN  0xF875

#define KBD_SHORT_PRESS   0x0
#define KBD_LONG_PRESS    0x1
#define KBD_REPEAT        0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE  0x4

#define KEY_CAMERA_FOCUS 0x2A
#define KEY_CAMERA_SHOT 0x2B
#define KEY_DEL 0x5
#define KEY_DIEZ 0x1E
#define KEY_DIGITAL_0 0x13
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4
//#define KEY_FLIP_CLOSE UNDEFINED
//#define KEY_FLIP_OPEN UNDEFINED
#define KEY_GAME_A 0x39 //?
#define KEY_GAME_B 0x3A //?
//#define KEY_JACKKNIFE_CLOSE UNDEFINED
//#define KEY_JACKKNIFE_OPEN UNDEFINED
#define KEY_LEFT 0xF
#define KEY_LEFT_SOFT 0x2
#define KEY_LENS_COVER_CLOSE 0x42
#define KEY_LENS_COVER_OPEN 0x41
#define KEY_MEDIAPLAYER 0x23
#define KEY_OPERATOR 0x20
#define KEY_PHF 0x36
#define KEY_PHF1 0x37
#define KEY_PHF_ENDOF 0x38
#define KEY_PLAY 0x24
#define KEY_POWER 0x1
#define KEY_RIGHT 0xB
#define KEY_RIGHT_SOFT 0x3
//#define KEY_SLIDER_CLOSE UNDEFINED
//#define KEY_SLIDER_OPEN UNDEFINED
#define KEY_STAR 0x1D
#define KEY_TASK 0x1F
#define KEY_UP 0x9
#define KEY_VOL_DOWN 0x12
#define KEY_VOL_UP 0x11

#define ACTION_BACK       0xFC0
#define ACTION_LONG_BACK  0xFAF
#define ACTION_SELECT1    0xFC2
#define ACTION_DELETE     0xFB4
#define ACTION_YES        0xFC5
#define ACTION_NO         0xFBE

#define NIL_EVENT         0
#define ACCEPT_EVENT      0x2
#define PREVIOUS_EVENT    0x3
#define CANCEL_EVENT      0x4
#define PAGE_ENTER_EVENT  0x7
#define PAGE_EXIT_EVENT   0x8

#define RETURN_TO_STANDBY_EVENT 0x848
#define TERMINATE_SESSION_EVENT 0x84A

#define CAMERA_ID             _STR("Camera album")
#define PICTURES_ID           _STR("Pictures")
#define MUSIC_ID              _STR("Music")
#define VIDEOS_ID             _STR("Videos")
#define THEMES_ID             _STR("Themes")
#define OTHER_ID              _STR("Other")

#define CAMERA_DIR_ICN        0xEa40
#define IMAGE_DIR_ICN         0xEA50
#define MUSIC_DIR_ICN         0xEA6B
#define VIDEO_DIR_ICN         0xEAA7
#define THEME_DIR_ICN         0xEA73
#define OTHER_DIR_ICN         0xEA64
#define JAVAAPPS_DIR_ICN      0xEA55
#define ELFS_DIR_ICN          0xEA6A
#define PATCHES_DIR_ICN       0xEA3C
#define RECYCLER_DIR_ICN      0xF899
#define PRIVATE_DIR_ICN       0xEC98

#define PATH_USER_INT         L"/usb"
#define PATH_USER_EXT         L"/card"
#define PATH_AUDIO_INT        L"/usb/music"
#define PATH_AUDIO_EXT        L"/card/music"
#define PATH_IMAGE_INT        L"/usb/picture"
#define PATH_IMAGE_EXT        L"/card/picture"
#define PATH_VIDEO_INT        L"/usb/video"
#define PATH_VIDEO_EXT        L"/card/video"
#define PATH_THEME_INT        L"/usb/theme"
#define PATH_THEME_EXT        L"/card/theme"
#define PATH_OTHER_INT        L"/usb/other"
#define PATH_OTHER_EXT        L"/card/other"

#define PATH_ALBUM_INT        L"/usb/DCIM"
#define PATH_ALBUM_EXT        L"/card/DCIM"

#define PATH_PATCHES_EXT      L"/card/patches"
#define PATH_RECYCLER_ROOT    L"/card/system/RECYCLER"
#define PATH_PRIVATE_ROOT     L"/card/system/private"

#define PATH_ELF_ROOT_INT     L"/usb/other/ZBin"
#define PATH_ELF_ROOT_EXT     L"/card/other/ZBin"
#define PATH_ELF_INT          L"/usb/other/ZBin"
#define PATH_ELF_EXT          L"/card/other/ZBin"
#define PATH_ELF_DAEMONS_INT  L"/usb/other/ZBin/Daemons"
#define PATH_ELF_DAEMONS_EXT  L"/card/other/ZBin/Daemons"
#define PATH_ELF_CONFIG_INT   L"/usb/other/ZBin/Config"
#define PATH_ELF_CONFIG_EXT   L"/card/other/ZBin/Config"
#define PATH_INI              L"/usb/other/ini"
#define PATH_DLL              L"/usb/other/ZBin/DLL"
#define PATH_DEFAULT          L"/usb/other"

#endif
#endif
