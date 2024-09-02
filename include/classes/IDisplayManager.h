#ifndef _IDISPLAYMANAGER_H_
#define _IDISPLAYMANAGER_H_

#include "..\types\Basic_types.h"

#define DISPLAY_VERSION_LEN 45

typedef struct
{
  int unk_10;
  int width;
  int height;
  int unk_1;
  int null_2;
  char unk[0xAC];
  wchar_t driver_version[DISPLAY_VERSION_LEN];
} TDisplayManagerInfo;

class IDisplaySession : public IUnknown
{
public:
  virtual int method10();
  virtual int method14(int width, int height, int bpp);
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
#if defined(DB2000) || defined(DB2010)
  virtual int GetDisplayBuffer(int x, int y, int width, int height, FUint8 *buffer);
#elif defined(DB2020) || defined(DB3150)
  virtual int method3c();
  virtual int method40();
  virtual int GetDisplayBuffer(int x, int y, int width, int height, FUint8 *buffer);
#elif defined(DB3210)
  virtual int method3c();
  virtual int method40();
  virtual int method44();
  virtual int method48();
  virtual int method4c();
  virtual int GetDisplayBuffer(int x, int y, int width, int height, FUint8 *buffer);
#elif defined(DB3350)
  virtual int method3c();
  virtual int method40();
  virtual int method44();
  virtual int method48();
  virtual int method4c();
  virtual int method50(int *x);
  virtual int GetDisplayBuffer(int x, int y, int width, int height, FUint8 *buffer);
#endif
};

class IDisplayManager : public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int GetInfo(UI_Display_t display, TDisplayManagerInfo *info);
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
#ifdef A2
  virtual int method44();
  virtual int method48();
  virtual int method4c();
  virtual int method50();
  virtual int method54();
#endif
  virtual int CreateDisplaySession(int, int, int, int, int, IDisplaySession **pIDisplaySession);
#ifdef A1
  virtual int method48();
  virtual int method4c();
  virtual int method50();
  virtual int method54();
#endif
};

#endif
