#ifndef W350_R11CA002
#define W350_R11CA002

#define A1
#define PNX5230

#define NIL_EVENT 0
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x7
#define RETURN_TO_STANDBY_EVENT 0x848

#define MissedEvents (char*)0x480D1100

#define KEYLOCK_SLEEPMODE_ICN 0xEC29
#define SILENT_SLEEPMODE_ICN 0xEEB0
#define CALLS_MISSED_SLEEPMODE_ICN 0xE5F6
#define SMS_SLEEPMODE_ICN 0xF2E0
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0xECB0
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN 0xE56F
#define TASK_REMINDER_SLEEPMODE_ICN 0xF30B
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0xED5A
#define WV_SLEEPMODE_MSN_ICN 0xF475
#define WV_SLEEPMODE_WV_ICN 0xF476
#define WV_SLEEPMODE_YAHOO_ICN 0xF477

#define TEXTID_1 0x226 // Sunday
#define TEXTID_2 0x1B6 // Monday
#define TEXTID_3 0x22A // Thursday
#define TEXTID_4 0x252 // Wednesday
#define TEXTID_5 0x238 // Tuesday
#define TEXTID_6 0x188 // Friday
#define TEXTID_7 0x1FB // Saturday

#define FONT_E_6R 0x0
#define FONT_D_7R 0x1
#define FONT_E_12R 0xc
#define FONT_E_12B 0xd
#define FONT_E_14R 0x11
#define FONT_E_14B 0x12
#define FONT_E_14I 0x13
#define FONT_E_14BI 0x14
#define FONT_E_16R 0x18
#define FONT_E_16B 0x19
#define FONT_E_16I 0x1a
#define FONT_E_16BI 0x1b
#define FONT_D_18B 0x20
#define FONT_E_20R 0x2b
#define FONT_E_20B 0x2c
#define FONT_E_20I 0x2d
#define FONT_E_20BI 0x2e
#define FONT_E_24B 0x36
#define FONT_D_24B 0x3f
#define FONT_D_29B 0x40
#define FONT_ICON_16BI 0x48
#define FONT_E_26R 0x54
#define FONT_E_30R 0x55
#define FONT_E_40R 0x57
#define FONT_E_50R 0x58
#define FONT_E_76R 0x5d

#define FONT_TIME FONT_D_29B
#define FONT_DATE FONT_D_24B
#define FONT_DAY FONT_E_20R

#define MISSED_STEP 4
#define MISSED_Y 4
#define TIME_Y 96
#define DATE_Y 48
#define DAY_Y 144

#endif
