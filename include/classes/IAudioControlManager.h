#ifndef _IAUDIOCONTROLMANAGER_H_
#define _IAUDIOCONTROLMANAGER_H_

// const UUID CID_CAudioControlManager = {0xE2, 0x00, 0x10, 0x71, 0x81, 0xD3, 0x43, 0xC3, 0xAB, 0xEA, 0xD4, 0xF4, 0xEB, 0x67, 0xC8, 0x93};
// const UUID IID_IAudioControlManager = {0x78, 0x0E, 0x15, 0xD9, 0x40, 0xF5, 0x4F, 0x99, 0xAF, 0x93, 0x38, 0x3B, 0x38, 0x7F, 0xA7, 0xED};

#define MAX_MEDIAVOLUME 15
#define MAX_CALLVOLUME 8
#define MAX_RINGVOLUME 8

const uint16_t AUDIOCONTROL_DEBUGMENU_STRING_MAXLENGTH = 79;
typedef wchar_t TAudioControl_DebugMenuString[AUDIOCONTROL_DEBUGMENU_STRING_MAXLENGTH + 1];

typedef enum
{
  AUDIOCONTROL_UED_GENERAL_ERROR = 0x000, /**< Returned when none of the other error codes are applicable */

  /* AudioPlayer specific return values */
  AUDIOCONTROL_UED_NOT_AUTHORIZED = 0x001, /**< Returned when there are not any available resources, and another ongoing activity has higher priority */
  AUDIOCONTROL_UED_FILE_NOT_FOUND = 0x002, /**< Returned when the specified file is not found */
  AUDIOCONTROL_UED_DRM_ERROR = 0x004,      /**< Returned when the specified file is a DRM file, and the credentials not allows playback */

  /* Internal ac channel return value */
  AUDIOCONTROL_UED_ROUTED_TO_SILENT = 0x008, /**< Returned when no channel delivered due to internal channelsetting AUDIOCONTROL_CHANNELSETTING_NO_CHANNEL_IF_SILENT  */

  /* Accessory specific return values */
  AUDIOCONTROL_UED_NO_SUCH_DEVICE = 0x010, /**< Unknown accessory */

  /* General return values, used for all categories */
  AUDIOCONTROL_UED_NOT_SUPPORTED = 0x020,    /**< Returned when some functionality not is supported with the current platform configuration */
  AUDIOCONTROL_UED_OPA_ERROR = 0x040,        /**< Returned when OPA is returning an error of unknown reason */
  AUDIOCONTROL_UED_OUT_OF_MEMORY = 0x080,    /**< Returned when some allocation failed due to lack of memory */
  AUDIOCONTROL_UED_INPUT_PARAM_ERROR = 0x100 /**< Returned when there was some error in the input parameters */
} TAudioControl_ReturnValues;

typedef enum
{
  AUDIOCONTROL_NOTIFICATION_RINGER,
  AUDIOCONTROL_NOTIFICATION_ALARM,
  AUDIOCONTROL_NOTIFICATION_REQUEST,
  AUDIOCONTROL_NOTIFICATION_REQUEST_CALL,
  AUDIOCONTROL_NOTIFICATION_SUCCESS,
  AUDIOCONTROL_NOTIFICATION_FAILURE,
  AUDIOCONTROL_NOTIFICATION_PROGRESS,
  AUDIOCONTROL_NOTIFICATION_NOTIFICATION,
  AUDIOCONTROL_NOTIFICATION_REMINDER,
  AUDIOCONTROL_NOTIFICATION_DISCONNECTED,
  AUDIOCONTROL_NOTIFICATION_DISCREET,
  AUDIOCONTROL_NOTIFICATION_LOWBATTERY,
  AUDIOCONTROL_NOTIFICATION_EMPTYBATTERY,
  AUDIOCONTROL_NOTIFICATION_CHARGING,
  AUDIOCONTROL_NOTIFICATION_VIDEO,
  AUDIOCONTROL_NOTIFICATION_RETRYSUCCESS,
  AUDIOCONTROL_NOTIFICATION_TIMER,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT_SILENT,
  AUDIOCONTROL_NOTIFICATION_MESSAGECLICK,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT1,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT2,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT3,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT4,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT5,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT6,

  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER,
  AUDIOCONTROL_NOTIFICATION_CAMERATIMER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER2,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER3,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER4,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER2_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER3_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER4_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERA_FOCUS_SUCCESS,
  AUDIOCONTROL_NOTIFICATION_CAMERA_BURST,
  AUDIOCONTROL_NOTIFICATION_CAMERA_BESTPIC,

  AUDIOCONTROL_NOTIFICATION_PTT_BUDDY_JOINED,
  AUDIOCONTROL_NOTIFICATION_PTT_BUDDY_LEFT,
  AUDIOCONTROL_NOTIFICATION_PTT_FLOOR_AVAILABLE,
  AUDIOCONTROL_NOTIFICATION_PTT_SPEAK_NOW,
  AUDIOCONTROL_NOTIFICATION_PTT_RINGTONE,
  AUDIOCONTROL_NOTIFICATION_PTT_BARGE_ALERT,
  AUDIOCONTROL_NOTIFICATION_PTT_FLOOR_TAKEN,

  AUDIOCONTROL_NOTIFICATION_SPORT_ABOVE_SPEED,
  AUDIOCONTROL_NOTIFICATION_SPORT_BELOW_SPEED,
  AUDIOCONTROL_NOTIFICATION_SPORT_START,
  AUDIOCONTROL_NOTIFICATION_SPORT_MILESTONE,
  AUDIOCONTROL_NOTIFICATION_SPORT_END,
  AUDIOCONTROL_NOTIFICATION_SPORT_FAILURE,

  AUDIOCONTROL_NOTIFICATION_IM_BUDDY_JOINED,
  AUDIOCONTROL_NOTIFICATION_IM_BUDDY_LEFT,

  AUDIOCONTROL_NOTIFICATION_PHONE_OPEN1,
  AUDIOCONTROL_NOTIFICATION_PHONE_OPEN2,
  AUDIOCONTROL_NOTIFICATION_PHONE_OPEN3,

  AUDIOCONTROL_NOTIFICATION_VIDEOCALLPREFIX,

  AUDIOCONTROL_NOTIFICATION_CALLERNAME,

  AUDIOCONTROL_NOTIFICATION_STARTUP,

  AUDIOCONTROL_NOTIFICATION_ILM_MTCALL,
  AUDIOCONTROL_NOTIFICATION_ILM_ALARM,
  AUDIOCONTROL_NOTIFICATION_ILM_MESSAGING,
  AUDIOCONTROL_NOTIFICATION_ILM_TIMER,
  AUDIOCONTROL_NOTIFICATION_ILM_CALEVENT,
  AUDIOCONTROL_NOTIFICATION_ILM_TEST,
  AUDIOCONTROL_NOTIFICATION_ILM_DEMO,
  AUDIOCONTROL_NOTIFICATION_ILM_INTRO,
  AUDIOCONTROL_NOTIFICATION_ILM_ACCESSORY,
  AUDIOCONTROL_NOTIFICATION_ILM_CHARGEBATT,
  AUDIOCONTROL_NOTIFICATION_ILM_PREVIEW,
  AUDIOCONTROL_NOTIFICATION_ILM_POWERUP,
  AUDIOCONTROL_NOTIFICATION_ILM_POWERDOWN,
  AUDIOCONTROL_NOTIFICATION_ILM_OPENFLIP,
  AUDIOCONTROL_NOTIFICATION_ILM_CLOSEFLIP,
  AUDIOCONTROL_NOTIFICATION_ILM_STARTSLEEP,
  AUDIOCONTROL_NOTIFICATION_ILM_ENDSLEEP,

  AUDIOCONTROL_NOTIFICATION_VT_SNAPSHOT,

  AUDIOCONTROL_NOTIFICATION_VC_FAILURE,
  AUDIOCONTROL_NOTIFICATION_VC_VOICETAG,

  AUDIOCONTROL_NOTIFICATION_MAM_GUIDANCE,

  AUDIOCONTROL_NOTIFICATION_LAST
} TAudioControl_Notification;

