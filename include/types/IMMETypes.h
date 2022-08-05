#ifndef _IMMETYPES_H_
#define _IMMETYPES_H_

#include "Basic_types.h"
#include "UIRect_types.h"

/**
 * The maximum length of a file path or a streaming URL
 */
const int MME_URL_TYPE_MAX_LENGTH = 512;

const int MME_STREAMING_SESSION_NAME_MAX_LENGTH = 512;

/**
 * The firewall traversal interval used when streaming is connected via WLAN
 */
const int MME_STREAMING_WLAN_FIREWALL_TRAVERSAL_INTERVAL = 60000;

/**
 * The set of error codes that can be sent
 * from the mutlimedia engine.
 */
typedef enum
{
  // General
  MME_UED_GENERAL_ERROR, ///< Returned when none of the other error codes are applicable.
  MME_UED_INTERRUPTED,   ///< Returned when the session or the player was interrupted by another session or player (with the same or
                         ///< higher priority) or a call.

  MME_UED_NOT_SUPPORTED,     ///< Returned when some functionality not is supported with the current platform
                             ///< configuration or a file format not supported with current phone project configuration.
  MME_UED_OPA_ERROR,         ///< Returned when the platform is returning an error of unknown reason.
  MME_UED_OUT_OF_MEMORY,     ///< Returned when some allocation failed due to lack of memory.
  MME_UED_INPUT_PARAM_ERROR, ///< Returned when there was some error in the input parameters.
  MME_UED_NOT_ALLOWED_ERROR, ///< Returned when an action is not allowed to be performed (due to wrong state etc.).

  // Player specific
  MME_UED_NOT_AUTHORIZED,     ///< Returned when there are not any available resources, and another ongoing activity has higher priority.
  MME_UED_FILE_NOT_FOUND,     ///< Returned when the specified file is not found, local or on media server.
  MME_UED_END_OF_FILE,        ///< Returned when the player stopped since end of file was reached.
  MME_UED_CLIENT_TERMINATION, ///< Returned when the player stopped since the client called the stopped method.

  // DRM specific
  MME_UED_DRM_ERROR,                   ///< Returned when the specified file is a DRM file, and DRM is returning an error of unknown reason.
  MME_UED_DRM_PLAYRIGHTS_EXPIRED,      ///< Returned when the specified file is a DRM file, and the credentials not allows playback.
  MME_UED_DRM_AUDIO_ROUTING_FORBIDDEN, ///< Returned when the specified file is a DRM file, and audio routing to an accessory is forbidden.
                                       // MME_UED_DRM_NOT_ALLOWED,                  ///< Returned when the specified DRM file is not allowed to be played.

  // Streaming specific
  MME_UED_STREAMING_NETWORK_ERROR,            ///< Returned when connection/registrating to the network failed or network initiated close.
  MME_UED_STREAMING_RADIO_OFF_ERROR,          ///< Returned when trying to connect when in Radio OFF mode a.k.a flight mode.
  MME_UED_STREAMING_SERVER_ERROR,             ///< Returned when connection to the media server failed.
  MME_UED_STREAMING_PROXY_ERROR,              ///< Returned when connection to the given proxy server failed.
  MME_UED_STREAMING_DNS_ERROR,                ///< Returned when failed to resolve a host name to an IP adress.
  MME_UED_STREAMING_ACCOUNT_MISSING,          ///< Returned when the streaming connection account is missing.
  MME_UED_STREAMING_BAD_ACCOUNT,              ///< Returned when the streaming connection account was incorrect and could not be opened.
  MME_UED_STREAMING_CONNECTION_LOST,          ///< Returned when lost network or server connection.
  MME_UED_STREAMING_AUTHENTICATION_CANCELLED, ///< Returned when authentication to the network is needed and it is cancelled.
  MME_UED_STREAMING_AUTHENTICATION_ERROR,     ///< Returned when authentication to the network or streaming server is needed and it has failed due to wrong input.
  MME_UED_PDP_MODIFICATION_FAILURE,           ///< Returned when network connection QoS modification failed.
  MME_UED_STREAMING_CLOSED,                   ///< Returned when the network or streaming connection is closed.
  MME_LAST                                    ///< Place holder. Put new data before this!
} TMMEErrorCode;

