#ifndef _IMUSICSERVERMANAGER_H_
#define _IMUSICSERVERMANAGER_H_

#include "..\types\Basic_types.h"
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
  virtual void *unk_0x28();
  virtual void *unk_0x2C();
  virtual int GetState(TMusicServer_State *State);                                   // 0x30
  virtual int Play(FUint32 itemIndex);                                               // 0x34
  virtual int Pause(void);                                                           // 0x38
  virtual int FastFoward(void);                                                      // 0x3c
  virtual int Rewind(void);                                                          // 0x40
  virtual int Next(TBool activePress);                                               // 0x44
  virtual int Previous(void);                                                        // 0x48
  virtual int SetApplicationWindowMode(TBool maximized);                             // 0x4C
  virtual int SetStereoWidening(TBool enable);                                       // 0x50
  virtual void *unk_0x54();                                                          // 0x54
  virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);             // 0x58
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
  virtual void *unk_0x24();
  virtual int Play(FUint32 itemIndex);                                               // 0x28
  virtual int Pause(void);                                                           // 0x2C
  virtual int FastFoward(void);                                                      // 0x30
  virtual int Rewind(void);                                                          // 0x34
  virtual int Next(TBool activePress);                                               // 0x38
  virtual int Previous(void);                                                        // 0x3C
  virtual int SetApplicationWindowMode(TBool maximized);                             // 0x40
  virtual int SetStereoWidening(TBool enable);                                       // 0x44
  virtual int EnableEqualizer(void);                                                 // 0x48
  virtual int DisableEqualizer(void);                                                // 0x4C
  virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);             // 0x50
  virtual int SetEqualizerPreset(TMusicServer_EqPreset equalizerPreset);             // 0x54
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, TBool setting); // 0x58
  virtual int SetSettings_String(wchar_t *pSettingString);                           // 0x5C
  virtual int SetSettings_Int(FUint16 setting);                                      // 0x60
  virtual int SetSettings_Time(TMusicServer_Time settingTime);                       // 0x64
  virtual int RemoveFromPlaylist(int itemIndex);                                     // 0x68
  virtual int SavePlayQueue(wchar_t *pPlaylistname);                                 // 0x6C
};
#elif defined(DB3200) || defined(DB3210)
class IMusicServer : public IUnknown
{
public:
  virtual int StartMusicServer(IUnknown *pICBMusicServer, FUint16 msgBase, FUint32 clientData, char StartMode, FUint32 itemIndex);                                                                                                                              // 0x10
  virtual int Destroy(FUint32 subscriptionHandle);                                                                                                                                                                                                              // 0x14
  virtual int Subscribe(IUnknown *pICBMusicServer, FUint16 msgBase, FUint32 clientData, FUint32 *pSubscriptionHandle);                                                                                                                                          // 0x18
  virtual int Unsubscribe(FUint32 subscriptionHandle);                                                                                                                                                                                                          // 0x1C
  virtual int StartApplication(TMusicServer_Action action);                                                                                                                                                                                                     // 0x20
  virtual int StopApplication(void);                                                                                                                                                                                                                            // 0x24
  virtual int SetPurchaseFlag(void);                                                                                                                                                                                                                            // 0x28
  virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);                                                                                                                                                   // 0x2C
  virtual int GetFocusedItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle, wchar_t *pFilename, TMusicServer_Time *pPlaylength, TMusicServer_Time *pResumePosition, TBool *pContainsAlbumart, TBool *pIsRealMediaFile); // 0x30
  virtual int GetFilename(FUint32 itemIndex, FUint32 length, wchar_t *pFilename);                                                                                                                                                                               // 0x34
  virtual int GetAlbumArt(FUint32 itemIndex, FUint32 length, wchar_t *pFilename, FUint32 *Offset, FUint32 *Size, TMusicServer_AlbumArt_ImageType *pImageType, TBool *IsDRMProtected);                                                                           // 0x38
  virtual int GetState(TMusicServer_State *State);                                                                                                                                                                                                              // 0x3C
  virtual int Play(FUint32 itemIndex);                                                                                                                                                                                                                          // 0x40
  virtual int Pause(void);                                                                                                                                                                                                                                      // 0x44
  virtual int FastFoward(void);                                                                                                                                                                                                                                 // 0x48
  virtual int Rewind(void);                                                                                                                                                                                                                                     // 0x4C
  virtual int Next(TBool activePress);                                                                                                                                                                                                                          // 0x50
  virtual int Previous(void);                                                                                                                                                                                                                                   // 0x54
  virtual int SetElapsedTime(TMusicServer_Time time);                                                                                                                                                                                                           // 0x58
  virtual int GetElapsedTime(TMusicServer_Time *time);                                                                                                                                                                                                          // 0x5C
  virtual int SetApplicationWindowMode(TBool maximized);                                                                                                                                                                                                        // 0x60
  virtual int SetStarted(TBool started);                                                                                                                                                                                                                        // 0x64
  virtual int SetStereoWidening(TBool enable);                                                                                                                                                                                                                  // 0x68
  virtual int EnableEqualizer(void);                                                                                                                                                                                                                            // 0x6C
  virtual int DisableEqualizer(void);                                                                                                                                                                                                                           // 0x70
  virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);                                                                                                                                                                                        // 0x74
  virtual int SetEqualizerPreset(TMusicServer_EqPreset equalizerPreset);                                                                                                                                                                                        // 0x78
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, TBool setting);                                                                                                                                                                            // 0x7C
  virtual int SetSettings_Int(FUint16 setting);                                                                                                                                                                                                                 // 0x80
  virtual int SetSettings_String(wchar_t *pSettingString);                                                                                                                                                                                                      // 0x84
  virtual int SetSettings_Time(TMusicServer_Time settingTime);                                                                                                                                                                                                  // 0x88
  virtual int SkipTrack(void);                                                                                                                                                                                                                                  // 0x8C
  virtual int RemoveFromPlaylist(FUint32 itemIndex);                                                                                                                                                                                                            // 0x90
  virtual int SavePlayQueue(wchar_t *pPlaylistname);                                                                                                                                                                                                            // 0x94
};
#elif defined(DB3350)
#if defined(DB3350_R2)
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
  virtual void *unk_0x38();
  virtual void *unk_0x3C();
  virtual void *unk_0x40();
  virtual void *unk_0x44();
  virtual void *unk_0x48();
  virtual void *unk_0x4C();
  virtual void *unk_0x50();
  virtual void *unk_0x54();
  virtual void *unk_0x58();
  virtual void *unk_0x5C();            // 0x5C
  virtual void *unk_0x60();            // 0x60
  virtual int Play(FUint32 itemIndex); // 0x64
  virtual int Pause(void);             // 0x68
  virtual int FastFoward(void);        // 0x6C                                                                                                                                                                                                                        // 0x48
  virtual int Rewind(void);            // 0x70
  virtual int Next(TBool activePress); // 0x74
  virtual int Previous(void);          // 0x78
  virtual void *unk_0x7C();
  virtual void *unk_0x80();
  virtual void *unk_0x84();
  virtual void *unk_0x88();
  virtual void *unk_0x8C();
  virtual void *unk_0x90();
  virtual int EnableEqualizer(void);
  virtual int DisableEqualizer(void);
  virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);
  virtual void *unk_0xA0();
  virtual void *unk_0xA4();
  virtual void *unk_0xA8();
  virtual int RemoveFromPlaylist(FUint32 itemIndex);
  virtual int SavePlayQueue(wchar_t *name);
};
#else
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
  virtual void *unk_0x38();
  virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
  virtual void *unk_0x40();
  virtual void *unk_0x44();
  virtual void *unk_0x48();
  virtual void *unk_0x4C();
  virtual void *unk_0x50();
  virtual void *unk_0x54();
  virtual int GetAlbumArt(FUint32 itemIndex, FUint32 length, wchar_t *pFilename, FUint32 *Offset, FUint32 *Size, TMusicServer_AlbumArt_ImageType *pImageType, TBool *IsDRMProtected);
  virtual void *unk_0x5C();
  virtual int Play(FUint32 itemIndex); // 0x60
  virtual int Pause(void);             // 0x64
  virtual int FastFoward(void);        // 0x68
  virtual int Rewind(void);            // 0x6C
  virtual int Next(TBool activePress); // 0x70
  virtual void *unk_0x74();            // 0x74
  virtual int Previous(void);          // 0x78
  virtual void *unk_0x7C();
  virtual void *unk_0x80();
  virtual void *unk_0x84();
  virtual void *unk_0x88();
  virtual void *unk_0x8C();
  virtual int EnableEqualizer(void);
  virtual int DisableEqualizer(void);
  virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);
  virtual void *unk_0x9C();
  virtual void *unk_0xA0();
  virtual void *unk_0xA4();
  virtual int RemoveFromPlaylist(FUint32 itemIndex);
  virtual int SavePlayQueue(wchar_t *name);
  virtual void *unk_0xB0();
  virtual void *unk_0xB4();
  virtual void *unk_0xB8();
  virtual void *unk_0xBC();
};
#endif
#endif

class IMusicServerManager : public IUnknown
{
public:
  virtual int CreateMusicServer(void *pICBMusicServer, IMusicServer **ppIMusicServer);
  virtual int method1();
};

#endif
