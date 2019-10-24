#ifndef __MULTIMEDIA_TYPES_H__
#define __MULTIMEDIA_TYPES_H__

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\Time_types.h"


//-----------------------------------------------------------------------
/**
    *   This enum specifies the clockwise rotation angle. Use MULTIMEDIA_ROTATION_ANGLE_0
    *   when no rotation is desired.
    *
    *   @param  MULTIMEDIA_ROTATION_ANGLE_0         No rotation
    *   @param  MULTIMEDIA_ROTATION_ANGLE_90        90 degrees clockwise rotation
    *   @param  MULTIMEDIA_ROTATION_ANGLE_180       180 degrees rotation
    *   @param  MULTIMEDIA_ROTATION_ANGLE_270       270 degrees clockwise rotation
    *   
    */
typedef enum
{
    MULTIMEDIA_ROTATION_ANGLE_0,
    MULTIMEDIA_ROTATION_ANGLE_90,
    MULTIMEDIA_ROTATION_ANGLE_180,
    MULTIMEDIA_ROTATION_ANGLE_270
}TMultimediaRotationAngle;

/**
  * Priority for playing audio.
  *
  * @param MULTIMEDIA_PLAY_PRIORITY_LOW   Use low priority in most situations.
  * @param MULTIMEDIA_PLAY_PRIORITY_HIGH  High priority may interrupt low priority.
  */
typedef enum {
  MULTIMEDIA_PLAY_PRIORITY_LOW,
  MULTIMEDIA_PLAY_PRIORITY_HIGH
} TMultimediaPlayPriority;

/**
  * Reasons that trigger multimedia messages.
  *
  * @param  MULTIMEDIA_EVENT_CAUSE_ERROR                       Error occurred while playing or recording. 
  * @param  MULTIMEDIA_EVENT_CAUSE_END_OF_FILE                 The player stopped because end of file was reached.
  * @param  MULTIMEDIA_EVENT_CAUSE_INTERRUPTED                 The player was stopped by the application or interrupted
  *	                                                           by another player (with higher priority) or a call.
  * @param  MULTIMEDIA_EVENT_CAUSE_FILESYSTEM_FULL             File system full; can happen when recording audio or video.
  * @param  MULTIMEDIA_EVENT_CAUSE_FILE_LIMIT_REACHED  The size limit specified for an audio or video recording is reached.
  * @param  MULTIMEDIA_EVENT_CAUSE_TIME_LIMIT_REACHED  The time limit specified for a video recording is reached.
  * @param  MULTIMEDIA_EVENT_CAUSE_RECORDER_STOP       Recorder was stopped by the application, interrupted by a call, or 
  *                                                    stopped by some other internal (error) cause that is possible to handle. 
  *                                                    The recorded output is valid.
  * @param  MULTIMEDIA_EVENT_CAUSE_DRM_RENDERING_TIME_EXPIRED  DRM rendering time expired.
  */
typedef enum {
  MULTIMEDIA_EVENT_CAUSE_ERROR,
  MULTIMEDIA_EVENT_CAUSE_END_OF_FILE,
  MULTIMEDIA_EVENT_CAUSE_INTERRUPTED,
  MULTIMEDIA_EVENT_CAUSE_FILESYSTEM_FULL,
  MULTIMEDIA_EVENT_CAUSE_FILE_LIMIT_REACHED,
  MULTIMEDIA_EVENT_CAUSE_TIME_LIMIT_REACHED,
  MULTIMEDIA_EVENT_CAUSE_RECORDER_STOP,
  MULTIMEDIA_EVENT_CAUSE_DRM_RENDERING_TIME_EXPIRED
} TMultimediaEventCause;

/**
  * This struct describes the time representation for multimedia.
  * 
  * @param Hours Number of hours.
  * @param Minutes Number of minutes (0 - 59).
  * @param Seconds Number of seconds (0 - 59).
  * @param MilliSeconds Number of milliseconds (0 - 999).
  */
typedef struct {
  THour  Hours;
  TMinute  Minutes;
  TSecond  Seconds;
  TMillisecond MilliSeconds;
} TMultimediaTime;

