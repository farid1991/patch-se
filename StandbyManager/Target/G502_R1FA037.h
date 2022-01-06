#ifndef G502_R1FA037
#define G502_R1FA037

#define A2
#define DB3150v1

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define RETURN_TO_STANDBY_EVENT 0x841
#define CANCEL_EVENT            0x4
#define PAGE_ENTER_EVENT        0xE
#define NIL_EVENT               0

#define TEXTID_TITLE            0x92A  // Display:
#define SOFTKEY_TEXTID          0x19ED  // Day

#define TEXTID_SWITCHED_OFF     0xA72  // Disabled
#define TEXTID_OFF              0x85C  // Turn off
#define TEXTID_OP3              0x2C7A // Operator 3
#define TEXTID_OP2              0x2C79 // Operator 2
#define TEXTID_OP1              0x2C81 // Operator
#define TEXTID_SF               0x31FD // Searching
#define TEXTID_NO               0x1DB5 // No Signal
#define TEXTID_PROF             0x1E1B // Profiles 
#define TEXTID_NOTES            0x1E9  // Notes
#define TEXTID_BIG_TIME         0x4B3  // Real time clock - Big
#define TEXTID_TIME             0x2355 // Real time clock - Small
#define TEXTID_DATE             0x190  // Date
#define TEXTID_ALARM            0x13F7 // Alarm
#define TEXTID_TIMER            0x2853 // Timer
#define TEXTID_TALK             0x2368 // Total Call time
#define TEXTID_SHIFT            0x4B2  // Смещение

#define ICONID_OP3              0xF85F // Оператор 3
#define ICONID_OP2              0xF85F // Оператор 2
#define ICONID_OP1              0xF85F // Оператор 1

#define ICONID_SF               0xEB69 // Flight Mode
#define ICONID_NO               0xF33C // No Signal
#define ICONID_PROF             0xF35C
#define ICONID_NOTES            0xEE95 // Заметки
#define ICONID_BIG_TIME         0xF43E // Большие часы
#define ICONID_TIME             0xF43E // Часы
#define ICONID_DATE             0xF43D // Дата
#define ICONID_ALARM            0xF43B // Будильник
#define ICONID_TIMER            0xF825 // Таймер
#define ICONID_TALK             0xE5CB // Время разговора
#define ICONID_SHIFT            0xF887 // Смещение

//Дни недели

#define TEXTID_1                0x255C  // Mon
#define TEXTID_2                0x257D  // Tue
#define TEXTID_3                0x257F  // Wed
#define TEXTID_4                0x257A  // Thu
#define TEXTID_5                0x2555  // Fri
#define TEXTID_6                0x2562  // Sat
#define TEXTID_7                0x2578  // Sun

#define TEXTID_ON_DAY           0x4B0  // Turn on weekday
#define TEXTID_OFF_DAY          0x4B1  // Turn off weekday

#define FILE_PATH (wchar_t*)0x11987FC4  //L"/tpa/system/settings/"

#endif
