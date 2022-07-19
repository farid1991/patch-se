#ifndef _IMUSIC_SERVER_H_
#define _IMUSIC_SERVER_H_

#include "IUnknown.h"

#include "..\types\MusicServer_types.h"

#if defined(DB3150v1)
class IMusicServer : public IUnknown
{
public:
  virtual void *unk_0x10();
  virtual void *unk_0x14();
  virtual void *unk_0x18();
  virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
  virtual int GetFocusedItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle, wchar_t *pFilename, TMusicServer_Time *pPlaylength, TMusicServer_Time *pResumePosition, TBool *pContainsAlbumart, TBool *pIsRealMediaFile);
  virtual int GetFilename(FUint32 itemIndex, FUint32 length, wchar_t *pFilename);
  virtual void *unk_0x28();                                                          // 0x28
  virtual void *unk_0x2C();                                                          // 0x2C
  virtual int GetState(char *State);                                                 // 0x30
  virtual int Play(FUint32 itemIndex);                                               // 0x34
  virtual int Pause(void);                                                           // 0x38
  virtual int FastFoward(void);                                                      // 0x3c
  virtual int Rewind(void);                                                          // 0x40
  virtual int Next(TBool activePress);                                               // 0x44
  virtual int Previous(void);                                                        // 0x48
  virtual int SetApplicationWindowMode(TBool maximized);                             // 0x4C
  virtual int SetStereoWidening(TBool enable);                                       // 0x50
  virtual void *unk_0x54();                                                          // 0x54
  virtual int SetEqualizerGain(int band, int level);                                 // 0x58
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, TBool setting); // 0x5C
  virtual int SetSettings_String(wchar_t *pSettingString);                           // 0x60
  virtual int SetSettings_Int(FUint16 setting);                                      // 0x64
  virtual int SetSettings_Time(TMusicServer_Time settingTime);                       // 0x68
  virtual void *unk_0x6C();                                                          // 0x6C
  virtual void *unk_0x70();                                                          // 0x70
  virtual void *unk_0x74();                                                          // 0x74
  virtual void *unk_0x78();                                                          // 0x78
  virtual int RemoveFromPlaylist(FUint32 itemIndex);                                 // 0x7C
  virtual int SavePlayQueue(wchar_t *pPlaylistname);                                 // 0x80
};
#elif defined(DB3150v2)
class IMusicServer : public IUnknown
{
public:
  virtual void *unk_0x10();
  virtual void *unk_0x14();
  virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);                                                                                                                                                   // 0x18
  virtual int GetFocusedItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle, wchar_t *pFilename, TMusicServer_Time *pPlaylength, TMusicServer_Time *pResumePosition, TBool *pContainsAlbumart, TBool *pIsRealMediaFile); // 0x1C
  virtual int GetFilename(FUint32 itemIndex, FUint32 length, wchar_t *pFilename);                                                                                                                                                                               // 0x20
  virtual void *unk_0x24();                                                                                                                                                                                                                                     // 0x24
  virtual int Play(int itemIndex);                                                                                                                                                                                                                              // 0x28
  virtual int Pause(void);                                                                                                                                                                                                                                      // 0x2C
  virtual int FastFoward(void);                                                                                                                                                                                                                                 // 0x30
  virtual int Rewind(void);                                                                                                                                                                                                                                     // 0x34
  virtual int Next(TBool activePress);                                                                                                                                                                                                                          // 0x38
  virtual int Previous(void);                                                                                                                                                                                                                                   // 0x3C
  virtual int SetApplicationWindowMode(TBool maximized);                                                                                                                                                                                                        // 0x40
  virtual int SetStereoWidening(TBool enable);                                                                                                                                                                                                                  // 0x44
  virtual int EnableEqualizer(void);                                                                                                                                                                                                                            // 0x48
  virtual int DisableEqualizer(void);                                                                                                                                                                                                                           // 0x4C
  virtual int SetEqualizerGain(int band, int level);                                                                                                                                                                                                            // 0x50
  virtual int SetEqualizerPreset(int equalizerPreset);                                                                                                                                                                                                          // 0x54
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, TBool setting);                                                                                                                                                                            // 0x58
  virtual int SetSettings_String(wchar_t *pSettingString);                                                                                                                                                                                                      // 0x5C
  virtual int SetSettings_Int(FUint16 setting);                                                                                                                                                                                                                 // 0x60
  virtual int SetSettings_Time(TMusicServer_Time settingTime);                                                                                                                                                                                                  // 0x64
  virtual int RemoveFromPlaylist(int itemIndex);                                                                                                                                                                                                                // 0x68
  virtual int SavePlayQueue(wchar_t *pPlaylistname);                                                                                                                                                                                                            // 0x6C
};
#elif defined(DB3200) || defined(DB3210)
class IMusicServer : public IUnknown
{
public:
  virtual int StartMusicServer(IUnknown *pICBMusicServer, FUint16 msgBase, FUint32 clientData, char StartMode, FUint32 itemIndex);
  virtual int Destroy(FUint32 subscriptionHandle);
  virtual int Subscribe(IUnknown *pICBMusicServer, FUint16 msgBase, FUint32 clientData, FUint32 *pSubscriptionHandle);
  virtual int Unsubscribe(FUint32 subscriptionHandle);
  virtual int StartApplication(TMusicServer_Action action);
  virtual int StopApplication(void);
  virtual int SetPurchaseFlag(void);
  virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
  virtual int GetFocusedItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle, wchar_t *pFilename, TMusicServer_Time *pPlaylength, TMusicServer_Time *pResumePosition, TBool *pContainsAlbumart, TBool *pIsRealMediaFile);
  virtual int GetFilename(FUint32 itemIndex, FUint32 length, wchar_t *pFilename);
  virtual int GetAlbumArt(FUint32 itemIndex, FUint32 length, wchar_t *pFilename, FUint32 *Offset, FUint32 *Size, TMusicServer_AlbumArt_ImageType *pImageType, TBool *IsDRMProtected);
  virtual int GetState(char *State);
  virtual int Play(FUint32 itemIndex);
  virtual int Pause(void);
  virtual int FastFoward(void);
  virtual int Rewind(void);
  virtual int Next(TBool activePress);
  virtual int Previous(void);
  virtual int SetElapsedTime(TMusicServer_Time time);
  virtual int GetElapsedTime(TMusicServer_Time *time);
  virtual int SetWindowMode(char mode);
  virtual int SetStarted(TBool started);
  virtual int SetStereoWidening(TBool enable);
  virtual int EnableEqualizer(void);
  virtual int DisableEqualizer(void);
  virtual int SetEqualizerGain(int band, int level);
  virtual int SetEqualizerPreset(int equalizerPreset);
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, TBool setting);
  virtual int SetSettings_String(wchar_t *pSettingString);
  virtual int SetSettings_Int(FUint16 setting);
  virtual int SetSettings_Time(TMusicServer_Time settingTime);
  virtual int SkipTrack(void);
  virtual int RemoveFromPlaylist(FUint32 itemIndex);
  virtual int SavePlayQueue(wchar_t *pPlaylistname);
};
#elif defined(DB3350)
class IMusicServer : public IUnknown
{
public:
  virtual void *unk_0x10();
  virtual void *unk_0x14();
  virtual void *unk_0x18();
  virtual void *unk_0x1C();
  virtual void *unk_0x20();
  virtual void *unk_0x24();
  virtual void *unk_0x28();
  virtual void *unk_0x2C();
  virtual void *unk_0x30();
  virtual void *unk_0x34();
  virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
  virtual void *unk_0x3C();
  virtual void *unk_0x40();
  virtual void *unk_0x44();
  virtual void *unk_0x48();
  virtual void *unk_0x4C();
  virtual void *unk_0x50();
  virtual void *unk_0x54();
  virtual void *unk_0x58();
  virtual int Play(FUint32 itemIndex);                  // 0x5C
  virtual int Pause(void);                              // 0x60
  virtual int FastFoward(void);                         // 0x64
  virtual int Rewind(void);                             // 0x68
  virtual int Next(TBool activePress);                  // 0x6C
  virtual int Previous(void);                           // 0x70
  virtual int SetApplicationWindowMode(BOOL maximized); // 0x74
  virtual void *unk_0x78();
  virtual void *unk_0x7C();
  virtual void *unk_0x80();
  virtual void *unk_0x84();
  virtual void *unk_0x88();
  virtual void *unk_0x8C();
  virtual void *unk_0x90();
  virtual void *unk_0x94();
  virtual void *unk_0x98();
  virtual void *unk_0x9C();
  virtual void *unk_0xA0();
  virtual int RemoveFromPlaylist(FUint32 itemIndex);
  virtual int SavePlayQueue(wchar_t *name);
};
#endif

class IMusicServerManager : public IUnknown
{
public:
  virtual int CreateMusicServer(void *pICBMusicServer, IMusicServer **ppIMusicServer);
  virtual int method1();
};

#endif
