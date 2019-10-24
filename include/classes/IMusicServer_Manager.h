#ifndef _IMUSICSERVERMANAGER_H_
#define _IMUSICSERVERMANAGER_H_

#include "..\\include\types\MusicServer_types.h"

//UUID CID_ÑMusicServer_Manager = {9, 0xE5, 0x76, 0x91, 0x7F, 0x36, 0x4B, 0x59, 0x82, 0xB9, 0x89, 0x19, 0xEA, 0x18, 0xB6, 0xF8};
//UUID IID_IMusicServer_Manager = {0xAE, 0x67, 0x65, 0x71, 0xB3, 0x99, 0x44, 0xBE, 0xA5, 0xF4, 0xE6, 0x96, 0xCA, 0x63, 0x18, 0x6B};

class IMusicServer: public IUnknown
{
public:
  virtual void* unk_0x10();
  virtual void* unk_0x14();
  virtual void* unk_0x18();
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

class IMusicServer_ExternalStart;

class IMusicServer_Manager: public IUnknown
{
public:
  virtual int CreateMusicServer(void* pIShell, IMusicServer** pIMusicServer);
  virtual int method1(IMusicServer_ExternalStart** pIMusicServer_ExternalStart);
};

#endif
