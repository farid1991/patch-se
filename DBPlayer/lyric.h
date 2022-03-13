#ifndef Lyric_H_
#define Lyric_H_

#define MAX_STR 200
#define MAX_EXT 100
#define MAX_TIMER 400

#include "main.h"

typedef enum
{
  UTF8,
  UTF8_BOM,
  UTF16_LE,
  UTF16_BE,
  OTHERS_ENC
} ENCODING_T;

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

void GetLyric(DISP_OBJ_DBP *disp_obj, wchar_t *path, wchar_t *name);
int LoadLrc(DISP_OBJ_DBP *disp_obj, wchar_t *path, wchar_t *name);
int find_current_timer_list(DISP_OBJ_DBP *data, time_t tm);
void TimerList_Free(TimerList *lrclist);
void lyricOnTimer(u16 timerID, LPARAM lparam);
void Kill_LyricTimer(DISP_OBJ_DBP *data);
void Start_LyricTimer(DISP_OBJ_DBP *data);
void Lyric_FreeData(DISP_OBJ_DBP *data);

#endif
