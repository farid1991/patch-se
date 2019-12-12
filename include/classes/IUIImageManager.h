#ifndef _IUIIMAGEMANAGER_H_
#define _IUIIMAGEMANAGER_H_

#include "..\\include\types\Time_types.h"
#include "..\\include\types\UIRect_types.h"
#include "..\\include\types\UIIconTypes.h"

const UUID IID_IUIImageManager={0x63, 0xEF, 0xA5, 0x31, 0xFF, 0xD1, 0x4E, 0x25, 0xA6, 0x24, 0x60, 0x0A, 0x96, 0x81, 0x3F, 0xC5};
const UUID CID_CUIImageManager={0x86, 0x2D, 0xF9, 0x95, 0x1C, 0x3B, 0x4B, 0x24, 0xB7, 0x4D, 0x8F, 0x98, 0x70, 0x1E, 0x5D, 0x14};

typedef void TSizeUnit;

class ISimpleLockableBuffer;

typedef struct
{
  /// Icon ID
  TIconId iconID;
  /// A string in the "icon://<Icon-ID>" format.
  TChar* pURI;

} TUIImageIconFactoryCreationInfo;

class IIconSet : public IRoot
{
public:
  /**
   * Gets icon data from the IconFile.
   *
   * @note  The client is responsible to free the the mime-type string.
   *
   * @param[in] iconId The icon id to get data for.
   * @param[out] ppISimpleLockableBuffer The icon data.
   * @param[out] pSize size of the image data in the ppISimpleLockableBuffer
   * @param[out] ppMimeType The mime type for the icon data
   *
   * @note The memory at *ppMimeType must be freed by caller!
   *
   * @return  Returns OPA_OK if successful.
   */
  virtual int GetIconData( TIconId iconId, ISimpleLockableBuffer** ppISimpleLockableBuffer, FUint32* pSize, TAscii** ppMimeType);

  /**
   * Gets icon header data from the IconSet. Used by the icon IUIImage.
   *
   * @param[in] iconId The icon id to get data for.
   * @param[out] pTIconHeader The icon header.
   * @param[out] ppISimpleLockableBufferExtraData Optional extra header data (format specific). Can be NULL.
   *
   * @return  Returns OPA_OK if successful.
   */
  virtual int GetIconHeaderData( TIconId iconId, TIconHeader* pTIconHeader, ISimpleLockableBuffer** ppISimpleLockableBufferExtraData);

  /**
   * This function loads a new icon file to the IconSet.
   *
   * @note  If the icon file contains icons with the same IconId as in the 
   *        original IconSet, the new icons will override the old.
   *
   * @param[in] pIconFilePath Path to the icon file.
   *
   * @return  Returns OPA_OK if successful.
   */
  virtual int LoadIconFile( TChar* pIconFilePath );

  /**
   * This function unloads an icon file from the IconSet.
   *
   * @note  Only files loaded using IIconSet::LoadIconFile can be unloaded. 
   *        The original iconfile (given in IIconManager::CreateIconSet)
   *        cannot be unloaded.
   *
   * @param[in] pIconFilePath Path to the icon file.
   *
   * @return  Returns OPA_OK if successful.
   */
  virtual int UnloadIconFile( TChar* pIconFilePath );

  /**
   * This function returns the version number for a certain icon
   *
   * 
   * @param[in] iconId ID of the icon to check.
   * @param[out] pVersion  Version of the icon.
   *
   *
   * @return  Returns OPA_OK if successful.
   */
  virtual int GetIconVersion( TIconId iconId, FUint32 *pVersion );
};

class IUIImageRenderer : public IRoot
{
public:
  /**
   * Get image original width and its type.
   * @param[out] pWidth Returned width.
   * @param[out] pUnit Describe the width value.
   * @return OPA_OK if successful
   */
  virtual int GetWidth( TUnsigned* pWidth, TSizeUnit* pUnit );

  /**
   * Get image original height and type.
   * @param[out] pHeight Returned height.
   * @param[out] pUnit Describe the height value.
   * @return OPA_OK if successful.
   */
  virtual int GetHeight( TUnsigned* pHeight, TSizeUnit* pUnit );

