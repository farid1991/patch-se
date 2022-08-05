#ifndef W910_R1FA037
#define W910_R1FA037

#define A2
#define DB3150v1

#define DISP_MAX_HEIGHT 266
#define STATUSROW_HEIGHT 24
#define SOFTKEYS_HEIGHT 30

#define PGetFontDesc (FONT_DESC *)0x2A27E8B0
#define PGetFontCount (int *)0x2A27EC20

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
#define PAGE_ENTER_EVENT 0xE
#define PAGE_EXIT_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x841

#define KBD_SHORT_PRESS 0x0
#define KBD_LONG_PRESS 0x1
#define KBD_REPEAT 0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE 0x4

#define KEY_ESC 0x4
#define KEY_DEL 0x5
#define KEY_ENTER 0x8
#define KEY_UP 0x9
#define KEY_RIGHT 0xB
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_VOL_UP 0x11
#define KEY_VOL_DOWN 0x12
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
#define KEY_STAR 0x1D
#define KEY_DIEZ 0x1E

#define TEXT_LAYOUT 0x962         // L"layout"
#define TEXT_ON 0x1E1             // L"On"
#define TEXT_OFF 0x1DF            // L"Off"
#define TEXT_CHANGE 0xD4C         // L"Change"
#define TEXT_QUESTION 0x723       // L"Save now?"
#define TEXT_SAVE 0x121           // L"Save"
#define TEXT_LEFT 0x17D3         // L"Left"
#define TEXT_RIGHT 0x17D4         // L"Right"
#define TEXT_CENTRE STR("Center") // L"Center"
#define TEXT_IMAGE 0x1021         // L"???????????"
#define TEXT_CANCEL 0x855         // L"Cancel"
#define TEXT_BACKROUND 0x2E4F     // L"Background"
#define TEXT_ADDITIONAL 0x12E     // L"Advanced"
#define TEXT_COLOR 0x23AA         // L"Colour"
#define TEXT_COLOR_TEXT 0x23D9    // L"Text colour"
#define TEXT_PTYPE 0x2ED6         // L"Type:"
#define TEXT_COLOR_B 0x2385       // L"Background colour"

#define TEXT_RDS 0xB97
#define TEXT_NAV_LEFT 0x22B0
#define TEXT_NAV_RIGHT 0x22B8
#define TEXT_NAV_UP 0x22BC
#define TEXT_NAV_DOWN 0x22AC

#define POPUP_WARNING_ICN 0xF831

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
#define FONT_E_30R 0x55
#define FONT_E_40R 0x57
#define FONT_E_60R 0x5B
#define FONT_E_75R 0x5C
#define FONT_E_100R 0x5E
#define FONT_ICON_16BI 0x48

#endif