/**
 * The set of causes that can be sent
 * from the mutlimedia engine.
 */
typedef enum
{
  TMMECause_Error,                     ///< General unspecified error.
  TMMECause_OPA_Error,                 ///< Unspecified platform error
  TMMECause_Beginning_Of_File_Passed,  ///< Passed beginnig of media file (case of rewind operation).
  TMMECause_End_Of_File,               ///< End of media file reached.
  TMMECause_Client_Termination,        ///< Client terminated the session player.
  TMMECause_DRM_Credentials_Expired,   ///< DRM credentials expired.
  TMMECause_Streaming_Connection_Lost, ///< Streaming connection lost.
  TMMECause_Streaming_Session_Ended,   ///< This concerns packet video networks only. A pre-paid account has no credit
                                       ///< left or that the current playlist has been exhausted and the client has not
                                       ///< requested an updated playlist.
  TMMECause_VideoInterrupt,            ///< Video interrupted a video -> decoder conflict.
  TMMECause_Last                       ///< Place holder. Put new data before this!
} TMMECause;

/**
 * The set of player states.
 */
typedef enum
{
  TMMEState_Idle,           ///< Player is idle, eg is in the init phase but not yet fully initiated.
  TMMEState_Stopped,        ///< Player is stopped due to an error or EOF (end of file) and can not be used anymore.
  TMMEState_Initiated,      ///< Player is initiated and ready to be played.
  TMMEState_Playing,        ///< Player is playing.
  TMMEState_Paused,         ///< Player is paused. Use the resume method to resume the playback.
  TMMEState_FastForwarding, ///< Player is fast forwarding.
  TMMEState_Rewinding,      ///< Player is rewinding.
  TMMEState_Interrupted,    ///< Player is interrupted by another playback session/player/call.
  TMMEState_SlowMotion,     ///< Player is playing video in slow motion.
  // MME internal states. Will not be exposed to the clients!
  TMMEState_Delayed_Playing,
  TMMEState_ReInitiating,
  TMMEState_Last ///< Place holder. Put new data before this!
} TMMEState;

/**
 * The set of additional player features (bitwise) supported
 * for different file types. All file types do not
 * support these.
 */
typedef enum
{
  TMMEFeature_Wind = 0x01,         ///< Bit = 0001, Fast forward and rewind.
  TMMEFeature_Capture_Video = 0x02 ///< Bit = 0010, Capture video snapshot.
} TMMEFeature;

/**
 * The set of player creation configurations.
 * Some restrictions will be present though:
 *
 * 1) An audio player can be created for a video file -> play video file as audio only.
 * 2) A video player can not be created for audio only files.If this type is set
 *    for an audio only file the player created will be of type audio only!
 */
typedef enum
{
  TMMECreatePlayer_AudioOnly,      ///< Creating a player for audio only. Low priority.
  TMMECreatePlayer_VideoOnly,      ///< Creating a player for video only (sound disabled). Low priority.
  TMMECreatePlayer_VideoThumbnail, ///< Creating a player for video only (this does not apply for streaming) and no resource handling, e.g. for playing video thumbnails,
                                   ///< but may also be used for video playback (without sound) during voice call.
                                   ///< The client is responsible for the resource handling. SHOULD BE USED WITH CARE. Low priority.
  TMMECreatePlayer_AsMedia,        ///< Creating a player that follows the media file content - audio, video, audio/video.. Low priority.

  TMMECreatePlayer_Last ///< Place holder. Put new data before this!
} TMMECreatePlayer;

/**
 * The set of values that determines
 * the MME player priority.
 */
typedef enum
{
  TMMEPlayerPriority_MediaPlayer,
  TMMEPlayerPriority_VideoTelephony,
  TMMEPlayerPriority_Java,
  TMMEPlayerPriority_FM_Radio,
  TMMEPlayerPriority_FM_Radio_Alarm,
  TMMEPlayerPriority_Ringer,
  TMMEPlayerPriority_SlideShow,
  TMMEPlayerPriority_Unknown = 0xFF ///< Place holder. Put new data before this!
} TMMEPlayerPriority;

