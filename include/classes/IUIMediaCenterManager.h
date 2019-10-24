#ifndef _IUIMEDIACENTERMANAGER_H_
#define _IUIMEDIACENTERMANAGER_H_

//UUID CID_CUIMediaCenterManager = {0xF0, 0x8A, 0xB9, 0xCA, 0xB9, 0xCA, 0x44, 0x1D, 0xAD, 0x3F, 0xF, 3, 0x99, 0xDB, 0x2F, 0x26};
//UUID IID_IUIMediaCenterManager = {0xCB, 0x76, 0x32, 0x14, 0x31, 0x9C, 0x47, 0x1D, 0x99, 0xA2, 0x7D, 0x54, 0x7C, 0x3C, 0xDA, 0x9F};

class IUIMediaCenter;
class IUIMediaCenterTree;
class IUIMediaCenterMultitasking;
class IUIMediaCenterResource;

typedef enum
{
  TUIMediaCenterOrientation_VERTICAL,  ///< Vertical orientation.
  TUIMediaCenterOrientation_HORIZONTAL ///< Horizontal orientation.
}TUIMediaCenterOrientation;

class ICBUIMediaCenterSettings : public IUnknown
{
public:
  virtual void OnOrientationRetrieved(TUIMediaCenterOrientation orientation, int ClientData);
  virtual void OnAutoRotateRetrieved(char AutoRotate, int ClientData);
};

class IUIMediaCenterSettings : public IUnknown
{
public:
  virtual int GetOrientation(ICBUIMediaCenterSettings* pICBUIMediaCenterSettings, u16 msgBase, int ClientData);
  virtual int IsAutoRotateEnabled(ICBUIMediaCenterSettings* pICBUIMediaCenterSettings, u16 msgBase, int ClientData);
  virtual int SetOrientation(TUIMediaCenterOrientation orientation);
  virtual int LockOrientation(TUIMediaCenterOrientation orientation);
  virtual int UnlockOrientation();
  virtual int DisableEffect();
  virtual int EnableEffect();
};

class IUIMediaCenterManager : public IUnknown
{
public:
  virtual int GetMediaCenter(IUIMediaCenter** ppIUIMediaCenter);
  virtual int GetMediaCenterSettings(IUIMediaCenterSettings** ppIUIMediaCenterSettings);
  virtual int GetMediaCenterTree(IUIMediaCenterTree** ppIUIMediaCenterTree);
  virtual int GetMediaCenterMultitasking(IUIMediaCenterMultitasking** ppIUIMediaCenterMultitasking);
  virtual int GetMediaCenterResource(IUIMediaCenterResource** ppIUIMediaCenterResource);
};

#endif
