#ifndef _IUIIMAGEMANAGER_H_
#define _IUIIMAGEMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\OPA_types.h"
#include "..\types\UIRect_types.h"
#include "..\types\Time_types.h"

#include "IIconSet.h"

const TMillisecond IUIIMAGERENDERER_TIME_INFINITY = FUINT32_MAX;

class IUIImageRenderer : public IUnknown
{
public:
  virtual int GetWidth(TUnsigned *pWidth, void *pUnit);
  virtual int GetHeight(TUnsigned *pHeight, void *pUnit);
  virtual int GetAnimationLength(TMillisecond *pLength);
  virtual int KeepAspectRatio(TBool keepAspectRatio);
  virtual int Restart(void);
  virtual int SetImageSourceRectangle(TRectangle *pRectangle);
  virtual int GetImageSourceRectangle(TRectangle *pRectangle);
  virtual int SetDrawRectangle(TRectangle *pRectangle);
  virtual int GetDrawRectangle(TRectangle *pRectangle);
  virtual int Render(IUnknown *pICanvas, TMillisecond timeThisRender, TMillisecond *pTimeToNextRender);
};

class IUIImage : public IUnknown
{
public:
  virtual int GetDimensions(TSigned *pWidth, void *pWidthUnit, TSigned *pHeight, void *pHeightUnit);
  virtual int CreateRenderer(IUIImageRenderer *pIUIImageRenderer);
  virtual int IsAnimation(TBool *IsAnimation);
  virtual int IsScalable(TBool *IsScalable);
};

class IUIImageCanvas : IUIImage
{
public:
  virtual int GetCanvas(IUnknown **ppICanvas);
};

class IUIImageFile : IUIImage
{
public:
  virtual int GetFilenameAndDir(wchar_t **ppDir, wchar_t **ppFilename);
};

class IUIImageIcon : IUIImage
{
public:
  virtual int GetIcon(TIconId *pIconID);
};

class IUIImageManager : public IUnknown
{
public:
  virtual int CreateFromPath(wchar_t *fpath, wchar_t *fname, char *pMime, TUnsigned mimeLength, IUIImage **pUIImage);
  virtual int CreateFromCanvas(IUnknown *pICanvas, IUIImage **pUIImage);
  virtual int CreateFromIcon(TUnsigned imageID, IUIImage **pUIImage);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  virtual int CreateFromIconWithIconSet(TUnsigned imageID, IIconSet *pIconSet, IUIImage **pUIImage);
#endif
  virtual int CreateFromMemory(FUint8 *pBuffer, TUnsigned bufferSize, wchar_t *pExtension, TUnsigned extensionLength, char *pMime, TUnsigned mimeLength, IUIImage **pUIImage);
  virtual int CreateFromSimpleLockableBuffer(IUnknown *pISimpleLockableBuffer, TUnsigned imageDataSize, wchar_t *extension, TUnsigned extensionLength, char *pMime, TUnsigned mimeLength, IUIImage **pUIImage);
#if defined(DB3350)
  virtual int unk_0x28();
#endif
  virtual int Draw(IUIImage *pUIImage, IUnknown *pICanvas, TUIRectangle targetRect);
};

#endif
