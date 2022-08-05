#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#include "..\\dll.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\CurrentTrack.h"
#include "..\\Function.h"
#include "..\\main.h"
#include "..\\String.h"

#include "..\\GUI\AdvLyric.h"

#include "Lyric.h"

//==============================================================================

BOOL IsAdvLyricBook(BOOK *book)
{
  if (!strcmp(book->xbook->name, AdvLyric_BookName))
    return TRUE;
  return FALSE;
}

AdvLyricBook *Find_AdvLyricBook()
{
  return (AdvLyricBook *)FindBook(IsAdvLyricBook);
}

void Free_AdvLyricBook()
{
  AdvLyricBook *Lrc = Find_AdvLyricBook();
  if (Lrc)
    FreeBook(Lrc);
}

void Kill_LyricShowTimer(BOOK *book)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;
  if (Lrc->LyricShowTimer)
  {
    Timer_Kill(&Lrc->LyricShowTimer);
    Lrc->LyricShowTimer = NULL;
    Lrc->Length = NULL;
  }
}

int Str2Timer(char *str)
{
  int len = strlen(str);
  int i = 0;
  int ret = 0;
  while (i < len)
  {
    int j = len - i;
    int e = 1;
    while (j > 0)
    {
      e *= 10;
      j--;
    }
    e = division(e, 10);
    ret += e * (str[i] - '0');
    i++;
  }
  return ret;
}

void TimerList_Free(TimerList *LrcList)
{
  for (int list_num = 0; list_num < MAX_TIMER; list_num++)
  {
    if (LrcList[list_num].LrcInfo)
    {
      mfree(LrcList[list_num].LrcInfo);
      LrcList[list_num].LrcInfo = NULL;
    }
  }
  mfree(LrcList);
}

int LoadLrc(BOOK *book, wchar_t *fpath, wchar_t *fname)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;

  FSTAT _fstat;
  if (fstat(fpath, fname, &_fstat) < 0)
    return 0;

  int fsize = _fstat.fsize;
  if (!fsize)
    return 0;

  int file = _fopen(fpath, fname, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file < 0)
    return 0;

  char *lrca;
  wchar_t *wlrca;

  lrca = StringAlloc(fsize);
  fread(file, lrca, fsize);
  fclose(file);

  int encoding = Encoding_GetType(lrca);
  StringFree(Lrc->LrcBuf);
  switch (encoding)
  {
  case ANSI:
    Lrc->LrcBuf = StringAlloc(StringLength(lrca));
    strcpy(Lrc->LrcBuf, lrca);
    break;
  case UNICODE:
    wlrca = WStringAlloc(division(fsize, 2));
    memcpy(wlrca, lrca + 2, fsize - 1);
    Lrc->LrcBuf = StringAlloc(fsize);
    wstr2strn(Lrc->LrcBuf, wlrca, fsize + 1);
    WStringFree(wlrca);
    break;
  case UTF8:
    Lrc->LrcBuf = StringAlloc(StringLength(lrca));
    wlrca = WStringAlloc(StringLength(lrca) * 2);
    UTF82unicode(wlrca, lrca, StringLength(lrca));
    wstr2strn(Lrc->LrcBuf, wlrca, StringLength(lrca));
    WStringFree(wlrca);
    break;
  default:
    break;
  }
  StringFree(lrca);

  if (Lrc->LrcList)
    TimerList_Free(Lrc->LrcList);

  Lrc->LrcList = (TimerList *)malloc(sizeof(TimerList) * MAX_TIMER);
  memset(Lrc->LrcList, NULL, sizeof(TimerList) * (MAX_TIMER));
  Lrc->list_num = 0;
  int i = 0;
  while (i < StringLength(Lrc->LrcBuf))
  {
    if (Lrc->LrcBuf[i] == '[')
    {
      if (IsDigit(Lrc->LrcBuf[i + 1]))
      {
        int j = 1;
        char *tmp = StringAlloc(MAX_EXT);
        while (Lrc->LrcBuf[i + j] != ']')
        {
          if (j <= MAX_EXT)
          {
            tmp[j - 1] = Lrc->LrcBuf[i + j];
          }
          j++;
        }
        char Min[4] = "";
        char Sec[4] = "";
        char MSec[4] = "";
        strncpy(Min, tmp, StringLength(tmp) - StringLength(strstr(tmp, ":")));
        if (strstr(tmp, "."))
        {
          strncpy(Sec, strstr(tmp, ":") + 1, StringLength(strstr(tmp, ":")) - StringLength(strstr(tmp, ".")) - 1);
          strncpy(MSec, strstr(tmp, ".") + 1, StringLength(strstr(tmp, ".")) - 1);
        }
        else
          strncpy(Sec, strstr(tmp, ":") + 1, StringLength(strstr(tmp, ":")) - 1);
        Lrc->LrcList[Lrc->list_num].Timer = Str2Timer(MSec) + (Str2Timer(Sec) * 1000) + (Str2Timer(Min) * 60 * 1000);

        int m = i;
        int k = i;
        char *ttmp = StringAlloc(MAX_STR * 2);
        while (Lrc->LrcBuf[m] != '\r' && Lrc->LrcBuf[m] != '\n')
        {
          if (!Lrc->LrcBuf[m])
            break;
          ttmp[k - i] = Lrc->LrcBuf[m];
          k++;
          m++;
        }
        wchar_t *wstr = WStringAlloc(MAX_STR * 2);
        str2wstr(wstr, ttmp);
        Lrc->LrcList[Lrc->list_num].LrcInfo = WStringAlloc(MAX_EXT);

        wstrcpy(Lrc->LrcList[Lrc->list_num].LrcInfo, wstrrchr(wstr, ']') + 1);
        i += (StringLength(tmp) + 1);
        Lrc->list_num++;
      }
    }
    i++;
  }
  return 1;
}

