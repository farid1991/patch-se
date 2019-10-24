#ifndef _IILLUMINATIONMANAGER_H_
#define _IILLUMINATIONMANAGER_H_

//UUID CID_CIlluminationManager = {0xD7, 0xEF, 0x2A, 0x56, 0x94, 0x72, 0x40, 0x5E, 0xBF, 0xCA, 0xA2, 0x83, 0x97, 0x79, 0xF1, 0x9A};
//UUID IID_IIlluminationManager = {0x60, 0x90, 0xF1, 0x81, 0xA5, 0x31, 0x43, 0x3A, 0x82, 0x30, 0x69, 0xF0, 8, 0xBC, 0xD1, 0xD1};

typedef enum
{
  UIBacklightStatus_On,
  UIBacklightStatus_Off,
  UIBacklightStatus_Blink,
  UIBacklightStatus_Low
} UIBacklightStatus_t;

typedef enum
{
  UIBacklightMode_On,
  UIBacklightMode_Off,
  UIBacklightMode_Automatic,
  UIBacklightMode_LowOff,
  UIBacklightMode_LowOn
} UIBacklightMode_t;

class ICBBacklight: public IUnknown
{
public:
  virtual void OnInitiated(void* statusCode, int nbrOfItems, bool random, bool loop, void* clientData);
};

class IBacklight: public IUnknown
{
public:
  virtual int GetStatus(int display, UIBacklightStatus_t* pStatus);
  virtual int GetMode(UIBacklightMode_t* pMode);
  virtual int GetOnLevel(int display, char* pLevel);
  virtual int SetOverrideMode(UIBacklightMode_t mode);
  virtual int unk_20(int);
  virtual int SetOnLevel(int display, char pLevel);
  virtual int ResetOverrideMode();
  virtual int KeyLight(bool mode);
  virtual int unk_30(int display);
  virtual int unk_34(int display);
  virtual int unk_38();
  virtual int Fade(int display);
  virtual int FadeOnTimer(int display, int time);
  virtual int unk_44(int unk1, int unk2, int unk3, int unk4, int time);
  virtual int unk_48();
  virtual int BlinkTime(int display, int onTime, int offTime);
  virtual int unk_50();
  virtual int ActiveDisplay(int display);
  virtual int DeactiveDisplay();
  virtual int unk_5C();
  virtual int unk_60();
  virtual int unk_64();
  virtual int On_TimerCB(ICBBacklight* pICBBacklight, u16 msgBase, int clientData, int* pTimerHandle);
  virtual int Off_TimerCB(int pTimerHandle);
  virtual int unk_70(int unk1, int unk2);
  virtual int unk_74();
  virtual int unk_78();
  virtual int unk_7C();
  virtual int Tally_Lamp(int id, int unk, int level);
  virtual int unk_84();
  virtual int unk_88();
  virtual int unk_8C();
  virtual int unk_90();
  virtual int unk_94();
};

/*
FadeToLevel
ActivateMode
On_State_Time
*/

class ILightEffect: public IUnknown
{
public:
  virtual int StartType(int effectTypeID);
  virtual int unk_14(int*);
  virtual int StartTypeOnLevel(int effectTypeID, char pLevel);
  virtual int StartEffectFile(wchar_t* filename);
  virtual int unk_20();
  virtual int unk_24();
  virtual int unk_28();
  virtual int unk_2C(int);
  virtual int unk_30();
  virtual int Stop();
  virtual int SetEffectColor(char* red, char* green, char* blue);
  virtual int unk_3C(void);
  virtual int unk_40();
  virtual int unk_44(int* unk);
  virtual int unk_48(/*..., int null, int null, ...*/);
  virtual int unk_4C();
  virtual int unk_50(/*int one, ...*/);
  virtual int unk_54(/*...*/);
};

class IIlluminationManager: public IUnknown
{
public:
  virtual int CreateBacklight(IBacklight** pIBacklight); //0x78
  virtual int CreateLightEffect(ILightEffect** pILightEffect); //0x74
};

#endif
