#ifndef _IMUSIC_SERVER_H_
#define _IMUSIC_SERVER_H_

#include "..\\include\classes\IUnknown.h"

class IMusicServer: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int GetFilename1( int itemIndex, int length, wchar_t* pFilename );
  virtual int GetFilename2( int itemIndex, int length, wchar_t* pFilename );
  virtual int GetFilename3( int itemIndex, int length, wchar_t* pFilename );
  virtual int GetFilename4( int itemIndex, int length, wchar_t* pFilename );
};

#endif
