#ifndef __MUSICSERVERTYPES_H__
#define __MUSICSERVERTYPES_H__

#include "Time_types.h"

#include "..\classes\IMMEPlayer.h"

//////////////////////////////////////////////////////////////////////
/// @name Types
//@{

const TUnsigned MUSIC_SERVER_MAX_URI_LENGTH = 512;
const TUnsigned MUSIC_SERVER_MAX_PLAYLISTNAME_LENGTH = 251;

typedef enum
{
  // General
  MUSIC_SERVER_GENERAL_ERROR, ///< Returned when none of the other error codes are applicable.
  MUSIC_SERVER_INTERRUPTED,   ///< Returned when the session or the player was interrupted by another session
                              ///< or player (with the same or higher priority) or a call.

  MUSIC_SERVER_NOT_SUPPORTED,     ///< Returned when some functionality not is supported with the current platform.
                                  ///< configuration or a file format not supported with current phone project configuration.
  MUSIC_SERVER_PLATFORM_ERROR,    ///< Returned when the platform is returning an error of unknown reason.
  MUSIC_SERVER_OUT_OF_MEMORY,     ///< Returned when some allocation failed due to lack of memory.
  MUSIC_SERVER_INPUT_PARAM_ERROR, ///< Returned when there was some error in the input parameters.
  MUSIC_SERVER_NOT_ALLOWED_ERROR, ///< Returned when an action is not allowed to be performed (due to wrong state etc.).

  // Player specific
  MUSIC_SERVER_CREATE_PLAYER_FAILED, ///< The MME Player failed during create.
  MUSIC_SERVER_NOT_AUTHORIZED,       ///< Returned when there are not any available resources, and another ongoing activity has higher priority.
  MUSIC_SERVER_FILE_NOT_FOUND,       ///< Returned when the specified file is not found, local or on media server.
  MUSIC_SERVER_END_OF_FILE,          ///< Returned when the player stopped since end of file was reached.
  MUSIC_SERVER_CLIENT_TERMINATION,   ///< Returned when the player stopped since the client called the stopped method.

  // DRM specific
  MUSIC_SERVER_DRM_ERROR,                   ///< Returned when the specified file is a DRM file, and DRM is returning an error of unknown reason.
  MUSIC_SERVER_DRM_PLAYRIGHTS_EXPIRED,      ///< Returned when the specified file is a DRM file, and the credentials not allows playback.
  MUSIC_SERVER_DRM_AUDIO_ROUTING_FORBIDDEN, ///< Returned when the specified file is a DRM file, and audio routing to an accessory is forbidden.
  MUSIC_SERVER_DRM_MSDRM_EXPIRED,           ///< Returned when the file is a MS DRM file and no valid license.
  MUSIC_SERVER_DRM_RIGHTS_RENEWABLE,
  MUSIC_SERVER_DRM_WAITING_FOR_RIGHTS, ///< Returned when the specified file is a DRM file, and the DRM system is busy aquiring new license

  MUSIC_SERVER_LAST ///< Place holder. Put new data before this!
} TMusicServer_ErrorCode;

//*************************** Should Be Changed*****************************

/**
 * This type is used to indicate mute reason received from MME.
 */
typedef TMMEMuteReason TMusicServer_MuteReason;

// ContentProvider
// typedef TMultimediaContentProvider_LocationPath TMusicServer_LocationPath;

/**
 * The set of data to describe time.
 */
typedef struct
{
  FUint32 hours;
  FUint32 minutes;
  FUint32 seconds;
} TMusicServer_Time;

/**
 * The set of settings used in the music server
 */
typedef enum
{
  TMusicServerSetting_Loop,
  TMusicServerSetting_Random
} TMusicServer_Settings;

/**
 * The set of equalizer bands available.
 *
 * The possible values are:
 *
 * TMMEEqBand_ClearBass1,   Only for Clear Audio
 * TMMEEqBand_ClearBass2,   Only for Clear Audio
 * TMMEEqBand_63,           Only for ordinary EQ
 * TMMEEqBand_250,          Only for ordinary EQ
 * TMMEEqBand_400,          Only for Clear Audio
 * TMMEEqBand_1000,         Both Clear Audio and ordinary EQ
 * TMMEEqBand_2500,         Only for Clear Audio
 * TMMEEqBand_4000,         Only for ordinary EQ
 * TMMEEqBand_6300,         Only for Clear Audio
 * TMMEEqBand_16000,        Both Clear Audio and ordinary EQ
 *
 */
// typedef TMMEEqBand TMusicServer_EqBand;

/**
 * The set of equalizer presets available.
 *
 * The possible values are:
 *
 * TMMEEqPreset_Heavy,
 * TMMEEqPreset_Pops,
 * TMMEEqPreset_Jazz,
 * TMMEEqPreset_Unique,
 * TMMEEqPreset_Soul,
 * TMMEEqPreset_EasyListening,
 * TMMEEqPreset_BassBoost,
 * TMMEEqPreset_TrebleBoost,
 *
 */
// typedef TMMEEqPreset TMusicServer_EqPreset;

typedef enum
{
  TMusicServerEqPreset_Normal = 0,
  TMusicServerEqPreset_Bass = 1,
  TMusicServerEqPreset_Megabass = 2,
  TMusicServerEqPreset_Voice = 3,
  TMusicServerEqPreset_TrebleBoost = 4,
  TMusicServerEqPreset_Manual = 6
} TMusicServer_EqPreset; // NON-CLEARBASS

typedef enum
{
  EqBand_63,
  EqBand_250,
  EqBand_1000,
  EqBand_4000,
  EqBand_16000,
  EqBand_Last
} TMusicServer_EqBand;

//**************************** End of change *****************************'

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
  TMusicServerStatus_ActiveMaximized, ///< Player is started in maximized mode, can be paused or playing.
  TMusicServerStatus_ActiveMinimized, ///< Player is started in maximized mode, can only be playing in minimized.
  TMusicServerStatus_Inactive,        ///< Player is shut down.
  TMusicServerStatus_Last             ///< Place holder. Put new data before this!
} TMusicServer_Status;

/**
 * Defines an unused handle.
 *
 */
const FUint32 MUSICSERVER_HANDLE_NOT_USED = 0;

/**
 * The set of causes that can be sent
 * from the mutlimedia engine.
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
 * The set of actions that can be sent
 * to the mutlimedia engine.
 */
typedef enum
{
  TMusicServerAction_None,             ///< No action set.
  TMusicServerAction_CreateMaximized,  ///< Must be able to create player maximized from extern part, accessories.
  TMusicServerAction_CreateMinimized,  ///< Must be able to create player minimized from extern part, accessories.
  TMusicServerAction_Destroy,          ///< Must be able to destroy player from extern part, accessories.
  TMusicServerAction_Play,             ///< Starts player.
  TMusicServerAction_Pause,            ///< Pauses player.
  TMusicServerAction_Next,             ///< Get next file.
  TMusicServerAction_Previous,         ///< Get previous file.
  TMusicServerAction_StartFastForward, ///< Starts fastforward of player.
  TMusicServerAction_StopFastForward,  ///< Stops fastfowardad of player, must be done before play.
  TMusicServerAction_StartRewind,      ///< Starts rewind of player.
  TMusicServerAction_StopRewind,       ///< Stops rewind of player, must be done before play.
  TMusicServerAction_Last              ///< Place holder. Put new data before this!
} TMusicServer_Action;

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

//@} End of Types

#endif
