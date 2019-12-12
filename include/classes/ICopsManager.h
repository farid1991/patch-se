#ifndef _ICOPSMANAGER_H_
#define _ICOPSMANAGER_H_

const UUID CID_CCopsManager = {0xA8, 0xB8, 0x92, 0x61, 0xB0, 0x06, 0x4F, 0x5B, 0xBC, 0x57, 0xA1, 0xC6, 0xF1, 0x2C, 0x06, 0x02};
const UUID IID_ICopsManager = {0xFC, 0x49, 0x8A, 0x1A, 0xAF, 0x4B, 0x42, 0xC2, 0x80, 0x12, 0x98, 0x45, 0x12, 0x10, 0xFC, 0x31};

typedef struct
{
  int unk1;
  int Net;            // 0 - unlock;
  char unk_1[0x18];
  int SubNet;         // 0 - unlock;
}TSimLockProperties;  //size 0x98?

typedef enum
{
  PHONELOCK_OFF,
  PHONELOCK_ON,
  PHONELOCK_AUTO,
  PHONELOCK_UNAVAILABLE
}TPhoneLockStatus;

class ISimLock: public IRoot
{
public:
  virtual int unk_0x10();
  virtual int SimLockProperties( TSimLockProperties* pSimLockProperties );
  virtual int unk_0x18();
};

class IPhoneLock: public IRoot
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int PhoneLockStatus( TPhoneLockStatus* pPhoneLockStatus );
};

class ICopsManager: public IRoot
{
public:
  virtual int CreateSimLock( ISimLock** pISimLock );
  virtual int CreatePhoneLock( IPhoneLock** pIPhoneLock );
  virtual int unk_0x18();
  virtual int GetIMEI( char* pIMEI );
};

#endif
