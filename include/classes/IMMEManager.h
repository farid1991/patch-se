#ifndef _IMMEMANAGER_H_
#define _IMMEMANAGER_H_

#include "..\\include\types\IMMETypes.h"

//UUID CID_CMMEManager = {0x12, 0xE7, 0x4B, 0x58, 0x29, 0xA0, 0x40, 0xFF, 0x80, 0x55, 0x16, 0xA0, 0x2A, 0xB6, 0xCF, 0xAF};
//UUID IID_IMMEManager = {0x32, 0xA3, 0xED, 9, 7, 0x21, 0x48, 0xE6, 0xA5, 0x3D, 0x91, 0x47, 0x79, 0xF3, 0xE6, 0xAC};
//UUID IID_IMMESessionContentUtility = {0x74, 0xF0, 0xE9, 0x93, 0x27, 0xDB, 0x4E, 0xD9, 0x8E, 0x75, 0x6E, 0xF4, 0xC7, 0x26, 0x5E, 0x3E};
//UUID IID_IMMESessionEqualizer = {0x62, 0xAE, 0xAF, 0xCC, 0x8A, 0x76, 0x4A, 0xEA, 0xA2, 0xE6, 0x54, 0x97, 0x58, 0xA7, 0x67, 0x6C};
//UUID IID_IMMESessionStreaming = {6, 0x6D, 0x7A, 0x77, 0xDB, 0xB3, 0x47, 0x9B, 0x86, 0xC, 0x7C, 0xC9, 0xEE, 0xB7, 0xB9, 0x2A};

/*
CMMESession_GetSetupInterface
CMMESession_Constructor
CMMESession_Destructor
CMMESession_IsStreamingLink
*/

class ICBMMEPlayer;

class IMMESessionContentUtility: public IRoot
{
public:
  virtual int IsFeatureValid();
  virtual int IsContentValid();
  virtual int GetMediaProperties(wchar_t* pFilePath, TMMEMediaProperties* mediaProperties);
  virtual int GetMediaFromMimeType(char* type);
  virtual int GetMediaFormats();
  virtual int GetVideoProfile();
  virtual int SaveVideoFrameAsImage();
};

class IMMESessionEqualizer: public IRoot
{
public:
  virtual int Enable();
  virtual int Disable();
  virtual int IsEnabled();
  virtual int SetGain();
  virtual int GetGain();
  virtual int SetPreset();
};

class IMMESessionStreaming: public IRoot
{
public:
  virtual int SetAccount();
  virtual int SetLocalBearerDetection(/*pIMMESessionStreaming, (TBool)pThis->settings.useLocalBearers*/);
  virtual int OpenNetworkConnection();
  virtual int CloseNetworkConnectionSession();
};

class IMMEPlayer: public IRoot
{
public:
  virtual int GetHandle(int* handle);
  virtual int GetState(TMMEState* state);
  virtual int GetTime(TMMETime* elapsedTime);
  virtual int SetTime(TMMETime* offsetTime);
  virtual int SetDisplayAppearance(TRectangle* TMMEVideoArea);
  virtual int Play(int unk_null, bool repeat);
  virtual int Pause();
  virtual int SetFastForwardRewindBoundaryConditions(TMMEWindCondition windCondition);
  virtual int SetWindTimerInterval(int time);
  virtual int StartFastForward();
  virtual int StopFastForward();
  virtual int StartRewind();
  virtual int StopRewind();
  virtual int SlowMotion();
  virtual int SetFadeDownOnInterrupted(TMMEFadeDirection fadeDirection);
  virtual int StartAudioFade();
  virtual int Mute();
  virtual int UnMute();
  virtual int SetVolume();
  virtual int GetVolume();
};

class IMMESession: public IRoot
{
public:
  virtual int BeginPlaybackSession(int unk1, int unk2, int unk3, int unk4, int* sessionHandle);
  virtual int EndPlaybackSession(int sessionHandle);
  virtual int RequestPlaybackSessionFocus();
  virtual int SetStereoWidening(bool activate);
  virtual int CreatePlayer(ICBMMEPlayer* pICBMMEPlayer, TMsgBase msgBase, TClientData clientData, wchar_t* pFilePath, TMMEMediaProperties* mediaProperties, int unk1_null, int unk2_null, IMMEPlayer** pIMMEPlayer);
};

class IMMEManager: public IRoot
{
public:
  virtual int CreateSession(IMMESession** pIMMESession);
};

#endif