/**
 * The set of audio configurations. The values may be used to
 * create a mask containing all settings.
 *
 * E.g. TMMEAudioConfig_FollowSilentMode | TMMEAudioConfig_Mute_When_Rerouting_To_Speaker
 */
typedef enum
{
  TMMEAudioConfig_Normal = 0x0000,                         ///< No special setting
  TMMEAudioConfig_FollowSilentMode = 0x0001,               ///< Silent mode is followed, sound will only be played in discreet accessory.
  TMMEAudioConfig_Mute_When_Rerouting_To_Speaker = 0x0002, ///< Mutes sound if it ends up in speaker and previously was in accessory (embarassing transition).
  TMMEAudioConfig_Allow_FMTX = 0x0004,                     ///< Specifies that the player allows audio to be sent over FM
  TMMEAudioConfig_Unknown = 0xFF                           ///< Place holder. Put new data before this!
} TMMEAudioConfig;

/**
 * The set of values type that
 * determines the MME session priority.
 */
typedef enum
{
  TMMESessionPriority_MediaPlayer,
  TMMESessionPriority_VideoTelephony,
  TMMESessionPriority_Java,
  TMMESessionPriority_FM_Radio,
  TMMESessionPriority_Messaging,
  TMMESessionPriority_VoiceCall,
  TMMESessionPriority_SlideShow
} TMMESessionPriority;

/**
 * The set of player configuration description.
 */
typedef struct
{
  TMMECreatePlayer playerToCreate;   ///< Type of player to create.
  TMMEPlayerPriority playerPriority; ///< Type of audio channel (different priorities), @see TMMEPlayerPriority.
  TMMEAudioConfig audioConfig;       ///< Audio configuration - follow silent mode/normal..., @see TMMEAudioConfig.
} TMMEPlayerConfig;

/**
 * The set of player types. Returned when a player has been created to
 * describe what sort of player that has been created.
 */
typedef enum
{
  TMMEPlayerType_Audio,                    ///< Audio player for local file.
  TMMEPlayerType_Video_And_Audio,          ///< Video player with both video and audio for local file.
  TMMEPlayerType_VideoOnly,                ///< Video player with video and no audio for local file.
  TMMEPlayerType_VideoThumbnail,           ///< Video player with video and no audio for local file. Used mainly for video thumbnail playback,
                                           ///< but can also be use to play a video during a voice call. RESOURCE HANDLING IS DISABLED so
                                           ///< the client is responsible for the resource handling. SHOULD BE USED WITH CARE.
  TMMEPlayerType_StreamingAudio,           ///< Streaming audio player.
  TMMEPlayerType_StreamingVideo_And_Audio, ///< Streaming video player with both video and audio.
  TMMEPlayerType_StreamingVideoOnly,       ///< Streaming video player with video and no audio.
  TMMEPlayerType_StreamingUnknown,         ///< Player type unknown. Will only be set in streaming before the player is initiated.
  TMMEPlayerType_Last                      ///< Place holder. Put new data before this!
} TMMEPlayerType;

/**
 * The set of data to describe the multimedia engine time
 * representation.
 */
typedef struct
{
  FUint32 Hours;        ///< Number of hours.
  FUint32 Minutes;      ///< Number of minutes (0 - 59).
  FUint32 Seconds;      ///< Number of seconds (0 - 59).
  FUint32 MilliSeconds; ///< Number of milliseconds (0 - 999).
} TMMETime;

/**
 * The set of content possibilities a media file can have.
 */
typedef enum
{
  TMMEContentType_VideoAndAudio, ///< File containing both audio and video.
  TMMEContentType_VideoOnly,     ///< File only containing video.
  TMMEContentType_AudioOnly,     ///< File only containing audio.
  TMMEContentType_Unknown        ///< File content type is unknown.
} TMMEContentType;

/**
 * The set of media types possible to determine from a drm protected media file.
 * Returned by interface function IMMESessionContentUtility::GetMediaFromMimeType
 */