typedef enum
{
  /* Normal Tones, such as DTMF etc. They are directly mapped from OPA, see TTone in IToneManager.idl for more info */
  AUDIOCONTROL_TONE_OFF,
  AUDIOCONTROL_TONE_KEY_1,
  AUDIOCONTROL_TONE_KEY_2,
  AUDIOCONTROL_TONE_KEY_3,
  AUDIOCONTROL_TONE_KEY_4,
  AUDIOCONTROL_TONE_KEY_5,
  AUDIOCONTROL_TONE_KEY_6,
  AUDIOCONTROL_TONE_KEY_7,
  AUDIOCONTROL_TONE_KEY_8,
  AUDIOCONTROL_TONE_KEY_9,
  AUDIOCONTROL_TONE_KEY_0,
  AUDIOCONTROL_TONE_KEY_ASTERISK,
  AUDIOCONTROL_TONE_KEY_NUMBERSIGN,
  AUDIOCONTROL_TONE_KEY_A,
  AUDIOCONTROL_TONE_KEY_B,
  AUDIOCONTROL_TONE_KEY_C,
  AUDIOCONTROL_TONE_KEY_D,
  AUDIOCONTROL_TONE_SILENCE,
  AUDIOCONTROL_RING_TONE,
  AUDIOCONTROL_TRIPLE_TONE_950_HZ,
  AUDIOCONTROL_TRIPLE_TONE_1400_HZ,
  AUDIOCONTROL_TRIPLE_TONE_1800_HZ,
  AUDIOCONTROL_RING_TONE_500_HZ,
  AUDIOCONTROL_RING_TONE_1056_HZ,
  AUDIOCONTROL_RING_TONE_1750_HZ,
  AUDIOCONTROL_RING_TONE_1900_HZ,
  AUDIOCONTROL_RING_TONE_2000_HZ,
  AUDIOCONTROL_RING_TONE_2200_HZ,
  AUDIOCONTROL_RING_TONE_2800_HZ,
  AUDIOCONTROL_RING_TONE_480_620_HZ,
  AUDIOCONTROL_RING_TONE_440_HZ,
  AUDIOCONTROL_RING_TONE_440_480_HZ,

  /* Comfort Tones, directly mapped from OPA */
  AUDIOCONTROL_DIAL,                      /**< 425Hz continuous */
  AUDIOCONTROL_SUBSCRIBER_BUSY,           /**< 425Hz on 500ms, off 500ms continuous */
  AUDIOCONTROL_CONGESTION,                /**< 425Hz on 200ms, off 200ms continuous */
  AUDIOCONTROL_RADIO_PATH_ACKNOWLEDGE,    /**< 425Hz single tone 200ms */
  AUDIOCONTROL_RADIO_PATH_NOT_AVAILABLE,  /**< 425Hz 200ms on/off for 3 burst */
  AUDIOCONTROL_ERROR_SPECIAL_INFORMATION, /**< 950Hz, 1400Hz and 1800Hz triple tone, on 330ms, off 1s continuous */
  AUDIOCONTROL_CALL_WAITING,              /**< 425Hz on 200ms, off 600ms, on 200ms, off 3s continuous */
  AUDIOCONTROL_RINGING,                   /**< 425Hz on 1s, off 4s continuous */

  /* SAT Tones */
  AUDIOCONTROL_SAT_POSITIVEACK,
  AUDIOCONTROL_SAT_NEGATIVEACK,
  AUDIOCONTROL_SAT_GENERALBEEP,

  AUDIOCONTROL_TONE_LAST
} TAudioControl_Tone;

