#ifndef _STANDBYBOOK_H_
#define _STANDBYBOOK_H_

typedef struct _StandbyBook : BOOK
{
  GUI *StatusIndication;// 0x18
  GUI *MainInput;       // 0x1C
  char unk_0x08[0x20];  // 0x20
  TEXTID x_textid;      // 0x40
  char unk_0x44[0x14];  // 0x44
  TEXTID searching;     // 0x58
} StandbyBook;

#endif