  /**
   * Get animation length (if applicable). If not animated length will be 0.
   * @param[out] pLength Length of animation in milliseconds.
   * @return OPA_OK if successful.
   */
  virtual int GetAnimationLength( TMillisecond* pLength );

  /**
   * Set if renderer should keep aspect ratio or not.
   * @note Renderer can answer NOT_APPLICABLE
   * @param[in] keepAspectRatio TRUE or FALSE.
   * @return OPA_OK or status in TImageStatus.
   */
  virtual int KeepAspectRatio( TBool keepAspectRatio );

  /// Restarts animation (if applicable)
  virtual int Restart(void);

  /// Set region of interest in image.
  virtual int SetImageSourceRectangle( TRectangle* pRectangle );

  /// Get the current region of interest of image.
  virtual int
    GetImageSourceRectangle( TRectangle* pRectangle );

  /**
   * Set region of interest on canvas.
   * @param[in] pRectangle Area to be set.
   * @return OPA_OK if successful.
   */
  virtual int SetDrawRectangle( TRectangle* pRectangle );

  /** 
   * Get current region of interest for output surface.
   * @param[out] pRectangle Returned area of interest.
   * @return OPA_OK if successful.
   */
  virtual int GetDrawRectangle( TRectangle* pRectangle );
  
  /**
   * Renders onto the canvas.
   * If still image (only one frame) decoder should return IDECODER_TIME_INFINITY in pTimeToNextRender.
   *
   * @param[in] pICanvas Pointer to canvas interface.
   * @param[in]  timeThisRender Time to render. Zero if still image.
   * @param[out] pTimeToNextRender Pointer to delta time.
   * @retval OPA_OK if successful.
   */
  virtual int Render(IRoot* pICanvas, 
                     TMillisecond timeThisRender, 
                     TMillisecond* pTimeToNextRender );

};

class IUIImage : public IRoot
{
public:
  /**
   * Returns the size of the image.
   *
   * @retval OPA_OK on success.
   * @retval IMAGE_STATUS_UE_NOT_APPLICABLE if size cannot be determined at this stage.
   * @see @ref TSizeUnit for additional possible error codes.
   */
  virtual int GetDimensions(TUnsigned* pWidth, 
                            TSizeUnit* pWidthUnit, 
                            TUnsigned* pHeight, 
                            TSizeUnit* pHeightUnit);
  
  /**
   * Creates a renderer that can be used to output the image
   * to a canvas (on or off screen).
   *
   * @retval OPA_OK on success.
   */
  virtual int CreateRenderer(IRoot* pIUIImageRenderer);
  
  /**
   * check if image format generally is an animation or not.
   * @param[out] pIsAnimation Return value TRUE if animation else FALSE.
   */
  virtual int IsAnimation(TBool* IsAnimation);
  
  /**
   * check if image format is generally scalable or not.
   * @param[out] pIsScalable Holder for return value. TRUE if scalable else FALSE.
   */
  virtual int IsScalable(TBool* IsScalable);
};

class IUIImageCanvas : public IUIImage
{
public:
  ///Get canvas from IUIImage
  virtual int GetCanvas( IRoot** ppICanvas );
};

class IUIImageFile : public IUIImage
{
public:
  ///Get pointers to string with directory and filename
  virtual int GetFilenameAndDir( TChar** ppDir, TChar** ppFilename);
};

class IUIImageIcon : public IUIImage
{
public:
  ///Get icon id from the IUIImage
  virtual int GetIcon( TIconId* pIconID );
};

class IUIImageManager : public IRoot
{
public:
  /**
   * Creates an IUIImage from a a path. It's possible to leave the pName parameter 
   * empty and have the entire path in pDir. The MIME type does not have to be
   * specified and can be left empty. If no MIME type is supplied, the correct 
   * factory functon are found by using the extention on the file.
   *
   * @param pDir          Directory for the image.
   * @param pName         Filename of the image.
   * @param pMime         Optional MIME string.
   * @param mimeLength    Length of mime string.
   * @param ppIUIImage    Resulting IUIImage interface. 
   */
  virtual int CreateFromPath(TChar* fpath, 
                             TChar* fname,
                             TAscii* pMime, 
                             TUnsigned mimeLength, 
                             IUIImage** pUIImage);
  
