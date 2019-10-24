#ifndef _MOCALLBOOK_H_
#define _MOCALLBOOK_H_

typedef struct
{
  char dummy[0x2];
  IMAGEID icon;
}XIMAGEID;

typedef struct
{
  char dummy[0x70]; ///74!?!
  XIMAGEID * ximg;
}CallStatusDesc_A1;

typedef struct
{
  char dummy[0x7C];
  XIMAGEID * ximg;
}CallStatusDesc_3150;

typedef struct
{
  char dummy[0x78];
  XIMAGEID * ximg;
}CallStatusDesc_3210;

typedef struct
{
  char dummy[0x3e];
  char CallID;
}MOCallBook_2010;

typedef struct
{
  char dummy[0x18];
  char CallID;
}MOCallBook_2020;

typedef struct
{
  BOOK book;
  char dummy_1[0x4];
  char CallID;
  char dummy_2[0x85];
  char PNUM[0x50];
}MOCallBook_3150;

typedef struct
{
  BOOK book;
  char dummy_1[0x4];
  char CallID;
  char dummy_2[0x89];
  char PNUM[0x50];
}MOCallBook_3210;

enum
{
  CALLMANAGER_IDLE            =0,
  CALLMANAGER_CALL_CONNECTED  =1, /*Поднятие трубки*/
  CALLMANAGER_CALL_SETUP      =2, /*Нажатие вызвать*/
  CALLMANAGER_CALL_ALERT      =4, /*Входящий вызов*/
  CALLMANAGER_CALL_WAITING    =5,
  CALLMANAGER_CALL_TERMINATED =6  /*Завершение соединения*/
};

#endif
	