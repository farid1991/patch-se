#ifndef _IMUSICSERVERMANAGER_H_
#define _IMUSICSERVERMANAGER_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\MusicServer_types.h"

const UUID CID_IMusicServer_Manager = {0x09, 0xE5, 0x76, 0x91, 0x7F, 0x36, 0x4B, 0x59, 0x82, 0xB9, 0x89, 0x19, 0xEA, 0x18, 0xB6, 0xF8};
const UUID IID_IMusicServer_Manager = {0xAE, 0x67, 0x65, 0x71, 0xB3, 0x99, 0x44, 0xBE, 0xA5, 0xF4, 0xE6, 0x96, 0xCA, 0x63, 0x18, 0x6B};

#if defined(DB3200) || defined(DB3210) || defined(DB3350)

class ICBMusicServer : public IRoot
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

class IMusicServer : public IRoot
{
public:
  /**
 * Start Music Server.
 * Should be called before any other interface function.
 * The server can only be started once.
 * Subsequent calls to Start will be ignored if server is already started or starting.
 *
 * NOTE! This operation is reserved for the Music Application only. All other
 *       clients should use the StartApplication and StopApplication operations instead.
 *
 * - Initiate Server, MME and Content Provider.
 * - Retrieve playqueue from Content Provider.
 * - Set correct item as active in Server.
 * - Start playback immediately if startModePlaying is TRUE.
 * 
 * The following replies can be expected:
 * - OnInitiated: Doesn't require callback subscription.
 * - OnItemChanged: Requires callback subscription.
 * - OnStateChanged: Requires callback subscription.
 *
 * @param[in] pICBMusicServer      A pointer to the callback interface.
 * @param[in] MsgBase              The message base.
 * @param[in] clientData           Data passed back to client see #TClientData
 * @param[in] startModePlaying     Set TRUE if playback should start immediately
 * @param[in] itemIndex            The item index. If NOPOS, Server will start in
 *                                 resume mode (e g GoMusic), using the saved
 *                                 itemIndex and elapsedTime from last time.
 *
 * @returns Returns default status code.
 *          (async function - can't propagate correct return value)
 */ 
  virtual int Start(ICBMusicServer* pICBMusicServer, 
                    TMsgBase        msgBase, 
                    TClientData     clientData, 
                    TBool           StartModePlaying, 
                    FUint32         itemIndex ); //0x10
  
  /**
 * Destroy the Music Server. Should be called after usage of the interface.
 * NOTE! This operation is reserved for the Music Application only. All other
 *       clients should use the StartApplication and StopApplication operations instead.
 *
 * @param[in] subscriptionHandle    Identifies the Music Server callbacks subscription.
 *                                  This is the same handle that is returned from Start.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Destroy( TUnsigned subscriptionHandle ); //0x14
  
  /**
 * Subscribe to Music Server callbacks.
 *
 * @param[in] pICBMusicServer      A pointer to the callback interface.
 * @param[in] MsgBase              The message base.
 * @param[in] clientData           Data passed back to client see #TClientData
 * @param[out] pSubscriptionHandle Identifies the Music Server callbacks subscription.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Subscribe(ICBMusicServer* pICBMusicServer, 
                        TMsgBase        msgBase, 
                        TClientData     clientData, 
                        TUnsigned*      pSubscriptionHandle); //0x18
  
  /**
 * Unsubscribe the client from Music Server callbacks.
 * Should be called when the client is not interested in using the Music Server or 
 * when the client is not interested in the Music Server callbacks.
 *
 * @param[in] subscriptionHandle    Identifies the Music Server callbacks subscription.
 *                                  This is the same handle that is returned from Start.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Unsubscribe( TUnsigned subscriptionHandle );//0x1C
  
  /**
 * Start the Music Application. Should only be used by Open Walkman API and all other clients
 * and not by the Music Application. 
 *
 * Should only be called after Start.
 *
 * Only the following actions are supported by this function:
 *  - TMusicServerAction_CreateMaximized: Start the application with maximized GUI. The player will be started
 *    in paused mode.
 *
 *  - TMusicServerAction_CreateMinimized: Start the application with minimized GUI. The player will start playing 
 *    instantly due to the fact that the Music Application can never be minimized in non-playing mode.
 *
 * @param[in] action            How to start the application.
 * 
 * @returns Returns a RVoid status code.
 */ 
  virtual int StartApplication( TMusicServer_Action action );//0x20
  
  /**
 * Stop the Music Application. Should only be used by Open Walkman API and all other clients 
 * and not by the Music Application. 
 *
 * The Music Application will call IMusicServer_Destroy upon this call. 
 * 
 * @returns Returns a RVoid status code.
 */ 
  virtual int StopApplication( void ); //0x24
  