typedef enum
{
  AUDIOCONTROL_TONE_REDIRECTION_NEAR_END,         /**< The tone is played in the speaker */
  AUDIOCONTROL_TONE_REDIRECTION_NEAR_AND_FAR_END, /**< The tone is played in the speaker and is also sent to the remote party */
  AUDIOCONTROL_TONE_REDIRECTION_LAST
} TAudioControl_ToneRedirection;

typedef enum
{
  AUDIOCONTROL_VOLUMETYPE_CURRENT,     /**< The current volumetype */
  AUDIOCONTROL_VOLUMETYPE_CALLVOLUME,  /**< The call volume */
  AUDIOCONTROL_VOLUMETYPE_RINGVOLUME,  /**< The ring signal volume */
  AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, /**< The media volume */
  AUDIOCONTROL_VOLUMETYPE_INPUTVOLUME, /**< FOR AUDIOCONTROL INTERNAL USE ONLY */

  AUDIOCONTROL_VOLUMETYPE_LAST
} TAudioControl_VolumeType;

typedef enum
{
  AUDIOCONTROL_TTYMODE_OFF,      /**< TTY mode set to off*/
  AUDIOCONTROL_TTYMODE_STANDARD, /**< TTY mode set to standard*/
  AUDIOCONTROL_TTYMODE_HCO,      /**< TTY mode set to hearing carry over*/
  AUDIOCONTROL_TTYMODE_VCO,      /**< TTY mode set to voice carry over*/

  AUDIOCONTROL_TTYMODE_LAST
} TAudioControl_TTYMode;

typedef enum
{
  AUDIOCONTROL_HACMODE_OFF,
  AUDIOCONTROL_HACMODE_MIC,
  AUDIOCONTROL_HACMODE_TCOIL,

  AUDIOCONTROL_HACMODE_LAST
} TAudioControl_HACMode;

typedef enum
{
  AUDIOCONTROL_VIBRATORSTATE_OFF,         /**< The vibrator is always off */
  AUDIOCONTROL_VIBRATORSTATE_ON,          /**< The vibrator is used when appropriate */
  AUDIOCONTROL_VIBRATORSTATE_ON_IF_SILENT /**< The vibrator is used when appropriate, if silentmode is on */
} TAudioControl_VibratorState;

typedef enum
{
  AUDIOCONTROL_CALLTYPE_VOICE, /**< VoiceCall */
  AUDIOCONTROL_CALLTYPE_VIDEO, /**< VideoCall */

  AUDIOCONTROL_CALLTYPE_LAST
} TAudioControl_CallType;

typedef enum
{
  AUDIOCONTROL_CALLSTATE_IDLE,      /**< Should be used when no call is active */
  AUDIOCONTROL_CALLSTATE_ANSWERING, /**< Should be used before ICall_Answer to indicate that a call is about to be answered*/
  AUDIOCONTROL_CALLSTATE_ALERTING,  /**< Obsolete, replaced with AUDIOCONTROL_CALLSTATE_ANSWERING*/
  AUDIOCONTROL_CALLSTATE_SETUP,     /**< Should be used before initiating an outgoing call*/
  AUDIOCONTROL_CALLSTATE_ONGOING,   /**< Should be used when a call is active*/
  AUDIOCONTROL_CALLSTATE_HOLDING,   /**< Should be used when all calls are on hold*/

  AUDIOCONTROL_CALLSTATE_LAST
} TAudioControl_CallState;

typedef enum
{
  AUDIOCONTROL_FADE_DIRECTION_NONE,
  AUDIOCONTROL_FADE_DIRECTION_UP,
  AUDIOCONTROL_FADE_DIRECTION_DOWN,

  AUDIOCONTROL_FADE_DIRECTION_LAST
} TAudioControl_FadeDirection;

typedef enum
{
  AUDIOCONTROL_FADE_REASON_PLAY,
  AUDIOCONTROL_FADE_REASON_STOP,
  AUDIOCONTROL_FADE_REASON_SUSPEND,

  AUDIOCONTROL_FADE_REASON_LAST
} TAudioControl_FadeReason;

typedef enum
{
  AUDIOCONTROL_KEYSOUND_CLICK, /**< Keyclick */

  AUDIOCONTROL_KEYSOUND_TONE_KEY_1,          /**< Key 1 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_2,          /**< Key 2 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_3,          /**< Key 3 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_4,          /**< Key 4 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_5,          /**< Key 5 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_6,          /**< Key 6 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_7,          /**< Key 7 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_8,          /**< Key 8 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_9,          /**< Key 9 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_0,          /**< Key 0 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_ASTERISK,   /**< Key * */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_NUMBERSIGN, /**< Key # */

  AUDIOCONTROL_KEYSOUND_TONE, /**< General key */

  AUDIOCONTROL_KEYSOUND_LAST
} TAudioControl_KeySound;

typedef enum
{
  AUDIOCONTROL_ROUTING_PHONE,    /**< The Audio is routed to the phone */
  AUDIOCONTROL_ROUTING_ACCESSORY /**< The Audio is routed to an accessory */
} TAudioControl_AudioRouting;

typedef enum
{
  AUDIOCONTROL_SPEAKERMODE_OFF,               /**< Speaker mode set to off, normal routing rules apply */
  AUDIOCONTROL_SPEAKERMODE_FORCE_ON,          /**< Speaker mode set forcefully by application and will not be turned off if an accessory is attached */
  AUDIOCONTROL_SPEAKERMODE_USER_ON,           /**< Speaker mode has been set by user but will be turned off when an accessory is attached*/
  AUDIOCONTROL_SPEAKERMODE_ON_IF_NO_ACCESSORY /**< Speaker mode will be active if there is no accessory attached */
} TAudioControl_SpeakerMode;

