#ifndef Lyric_H_
#define Lyric_H_

#define MAX_STR 200
#define MAX_EXT 100
#define MAX_TIMER 400

#include "main.h"

typedef enum
{
  NOLYRIC = -2,
  WAIT = -1,
  READY = 0
} OFFSET_STATUS;

typedef enum
{
  READ_FAIL = 0,
  READ_OK = 1
} LRC_STATE;

int find_current_timer_list(time_t tm, SLEEPMODE_DATA *data);
void GetLyric(wchar_t *path, wchar_t *name);
void TimerList_Free(TimerList *lrclist);
void lyricOnTimer(u16 timerID, LPARAM lparam);
void Kill_LyricTimer(SLEEPMODE_DATA *data);
void Start_LyricTimer(SLEEPMODE_DATA *data);
void Lyric_FreeData(SLEEPMODE_DATA *data);

#endif
