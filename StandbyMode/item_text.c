#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#endif
#include "..\\include\book\FmRadio_Book.h"
#include "..\\include\book\StandbyBook.h"
#include "..\\include\book\TimerBook.h"

#include "dll.h"
#include "main.h"
#include "standby_data.h"
#include "item_text.h"

// Weekday
// 0: Shortname; eg: Mon
// 1: Fullname; eg: Monday
TEXTID Get_WeekDay(STANDBY_DATA *standby_data)
{
  const TEXTID fulldays[7] = {
      TEXTID_FULLDAY_1,
      TEXTID_FULLDAY_2,
      TEXTID_FULLDAY_3,
      TEXTID_FULLDAY_4,
      TEXTID_FULLDAY_5,
      TEXTID_FULLDAY_6,
      TEXTID_FULLDAY_7,
  };

  const TEXTID shortdays[7] = {
      TEXTID_SHDAY_1,
      TEXTID_SHDAY_2,
      TEXTID_SHDAY_3,
      TEXTID_SHDAY_4,
      TEXTID_SHDAY_5,
      TEXTID_SHDAY_6,
      TEXTID_SHDAY_7,
  };

  char weekday;
  DATE_GetWeekDay(&standby_data->now->date, &weekday);

  if (standby_data->settings.weekday.mode == 1)
    return fulldays[weekday];
  return shortdays[weekday];
}

int timecmp(const TIME *time1, const TIME *time2)
{
  if (time1->hour > time2->hour)
    return 1;
  if (time1->hour < time2->hour)
    return -1;

  if (time1->min > time2->min)
    return 1;
  if (time1->min < time2->min)
    return -1;

  return 0;
}

int Alarm_GetCurrentAlarmTime(STANDBY_DATA *standby_data, TIME *alarm_time)
{
  alarm_time->hour = alarm_time->min = 0;

  wchar_t alarm_id;
  char alarm_type;
  int status = Alarm_GetCurrentTypeAndAlarmID(&alarm_type, &alarm_id);
  if (status < 0)
  {
    return -1;
  }

  if (alarm_type > AlarmType_Regular)
  {
    return -1;
  }

  IAlarmItem *pAlarmItem = NULL;
  IAlarmRecurrent *pAlarmRecurrent = NULL;
  Get_IAlarm(&pAlarmItem, &pAlarmRecurrent);

  status = pAlarmItem->GetTime(alarm_time, alarm_id);
  if (status >= 0)
  {
    if (alarm_type == AlarmType_Recurrent)
    {
      AlarmWeek alarm_week;
      status = pAlarmRecurrent->GetRecurrent(&alarm_week, alarm_id);
      if (status >= 0)
      {
        char weekday;
        DATE_GetWeekDay(&standby_data->now->date, &weekday);
        char next_weekday = (weekday + 1) % 7;

        if (alarm_week.days[weekday])
        {
          if (!alarm_week.days[next_weekday] && timecmp(&standby_data->now->time, alarm_time) >= 0)
          {
            status = -1;
          }
        }
        else
        {
          if (!alarm_week.days[next_weekday] || timecmp(&standby_data->now->time, alarm_time) >= 0)
          {
            status = -1;
          }
        }
      }
    }
  }
  pAlarmItem->Release();
  pAlarmRecurrent->Release();
  return status;
}

TEXTID Get_ProfileName()
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  int num;
  REQUEST_PROFILE_GETACTIVEPROFILE(SYNC, &num);

  if (num == 0)
  {
    return TEXTID_NORMAL;
  }

  TEXTID_DATA GetProfile;
  wchar_t SetName[16];
  char error;
  GetProfile.ptr = SetName;
  REQUEST_PROFILE_GETPROFILENAME(SYNC, -2, &GetProfile, &error);
  return TextID_Create(GetProfile.ptr, ENC_UCS2, GetProfile.lenght);
}

TEXTID Get_FreeHeap(STANDBY_DATA *standby_data)
{
  int heap = GetFreeBytesOnHeap();
  wchar_t ustr[32];
  if (standby_data->settings.heap.mode == 0)
  {
    snwprintf(ustr, MAXELEMS(ustr), L"HEAP:%dKB", heap / 1024);
  }
  else
  {
    snwprintf(ustr, MAXELEMS(ustr), L"HEAP:%dMB", heap / 1024 / 1024);
  }
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

void GetTimerTime(BOOK *timer, TIME *time)
{
  TimerBook *timer_book = (TimerBook *)timer;

  int timer_duration = timer_book->duration;
  int elapsed_time = get_sys_uptime() - timer_book->start_time;

  if (elapsed_time >= timer_duration)
  {
    time->hour = time->min = time->sec = time->msec = 0;
    return;
  }
  int remaining_time = timer_duration - elapsed_time;

  int divider = 3600000;
  time->hour = remaining_time / divider;
  remaining_time = remaining_time % divider;

  divider = 60000;
  time->min = remaining_time / divider;
  remaining_time = remaining_time % divider;

  divider = 1000;
  time->sec = remaining_time / divider;
  time->msec = 0;
}

TEXTID Get_TimerTime(BOOK *timer)
{
  TIME time;
  GetTimerTime(timer, &time);

  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"%02d:%02d:%02d", time.hour, time.min, time.sec);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_CallTimeInfo()
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  CALLINFO info;
  int8_t error;
  CallInfo_Get(SYNC, 1, &info, &error);

  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"%02d:%02d", info.time.min, info.time.sec);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_CurrentOperatorName()
{
  StandbyBook *sby = (StandbyBook *)Find_StandbyBook();

  if (FlightMode_GetState())
  {
    return TEXTID_FLIGHTMODE;
  }

  if (sby->inactive != EMPTY_TEXTID)
  {
    return sby->inactive;
  }

  if (sby->operatorname != EMPTY_TEXTID)
  {
    return sby->operatorname;
  }

  TEXTID networkname = INetworkServices_GetNetworkName();
  if (networkname != EMPTY_TEXTID)
  {
    return networkname;
  }

  wchar_t buf;
  TEXTID operatorname = GetOperatorName(&buf);
  if (operatorname != EMPTY_TEXTID)
  {
    return operatorname;
  }

  return TEXTID_SEARCHING;
}

