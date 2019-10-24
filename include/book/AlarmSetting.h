typedef struct
{
  char state;
  char hour_0;
  char min_0;
  char sec_0;
  char hour_1;
  char min_1;
  char sec_1;
  char enable_repeat;
  char repeat_mon;
  char repeat_tur;
  char repeat_wed;
  char repeat_thu;
  char repeat_fri;
  char repeat_sat;
  char repeat_sun;
  char dummy_3;
  wchar_t alarm_picture[252];
  wchar_t alarm_sound[252];
  wchar_t alarm_text[23];
}AlarmID;

typedef struct _AlarmData
{
  AlarmID 1;
  AlarmID 2;
  AlarmID 3;
  AlarmID 4;
  AlarmID 5;
}AlarmData;