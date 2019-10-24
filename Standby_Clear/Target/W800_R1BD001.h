#ifndef W800_R1BD001
#error W800_R1BD001 configuration needed for this header!
#else
#ifndef _W800_R1BD001_
#define _W800_R1BD001_

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC3
#define ACTION_DELETE           0xFB4
#define ACTION_BACK             0xFC1
#define ACTION_YES              0xFC6
#define ACTION_NO               0xFBC

#define RETURN_TO_STANDBY_EVENT 0x7B2
#define CANCEL_EVENT            0x11
#define PAGE_ENTER_EVENT        0x5

#define TEXTID_TITLE            0x1659
#define SOFTKEY_TEXTID          0x341

#define TEXTID_SWITCHED_OFF     0x165A // Отключено
#define TEXTID_OFF              0x65   // Отключить
#define TEXTID_OP3              0x165B // Оператор 3
#define TEXTID_OP2              0x165C // Оператор 2
#define TEXTID_OP1              0x165D // Оператор 1
#define TEXTID_SF               0x5C9  // Поиск
#define TEXTID_NOTES            0xA48  // Заметки
#define TEXTID_BIG_TIME         0x1657 // Большие часы
#define TEXTID_TIME             0x10D5 // Часы
#define TEXTID_DATE             0x322  // Дата
#define TEXTID_ALARM            0x126F // Будильник
#define TEXTID_TIMER            0xAA6  // Таймер
#define TEXTID_TALK             0x165E // Время разговора
#define TEXTID_SHIFT            0x1658 // Смещение

#define ICONID_OP3              0xE697 // Оператор 3
#define ICONID_OP2              0xE697 // Оператор 2
#define ICONID_OP1              0xE697 // Оператор 1
#define ICONID_SF               0xE892 // Поиск и Flight
#define ICONID_NOTES            0xE604 // Заметки
#define ICONID_BIG_TIME         0xE62F // Большие часы
#define ICONID_TIME             0xE606 // Часы
#define ICONID_DATE             0xE603 // Дата
#define ICONID_ALARM            0xE605 // Будильник
#define ICONID_TIMER            0xE607 // Таймер
#define ICONID_TALK             0xE6DA // Время разговора
#define ICONID_SHIFT            0xE6F1 // Смещение

#endif
#endif