  /**
 * Set the SetPurchaseFlag. used for calling the same method in the content provider.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetPurchaseFlag( void ); //0x28
  
  /**
 * Get the item info.
 * If title metadata is missing, the filename (without path and extension)
 * is given as pTitle instead.
 *
 * @param[in] itemIndex          The item index
 * @param[in] length             The length of the pointer
 * @param[out] pArtist           The artist metadata
 * @param[out] pAlbum            The artist metadata
 * @param[out] pTitle            The artist metadata
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int GetItem(FUint32 itemIndex, 
                      FUint32 length, 
                      TChar*  pArtist, 
                      TChar*  pAlbum, 
                      TChar*  pTitle ); //0x2C
  /**
 * Get the item info of the focused item, i e just like GetItem,
 * but more output parameters.
 * If title metadata is missing, the filename (without path and extension)
 * is given as pTitle instead.
 *
 * @param[in] itemIndex              The item index
 * @param[in] length                 The length of the pointer
 * @param[out] pArtist               The artist metadata
 * @param[out] pAlbum                The artist metadata
 * @param[out] pTitle                The artist metadata
 * @param[out] pFilename             The complete filepath
 * @param[out] pPlaylength           The total playlength of the item
 * @param[out] pResumePosition       The resume position of the item
 * @param[out] pContainsAlbumart     Returns true if item contains albumart
 * @param[out] pIsRealMediaFile      Returns true if the item is a realmedia file
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int GetFocusedItem(FUint32  itemIndex,
                             FUint32  length, 
                             TChar*   pArtist, 
                             TChar*   pAlbum, 
                             TChar*   pTitle, 
                             TChar*   pFilename, 
                             TMusicServer_Time* pPlaylength, 
                             TMusicServer_Time* pResumePosition, 
                             TBool*   pContainsAlbumart, 
                             TBool*   pIsRealMediaFile );
  
  /**
 * Get the filename (incl path) of the item.
 *
 * @param[in] itemIndex         The item index
 * @param[in] length            The length of the pointer
 * @param[out] pFilename        The complete filepath.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int GetFilename(FUint32 itemIndex, 
                          FUint32 length, 
                          TChar*  pFilename ); //0x34
  
  /**
 * Get the album art of the item.
 * NOTE! A call to this function will only return the information about where the album art is located.
 *       The client is responsible in creating the album art image based on the information returned
 *       from this function.
 *
 * @param[in] itemIndex               The item index. Set to NOPOS if wanting to get album art for current
 *                                    item.
 * @param[in] length                  The length of the pAlbumArtFileName pointer.
 * @param[out] pAlbumArtFileName      The complete filepath to the album art. Will be set to L'\0' if
 *                                    album art doesn't exists.
 * @param[out] pFileOffset            If album art is stored as part of pAlbumArtFileName, pFileOffset
 *                                    points out the position to start reading the album art. If pFileOffset 
 *                                    is 0, the whole file is the album art.
 * @param[out] pAlbumArtSize          The size of the album art in bytes. If album art is stored as part
 *                                    of pAlbumArtFileName, read pAlbumArtSize starting from pFileOffset.
 * @param[out] imageType              The type of the image.
 * @param[out] pIsDRM                 TRUE if album art is DRM protected. FALSE otherwise.
 *                                    If TRUE, it is necessary to use DRM functions, e.g., FSX_DRM_Open.
 *                                    If FALSE, to enhance performance, use e.g., FSX_Open instead.
 *                                    
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int GetAlbumArt(FUint32 itemIndex, 
                          FUint32 length, 
                          TChar*  pAlbumArtFileName, 
                          FUint32* pFileOffset, 
                          FUint32* pAlbumArtSize, 
                          TMusicServer_AlbumArt_ImageType* pImageType, 
                          TBool* pIsDRM); //0x38
  
  /**
 * Get current state
 *
 * @param[out] pState         Returns the current state
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int GetState(TMusicServer_State* pState); //0x3C
  
  /**
 * Start playing an item.
 *
 * If itemIndex is same as before, or NOPOS, player will be resumed from last position.
 *
 * @param[in] itemIndex      The item index
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Play(int itemIndex); //0x40
  
  /**
 * Pause ongoing playback
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Pause(void); //0x44
  
  /**
 * Perform Fast Forward on a specific item
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int FastFoward(void); //0x48
  
  /**
 * Perform Rewind on a specific item
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Rewind(void); //0x4C
  
  /**
 * Select next item
 *
 * Will trigger an OnItemChanged callback (with status code),
 * if next is allowed else a not allowed error is returned 
 * see ICBMusicServer.idl
 *
 * @param[in] activePress      True if next was pressed actively by user.
 *                             if activePress and state playing and the current 
 *                             item is the last in the list to be played, the first item in the
 *                             list will start playing. If not activePress, the first
 *                             item will be chosen but not start playing
 *                              
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Next(TBool activePress); //0x50
  
  /**
 * Select previous item
 *
 *  
 * Will trigger an OnItemChanged callback (with status code),
 * if previous is allowed else a not allowed error is returned 
 * see ICBMusicServer.idl
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int Previous( void ); //0x54
  
  /**
 * Sets the elapsed time in the current item.
 *
 * This function is not available in TMusicServerState_Idle, TMusicServerState_Interrupted state, 
 * or TMusicServerState_Unknown.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetTime(TMusicServer_Time time); //0x58
  
  /**
 * Gets the elapsed time in the current item.
 *
 * @param[out] time   The elapsed play time for the current track.
 *
 * @returns Returns an RVoid status code.
 */
  virtual int GetTime(TMusicServer_Time* time); //0x5C
  
