#ifndef W200_R4HA014
#define W200_R4HA014

#define A1
#define DB2010

#define CALLS_MISSED_SLEEPMODE_ICN 0xE5C2
#define SMS_SLEEPMODE_ICN 0xE953
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0xE842
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0xE7F3

#define MissedEvents (char *)0x4C25E17F

#define TEXTID_1 0x166 // Monday
#define TEXTID_2 0x1B4 // Tuesday
#define TEXTID_3 0x1CB // Wednesday
#define TEXTID_4 0x1A6 // Thursday
#define TEXTID_5 0x138 // Friday
#define TEXTID_6 0x182 // Saturday
#define TEXTID_7 0x1A4 // Sunday

#define FONT_A_10B 0x5
#define FONT_D_18B 0x2D
#define FONT_D_29B 0x30
#define FONT_E_12R 0xB
#define FONT_E_12B 0xC
#define FONT_E_12I 0xD
#define FONT_E_12BI 0xE
#define FONT_E_14R 0x10
#define FONT_E_14B 0x11
#define FONT_E_14I 0x12
#define FONT_E_14BI 0x13
#define FONT_E_18R 0x1F
#define FONT_E_18B 0x20
#define FONT_E_18I 0x21
#define FONT_E_18BI 0x22
#define FONT_ICON_16BIT_V2 0x38

#define FONT_TIME FONT_D_29B
#define FONT_DATE FONT_E_18R
#define FONT_DAY FONT_E_18R

#define TIME_Y 60
#define DATE_Y 30
#define DAY_Y 120
#define MISSED_Y 2

#endif