typedef enum
{
  TMMEMediaType_Unknown, ///< File content type is unknown.
  TMMEMediaType_Audio,   ///< File only containing audio.
  TMMEMediaType_Video    ///< File only containing video.
} TMMEMediaType;

/**
 * The set of audio output possibilities a media file can have.
 * E.g. stereo/mono.
 */
typedef enum
{
  TMMEAudioOutput_Mono,   ///< Mono audio output.
  TMMEAudioOutput_Stereo, ///< Stereo audio output.
  TMMEAudioOutput_Unknown ///< Unknown output.
} TMMEAudioOutput;

/**
 * The set of data to describe a video image size in pixels.
 */
typedef struct
{
  int Height; ///< Height in pixels.
  int Width;  ///< Width in pixels.
} TMMEVideoImageSize;

/**
 * The set of data to describe a H263/H264 video encoded file.
 */
typedef struct
{
  char videoProfile;      ///< Video profile of a H263/H264 encoded video file.
  char videoProfileLevel; ///< Video profile level of a H263/H264 encoded video file.
} TMMEVideoProfile;

/**
 * The set of file format types.
 */
typedef enum
{
  TMMEFileFormatIdType_NONE, // Probably a streaming link
  TMMEFileFormatIdType_3GA,
  TMMEFileFormatIdType_3GP,
  TMMEFileFormatIdType_AAC,
  TMMEFileFormatIdType_AMR,
  TMMEFileFormatIdType_ASF,
  TMMEFileFormatIdType_AWB, // AMR wide band
  TMMEFileFormatIdType_EMY,
  TMMEFileFormatIdType_IMY,
  TMMEFileFormatIdType_M4A,
  TMMEFileFormatIdType_M4B,
  TMMEFileFormatIdType_MIDI,
  TMMEFileFormatIdType_MMF,
  TMMEFileFormatIdType_MP3,
  TMMEFileFormatIdType_MP4,
  TMMEFileFormatIdType_MXMF,
  TMMEFileFormatIdType_RAM,
  TMMEFileFormatIdType_RA,
  TMMEFileFormatIdType_RHZ,
  TMMEFileFormatIdType_RM,
  TMMEFileFormatIdType_RV,
  TMMEFileFormatIdType_SDP,
  TMMEFileFormatIdType_WAV,
  TMMEFileFormatIdType_WMA,
  TMMEFileFormatIdType_WMV,
  TMMEFileFormatIdType_XMF,
  TMMEFileFormatIdType_Last // Put new file types before this.
} TMMEFileFormatIdType;

/**
 * The set of video format (codec) types
 * a file format may contain.
 */
typedef enum
{
  TMMEVideoCodecIdType_NONE,
  TMMEVideoCodecIdType_H263,
  TMMEVideoCodecIdType_H264,
  TMMEVideoCodecIdType_M4V, // MPEG4
  TMMEVideoCodecIdType_WMV,
  TMMEVideoCodecIdType_REAL,
  TMMEVideoCodecIdType_UNKNOWN, // Put new codec types before this.
  TMMEVideoCodecIdType_Last
} TMMEVideoCodecIdType;

/**
 * The set of audio format (codec) types
 * a file format may contain.
 *
 * Note: These values are re-mapped and type checks must therefore
 * be performed against audioCodecType. Will NOT work with AudioCodecId!
 */
typedef enum
{
  TMMEAudioCodecIdType_NONE,
  TMMEAudioCodecIdType_AAC,
  TMMEAudioCodecIdType_AMR,
  TMMEAudioCodecIdType_EMELODY,
  TMMEAudioCodecIdType_IMELODY,
  TMMEAudioCodecIdType_MIDI,
  TMMEAudioCodecIdType_MP3,
  TMMEAudioCodecIdType_RAWHERTZ,
  TMMEAudioCodecIdType_PCM, // WAV
  TMMEAudioCodecIdType_SMAF,
  TMMEAudioCodecIdType_WMA,
  TMMEAudioCodecIdType_AMR_WB,
  TMMEAudioCodecIdType_AMR_WBP,
  TMMEAudioCodecIdType_REAL_SIPRO,
  TMMEAudioCodecIdType_REAL_GECKO,
  TMMEAudioCodecIdType_UNKNOWN, // Put new codec types before this.
  TMMEAudioCodecIdType_Last
} TMMEAudioCodecIdType;

