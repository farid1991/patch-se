#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\include\book\AudioPlayerBook.h"
#include "..\\include\book\FmRadio_Book.h"
#include "..\include\book\ScreenSaverBook.h"

#include "Lib.h"
#include "cover.h"
#include "CurrentTrack.h"
#include "main.h"

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "", 0);
#else
  return memalloc(size, 1, 5, "", 0);
#endif
}

void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "", 0);
#else
  if (mem)
    memfree(mem, "", 0);
#endif
}

SLEEPMODE_DATA *InitData()
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)malloc(sizeof(SLEEPMODE_DATA));
  memset(data, NULL, sizeof(SLEEPMODE_DATA));
  set_envp(get_bid(current_process()), EMP_NAME, (OSADDRESS)data);
  return data;
}

SLEEPMODE_DATA *GetData()
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)get_envp(get_bid(current_process()), EMP_NAME);
  if (data)
    return data;
  return InitData();
}

void FreeData(SLEEPMODE_DATA *data)
{
  if (data)
  {
    mfree(data);
    set_envp(get_bid(current_process()), EMP_NAME, (OSADDRESS)NULL);
  }
}

void onTimer(u16 timerID, LPARAM lparam)
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)lparam;
  Timer_ReSet(&data->TimerID, 1000, onTimer, lparam);
  DispObject_InvalidateRect(data->ScrScv, NULL);
}

void SleepMode_SetRefreshTimer(SLEEPMODE_DATA *data)
{
  data->TimerID = Timer_Set(1000, onTimer, (LPARAM *)data);
}

void SleepMode_KillRefreshTimer(SLEEPMODE_DATA *data)
{
  if (data->TimerID)
  {
    Timer_Kill(&data->TimerID);
    data->TimerID = NULL;
  }
}

TEXTID Get_ChannelName(BOOK *book)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  char CurrentChannel = fmbook->CurrentChannel;
  wchar_t *ChannelName = fmbook->Channel[CurrentChannel - 1].Name;
  return TextID_Create(ChannelName, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_CurrentFrequency(BOOK *book)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  u16 CurrentFrequency = fmbook->CurrentFrequency;

  wchar_t buffer[64];
  snwprintf(buffer, MAXELEMS(buffer), L"%.1f MHz", CurrentFrequency / 10.0);
  return TextID_Create(buffer, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_GetPSName(BOOK *book)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  return TextID_Create(fmbook->ProgramServiceName, ENC_UCS2, TEXTID_ANY_LEN);
}

void GetTags(BOOK *book)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  SLEEPMODE_DATA *data = GetData();

  TRACK_DESC *NewTrack = TrackDesc_Get(audioBook);
  if (!TrackDesc_Compare(data->CurrentTrack, NewTrack))
  {
    if (data->HasCover)
      IMAGE_FREE(data->CoverArt);

    TrackDesc_Free(data->CurrentTrack);
    data->CurrentTrack = NewTrack;

    if (MetaData_ExtractCover(data->CurrentTrack->path, data->CurrentTrack->name))
    {
      ImageID_Get(SLEEPMODE_PATH, L"albumart.png", &data->CoverArt);
      data->HasCover = TRUE;
    }
    else
    {
      data->CoverArt = NOIMAGE;
      data->HasCover = FALSE;
    }
  }
  else
  {
    TrackDesc_Free(NewTrack);
  }
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

  data->ScrScv = disp_obj;
  SleepMode_SetRefreshTimer(data);

  InitImage(data);
  data->CoverArt = NOIMAGE;
  data->HasCover = FALSE;
  data->CurrentTrack = NULL;
  data->DispWidth = Display_GetWidth(UIDisplay_Main);
  return 1;
}

extern "C" void New_SleepMode_OnClose(DISP_OBJ *disp_obj)
{
  SleepMode_OnClose(disp_obj);

  SLEEPMODE_DATA *data = GetData();
  IMAGE_FREE(data->Background);
  IMAGE_FREE(data->CoverArt);
  data->HasCover = FALSE;
  TrackDesc_Free(data->CurrentTrack);
  SleepMode_KillRefreshTimer(data);
  FreeData(data);
}

extern "C" void New_SleepMode_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  SLEEPMODE_DATA *data = GetData();
  BOOK *audioBook = FindBook(IsAudioPlayerBook);
  BOOK *fmbook = FindBook(IsFmRadioBook);

  GC *pGC = get_DisplayGC();
  if (data->Background != NOIMAGE)
    GC_PutChar(pGC, 0, 0, 0, 0, data->Background);

  if (audioBook)
  {
    GetTags(audioBook);

    if (data->CoverArt != NOIMAGE)
      GC_PutChar(pGC, COVER_X, COVER_Y, COVER_SIZE, COVER_SIZE, data->CoverArt);

    SetFont(FONT_ARTIST);
    DrawString(data->CurrentTrack->Artist, AlignCenter, 1, ARTIST_Y, data->DispWidth, ARTIST_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);

    SetFont(FONT_TITLE);
    DrawString(data->CurrentTrack->Title, AlignCenter, 1, TITLE_Y, data->DispWidth, TITLE_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);

    SetFont(FONT_ALBUM);
    DrawString(data->CurrentTrack->Album, AlignCenter, 1, ALBUM_Y, data->DispWidth, ALBUM_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  }
  else if (fmbook)
  {
    data->text_id = Get_CurrentFrequency(fmbook);
    SetFont(FONT_FREQ);
    DrawString(data->text_id, AlignCenter, 1, FREQ_Y, data->DispWidth, FREQ_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
    TextID_Destroy(data->text_id);

    data->text_id = Get_ChannelName(fmbook);
    SetFont(FONT_CHANNEL);
    DrawString(data->text_id, AlignCenter, 1, CHANNEL_Y, data->DispWidth, CHANNEL_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
    TextID_Destroy(data->text_id);

    data->text_id = Get_GetPSName(fmbook);
    SetFont(FONT_PSNAME);
    DrawString(data->text_id, AlignCenter, 1, PSNAME_Y, data->DispWidth, PSNAME_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
    TextID_Destroy(data->text_id);
  }
  else
  {
    int _SYNC = NULL;
    int *SYNC = &_SYNC;

    DATETIME dt;
    REQUEST_DATEANDTIME_GET(SYNC, &dt);

    data->text_id = Time2ID(&dt.time, 2, FALSE);
    SetFont(FONT_TIME);
    DrawString(data->text_id, AlignCenter, 1, TIME_Y, data->DispWidth, TIME_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
    TextID_Destroy(data->text_id);

    data->text_id = Date2ID(&dt.date, 0, 1);
    SetFont(FONT_DATE);
    DrawString(data->text_id, AlignCenter, 1, DATE_Y, data->DispWidth, DATE_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
    TextID_Destroy(data->text_id);

    char weekday;
    DATE_GetWeekDay(&dt.date, &weekday);
    data->text_id = days[weekday];
    SetFont(FONT_DAY);
    DrawString(data->text_id, AlignCenter, 1, DAY_Y, data->DispWidth, DAY_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
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
    DrawString(data->text_id, AlignCenter, 1, MISSED_Y, data->DispWidth, MISSED_Y + GetImageHeight(30), 40, 1, clWhite2, clEmpty);
    TextID_Destroy(data->text_id);
  }
}
