#ifndef __ACCEL_TYPES_H__
#define __ACCEL_TYPES_H__

#include "OPA_types.h"

typedef enum
{
  ACC_POLLFREQ_1HZ=1,
  ACC_POLLFREQ_3HZ=3,
  ACC_POLLFREQ_4HZ=4,
  ACC_POLLFREQ_5HZ=5,
  ACC_POLLFREQ_10HZ=10,
  ACC_POLLFREQ_20HZ=20,
  ACC_POLLFREQ_30HZ=30,
  ACC_POLLFREQ_40HZ=40,
  ACC_POLLFREQ_50HZ=50,
  ACC_POLLFREQ_60HZ=60,
  ACC_POLLFREQ_70HZ=70,
  ACC_POLLFREQ_80HZ=80,
  ACC_POLLFREQ_90HZ=90,
  ACC_POLLFREQ_100HZ=100
} Acc_PollFrequency_t;

typedef enum
{
  ACC_SAMPLERATE_100HZ=0, /* default */
  ACC_SAMPLERATE_400HZ
} Acc_InternalSamplingRate_t;

typedef enum
{
  ACC_SCALE_2G=0,         /* default */
  ACC_SCALE_8G
} Acc_ScaleSelection_t;

typedef enum
{
  ACC_AXES_DISABLE=0,
  ACC_AXES_ENABLE=1,	  /* default */
  ACC_AXES_DONTCARE=2
} Acc_Axes_OP_t;

typedef enum
{
  ACC_EVENT_BUFFER_FILLED=0,
  ACC_EVENT_DETECTRANGE_CHANGE,
  ACC_EVENT_CHIP_POWERON,
  ACC_EVENT_CHIP_POWEROFF
} Acc_EventType_t;

typedef struct
{
  Acc_ScaleSelection_t range;
} Acc_EventStruct_DetectRange;

typedef FUint32 Acc_BufferSize_t;

typedef enum
{
  ACC_FILTER_NONE=0,
  ACC_FILTER_SMOOTHING_MOVING_AVERAGE
} Acc_Filter_Type_t;

typedef FSint32 Acc_Filter_Param_t;

typedef enum
{
  ACC_X_AXIS=1,
  ACC_Y_AXIS=2,
  ACC_Z_AXIS=4,
  ACC_XY_AXES=3,
  ACC_XZ_AXES=5,
  ACC_YZ_AXES=6,
  ACC_XYZ_AXES=7,
  ACC_AXES_INVALID=8
} Acc_Channels_t;

#endif
