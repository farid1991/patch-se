#ifndef _IALARM_TYPES_H_
#define _IALARM_TYPES_H_

//UUID CID_CAlarm_Manager = {};
//UUID IID_IAlarm_Manager = {};

typedef enum
{
  AlarmSignalMode_Signal = 0,
  AlarmSignalMode_Radio
}AlarmSignalMode;

typedef enum
{
  AlarmVolume_Loud = 0,
  AlarmVolume_Normal,
  AlarmVolume_Modest,
  AlarmVolume_Discreet
}AlarmVolume;

typedef enum
{
  AlarmSilentMode_AlarmSound = 0,
  AlarmSilentMode_NoAlarmSound
}AlarmSilentMode;

typedef enum
{
  AlarmSnoozeDuration_10min = 0,
  AlarmSnoozeDuration_3min,
  AlarmSnoozeDuration_5min,
  AlarmSnoozeDuration_7min,
  AlarmSnoozeDuration_15min,
  AlarmSnoozeDuration_30min
}AlarmSnoozeDuration;

typedef struct
{
  char State;
  char Monday;
  char Tuesday;
  char Wednesday;
  char Thursday;
  char Friday;
  char Saturday;
  char Sunday;
}AlarmRecurrentState;

typedef struct
{
  TIME time;
  wchar_t AlarmSignalSound[0xFC];
  wchar_t AlarmImage[0xFC];
  wchar_t AlarmText[0x15];
  char RecurrentState[7];
  char SignalMode;
  bool AlarmState;
  bool SilentMode;
  bool TimeState; 
} ALARM;

#endif
