#ifndef _IMMEPLAYER_H_
#define _IMMEPLAYER_H_

#include "..\types\Basic_types.h"
#include "..\types\IMMETypes.h"
#include "..\types\UIRect_types.h"

class IMMEPlayer : public IUnknown
{
public:
  virtual int GetHandle(FUint32 *handle);
  virtual int GetState(TMMEState *state);
  virtual int GetTime(TMMETime *elapsedTime);
  virtual int SetTime(TMMETime *offsetTime);
  virtual int SetDisplayAppearance(TUIRectangle *TMMEVideoArea);
  virtual int Play(FUint32 unk_null, TBool repeat);
  virtual int Pause();
  virtual int SetFastForwardRewindBoundaryConditions(TMMEWindCondition windCondition);
  virtual int SetWindTimerInterval(FUint32 time);
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

#endif
