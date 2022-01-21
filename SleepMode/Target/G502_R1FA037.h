#ifndef G502_R1FA037
#define G502_R1FA037

#define A2
#define DB3150v1

#define NIL_EVENT               0
#define CANCEL_EVENT            4
#define PAGE_ENTER_EVENT        0xE
#define RETURN_TO_STANDBY_EVENT 0x841

#define _SYNC_              	0x11A8331C
#define MissedEvents            0x2A285648

#define KEYLOCK_SLEEPMODE_ICN               0xEC99
#define SILENT_SLEEPMODE_ICN                0xF3C5
#define CALLS_MISSED_SLEEPMODE_ICN          0xE5D0
#define SMS_SLEEPMODE_ICN                   0xF3EB
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN       0xED52
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN  0xE55F
#define TASK_REMINDER_SLEEPMODE_ICN         0xF429
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN  0xEDFA

#define TEXTID_1                0x1D0  // пн
#define TEXTID_2                0x25B  // вт
#define TEXTID_3                0x27B  // ср
#define TEXTID_4                0x24C  // чт
#define TEXTID_5                0x28F  // пт
#define TEXTID_6                0x217  // сб
#define TEXTID_7                0x248  // вс

#define FONT_TIME               0x5E
#define FONT_DATE               0x55
#define FONT_DAY                0x55

#define MISSED_STEP             5
#define MISSED_Y                5
#define TIME_Y                  115
#define DATE_Y                  60
#define DAY_Y                   230

#endif