int songname_to_lrc(wchar_t *lyricname, wchar_t *songname, int len)
{
  if (!len)
    return FALSE;

  int i = 0;
  wchar_t *wstr = wstrrchr(songname, '.');
  int extlen = (wstrlen(wstr) - 1);
  while (i < (len - extlen))
  {
    lyricname[i] = songname[i];
    i++;
  }
  wstrcat(lyricname, L"lrc");
  return TRUE;
}

int find_current_timer_list(time_t Time, AdvLyricBook *Lrc)
{
  int i = 0;
  DISP_OBJ_ADVLYRIC *disp_obj = (DISP_OBJ_ADVLYRIC *)GUIObject_GetDispObject(Lrc->LyricGUI);
  while (i <= Lrc->list_num)
  {
    if ((Time - Lrc->LrcList[i].Timer) <= 100 || (Lrc->LrcList[i].Timer - Time <= 100))
    {
      if ((Time - Lrc->LrcList[i + 1].Timer) <= 100 || (Lrc->LrcList[i + 1].Timer - Time <= 100))
      {
        return i + 1;
      }
      else if ((Time - Lrc->LrcList[i + 2].Timer) <= 100 || (Lrc->LrcList[i + 2].Timer - Time <= 100))
      {
        return i + 2;
      }
      else
      {
        return i;
      }
    }
    else if (Time >= Lrc->LrcList[i].Timer && Time <= Lrc->LrcList[i + 1].Timer && disp_obj->fastchanged == 1)
    {
      disp_obj->fastchanged = 0;
      return i;
    }
    i++;
  }
  return MAX_TIMER;
}

void SortTimer(AdvLyricBook *Lrc)
{
  int i = 0;
  while (i <= Lrc->list_num)
  {
    int j = i;
    while (j <= Lrc->list_num)
    {
      if (Lrc->LrcList[i].Timer > Lrc->LrcList[j].Timer && Lrc->LrcList[i].Timer > 0 && Lrc->LrcList[j].Timer > 0)
      {
        TimerList tmp;
        memcpy(&tmp, &Lrc->LrcList[i], sizeof(TimerList));
        memcpy(&Lrc->LrcList[i], &Lrc->LrcList[j], sizeof(TimerList));
        memcpy(&Lrc->LrcList[j], &tmp, sizeof(TimerList));
      }
      j++;
    }
    i++;
  }
}

void onLrcShowTimer(u16 timerID, LPARAM lparam)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)lparam;
  Lrc->Length++;

  DISP_OBJ_ADVLYRIC *disp_obj = (DISP_OBJ_ADVLYRIC *)GUIObject_GetDispObject(Lrc->LyricGUI);

  InvalidateRect(disp_obj);

  int textid = TextID_Create(Lrc->LrcList[Lrc->CurrentIndex].LrcInfo, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210)
  int width = dll_Disp_GetTextIDWidth(FONT_E_16B, textid, TextID_GetLength(textid));
#else
  int width = Disp_GetTextIDWidth(textid, TextID_GetLength(textid));
#endif
  DESTROY_TEXTID(textid);

  int BetweenTimer = Lrc->LrcList[Lrc->CurrentIndex + 1].Timer - Lrc->LrcList[Lrc->CurrentIndex].Timer;
  if (width <= Lrc->scr_w)
  {
    Timer_ReSet(&Lrc->LyricShowTimer, division(BetweenTimer, 20), onLrcShowTimer, (LPARAM *)Lrc);
  }
  if (width > Lrc->scr_w && width <= Lrc->scr_w * 2)
  {
    Timer_ReSet(&Lrc->LyricShowTimer, division(BetweenTimer, (20 * 2)), onLrcShowTimer, (LPARAM *)Lrc);
  }
  if (width > Lrc->scr_w * 2 && width <= Lrc->scr_w * 3)
  {
    Timer_ReSet(&Lrc->LyricShowTimer, division(BetweenTimer, (20 * 3)), onLrcShowTimer, (LPARAM *)Lrc);
  }
  if (width > Lrc->scr_w * 3 && width <= Lrc->scr_w * 4)
  {
    Timer_ReSet(&Lrc->LyricShowTimer, division(BetweenTimer, (20 * 4)), onLrcShowTimer, (LPARAM *)Lrc);
  }
}

