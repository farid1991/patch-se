#ifndef W810_R4EA031
#define W810_R4EA031

#define A1
#define DB2010

#define PGetFontDesc (FONT_DESC *)0x4C2DF9D0
#define PGetFontCount (int *)0x4C2DFB88

#define DISP_MAX_HEIGHT 196
#define STATUSROW_HEIGHT 20
#define SOFTKEYS_HEIGHT 24

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

#define FMRADIO_ACTION_LAYOUT 0x1F

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x7B2

#define TEXT_LAYOUT 0x12DE        // L"Layout"
#define TEXT_ON 0x700             // L"On"
#define TEXT_OFF 0x6FE            // L"Off"
#define TEXT_CHANGE 0x65C         // L"Change"
#define TEXT_QUESTION 0x432       // L"Save now?"
#define TEXT_SAVE 0x215           // L"Save"
#define TEXT_LEFT 0xE08           // L"Left"
#define TEXT_RIGHT 0xE09          // L"Right"
#define TEXT_CENTRE STR("Center") // L"Center"
#define TEXT_IMAGE 0x1031         // L"???????????"
#define TEXT_CANCEL 0x6BB         // L"Cancel"
#define TEXT_BACKROUND 0x12B3     // L"Background"
#define TEXT_ADDITIONAL 0xDD6     // L"Advanced"
#define TEXT_COLOR 0x12B6         // L"Colour"
#define TEXT_COLOR_TEXT 0x1303    // L"Text colour"
#define TEXT_PTYPE 0x1440         // L"Type:"
#define TEXT_COLOR_B 0x12B2       // L"Background colour"

#define TEXT_RDS 0x659
#define TEXT_NAV_LEFT 0x1225
#define TEXT_NAV_RIGHT 0x122B
#define TEXT_NAV_UP 0x122F
#define TEXT_NAV_DOWN 0x1222

#define POPUP_WARNING_ICN 0xE931

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

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_CAMERA_FOCUS 0x22
#define KEY_CAMERA_SHOT 0x23
#define KEY_DEL 0x4
#define KEY_DIEZ 0x1B
#define KEY_DIGITAL_0 0x10
#define KEY_DIGITAL_1 0x11
#define KEY_DIGITAL_2 0x12
#define KEY_DIGITAL_3 0x13
#define KEY_DIGITAL_4 0x14
#define KEY_DIGITAL_5 0x15
#define KEY_DIGITAL_6 0x16
#define KEY_DIGITAL_7 0x17
#define KEY_DIGITAL_8 0x18
#define KEY_DIGITAL_9 0x19
#define KEY_DOWN 0xA
#define KEY_ENTER 0x5
#define KEY_ESC 0x3
#define KEY_LEFT 0xC
#define KEY_LEFT_SOFT 0x1
#define KEY_LENS_COVER_CLOSE 0x32
#define KEY_LENS_COVER_OPEN 0x31
#define KEY_MEDIAPLAYER 0x1F
#define KEY_PHF 0x36
#define KEY_PHF1 0x37
#define KEY_PHF_ENDOF 0x38
#define KEY_PLAY 0x20
#define KEY_POWER 0x0
#define KEY_RIGHT 0x8
#define KEY_RIGHT_SOFT 0x2
#define KEY_STAR 0x1A
#define KEY_TASK 0x1C
#define KEY_UP 0x6
#define KEY_VOL_DOWN 0xF
#define KEY_VOL_UP 0xE

