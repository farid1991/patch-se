#ifndef _IALARMMANAGER_H_
#define _IALARMMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\Alarm_types.h"

// UUID CID_CAlarmManager = {0xB0, 0x68, 0xDA, 0xA4, 0x3C, 0x8B, 0x4C, 0x26, 0x81, 0xF5, 0x7E, 0x01, 0x2C, 0x2B, 0xF9, 0xCC};
// UUID IID_IAlarmManager = {0x45, 0x4B, 0xC2, 0x06, 0x9A, 0x26, 0x4B, 0x7B, 0xA0, 0x55, 0x3D, 0xEA, 0x78, 0xCE, 0x60, 0x5C};

class IAlarmItem : public IUnknown
{
public:
  virtual void *unk_0x10();
  virtual void *unk_0x14();
  virtual int SetTime(TIME *time, uint16_t number);                                                           // 0x18
  virtual int GetTime(TIME *time, uint16_t number);                                                           // 0x1C
  virtual void *unk_0x20();                                                                                   // 0x20
  virtual int SetState(char state, uint16_t number);                                                          // 0x24
  virtual int GetState(char *state, uint16_t number);                                                         // 0x28
  virtual void *unk_0x2C();                                                                                   // 0x2C
  virtual int SetSignalSound(wchar_t *fullpath, uint16_t pathlen, AlarmSignalMode signal, uint16_t number);   // 0x30  // maxlen = 0xFF
  virtual int GetSignalSound(wchar_t *fullpath, uint16_t *pathlen, AlarmSignalMode *signal, uint16_t number); // 0x34
  virtual int SetImage(wchar_t *fullpath, uint16_t pathlen, uint16_t number);                                 // 0x38  // maxlen = 0xFF
  virtual int GetImage(wchar_t *fullpath, uint16_t *pathlen, uint16_t number);                                // 0x3C
  virtual int SetName(wchar_t *name, uint16_t namelen, uint16_t number);                                      // 0x40  // maxlen = 20
  virtual int GetName(wchar_t *name, uint16_t *namelen, uint16_t number);                                     // 0x44
  virtual int SetSilentMode(AlarmSilentMode *silent, uint16_t number);                                        // 0x48
  virtual int SetSnoozeDuration(AlarmSnoozeDuration *duration, uint16_t number);                              // 0x4C
  virtual int GetSnoozeDuration(AlarmSnoozeDuration *duration, uint16_t number);                              // 0x50
  virtual int SetVolume(AlarmVolume *volume, uint16_t number);                                                // 0x54
  virtual int GetVolume(AlarmVolume *volume, uint16_t number);                                                // 0x58
  virtual int GetSilentMode(AlarmSilentMode *silent, uint16_t number);                                        // 0x5C
  virtual int SetTimeState(char *state, uint16_t number);                                                     // 0x60
  virtual int GetTimeState(char *state, uint16_t number);                                                     // 0x64
};

class IAlarmRecurrent : public IUnknown
{
public:
  virtual int SetRecurrent(AlarmWeek state, uint16_t number);
  virtual int GetRecurrent(AlarmWeek *state, uint16_t number);
};

class IAlarmTime : public IUnknown
{
public:
  virtual void *unk_0x10();
  virtual void *unk_0x14();
  virtual int GetTimeFormat(char *format);
};

class IAlarmManager : public IUnknown
{
public:
  virtual int CreateAlarmItem(IAlarmItem **ppIAlarmItem);
  virtual int CreateAlarmRecurrent(IAlarmRecurrent **ppIAlarmRecurrent);
  virtual int CreateAlarmTime(IAlarmTime **ppIAlarmTime);
};

#endif
