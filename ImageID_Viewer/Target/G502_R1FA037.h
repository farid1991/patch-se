#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define NIL_EVENT               0
#define CANCEL_EVENT            4
#define PAGE_ENTER_EVENT        0xE
#define PAGE_EXIT_EVENT         0xF
#define RETURN_TO_STANDBY_EVENT 0x841

#define ACTION_BACK             0xFC0
#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_ACCEPT           0xFAC   

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

#define KEY_0	KEY_DIGITAL_0+0
#define KEY_1	KEY_DIGITAL_0+1
#define KEY_2	KEY_DIGITAL_0+2
#define KEY_3	KEY_DIGITAL_0+3
#define KEY_4	KEY_DIGITAL_0+4
#define KEY_5	KEY_DIGITAL_0+5
#define KEY_6	KEY_DIGITAL_0+6
#define KEY_7	KEY_DIGITAL_0+7
#define KEY_8	KEY_DIGITAL_0+8
#define KEY_9	KEY_DIGITAL_0+9

#define KEY_STAR      0x1D
#define KEY_DIEZ      0x1E

#define TXT_GOTO  0xD22
#define TXT_OUT   0x2EE3
#define TXT_INPUT 0x27BD

#define ITEM_1 0x13C5
#define ITEM_2 0x13C6
#define ITEM_3 0x13C7
#define ITEM_4 0x13ED
#define ITEM_5 0x1A8

#define SCN_WIDTH 240
#define SCN_HEIGHT 320

#endif
#endif
