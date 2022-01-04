#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

typedef struct
{
  uint32_t hours;
  uint32_t minutes;
  uint32_t seconds;
} TMusicServer_Time;

/**
 * The set of music server states.
 */
typedef enum
{
  TMusicServerState_Idle,           ///< Player is idle, eg is in the init phase but not yet fully initiated.
  TMusicServerState_Initiated,      ///< Player is initiated.
  TMusicServerState_Playing,        ///< Player is playing.
  TMusicServerState_Paused,         ///< Player is paused. Use the resume method to resume the playback.
  TMusicServerState_FastForwarding, ///< Player is fast forwarding.
  TMusicServerState_Rewinding,      ///< Player is rewinding.
  TMusicServerState_Interrupted,    ///< Player is interrupted by another playback session/player/call.
  TMusicServerState_Unknown,        ///< State is unknown to the Music Server.
  TMusicServerState_Last            ///< Place holder. Put new data before this!
} TMusicServer_State;

/**
 * The set of music server status.
 */
typedef enum
{
  TMusicServerCause_Error,                    ///< General unspecified error.
  TMusicServerCause_Platform_Error,           ///< Unspecified platform error.
  TMusicServerCause_Beginning_Of_File_Passed, ///< Passed beginnig of media file (case of rewind operation).
  TMusicServerCause_End_Of_File,              ///< End of media file reached.
  TMusicServerCause_Client_Termination,       ///< Client terminated the session player.
  TMusicServerCause_DRM_Credentials_Expired,  ///< DRM credentials expired.
  TMusicServerCause_File_Not_Found,           ///< File does not exist.
  TMusicServerCause_Last                      ///< Place holder. Put new data before this!
} TMusicServer_Cause;

/**
 * The set of music server status.
 */
typedef enum
{
  TMusicServerStatus_ActiveMaximized, ///< Player is started in maximized mode, can be paused or playing.
  TMusicServerStatus_ActiveMinimized, ///< Player is started in maximized mode, can only be playing in minimized.
  TMusicServerStatus_Inactive,        ///< Player is shut down.
  TMusicServerStatus_Last             ///< Place holder. Put new data before this!
} TMusicServer_Status;

/**
 * Album art image types
 */
typedef enum
{
  TMusicServer_AlbumArt_ImageType_Jpeg,
  TMusicServer_AlbumArt_ImageType_Gif,
  TMusicServer_AlbumArt_ImageType_Png,
  TMusicServer_AlbumArt_ImageType_Bmp,
  TMusicServer_AlbumArt_ImageType_None,
  TMusicServer_AlbumArt_ImageType_Embedded
} TMusicServer_AlbumArt_ImageType;

/**
 * The set of settings used in the music server
 */
typedef enum
{
  TMusicServerSetting_Loop,
  TMusicServerSetting_Random
} TMusicServer_Settings;

typedef struct _PLAYING_TIME_DATA
{
  uint8_t dummy[0x24];
  TMusicServer_Time PlayingTime;
} PLAYING_TIME_DATA;

typedef struct _NEW_TRACK_DATA
{
  uint8_t dummy_0x0[0x28];       //0
  int Track_ID;                  //0x28
  TMusicServer_Time ElapsedTime; //0x2C
  uint8_t dummy_0x30[0x24];      //0x38
  TMusicServer_Time FullTime;    //0x5C
} NEW_TRACK_DATA;

#endif