#define THEMEITEM_BACKGROUND 0x1
#define THEMEITEM_CALENDAR_WEEKVIEW_MARKINGS 0x76
#define THEMEITEM_DESKTOP 0x33
#define THEMEITEM_DESKTOP_TITLE_TEXT 0x32
#define THEMEITEM_HIGHLIGHT 0x7
#define THEMEITEM_HIGHLIGHT_TEXT 0x6
#define THEMEITEM_HOME_SCREEN 0x13
#define THEMEITEM_HOME_SCREEN_FRAME 0x24
#define THEMEITEM_HOME_SCREEN_HIGHLIGHT 0x1F
#define THEMEITEM_HOME_SCREEN_HIGHLIGHT_TEXT 0x1E
#define THEMEITEM_HOME_SCREEN_SCROLLBAR_BACKGROUND 0x23
#define THEMEITEM_HOME_SCREEN_SCROLLBAR_SLIDER 0x22
#define THEMEITEM_HOME_SCREEN_TAB 0x16
#define THEMEITEM_HOME_SCREEN_TAB_SELECTED 0x1A
#define THEMEITEM_HOME_SCREEN_TAB_TEXT 0x1C
#define THEMEITEM_HOME_SCREEN_TAB_UNSELECTED 0x18
#define THEMEITEM_HOME_SCREEN_TEXT 0x12
#define THEMEITEM_INPUT_MARKED_TEXT 0xB
#define THEMEITEM_INPUT_POPUP 0xD
#define THEMEITEM_INPUT_POPUP_FRAME 0x10
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT 0xF
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT_TEXT 0xE
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_BACKGROUND 0x9
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_SLIDER 0x8
#define THEMEITEM_INPUT_POPUP_TEXT 0xC
#define THEMEITEM_INPUT_TEXT 0xA
#define THEMEITEM_MORELIST 0x27
#define THEMEITEM_MORELIST_FRAME 0x30
#define THEMEITEM_MORELIST_HIGHLIGHT 0x2B
#define THEMEITEM_MORELIST_HIGHLIGHT_TEXT 0x2A
#define THEMEITEM_MORELIST_SCROLLBAR_BACKGROUND 0x2F
#define THEMEITEM_MORELIST_SCROLLBAR_SLIDER 0x2E
#define THEMEITEM_MORELIST_TEXT 0x26
#define THEMEITEM_POPUP 0x41
#define THEMEITEM_POPUP_DIM 0x4A
#define THEMEITEM_POPUP_FRAME 0x3A
#define THEMEITEM_POPUP_HIGHLIGHT 0x3D
#define THEMEITEM_POPUP_HIGHLIGHT_TEXT 0x3C
#define THEMEITEM_POPUP_SCROLLBAR_BACKGROUND 0x43
#define THEMEITEM_POPUP_SCROLLBAR_SLIDER 0x42
#define THEMEITEM_POPUP_TEXT 0x40
#define THEMEITEM_POPUP_TITLE_TEXT 0x46
#define THEMEITEM_PROGRESS_BAR_FILL 0x75
#define THEMEITEM_PROGRESS_BAR_OUTLINE 0x72
#define THEMEITEM_PROGRESS_BAR_SLIDER 0x74
#define THEMEITEM_SCROLLBAR_BACKGROUND 0x49
#define THEMEITEM_SCROLLBAR_SLIDER 0x48
#define THEMEITEM_SOFTKEY_LEFT 0x50
#define THEMEITEM_SOFTKEY_RIGHT 0x52
#define THEMEITEM_SOFTKEY_TEXT_LEFT 0x58
#define THEMEITEM_SOFTKEY_TEXT_LEFT_PRESSED 0x54
#define THEMEITEM_SOFTKEY_TEXT_RIGHT 0x5C
#define THEMEITEM_SOFTKEY_TEXT_RIGHT_PRESSED 0x56
#define THEMEITEM_STANDBY_OPERATORNAME_OUTLINE 0x61
#define THEMEITEM_STANDBY_OPERATORNAME_TEXT 0x60
#define THEMEITEM_STANDBY_TIME 0x62
#define THEMEITEM_STANDBY_TIME_OUTLINE 0x63
#define THEMEITEM_TAB 0x64
#define THEMEITEM_TAB_SELECTED 0x6A
#define THEMEITEM_TAB_TEXT 0x66
#define THEMEITEM_TAB_UNSELECTED 0x68
#define THEMEITEM_TEXT 0x4
#define THEMEITEM_TITLE_TEXT 0x6E
#define THEMEITEM_VOLUME_STAPLES 0x70
#define THEMEITEM_WAPBROWSER_TABLEBORDER 0x2
#define THEMEITEM_WAPBROWSER_UNDERLINE 0x0

#endif
