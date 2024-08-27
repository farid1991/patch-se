#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "standby_data.h"
#include "dll.h"
#include "Editor.h"
#include "main.h"

BATT *data_battery_create()
{
  BATT *batt = (BATT *)malloc(sizeof(BATT));
  memset(batt, 0, sizeof(BATT));
  return batt;
}

DATE *data_date_create()
{
  DATE *date = (DATE *)malloc(sizeof(DATE));
  memset(date, 0, sizeof(DATE));
  return date;
}

DATETIME *data_datetime_create()
{
  DATETIME *datetime = (DATETIME *)malloc(sizeof(DATETIME));
  memset(datetime, 0, sizeof(DATETIME));
  return datetime;
}

void data_init(STANDBY_DATA *standby_data)
{
  standby_data->status_list = List_Create();
  standby_data->battery_data = data_battery_create();
  standby_data->now = data_datetime_create();
  standby_data->temp_date = data_date_create();
}

STANDBY_DATA *Create_StandbyData()
{
  STANDBY_DATA *standby_data = (STANDBY_DATA *)malloc(sizeof(STANDBY_DATA));
  memset(standby_data, 0, sizeof(STANDBY_DATA));
  set_envp(0, EMP_NAME, (OSADDRESS)standby_data);
  data_init(standby_data);
  return standby_data;
}

STANDBY_DATA *Get_StandbyData()
{
  STANDBY_DATA *standby_data = (STANDBY_DATA *)get_envp(0, EMP_NAME);
  if (standby_data)
    return standby_data;
  return Create_StandbyData();
}

void MoveTemp_toTextData(STANDBY_DATA *standby_data, TEXT_ITEM_DATA *item)
{
  (*item).state = standby_data->temp.state;
  (*item).mode = standby_data->temp.mode;
  (*item).align = standby_data->temp.align;
  (*item).t_color = standby_data->temp.t_color;
  (*item).h_color = standby_data->temp.h_color;
  (*item).highlight = standby_data->temp.highlight;
  (*item).font_size = standby_data->temp.font_size;
  (*item).XPos = standby_data->temp.XPos;
  (*item).YPos = standby_data->temp.YPos;
  (*item).Width = standby_data->temp.Width;
  (*item).Height = standby_data->temp.Height;
  (*item).MaxHeight = standby_data->temp.MaxHeight;
  (*item).underline = standby_data->temp.underline;
  (*item).u_color = standby_data->temp.u_color;
}

void MoveTemp_toIconData(STANDBY_DATA *standby_data, ICON_ITEM_DATA *item)
{
  (*item).state = standby_data->temp.state;
  (*item).XPos = standby_data->temp.XPos;
  (*item).YPos = standby_data->temp.YPos;
}

void MoveTemp_toStatusData(STANDBY_DATA *standby_data, STATUS_ICN_DATA *item)
{
  (*item).state = standby_data->temp.state;
  (*item).align = standby_data->temp.align;
  (*item).XPos = standby_data->temp.XPos;
  (*item).YPos = standby_data->temp.YPos;
}

void SaveData(bool save, int item)
{
  STANDBY_DATA *standby_data = Get_StandbyData();

  switch (item)
  {
  case ITEM_Statusbar:
    MoveTemp_toStatusData(standby_data, &standby_data->settings.status);
    break;
  case ITEM_NetworkIcon:
    MoveTemp_toIconData(standby_data, &standby_data->settings.net_icn);
    break;
  case ITEM_BatteryIcon:
    MoveTemp_toIconData(standby_data, &standby_data->settings.batt_icn);
    break;
  case ITEM_MusicWidget:
    MoveTemp_toIconData(standby_data, &standby_data->settings.music);
    break;

  case ITEM_StandbyClock:
    MoveTemp_toTextData(standby_data, &standby_data->settings.standbyclock);
    break;
  case ITEM_StatusClock:
    MoveTemp_toTextData(standby_data, &standby_data->settings.statusclock);
    break;
  case ITEM_Date:
    MoveTemp_toTextData(standby_data, &standby_data->settings.date);
    break;
  case ITEM_Weekday:
    MoveTemp_toTextData(standby_data, &standby_data->settings.weekday);
    break;
  case ITEM_Alarm:
    MoveTemp_toTextData(standby_data, &standby_data->settings.alarm);
    break;
  case ITEM_Profile:
    MoveTemp_toTextData(standby_data, &standby_data->settings.profile);
    break;
  case ITEM_Heap:
    MoveTemp_toTextData(standby_data, &standby_data->settings.heap);
    break;
  case ITEM_Timer:
    MoveTemp_toTextData(standby_data, &standby_data->settings.timer);
    break;
  case ITEM_Call:
    MoveTemp_toTextData(standby_data, &standby_data->settings.calltime);
    break;
  case ITEM_Signal:
    MoveTemp_toTextData(standby_data, &standby_data->settings.signal);
    break;
  case ITEM_NetworkName:
    MoveTemp_toTextData(standby_data, &standby_data->settings.opname);
    break;
  case ITEM_Batt:
    MoveTemp_toTextData(standby_data, &standby_data->settings.battery);
    break;
  case ITEM_Charge:
    MoveTemp_toTextData(standby_data, &standby_data->settings.charge);
    break;
  case ITEM_Batttemp:
    MoveTemp_toTextData(standby_data, &standby_data->settings.batttemp);
    break;
  case ITEM_Systemp:
    MoveTemp_toTextData(standby_data, &standby_data->settings.systemp);
    break;
  case ITEM_Phone:
    MoveTemp_toTextData(standby_data, &standby_data->settings.phone);
    break;
  case ITEM_Card:
    MoveTemp_toTextData(standby_data, &standby_data->settings.card);
    break;
  case ITEM_Radio:
    MoveTemp_toTextData(standby_data, &standby_data->settings.radio);
    break;
  }

  if (save)
  {
    int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_WRONLY, FSX_S_IWRITE | FSX_S_IREAD, NULL);
    if (file >= NULL)
    {
      fwrite(file, &standby_data->settings, sizeof(SETTINGS_DATA));
      fclose(file);
    }
  }
}

void LoadData(STANDBY_DATA *standby_data)
{
  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    fread(file, &standby_data->settings, sizeof(SETTINGS_DATA));
    fclose(file);
  }
}
