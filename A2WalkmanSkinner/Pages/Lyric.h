#ifndef _LYRIC_H_
#define _LYRIC_H_

#include "..\\CurrentTrack.h"
#include "..\\GUI/AdvLyric.h"

#define MAX_STR 200
#define MAX_EXT 100
#define MAX_TIMER 400

#define LRC_READY 0
#define LRC_NOTFOUND (-2)
#define LRC_PREPARING (-1)

static const char AdvLyric_BookName[] = "AdvLyricBook";
static const char AdvLyric_Base_PageName[] = "AdvLyric_Base_Page";
static const char AdvLyric_Main_PageName[] = "AdvLyric_Main_Page";

typedef struct
{
  unsigned long Timer;
  wchar_t *LrcInfo;
} TimerList;

typedef struct _AdvLyricBook : BOOK
{
  GUI *LyricGUI;
  char *LrcBuf;
  TimerList *LrcList;
  TRACK_DESC *CurrentTrack;
  int Display;
  int CurrentIndex;
  int Length;
  u16 LyricShowTimer;
  unsigned int list_num;
  u16 scr_w;
  u16 scr_h;
} AdvLyricBook;

void Enter_Lyric(BOOK *book, GUI *gui);
BOOL IsAdvLyricBook(BOOK *book);
AdvLyricBook *Find_AdvLyricBook();
void Free_AdvLyricBook();
void AdvLyric_GetLyric(void *timedata, BOOK *book);
void Kill_LyricShowTimer(BOOK *book);
AdvLyricBook *Find_AdvLyricBook();

int pg_AdvLyric_EnterEvent(void *r1, BOOK *book);
int pg_AdvLyric_ExitEvent(void *data, BOOK *book);
int pg_AdvLyric_CancelEvent(void *data, BOOK *book);

const PAGE_MSG bk_Advlyric_base[] =
    {
        CANCEL_EVENT, pg_AdvLyric_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_AdvLyric_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC AdvLyric_Base_Page = {AdvLyric_Base_PageName, NULL, bk_Advlyric_base};

const PAGE_MSG bk_Advlyric_main[] =
    {
        PAGE_ENTER_EVENT, pg_AdvLyric_EnterEvent,
        PAGE_EXIT_EVENT, pg_AdvLyric_ExitEvent,
        NIL_EVENT, NULL};
const PAGE_DESC AdvLyric_Main_Page = {AdvLyric_Main_PageName, NULL, bk_Advlyric_main};

#endif
