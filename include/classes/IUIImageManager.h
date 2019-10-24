#ifndef _IUIIMAGEMANAGER_H_
#define _IUIIMAGEMANAGER_H_

typedef struct
{
  long X;
  long Y;
}TUIPoint;

typedef struct
{
  long Width;
  long Height;
}TUISize;

typedef struct
{
  TUIPoint Point;
  TUISize  Size;
}TUIRectangle;

class IUIImage: public IUnknown
{
public:
  virtual int GetDimensions(long* pWidth, void* pWidthUnit, long* pHeight, void* pHeightUnit);
  virtual int CreateRenderer(IUnknown* pIUIImageRenderer);
  virtual int IsAnimation(bool* IsAnimation);
  virtual int IsScalable(bool* IsScalable);
};

class IUIImageManager: public IUnknown
{
public:
  virtual int CreateFromPath(wchar_t* fpath, wchar_t* fname, char* pMime, long mimeLength, IUIImage** pUIImage);
  virtual int CreateFromCanvas(IUnknown* pGC, IUIImage** pUIImage);
  virtual int CreateFromIcon(long imageID, IUIImage** pUIImage);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  virtual int CreateFromIconWithIconSet(long imageID, IUnknown* pIconSet, IUIImage** pUIImage);
#endif
  virtual int CreateFromMemory(char* buf_image, long bufferSize, wchar_t* extension, long extensionLength, char* pMime, long mimeLength, IUIImage** pUIImage);
  virtual int CreateFromSimpleLockableBuffer(IUnknown* pISimpleLockableBuffer, long imageDataSize, wchar_t* extension, long extensionLength, char* pMime, long mimeLength, IUIImage** pUIImage);
  virtual int Draw(IUIImage* pUIImage, IUnknown* pGC, TUIRectangle rect);
};

#endif
