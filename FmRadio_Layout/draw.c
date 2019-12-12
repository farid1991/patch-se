/*
;Fm Radio Layout Editor
;- Ability to hide/show all items.
;- Ability to change coordinates of each item in realtime.
;- Ability to choose Text color, font, etc.
;- Ability to use color or Theme Image on the background.
;v. 1.2
;(c) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "data.h"
#include "main.h"

void DrawProgressBar(FmRadio_Data* data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor)
{
  int bar = rect.x1 + (cur_value * (rect.x2-rect.x1) / total_value);
  
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
    IMAGEID image = data->Image[FREQUENCY_INDICATOR_ICN].ID;

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    int blob_x = bar - (dll_GetImageHeight(image) >> 1);
    int blob_y = (rect.y1 - (dll_GetImageWidth(image) >> 1)) + ((rect.y2 - rect.y1) >> 1);
#else
    int blob_x = bar - (GetImageHeight(image) >> 1);
    int blob_y = (rect.y1 - (GetImageWidth(image) >> 1)) + ((rect.y2 - rect.y1) >> 1);
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
    switch(overlay) // (Overlay type)
    {
    case 1: // (Full) v1
      dll_DrawString( font, text, align, x1 - 1, y1 - 1, x2 - 1, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1 - 1, y1 + 1, x2 - 1, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1 + 1, y1 - 1, x2 + 1, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1 + 1, y1 + 1, x2 + 1, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1, y1, x2, y2, tcolor,NULL, NULL);
      break;
    case 2: // (Full) v2
      dll_DrawString( font, text, align, x1 + 1, y1, x2, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1, y1 + 1, x2, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1 - 1, y1, x2, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1, y1 - 1, x2, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1, y1, x2, y2, tcolor,NULL, NULL);
      break;
    case 3: // (Shadow)
      dll_DrawString( font, text, align, x1 + 1, y1 + 1, x2, y2, ocolor,NULL, NULL);
      dll_DrawString( font, text, align, x1, y1, x2, y2, tcolor,NULL, NULL);
      break;
    default: // (No)
      dll_DrawString( font, text, align, x1, y1, x2, y2, tcolor,NULL, NULL);
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