typedef enum
{
  AUDIOCONTROL_COMFORT_TONE_STANDARD_JAPAN, /**< Japanese comfort tone standard*/
  AUDIOCONTROL_COMFORT_TONE_STANDARD_ANSI,  /**< ANSI comfort tone standard*/
  AUDIOCONTROL_COMFORT_TONE_STANDARD_CEPT,  /**< CEPT comfort tone standard*/

  AUDIOCONTROL_COMFORT_TONE_STANDARD_LAST
} TAudioControl_ComfortToneStandard;

typedef enum
{
  AUDIOCONTROL_AUDIOTYPE_MEDIAPLAYER,
  AUDIOCONTROL_AUDIOTYPE_SOUNDRECORDER,
  AUDIOCONTROL_AUDIOTYPE_VIDEORECORDER,
  AUDIOCONTROL_AUDIOTYPE_VIDEOTELEPHONY,

  AUDIOCONTROL_AUDIOTYPE_VOICECALL_RX,
  AUDIOCONTROL_AUDIOTYPE_VOICECALL_TX,

  AUDIOCONTROL_AUDIOTYPE_JAVA,
  AUDIOCONTROL_AUDIOTYPE_JAVA_SOUNDRECORDER,

  AUDIOCONTROL_AUDIOTYPE_SPEECHTRAINING,
  AUDIOCONTROL_AUDIOTYPE_SPEECHRECOGNITION,
  AUDIOCONTROL_AUDIOTYPE_MAGIC_WORD,

  AUDIOCONTROL_AUDIOTYPE_FM_RADIO,
  AUDIOCONTROL_AUDIOTYPE_FM_RADIO_ALARM,

  AUDIOCONTROL_AUDIOTYPE_PTT_RX,
  AUDIOCONTROL_AUDIOTYPE_PTT_TX,
  AUDIOCONTROL_AUDIOTYPE_PTT_TX_DECODER,
  AUDIOCONTROL_AUDIOTYPE_PTT_BUFFER,

  // Internal enums.
  AUDIOCONTROL_AUDIOTYPE_RINGER,                 /**< Used for Ringer_Play and for Video CLI, through AudioChannel_Open */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_ALERT,     /**< Used for Notification_Play with high prio sounds, see ac_notification.c*/
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_IMPORTANT, /**< Used for Notification_Play with medium prio sounds, see ac_notification.c*/
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_GENERAL,   /**< Used for Notification_Play with low prio sounds, see ac_notification.c*/
  AUDIOCONTROL_AUDIOTYPE_AUDIO,                  /**< Used for Play */
  AUDIOCONTROL_AUDIOTYPE_KEYTONE,                /**< Used for KeySound_Play and not AUDIOCONTROL_KEYSOUND_CLICK */
  AUDIOCONTROL_AUDIOTYPE_KEYCLICK,               /**< Used for KeySound_Play and AUDIOCONTROL_KEYSOUND_TONE  */
  AUDIOCONTROL_AUDIOTYPE_ALARM,                  /**< Used for Alarm_Play */
  AUDIOCONTROL_AUDIOTYPE_TONE,                   /**< Used for Tone_Play */
  AUDIOCONTROL_AUDIOTYPE_SPEAKERTEST,            /**< Used for ServiceMenu_SpeakerTest_Play */
  AUDIOCONTROL_AUDIOTYPE_EARPIECETEST,           /**< Used for ServiceMenu_SpeakerTest_Play */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_CAMERA,    /**< Used for camera sounds */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_VOICECTRL, /**< Used for voice control sounds */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_INCALL,    /**< Used for notification that should be played in earpiece during voice call*/

  AUDIOCONTROL_AUDIOTYPE_LAST /**< Keep this last*/

} AC_AudioType_t;

typedef AC_AudioType_t TAudioControl_ChannelType;

typedef enum
{
  AUDIO_CHANNEL_SAMPLE_RATE_8_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_16_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_44_1_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_48_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_UNSPECIFIED,

  AUDIO_CHANNEL_SAMPLE_RATE_LAST
} TAudioChannelSampleRate;

typedef enum
{
  MULTIMEDIA_AUDIO_OUTPUT_MONO,
  MULTIMEDIA_AUDIO_OUTPUT_STEREO,
  MULTIMEDIA_AUDIO_OUTPUT_UNKNOWN
} TMultimediaAudioOutput;

typedef enum
{
  AUDIOCONTROL_SPEAKERTYPE_EARPIECE, /**< The earpiece speaker */
  AUDIOCONTROL_SPEAKERTYPE_SPEAKER,  /**< The builtin speaker */
  AUDIOCONTROL_SPEAKERTYPE_AUTO      /**< Automatically choose speaker */
} TAudioControl_SpeakerType;

