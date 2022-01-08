#ifndef _STANDBYBOOK_H_
#define _STANDBYBOOK_H_

typedef struct _StandbyBook : BOOK
{
  GUI *StatusIndication; // 0x18
  GUI *MainInput;        // 0x1C
  int unk_0x20;          // 0x20
  int unk_0x24;          // 0x24
  int unk_0x28;          // 0x28
  int unk_0x2C;          // 0x2C
  int unk_0x30;          // 0x30
  int unk_0x34;          // 0x34
  int unk_0x38;          // 0x38
  int unk_0x3C;          // 0x3C
  TEXTID x_textid;       // 0x40
  char unk_0x44[0x14];   // 0x44
  TEXTID searching;      // 0x58
} StandbyBook;

typedef struct _StandbyExternalBook : BOOK
{
  GUI *StatusIndication; // 0x18
} StandbyExternalBook;

#endif
