#ifndef _IMUSIC_SERVER_H_
#define _IMUSIC_SERVER_H_

#include "..\\include\classes\IUnknown.h"

class IMusicServer : public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int unk_0x20();
  virtual int unk_0x24();
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int unk_0x30();
  virtual int unk_0x34();
  virtual int unk_0x38();
  virtual int unk_0x3C();
  virtual int unk_0x40();
  virtual int unk_0x44();
  virtual int unk_0x48();
  virtual int unk_0x4C();
  virtual int unk_0x50();
  virtual int unk_0x54();
  virtual int unk_0x58();
  virtual int unk_0x5c();
  virtual int unk_0x60();
  virtual int FastFoward(void);       //0x64
  virtual int Rewind(void);           //0x68
  virtual int Next(BOOL activePress); //0x6C
  virtual int Previous(void);         //0x70
};

#endif
