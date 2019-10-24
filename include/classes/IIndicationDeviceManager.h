#ifndef _INDICATIONDEVICEMANAGER_H_
#define _INDICATIONDEVICEMANAGER_H_

//UUID CID_CIndicationDeviceManager = {0x3F, 0x48, 0xFE, 0x27, 0x64, 0xF8, 0x49, 7, 0xA0, 0xE6, 0xEA, 0x2B, 0xC0, 0xE0, 0xCC, 0xC8};
//UUID IID_IIndicationDeviceManager = {0xD, 0x44, 0xBF, 0x86, 0x86, 0xEA, 0x4C, 0x8A, 0xAE, 0x7B, 0xBA, 0x26, 0x40, 0xC8, 0x63, 0x10};

typedef enum
{
  VIBRATOR_DEVICE_MODE_OFF,
  VIBRATOR_DEVICE_MODE_ON,
  VIBRATOR_DEVICE_MODE_ON_IF_SILENCE
}TVibratorDeviceMode;

class IVibratorDevice: public IUnknown
{
public:
  virtual int GetMode(TVibratorDeviceMode* pVibratorMode);
  virtual int SetMode(TVibratorDeviceMode VibratorMode);
  virtual int TurnOff();
  virtual int TurnOn(int Period, char DutyCycle);
};

class IBacklightDevice: public IUnknown
{
  virtual int unk_10();
  virtual int unk_14();
  virtual int SetOnLevel(int display, char pLevel);
};

class ILedControlDevice: public IUnknown
{
public:
  virtual int GetNrOfLeds(int* NrOfLeds);
  virtual int TurnOff(int lednum);
  virtual int TurnOn(int lednum, int unk, int unk1);
};

class IIndicationDeviceManager: public IUnknown
{
public:
  virtual int CreateVibratorDevice(IVibratorDevice** pIVibratorDevice);
  virtual int CreateBacklightDevice(IBacklightDevice** pIBacklightDevice);
  virtual int CreateLedControlDevice(ILedControlDevice** pILedControlDevice);
};

#endif
