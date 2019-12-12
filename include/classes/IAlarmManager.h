#ifndef _IALARMMANAGER_H_
#define _IALARMMANAGER_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\IAlarm_types.h"

class IAlarmItem: public IRoot
{
public:
    virtual int unk_0x10();
    virtual int unk_0x14();
    virtual int SetTime(TIME* time, FUint16 ItemNumber);                                                         // 0x18
    virtual int GetTime(TIME* time, FUint16 ItemNumber);                                                         // 0x1C
    virtual int unk_0x20();                                                                                      // 0x20
    virtual int SetState(TAscii state, FUint16 ItemNumber);                                                      // 0x24
    virtual int GetState(TAscii* state, FUint16 ItemNumber);                                                     // 0x28
    virtual int unk_0x2C();                                                                                      // 0x2C
    virtual int SetSignalSound(TChar* pathname, FUint16 pathlen, AlarmSignalMode signal, FUint16 ItemNumber);    // 0x30  // maxlen = 0xFF
    virtual int GetSignalSound(TChar* pathname, FUint16* pathlen, AlarmSignalMode* signal, FUint16 ItemNumber);  // 0x34
    virtual int SetImage(TChar* pathname, FUint16 pathlen, FUint16 ItemNumber);                                  // 0x38  // maxlen = 0xFF
    virtual int GetImage(TChar* pathname, FUint16* pathlen, FUint16 ItemNumber);                                 // 0x3C
    virtual int SetText(TChar* text, u16 namelen, FUint16 ItemNumber);                                           // 0x40  // maxlen = 20
    virtual int GetText(TChar* text, u16* namelen, FUint16 ItemNumber);                                          // 0x44
    virtual int SetSilentMode(AlarmSilentMode* silent, u16 ItemNumber);                                          // 0x48
    virtual int SetSnoozeDuration(AlarmSnoozeDuration* duration, FUint16 ItemNumber);                            // 0x4C
    virtual int GetSnoozeDuration(AlarmSnoozeDuration* duration, FUint16 ItemNumber);                            // 0x50
    virtual int SetVolume(AlarmVolume* volume, FUint16 ItemNumber);                                              // 0x54
    virtual int GetVolume(AlarmVolume* volume, FUint16 ItemNumber);                                              // 0x58
    virtual int GetSilentMode(AlarmSilentMode* silent, FUint16 ItemNumber);                                      // 0x5C
    virtual int SetTimeState(TAscii* state, FUint16 ItemNumber);                                                 // 0x60
    virtual int GetTimeState(TAscii* state, FUint16 ItemNumber);                                                 // 0x64
};

class IAlarmWeek: public IRoot
{
public:
    virtual int SetWeek(AlarmRecurrentState state, FUint16 ItemNumber);
    virtual int GetWeek(AlarmRecurrentState* state, FUint16 ItemNumber);
};

class IAlarmTime : public IRoot
{
public:
  virtual int unk0();
  virtual int unk1();
  virtual int GetTimeFormat( TAscii* pTimeFormat );
};

class IAlarmManager : public IRoot
{
public:
    virtual int CreateAlarmItem(IAlarmItem** ppIAlarmItem);
    virtual int CreateAlarmWeek(IAlarmWeek** ppIAlarmWeek);
    virtual int CreateAlarmTime(IAlarmTime** ppIAlarmTime);
};
  
#endif
