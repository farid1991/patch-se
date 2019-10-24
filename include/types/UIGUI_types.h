#ifndef __UIGUI_TYPES_H__
#define __UIGUI_TYPES_H__

typedef enum {
  GuiObjectZOrderAbove = 0, ///< Sets the GUI Z-order to Above
  GuiObjectZOrderBelow, ///< Sets the GUI Z-order to Below
  GuiObjectZOrderTop,   ///< Sets the GUI Z-order to Top
  GuiObjectZOrderBottom, ///< Sets the GUI Z-order to Bottom

  // Obsolete use above enums.
  UIZOrder_Above = 0, 
  UIZOrder_Below,
  UIZOrder_Top,   
  UIZOrder_Bottom 
} GuiObjectZOrder_t;

typedef GuiObjectZOrder_t UIZOrder_t;

/**
 * Overlay Style.
 *
 */
 typedef enum
{
  UI_OverlayStyle_NotDefined = 0,
  UI_OverlayStyle_Default,                      // Use original frame settings
  UI_OverlayStyle_FullScreen,                   // Fullscreen
  UI_OverlayStyle_FullScreenNoStatus,           // Fullscreen with no statusRow
  UI_OverlayStyle_TrueFullScreen,               // True fullscreen without softkeys and statusrow
  UI_OverlayStyle_InternalFrameSmall,           // Fullscreen with small internal frame
  UI_OverlayStyle_InternalFrameLarge,           // Fullscreen with large internal frame
  UI_OverlayStyle_InternalFrameOutput,          // Informationtext style
  UI_OverlayStyle_PopupFrame,                   // Popup with SW rendered frame
  UI_OverlayStyle_PopupNoFrame,                 // Transparent popup window. Default popup style.
  UI_OverlayStyle_FullScreenNoSoftkeys,         // Fullscreen without softkeys but with status row
  UI_OverlayStyle_Last,

  // These are obsolete and should not be used. Use the above enums instead.
  UIOverlayStyle_NotDefined = 0,
  UIOverlayStyle_Default,
  UIOverlayStyle_FullScreen,
  UIOverlayStyle_FullScreenNoStatus,
  UIOverlayStyle_TrueFullScreen,
  UIOverlayStyle_InternalFrameSmall,
  UIOverlayStyle_InternalFrameLarge,
  UIOverlayStyle_InternalFrameOutput,
  UIOverlayStyle_PopupFrame,
  UIOverlayStyle_PopupNoFrame,
  UIOverlayStyle_Last
} UI_OverlayStyle_t;

typedef UI_OverlayStyle_t UIOverlayStyle_t;

/**
 * Alignment.
 *
 */
enum
{
  AlignLeft = 0,
  AlignRight,
  AlignCenter,
  AlignLeftDynamic,
  AlignRightDynamic,
  AlignCurrent,

  // These are obsolete. Use the above enums instead.
  UITextAlignment_Left = 0,
  UITextAlignment_Right,
  UITextAlignment_Center,
  UITextAlignment_LeftDynamic,
  UITextAlignment_RightDynamic,
  UITextAlignment_Current
};

typedef FUint8 TextAlignment;
typedef TextAlignment UITextAlignment_t;

/**
 * Title mode.
 *
 */
typedef enum
{
  UI_TitleMode_Uninitated = 0, // Uninitiated
  UI_TitleMode_None,       // Show no title
  UI_TitleMode_Normal,     // Normal title size
  UI_TitleMode_Small,      // Small title
  UI_TitleMode_Tab,        // Show tabs instead of title.
  UI_TitleMode_Large,      // Large two row title (different fonts for 1:st and 2:nd line)
  UI_TitleMode_Desktop,    // Only for desktop title. Will be removed after hb107.
  UI_TitleMode_Last,

  // These enums are obsolete. Use the above enums instead.
  UITitleMode_Uninitated = 0, // Uninitiated
  UITitleMode_None,       // Show no title
  UITitleMode_Normal,     // Normal title size
  UITitleMode_Small,      // Small title
  UITitleMode_Tab,        // Show tabs instead of title.
  UITitleMode_Large,      // Large two row title (different fonts for 1:st and 2:nd line)
  UITitleMode_Last
} UI_TitleMode_t;

// obsolete
typedef UI_TitleMode_t UITitleMode_t;
typedef UI_TitleMode_t TitleMode_t;

/**
 * Display
 *
 * @param UIDisplay_Main    Main display
 * @param UIDisplay_Second  Second display. Used on clam phones
 * @param UIDisplay_Last    End
 */
enum
{
  UIDisplay_Main = 0,
  UIDisplay_Second,
  UIDisplay_TVOut,
  UIDisplay_Last,
  UI_Display_Main = 0,
  UI_Display_Second,
  UI_Display_TVOut,
  UI_Display_Last
};
typedef FUint8 UIDisplay_t;
typedef UIDisplay_t UI_Display_t;

#endif
