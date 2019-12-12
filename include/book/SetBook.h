#ifndef _SETBOOK_H_
#define _SETBOOK_H_

typedef struct _SetBook : BOOK
{
  char dummy2[0x4];				//0x18
  GUI* gui;						//0x1C
  char dummy3[0x1C];
  int brightness;				//0x3C
  TEXTID item1;					//0x40
  TEXTID item2;					//0x44
  TEXTID item3;					//0x48
  TEXTID item4;					//0x4C
}SetBook;

#endif
