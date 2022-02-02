#ifndef W980_R3EG004
#define W980_R3EG004

#define A2
#define DB3150v2

#define DISP_MAX_HEIGHT 266
#define STATUSROW_HEIGHT 24
#define SOFTKEYS_HEIGHT 30

#define PGetFontDesc (FONT_DESC *)0x4BB9D07C
#define PGetFontCount (int *)0x4BB9D3EC
#define CID_CUIImageManager (PUUID)0x11DE4690
#define IID_IUIImageManager (PUUID)0x11E0E968

#define ACTION_ACCEPT 0xFAC
#define ACTION_LONG_BACK 0xFAF
#define ACTION_DELETE 0xFB4
#define ACTION_NO 0xFBE
#define ACTION_BACK 0xFC0
#define ACTION_SELECT1 0xFC2
#define ACTION_YES 0xFC5

#define FMRADIO_ACTION_LAYOUT 0x1F

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840

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

#define TEXT_LAYOUT 0x972         // L"layout"
#define TEXT_ON 0x1E6             // L"On"
#define TEXT_OFF 0x1E3            // L"Off"
#define TEXT_CHANGE 0xD5C         // L"Change"
#define TEXT_QUESTION 0x72E       // L"Save now?"
#define TEXT_SAVE 0x121           // L"Save"
#define TEXT_LEFT 0x17E8          // L"Left"
#define TEXT_RIGHT 0x17E9         // L"Right"
#define TEXT_CENTRE STR("Center") // L"Center"
#define TEXT_IMAGE 0x1031         // L"???????????"
#define TEXT_CANCEL 0x860         // L"Cancel"
#define TEXT_BACKROUND 0x2E72     // L"Background"
#define TEXT_ADDITIONAL 0x12E     // L"Advanced"
#define TEXT_COLOR 0x23AA         // L"Colour"
#define TEXT_COLOR_TEXT 0x23FA    // L"Text colour"
#define TEXT_PTYPE 0x2B45         // L"Type:"
#define TEXT_COLOR_B 0x23A6       // L"Background colour"

#define TEXT_RDS 0xBA7
#define TEXT_NAV_LEFT 0x22D1
#define TEXT_NAV_RIGHT 0x22D9
#define TEXT_NAV_UP 0x22DD
#define TEXT_NAV_DOWN 0x22CD

#define POPUP_WARNING_ICN 0xF831

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
#define FONT_ICON_16BIT_V2 0x48

#endif
