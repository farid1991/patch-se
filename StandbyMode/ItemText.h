#ifndef _ITEMTEXT_H_
#define _ITEMTEXT_H_

TEXTID Get_Time(STANDBY_DATA *standby_data, int mode);
TEXTID Get_Date(STANDBY_DATA *standby_data, int mode);
TEXTID Get_WeekDay(STANDBY_DATA *standby_data, int mode);

int Alarm_GetCurrentAlarmTime(STANDBY_DATA *standby_data, TIME *alarm_time);
TEXTID Get_TimerTime(BOOK* timer);
TEXTID Get_ProfileName();
TEXTID Get_FreeHeap(int mode);
TEXTID Get_CurrentOperatorName();
TEXTID Get_CallTimeInfo();
TEXTID Get_SignalQuality();

TEXTID Get_BatteryCapacity(int mode);
TEXTID Get_ChargerCurrent();
TEXTID Get_BatteryTemp();
TEXTID Get_SystemTemp();

TEXTID Get_PhoneVolumeSize(int mode);
TEXTID Get_CardVolumeSize(int mode);

TEXTID Get_TitleTag(BOOK* book);
TEXTID Get_ArtistTag(BOOK* book);
TEXTID Get_FMRadioInfo(BOOK *book, int mode);

#endif