  /**
   * Creates IUIImage from a Canvas-interface.
   *
   * @param pICanvas    Pointer to canvas interface.
   * @param ppIUIImage  Resulting IUIImage interface.
   */
  virtual int CreateFromCanvas(IRoot* pICanvas, IUIImage** ppUIImage);
  
  /**
   * Creates IUIImage from a static font index.
   *
   * @note If the id given is an ImageId, this fucntion will return
   *       the IUIImage in the ImageFont for this ID.
   *
   * @param icon        Icon index.
   * @param ppIUIImage  Resulting IUIImage interface.
   */
  virtual int CreateFromIcon(TUnsigned icon, IUIImage** ppUIImage);
  
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  /**
   * Creates IUIImage from a specified IconSet.   
   *
   * @param icon        Icon index.
   * @param pIIconSet    Icon set.
   * @param ppIUIImage  Resulting IUIImage interface.
   */
  virtual int CreateFromIconWithIconSet(TUnsigned icon, 
                                        IIconSet* pIconSet, 
                                        IUIImage** pUIImage);
#endif
  
  /**
   * Creates IUIImage from memory. It's only needed to supply etiher
   * extention or MIME type. If both are supplied only the MIME type 
   * are used.
   *
   * If the creation of the IUIImage fails, the memory (pBuffer) will 
   * be freed.
   *
   * @param pBuffer           Buffer containing the image data
   * @param bufferSize        Size of the buffer
   * @param pExtension        Optional data type extension. E.g. "gif".
   * @param extensionLength   Number of chars in extension. E.g. "3".
   * @param pMime             String with mime type. E.g. "image/gif".
   * @param mimeLength        Number of chars in mime string. E.g. "9".
   * @param ppIUIImage        Resulting IUIImage interface. 
   */
  virtual int CreateFromMemory(FUint8* pBuffer, 
                               TUnsigned bufferSize, 
                               TChar* pExtension, 
                               TUnsigned extensionLength, 
                               TAscii* pMime, 
                               TUnsigned mimeLength, 
                               IUIImage** ppUIImage);
  
  /**
   * Creates IUIImage from a SimpleLockableBuffer. It's only needed to 
   * supply etiher extention or MIME type. If both are supplied only 
   * the MIME type are used.
   *
   * @param pISimpleLockableBuffer  SimpleLockableBuffer containing the image data
   * @param imageDataSize           Size of the image data in bytes (size of the buffer and image can differ)
   * @param pExtension              Optional data type extension. E.g. "gif".
   * @param extensionLength         Number of chars in extension. E.g. "3".
   * @param pMime                   String with mime type. E.g. "image/gif".
   * @param mimeLength              Number of chars in mime string. E.g. "9".
   * @param ppIUIImage              Resulting IUIImage interface. 
   */
  virtual int CreateFromSimpleLockableBuffer(ISimpleLockableBuffer* pISimpleLockableBuffer,
                                             TUnsigned imageDataSize,
                                             TChar* pExtension,
                                             TUnsigned extensionLength,
                                             TAscii* pMime,
                                             TUnsigned mimeLength,
                                             IUIImage** ppIUIImage);
  
  /**
   * Draw the image to the canvas at the specified position with the
   * specifed width and height. Since this draw does not subscribe to 
   * any callbacks from the render-component, it's not possible to 
   * draw animated IUIImages (They will display as static images) or
   * using other drawing-methods, such as Progressive Rendering of JPEG
   * images.
   *
   * @param pIUIImage   The IUIImage to draw
   * @param pICanvas    The canvas to draw to.
   * @param targetRect  The target rectangle do draw to
   */
  virtual int Draw(IUIImage* pUIImage, IRoot* pGC, TUIRectangle rect);
};

class IUIImageFactory : public IRoot
{
};

class IUIImageIconFactory : IUIImageFactory
{
public:
  /**
   * Creates an image from an icon ID.
   */
  virtual int CreateImage( TUIImageIconFactoryCreationInfo* pCreationInfo, IUIImage** ppIUIImage);

  /**
   * Creates an image from an icon ID using the specifed IconSet.
   */
  virtual int CreateImageFromIconSet( TUIImageIconFactoryCreationInfo* pCreationInfo, IIconSet* pIIconSet, IUIImage** ppIUIImage);
};

#endif
