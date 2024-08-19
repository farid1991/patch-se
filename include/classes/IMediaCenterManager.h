#ifndef _IMEDIACENTER_H_
#define _IMEDIACENTER_H_

#include "IUnknown.h"

#include "..\types\Basic_types.h"
#include "..\types\OPA_types.h"

// CID_IMediaCenterManager = {0xF0, 0x8A, 0xB9, 0xCA, 0xB9, 0xCA, 0x44, 0x1D, 0xAD, 0x3F, 0x0F, 0x03, 0x99, 0xDB, 0x2F, 0x26};
// IID_IMediaCenterManager = {0xCB, 0x76, 0x32, 0x14, 0x31, 0x9C, 0x47, 0x1D, 0x99, 0xA2, 0x7D, 0x54, 0x7C, 0x3C, 0xDA, 0x9F};

typedef enum
{
  TUIMediaCenterOrientation_VERTICAL,  ///< Vertical orientation.
  TUIMediaCenterOrientation_HORIZONTAL ///< Horizontal orientation.
}TUIMediaCenterOrientation;

class ICBMediaCenterSettings : public IUnknown
{
public:
  virtual void OnOrientationRetrieved(TUIMediaCenterOrientation orientation, int ClientData);
  virtual void OnAutoRotateRetrieved(char AutoRotate, int ClientData);
};

class IMediaCenterSettings : public IUnknown
{
public:
  virtual int GetOrientation(ICBMediaCenterSettings *pICBSettings, TMsgBase msgBase, TClientData clientData);
  virtual int IsAutoRotateEnabled(ICBMediaCenterSettings *pICBSettings, TMsgBase msgBase, TClientData clientData);
  virtual int SetOrientation(int orientation);
  virtual int LockOrientation(int orientation);
  virtual int UnlockOrientation(void);
  virtual int DisableEffect(void);
  virtual int EnableEffect(void);
};

class IMediaCenterManager : public IUnknown
{
public:
  virtual int GetMediaCenter(IUnknown **ppIUIMediaCenter);
  virtual int GetMediaCenterSettings(IMediaCenterSettings **ppIMediaCenterSettings);
  virtual int GetMediaCenterTree(IUnknown **ppIUIMediaCenterTree);
  virtual int GetMediaCenterMultitasking(IUnknown **ppIUIMediaCenterMultitasking);
  virtual int GetMediaCenterResource(IUnknown **ppIUIMediaCenterResource);
};

#endif
