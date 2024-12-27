#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "data.h"
#include "main.h"

void DrawImage(int x, int y, IMAGEID image_id)
{
  if (image_id != NOIMAGE)
  {
    GC *gc = get_DisplayGC();
#if defined(DB3200) || defined(DB3210)
    dll_GC_PutChar(gc, x, y, 0, 0, image_id);
#else
    GC_PutChar(gc, x, y, 0, 0, image_id);
#endif
  }
}

void DrawProgressBar(FmRadio_Data *data, int cur_value, int total_value, RECT rect, uint32_t b_color, uint32_t e_color)
{
  int bar = rect.x1 + (cur_value * (rect.x2 - rect.x1) / total_value);

  if (data->setting.freq_indicator.round)
  {
    DrawRect(rect.x1 + 1, rect.y1, rect.x2 - 1, rect.y2, clEmpty, e_color);
    DrawRect(rect.x1, rect.y1 + 1, rect.x2, rect.y2 - 1, clEmpty, e_color);
    DrawRect(rect.x1 + 1, rect.y1 + 1, rect.x2 - 1, rect.y2 - 1, b_color, b_color);
    DrawRect(rect.x1 + 1, rect.y1 + 1, bar - 1, rect.y2 - 1, e_color, e_color);
  }
  else
  {
    DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, b_color, b_color);
    DrawRect(rect.x1, rect.y1, bar, rect.y2, e_color, e_color);
  }

  if (data->setting.freq_indicator.slider)
  {
    IMAGEID image = data->Image[FREQUENCY_INDICATOR_ICN].ID;

#if defined(DB3200) || defined(DB3210)
    int blob_x = bar - (dll_GetImageHeight(image) >> 1);
    int blob_y = (rect.y1 - (dll_GetImageWidth(image) >> 1)) + ((rect.y2 - rect.y1) >> 1);
#else
    int blob_x = bar - (GetImageHeight(image) >> 1);
    int blob_y = (rect.y1 - (GetImageWidth(image) >> 1)) + ((rect.y2 - rect.y1) >> 1);
#endif
    DrawImage(blob_x, blob_y, image);
  }
}

void DrawString_Params(TEXTID text_id, int font, int align, int x1, int y1, int x2, uint32_t t_color, uint32_t h_color, uint8_t overlay)
{
  if (text_id == EMPTY_TEXTID)
    return;
  int y2 = y1 + (font & 0xFF);
#if defined(DB3200) || defined(DB3210)
  switch (overlay) // (Overlay type)
  {
  case 1: // (Full) v1
    dll_DrawString(font, text_id, align, x1 - 1, y1 - 1, x2 - 1, y2, h_color);
    dll_DrawString(font, text_id, align, x1 - 1, y1 + 1, x2 - 1, y2, h_color);
    dll_DrawString(font, text_id, align, x1 + 1, y1 - 1, x2 + 1, y2, h_color);
    dll_DrawString(font, text_id, align, x1 + 1, y1 + 1, x2 + 1, y2, h_color);
    dll_DrawString(font, text_id, align, x1, y1, x2, y2, t_color);
    break;
  case 2: // (Full) v2
    dll_DrawString(font, text_id, align, x1 + 1, y1, x2, y2, h_color);
    dll_DrawString(font, text_id, align, x1, y1 + 1, x2, y2, h_color);
    dll_DrawString(font, text_id, align, x1 - 1, y1, x2, y2, h_color);
    dll_DrawString(font, text_id, align, x1, y1 - 1, x2, y2, h_color);
    dll_DrawString(font, text_id, align, x1, y1, x2, y2, t_color);
    break;
  case 3: // (Shadow)
    dll_DrawString(font, text_id, align, x1 + 1, y1 + 1, x2, y2, h_color);
    dll_DrawString(font, text_id, align, x1, y1, x2, y2, t_color);
    break;
  default: // (No)
    dll_DrawString(font, text_id, align, x1, y1, x2, y2, t_color);
    break;
  }
#else
  SetFont(font);
  switch (overlay) //(Overlay type)
  {
  case 1: //(Full) v1
    DrawString(text_id, align, x1 - 1, y1 - 1, x2 - 1, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1 - 1, y1 + 1, x2 - 1, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1 + 1, y1 - 1, x2 + 1, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1 + 1, y1 + 1, x2 + 1, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1, y1, x2, y2, 0, 1, t_color, t_color);
    break;
  case 2: //(Full) v2
    DrawString(text_id, align, x1 + 1, y1, x2, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1, y1 + 1, x2, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1 - 1, y1, x2, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1, y1 - 1, x2, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1, y1, x2, y2, 0, 1, t_color, t_color);
    break;
  case 3: //(Shadow)
    DrawString(text_id, align, x1 + 1, y1 + 1, x2, y2, 0, 1, h_color, h_color);
    DrawString(text_id, align, x1, y1, x2, y2, 0, 1, t_color, t_color);
    break;
  default: //(No)
    DrawString(text_id, align, x1, y1, x2, y2, 0, 1, t_color, t_color);
    break;
  }
#endif
}
