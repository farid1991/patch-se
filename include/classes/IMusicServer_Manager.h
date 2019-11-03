#ifndef _IMUSICSERVERMANAGER_H_
#define _IMUSICSERVERMANAGER_H_

#include "..\\include\types\MusicServer_types.h"

//UUID CID_ÑMusicServer_Manager = {9, 0xE5, 0x76, 0x91, 0x7F, 0x36, 0x4B, 0x59, 0x82, 0xB9, 0x89, 0x19, 0xEA, 0x18, 0xB6, 0xF8};
//UUID IID_IMusicServer_Manager = {0xAE, 0x67, 0x65, 0x71, 0xB3, 0x99, 0x44, 0xBE, 0xA5, 0xF4, 0xE6, 0x96, 0xCA, 0x63, 0x18, 0x6B};

#if defined(DB3200) || defined(DB3210) || defined(DB3350)

class ICBMusicServer : public IUnknown
{
public:
  virtual void OnInitiated(int status, int track_count, bool random, bool loop, int ClientData);
  virtual void OnDestroy(int ClientData);
  virtual void OnDestroyed(int ClientData);
  virtual void OnStopped(TMusicServer_Cause cause, TMusicServer_Time time, int ClientData);
  virtual void OnStateChanged(TMusicServer_State state, TMusicServer_Time elapsedtime, int ClientData);
  virtual void OnTimeFeedback(TMusicServer_Time elapsedtime, int ClientData);
  virtual void OnAudioMuted(TMusicServer_MuteReason muteReason, int ClientData);
  virtual void OnNbrOfItemsChanged(int track_count, int ClientData, int result);
  virtual void OnItemChanged(int status, int track_id, TMusicServer_Time Position, TMusicServer_Action Action, wchar_t* fullpath, int path_lengh, wchar_t* Title, int TitleLengh, wchar_t* Artist, int ArtistLengh, wchar_t* Album, int AlbumLengh, TMusicServer_Time FullTime, bool isAlumArt, bool isDRMProtected, bool isRealMediaFile, int ClientData);
  virtual void OnApplicationStarted(bool started, int ClientData);
  virtual void OnError(int error, int ClientData);
};

class IMusicServer : public IUnknown
{
public:
  virtual int Start(ICBMusicServer* pICBMusicServer, u16 msgBase, int clientData, bool StartModePlaying, int track_id); //0x10
  virtual int Destroy(unsigned long subscriptionHandle); //0x14
  virtual int Subscribe(ICBMusicServer* pICBMusicServer, u16 msgBase, int clientData, unsigned long * pSubscriptionHandle); //0x18
  virtual int Unsubscribe(unsigned long subscriptionHandle);//0x1C
  virtual int StartApplication(TMusicServer_Action action);//0x20
  virtual int StopApplication(void); //0x24
  virtual int SetPurchaseFlag(void); //0x28
  virtual int GetItem(int itemIndex, int length, wchar_t* pArtist, wchar_t* pAlbum, wchar_t* pTitle); //0x2C
  virtual int GetFocusedItem(int itemIndex, int length, wchar_t* pArtist, wchar_t* pAlbum, wchar_t* pTitle, wchar_t* pFilename, TMusicServer_Time* pPlaylength, TMusicServer_Time* pResumePosition, bool* pContainsAlbumart, bool* pIsRealMediaFile); //0x30
  virtual int GetFilename(int itemIndex, int length, wchar_t* pFilename); //0x34
  virtual int GetAlbumArt(int itemIndex, int length, wchar_t* pAlbumArtFileName, int* pFileOffset, int* pAlbumArtSize, TMusicServer_AlbumArt_ImageType* pImageType, bool* pIsDRM); //0x38
  virtual int GetState(TMusicServer_State* pState); //0x3C
  virtual int Play(int itemIndex); //0x40
  virtual int Pause(void); //0x44
  virtual int FF(void); //0x48
  virtual int REW(void); //0x4C
  virtual int Next(bool activePress); //0x50
  virtual int Previous(void); //0x54
  virtual int SetTime(TMusicServer_Time time); //0x58
  virtual int GetTime(TMusicServer_Time* time); //0x5C
  virtual int SetApplicationWindowMode(bool maximized); //0x60
  virtual int SetApplicationStarted(bool started); //0x64
  virtual int SetStereoWidening(bool enable); //0x68
  virtual int EnableEqualizer(void); //0x6C
  virtual int DisableEqualizer(void); //0x70
  virtual int SetEqualizerGain(int equalizerBand, int equalizerGain); //0x74
  virtual int SetEqualizerPreset(TMusicServer_EqPreset equalizerPreset); //0x78
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, bool setting); //0x7C
  virtual int SetSettings_Int(u16 setting); //0x80
  virtual int SetSettings_String(wchar_t* pSettingString); //0x84
  virtual int SetSettings_Time(TMusicServer_Time settingTime); //0x88
  virtual int SkipTrack(void); //0x8C
  virtual int RemoveFromPlaylist(int itemIndex); //0x90
  virtual int SavePlayQueue(wchar_t* pPlaylistname); //0x94
};

#else

class IMusicServer: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int GetItem( FUint32 itemIndex, FUint32 length, TChar* pArtist, TChar* pAlbum, TChar* pTitle );
  virtual int GetFocusedItem( FUint32 itemIndex, FUint32 length, TChar* pArtist, TChar* pAlbum, TChar* pTitle, TChar* pFilename, TMusicServer_Time* pPlaylength, TMusicServer_Time* pResumePosition, TBool* pContainsAlbumart, TBool* pIsRealMediaFile );
  virtual int GetFilename( FUint32 itemIndex, FUint32 length, TChar* pFilename );
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int unk_0x30();
  virtual int Play( FUint32 itemIndex );  //0x34
  virtual int Pause( void );              //0x38
  virtual int FastFoward( void );         //0x3c
  virtual int Rewind( void );             //0x40
  virtual int Next( TBool activePress );  //0x44
  virtual int Previous( void );           //0x48
  virtual int SetApplicationWindowMode( TBool maximized ); // unk_0x4C();
  virtual int unk_0x50();
  virtual int unk_0x54();
  virtual int SetEqualizerGain( int equalizerBand, TSigned equalizerGain );
  virtual int SetSettings_Boolean( TMusicServer_Settings settingType, TBool setting );//void* unk_0x5C();
  virtual int SetSettings_Int( FUint16 setting ); //void* unk_0x60();
  virtual int unk_0x64();
  virtual int SetSettings_Time( TMusicServer_Time settingTime ); // unk_0x68();
  virtual int GetSettings_Boolean( TMusicServer_Settings settingType, TBool* setting ); //unk_0x6C();
  virtual int GetCurrentItemIndex( FUint32* itemIndex ); //unk_0x70();
  virtual int unk_0x74();
  virtual int GetTime( TMusicServer_Time* time ); //0x78;
  virtual int RemoveFromPlaylist( FUint32 itemIndex );
  virtual int SavePlayQueue( TChar* pPlaylistname );
};

#endif

class IMusicServer_ExternalStart;

class IMusicServer_Manager: public IUnknown
{
public:
  virtual int CreateMusicServer(void* pIShell, IMusicServer** pIMusicServer);
  virtual int method1(IMusicServer_ExternalStart** pIMusicServer_ExternalStart);
};

#endif
