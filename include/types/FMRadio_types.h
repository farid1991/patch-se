#ifndef __IFMRADIOTYPES_H__
#define __IFMRADIOTYPES_H__

#include "..\\include\types\Basic_types.h"

//////////////////////////////////////////////////////////////////////
/// @name Typedefs
//@{

/**
 * Bitfield to signal current supported functionality
 */
typedef FUint16 FMRadio_FunctionalityBitfield_t;

/**
 * Bitfield to set which RDS functions that shall be activated.
 * Example: (ENABLE_RDS | ENABLE_ALTERNATIVE_FREQUENCY | ENABLE_PROGRAM_SERVICE_NAME)
 */
typedef FUint16 FMRadio_RDSFlag_Bitfield_t;

/** 
 * The different modes to put the radio in
 */
typedef enum
{
  FMRADIO_POWERMODE_OFF,         ///< Shut off the radio
  FMRADIO_POWERMODE_ON_RDS_ON,   ///< Turn on the radio with the RDS part activated
  FMRADIO_POWERMODE_ON_RDS_OFF,  ///< Turn on the radio with the RDS part inactivated
  FMRADIO_POWERMODE_STANDBY      ///< Put the radio in standby mode
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
  FMRADIO_FREQ_PRECISION_100KHZ,     ///< 100 kHz frequency precision (i e 107.0MHz is typed 1070)
  FMRADIO_FREQ_PRECISION_10KHZ       ///< 10 kHz frequency precision (i e 107.00MHz is typed 10700)
} FMRadio_FrequencyPrecision_t;

/** 
 * The two possible directions to search the FM Band with.
 */
typedef enum
{
  FMRADIO_SEARCH_DIRECTION_UP,   ///< Search the band up from the current frequency
  FMRADIO_SEARCH_DIRECTION_DOWN  ///< Search the band down from the current frequency
} FMRadio_Search_Direction_t;

/** 
 * The different ways to mute the FM Radio
 */
typedef enum
{
  FMRADIO_SOFT_MUTE,  ///< NOT SUPPORTED!
  FMRADIO_HARD_MUTE   ///< An instant interrupt in the sound 
} FMRadio_MuteOption_t;

/** 
 * The different Radio Driver errors that can occur.
 */
typedef enum
{
  FMRADIO_OK,                         ///< Command successful
  FMRADIO_FAILED_TO_START,            ///< The chip failed to start
  FMRADIO_FAILED_TO_STOP,             ///< The chip failed to stop
  FMRADIO_INVALID_FREQUENCY,          ///< An invalid frequency was tried to be set
  FMRADIO_RDS_NOT_ENABLED,            ///< The RDS functionality is not enabled
  FMRADIO_RDS_FUNC_NOT_ACTIVATED,     ///< The used RDS functionality is not activated
  FMRADIO_I2C_FAILED,                 ///< An I2C command failed (read or write)
  FMRADIO_GPIO_FAILED,                ///< An GPIO command failed
  FMRADIO_FAILED_FUNC_NOT_ACTIVATED,	///< An GPIO command failed
  FMRADIO_OUT_OF_MEMORY               ///< Memory allocation failed
} FMRadio_ErrorCode_t;


/** 
 * Struct used to send the list retrieved with autostore.
 */
typedef struct
{
  FUint8  ListPosition; ///< The position in the list
  FUint16 Frequency;    ///< The frequency
} FmRadio_ProgramInfo_t;

//@} End of Typedefs


//////////////////////////////////////////////////////////////////////
/// @name Data
//@{

/** 
 * Number of characters in the RDS function Program Service Name (PS)
 */
const FUint8 NBR_OF_PS_NAME_CHARS = 8;

/**
 * General RDS support (FMRadio_FunctionalityBitfield_t)
 */
const FUint16 RDS_SUPPORT        = 0x01;  //bin: 0000 0000 0000 0001
/**
 * Program Service Name support (FMRadio_FunctionalityBitfield_t)
 */
const FUint16 RDS_SUPPORT_PS     = 0x02;  //bin: 0000 0000 0000 0010
/**
 * Alternative Frequency support (FMRadio_FunctionalityBitfield_t)
 */
const FUint16 RDS_SUPPORT_AF     = 0x04;  //bin: 0000 0000 0000 0100
/**
 * Traffic Announcement support (FMRadio_FunctionalityBitfield_t)
 */
const FUint16 RDS_SUPPORT_EON_TA = 0x08;  //bin: 0000 0000 0000 1000
/**
 * Traffic Program support (FMRadio_FunctionalityBitfield_t)
 */
const FUint16 RDS_SUPPORT_EON_TP = 0x10;  //bin: 0000 0000 0001 0000

/**
 * Activate/de-activate RDS (FMRadio_RDSFlag_Bitfield_t)
 */
const FUint16 ENABLE_RDS                   = 0x01; //bin: 0000 0000 0000 0001
/**
 * Activate/de-activate PS (FMRadio_RDSFlag_Bitfield_t)
 */
const FUint16 ENABLE_PROGRAM_SERVICE_NAME  = 0x02; //bin: 0000 0000 0000 0010
/**
 * Activate/de-activate AF (FMRadio_RDSFlag_Bitfield_t)
 */
const FUint16 ENABLE_ALTERNATIVE_FREQUENCY = 0x04; //bin: 0000 0000 0000 0100
/**
 * Activate/de-activate TA (FMRadio_RDSFlag_Bitfield_t)
 */
const FUint16 ENABLE_TRAFFIC_ANNOUNCEMENTS = 0x08; //bin: 0000 0000 0000 1000


#endif
