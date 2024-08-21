#ifndef _MAIN_H_
#define _MAIN_H_

#define VALUE_NAME "brightness"
#define CONFIG_PATH L"/usb/other/ZBin/Config/Brightness"
#define CONFIG_NAME L"Brightness.ini"

#define BRIGHT_MAX 100
#define BRIGHT_MIN 0

typedef struct GUI GUI_BRIGHT;

static const char GuiName[] = "GUI_Bright";

typedef enum
{
  BACKGROUND_ICN,
  LEVEL_NORMAL_ICN,  
  LEVEL_UP_ICN,     
  LEVEL_DOWN_ICN,
  LAST_ICN
} IMAGE_LIST;

typedef struct
{
  IMAGEID id;
  uint16_t handle;
} IMG;

typedef struct
{
  uint32_t Percent_Text_Color;
  uint32_t Percent_Text_Overlay;
  int Percent_Text_x1;
  int Percent_Text_y1;
  int Percent_Text_x2;
  int Percent_Text_y2;
  int Percent_Text_Align;
  int Percent_Text_Font;
  int Percent_Text_Bold;
  int Percent_Text_Italic;

  uint32_t Title_Text_Color;
  uint32_t Title_Text_Overlay;
  int Title_Text_x1;
  int Title_Text_y1;
  int Title_Text_x2;
  int Title_Text_y2;
  int Title_Text_Align;
  int Title_Text_Font;
  int Title_Text_Bold;
  int Title_Text_Italic;

  int Icon_Background_x;
  int Icon_Background_y;
  int Icon_Level_x;
  int Icon_Level_y;
} FILE_DATA;

typedef struct _DISP_OBJ_BRIGHT : DISP_OBJ
{
  uint16_t bright;
  uint16_t cstep;
  TEXTID text_id;
  IMAGEID image_id;
  IMG images[LAST_ICN];
  FILE_DATA *data;
} DISP_OBJ_BRIGHT;

//  ---------------------------------------------------- base

#define TI_GET_HOUR(x) ((uint32_t)x & 0xFF)
#define TI_GET_MIN(x) (((uint32_t)x >> 8) & 0xFF)
#define TI_GET_SEC(x) (((uint32_t)x >> 16) & 0xFF)

//  ----------------------------------------------------

#endif
