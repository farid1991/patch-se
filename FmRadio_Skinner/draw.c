#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "data.h"
#include "main.h"

int divide(int nu, int de) 
{
  int temp = 1;
  int quotient = 0;
  
  while (de <= nu) 
  {
    de <<= 1;
    temp <<= 1;
  }
  
  //printf("%d %d\n",de,temp,nu);
  while (temp > 1) 
  {
    de >>= 1;
    temp >>= 1;

    if (nu >= de) 
    {
      nu -= de;
      //printf("%d %d\n",quotient,temp);
      quotient += temp;
    }
  }
  return quotient;
}

void DrawProgressBar(FmRadio_Data* data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor)
{
  //int bar = rect.x1 + (cur_value * (rect.x2-rect.x1) / total_value);
  int bar = rect.x1 + divide(cur_value*(rect.x2-rect.x1), total_value);
  
  if (data->setting.freq_indicator.round)
  {
    DrawRect(rect.x1 + 1, rect.y1, rect.x2 - 1, rect.y2, clEmpty, Ecolor);
    DrawRect(rect.x1, rect.y1 + 1, rect.x2, rect.y2 - 1, clEmpty, Ecolor);
    DrawRect(rect.x1 + 1, rect.y1 + 1, rect.x2 - 1, rect.y2 - 1, Bcolor, Bcolor);
    DrawRect(rect.x1 + 1, rect.y1 + 1, (int)bar - 1, rect.y2 - 1, Ecolor, Ecolor);
  }
  else
  {
    DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor);
    DrawRect(rect.x1, rect.y1, (int)bar, rect.y2, Ecolor, Ecolor);
  }
  
  if (data->setting.freq_indicator.slider)
  {
    IMAGEID image = data->Image[7].ID;

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    int blob_x = bar - (dll_GetImageHeight(image) / 2);
    int blob_y = (rect.y1 - (dll_GetImageWidth(image) / 2)) + ((rect.y2 - rect.y1) / 2);
#else
    int blob_x = bar - (GetImageHeight(image) / 2);
    int blob_y = (rect.y1 - (GetImageWidth(image) / 2)) + ((rect.y2 - rect.y1) / 2);
#endif
    DrawImage(blob_x, blob_y, image);
  }
}

void DrawString_Params(TEXTID text, int font, int align, int x1, int y1, int x2, color_t tcolor, color_t ocolor, int overlay)
{
  if (text && text!=EMPTY_TEXTID)
  {
    int y2 = y1 + (font&0xFF);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    switch(overlay) //??? ??????? (Overlay type)
    {
    case 1: //?????? (Full) v1
      dll_DrawString(text, font, (TUITextAlignment)align, x1 - 1, y1 - 1, x2 - 1, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1 - 1, y1 + 1, x2 - 1, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1 + 1, y1 - 1, x2 + 1, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1 + 1, y1 + 1, x2 + 1, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1, y1, x2, y2, tcolor);
      break;
    case 2: //?????? (Full) v2
      dll_DrawString(text, font, (TUITextAlignment)align, x1 + 1, y1, x2, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1, y1 + 1, x2, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1 - 1, y1, x2, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1, y1 - 1, x2, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1, y1, x2, y2, tcolor);
      break;
    case 3: //???? (Shadow)
      dll_DrawString(text, font, (TUITextAlignment)align, x1 + 1, y1 + 1, x2, y2, ocolor);
      dll_DrawString(text, font, (TUITextAlignment)align, x1, y1, x2, y2, tcolor);
      break;
    default: //??? (No)
      dll_DrawString(text, font, (TUITextAlignment)align, x1, y1, x2, y2, tcolor);
      break;
    }
#else 
    SetFont(font);
    switch(overlay) //(Overlay type)
    {
    case 1: //(Full) v1
      DrawString( text, align, x1 - 1, y1 - 1, x2 - 1, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1 - 1, y1 + 1, x2 - 1, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1 + 1, y1 - 1, x2 + 1, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1 + 1, y1 + 1, x2 + 1, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, clEmpty);
      break;
    case 2: //(Full) v2
      DrawString( text, align, x1+1, y1, x2, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1, y1 + 1, x2, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1-1, y1, x2, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1, y1-1, x2, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, clEmpty);
      break;
    case 3: //(Shadow)
      DrawString( text, align, x1 + 1, y1 + 1, x2, y2, 0, 0, ocolor, clEmpty);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, clEmpty);
      break;
    default: //(No)
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, clEmpty);
      break;
    }
#endif
  }
}