typedef enum
{
  // aligned with parallellTable and sessionTypePriorities in ac_audiochannel.c
  AUDIOCONTROL_SESSIONTYPE_MEDIAPLAYER /**< An audio session for a media player           */ = 0x00000001,
  AUDIOCONTROL_SESSIONTYPE_CAMERA /**< An audio session for camera application       */ = 0x00000002,
  AUDIOCONTROL_SESSIONTYPE_FM_RADIO /**< An audio session for FM radio                 */ = 0x00000004,
  AUDIOCONTROL_SESSIONTYPE_VOICECALL /**< An audio session for a voicecall              */ = 0x00000008,
  AUDIOCONTROL_SESSIONTYPE_VIDEOTELEPHONY /**< An audio session for video telephony          */ = 0x00000010,
  AUDIOCONTROL_SESSIONTYPE_SOUNDRECORDER /**< An audio session for sound recorder           */ = 0x00000020,
  AUDIOCONTROL_SESSIONTYPE_VIDEORECORDER /**< An audio session for video recorder           */ = 0x00000040,
  AUDIOCONTROL_SESSIONTYPE_MESSAGING /**< An audio session for messaging                */ = 0x00000080,
  AUDIOCONTROL_SESSIONTYPE_JAVA /**< An audio session for a Java Virtual Machine   */ = 0x00000100,
  AUDIOCONTROL_SESSIONTYPE_PTT /**< An audio session for PTT                      */ = 0x00000200,
  AUDIOCONTROL_SESSIONTYPE_SLIDESHOW /**< An audio session for Slide show               */ = 0x00000400,
  AUDIOCONTROL_SESSIONTYPE_VOICETRAINING /**< An audio session for Voice training           */ = 0x00000800,
  AUDIOCONTROL_SESSIONTYPE_VOICECONTROL /**< An audio session for Voice control            */ = 0x00001000,
  AUDIOCONTROL_SESSIONTYPE_ASR_RECOGNITION_CONTINUOUS /**< An audio session for Voice control */ = 0x00002000,

  // Internal, not for external use
  AUDIOCONTROL_SESSIONTYPE_SYSTEM_SOUND /**< An audio session for system sounds            */ = 0x01000000,
  AUDIOCONTROL_SESSIONTYPE_KEYSOUNDS /**< An audio session for Key clicks and Key tones */ = 0x02000000,
  AUDIOCONTROL_SESSIONTYPE_LAST /**< For internal audio control use only           */ = 0x04000000,
  AUDIOCONTROL_SESSIONTYPE_NONE /**< */ = 0x00000000,
  AUDIOCONTROL_SESSIONTYPE_ALL /**< */ = 0xFFFFFFFF
} TAudioControl_SessionType;

typedef enum
{
  AUDIOCONTROL_AUDIOFORMAT_WAV,               /**< The audio is a wav file*/
  AUDIOCONTROL_AUDIOFORMAT_AMR,               /**< The audio is a amr file*/
  AUDIOCONTROL_AUDIOFORMAT_TONE,              /**< The audio is a tone*/
  AUDIOCONTROL_AUDIOFORMAT_MIDI,              /**< The audio is a MIDI file*/
  AUDIOCONTROL_AUDIOFORMAT_SMAF,              /**< The audio is a SMAF file*/
  AUDIOCONTROL_AUDIOFORMAT_PMR,               /**< The audio is a Nokia pmr file file*/
  AUDIOCONTROL_AUDIOFORMAT_MFI,               /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_SPEECHRECOGNITION, /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_MP3,               /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_AAC,               /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_AAC_PLUS,          /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_FM_RADIO,          /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_VOICECALL,         /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_VIDEOCALL,         /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_INPUT,             /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_OTHER              /**< Todo */
} TAudioControl_AudioFormat;

typedef enum
{
  AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYCHANGED = 0x0001,           /**< Event when the active accessory is changed, the active accessory is the accessory that currently has audio routed to */
  AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYMUTE = 0x0002,              /**< Event when the accessory is to bemuted */
  AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYCALLVOLUMECHANGED = 0x0004, /**< Event when the the call volume is changed */
  AUDIOCONTROL_ACCESSORY_EVENT_ONREQUIRECCO = 0x0008,                 /**< Obsolete */
  AUDIOCONTROL_ACCESSORY_EVENT_ONVOLUMECHANGED = 0x0010,              /**< Event sent when volume changes*/
  AUDIOCONTROL_ACCESSORY_EVENT_ONSESSIONBEGIN = 0x0020,               /**< Event when a session is started
                                                                           ICBAudioControl::OnSessionBegin */
  AUDIOCONTROL_ACCESSORY_EVENT_ONSPEAKERMODECHANGED = 0x0040,         /**< Event when the speakermode changes. */
  AUDIOCONTROL_ACCESSORY_EVENT_ONSESSIONEND = 0x0080,                 /**< Event when a session is ended
                                                                           ICBAudioControl::OnSessionEnd */
  AUDIOCONTROL_ACCESSORY_EVENT_ONMICROPHONEMUTECHANGED = 0x0100,      /**< Event when the microphone is muted. */
  AUDIOCONTROL_ACCESSORY_EVENT_ONFMTXCHANGED = 0x0200,                /**< Event when fm transmitter is disabled/enabled */
  AUDIOCONTROL_ACCESSORY_EVENT_ALL_EVENTS = 0xFFFF                    /**< All events */
} TAudioControl_AccessoryEvents;

typedef enum
{
  AUDIOCONTROL_EVENT_NONE = 0x0000,
  AUDIOCONTROL_EVENT_ONSPEAKERMODECHANGED = 0x0040,    /**< Event when the speaker mode has changed. */
  AUDIOCONTROL_EVENT_ONMICROPHONEMUTECHANGED = 0x0100, /**< Event when the microphone is muted. */
  AUDIOCONTROL_EVENT_ONFMTXCHANGED = 0x0200            /**< Event when fm transmitter is disabled/enabled */
} TAudioControl_Events;

