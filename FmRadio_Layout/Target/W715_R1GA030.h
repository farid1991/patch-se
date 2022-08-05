#ifndef W715_R1GA030
#define W715_R1GA030

#define A2
#define DB3210

#define DISP_MAX_HEIGHT 266
#define STATUSROW_HEIGHT 24
#define SOFTKEYS_HEIGHT 30

#define CID_CUIFontManager (PUUID)0x15B36F08
#define IID_IUIFontManager (PUUID)0x15B70DC0
#define CID_CTextRenderingManager (PUUID)0x15B3E674
#define IID_ITextRenderingManager (PUUID)0x15B75CD0
#define CID_CUIImageManager (PUUID)0x15B39BCC
#define IID_IUIImageManager (PUUID)0x15B7317C

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

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DIEZ 0x23
#define KEY_STAR 0x22
#define KEY_ESC 0x4
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB
#define KEY_ENTER 0x8
#define KEY_DIGITAL_0 0x18
#define KEY_DIGITAL_1 0x19
#define KEY_DIGITAL_2 0x1A
#define KEY_DIGITAL_3 0x1B
#define KEY_DIGITAL_4 0x1C
#define KEY_DIGITAL_5 0x1D
#define KEY_DIGITAL_6 0x1E
#define KEY_DIGITAL_7 0x1F
#define KEY_DIGITAL_8 0x20
#define KEY_DIGITAL_9 0x21
#define KEY_DEL 0x5

#define FONT_D_18B 0x112
#define FONT_D_24B 0x118
#define FONT_D_29B 0x11D
#define FONT_D_7R 0x7
#define FONT_E_100R 0x64
#define FONT_E_12B 0x10C
#define FONT_E_12R 0xC
#define FONT_E_14B 0x10E
#define FONT_E_14BI 0x30E
#define FONT_E_14I 0x20E
#define FONT_E_14R 0xE
#define FONT_E_16B 0x110
#define FONT_E_16BI 0x310
#define FONT_E_16I 0x210
#define FONT_E_16R 0x10
#define FONT_E_18B 0x112
#define FONT_E_18BI 0x312
#define FONT_E_18I 0x212
#define FONT_E_18R 0x12
#define FONT_E_20B 0x114
#define FONT_E_20BI 0x314
#define FONT_E_20I 0x214
#define FONT_E_20R 0x14
#define FONT_E_22B 0x116
#define FONT_E_22BI 0x316
#define FONT_E_22I 0x216
#define FONT_E_22R 0x16
#define FONT_E_24B 0x118
#define FONT_E_24BI 0x318
#define FONT_E_24I 0x218
#define FONT_E_24R 0x18
#define FONT_E_25B 0x119
#define FONT_E_25BI 0x319
#define FONT_E_25I 0x219
#define FONT_E_25R 0x19
#define FONT_E_30R 0x1E
#define FONT_E_36R 0x24
#define FONT_E_40R 0x28
#define FONT_E_60R 0x3C
#define FONT_E_75R 0x49
#define FONT_E_8R 0x8

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840

#define FMRADIO_ACTION_LAYOUT 0x11

#define POPUP_WARNING_ICN 0xF831

#define TEXT_LAYOUT 0x78E         // L"Layout"
#define TEXT_ON 0x1E8             // L"On"
#define TEXT_OFF 0x1E5            // L"Off"
#define TEXT_CHANGE 0xC0E         // L"Change"
#define TEXT_QUESTION 0x656       // L"Save now?"
#define TEXT_SAVE 0x657           // L"Save"
#define TEXT_LEFT 0x1557          // L"Left"
#define TEXT_RIGHT 0x1558         // L"Right"
#define TEXT_CENTRE STR("Center") // L"Center"
#define TEXT_IMAGE 0x1D34         // L"???????????"
#define TEXT_CANCEL 0x7BB         // L"Cancel"
#define TEXT_BACKROUND 0x24E0     // L"Background"
#define TEXT_ADDITIONAL 0xD04     // L"Advanced"
#define TEXT_COLOR 0x1D17         // L"Colour"
#define TEXT_COLOR_TEXT 0x1D63    // L"Text colour"
#define TEXT_PTYPE 0x103E         // L"Type:"
#define TEXT_COLOR_B 0x1D13       // L"Background colour"

#define TEXT_RDS 0x94F
#define TEXT_NAV_LEFT 0x1C56
#define TEXT_NAV_RIGHT 0x1C5A
#define TEXT_NAV_UP 0x1C5E
#define TEXT_NAV_DOWN 0x1C53

#endif
