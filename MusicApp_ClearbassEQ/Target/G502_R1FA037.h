#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define PATH                    0x11989974 // "/usb/other"
#define _SYNC_              	0x11A8331C

#define FPATH                   L"/usb/other/ZBin/Config/Equalizer"
#define DB_UPDATE_EVENT         0x1770

#define ACTION_MP_FILE          0x8
#define ACTION_MP_SETTINGS      0xF
#define ACTION_MP_SKINEDITOR    0x13
#define ACTION_MP_VISUALISATION 0x14
#define ACTION_MP_USE_AS        0x15

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_ACCEPT           0xFAC
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define UI_MEDIAPLAYER_UPDATE_EVENT 0x3C36
#define RETURN_TO_STANDBY_EVENT 0x841
#define PAGE_EXIT_EVENT         0xF
#define PAGE_ENTER_EVENT        0xE
#define CANCEL_EVENT            0x4
#define PREVIOUS_EVENT          0x3
#define ACCEPT_EVENT            0x2
#define NIL_EVENT               0

//G502 fonts
#define D_7R 	  	0x01
#define E_8R	  	0x02
#define E_12R	  	0x0D
#define E_12B	  	0x0E
#define E_14R	  	0x12
#define E_14B	  	0x13
#define E_16R	  	0x19
#define E_16B	  	0x1A
#define E_16I	  	0x1B
#define E_16BI	  	0x1C
#define E_18R	  	0x22
#define E_20R	  	0x2B
#define E_20B	  	0x2C
#define E_20I	  	0x2D
#define E_20BI	  	0x2E
#define E_24R	  	0x35
#define E_24B	  	0x36
#define E_24I	  	0x37
#define E_24BI	  	0x38
#define D_24B	  	0x3F
#define D_29B	  	0x40
#define ICON_16BI 	0x48
#define E_30R	  	0x55
#define E_40R	  	0x57
#define E_60R	  	0x5B
#define E_75R	  	0x5C
#define E_100R	  	0x5E

#define FONT_E_20B      0x2C
#define FONT_E_20R      0x2B

#define KBD_LONG_PRESS    0x1
#define KBD_LONG_RELEASE  0x4
#define KBD_REPEAT        0x2
#define KBD_SHORT_PRESS   0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DEL         0x5
#define KEY_DIEZ        0x1E
#define KEY_DIGITAL_0   0x13
#define KEY_DOWN        0xD
#define KEY_ENTER       0x8
#define KEY_ESC         0x4

#define KEY_LEFT        0xF
#define KEY_LEFT_SOFT   0x2

#define KEY_RIGHT       0xB
#define KEY_RIGHT_SOFT  0x3
#define KEY_STAR        0x1D
#define KEY_TASK        0x1F
#define KEY_UP          0x9
#define KEY_VOL_DOWN    0x12
#define KEY_VOL_UP      0x11

#define TXT_EQUALIZER   0x156C

#define USE_AS_TXT	        0x78E
#define RING_CHANGED_TXT        0x71B
#define MESSAGE_CHANGED_TXT     0x6C3

#define RINGTONE_TXT        0x752
#define MESSAGEALERT_TXT    0x757
#define ALARMSIGNAL_TXT     0x750
#define CONTACTSIGNAL_TXT   0x662

#endif
#endif
