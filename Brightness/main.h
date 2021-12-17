#ifndef _MAIN_H_
#define _MAIN_H_

#define VALUE_NAME "brightness"
#define FILE_PATH L"/usb/other/ZBin/Config/Brightness"
#define FILE_NAME L"Brightness.ini"

#define data_count sizeof(FILE_DATA) / sizeof(int)

typedef struct GUI GUI_BRIGHT;

static const char GuiName[] = "GUI_Bright";

typedef struct
{
  IMAGEID ImageID;
  uint16_t ImageHandle;
} IMG;

#define img_count 4

typedef struct
{
  unsigned int Percent_Text_Color;
  unsigned int Percent_Text_Overlay;
  int Percent_Text_x1;
  int Percent_Text_y1;
  int Percent_Text_x2;
  int Percent_Text_y2;
  int Percent_Text_Align;
  int Percent_Text_Font;
  int Percent_Text_Bold;
  int Percent_Text_Italic;

  unsigned int Title_Text_Color;
  unsigned int Title_Text_Overlay;
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
  int bright;
  uint8_t cstep;
  TEXTID text;
  IMAGEID image;
  IMG Images[img_count];
  FILE_DATA *data;
} DISP_OBJ_BRIGHT;

//  ---------------------------------------------------- base

#define TI_GET_HOUR(x) ((unsigned int)x & 0xFF)
#define TI_GET_MIN(x) (((unsigned int)x >> 8) & 0xFF)
#define TI_GET_SEC(x) (((unsigned int)x >> 16) & 0xFF)

//  ----------------------------------------------------

#endif
