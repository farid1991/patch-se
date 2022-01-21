#ifndef W350_R11CA002
#define W350_R11CA002

#define A1
#define PNX5230

#define NIL_EVENT 0
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x7
#define RETURN_TO_STANDBY_EVENT 0x848

#define MissedEvents 0x480D1100

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

#define TEXTID_1 0xCE8 // Sun
#define TEXTID_2 0xCE6 // Mon
#define TEXTID_3 0xCE9 // Thu
#define TEXTID_4 0xCEB // Wed
#define TEXTID_5 0xCEA // Tue
#define TEXTID_6 0xCE5 // Fri
#define TEXTID_7 0xCE7 // Sat

#define E_20R 0x2B
#define E_24B 0x36
#define D_29B 0x40

#define FONT_TIME D_29B
#define FONT_DATE E_24B
#define FONT_DAY E_20R

#define MISSED_STEP 4
#define MISSED_Y 4
#define TIME_Y 96
#define DATE_Y 48
#define DAY_Y 144

#endif