/**
  * Index to the selected content of a 3GP file.
  */
typedef FUint16 TMultimedia3GpIndex;

/**
  * Number of voices allocated in the synthesizer.
  */
typedef FUint8 TMultimediaNrOfMidiVoices;

/**
  * The buffering progress in percent. Valid range is 0-100. 
  */
typedef FUint8 TMultimediaBufferingProgress;


//-----------------------------------------------------------------------
// NEW TYPES

/**
  * ID of a multimedia format. The format ID must be supplied in  
  * <link>IPlayerManager::GetFileProperties</link>
  * and the Init methods for the audio and video players. Information about the format ID
  * can be retrieved from <link>IPlayerManager::GetMultimediaFormats</link> that returns a 
  * list of items all of the <link>::TMultimediaFormatInfo</link> type. 
  */
typedef FUint8 TMultimediaFormatId;

/**
  * ID of an audio format. The audio format ID is returned by
  * <link>IPlayerManager::GetFileProperties</link>.
  * Information about the format can be retrieved from the <link>::TMultimediaAudioCodecFormat</link> type. 
  */
typedef FUint8 TMultimediaAudioFormatId;

/**
  * ID of a video format. The video format ID is returned by <link>IPlayerManager::GetFileProperties</link>.
  * Information about the format can be retrieved from the <link>::TMultimediaVideoCodecFormat</link> type. 
  */
typedef FUint8 TMultimediaVideoFormatId;

/**
  * Maximum multimedia file name string length.
  */

const TUnsigned MULTIMEDIA_FILE_NAME_STRING_MAX_LENGTH = 256;

/**
  * Maximum length of a file extension.
  */
const TUnsigned MULTIMEDIA_FILE_EXTENSION_MAX_LENGTH = 4;

/**
  * Maximum length of a codec description.
  */
const TUnsigned MULTIMEDIA_CODEC_DESCRIPTION_MAX_LENGTH = 15;

/**
  * Maximum length of a format description.
  */
const TUnsigned MULTIMEDIA_FORMAT_DESCRIPTION_MAX_LENGTH = 15;

/**
  * Maximum number of bytes of media data that can be stored in the <link>::TMultimediaMediaContainer</link>.
  */
const TUnsigned MULTIMEDIA_MAX_MEDIA_DATA_SIZE = 2048;

/**
  * The common file extension of an audio or video format.
  */
typedef TChar TMultimediaFileExtension[MULTIMEDIA_FILE_EXTENSION_MAX_LENGTH + 1];

/**
  * A textual description of the audio or video format handled by a codec.
  */
typedef TChar TMultimediaCodecDescription[MULTIMEDIA_CODEC_DESCRIPTION_MAX_LENGTH + 1];

/**
  * A textual description of the audio or video format handled by a codec.
  */
typedef TChar TMultimediaFormatDescription[MULTIMEDIA_FORMAT_DESCRIPTION_MAX_LENGTH + 1];

/**
  * This struct contains information about an audio format supported
  * by a codec. Each content has a FormatId, a short textual description
  * and a common file extension used for the format. The audio format ID
  * is retrieved from <link>IPlayerManager::GetFileProperties</link>.
  * If no formats are available, one item - indicating No format - is returned.
  *
  * @param  FormatId            The ID of an audio content format.
  * @param  Description         A short textual explanation of the audio format. 
  * @param  FileExtension       The common file extension used for the audio format.
  */
typedef struct
{
  TMultimediaAudioFormatId            FormatId;
  TMultimediaCodecDescription         Description;
  TMultimediaFileExtension            FileExtension;
} TMultimediaAudioCodecFormat;

/**
  * This struct contains information about a video format supported
  * by a codec. Each format has a FormatId, a short textual description
  * and a common file extension used for the format. The video format ID
  * is retrieved from <link>IPlayerManager::GetFileProperties</link>.
  *
  * @param  FormatId        The ID of a video content format.
  * @param  Description     A short textual explanation of the video format. 
  * @param  FileExtension   The common file extension used for the video format.
  */
