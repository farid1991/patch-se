#ifndef _IDISPLAYMANAGER_H_
#define _IDISPLAYMANAGER_H_

typedef struct UUID2010SAFE
{
  UUID uuid;
  UUID2010SAFE* parent;
}*PUUID2010SAFE;

#ifdef DB2010
const UUID2010SAFE IID_IDisplayManager={0x00, 0x75, 0x50, 0xC3, 0x9A, 0x1D, 0x4F, 0xA4, 0xAE, 0xC9, 0x10, 0x98, 0xD8, 0xF9, 0xDA, 0x7A, NULL};
#elif DB2020
const UUID2010SAFE IID_IDisplayManager={0xBC, 0x8E, 0xB4, 0x02, 0x3E, 0x52, 0x41, 0x3E, 0xA1, 0x19, 0x98, 0xE0, 0x9D, 0x07, 0x95, 0xE3, NULL};
#elif DB3150
const UUID2010SAFE IID_IDisplayManager={0x2F, 0x63, 0xF8, 0xC5, 0xFF, 0x23, 0x41, 0x87, 0xAC, 0xB9, 0x74, 0xA8, 0xDC, 0x57, 0x1C, 0xC3, NULL};
#elif DB3210
const UUID2010SAFE IID_IDisplayManager={0x2F, 0x63, 0xF8, 0xC5, 0xFF, 0x23, 0x41, 0x87, 0xAC, 0xB9, 0x74, 0xA8, 0xDC, 0x57, 0x1C, 0xC3, NULL};
#elif DB3350
const UUID2010SAFE IID_IDisplayManager={0x87, 0x7E, 0x94, 0x1D, 0x61, 0x27, 0x48, 0x2A, 0x9A, 0x2C, 0x1C, 0xE7, 0x6D, 0x56, 0xA5, 0x97, NULL};
#endif
const UUID CID_IDisplayManager={0x88, 0xC6, 0x4A, 0x99, 0x8D, 0x3A, 0x42, 0x48, 0xB5, 0xD4, 0x24, 0x30, 0xDD, 0x3F, 0x74, 0x17};


#ifdef DB2010
const UUID2010SAFE IID_IDisplaySession={0xE1, 0xB6, 0xF0, 0xFC, 0xBD, 0xDE, 0x44, 0x6B, 0xB8, 0xE9, 0x19, 0x1A, 0x42, 0x11, 0xA8, 0x39, NULL};
#elif DB2020
const UUID2010SAFE IID_IDisplaySession={0xB0, 0x90, 0x04, 0xAE, 0xB0, 0xA0, 0x40, 0x67, 0xBD, 0x69, 0x4B, 0xC3, 0x95, 0x82, 0xEE, 0xDF, NULL};
#elif DB3150
const UUID2010SAFE IID_IDisplaySession={0xB2, 0xB7, 0xBA, 0x91, 0x86, 0x71, 0x44, 0x3E, 0xBE, 0x29, 0xA0, 0xAB, 0x34, 0xF7, 0xC2, 0x93, NULL};
#elif DB3210
const UUID2010SAFE IID_IDisplaySession={0xDF, 0xB1, 0xE7, 0xC2, 0x6A, 0xF3, 0x44, 0x0B, 0xBB, 0xEE, 0x83, 0xD8, 0x9C, 0x91, 0x8E, 0xD4, NULL};
#elif DB3350
const UUID2010SAFE IID_IDisplaySession={0x2B, 0x9F, 0x99, 0x70, 0xA0, 0xE2, 0x4C, 0x5A, 0xBC, 0xB3, 0x45, 0x85, 0xAB, 0xB4, 0x46, 0x4A, NULL};
#endif


#ifdef DB2010
class IDisplaySession: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int get_DisplayBuffer(int x,int y, int w, int h, char* bmp);
};
#elif DB2020
class IDisplaySession: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
  virtual int get_DisplayBuffer(int x,int y, int w, int h, char* bmp);
};

#elif DB3150
class IDisplaySession: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
  virtual int get_DisplayBuffer(int x,int y, int w, int h, char* bmp);
};
#elif DB3210
class IDisplaySession: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
  virtual int method44();
  virtual int method48();
  virtual int method4c();
  virtual int get_DisplayBuffer(int x,int y, int w, int h, char* bmp);
};
#elif DB3350
class IDisplaySession: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
  virtual int method44();
  virtual int method48();
  virtual int method4c();
  virtual int method50();
  virtual int get_DisplayBuffer(int x,int y, int w, int h, char* bmp);
};
#endif

#ifdef A1
class IDisplayManager: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
  virtual int CreateDisplaySession(int,int,int,int,int, IDisplaySession** pIDisplaySession_A1);
};
#elif A2
class IDisplayManager: public IUnknown
{
public:
  virtual int method10();
  virtual int method14();
  virtual int method18();
  virtual int method1C();
  virtual int method20();
  virtual int method24();
  virtual int method28();
  virtual int method2c();
  virtual int method30();
  virtual int method34();
  virtual int method38();
  virtual int method3c();
  virtual int method40();
  virtual int method44();
  virtual int method48();
  virtual int method4c();
  virtual int method50();
  virtual int method54();
  virtual int CreateDisplaySession(int,int,int,int,int, IDisplaySession** pIDisplaySession_A2);
};
#endif

#endif
