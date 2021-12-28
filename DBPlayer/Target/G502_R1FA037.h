#ifndef G502_R1FA037
#define G502_R1FA037

#define A2
#define DB3150v1

#define FONT_D_7R 	  0x01
#define FONT_E_8R	  0x02
#define FONT_E_12R	  0x0D
#define FONT_E_12B	  0x0E
#define FONT_E_14R	  0x12
#define FONT_E_14B	  0x13
#define FONT_E_16R	  0x19
#define FONT_E_16B	  0x1A
#define FONT_E_16I	  0x1B
#define FONT_E_16BI	  0x1C
#define FONT_E_18R	  0x22
#define FONT_E_20R	  0x2B
#define FONT_E_20B	  0x2C
#define FONT_E_20I	  0x2D
#define FONT_E_20BI	  0x2E
#define FONT_E_24R	  0x35
#define FONT_E_24B	  0x36
#define FONT_E_24I	  0x37
#define FONT_E_24BI	  0x38
#define FONT_D_24B	  0x3F
#define FONT_D_29B	  0x40
#define FONT_ICON_16BI 	  0x48
#define FONT_E_30R	  0x55
#define FONT_E_40R	  0x57
#define FONT_E_60R	  0x5B
#define FONT_E_75R	  0x5C
#define FONT_E_100R	  0x5E

#define POPUP_WARNING_ICN 0xF831

#define TEXT_STOP             0x5B8   // L"????"
#define TEXT_TURN             0xBE3   // L"????????"
#define TEXT_SETTING          0x32D  // L"?????????"
#define TEXT_ON               0x1E1   // L"????????"
#define TEXT_OFF              0x1DF  // L"?????????"
#define TEXT_ON_OOM           0x85E     // L"????????"
#define TEXT_OFF_OOM          0x85C   // L"?????????"
#define TEXT_CHANGE           0xD54   // L"??????? ?????????"
#define TEXT_QUESTION         0x723   // L"??????????"
#define TEXT_SAVE             0x121   // L"?????????"
#define TEXT_LEFT             0x17D3   // L"?????"
#define TEXT_RIGHT            0x17D4  // L"??????"
#define TEXT_CENTRE           STR("Center")   // L"Center"
#define TEXT_IMAGE            0x1021   // L"???????????"
#define TEXT_CANCEL           0x855    // L"????????"
#define TEXT_PLAY             0x15C0   // L"?????."
#define TEXT_PAUSE            0x15B9  // L"?????"
#define TEXT_TIME             0xD22   // L"???????"
// #define TEXT_YEAR             0x1653  // L"???"
// #define TEXT_GENRE            0x1588   // L"????"
#define TEXT_COVER            0x1639  // L"??????? ????."
// #define TEXT_BACKROUND        0x2E4F  // L"???"
// #define TEXT_ADDITIONAL       0x12E    // L"?????????????"
//#define TEXT_ACTIVATE         0xCD7   // L"????????"
#define TEXT_COLOR            0x2389  // L"????"
#define TEXT_COLOR_TEXT       0x23D9  // L"???? ??????"
#define TEXT_PTYPE            0x2B21  // L"???"
#define TEXT_COLOR_B          0x2385  // L"???? ????"
#define TEXT_MODE             0x1A0F  // L"????? ???????."
#define TEXT_SCREEN           0x59C   // L"Fullscreen"
#define TEXT_ANIMATION        0x1727  // L"????????"
#define TEXT_THEME            0x27C4   // L"?? ????"
#define TEXT_UNKNOWN          0x110

#define ACTION_LONG_BACK  0xFAF
#define ACTION_NO         0xFBE
#define ACTION_BACK       0xFC0
#define ACTION_SELECT1    0xFC2
#define ACTION_YES        0xFC5

#define KBD_SHORT_PRESS   0x0
#define KBD_LONG_PRESS    0x1
#define KBD_REPEAT        0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE  0x4

#define KEY_ESC       0x4
#define KEY_DEL       0x5
#define KEY_ENTER     0x8
#define KEY_UP        0x9
#define KEY_RIGHT     0xB
#define KEY_DOWN      0xD
#define KEY_LEFT      0xF
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
#define KEY_STAR      0x1D
#define KEY_DIEZ      0x1E
#define KEY_VOL_DOWN  0x12
#define KEY_VOL_UP    0x11

#define NIL_EVENT         0x0
#define PREVIOUS_EVENT    0x3
#define CANCEL_EVENT      0x4
#define PAGE_ENTER_EVENT  0xE

#define RETURN_TO_STANDBY_EVENT         0x841
#define UI_KEYLOCK_ACTIVATE_EVENT       0x571F
#define VOLUMEDOWNKEY_SHORT_PRESS_EVENT 0x58
#define VOLUMEUPKEY_SHORT_PRESS_EVENT   0x55

#define PFONTDESC		(FONT_DESC*)0x2A2846AC
#define PFONTCOUNT		(int*)0x2A284A1C

#define IID_IMetaData             (UUID*)0x119C7578
#define CID_CMetaData             (UUID*)0x1199A854
#define CID_CMusicServer_Manager  (UUID*)0x119A61F0
#define IID_IMusicServer_Manager  (UUID*)0x119CE310

#define _SYNC_            0x11A8331C
#define DEFCFG_PATH       (wchar_t*)0x11987FC4

#define SCR_WIDTH 240
#define SCR_HEIGHT 320
      
#endif