/**
 * The set of data to describe content properties of a media file.
 */
typedef struct
{
  TMMEContentType contentType;         ///< Type of content, @see TMMEContentType.
  TMMETime mediaLength;                ///< Media file total playback time, @see TMMETime.
  FUint8 fileFormatId;                 ///< Media file format identifier.
  TMMEFileFormatIdType fileFormatType; ///< File format type description, @see TMMEFileFormatIdType.
  TMMEAudioOutput audioOutput;         ///< Mono/stero audio output, @see TMMEAudioOutput.
  FUint8 audioCodecId;                 ///< Audio codec identifier (EMP value, to be used mainly for DRM checks).
  TMMEAudioCodecIdType audioCodecType; ///< Audio codec id type description, @see TMMEAudioCodecIdType.
  FUint32 audioSampleRate;             ///< Sample rate of the audio encoding, values from 0 to 4294967295 Hz.
  FUint16 bpmTempo;                    ///< Beats-per-minute tempo. Only valid for MIDI and iMelody files.
  TBool videoImageSizePresent;         ///< TRUE if there is available information about VideoImageSize.
  TMMEVideoImageSize videoImageSize;   ///< Video image size, @see TMMEVideoImageSize.
  FUint8 videoCodecId;                 ///< Video codec id of an video encoding type.
  TMMEVideoCodecIdType videoCodecType; ///< Video codec id type description, @see TMMEVideoCodecIdType.

  wchar_t streamingSessionName[MME_STREAMING_SESSION_NAME_MAX_LENGTH + 1]; ///< Name of the streaming session.
  FUint32 streamingContentId;                                              ///< Streaming content format identifier.
  TBool isLiveStreaming;                                                   ///< Description if the content is live streamig or not.
  TBool is_DRM_Protected;                                                  ///< Description if the content is DRM protected or not.
} TMMEMediaProperties;

#ifdef DB3350
typedef struct MME_DATA
{
  char dummy_1[0x48];                  ///< unknown value
  FUint8 contentType;                  ///< Type of content, @see TMMEContentType.
  char dummy_2[0x3];                   ///< unknown value
  TMMETime mediaLength;                ///< Media file total playback time, @see TMMETime.
  FUint8 fileFormatId;                 ///< Media file format identifier.
  FUint8 fileFormatType;               ///< File format type description, @see TMMEFileFormatIdType.
  FUint8 audioOutput;                  ///< Mono/stereo audio output, @see TMMEAudioOutput.
  FUint8 audioCodecId;                 ///< Audio codec identifier (EMP value, to be used mainly for DRM checks).
  FUint32 audioCodecType;              ///< Audio codec id type description, @see TMMEAudioCodecIdType.
  FUint32 audioSampleRate;             ///< Sample rate of the audio encoding, values from 0 to 4294967295 Hz.
  FUint16 bpmTempo;                    ///< Beats-per-minute tempo. Only valid for MIDI and iMelody files.
  TBool videoImageSizePresent;         ///< TRUE if there is available information about VideoImageSize.
  TMMEVideoImageSize videoImageSize;   ///< Video image size, @see TMMEVideoImageSize.
  FUint8 videoCodecId;                 ///< Video codec id of an video encoding type.
  TMMEVideoCodecIdType videoCodecType; ///< Video codec id type description, @see TMMEVideoCodecIdType.

  TChar streamingSessionName[MME_STREAMING_SESSION_NAME_MAX_LENGTH + 1]; ///< Name of the streaming session.
  FUint32 streamingContentId;                                            ///< Streaming content format identifier.
  TBool isLiveStreaming;                                                 ///< Description if the content is live streamig or not.
  TBool is_DRM_Protected;                                                ///< Description if the content
} MME_DATA;
#else
typedef struct MME_DATA
{
  char dummy[0x2C];
  FUint8 contentType;                                                    ///< Type of content, @see TMMEContentType.
  char dummy_2[0x3];                                                     ///< unknown value
  TMMETime mediaLength;                                                  ///< Media file total playback time, @see TMMETime.
  FUint8 fileFormatId;                                                   ///< Media file format identifier.
  FUint8 fileFormatType;                                                 ///< File format type description, @see TMMEFileFormatIdType.
  FUint8 audioOutput;                                                    ///< Mono/stero audio output, @see TMMEAudioOutput.
  FUint8 audioCodecId;                                                   ///< Audio codec identifier (EMP value, to be used mainly for DRM checks).
  FUint32 audioCodecType;                                                ///< Audio codec id type description, @see TMMEAudioCodecIdType.
  FUint32 audioSampleRate;                                               ///< Sample rate of the audio encoding, values from 0 to 4294967295 Hz.
  FUint16 bpmTempo;                                                      ///< Beats-per-minute tempo. Only valid for MIDI and iMelody files.
  TBool videoImageSizePresent;                                           ///< TRUE if there is available information about VideoImageSize.
  TMMEVideoImageSize videoImageSize;                                     ///< Video image size, @see TMMEVideoImageSize.
  FUint8 videoCodecId;                                                   ///< Video codec id of an video encoding type.
  TMMEVideoCodecIdType videoCodecType;                                   ///< Video codec id type description, @see TMMEVideoCodecIdType.
  TChar streamingSessionName[MME_STREAMING_SESSION_NAME_MAX_LENGTH + 1]; ///< Name of the streaming session.
  FUint32 streamingContentId;                                            ///< Streaming content format identifier.
  TBool isLiveStreaming;                                                 ///< Description if the content is live streamig or not.
  TBool is_DRM_Protected;                                                ///< Description if the content
} MME_DATA;
#endif
/**
 * The set of media formats contained in a media file.
 */
