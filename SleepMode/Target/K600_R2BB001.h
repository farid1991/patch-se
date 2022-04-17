#ifndef K600_R2BB001
#define K600_R2BB001

#define A1
#define DB2000

#define KEYLOCK_SLEEPMODE_ICN               NOIMAGE
#define SILENT_SLEEPMODE_ICN                NOIMAGE
#define CALLS_MISSED_SLEEPMODE_ICN          0xE869
#define SMS_SLEEPMODE_ICN                   0xE64C
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN  0xE64D
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN       0xE64E
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN  NOIMAGE
#define TASK_REMINDER_SLEEPMODE_ICN         NOIMAGE

#define MissedEvents            (char *)0x28244364

#define TEXTID_1 0x15A // Monday
#define TEXTID_2 0x198 // Thursday
#define TEXTID_3 0x1B6 // Wednesday
#define TEXTID_4 0x1A6 // Tuesday
#define TEXTID_5 0x12E // Friday
#define TEXTID_6 0x176 // Saturday
#define TEXTID_7 0x196 // Sunday

#define FONT_D_24B 0x2F
#define FONT_D_29B 0x30
#define FONT_D_7R 0x00
#define FONT_E_14B 0x11
#define FONT_E_14BI 0x13
#define FONT_E_14I 0x12
#define FONT_E_14R 0x10
#define FONT_E_16B 0x18
#define FONT_E_16BI 0x1A
#define FONT_E_16I 0x19
#define FONT_E_16R 0x17
#define FONT_E_20B 0x26
#define FONT_E_20BI 0x28
#define FONT_E_20I 0x27
#define FONT_E_20R 0x25
#define FONT_ICON_16BIT_V2 0x38
#define FONT_ICON_2BIT_V2_2NDLCD 0x37

#define FONT_TIME               FONT_D_29B
#define FONT_DATE               FONT_E_20R
#define FONT_DAY                FONT_E_20R

#define TIME_Y                  85
#define DATE_Y                  50
#define DAY_Y                   150
#define MISSED_Y                3

#endif
