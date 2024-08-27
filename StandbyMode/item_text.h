#ifndef _ITEMTEXT_H_
#define _ITEMTEXT_H_

TEXTID Get_WeekDay(STANDBY_DATA *standby_data);

int Alarm_GetCurrentAlarmTime(STANDBY_DATA *standby_data, TIME *alarm_time);
TEXTID Get_TimerTime(BOOK* timer);
TEXTID Get_ProfileName();
TEXTID Get_FreeHeap(STANDBY_DATA *standby_data);
TEXTID Get_CurrentOperatorName();
TEXTID Get_CallTimeInfo();
TEXTID Get_SignalQuality();

TEXTID Get_BatteryCapacity(STANDBY_DATA *standby_data);
TEXTID Get_ChargerCurrent(int charger_current);
TEXTID Get_BatteryTemp(int battery_temp);
TEXTID Get_SystemTemp(int system_temp);

TEXTID Get_PhoneVolumeSize(int mode);
TEXTID Get_CardVolumeSize(int mode);

TEXTID Get_TitleTag(BOOK* book);
TEXTID Get_ArtistTag(BOOK* book);
TEXTID Get_FMRadioInfo(BOOK *book, int mode);

#endif
