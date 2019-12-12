#ifndef _IFONTMANAGER_H_
#define _IFONTMANAGER_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\UIFont_types.h"
#include "..\\include\types\UIFontParam_types.h"
#include "..\\include\types\UIRect_types.h"

const UUID IID_IUIFontManager = {0x95,0xD0,0x5F,0xCA,0x0F,0x30,0x4F,0x92,0x94,0x3B,0x13,0x89,0x21,0x2F,0x09,0xD7};
const UUID CID_CUIFontManager = {0x82,0xAC,0x97,0x9B,0x58,0x44,0x41,0x39,0xA0,0xD3,0xE6,0xCF,0x72,0xB5,0x80,0x69};

class IString;

/**
 *  Height of the font
 */
typedef FSint32 TUIFontHeight;

/**
 *  Ascent of the font
 */
typedef FSint32 TUIFontAscent;

typedef TUIFontParam TUIFontData;

/**
 *  Glyph metrics such as bounding box and advance width.
 *
 */
typedef struct
{
  TFloat       xAdvance;
  TFloat       yAdvance;
  TFloat       xPixelAdvance;
  TFloat       yPixelAdvance;
  TUIRectangle boundingBox;
} TUIGlyphMetrics;

class IUIFontResource : public IRoot
{
public:
 /**
  *  Get the name of this font.
  *
  *  This function takes a buffer and buffer length as parameters and
  *  will return with the buffer set to the font name.
  *
  *  @param[out] ppIString font name. 
  *     
  * @return This method returns an RVoid status code.
  */
  RVoid GetName( IRoot** ppIString );

 /**
  *  Get the style of this font.
  *
  *  @param[out] pStyle font style. 
  *     
  * @return This method returns an RVoid status code.
  */
  RVoid GetStyle( TUIFontResourceStyle *pStyle );
};

class IUIFontResourceManager : public IRoot
{
public:
 /**
  *  Gets the default system font
  *
  *  @param[in]  style         
  *  @param[out] ppIUIFontResource pointer to IUIFontResource font object
  *
  *  @return This method returns an RVoid status code.
  *
  */
  RVoid GetDefaultFont(TUIFontResourceStyle  style,
                       IUIFontResource**     ppIUIFontResource );

/**
  *  Gets a font from family name
  *
  *  @param[in]  pIFamilyName         
  *  @param[in]  style         
  *  @param[out] ppIUIFontResource pointer to IUIFontResource font object
  *
  *  @return This method returns an RVoid status code.
  *
  */
  RVoid GetFontFromFamilyName(IString*              pIFamilyName,
                              TUIFontResourceStyle  style,
                              IUIFontResource**     ppIUIFontResource );

 /**
  *  Adds a font to the resource manager
  *
  *  @param[in]  pIFamilyName         
  *  @param[in]  pIFontPath
  *  @param[in]  style
  *  @param[out]  ppIUIFontResource pointer to IUIFontResource font objec
  *
  *  @return This method returns an RVoid status code.
  *
  */
  RVoid AddFontResource(IString*              pIFamilyName,
                        IString*              pIFontPath,
                        TUIFontResourceStyle  style,
                        IUIFontResource**     ppIUIFontResource );

  /**
  *  Sets the default font group
  *
  *  @param[in]  pIFamilyName         
  *
  *  @return This method returns an RVoid status code.
  *
  */
  RVoid SetDefaultFont(IString*  pIFamilyName);

  /**
  *  Gets a font from file
  *
  *  @param[in]  pIPath          Full path to font
  *  @param[out] ppIUIFontResource pointer to IUIFontResource font object
  *
  *  @return This method returns an RVoid status code.
  *
  */
  RVoid GetFontFromFile( IString* pIPath, IUIFontResource** ppIUIFontResource
  );
};

class IUIFontStyle: public IRoot
{
public:
 /**
  *  Returns the scaled font ascender value in fixed point pixel units. 
  *
  *  @param [out] pAscender ascender value.
  *  
  * @return This method returns an RVoid status code.
  *
  */
  virtual int GetAscender( TFloat* pAscender );

 /**
  *
  *  Returns the scaled font descender value in fixed point pixel units. 
  *
  *  @param [out] pDescender descender value.
  *
  * @return This method returns an RVoid status code.
  *
  */  
  virtual int GetDescender( TFloat* pDescender );

 /**
  *  Returns the scaled font leading value in fixed point pixel units. 
  *
  *  param [out] pLeading leading value.
  *
  *
  * @return This method returns an RVoid status code.
  */
  virtual int GetLeading( TFloat* pLeading );

 /**
  *
  *  Returns the scaled font x size value in fixed point pixel units. 
  *
  *  param [out] pXSize x value.
  *
  * @return This method returns an RVoid status code.
  *
  */  
  virtual int GetXSize( TFloat* pXSize );

 /**
  *
  *  Returns the scaled font y size value in fixed point pixel units. 
  *
  *  2param [out] pYSize y value.
  *
  * @return This method returns an RVoid status code.
  *
  */  
  virtual int GetYSize( TFloat* pYSize );

  /**
   *
   *  Maps a character through the font cmap to produce a glyphID.
   *
   *      This function is similar to TsFont_mapChar, except it accounts
   *      for mapping that may be a function of style.  In particular,
   *      if the rendering style is set to TS_RENDER_COLORED_ICON, it
   *      does not use the normal cmap.
   *
   *  Parameters:
   *      style   - [in] handle to this font style object
   *      charID  - [in] character value.
   *      glyphID - [out] function returns the glyphID here.
   *
   * @return This method returns an RVoid status code.
   */
  virtual int MapChar( FSint32 charID, FSint32 *pGlyphID );
  