typedef struct
{
  TMultimediaVideoFormatId            FormatId;
  TMultimediaCodecDescription         Description;
  TMultimediaFileExtension            FileExtension;
} TMultimediaVideoCodecFormat;

/**
  * This struct contains a combination of a MIME type, a file extension
  * and a format  ID. It also contains a short textual description
  * used for the format. Use the format ID when initiating an
  * audio or video player or getting the properties of a file.
  *
  * @param  FormatId            The ID of a format.
  * @param  MimeType            MIME type of the format.
  * @param  Description         A short textual explanation of the format. 
  * @param  FileExtension       A file extension used for the format.
  */
typedef struct
{
  TMultimediaFormatId           FormatId;
  TMimeType                     MimeType;
  TMultimediaFormatDescription  Description;
  TMultimediaFileExtension      FileExtension;
} TMultimediaFormatInfo;


//-----------------------------------------------------------------------
// TYPES needed for GetFileProperties

/**
  * This type describes if the content is mono or stereo. This information is 
  * needed, for example, when opening the correct AudioChannel. Ignore this parameter 
  * if no audio content exists.
  *
  * @param  MULTIMEDIA_AUDIO_OUTPUT_MONO      Mono audio output.
  * @param  MULTIMEDIA_AUDIO_OUTPUT_STEREO    Stereo audio output.
  * @param  MULTIMEDIA_AUDIO_OUTPUT_UNKNOWN   Unknown output.
  */
typedef enum{
  MULTIMEDIA_AUDIO_OUTPUT_MONO,
  MULTIMEDIA_AUDIO_OUTPUT_STEREO,
  MULTIMEDIA_AUDIO_OUTPUT_UNKNOWN
} TMultimediaAudioOutput;

/**
  * Bit rate of an AMR file.
  *
  * @param  MULTIMEDIA_AMR_BIT_RATE_4750           Bit rate 4750.
  * @param  MULTIMEDIA_AMR_BIT_RATE_5150           Bit rate 5150.
  * @param  MULTIMEDIA_AMR_BIT_RATE_5900           Bit rate 5900.
  * @param  MULTIMEDIA_AMR_BIT_RATE_6700           Bit rate 6700.
  * @param  MULTIMEDIA_AMR_BIT_RATE_7400           Bit rate 7400.
  * @param  MULTIMEDIA_AMR_BIT_RATE_7950           Bit rate 7950.
  * @param  MULTIMEDIA_AMR_BIT_RATE_10200          Bit rate 10200.
  * @param  MULTIMEDIA_AMR_BIT_RATE_12200          Bit rate 12200.
  * @param  MULTIMEDIA_AMR_BIT_RATE_NOT_AVAILABLE  Bit rate not available. Used when AMR (Adaptive Multi-Rate) is not available.
  */
typedef enum {
  MULTIMEDIA_AMR_BIT_RATE_4750,
  MULTIMEDIA_AMR_BIT_RATE_5150,
  MULTIMEDIA_AMR_BIT_RATE_5900,
  MULTIMEDIA_AMR_BIT_RATE_6700,
  MULTIMEDIA_AMR_BIT_RATE_7400,
  MULTIMEDIA_AMR_BIT_RATE_7950,
  MULTIMEDIA_AMR_BIT_RATE_10200,
  MULTIMEDIA_AMR_BIT_RATE_12200,
  MULTIMEDIA_AMR_BIT_RATE_NOT_AVAILABLE
} TMultimediaAmrBitRate; 

/**
  * This struct describes the video-image size in pixels.
  *
  * @param Height Height in pixels.
  * @param Width Width in pixels.
  */
typedef struct {
  TUnsigned Height; 
  TUnsigned Width; 
} TMultimediaVideoImageSize;

/**
  * This type indicates if the media is audio, video, or audio and video.
  *
  * @param  MULTIMEDIA_CONTENT_VIDEO_AND_AUDIO  File containing both audio and video.
  * @param  MULTIMEDIA_CONTENT_VIDEO            File only containing video.
  * @param  MULTIMEDIA_CONTENT_AUDIO            File only containing audio.
  */
