#ifndef _ICLOCKMANAGER_H_
#define _ICLOCKMANAGER_H_

//UUID CID_CClockManager = {0x1C, 0x3F, 0, 0x73, 0x97, 0xA4, 0x48, 0xDF, 0x96, 0xE9, 0x5C, 0x72, 0xA6, 0xE6, 0x31, 0x4E};
//UUID IID_IClockManager = {0xB3, 0x8A, 0xA0, 0x98, 0x3B, 0xB9, 0x4E, 0x2A, 0xA1, 0xA2, 0xED, 0x3E, 0x1C, 0x6A, 0x84, 0xC};

class IClock: public IUnknown
{
public:
  virtual int SetDate(DATE* date);
  virtual int GetDate(DATE* date);
  virtual int SetTime(TIME* time);
  virtual int GetTime(TIME* time);
  virtual int SetDateAndTime(DATETIME* datetime);
  virtual int GetDateAndTime(DATETIME* datetime);
  virtual int GetDateAndUTCTime(DATETIME* datetime);
  virtual int GetTimeZone(char* timezone);
  virtual int SetTimeZone(char* timezone);
  virtual int GetDaylightSaving(char* ds);
  virtual int SetDaylightSaving(char* ds);
};

class IClockManager: public IUnknown
{
public:
  virtual int CreateClock(IClock** pIClock);
  virtual int CreateMonotonicClock(IUnknown** pIMonotonicClock);
  virtual int CreateSecureClock(IUnknown** pISecureClock);
};

#endif
