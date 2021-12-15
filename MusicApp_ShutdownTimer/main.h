#ifndef _MAIN_H_
#define _MAIN_H_

#define EMP_NAME "AudioTimer"
typedef struct
{
  bool TimerOn;
  uint16_t TimerID;
  uint8_t Hour;
  uint8_t Min;
  int Interval;
} TIMER_DATA;

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

void onTimer(u16 timerID, LPARAM lparam);

extern "C"
{
  int pg_MusicApplication_PreviousAction(void *wData, BOOK *book);
  int pg_MusicApplication_CancelAction(void *wData, BOOK *book);
  int pg_MusicApplication_ExitAction(void *wData, BOOK *book);

  void MusicApplication_PrevAction(BOOK *book, GUI *gui);
  void MusicApplication_CancelAction(BOOK *book, GUI *gui);
  void MusicApplication_ExecuteSubroutine(BOOK *book, int action, wchar_t *fullpath);
};

#endif
