#ifndef U10_R7AA071
#define U10_R7AA071

#define A2
#define DB3350

#define FILE_PATH (wchar_t*)0x15C32E78

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define RETURN_TO_STANDBY_EVENT 0x840
#define CANCEL_EVENT            0x4
#define PAGE_ENTER_EVENT        0x10
#define NIL_EVENT               0

#define TEXTID_TITLE            0x9A4  // Display:
#define SOFTKEY_TEXTID          0x1A13 // About

#define TEXTID_SWITCHED_OFF     0xAA6  // Disabled
#define TEXTID_OFF              0x1725 // Disable
#define TEXTID_OP3              0x299E // Operator 3
#define TEXTID_OP2              0x299D // Operator 2
#define TEXTID_OP1              0x29A5 // Operator 1
#define TEXTID_SF               0x1D05 // Flight mode
#define TEXTID_NO               0x19E1 // Networks
#define TEXTID_PROF             0x1F55 // Profile name
#define TEXTID_NOTES            0x1B6C // Notes
#define TEXTID_BIG_TIME         0x1D06 // Большие часы
#define TEXTID_TIME             0x22CA // Real time clock
#define TEXTID_DATE             0x229  // Date
#define TEXTID_ALARM            0x1518 // Alarm
#define TEXTID_TIMER            0x1523 // Timer
#define TEXTID_TALK             0x1D07 // Время разговора
#define TEXTID_SHIFT            0x1D08 // Смещение

#define ICONID_OP3              0xF864 // Operator 3
#define ICONID_OP2              0xF864 // Operator 2
#define ICONID_OP1              0xF864 // Operator 1
#define ICONID_SF               0xF85F // Поиск и Flight
#define ICONID_NO               0xF806
#define ICONID_PROF             0xF865
#define ICONID_NOTES            0xC8C  // Заметки
#define ICONID_BIG_TIME         0xF8CB // Большие часы
#define ICONID_TIME             0xF8CA // Часы
#define ICONID_DATE             0xF848 // Дата
#define ICONID_ALARM            0xF8CE // Будильник
#define ICONID_TIMER            0xF825 // Таймер
#define ICONID_TALK             0xF83C // Время разговора
#define ICONID_SHIFT            0xF83E // Смещение

//Дни недели

#define TEXTID_1                0x2BD4 //Mon
#define TEXTID_2                0x2BD9 //Tue
#define TEXTID_3                0x2BDB //Wed
#define TEXTID_4                0x2BD7 //Thu
#define TEXTID_5                0x2BD3 //Fri
#define TEXTID_6                0x2BD5 //Sat
#define TEXTID_7                0x2BD6 //Sun

#define TEXTID_ON_DAY           0x1D09 // Включить день
#define TEXTID_OFF_DAY          0x1D0A // Отключить день

#endif
