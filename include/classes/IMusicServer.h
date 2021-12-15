#ifndef _IMUSIC_SERVER_H_
#define _IMUSIC_SERVER_H_

#include "IUnknown.h"

#if defined(DB3150v1)
class IMusicServer : public IUnknown
{
public:
  virtual uint32_t unk_0x10();
  virtual uint32_t unk_0x14();
  virtual uint32_t unk_0x18();
  virtual uint32_t GetItem(uint32_t itemIndex, uint32_t length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
  virtual uint32_t GetFocusedItem(uint32_t itemIndex, uint32_t length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle, wchar_t *pFilename, TMusicServer_Time *pPlaylength, TMusicServer_Time *pResumePosition, BOOL *pContainsAlbumart, BOOL *pIsRealMediaFile);
  virtual uint32_t GetFilename(uint32_t itemIndex, uint32_t length, wchar_t *pFilename);
  virtual uint32_t unk_0x28();
  virtual uint32_t unk_0x2C();
  virtual uint32_t unk_0x30();
  virtual uint32_t Play(uint32_t itemIndex);                 //0x34
  virtual uint32_t Pause(void);                              //0x38
  virtual uint32_t FastFoward(void);                         //0x3c
  virtual uint32_t Rewind(void);                             //0x40
  virtual uint32_t Next(BOOL activePress);                   //0x44
  virtual uint32_t Previous(void);                           //0x48
  virtual uint32_t SetApplicationWindowMode(BOOL maximized); // unk_0x4C();
  virtual uint32_t unk_0x50();
  virtual uint32_t unk_0x54();
  virtual uint32_t SetEqualizerGain(uint32_t equalizerBand, int32_t equalizerGain);
  virtual uint32_t SetSettings_Boolean(TMusicServer_Settings settingType, BOOL setting); //void* unk_0x5C();
  virtual uint32_t SetSettings_Int(uint16_t setting);                                     //void* unk_0x60();
  virtual uint32_t unk_0x64();
  virtual uint32_t SetSettings_Time(TMusicServer_Time settingTime);                       // unk_0x68();
  virtual uint32_t GetSettings_Boolean(TMusicServer_Settings settingType, BOOL *setting); //unk_0x6C();
  virtual uint32_t GetCurrentItemIndex(uint32_t *itemIndex);                              //unk_0x70();
  virtual uint32_t unk_0x74();
  virtual uint32_t GetTime(TMusicServer_Time *time); //0x78;
  virtual uint32_t RemoveFromPlaylist(uint32_t itemIndex);
  virtual uint32_t SavePlayQueue(wchar_t *pPlaylistname);
};

#elif defined(DB3350)
class IMusicServer : public IUnknown
{
public:
  virtual uint32_t unk_0x10();
  virtual uint32_t unk_0x14();
  virtual uint32_t unk_0x18();
  virtual uint32_t unk_0x1C();
  virtual uint32_t unk_0x20();
  virtual uint32_t unk_0x24();
  virtual uint32_t unk_0x28();
  virtual uint32_t unk_0x2C();
  virtual uint32_t unk_0x30();
  virtual uint32_t unk_0x34();
  virtual uint32_t GetItem(uint32_t itemIndex, uint32_t length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
  virtual uint32_t unk_0x3C();
  virtual uint32_t unk_0x40();
  virtual uint32_t unk_0x44();
  virtual uint32_t unk_0x48();
  virtual uint32_t unk_0x4C();
  virtual uint32_t unk_0x50();
  virtual uint32_t unk_0x54();
  virtual uint32_t unk_0x58();
  virtual uint32_t Play(uint32_t itemIndex); //0x5C OK
  virtual uint32_t Pause(void);              //0x60 OK
  virtual uint32_t FastFoward(void);         //0x64 OK
  virtual uint32_t Rewind(void);             //0x68 OK
  virtual uint32_t Next(BOOL activePress);   //0x6C
  virtual uint32_t Previous(void);           //0x70
  virtual uint32_t SetApplicationWindowMode(BOOL maximized);
  virtual uint32_t unk_0x78();
  virtual uint32_t unk_0x7C();
  virtual uint32_t unk_0x80();
  virtual uint32_t unk_0x84();
  virtual uint32_t unk_0x88();
  virtual uint32_t unk_0x8C();
  virtual uint32_t unk_0x90();
  virtual uint32_t unk_0x94();
  virtual uint32_t unk_0x98();
  virtual uint32_t unk_0x9C();
  virtual uint32_t unk_0xA0();
  virtual uint32_t RemoveFromPlaylist(uint32_t itemIndex);
  virtual uint32_t SavePlaylist(wchar_t *name);
};
#endif

#endif