typedef struct
{
  // File format
  TMMEFileFormatIdType fileFormatType; ///< File format type description, @see TMMEFileFormatIdType.

  // Audio
  FUint8 audioCodecId;                 ///< Audio codec identifier.
  TMMEAudioCodecIdType audioCodecType; ///< Audio codec id type description, @see TMMEAudioCodecIdType.

  // Video
  FUint8 videoCodecId;                 ///< Video codec id of an video encoding type.
  TMMEVideoCodecIdType videoCodecType; ///< Video codec id type description, @see TMMEVideoCodecIdType.
} TMMEMediaFormats;

#ifdef DB3150v1
typedef enum
{
  TMMEEqBand_63,
  TMMEEqBand_250,
  TMMEEqBand_1000,
  TMMEEqBand_4000,
  TMMEEqBand_16000,
  TMMEEqBand_Last
} TMusicServer_EqBand;
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
#else
typedef enum
{
  TMMEEqBand_ClearBass1,
  TMMEEqBand_ClearBass2,
  TMMEEqBand_63,
  TMMEEqBand_250,
  TMMEEqBand_400,
  TMMEEqBand_1000,
  TMMEEqBand_2500,
  TMMEEqBand_4000,
  TMMEEqBand_6300,
  TMMEEqBand_16000,
  TMMEEqBand_Last
} TMMEEqBand;
#endif
/**
 * The different equalizer presets. Only avaialble for Clear Audio!
 */
typedef enum
{
  TMMEEqPreset_Normal,
  TMMEEqPreset_Heavy,
  TMMEEqPreset_Pops,
  TMMEEqPreset_Jazz,
  TMMEEqPreset_Unique,
  TMMEEqPreset_Soul,
  TMMEEqPreset_EasyListening,
  TMMEEqPreset_BassBoost,
  TMMEEqPreset_TrebleBoost,

  // Always have this as the last preset
  TMMEEqPreset_Last
} TMMEEqPreset;

/**
 * The set of display options where to show the video.
 */
typedef enum
{
  TMMEDisplay_Main,   ///< Main display
  TMMEDisplay_Second, ///< Second display. Used on clam phones.
  TMMEDisplay_Last
} TMMEDisplay;

