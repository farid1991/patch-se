#ifndef _STANDBYBOOK_H_
#define _STANDBYBOOK_H_

#if defined(DB3200) || defined(DB3210)
typedef struct StandbyBook : BOOK
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
  TEXTID inactive;       // 0x40
  char unk_0x44[0x14];   // 0x44
  TEXTID operatorname;   // 0x58
} StandbyBook;
#elif defined(DB3150v2)
typedef struct StandbyBook : BOOK
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
  TEXTID inactive;       // 0x3C
  char unk_0x40[0x14];   // 0x40
  TEXTID networkname;    // 0x54
} StandbyBook;
#endif

typedef struct StandbyExternalBook : BOOK
{
  GUI *StatusIndication; // 0x18
} StandbyExternalBook;

#endif
