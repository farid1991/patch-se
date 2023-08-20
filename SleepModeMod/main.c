#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"

#include "Lib.h"
#include "cover.h"
#include "CurrentTrack.h"
#include "fmradio.h"
#include "main.h"
#include "lyric.h"

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "sl", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "sl", 0);
#else
  return memalloc(size, 1, 5, "sl", 0);
#endif
}

void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "sl", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "sl", 0);
#else
  if (mem)
    memfree(mem, "sl", 0);
#endif
}

SLEEPMODE_DATA *InitData()
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)malloc(sizeof(SLEEPMODE_DATA));
  memset(data, NULL, sizeof(SLEEPMODE_DATA));
  set_envp(get_bid(current_process()), ENV_NAME, (OSADDRESS)data);
  return data;
}

SLEEPMODE_DATA *GetData()
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)get_envp(get_bid(current_process()), ENV_NAME);
  if (data)
    return data;
  return InitData();
}

void FreeData(SLEEPMODE_DATA *data)
{
  if (data)
  {
    mfree(data);
    set_envp(get_bid(current_process()), ENV_NAME, (OSADDRESS)NULL);
  }
}

void refresh_screen(DISP_OBJ *disp_obj)
{
  if (disp_obj)
    DispObject_InvalidateRect(disp_obj, NULL);
}

void onTimerID(u16 timerID, LPARAM lparam)
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)lparam;
  refresh_screen(data->sleepmode);
  Timer_ReSet(&data->TimerID, SECOND(REFRESH_TIME), onTimerID, (LPARAM *)data);
}

void SleepMode_SetRefreshTimer(SLEEPMODE_DATA *data)
{
  data->TimerID = Timer_Set(SECOND(REFRESH_TIME), onTimerID, (LPARAM *)data);
}

void SleepMode_KillRefreshTimer(SLEEPMODE_DATA *data)
{
  if (data->TimerID)
  {
    Timer_Kill(&data->TimerID);
    data->TimerID = NULL;
  }
  if (data->TimerLyric)
  {
    Timer_Kill(&data->TimerLyric);
    data->TimerLyric = NULL;
  }
}

void Draw_ScreenSaver(SLEEPMODE_DATA *data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);

  data->text_id = Time2ID(&dt.time, 2, FALSE);
  SetFont(FONT_TIME);
  DrawString(data->text_id, AlignCenter, 1, TIME_Y, data->disp_width, TIME_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);

  data->text_id = Date2ID(&dt.date, 0, 1);
  SetFont(FONT_DATE);
  DrawString(data->text_id, AlignCenter, 1, DATE_Y, data->disp_width, DATE_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);

  char weekday;
  DATE_GetWeekDay(&dt.date, &weekday);
  data->text_id = days[weekday];
  SetFont(FONT_DAY);
  DrawString(data->text_id, AlignCenter, 1, DAY_Y, data->disp_width, DAY_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);

  int missed[ICONS_COUNT + 2];
  int *id = missed;
  int events = *(MissedEvents);
  int index;

  for (index = 0; index < ICONS_COUNT; index++)
  {
    if (events & (1 << index))
    {
      *id++ = missed_icons[index];

      if (index < 2)
        *id++ = TEXTID_CONST + ' ';
    }
  }
  data->text_id = TextID_Create(&missed[0], ENC_TEXTID, id - missed);
  DrawString(data->text_id, AlignCenter, 1, MISSED_Y, data->disp_width, MISSED_Y + GetImageHeight(30), 40, 1, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);
}

