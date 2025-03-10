#ifndef FmRadio_Book_H
#define FmRadio_Book_H

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
  char ListPosition;  ///< The position in the list
  uint16_t Frequency; ///< The frequency
} FmRadio_ProgramInfo_t;

//@} End of Typedefs

//////////////////////////////////////////////////////////////////////
/// @name Data
//@{

/**
 * Number of characters in the RDS function Program Service Name (PS)
 */
const char NBR_OF_PS_NAME_CHARS = 8;

/**
 * General RDS support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT = 0x01; // bin: 0000 0000 0000 0001
/**
 * Program Service Name support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_PS = 0x02; // bin: 0000 0000 0000 0010
/**
 * Alternative Frequency support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_AF = 0x04; // bin: 0000 0000 0000 0100
/**
 * Traffic Announcement support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_EON_TA = 0x08; // bin: 0000 0000 0000 1000
/**
 * Traffic Program support (FMRadio_FunctionalityBitfield_t)
 */
const uint16_t RDS_SUPPORT_EON_TP = 0x10; // bin: 0000 0000 0001 0000

/**
 * Activate/de-activate RDS (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_RDS = 0x01; // bin: 0000 0000 0000 0001
/**
 * Activate/de-activate PS (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_PROGRAM_SERVICE_NAME = 0x02; // bin: 0000 0000 0000 0010
/**
 * Activate/de-activate AF (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_ALTERNATIVE_FREQUENCY = 0x04; // bin: 0000 0000 0000 0100
/**
 * Activate/de-activate TA (FMRadio_RDSFlag_Bitfield_t)
 */
const uint16_t ENABLE_TRAFFIC_ANNOUNCEMENTS = 0x08; // bin: 0000 0000 0000 1000

typedef struct DISP_OBJ_FMRADIO : DISP_OBJ
{
  uint8_t channel;      // 0x0
  char dummy_1[0x23];   // 0x1
  TEXTID text_id;       // 0x24
  uint16_t key_pressed; // 0x28
  uint8_t key_mode;     // 0x2A
  uint8_t unk_2B;       // 0x2B
  RECT rect;            // 0x2C
  uint32_t pen_color;   // 0x34
  uint32_t brush_color; // 0x38
} DISP_OBJ_FMRADIO;

typedef struct FmRadio_Settings
{
  bool SpeakerMode;
  bool StereoReception; // true=stereo //false=mono
} FmRadio_Settings;

typedef struct FmRadio_Channel
{
  uint16_t Frequency;
  uint16_t FmRadio_Channel;
  wchar_t Name[0x11];
} FmRadio_Channel;

#if defined(W980_R3EG004) || defined(DB3200)
typedef struct _FmRadio_Book : BOOK
{
  GUI *FmRadio_Gui;                                     // 0x18
  int unk_1C;                                           // 0x1C
  GUI *FmRadio_Gui_Submenu1;                            // 0x20
  GUI *FmRadio_Gui_Submenu2;                            // 0x24
  int unk_24;                                           // 0x28
  char CurrentChannel;                                  // 0x2C
  char unk_29;                                          // 0x2D
  uint16_t CurrentFrequency;                            // 0x2E
  uint16_t unk_2C;                                      // 0x30
  wchar_t ProgramServiceName[NBR_OF_PS_NAME_CHARS + 1]; // 0x32
  uint16_t unk_40;                                      // 0x44
  FmRadio_Channel Channel[20];                          // 0x46
  uint16_t unk_33E;                                     // 0x33E
  int RadioVal;                                         // 0x340
  int unk_344;                                          // 0x344
  int unk_348;                                          // 0x348
  void *pIAudioControl;                                 // 0x34C
  int unk_350;                                          // 0x350
  void *pIFMRadio;                                      // 0x354
  int unk_358;                                          // 0x358
  void *pIAccessoryServer;                              // 0x35C
  FmRadio_Settings Settings;                            // 0x360
  uint16_t unk_0x366;                                   // 0x364
  uint16_t TimerID;                                     // 0x366
  uint16_t FrequencySearch;                             // 0x368
  uint16_t unk_36A;                                     // 0x36A
  char unk_36C[0x2E];                                   // 0x36C
  bool RDS;                                             // 0x39A
  bool AF;                                              // 0x39B
  char unk_0x39C;                                       // 0x39C
} FmRadio_Book;
#else
typedef struct _FmRadio_Book : BOOK
{
  GUI *FmRadio_Gui;                                     // 0x18
  GUI *FmRadio_Gui_Submenu1;                            // 0x1C
  GUI *FmRadio_Gui_Submenu2;                            // 0x20
  int parent_book_id;                                   // 0x24
  char CurrentChannel;                                  // 0x28
  char unk_29;                                          // 0x29
  uint16_t CurrentFrequency;                            // 0x2A
  uint16_t unk_2C;                                      // 0x2C
  wchar_t ProgramServiceName[NBR_OF_PS_NAME_CHARS + 1]; // 0x2E
  uint16_t unk_40;                                      // 0x40
  FmRadio_Channel Channel[20];                          // 0x42
  uint16_t unk_33A;                                     // 0x33A
  int RadioVal;                                         // 0x33C
  int unk_340;                                          // 0x340
  int unk_344;                                          // 0x344
  void *pIAudioControl;                                 // 0x348
  int unk_34C;                                          // 0x34C
  void *pIFMRadio;                                      // 0x350
  int unk_354;                                          // 0x354
  void *pIAccessoryServer;                              // 0x358
  FmRadio_Settings Settings;                            // 0x35C
  uint16_t TimerID;                                     // 0x35E
  uint16_t unk_360;                                     // 0x360
  uint16_t unk_362;                                     // 0x362
  uint16_t FrequencySearch;                             // 0x364
  uint16_t unk_366;                                     // 0x366
  char unk_368[0x2E];                                   // 0x368
  bool RDS;                                             // 0x396
  bool AF;                                              // 0x397
  char unk_398;                                         // 0x398
} FmRadio_Book;
#endif

#endif
