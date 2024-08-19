#ifndef TimerBook_H
#define TimerBook_H

typedef struct _TimerBook : BOOK
{
  GUI *gui;
  void *unk_0x1C;
  void *unk_0x20;
  TIME current_time;
  int duration;
  int start_time;
} TimerBook;

#endif
