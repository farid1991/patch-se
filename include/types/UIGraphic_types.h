#ifndef __UIGRAPHIC_TYPES_H__
#define __UIGRAPHIC_TYPES_H__

/**
 * Background images.
 *
 */
typedef enum
{
  UIBackgroundManagerImage_None,
  UIBackgroundManagerImage_Current,
  UIBackgroundManagerImage_Standby,
  UIBackgroundManagerImage_Desktop,
  UIBackgroundManagerImage_General,
  UIBackgroundManagerImage_UserStandby,
  UIBackgroundManagerImage_Overlay,
  UIBackgroundManagerImage_MoreList,
  UIBackgroundManagerImage_HomeScreen,
  UIBackgroundManagerImage_Title,
  UIBackgroundManagerImage_TitleSmall,
  UIBackgroundManagerImage_TitleTab,
  UIBackgroundManagerImage_TitleOverlay,
  UIBackgroundManagerImage_TitleTabHomeScreen,
  UIBackgroundManagerImage_Highlight,
  UIBackgroundManagerImage_HighlightLarge,
  UIBackgroundManagerImage_HighlightDesktop,
  UIBackgroundManagerImage_HighlightOverlay,
  UIBackgroundManagerImage_HighlightMoreList,
  UIBackgroundManagerImage_HighlightHomeScreen,
  UIBackgroundManagerImage_HighlightLargeHomeScreen,
  UIBackgroundManagerImage_StandbyStatusBar,
  UIBackgroundManagerImage_StandbySoftkeys,
  UIBackgroundManagerImage_TabSelected,
  UIBackgroundManagerImage_TabSelectedHomeScreen,
  UIBackgroundManagerImage_TabUnSelected,
  UIBackgroundManagerImage_TabUnSelectedHomeScreen,
  UIBackgroundManagerImage_SoftkeyLeftPressed,
  UIBackgroundManagerImage_SoftkeyMiddlePressed,
  UIBackgroundManagerImage_SoftkeyRightPressed ,
  UIBackgroundManagerImage_Input,
  UIBackgroundManagerImage_InputSmall,
  UIBackgroundManagerImage_SecondDisplayCurrent,
  UIBackgroundManagerImage_SecondDisplayStandby,
  UIBackgroundManagerImage_UserSecondDisplayStandby,
  UIBackgroundManagerImage_MediaPortrait,
  UIBackgroundManagerImage_MediaLandscape,
  UIBackgroundManagerImage_Last
} UIBackgroundManagerImage_t;

/**
 * Theme colors.
 *
 */
