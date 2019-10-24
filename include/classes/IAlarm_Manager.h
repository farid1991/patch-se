#ifndef _IALARM_H_
#define _IALARM_H_

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

class IAlarm: public IUnknown
{
public:
    virtual void* unk_0x10();
    virtual void* unk_0x14();
    virtual int SetTime(TIME* time, u16 number);                                                 // 0x18
    virtual int GetTime(TIME* time, u16 number);                                                 // 0x1C
    virtual void* unk_0x20();                                                                     // 0x20
    virtual int SetState(char state, u16 number);                                                 // 0x24
    virtual int GetState(char* state, u16 number);                                               // 0x28
    virtual void* unk_0x2C();                                                                     // 0x2C
    virtual int SetSignalSound(wchar_t* pathname, u16 pathlen, AlarmSignalMode signal, u16 number);     // 0x30  // maxlen = 0xFF
    virtual int GetSignalSound(wchar_t* pathname, u16* pathlen, AlarmSignalMode* signal, u16 number);  // 0x34
    virtual int SetImage(wchar_t* pathname, u16 pathlen, u16 number);                            // 0x38  // maxlen = 0xFF
    virtual int GetImage(wchar_t* pathname, u16* pathlen, u16 number);                          // 0x3C
    virtual int SetName(wchar_t* name, u16 namelen, u16 number);                                 // 0x40  // maxlen = 20
    virtual int GetName(wchar_t* name, u16* namelen, u16 number);                               // 0x44
    virtual int SetSilentMode(AlarmSilentMode* silent, u16 number);                                      // 0x48
    virtual int SetSnoozeDuration(AlarmSnoozeDuration* duration, u16 number);                              // 0x4C
    virtual int GetSnoozeDuration(AlarmSnoozeDuration* duration, u16 number);                              // 0x50
    virtual int SetVolume(AlarmVolume* volume, u16 number);                                              // 0x54
    virtual int GetVolume(AlarmVolume* volume, u16 number);                                              // 0x58
    virtual int GetSilentMode(AlarmSilentMode* silent, u16 number);                                      // 0x5C
    virtual int SetTimeState(char* state, u16 number);                                           // 0x60
    virtual int GetTimeState(char* state, u16 number);                                           // 0x64
};

class IAlarm2: public IUnknown
{
public:
    virtual int SetRecurrent(AlarmRecurrentState state, u16 number);
    virtual int GetRecurrent(AlarmRecurrentState* state, u16 number);
};

class IAlarm_Manager: public IUnknown
{
public:
    virtual int CreateIAlarm(IAlarm** ppIAlarm);
    virtual int CreateIAlarm2(IAlarm2** ppIAlarm2);
    virtual void* unk_0x18(void**);
};

#endif