TEXTID Get_SignalQuality()
{
  if (FlightMode_GetState())
  {
    return TEXTID_FLIGHTMODE;
  }

  char ber;
  char rssi = 110;
  dll_GetSignalQuality(&rssi, &ber);

  if (rssi < 99)
  {
    int inp = rssi - 113;

    int rssi_id[2];
    rssi_id[0] = TextID_CreateIntegerID(inp);
    rssi_id[1] = TextID_Create(" dBm", ENC_GSM, 4);
    return TextID_Create(rssi_id, ENC_TEXTID, 2);
  }
  return EMPTY_TEXTID;
}

TEXTID Get_BatteryCapacity(STANDBY_DATA *standby_data)
{
  wchar_t ustr[32];
  if (standby_data->settings.battery.mode == 0)
  {
    snwprintf(ustr, MAXELEMS(ustr), L"%02d%%", standby_data->battery_data->RemainingCapacityInPercent);
  }
  else
  {
    snwprintf(ustr, MAXELEMS(ustr), L"%d mAH", standby_data->battery_data->RemainingCapacity);
  }
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_ChargerCurrent(int charger_current)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"%d mA", charger_current / 10);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_BatteryTemp(int battery_temp)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"%02d°C", battery_temp);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_SystemTemp(int system_temp)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"%02d°C", system_temp);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_PhoneVolumeSize(int mode)
{
  VOLUMESIZE_A2 vol;
  GetVolumeSize(DIR_USB, &vol);

  wchar_t ustr[32];
  if (mode == 0)
  {
    snwprintf(ustr, MAXELEMS(ustr), L"Free: %02d MB", vol.FreeSpace / 1048576);
  }
  else
  {
    snwprintf(ustr, MAXELEMS(ustr), L"Used: %02d MB", (vol.TotalSpace - vol.FreeSpace) / 1048576);
  }
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_CardVolumeSize(int mode)
{
  if (!GetMemoryStickStatus())
    return TEXTID_M2_NOTINSERTED;

  VOLUMESIZE_A2 vol;
  GetVolumeSize(DIR_CARD, &vol);

  wchar_t ustr[32];
  if (mode == 0)
  {
    snwprintf(ustr, MAXELEMS(ustr), L"Free: %02d MB", vol.FreeSpace / 1048576);
  }
  else
  {
    snwprintf(ustr, MAXELEMS(ustr), L"Used: %02d MB", (vol.TotalSpace - vol.FreeSpace) / 1048576);
  }
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_TitleTag(BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  if (!MusicBook->CurrentTrack)
    return EMPTY_TEXTID;

  wchar_t *path = FILEITEM_GetPath(MusicBook->CurrentTrack->file_item);
  wchar_t *name = FILEITEM_GetFname(MusicBook->CurrentTrack->file_item);
  wchar_t *title = MetaData_GetTags(path, name, TAG_TITLE);

  return TextID_Create(title, ENC_UCS2, wstrlen(title));
}

TEXTID Get_ArtistTag(BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  if (!MusicBook->CurrentTrack)
    return EMPTY_TEXTID;

  wchar_t *path = FILEITEM_GetPath(MusicBook->CurrentTrack->file_item);
  wchar_t *name = FILEITEM_GetFname(MusicBook->CurrentTrack->file_item);
  wchar_t *artist = MetaData_GetTags(path, name, TAG_ARTIST);

  return TextID_Create(artist, ENC_UCS2, wstrlen(artist));
}

TEXTID Get_FMRadioInfo(BOOK *book, int mode)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  if (mode == 0)
  {
    int frequency = fmbook->CurrentFrequency;
    int whole_part = frequency / 10;
    int decimal_part = frequency % 10;

    wchar_t ustr[64];
    snwprintf(ustr, MAXELEMS(ustr), L"%d.%d MHz", whole_part, decimal_part);
    return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
  }
  else
  {
    wchar_t *ChannelName = fmbook->Channel[fmbook->CurrentChannel - 1].Name;
    return TextID_Create(ChannelName, ENC_UCS2, TEXTID_ANY_LEN);
  }
}