typedef enum{
  MULTIMEDIA_CONTENT_VIDEO_AND_AUDIO,
  MULTIMEDIA_CONTENT_VIDEO,
  MULTIMEDIA_CONTENT_AUDIO
} TMultimediaContent;

/**
  * Sample rate of audio content in Hz.
  */
typedef FUint32 TMultimediaAudioSampleRate;

/**
  * Beats-per-minute (BPM) tempo.
  */
typedef FUint16 TMultimediaBpmTempo;

/**
  * This type describes the content properties of a media file.
  *
  * @param AudioFormatId    Audio format ID, maps against the ID in the <link>::TMultimediaAudioCodecFormat</link> type.
  * @param VideoFormatId    Video format ID, maps against the ID in the <link>::TMultimediaVideoCodecFormat</link> type.
  * @param VideoImageSize   Size of the video image in pixels.
  * @param Content          Audio and/or video content.
  * @param AudioOutput      Stereo or mono audio content. Ignore this parameter if no audio content exists.
  * @param MediaLength      Length of the media clip. Can be 0 if information is not available in the file.
  * @param MediaLengthIsAccurate  If TRUE, the MediaLength member of this struct holds a valid accurate value 
  *                         of the media clip length. 
  *                         If FALSE, the MediaLength value (if not 0)
  *                         is an approximation.
  * @param AudioSampleRate  Sample rate of the audio content.
  * @param BpmTempo         Beats-per-minute tempo. Only valid for MIDI and iMelody files.
  * @param MediaDataSize    Data size in bytes of the media clip. It is possible to allocate a larger data area (in the file system or in memory) 
  *                         than necessary for a media clip. Part of the allocated data area is then filled with media data and 
  *                         the rest with uninitialised data. The media data size is the part of the allocated data area that contains media 
  *                         clip data. Note that MediaDataSize is only valid for 3GP files.
  * @param NumberOfTimedTextTracks 
  *    The number of Timed Text Tracks. If value is larger than 0 this means that a Timed Text Control could be created to
  *    control the Timed Text functionality. See <link target="Multimedia_TimedText_Intro_TEXT">Timed Text Introduction</link>. 
  */
typedef struct {
  TMultimediaAudioFormatId    AudioFormatId;
  TMultimediaVideoFormatId    VideoFormatId;
  TMultimediaVideoImageSize   VideoImageSize;
  TMultimediaContent          Content;
  TMultimediaAudioOutput      AudioOutput;
  TMultimediaTime             MediaLength;
  TBool                       MediaLengthIsAccurate;
  TMultimediaAudioSampleRate  AudioSampleRate;
  TMultimediaBpmTempo         BpmTempo;
  TUnsigned                   MediaDataSize;
  TUnsigned                   NumberOfTimedTextTracks;
} TMultimediaFileProperties;


//-----------------------------------------------------------------------
// TONE TYPES

/**
  * Different iMelody tones with frequencies in mHz.
  * 
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_C   C   (523250 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_D   D   (587330 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_E   E   (659260 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_F   F   (698460 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_G   G   (783990 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_A   A   (880000 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_BASIC_B   B   (987770 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_D_FLAT    Db  (554370 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_E_FLAT    Eb  (622250 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_G_FLAT    Gb  (739990 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_A_FLAT    Ab  (830610 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_B_FLAT    Bb  (932330 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_C_SHARP   C# = Db  (554370 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_D_SHARP   D# = Eb  (622250 mHz). 
  * @param MULTIMEDIA_IMELODY_TONE_F_SHARP   F#  (739990 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_G_SHARP   G#  (830610 mHz).
  * @param MULTIMEDIA_IMELODY_TONE_A_SHARP   A#  (932330 mHz).
  */
