#ifndef _IACCELEROMETERMANAGER_H_
#define _IACCELEROMETERMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\OPA_types.h"
#include "..\types\IAccelerometer_types.h"

// UUID CID_CAccelerometerManager = {0xF7, 0xA4, 0x58, 0x00, 0xD8, 0x96, 0x47, 0xDE, 0x9C, 0x04, 0x6A, 0x30, 0xD5, 0x75, 0x50, 0x43};
// UUID IID_IAccelerometerManager = {0xB7, 0x6C, 0x85, 0x42, 0x43, 0x72, 0x43, 0x24, 0x98, 0x86, 0xFB, 0xD6, 0xF5, 0x26, 0x1F, 0x10};

class IAccelerometerControl : public IUnknown
{
public:
  virtual int SetInternalSamplingRate(Acc_InternalSamplingRate_t SampleRate);
  virtual int GetInternalSamplingRate(Acc_InternalSamplingRate_t *pSampleRate);
  virtual int SetDetectScale(Acc_ScaleSelection_t Scale);
  virtual int GetDetectScale(Acc_ScaleSelection_t *pScale);
  virtual int SetAxesUsage(Acc_Axes_OP_t x_axis, Acc_Axes_OP_t y_axis, Acc_Axes_OP_t z_axis);
  virtual int GetAxesUsage(Acc_Axes_OP_t *px_axis, Acc_Axes_OP_t *py_axis, Acc_Axes_OP_t *pz_axis);
  virtual int PowerOnChip(void);
  virtual int PowerOffChip(void);
};

class ICBAccelerometerData : public IUnknown
{
public:
  virtual int OnEvent(RVoid status, FUint32 eventType, TClientData clientData);
};

class IAccelerometerData : public IUnknown
{
public:
  virtual int GetRawAxisValues(FUint8 *pX, FUint8 *pY, FUint8 *pZ);
  virtual int GetMaxAxisValues(FSint32 *pX, FSint32 *pY, FSint32 *pZ);
  virtual int GetMinAxisValues(FSint32 *pX, FSint32 *pY, FSint32 *pZ);
  virtual int ResetMaxMinValues(void);
  virtual int GetAxisValues(FSint32 *pX, FSint32 *pY, FSint32 *pZ);
  virtual int SubscribeToEvents(ICBAccelerometerData *pICBAccelerometerData,
                                  TMsgBase msgBase,
                                  TClientData clientData,
                                  Acc_PollFrequency_t freq,
                                  Acc_Channels_t channels,
                                  FUint32 samples,
                                  Acc_Filter_Type_t filterType,
                                  Acc_Filter_Param_t filterParam,
                                  THnd *pSession);
  virtual int Unsubscribe(THnd hSession);
  virtual int GetNeededBufferSize(THnd hSession, Acc_BufferSize_t *pSize);
  virtual int GetBuffer(THnd hSession, FSint16 *pBuffer, Acc_BufferSize_t length, FUint32 *pNbrOfMissedBuffers);
};

class IAccelerometerManager : public IUnknown
{
public:
  virtual int CreateAccelerometerControl(IAccelerometerControl **ppIAccelerometerControl);
  virtual int CreateAccelerometerData(IAccelerometerData **ppIAccelerometerData);
};

#endif