typedef enum
{
  AUDIOCONTROL_ACCESSORYID_UNKNOWN = 0, /**< No audio capabilities */

  // Resitive identified:
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS1 = 1,
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS2 = 2,
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS3 = 3,
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS4 = 4,
  AUDIOCONTROL_ACCESSORYID_LINE_IN = 5,
  AUDIOCONTROL_ACCESSORYID_LINE_OUT = 6,
  AUDIOCONTROL_ACCESSORYID_BT_HEADSET = 7,
  AUDIOCONTROL_ACCESSORYID_BT_HANDSFREE = 8,
  AUDIOCONTROL_ACCESSORYID_LINE_OUT_ADJUSTABLE = 9,

  // 3.5 mm jack
  AUDIOCONTROL_ACCESSORYID_PHF_35MM_STEREO_JACK,
  AUDIOCONTROL_ACCESSORYID_HP_35MM_STEREO_JACK,
  AUDIOCONTROL_ACCESSORYID_LO_35MM_STEREO_JACK,
  AUDIOCONTROL_ACCESSORYID_LI_35MM_STEREO_JACK,

  // 1000-1999 PHF - Portable Hands Frees

  AUDIOCONTROL_ACCESSORYID_PHF_HPM_80 = 1001, /**< Accessory id for Remo (Fm radio PHF with remotecontrol and FM radio for Sakura) */
  AUDIOCONTROL_ACCESSORYID_PHF_HPM_82 = 1002, /**< Accessory id for Barret (PHF with remote control)*/

  // 2000-2999 VHF - Vehicle handsfrees
  AUDIOCONTROL_ACCESSORYID_VHF_HCA_60 = 2001, /**< Advanced Vehicle handsfree ("Pooh", "HCA-60") Speech and music in mono speaker */
  AUDIOCONTROL_ACCESSORYID_VHF_HCE_60 = 2002, /**< Advanced Vehicle handsfree ("Pooh", "HCA-60") Speech and music in car stereo speakers*/

  AUDIOCONTROL_ACCESSORYID_PEIKER = 2500,       /**< BMW car kit with no internal EC nor NC */
  AUDIOCONTROL_ACCESSORYID_PEIKER_EC_NR = 2501, /**< BMW car kit with internal EC and NC */

  // 3000-3999 BVHF - Budget Vehicle Hands Free (without accessory mic)
  AUDIOCONTROL_ACCESSORYID_BVHF_HCQ_60 = 3001, /**< HCQ-60, "Tiger" */

  // 4000-4999 BT - Bluetooth Headset, or Handsfree
  AUDIOCONTROL_ACCESSORYID_BT_HBH_10 = 4001,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_15 = 4002,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_20 = 4003,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_200 = 4004,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_30 = 4005,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_300 = 4006,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_35 = 4007,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_60 = 4008,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_600 = 4009,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_605 = 4010,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_65 = 4011,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_660 = 4012,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_670 = 4013,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_610 = 4014,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_620 = 4015,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_662 = 4016,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_602 = 4017,
  AUDIOCONTROL_ACCESSORYID_BT_HBM_30 = 4018,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_608 = 4021,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_PV705 = 4022,
  AUDIOCONTROL_ACCESSORYID_BT_MOTO_T305 = 4600, /**< Accessory id for Motorola T305, see DMS00384781. */
  AUDIOCONTROL_ACCESSORYID_BT_DSP = 4999,       /**< Accessory id for BT headsets with internal DSP. */

  // 5000-5999 BTC - Bluetooth Handsfree for installation in car.
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_30 = 5001,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_300 = 5002,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_400 = 5003,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_700 = 5004,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_610 = 5005,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_100 = 5006,

  // 6000-6999 BTL - Bluetooth Leisure (BT headset supporting the Advanced Audio Distribution Profile)
  // 7000-7999 BTBTL - A Bluetooth audio device supporting the Headset or the Handsfree profile and the Advanced Audio Distributionprofile.
  AUDIOCONTROL_ACCESSORYID_BTBTL_HBH_DS970 = 7001, // A.k.a "Hippix"

  // 8000-8999 BTBTLC - A Bluetooth audio device supporting the Headset or the Handsfree profile and the Advanced Audio Distributionprofile for installation in car.
  // 9000-9999 DSS - Desk Speaker Stand
  // 10000-10999 BDSS - Budget Desk Speaker Stand

  // 11000-11999 LO - Line out accesory
  AUDIOCONTROL_ACCESSORYID_MMR_60 = 11001, // Wadner

  // 12000-12999 LI - Line in accesory

  // Last accessory
  AUDIOCONTROL_ACCESSORYID_LAST /**< Last accessory id, only for internal Audio Control use*/
} TAudioControl_AccessoryId;

typedef enum
{
  // Ordinary accessories
  AUDIOCONTROL_ACCESSORYCLASS_NONE = 0,  /**< No audio capabilities */
  AUDIOCONTROL_ACCESSORYCLASS_PHF = 1,   /**< PHF - Portable Hands Free */
  AUDIOCONTROL_ACCESSORYCLASS_VHF = 2,   /**< VHF - Vehicle Hands Free */
  AUDIOCONTROL_ACCESSORYCLASS_BVHF = 3,  /**< BVHF - Budget Vehicle Hands Free (using phone mic) */
  AUDIOCONTROL_ACCESSORYCLASS_BT = 4,    /**< BT - Bluetooth Headset or Handsfree */
  AUDIOCONTROL_ACCESSORYCLASS_BTC = 5,   /**< BT Car HF - Bluetooth Car Handsfree */
  AUDIOCONTROL_ACCESSORYCLASS_BTL = 6,   /**< Bluetooth leisure headset supporting A2DP profile (like streaming mp3, currently not supported) */
  AUDIOCONTROL_ACCESSORYCLASS_DSS = 9,   /**< Desk speaker Stand */
  AUDIOCONTROL_ACCESSORYCLASS_BDSS = 10, /**< Budget Desk speaker Stand (using phone mic) */
  AUDIOCONTROL_ACCESSORYCLASS_LOA = 11,  /**< Line out signal that uses phone volume and settings*/
  AUDIOCONTROL_ACCESSORYCLASS_LI = 12,   /**< Line in */
  AUDIOCONTROL_ACCESSORYCLASS_LO = 13,   /**< Line out - flat signal */
  AUDIOCONTROL_ACCESSORYCLASS_HEADPHONE,

  // Virtual accessories (for internal Audio Control use only)
  AUDIOCONTROL_ACCESSORY_VIRTUAL_SPEAKER_CLOSED,  /**< Virtual speaker closed accessory (e.g. clam closed, jack closed, etc), only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_EARPIECE_CLOSED, /**< Virtual earpiece closed accessory (e.g. clam closed, jack closed, etc), only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_SPEAKER,         /**< Virtual speaker accessory, only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_EARPIECE,        /**< Virtual earpiece accessory, only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_SILENT,          /**< Virtual silent accessory, only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_FMTX,            /**< FM Transmitter */

  // Last enum
  AUDIOCONTROL_ACCESSORYCLASS_LAST /**< Last accessory, only for internal Audio Control use */
} TAudioControl_AccessoryClass;

