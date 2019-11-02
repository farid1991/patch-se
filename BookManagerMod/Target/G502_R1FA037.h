#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define _LastExtDB			0x11A364D8
#define mfree_adr()			mfree

#define RESTARTED_ACTIVITY_MENU_EVENT	0x1B5B

#define Java              (char*)"Java"
#define Foreign_app       (char*)0x11B71B98    //"Foreign app"
#define RSSTicker_Book    (char*)0x11A741D0    //"RSSTicker_Book"
#define MainMenu          (wchar_t*)0x11B66028 //L"MainMenu"

//#define Phone (wchar_t*)
//#define Card (wchar_t*)

#define NEW_SHORTCUT_TXT  0xDB7
#define MY_SHORTCUT_TXT   0xDC7
#define SHORTCUT_TXT      0x22BA
#define DELETE_TXT        0x7A7
#define EMPTY_LIST_TXT    0x1544 // L"No shortcuts"

#define POPUP_WARNING_ICN 0xF831
#define ELFS_ITEM_ICON    0xF393
#define BOOK_ITEM_ICON    0xF3A3
#define DB_LIST_JAVA_ICN  0xF875

#define KBD_LONG_PRESS    0x1
#define KBD_LONG_RELEASE  0x4
#define KBD_REPEAT        0x2
#define KBD_SHORT_PRESS   0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DIEZ      0x1E
#define KEY_STAR      0x1D
#define KEY_ESC       0x4
#define KEY_UP        0x9
#define KEY_DOWN      0xD
#define KEY_LEFT      0xF
#define KEY_RIGHT     0xB
#define KEY_ENTER     0x8
#define KEY_DIGITAL_0 0x13

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
#define PAGE_ENTER_EVENT  0xE
#define PAGE_EXIT_EVENT   0xF

#define RETURN_TO_STANDBY_EVENT 0x841
#define TERMINATE_SESSION_EVENT 0x843

#define CAMERA_ID             _STR("Camera album")
#define PICTURES_ID           _STR("Pictures")
#define MUSIC_ID              _STR("Music")
#define VIDEOS_ID             _STR("Videos")
#define THEMES_ID             _STR("Themes")
#define OTHER_ID              _STR("Other")

#define CAMERA_DIR_ICN      0xEa40
#define IMAGE_DIR_ICN       0xEA50
#define MUSIC_DIR_ICN       0xEA6B
#define VIDEO_DIR_ICN       0xEAA7
#define THEME_DIR_ICN       0xEA73
#define OTHER_DIR_ICN       0xEA64
#define JAVAAPPS_DIR_ICN    0xEA55
#define ELFS_DIR_ICN        0xEA6A
#define PATCHES_DIR_ICN     0xEA3C
#define RECYCLER_DIR_ICN    0xF899
#define PRIVATE_DIR_ICN     0xEC98

#define PATH_USER_INT         (wchar_t*)0x11989868 // L"/usb"
#define PATH_USER_EXT         (wchar_t*)0x1005C938 // L"/card"
#define PATH_AUDIO_INT        (wchar_t*)0x11989874 // L"/usb/music"
#define PATH_AUDIO_EXT        (wchar_t*)0x11986AF4 // L"/card/music"
#define PATH_IMAGE_INT        (wchar_t*)0x11B36B5C // L"/usb/picture"
#define PATH_IMAGE_EXT        (wchar_t*)0x11986B60 // L"/card/picture"
#define PATH_VIDEO_INT        (wchar_t*)0x11989B38 // L"/usb/video"
#define PATH_VIDEO_EXT        (wchar_t*)0x11986BD8 // L"/card/video"
#define PATH_THEME_INT        (wchar_t*)0x11B36AC4 // L"/usb/theme"
#define PATH_THEME_EXT        (wchar_t*)0x11986BC0 // L"/card/theme"
#define PATH_OTHER_INT        (wchar_t*)0x11B36AAC // L"/usb/other"
#define PATH_OTHER_EXT        (wchar_t*)0x11986BA8 // L"/card/other"

#define PATH_ALBUM_INT        (wchar_t*)0x11B36B48 // L"/usb/DCIM"
#define PATH_ALBUM_EXT        (wchar_t*)0x119869F0 // L"/card/DCIM"

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

// Menu
#define TITLE_TXT           0x2CB0 // L"Goto"
#define MENU_ADD_TXT        0x22B3 // L"New shortcut"
#define MENU_MODIFY_TXT     0x22AE // L"Edit shortcut"
#define EMPTY_LIST_TXT      0x1544 // L"No shortcuts"
#define MENU_ABOUT_TXT      0x19ED // L"About"
  
// Editing
#define EDITOR_TITLE_TXT    0x22AE // L"Editor"
#define EDITOR_LABEL_TXT    0x1EC8 // L"Name"
#define EDITOR_SHORTCUT_TXT 0x22AD // L"Shortcut"
#define TYPES_TITLE_TXT     0x2B21 // L"Type"

#define SHC_SET_MM          0x22B9
#define SHC_SET_SHORTCUT_SK 0x22BA
#define DELETEQ_TXT         0x2727

#define OPEN_TXT            0x6ED
#define SELECT_TXT          0x96C

#define JAVA_APP_TXT        0x69C
#define EVENT_TXT           0x1BA5
#define FOLDER_TXT          0x16DA
#define SELECT_FOLDER_TXT   0x1820

#define HPB_OTHER_ICN       0xEBE6
#define MENU_SETTINGS_ICN   0xEB25
#define ANIMALS_MOUSE_ICN   0xE5BE

#define SHORTCUT_LIST_ICN   0xF37A
#define ENTERTAINMENT_ICN   0xF379
#define DB_LIST_JAVA_ICN    0xF875
#define GUI_UNAVAILABLE_ICN 0xF8A6
#define DB_LIST_FOLDER_ICN  0xF377

#endif
#endif
