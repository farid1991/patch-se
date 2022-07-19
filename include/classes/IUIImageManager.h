#ifndef _IUIIMAGEMANAGER_H_
#define _IUIIMAGEMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\UIRect_types.h"

class IUIImage : public IUnknown
{
public:
  virtual int GetDimensions(TSigned *pWidth, void *pWidthUnit, TSigned *pHeight, void *pHeightUnit);
  virtual int CreateRenderer(IUnknown *pIUIImageRenderer);
  virtual int IsAnimation(TBool *IsAnimation);
  virtual int IsScalable(TBool *IsScalable);
};

class IUIImageManager : public IUnknown
{
public:
  virtual int CreateFromPath(wchar_t *fpath, wchar_t *fname, char *pMime, long mimeLength, IUIImage **pUIImage);
  virtual int CreateFromCanvas(IUnknown *pGC, IUIImage **pUIImage);
  virtual int CreateFromIcon(TUnsigned imageID, IUIImage **pUIImage);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  virtual int CreateFromIconWithIconSet(TUnsigned imageID, IUnknown *pIconSet, IUIImage **pUIImage);
#endif
  virtual int CreateFromMemory(char *buf_image, long bufferSize, wchar_t *extension, long extensionLength, char *pMime, long mimeLength, IUIImage **pUIImage);
  virtual int CreateFromSimpleLockableBuffer(IUnknown *pISimpleLockableBuffer, long imageDataSize, wchar_t *extension, long extensionLength, char *pMime, long mimeLength, IUIImage **pUIImage);
#if defined(DB3350)
  virtual int unk_0x28();
#endif
  virtual int Draw(IUIImage *pUIImage, IUnknown *pGC, TUIRectangle rect);
};

#endif
