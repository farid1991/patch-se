#ifndef W580_R8BE001
#error W580_R8BE001 configuration needed for this header!
#else
#ifndef _W580_R8BE001_
#define _W580_R8BE001_

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define RETURN_TO_STANDBY_EVENT 0x848
#define CANCEL_EVENT            0x4
#define PAGE_ENTER_EVENT        0x7

#define TEXTID_OP3              0x13E0 // Оператор 3
#define TEXTID_OP2              0x13E1 // Оператор 2
#define TEXTID_OP1              0x13E2 // Оператор 1
#define TEXTID_SF               0x13E3 // Поиск и Flight
#define TEXTID_BIG_TIME         0x13E4 // Большие часы
#define TEXTID_TALK             0x13E5 // Время разговора
#define TEXTID_SHIFT            0x13E6 // Смещение

#define TEXTID_TITLE            0x13F7
#define SOFTKEY_TEXTID          0x3E9
#define TEXTID_SWITCHED_OFF     0x1534 // Отключено
#define TEXTID_OFF              0x09CB // Отключить
#define TEXTID_NOTES            0x0E91 // Заметки
#define TEXTID_TIME             0x196E // Часы
#define TEXTID_DATE             0x01CC // Дата
#define TEXTID_ALARM            0x1C8E // Будильник
#define TEXTID_TIMER            0x1CDA // Таймер
#define TEXTID_ACCEL            0x1B5D // Счетчик шагов
#define TEXTID_NO               0x1409
#define TEXTID_PROF             0x165D

#define ICONID_NO               0xE621
#define ICONID_PROF             0xEE46
#define ICONID_OP3              0xE5E4 // Оператор 3
#define ICONID_OP2              0xE5E4 // Оператор 2
#define ICONID_OP1              0xE5E4 // Оператор 1
#define ICONID_SF               0xEEAF // Поиск и Flight
#define ICONID_NOTES            0xEDF7 // Заметки
#define ICONID_BIG_TIME         0xF355 // Большие часы
#define ICONID_TIME             0xF364 // Часы
#define ICONID_DATE             0xED55 // Дата
#define ICONID_ALARM            0xF35A // Будильник
#define ICONID_TIMER            0xF333 // Таймер
#define ICONID_TALK             0xEDFC // Время разговора
#define ICONID_SHIFT            0xECC1 // Смещение
#define ICONID_ACCEL            0xF301 // Счетчик шагов

#endif
#endif