  /**
   *
   *  Returns the glyph metrics associated with a fontStyle and a glyph index value.
   *
   *  Glyph metrics are returned within the 'metrics' structure.
   *      
   *  If the metrics can't be obtained then the metrics structure is
   *  initialized to 0 and the function returns an error.
   *      
   *  @param [in]  glyphID glyphID within font (TrueType calls this glyph index)
   *  @param [out] pMetrics pointer to metrics structure.
   *
   * @return This method returns an RVoid status code.
   */
  virtual int GetGlyphMetrics( FSint32 glyphID,  TUIGlyphMetrics *pMetrics );

  /**
   *
   *  Returns a reference to the IUIFontResource used to construct this font style.
   *
   *  @param [out]  ppIUIFontResource pointer to IUIFontResource object
   *
   * @return This method returns an RVoid status code.
   */  
  virtual int GetFont( IRoot **ppIUIFontResource );

  /**
   *
   *  Get the original font params used to construct this font style.
   *
   *      This function fills the fontParam structure with the values
   *      that were used to construct this font style.
   *
   *  @param [out] pFontParam pointer to font parameters structure.
   *
   * @return This method returns an RVoid status code.
   */  
  virtual int GetFontParams( IRoot *pFontParam);
};

class IUIFont: public IRoot
{
public:
  /**
   * Gets the face of the font.
   * @param[out] pFace face of the font.
   * @return This method returns an RVoid status code.
   */
  virtual int GetFace( TUIFontFace* pFace );
  
  /**
   * Gets the size of the font.
   * @param[out] pSize size of the font.
   * @return This method returns an RVoid status code.
  */
  virtual int GetSize( TUIFontSize* pSize );
  
  /**
   * Gets the style of the font.
   * @param[out] pStyle style of the font.
  * @return This method returns an RVoid status code.
   */
  virtual int GetStyle( TUIFontStyle* pStyle );
  
  /**
   * Gets the ascent of the font.
   * @param[out] pAscent ascent of the font.
  * @return This method returns an RVoid status code.
   */
  virtual int GetFontAscent( FSint32* pAscent );
  
  /**
   * Gets the height of the font.
   * @param[out] pHeight height of the font.
  * @return This method returns an RVoid status code.
   */
  virtual int GetFontHeight( FSint32* pHeight );
  
  /**
   * Returns true if the font is bold.
   */ 
  virtual int IsBold(void);
  
  /**
   * Returns true if the font is italic.
   */
  virtual int IsItalic(void);
  
  /**
   * Returns true if the font is plain.
   */
  virtual int IsPlain(void);
  
  /**
   * Returns true if the font is underlined.
   */ 
  virtual int IsUnderlined(void);
  
  /**
  * Gets the fontstyle. 
  * For backward compabillities
  *
  * @param[out] ppIUIFontStyle interface pointer to the font style component.
  * @return This method returns an RVoid status code.
  */ 
  virtual int GetFontStyle( IUIFontStyle** ppIUIFontStyle );
};

class IUIFontFactory: public IRoot
{
public:
  /**
   *  Obtains an object representing a font having the specified face, style, and size.
   *
   *  @param[in] Face  face of the font @note not implemented 
   *  @param[in] Size  size of the font
   *  @param[in] Style style of the font
   *  @param[out] ppIUIFont interface pointer to the font
   */
  virtual int GetFont(TUIFontFace Face, 
                      TUIFontSize Size, 
                      TUIFontStyle Style, 
                      IUIFont** ppIUIFont );
  
  /**
   *  Gets the default font of the system.
   *
   *  @param[out] ppIUIFont interface pointer to the font
   */
  virtual int GetDefaultFont( IUIFont** ppIUIFont );
  
  /**
   *  Initialize  font data
   *
   *  @param[in] Size  size of the font
   *  @param[out]  pFontData  font data
   */
  virtual int GetDefaultFontSettings( TUIFontSize Size, TUIFontData* pFontData );
  
  /**
   *  Create an object representing a font having the specified font data
   *
   *  @param[in]  pFontData  font data
   *  @param[out] ppIUIFont  interface pointer to the font
   */
  virtual int CreateDefaultFont( TUIFontData* pFontData, IUIFont** ppIUIFont );
  
  /**
   *  Create an object representing a font having the specified font data belonging to supplied font family
   *
   *  @param[in]  pIFamilyName  font family name, e.g "Arial", "SansSerif" etc.
   *  @param[in]  pFontData  font data
   *  @param[out] ppIUIFont  interface pointer to the font
   */
  virtual int CreateFontFromFamilyName(void* pIFamilyName, 
                                       TUIFontData* pFontData, 
                                       IUIFont** ppIUIFont );
  
  /**
   *  Create an object representing a font loaded from specified file
   *
   *  @param[in]  pIFullPath  path to a true type font file
   *  @param[in]  pFontData  font data
   *  @param[out] ppIUIFont  interface pointer to the font
   */
  virtual int CreateFontFromFile(void* pIFullPath, 
                                 TUIFontData* pFontData, 
                                 IUIFont** ppIUIFont );
};

class IUIFontManager: public IRoot
{
public:
  /**
   *  Get the font factory interface.
   *
   *  @param[out]   ppIUIFontFactory    the font factory interface
   * @return This method returns an RVoid status code.
   */
  virtual int GetFontFactory( IUIFontFactory** ppIUIFontFactory );
};

#endif
