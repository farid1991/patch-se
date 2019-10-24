#ifndef _IPLAYERMANAGER_H_
#define _IPLAYERMANAGER_H_

#include "IMMETypes.h"

//UUID CID_CPlayerManager = {0xB0, 5, 0xD9, 0x16, 8, 0x3D, 0x4B, 0x19, 0x9D, 0x98, 0xD0, 0x2A, 0x17, 0xE, 0x83, 0xA3};
//UUID IID_IPlayerManager = {0xAE, 0xAA, 0xD8, 0xE7, 0x81, 0x82, 0x48, 0x75, 0x8D, 0xB, 0xD3, 0xDD, 0x7F, 0xF9, 0xA6, 0x39};

/*
14C4CE2C
*/

/*
IPlayerManager_CreateStreamingAudioPlayer
IPlayerManager_CreateStreamingVideoPlayer
IPlayerManager_ExtractVideoFrame
IPlayerManager_ReleaseStreamProperties
IPlayerManager_CreateSynthesizer
IPlayerManager_GetAudioDecoderFormats
IPlayerManager_CreateVideoPlayer
IPlayerManager_CreateAudioPlayer
IPlayerManager_GetMultimediaFormats
*/

class ISome_3: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int unk_0x20(char* format);
  virtual int unk_0x24();
  virtual int unk_0x28(void);
};

class ISome_2: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14(ISome_3** pISome_3);
};

class ISome_4: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14(void* unk);
};

class IPlayerManager: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14(int unk_1, int unk_2, void unk_3);
  virtual int unk_0x18(int unk_1, int unk_2, void unk_3);
  virtual int unk_0x1C();
  virtual int unk_0x20();
  virtual int unk_0x24();
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int unk_0x30(int unk);
  virtual int unk_0x34();
  virtual int unk_0x38(int unk);
  virtual int unk_0x3C();
  virtual int unk_0x40();
  virtual int unk_0x44(); //CreateVideoPlayer
  virtual int unk_0x48();
  virtual int unk_0x4C();
  virtual int unk_0x50(int unk);
  virtual int unk_0x54(int unk);
  virtual int unk_0x58(ISome_4** pISome_4);
  virtual int unk_0x5C();
  virtual int unk_0x60(void unk, wchar_t* fullpath, void unk);
  virtual int GetFileProperties(char codec, wchar_t* fullpath, void* unk_2, TMMEMediaProperties* mediaProperties);
  virtual int unk_0x68();
  virtual int unk_0x6C();
  virtual int unk_0x70(ISome_2** pISome_2);
  virtual int unk_0x74();
  virtual int unk_0x78();
  virtual int unk_0x7C();
  virtual int unk_0x80();
  virtual int unk_0x84();
  virtual int unk_0x88();
};

#endif