/**
 * The set of data to describe where to draw video on the display.
 *
 * Contains:
 *
 * X      (TSigned)   - Start point, x-coordinate of the upper left corner of the rectangle.
 * Y      (TSigned)   - Start point, y-coordinate of the upper left corner of the rectangle.
 * Width  (TUnsigned) - Witdh of the rectangle.
 * Height (TUnsigned) - Height of the rectangle.
 */
typedef TUIRectangle TMMEVideoArea;

/**
 * The set of video display orientations,
 * i.e. how the video area will be shown on the display.
 * The video orientation can be rotated and/or mirrored.
 */
typedef enum
{
  TMMEDisplayOrientation_Portrait = 0x00000000,  ///< Show video in portrait orientation.
  TMMEDisplayOrientation_Landscape = 0x00000001, ///< Show video rotated 90 degrees clockwise compared
                                                 ///< to portrait orientation.
  TMMEDisplayOrientation_Mirror_X = 0x00000002,  ///< Show video mirrored around a vertical axis located
                                                 ///< in the center of the display.
  TMMEDisplayOrientation_Mirror_Y = 0x00000004,  ///< Show video mirrored around a horizontal axis
                                                 ///< located in the center of the display.
  TMMEDisplayOrientation_Last                    ///< Place holder. Put new data before this!
} TMMEDisplayOrientation;

/**
 * This type is used to store display orientation flags. The field is
 * computed by bitwise 'or' different TMMEDisplayOrientation together.
 * All combinations are valid.
 */
typedef int TMMEGuiDisplayOrientationFlagField;

/**
 * The set of streaming connection types.
 */
typedef enum
{
  TMMEStreamingConnectionType_Network,     ///< Network connection.
  TMMEStreamingConnectionType_MediaServer, ///< Media server connection.
  TMMEStreamingConnectionType_Last         ///< Place holder
} TMMEStreamingConnectionType;

/**
 * The set of IP (internet protocol)
 * address family.
 */
typedef enum
{
  TMMEAddressFamily_Unspecified, ///< Address family is not specified.
  TMMEAddressFamily_IPV4,        ///< The IPv4 address family.
  TMMEAddressFamily_IPV6,        ///< The IPv6 address family.
  TMMEAddressFamily_Packet       ///< The packet address family.
} TMMEAddressFamily;

const int MME_AUDIOCONTROL_HANDLE_NOT_USED = 0;

/**
 * This type is used to indicate the fade direction when
 * using fading sound in an MME player.
 */
typedef enum
{
  TMMEFadeDirection_None,
  TMMEFadeDirection_Up,
  TMMEFadeDirection_Down
} TMMEFadeDirection;

/**
 * This type is used to indicate the fade reason.
 */
typedef enum
{
  TMMEFadeReason_Play,
  TMMEFadeReason_Stop,
  TMMEFadeReason_Suspend
} TMMEFadeReason;

/**
 * This type is used to indicate mute reason received from lower layer (Audio Control).
 */
typedef enum
{
  TMMEMuteReason_Accessory_Detached
} TMMEMuteReason;

/**
 * This type is used to configure the fastforward and rewind operation when a
 * boundary is reached (end of file or beginning of file).
 *
 * E.g. if the TMMEWindCondition_BOF_Paused is set the player will
 * pause, instead of stop, when the beginning of the file is reached.
 */
typedef enum
{
  TMMEWindCondition_EOF_Stopped = 0x00000000, ///< Player will be stopped when end of file is reached.
  TMMEWindCondition_BOF_Stopped = 0x00000001, ///< Player will be stopped when beginning of file is reached.
  TMMEWindCondition_EOF_Paused = 0x00000002,  ///< Overrides TMMEWindCondition_EOF_Stopped.
                                              ///< Player will be paused when end of file is reached.
  TMMEWindCondition_BOF_Paused = 0x00000004,  ///< Overrides TMMEWindCondition_BOF_Stopped.
                                              ///< Player will be paused when beginning of file is reached.
  TMMEWindCondition_Last                      ///< Place holder. Put new data before this!
} TMMEWindCondition;

/**
 * This type is used to store wind condition flags. The field is
 * computed by bitwise 'or' different TMMEWindCondition together.
 */
typedef FUint16 TMMEWindConditionFlagField;

#endif
