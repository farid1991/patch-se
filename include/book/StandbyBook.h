#ifndef _STANDBYBOOK_H_
#define _STANDBYBOOK_H_

typedef struct _StandbyBook : BOOK
{
#ifdef DB2020
  char dummy[0x4];
#endif
  GUI* gui;
} StandbyBook;

#endif
