#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "data.h"
//#include "main.h"

void DrawProgressBar(DBP_DATA* data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor)
{
  int bar = rect.x1 + (cur_value * (rect.x2-rect.x1) / total_value);

  if (data->setting.time.round || data->setting.volume.round)
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
  
  if (data->setting.time.slider || data->setting.volume.slider)
  {
    IMAGEID image = data->Image[8].ID;
    int blob_x = bar - (GetImageHeight(image) / 2);
    int blob_y = (rect.y1 - (GetImageWidth(image) / 2)) + ((rect.y2 - rect.y1) / 2);
    GC_DrawImage(blob_x, blob_y, image);
  }
}

void DrawString_Params(TEXTID text, int font, int align, int x1, int y1, int x2, color_t tcolor, color_t ocolor, int overlay)
{
  if (text && text!=EMPTY_TEXTID)
  {
    int y2 = y1 + (font&0xFF);
    switch(overlay) //(Overlay type)
    {
    case 1: //(Full) v1
      SetFont(font);
      DrawString( text, align, x1 - 1, y1 - 1, x2 - 1, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1 - 1, y1 + 1, x2 - 1, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1 + 1, y1 - 1, x2 + 1, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1 + 1, y1 + 1, x2 + 1, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, 0);
      break;
    case 2: //(Full) v2
      SetFont(font);
      DrawString( text, align, x1 + 1, y1, x2, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1, y1 + 1, x2, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1 - 1, y1, x2, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1, y1 - 1, x2, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, 0);
      break;
    case 3: //(Shadow)
      SetFont(font);
      DrawString( text, align, x1 + 1, y1 + 1, x2, y2, 0, 0, ocolor, 0);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, 0);
      break;
    default: //(No)
      SetFont(font);
      DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, 0);
      break;
    }
  }
}