void AdvLyric_RefreshScreen(BOOK *book)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;
  DispObject_InvalidateRect(GUIObject_GetDispObject(Lrc->LyricGUI), NULL);
}

void AdvLyric_GetLyric(void *timedata, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  AdvLyricBook *Lrc = Find_AdvLyricBook();

  TRACK_DESC *NewTrack = TrackDesc_Get(MusicBook);
  if (!TrackDesc_Compare(Lrc->CurrentTrack, NewTrack))
  {
    TrackDesc_Free(Lrc->CurrentTrack);
    Lrc->CurrentTrack = NewTrack;

    wchar_t *Lyricname = WStringAlloc(wstrlen(Lrc->CurrentTrack->Filename));
    songname_to_lrc(Lyricname, Lrc->CurrentTrack->Filename, wstrlen(Lrc->CurrentTrack->Filename));

    Kill_LyricShowTimer(Lrc);
    Lrc->Display = LoadLrc(Lrc, Lrc->CurrentTrack->Filepath, Lyricname);
    WStringFree(Lyricname);

    if (Lrc->Display == 1)
    {
      Lrc->CurrentIndex = -1;
      SortTimer(Lrc);
    }
    else
    {
      Lrc->CurrentIndex = -2;
    }

    AdvLyric_RefreshScreen(Lrc);
  }
  else
  {
    TrackDesc_Free(NewTrack);
  }

  if (Lrc->Display == 1)
  {
    PLAYING_TIME_DATA *TimeData = (PLAYING_TIME_DATA *)timedata;
    int ElapsedTime = (TimeData->Minutes * 60 * 1000) + (TimeData->Seconds * 1000) + TimeData->MilliSeconds;

    int CurrentIndex = find_current_timer_list(ElapsedTime, Lrc);
    if (CurrentIndex <= Lrc->list_num && CurrentIndex >= 0)
    {
      Lrc->CurrentIndex = CurrentIndex;
      Kill_LyricShowTimer(Lrc);
      Lrc->LyricShowTimer = Timer_Set(NULL, onLrcShowTimer, (LPARAM *)Lrc);
    }
  }
}

void AdvLyric_CloseAction(BOOK *book, GUI *gui)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;
  FreeBook(Lrc);
}

int pg_AdvLyric_EnterEvent(void *r1, BOOK *book)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;
  DESTROY_GUI(Lrc->LyricGUI);

  Lrc->LyricGUI = CreateAdvLyric(Lrc);
  GUIObject_SoftKeys_SetAction(Lrc->LyricGUI, ACTION_BACK, AdvLyric_CloseAction);
  GUIObject_SoftKeys_SetAction(Lrc->LyricGUI, ACTION_LONG_BACK, AdvLyric_CloseAction);
  GUIObject_SetAnimation(Lrc->LyricGUI, LYRIC_GUI_ANIMATION);
  GUIObject_Show(Lrc->LyricGUI);

  return 1;
}

int pg_AdvLyric_ExitEvent(void *data, BOOK *book)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;
  DESTROY_GUI(Lrc->LyricGUI);
  return 1;
}

int pg_AdvLyric_CancelEvent(void *data, BOOK *book)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;
  FreeAllBook(Lrc, NULL);
  return 1;
}

void AdvLyricBook_Destroy(BOOK *book)
{
  AdvLyricBook *Lrc = (AdvLyricBook *)book;

  Kill_LyricShowTimer(Lrc);
  DESTROY_GUI(Lrc->LyricGUI);
  TrackDesc_Free(Lrc->CurrentTrack);

  if (Lrc->LrcList)
    TimerList_Free(Lrc->LrcList);
  StringFree(Lrc->LrcBuf);
}

AdvLyricBook *Create_AdvLyricBook()
{
  AdvLyricBook *Lrc = (AdvLyricBook *)malloc(sizeof(AdvLyricBook));
  memset(Lrc, NULL, sizeof(AdvLyricBook));
  if (!CreateBook(Lrc, AdvLyricBook_Destroy, &AdvLyric_Base_Page, AdvLyric_BookName, NO_BOOK_ID, NULL))
  {
    mfree(Lrc);
    return NULL;
  }
  Lrc->LyricGUI = NULL;
  Lrc->LrcBuf = NULL;
  Lrc->LrcList = NULL;
  Lrc->CurrentTrack = NULL;
  Lrc->Display = NULL;
  Lrc->CurrentIndex = NULL;
  Lrc->Length = NULL;
  Lrc->LyricShowTimer = NULL;
  Lrc->list_num = NULL;
  Lrc->scr_w = NULL;
  Lrc->scr_h = NULL;
  return Lrc;
}

void Enter_Lyric(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;

  AdvLyricBook *Lrc = Find_AdvLyricBook();
  if (!Lrc)
  {
    Lrc = Create_AdvLyricBook();
    Lrc->scr_w = Display_GetWidth(UIDisplay_Main);
    Lrc->scr_h = Display_GetHeight(UIDisplay_Main);
    BookObj_GotoPage(Lrc, &AdvLyric_Main_Page);
  }
  else
  {
    BookObj_SetFocus(Lrc, UIDisplay_Main);
  }
}
