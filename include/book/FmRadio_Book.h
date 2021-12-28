#ifndef _FMRADIO_BOOK_H_
#define _FMRADIO_BOOK_H_

//////////////////////////////////////////////////////////////////////
/// @name Typedefs
//@{

/**
 * Bitfield to signal current supported functionality
 */
typedef uint16_t FMRadio_FunctionalityBitfield_t;

/**
 * Bitfield to set which RDS functions that shall be activated.
 * Example: (ENABLE_RDS | ENABLE_ALTERNATIVE_FREQUENCY | ENABLE_PROGRAM_SERVICE_NAME)
 */
typedef uint16_t FMRadio_RDSFlag_Bitfield_t;

/** 
 * The different modes to put the radio in
 */
typedef enum
{
  FMRADIO_POWERMODE_OFF,        ///< Shut off the radio
  FMRADIO_POWERMODE_ON_RDS_ON,  ///< Turn on the radio with the RDS part activated
  FMRADIO_POWERMODE_ON_RDS_OFF, ///< Turn on the radio with the RDS part inactivated
  FMRADIO_POWERMODE_STANDBY     ///< Put the radio in standby mode
} FMRadio_PowerMode_t;

/** 
 * The different FM bands available
 */
typedef enum
{
  FMRADIO_JAPANESE_FM_BAND,      ///< The Japanese FM Band (76MHz to 91MHz)
  FMRADIO_JAPANESE_WIDE_FM_BAND, ///< The Japanese FM Wide Band (76MHz to 108MHz)
  FMRADIO_EUROPEAN_FM_BAND       ///< The European FM Band (87.5MHz to 108MHz)
} FMRadio_FrequencyBand_t;

/** 
 * The different frequency precisions available
 */
typedef enum
{
  FMRADIO_FREQ_PRECISION_100KHZ, ///< 100 kHz frequency precision (i e 107.0MHz is typed 1070)
  FMRADIO_FREQ_PRECISION_10KHZ   ///< 10 kHz frequency precision (i e 107.00MHz is typed 10700)
} FMRadio_FrequencyPrecision_t;

/** 
 * The two possible directions to search the FM Band with.
 */
typedef enum
{
  FMRADIO_SEARCH_DIRECTION_UP,  ///< Search the band up from the current frequency
  FMRADIO_SEARCH_DIRECTION_DOWN ///< Search the band down from the current frequency
} FMRadio_Search_Direction_t;

/** 
 * The different ways to mute the FM Radio
 */
typedef enum
{
  FMRADIO_SOFT_MUTE, ///< NOT SUPPORTED!
  FMRADIO_HARD_MUTE  ///< An instant interrupt in the sound
} FMRadio_MuteOption_t;

/** 
 * The different Radio Driver errors that can occur.
 */
typedef enum
{
  FMRADIO_OK,                        ///< Command successful
  FMRADIO_FAILED_TO_START,           ///< The chip failed to start
  FMRADIO_FAILED_TO_STOP,            ///< The chip failed to stop
  FMRADIO_INVALID_FREQUENCY,         ///< An invalid frequency was tried to be set
  FMRADIO_RDS_NOT_ENABLED,           ///< The RDS functionality is not enabled
  FMRADIO_RDS_FUNC_NOT_ACTIVATED,    ///< The used RDS functionality is not activated
  FMRADIO_I2C_FAILED,                ///< An I2C command failed (read or write)
  FMRADIO_GPIO_FAILED,               ///< An GPIO command failed
  FMRADIO_FAILED_FUNC_NOT_ACTIVATED, ///< An GPIO command failed
  FMRADIO_OUT_OF_MEMORY              ///< Memory allocation failed
} FMRadio_ErrorCode_t;

/** 
 * Struct used to send the list retrieved with autostore.
 */
typedef struct
{
  uint8_t ListPosition; ///< The position in the list
  uint16_t Frequency;   ///< The frequency
} FmRadio_ProgramInfo_t;

//@} End of Typedefs

//////////////////////////////////////////////////////////////////////
/// @name Data
//@{

/** 
 * Number of characters in the RDS function Program Service Name (PS)
 */
const uint8_t NBR_OF_PS_NAME_CHARS = 8;

/**
 * General RDS support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT = 0x01; //bin: 0000 0000 0000 0001
/**
 * Program Service Name support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_PS = 0x02; //bin: 0000 0000 0000 0010
/**
 * Alternative Frequency support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_AF = 0x04; //bin: 0000 0000 0000 0100
/**
 * Traffic Announcement support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_EON_TA = 0x08; //bin: 0000 0000 0000 1000
/**
 * Traffic Program support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_EON_TP = 0x10; //bin: 0000 0000 0001 0000

/**
 * Activate/de-activate RDS (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_RDS = 0x01; //bin: 0000 0000 0000 0001
/**
 * Activate/de-activate PS (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_PROGRAM_SERVICE_NAME = 0x02; //bin: 0000 0000 0000 0010
/**
 * Activate/de-activate AF (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_ALTERNATIVE_FREQUENCY = 0x04; //bin: 0000 0000 0000 0100
/**
 * Activate/de-activate TA (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_TRAFFIC_ANNOUNCEMENTS = 0x08; //bin: 0000 0000 0000 1000

typedef struct _DISP_OBJ_FMRADIO
{
#if defined(DB3200) || defined(DB3210)
  uint8_t dummy_1[0x194];
#elif defined(DB3150v1)
  uint8_t dummy_1[0x134];
#elif defined(DB2020)
  uint8_t dummy_1[0xD8];
#endif
  uint16_t key_pressed;
  uint8_t key_mode;
} DISP_OBJ_FMRADIO;

typedef struct FmRadio_Settings
{
  bool SpeakerMode;
  bool StereoReception; // true=stereo //false=mono
  bool FmRadio_Settings_3;
  bool FmRadio_Settings_4;
} FmRadio_Settings;

typedef struct FmRadio_Channel
{
  uint16_t Frequency;
  uint16_t FmRadio_Channel;
  wchar_t Name[17];
} FmRadio_Channel;

typedef struct _FmRadio_Book : BOOK
{
  GUI *FmRadio_Gui;              // 0x18
  GUI *FmRadio_Gui_Submenu1;     // 0x1C
  GUI *FmRadio_Gui_Submenu2;     // 0x20
  int unk_0x24;                  // 0x24
  uint8_t CurrentChannel;        // 0x28
  uint8_t unk_0x29;              // 0x29
  uint16_t CurrentFrequency;     // 0x2A
  uint16_t unk_0x2C;             // 0x2C
  wchar_t ProgramServiceName[9]; // 0x2E
  uint16_t unk_0x40;             // 0x40
  FmRadio_Channel Channel[20];   // 0x42
  uint16_t unk_0x33A;            // 0x33A
  int RadioVal;                  // 0x33C
  int unk_0x340;                 // 0x340
  int unk_0x344;                 // 0x344
  void *pIAudioControl;          // 0x348
  int unk_0x34C;                 // 0x34C
  void *pIFMRadio;               // 0x350
  int unk_0x354;                 // 0x354
  void *pIAccessoryServer;       // 0x358
  FmRadio_Settings Settings;     // 0x35C
  uint16_t unk_0x362;            // 0x360
  uint16_t TimerID;              // 0x362
  uint16_t FrequencySearch;      // 0x364
  uint16_t unk_0x366;            // 0x366
  uint8_t dummy_4[0x2E];         // 0x368
  bool RDS;                      // 0x396
  bool AF;                       // 0x397
  uint8_t unk_0x398;             // 0x398
} FmRadio_Book;

#endif