void Draw_LyricViewer(SLEEPMODE_DATA *data)
{
  if (data->lrclist)
  {
    if (data->current_offset == WAIT)
    {
      SetFont(Lyric_Font);
      int strr = TextID_Create(L"Please wait...", ENC_UCS2, TEXTID_ANY_LEN);
      DrawString(strr, AlignCenter, 0, data->disp_height >> 1, data->disp_width, data->disp_height, 20, 5, clYellow, clYellow);
      TextID_Destroy(strr);
    }
    else if (data->current_offset >= READY)
    {
      int stridd[100];
      int pos1 = 0;
      int pos = 0;

      for (int i = data->current_offset - 1; i >= 0; i--)
      {
        stridd[i] = TextID_Create(data->lrclist[i].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
        int width1 = Disp_GetTextIDWidth(stridd[i], TextID_GetLength(stridd[i]));
        if (width1 <= data->disp_width)
          pos1 -= 20;
        if (width1 > data->disp_width && width1 <= data->disp_width * 2)
          pos1 -= 40;
        if (width1 > data->disp_width * 2 && width1 <= data->disp_width * 3)
          pos1 -= 60;
        if (width1 > data->disp_width * 3 && width1 <= data->disp_width * 4)
          pos1 -= 80;
        SetFont(Lyric_Font);
        DrawString(stridd[i], AlignLeft, 0, 100 + pos1 - data->offset_len, data->disp_width, data->disp_height, 20, 5, clWhite, clWhite);
        TextID_Destroy(stridd[i]);
        if (100 + pos1 - data->offset_len < -60)
          break;
      }

      if (data->current_offset >= READY)
      {
        stridd[data->current_offset] = TextID_Create(data->lrclist[data->current_offset].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
        SetFont(Lyric_AFont);
        DrawString(stridd[data->current_offset], AlignLeft, 0, 100 - data->offset_len, data->disp_width, data->disp_height, 20, 5, clYellow, clYellow);
        int width2 = Disp_GetTextIDWidth(stridd[data->current_offset], TextID_GetLength(stridd[data->current_offset]));
        TextID_Destroy(stridd[data->current_offset]);
        if (width2 <= data->disp_width)
          pos += 20;
        if (width2 > data->disp_width && width2 <= data->disp_width * 2)
          pos += 40;
        if (width2 > data->disp_width * 2 && width2 <= data->disp_width * 3)
          pos += 60;
        if (width2 > data->disp_width * 3 && width2 <= data->disp_width * 4)
          pos += 80;
      }
      for (int i = (data->current_offset + 1); i < 100 && i >= 0; i++)
      {
        stridd[i] = TextID_Create(data->lrclist[i].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
        SetFont(Lyric_Font);
        DrawString(stridd[i], AlignLeft, 0, 100 + pos - data->offset_len, data->disp_width, data->disp_height, 20, 5, clWhite, clWhite);
        int width3 = Disp_GetTextIDWidth(stridd[i], TextID_GetLength(stridd[i]));
        TextID_Destroy(stridd[i]);
        if (100 + pos - data->offset_len > 280)
          break;
        if (width3 <= data->disp_width)
          pos += 20;
        if (width3 > data->disp_width && width3 <= data->disp_width * 2)
          pos += 40;
        if (width3 > data->disp_width * 2 && width3 <= data->disp_width * 3)
          pos += 60;
        if (width3 > data->disp_width * 3 && width3 <= data->disp_width * 4)
          pos += 80;
      }
    }
  }
}

void Draw_AudioPlayer(SLEEPMODE_DATA *data)
{
  SetFont(FONT_ARTIST);
  DrawString(data->CurrentTrack->Artist, AlignCenter, 1, ARTIST_Y, data->disp_width, ARTIST_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);

  SetFont(FONT_TITLE);
  DrawString(data->CurrentTrack->Title, AlignCenter, 1, TITLE_Y, data->disp_width, TITLE_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);

  SetFont(FONT_ALBUM);
  DrawString(data->CurrentTrack->Album, AlignCenter, 1, ALBUM_Y, data->disp_width, ALBUM_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
}

void InitImage(SLEEPMODE_DATA *data)
{
  if (FSX_IsFileExists(SLEEPMODE_PATH, L"Background.png"))
    ImageID_Get(SLEEPMODE_PATH, L"Background.png", &data->Background);
  else
    data->Background = NOIMAGE;
}

extern "C" int New_SleepMode_OnCreate(DISP_OBJ *disp_obj)
{
  SleepMode_OnCreate(disp_obj);
  SLEEPMODE_DATA *data = GetData();

  data->sleepmode = disp_obj;
  SleepMode_SetRefreshTimer(data);

  InitImage(data);
  data->CoverArt = NOIMAGE;
  data->has_cover = FALSE;
  data->CurrentTrack = NULL;
  data->disp_width = Display_GetWidth(UIDisplay_Main);
  data->disp_height = Display_GetHeight(UIDisplay_Main);
  return 1;
}

extern "C" void New_SleepMode_OnClose(DISP_OBJ *disp_obj)
{
  SleepMode_OnClose(disp_obj);

  SLEEPMODE_DATA *data = GetData();
  IMAGE_FREE(data->Background);
  IMAGE_FREE(data->CoverArt);
  data->has_cover = FALSE;
  TrackDesc_Free(data->CurrentTrack);
  Lyric_FreeData(data);
  SleepMode_KillRefreshTimer(data);
  FreeData(data);
}

extern "C" void New_SleepMode_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  SLEEPMODE_DATA *data = GetData();
  BOOK *audioBook = FindBook(IsAudioPlayerBook);
  BOOK *fmbook = FindBook(IsFmRadioBook);

  GC *PGC = get_DisplayGC();

  if (data->Background != NOIMAGE)
    GC_PutChar(PGC, 0, 0, 0, 0, data->Background);

  if (audioBook)
  {
    GetTags(audioBook);
    if (data->CoverArt != NOIMAGE)
      GC_PutChar(PGC, COVER_X, COVER_Y, COVER_SIZE, COVER_SIZE, data->CoverArt);

    if (data->current_offset == NOLYRIC)
      Draw_AudioPlayer(data);
    else
      Draw_LyricViewer(data);
  }
  else if (fmbook)
    Draw_FMRadio(fmbook, data);
  else
    Draw_ScreenSaver(data);
}

extern "C" void SetBacklightTimeout(DISP_OBJ *disp)
{
  int timeout;
  if (FindBook(IsAudioPlayerBook))
    timeout = SECOND(BACKLIGHT_MAX_TIMEOUT);
  else
    timeout = SECOND(BACKLIGHT_TIMEOUT);
  DispObject_SetBacklightTimeout(disp, timeout);
}