typedef enum {
  MULTIMEDIA_IMELODY_TONE_BASIC_C,
  MULTIMEDIA_IMELODY_TONE_BASIC_D,
  MULTIMEDIA_IMELODY_TONE_BASIC_E,
  MULTIMEDIA_IMELODY_TONE_BASIC_F,
  MULTIMEDIA_IMELODY_TONE_BASIC_G,
  MULTIMEDIA_IMELODY_TONE_BASIC_A,
  MULTIMEDIA_IMELODY_TONE_BASIC_B,
  MULTIMEDIA_IMELODY_TONE_D_FLAT,
  MULTIMEDIA_IMELODY_TONE_E_FLAT,
  MULTIMEDIA_IMELODY_TONE_G_FLAT,
  MULTIMEDIA_IMELODY_TONE_A_FLAT,
  MULTIMEDIA_IMELODY_TONE_B_FLAT,
  MULTIMEDIA_IMELODY_TONE_C_SHARP,
  MULTIMEDIA_IMELODY_TONE_D_SHARP,
  MULTIMEDIA_IMELODY_TONE_F_SHARP,
  MULTIMEDIA_IMELODY_TONE_G_SHARP,
  MULTIMEDIA_IMELODY_TONE_A_SHARP
} TMultimediaImelodyTone;

/**
  * Tone duration
  * @param MULTIMEDIA_NOTE_DURATION_WHOLE_NOTE Length = 2s . This is the default tempo and corresponds to BPM = 120.
  * @param MULTIMEDIA_NOTE_DURATION_HALF_NOTE Length = 1s
  * @param MULTIMEDIA_NOTE_DURATION_QUARTER_NOTE  Length = 1/2s 
  * @param MULTIMEDIA_NOTE_DURATION_EIGHTH_NOTE  Length = 1/4s 
  * @param MULTIMEDIA_NOTE_DURATION_SIXTEENTH_NOTE  Length = 1/8s 
  * @param MULTIMEDIA_NOTE_DURATION_THIRTYSECOND_NOTE Length = 1/16s 
  */
typedef enum {
  MULTIMEDIA_NOTE_DURATION_WHOLE_NOTE,
  MULTIMEDIA_NOTE_DURATION_HALF_NOTE,
  MULTIMEDIA_NOTE_DURATION_QUARTER_NOTE,
  MULTIMEDIA_NOTE_DURATION_EIGHTH_NOTE,
  MULTIMEDIA_NOTE_DURATION_SIXTEENTH_NOTE,
  MULTIMEDIA_NOTE_DURATION_THIRTYSECOND_NOTE
} TMultimediaNoteDuration;

/**
  * Different octaves used for iMelody.
  *
  * @param MULTIMEDIA_OCTAVE_0 Octave 0
  * @param MULTIMEDIA_OCTAVE_1 Octave 1
  * @param MULTIMEDIA_OCTAVE_2 Octave 2
  * @param MULTIMEDIA_OCTAVE_3 Octave 3
  * @param MULTIMEDIA_OCTAVE_4 Octave 4 (default iMelody) 
  * @param MULTIMEDIA_OCTAVE_5 Octave 5
  * @param MULTIMEDIA_OCTAVE_6 Octave 6 
  * @param MULTIMEDIA_OCTAVE_7 Octave 7
  * @param MULTIMEDIA_OCTAVE_8 Octave 8
  */
typedef enum {
  MULTIMEDIA_OCTAVE_0,
  MULTIMEDIA_OCTAVE_1,
  MULTIMEDIA_OCTAVE_2,
  MULTIMEDIA_OCTAVE_3,
  MULTIMEDIA_OCTAVE_4,
  MULTIMEDIA_OCTAVE_5,
  MULTIMEDIA_OCTAVE_6,
  MULTIMEDIA_OCTAVE_7,
  MULTIMEDIA_OCTAVE_8
} TMultimediaOctave;

/**
  * iMelody note, consists of the tone, octave, and duration.
  *
  * @param ImelodyTone The tone to play.
  * @param NoteDuration The length of the note.
  * @param Octave The note is played in this octave.
  */
typedef struct {
  TMultimediaImelodyTone ImelodyTone;
  TMultimediaNoteDuration NoteDuration;
  TMultimediaOctave Octave;
} TMultimediaImelodyNote;