  /**
 * Sets player window mode (maximized, minimized).
 *
 *  
 * Tells the server about which window mode (minimzed,maximized) the player is in.
 * The server has to know this to be able to tell it to the mmrcs.
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetApplicationWindowMode(TBool maximized); //0x60
  
  /**
 * Sets player started mode (TRUE, FALSE).
 *
 *  
 * Tells the server that the player is started.
 * The server has to know this in order to tell other clients that they can operate on the player.
 *
 * @returns Returns a RVoid status code.
 */
  virtual int SetApplicationStarted(TBool started); //0x64
  
  /**
 * Sets stereo widening to on/off
 *
 * @param[in] enable      True is stereo widening should be turned on
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetStereoWidening( TBool enable ); //0x68
  
  /**
 * Sets the equalizer to on
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int EnableEqualizer( void ); //0x6C
  
  /**
 * Sets the equalizer to off
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int DisableEqualizer( void ); //0x70
  
  /**
 * Sets the equalizer gain
 *
 * @param[in] equalizerBand         The equalizer band
 * @param[in] equalizerGain         The equalizer gain
 *
 * @returns Returns a TMusicServer_ErrorCode, returns OPA_OK if successfull.
 */ 
  virtual int SetEqualizerGain(int equalizerBand, TSigned equalizerGain); //0x74
  
  /**
 * Sets the equalizer preset
 *
 * @param[in] equalizerPreset       The equalizer preset
 *
 * @returns Returns a TMusicServer_ErrorCode, returns OPA_OK if successfull.
 */ 
  virtual int SetEqualizerPreset(TMusicServer_EqPreset equalizerPreset); //0x78
  
  /**
 * Set settings
 *
 * @param[in] settingType         The setting type (loop random)
 * @param[in] setting             The setting
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetSettings_Boolean(TMusicServer_Settings settingType, TBool setting); //0x7C
  
  /**
 * Set settings
 *
 * @param[in] setting         The setting to set
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetSettings_Int(FUint16 setting); //0x80
  
  /**
 * Set settings
 *
 * @param[in] pSettingString         The string setting
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetSettings_String(TChar* pSettingString); //0x84
  
  /**
 * Set settings
 *
 * @param[in] settingTime         The time setting to set
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SetSettings_Time(TMusicServer_Time settingTime); //0x88
  
  /** 
 * Skip the file in CMusicServer->skipDirection if there was en error
 * when skiping to next file.
 */
  virtual int SkipTrack( void ); //0x8C
  
  /**
 * Delete a specific item from playQueue. When the item is removed a call to
 * ICBMusicServer::OnNbrOfItemsChanged will be made.
 *
 * @param[in] itemIndex         The item to be removed
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int RemoveFromPlaylist(FUint32 itemIndex); //0x90
  
  /**
 * Save the current playqueue as a playlist
 *
 * @param[in] pPlaylistname         The playlist name
 *
 * @returns Returns a RVoid status code.
 */ 
  virtual int SavePlayQueue(TChar* pPlaylistname); //0x94
};

#elif defined(DB3150_V1)

class IMusicServer: public IRoot
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

class IMusicServer_Manager: public IRoot
{
public:
  virtual int CreateMusicServer(void* pIShell, IMusicServer** pIMusicServer);
  virtual int method1(IMusicServer_ExternalStart** pIMusicServer_ExternalStart);
};

#endif
