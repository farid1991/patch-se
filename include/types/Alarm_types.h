#ifndef __ALARM_TYPES_H__
#define __ALARM_TYPES_H__

typedef enum
{
  AlarmSignalMode_Signal = 0,
  AlarmSignalMode_Radio
} AlarmSignalMode;

typedef enum
{
  AlarmVolume_Loud = 0,
  AlarmVolume_Normal,
  AlarmVolume_Modest,
  AlarmVolume_Discreet
} AlarmVolume;

typedef enum
{
  AlarmSilentMode_AlarmSound = 0,
  AlarmSilentMode_NoAlarmSound
} AlarmSilentMode;

typedef enum
{
  AlarmType_Recurrent = 0,
  AlarmType_Regular
} AlarmType;

typedef enum
{
  AlarmSnoozeDuration_10min = 0,
  AlarmSnoozeDuration_3min,
  AlarmSnoozeDuration_5min,
  AlarmSnoozeDuration_7min,
  AlarmSnoozeDuration_15min,
  AlarmSnoozeDuration_30min
} AlarmSnoozeDuration;

typedef struct
{
  char state;
  char days[7];
} AlarmWeek;

#endif