/**
  * Struct to pack data bit streams
  *
  * @param ContainerSize The size of the complete container.
  * @param Timestamp The timestamp in milliseconds of the first media frame in the payload. The timestamp is used
  *        to define when in time the frame is to be played in relation to other frames.<break/>
  *        Note that the timestamp does not start at zero for the first container of a stream; it can start at any value. 
  *        If the media frames encapsulated within the TMultimediaMediaContainer contains timestamps themselves, the timestamp of the 
  *        container must be synchronous with, but not necessarily identical to, the timestamp of the encapsulated media frames.
  *
  * @param PacketMarker Media specific: 
  *                     <ul>
  *                     <li>H.263: TRUE indicates last media transfer of a frame.</li> 
  *                     <li>AMR: TRUE indicates the first non-silence frame.</li> 
  *                     <li>PCM: Has no meaning and is ignored.</li>
  *                     </ul>
  * @param FrameCount Number of media frames, in case the media format is either H.263 or AMR. 
  *                   In case of PCM (Pulse Code Modulation), this parameter is ignored.
  * @param DataSize The size in bytes of the data carried in the container.
  * @param MediaData The media data (max size MULTIMEDIA_MAX_MEDIA_DATA_SIZE).
  */

typedef struct 
{    
  FUint32   ContainerSize; 
  FUint32   Timestamp;
  TBool     PacketMarker; 
  FUint16   FrameCount; 
  FUint16   DataSize; 
  FUint8    MediaData[MULTIMEDIA_MAX_MEDIA_DATA_SIZE];
}TMultimediaMediaContainer;

/**
  * This type specifies information about a Multimedia Control.
  *
  * @param Iid                    
  *    Specifies the interface identity of a Multimedia Control.
  *
  *    The pointer to the interface identity can be used as the <cit>pIid</cit> 
  *    input parameter to a 
  *    <link target="IMultimediaControllable::CreateControl">CreateControl</link> 
  *    method.
  */
typedef struct 
{
  TUuid                  Iid;
} TMultimediaControlInfo;

//-----------------------------------------------------------------------
/**
  * Domain-specific field of Multimedia return codes.
  *
  * Future versions may return values other than those specified by this type.
  * Handle any such values in the same 
  * way as if <cit>MULTIMEDIA_UED_UNSPECIFIED</cit> was returned.
  *
  * Make sure values other than those specified here are not used.
  *
  * @param  MULTIMEDIA_UED_UNSPECIFIED         
  *    This value indicates that the domain specific value is not applicable.
  * @param  MULTIMEDIA_UED_CONTROL_NOT_APPLICABLE       
  *    The component implementing the IMultimediaControllable interface
  *    can not create a control since it is not applicable to the
  *    current file or stream. For example, a player component can not
  *    create a control if the file does not support that functionality.
  *    <break/>Classification: OPA_UEC_PRECOND   
  *    <break/>Extension     : OPA_UEE_PRECOND_STATE
  */
typedef enum
{
  MULTIMEDIA_UED_UNSPECIFIED  = 0x00,
  MULTIMEDIA_UED_CONTROL_NOT_APPLICABLE = 0x01
} TMultimediaUed;


/**
  * Multimedia stream identifier. 
  * For streaming content this corresponds to <link target="Player_types::TPlayerContentId">TPlayerContentId</link>.
  * For Mobile TV content this corresponds to <link target="MobileTvPlayer_types::TMobileTvPlayerStreamId">TMobileTvPlayerStreamId</link>.
  * <link target="Multimedia_types::MULTIMEDIA_STREAM_ID_DEFAULT">MULTIMEDIA_STREAM_ID_DEFAULT</link> is a reserved value used when 
  * the stream concept is not applicable.
  */
typedef FUint32 TMultimediaStreamId; 


/**
  * Reserved value used to indicate the default multimedia stream.
  */
const TMultimediaStreamId MULTIMEDIA_STREAM_ID_DEFAULT = 0xFFFFFFFF;

//@} End of Types

#endif