typedef enum
{
  UIThemeColor_BrowserUnderline,
  UIThemeColor_BrowserTableBorder,
  UIThemeColor_CalendarWeekendText,
  UIThemeColor_CalendarWeekendHighlight,
  UIThemeColor_InputScrollBar,
  UIThemeColor_InputText,
  UIThemeColor_InputOverlay,
  UIThemeColor_InputOverlayHighlight,
  UIThemeColor_InputOverlayFrame,
  UIThemeColor_HomeScreen,
  UIThemeColor_HomeScreenNonSel,         
  UIThemeColor_HomeScreenTab,
  UIThemeColor_HomeScreenTabNonSel,
  UIThemeColor_HomeScreenTabSel,
  UIThemeColor_HomeScreenTabText,
  UIThemeColor_HomeScreenHighlight,
  UIThemeColor_HomeScreenHighlightNonSel,
  UIThemeColor_HomeScreenScrollBar,
  UIThemeColor_HomeScreenFrame,          
  UIThemeColor_Morelist,
  UIThemeColor_MorelistNonSel,           
  UIThemeColor_MorelistHighlight,
  UIThemeColor_MorelistHighlightNonSel,  
  UIThemeColor_MorelistScrollBar,
  UIThemeColor_MorelistFrame,            
  UIThemeColor_TopMenu,
  UIThemeColor_Highlight,
  UIThemeColor_HighlightNonSel,          
  UIThemeColor_NonSel,                   
  UIThemeColor_OverlayFrame,             
  UIThemeColor_OverlayHighlight,
  UIThemeColor_OverlayHighlightNonSel,   
  UIThemeColor_OverlayNonSel,            
  UIThemeColor_OverlayScrollBar,
  UIThemeColor_OverlayText,
  UIThemeColor_OverlayTitle,
  UIThemeColor_ScrollBar,
  UIThemeColor_OverlayDim,
  UIThemeColor_SoftkeyNonSel,            
  UIThemeColor_SoftkeyBarLeft,
  UIThemeColor_SoftkeyBarRight,
  UIThemeColor_SoftkeyTextLeftPressed,
  UIThemeColor_SoftkeyTextRightPressed,
  UIThemeColor_SoftkeyTextLeft,          
  UIThemeColor_SoftkeyTextLeftNonSel,    
  UIThemeColor_SoftkeyTextRight,         
  UIThemeColor_SoftkeyTextRightNonSel,   
  UIThemeColor_StandbyOperatorName,
  UIThemeColor_StandbyTime,
  UIThemeColor_Tab,
  UIThemeColor_TabText,
  UIThemeColor_TabNonSel,
  UIThemeColor_TabSel,
  UIThemeColor_Text,
  UIThemeColor_Title,
  UIThemeColor_VolumeStaples,
  UIThemeColor_ProgressBarOutline,
  UIThemeColor_ProgressBar,
  UIThemeColor_CalendarWeekViewMarkings,
  UIThemeColor_TopMenuShadow,            
  UIThemeColor_Notes,                    
  UIThemeColor_OverlayTitleShadow,       
  UIThemeColor_TabTextShadow,            
  UIThemeColor_HomeScreenTabTextShadow,  
  UIThemeColor_TitleShadow,              
  UIThemeColor_Cursor,                   
  UIThemeColor_OverlayCursor,            
  UIThemeColor_OverlayPrompt,            
  UIThemeColor_Prompt,                   
  UIThemeColor_InternalFrame,
  UIThemeColor_InternalFrameText,
  UIThemeColor_InternalFrameNonSel,
  UIThemeColor_InternalFrameHighlight,
  UIThemeColor_MediaBackground,
  UIThemeColor_MediaBackgroundSearch,
  UIThemeColor_MediaIcon,
  UIThemeColor_MediaText,
  UIThemeColor_MediaHighlightIcon,
  UIThemeColor_MediaHighlightText,
  UIThemeColor_MediaLine,
  UIThemeColor_MediaWalkmanHighlight,
  UIThemeColor_MediaWalkmanParticle,
  UIThemeColor_MediaParticle,
  UIThemeColor_Last
} UIThemeColor_t;

/**
 * Statusrow blink mode.
 *
 * @param UIStatusrowBlinkMode_Off  Blink mode turned off
 * @param UIStatusrowBlinkMode_Slow Icon will blink slow
 * @param UIStatusrowBlinkMode_Fast Icon will blink fast
 */
typedef enum
{
  UIStatusrowBlinkMode_Off,
  UIStatusrowBlinkMode_Slow,
  UIStatusrowBlinkMode_Fast
} UIStatusrowBlinkMode_t;

typedef enum
{
  UIGraphicsFontStyle_Plain = 0,
  UIGraphicsFontStyle_Bold = 1,
  UIGraphicsFontStyle_Italic = 2,
  UIGraphicsFontStyle_Underlined = 4,
  UIGraphicsFontStyle_ItalicBold = 3
} UIGraphicsFontStyle_t;

typedef enum
{
  UIGraphicsFontSize_Small = 8,
  UIGraphicsFontSize_Medium = 0,
  UIGraphicsFontSize_Large = 16
} UIGraphicsFontSize_t;

typedef enum
{
  UIGraphicsFontFace_System = 0,
  UIGraphicsFontFace_Monospace = 32,
  UIGraphicsFontFace_Proportional = 64
} UIGraphicsFontFace_t;


/*@}*/

#endif
