#ifndef _IUITEXTRENDERINGMANAGER_H_
#define _IUITEXTRENDERINGMANAGER_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\UIRichText_types.h"

const UUID IID_ITextRenderingManager={0xCE,0x91,0x7B,0x62,0xE3,0x3A,0x4D,0xC7,0x85,0x24,0x79,0x1E,0x6F,0x01,0x03,0x09};
const UUID CID_CTextRenderingManager={0xCF,0xDC,0xCD,0x9D,0xAE,0x6D,0x40,0xAE,0xB3,0x97,0x38,0xB0,0x5D,0x2D,0x35,0x9D};

class IUITextRenderingFactory: public IRoot
{
public:
  /**
   *  Get the font resource factory interface.
   *
   *  @param[out]   ppIUIFontResourceManager    the font resource manager interface
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateFontResourceManager(IRoot** ppIUIFontResourceManager);
  
  /**
   *  Get the font style factory interface.
   *
   *  @param[out]   ppIUIFontStyleManager    the font style manager interface
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateFontStyleManager(IRoot** ppIUIFontStyleManager);
  
  /**
   * Creates a rich text object
   *
   *  @param[out] ppIUIRichText the created rich text
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateRichText(IUIRichText** ppIUIRichText);
  
  /**
   * Creates a text container
   *
   *  @param[out] ppIUITextContainer the created text container
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateTextContainer(IRoot** ppIUITextContainer);
  
  /**
   *  Creates a rich text layout object
   *
   *  @param[in]  pIUIRichText               interface pointer to a rich text
   *  @param[in]  pIUIRichTextLayoutControl  interface pointer to a rich text layout control
   *  @param[in]  pIUIRichTextLayoutOptions interface pointer to a rich text layout options
   *  @param[out] ppIUIRichTextLayout        the created rich text layout object
   *
   *  @note pIUIRichTextLayoutControl and pIUIRichTextLayoutOptions could be NULL
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateRichTextLayout(IUIRichText* pIUIRichText, IRoot* pIUIRichTextLayoutControl, IRoot* pIUIRichTextLayoutOptions, IUIRichTextLayout** ppIUIRichTextLayout);
  
  /**
   *  Creates a single line text layout object
   *
   *  @param[in]  pIUIRichTextLayoutControl    interface pointer to a rich text layout control
   *  @param[in]  pIUIRichTextLayoutOptions    interface pointer to a rich text layout options
   *  @param[out] ppIUISingleLineLayout        the created single line layout object
   *
   *  @note pIUIRichTextLayoutControl and pIUIRichTextLayoutOptions could be NULL
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateSingleLineLayout(IRoot* pIUIRichTextLayoutControl, IRoot* pIUIRichTextLayoutOptions, IRoot** ppIUISingleLineLayout);
  
  /**
   * Get the rich text layout control object
   * The control object handles large data that is needed for layout.
   * Thai dictonary, SEMC emoticons and pictograms etc.
   *
   *  @param[out] ppIUIRichTextLayoutControl the created rich text layout control
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateRichTextLayoutControl(IRoot** ppIUIRichTextLayoutControl);
  
  /**
   * Creates a rich text layout options object
   *
   *  @param[out] ppIUIRichTextLayoutOptions the created rich text layout options
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreateRichTextLayoutOptions(IUIRichTextLayoutOptions** ppIUIRichTextLayoutOptions);
  
  /**
   * Creates a polygon object
   *
   *  @param[out] ppIUIPolygon pointer to polygon object
   *
   *  @return This method returns an RVoid status code.
   *
   */
  virtual int CreatePolygon(IRoot** ppIUIPolygon);
  
  /**
   *
   * The IUIBasicTextHandling interface provides a low level text handling function.
   * 
   *
   * @note No layout engine is used. This means that bidirectional language and 
   * advanced script based language will not be displayed correct. 
   *
   *  @param[out]   ppIUIBasicTextHandling    the restricted text handler interface
   *
   *  @return This method returns an RVoid status code.
   *
   *
   */
  virtual int CreateBasicTextHandler(IRoot** ppIUIBasicTextHandling);};

class IUITextRenderingManager: public IRoot
{
public:

  /**
   *  Get the text rendering factory interface.
   *
   *  @param[out]   ppIUITextRenderingFactory    the text rendering factory interface
   *
   *  @return This method returns an RVoid status code.
   */
  virtual int GetTextRenderingFactory(IUITextRenderingFactory** ppIUITextRenderingFactory);
  
  /**
   *  Get the font config file path.
   *
   *  @see <a href="https://javawiki.sonyericsson.net/wiki/UI/WTLE/Font_Configuration#font.xml">
   *           Font configuration
   *  </a> <br>
   *
   *  @param[out]   ppIString    File System path to the font config file
   *
   *  @return This method returns an RVoid status code.
   */
  virtual int GetFontConfigFilePath(IRoot** ppIString);
  
  /**
   *  Get the font engine config file path.
   *
   *  @see <a href="https://javawiki.sonyericsson.net/wiki/UI/WTLE/Font_Configuration#fontengine.xml">
   *           Font engine configuration
   *  </a> <br>
   *
   *  @param[out]   ppIString    File System path to the font engine config file
   *
   *  @return This method returns an RVoid status code.
   */
  virtual int GetFontEngineConfigFilePath(IRoot** ppIString);
};

#endif
