#ifndef W810_R4EA031
#define W810_R4EA031

#define A1
#define DB2010

#define CALLS_MISSED_SLEEPMODE_ICN 0xE5D2
#define SMS_SLEEPMODE_ICN 0xE9A0
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0xE892
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0xE8F3

#define MissedEvents (char *)0x4C2E666F

#define TEXTID_1 0x167 // Monday
#define TEXTID_2 0x1A7 // Tuesday
#define TEXTID_3 0x1CC // Wednesday
#define TEXTID_4 0x1B5 // Thursday
#define TEXTID_5 0x139 // Friday
#define TEXTID_6 0x183 // Saturday
#define TEXTID_7 0x1A5 // Sunday

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

#define FONT_TIME FONT_D_29B
#define FONT_DATE FONT_E_20R
#define FONT_DAY FONT_E_20R

#define TIME_Y 85
#define DATE_Y 50
#define DAY_Y 150
#define MISSED_Y 3

#endif
