#ifndef _MAIN_H_
#define _MAIN_H_

#define TI_GET_HOUR(x) ((unsigned int)x & 0xFF)
#define TI_GET_MIN(x) (((unsigned int)x >> 8) & 0xFF)
#define TI_GET_SEC(x) (((unsigned int)x >> 16) & 0xFF)

#define EMP_NAME "AudioTimer"

typedef struct
{
  bool TimerOn;
  Uint16_t TimerID;
  Uint8_t Hour;
  Uint8_t Min;
  Uint8_t Sec;
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