typedef enum
{
} TAudioEffectFrequencyBandId;

typedef TAudioEffectFrequencyBandId TAudioControl_EqualizerBand;

typedef enum
{
} TAudioEffectLevel;

typedef TAudioEffectLevel TAudioControl_EqualizerGain;

class IAudioControl : public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int Accessory_Update(int accessoryHandle, TAudioControl_AccessoryClass accessoryClass, TAudioControl_AccessoryId accessoryId);                                                                                                                                                                                        // 0x20
  virtual int Accessory_CallVolume_Set2(int accessoryHandle, char callVolume);                                                                                                                                                                                                                                                  // 0x24
  virtual int Accessory_SubscribeToEvents(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_AccessoryEvents events, int *pSubscriptionHandle);                                                                                                                                                             // 0x28
  virtual int Subscribe(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Events events, int *pSubscriptionHandle);                                                                                                                                                                                        // 0x2C
  virtual int Accessory_GetCurrent(TAudioControl_AccessoryClass *pAccessoryClass, TAudioControl_AccessoryId *pAccessoryId, int *pAccessoryHandle);                                                                                                                                                                              // 0x30
  virtual int Accessory_UnsubscribeToEvents(int subscriptionHandle);                                                                                                                                                                                                                                                            // 0x34
  virtual int Unsubscribe(int subscriptionHandle);                                                                                                                                                                                                                                                                              // 0x38
  virtual int Ringer_Play(IUnknown *pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t *pFilePath, bool, bool followSilentMode, bool unk1, bool unk2, bool volumeOverride, char overrideVolume, int *pRingerHandle);                                                                                     // 0x3C
  virtual int Ringer_Play2(IUnknown *pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t *pFilePath, wchar_t *pIlluminationFileName, bool preview, bool followSilentMode, bool volumeOverride, char overrideVolume, int *pRingerHandle);                                                                  // 0x40
  virtual int Ringer_Stop(int ringerHandle, bool fadeDownBeforeStop);                                                                                                                                                                                                                                                           // 0x44
  virtual int Ringer_Pause(int ringerHandle);                                                                                                                                                                                                                                                                                   // 0x48
  virtual int Ringer_Resume(int ringerHandle);                                                                                                                                                                                                                                                                                  // 0x4C
  virtual int Notification_Play(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Notification notification, bool preview, int *pNotificationHandle);                                                                                                                                                      // 0x50
  virtual int Notification_PlayFile(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Notification notification, wchar_t *pFilePath, bool preview, int *pNotificationHandle);                                                                                                                              // 0x54
  virtual int Notification_PlayFile2(IUnknown *pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Notification notification, wchar_t *pFilePath, bool preview, int *pNotificationHandle);                                                                                                          // 0x58
  virtual int Notification_PlayFile3(IUnknown *pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Notification notification, wchar_t *pFilePath, bool preview, int *unk, int *pNotificationHandle);                                                                                                // 0x5C
  virtual int Notification_Stop(int notificationHandle);                                                                                                                                                                                                                                                                        // 0x60
  virtual int Alarm_Play(IUnknown *pICBAudioControl, u16 msgBase, int clientData, wchar_t *pFilePath, bool preview, bool followSilentMode, int *pAlarmHandle);                                                                                                                                                                  // 0x64 // 15176D72
  virtual int Alarm_Stop(int alarmHandle);                                                                                                                                                                                                                                                                                      // 0x68
  virtual int Play2(IUnknown *pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t *pFilePath, bool repeat, bool followSilentMode, int *pPlayHandle);                                                                                                                                                      // 0x6C
  virtual int Stop(int playHandle);                                                                                                                                                                                                                                                                                             // 0x70
  virtual int unk_0x74();                                                                                                                                                                                                                                                                                                       // 0x74
  virtual int unk_0x78();                                                                                                                                                                                                                                                                                                       // 0x78
  virtual int Tone_Play2(IUnknown *pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Tone tone, bool followSilentMode, TAudioControl_ToneRedirection toneRedirection, int time_duration, int *pToneHandle);                                                                                       // 0x7C
  virtual int Tone_Stop(int toneHandle);                                                                                                                                                                                                                                                                                        // 0x80
  virtual int KeySound_Extended_Play(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_KeySound keySound, int time_duration, int *pToneHandle);                                                                                                                                                            // 0x84
  virtual int KeySound_Extended_Stop(int toneHandle);                                                                                                                                                                                                                                                                           // 0x88
  virtual int ServiceMenu_SpeakerTest_Play(IUnknown *pICBAudioControl, u16 msgBase, int clientData, wchar_t *pFilePath, TAudioControl_SpeakerType speakerType, int *pChannelHandle);                                                                                                                                            // 0x8C
  virtual int ServiceMenu_SpeakerTest_Stop(int channelHandle);                                                                                                                                                                                                                                                                  // 0x90
  virtual int IsAudioPlaying(bool *pAudioPlaying, TAudioControl_VolumeType *pVolumeType);                                                                                                                                                                                                                                       // 0x94
  virtual int IsVibratorRunning(bool *pVibratorRunning);                                                                                                                                                                                                                                                                        // 0x98
  virtual int AudioChannel_Open2(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_ChannelType channelType, TAudioChannelSampleRate sampleRate, TMultimediaAudioOutput audioOutput, bool followSilentMode, int timeToWait, int sessionHandle, TAudioControl_AudioFormat audioFormat, int *pChannelHandle); // 0x9C
  virtual int unk_0xA0();                                                                                                                                                                                                                                                                                                       // 0xA0
  virtual int AudioChannel_Close(int channelHandle);                                                                                                                                                                                                                                                                            // 0xA4
  virtual int unk_0xA8();                                                                                                                                                                                                                                                                                                       // 0xA8
  virtual int unk_0xAC();                                                                                                                                                                                                                                                                                                       // 0xAC
  virtual int AudioSession_Begin2(IUnknown *pICBAudioControl, u16 msgBase, int clientData, TAudioControl_SessionType sessionType, int *pSessionHandle);                                                                                                                                                                         // 0xB0
  virtual int AudioSession_End(int sessionHandle);                                                                                                                                                                                                                                                                              // 0xB4
  virtual int unk_0xB8();                                                                                                                                                                                                                                                                                                       // 0xB8
  virtual int Volume_Set(TAudioControl_VolumeType volumeType, char pVolume);                                                                                                                                                                                                                                                    // 0xBC
  virtual int Volume_Get(TAudioControl_VolumeType volumeType, char *pVolume);                                                                                                                                                                                                                                                   // 0xC0
  virtual int ChannelVolume_Fade(int channelHandle, TAudioControl_FadeDirection fadeDirection, TAudioControl_FadeReason fadeReason);                                                                                                                                                                                            // 0xC4
  virtual int ChannelVolume_Set2(int channelHandle, char relVolume);                                                                                                                                                                                                                                                            // 0xC8
  virtual int ChannelVolume_Set(int channelHandle, char volume);                                                                                                                                                                                                                                                                // 0xCC
  virtual int ChannelVolume_Get(int channelHandle, char *pVolume);
  virtual int IncreaseVolume(TAudioControl_VolumeType volumeType, char *pNewVolume);
  virtual int DecreaseVolume(TAudioControl_VolumeType volumeType, char *pNewVolume);
  virtual int unk_0xDC();
  virtual int IncreasingRing_Set(bool increasingRingEnabled);   // 0xE0
  virtual int IncreasingRing_Get(bool *pIncreasingRingEnabled); // 0xE4
  virtual int MicrophoneMute_Set(bool muteOn);                  // 0xE8
  virtual int MicrophoneMute_Get(bool *pMuteOn);                // 0xEC
  virtual int unk_0xF0();
  virtual int EqualizerGain_Set(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, TAudioControl_EqualizerGain equalizerGain);
  virtual int EqualizerGain_Get(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, TAudioControl_EqualizerGain *pEqualizerGain);
  virtual int unk_0xFC();
  virtual int unk_0x100();
  virtual int unk_0x104();
  virtual int unk_0x108();
  virtual int unk_0x10C();
  virtual int unk_0x110();
  virtual int unk_0x114();
  virtual int unk_0x118();
  virtual int unk_0x11C();
  virtual int unk_0x120();
  virtual int unk_0x124();
  virtual int unk_0x128();
  virtual int unk_0x12C();
  virtual int unk_0x130();
  virtual int unk_0x134();
  virtual int unk_0x138();
  virtual int unk_0x13C();
  virtual int unk_0x140();
  virtual int unk_0x144();
  virtual int unk_0x148();
  virtual int unk_0x14C();
  virtual int unk_0x150();
  virtual int EqualizerCenterFreq_Get(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, int *pEqualizerCenterFreq); // 0x154
  virtual int DebugMenu_GetString(TAudioControl_DebugMenuString *pBuffer);                                                      // 0x158
  virtual int AudioRouting_Get(TAudioControl_AudioRouting *pAudioRouting);                                                      // 0x15C
  virtual int SpeakerPhone_Set(int sessionHandle, bool speakerPhoneEnabled);                                                    // 0x160
  virtual int SpeakerPhone_Set2(int sessionHandle, TAudioControl_SpeakerMode speakerMode);                                      // 0x164
  virtual int SpeakerPhone_Get(int sessionHandle, bool *pSpeakerPhoneEnabled);                                                  // 0x168
  virtual int ComfortToneStandard_Set(TAudioControl_ComfortToneStandard comfortToneStandard);                                   // 0x16C
  virtual int SilentMode_Set(bool silentModeEnabled);                                                                           // 0x170
  virtual int SilentMode_Get(bool *silentModeEnabled);                                                                          // 0x174
  virtual int TTYMode_Set(TAudioControl_TTYMode TTYMode);                                                                       // 0x178
  virtual int TTYMode_Get(TAudioControl_TTYMode *pTTYMode);                                                                     // 0x17C
  virtual int HACMode_Set(TAudioControl_HACMode HACMode);                                                                       // 0x180
  virtual int HACMode_Get(TAudioControl_HACMode *pHACMode);                                                                     // 0x184
  virtual int VibratorState_Set(TAudioControl_VibratorState vibratorState);                                                     // 0x188
  virtual int VibratorState_Get(TAudioControl_VibratorState *pVibratorState);                                                   // 0x18C
  virtual int Vibrator_Start(int period, int dutyCycle, int duration);                                                          // 0x190
  virtual int Vibrator_Stop(void);                                                                                              // 0x194
  virtual int Callstate_Set(TAudioControl_CallType callType, TAudioControl_CallState callState);                                // 0x198
  virtual int unk_0x19C();                                                                                                      // 0x19C
  virtual int Camera_FollowSilentMode_Set(bool followSilentMode);                                                               // 0x1A0
  virtual int Camera_FollowSilentMode_Get(bool *pFollowSilentMode);                                                             // 0x1A4
  virtual int AudioFocus_Request(int sessionHandle);                                                                            // 0x1A8
  virtual int LightPlayer_Enable(int sessionHandle, bool enable);                                                               // 0x1AC
  virtual int AudioChannel_Mute(int channelHandle, bool mute);                                                                  // 0x1B0
  virtual int AudioChannel_ConnectToDevice(int channelHandle);                                                                  // 0x1B4
  virtual int AudioChannel_Disconnect(int channelHandle);                                                                       // 0x1B8
  virtual int AudioVisualizer_Enable(int channelHandle, bool enable);                                                           // 0x1BC
};

class IAudioControlManager : public IUnknown
{
public:
  virtual int CreateAudioControl(IAudioControl **ppIAudioControl);
};

#endif
