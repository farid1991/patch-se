#ifndef _SCREENSAVERBOOK_H_
#define _SCREENSAVERBOOK_H_

typedef struct _ScreenSaverBook : BOOK
{
  GUI* SleepMode;
  char dummy[0x64];
}ScreenSaverBook;


#endif
