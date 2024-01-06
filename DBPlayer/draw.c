#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"

#ifndef DB3150v1
#include "dll.h"
#endif

#include "Lib.h"
#include "data.h"
#include "draw.h"
#include "main.h"

void DrawImageEx(GC *gc, int x, int y, int w, int h, IMAGEID img)
{
  if (img != NOIMAGE)
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_GC_PutChar(gc, x, y, w, h, img);
#else
    GC_PutChar(gc, x, y, w, h, img);
#endif
}

void DrawImage(int x, int y, IMAGEID img)
{
  GC *gc = get_DisplayGC();
  DrawImageEx(gc, x, y, 0, 0, img);
}

void DrawProgressBar(DBP_DATA *data, int cur_value, int total_value, RECT rect, uint32_t Bcolor, uint32_t Ecolor)
{
  int bar = rect.x1 + (cur_value * (rect.x2 - rect.x1) / total_value);

  if (data->setting.time.round || data->setting.volume.round)
  {
    DrawRect(rect.x1 + 1, rect.y1, rect.x2 - 1, rect.y2, clEmpty, Ecolor);
    DrawRect(rect.x1, rect.y1 + 1, rect.x2, rect.y2 - 1, clEmpty, Ecolor);
    DrawRect(rect.x1 + 1, rect.y1 + 1, rect.x2 - 1, rect.y2 - 1, Bcolor, Bcolor);
    DrawRect(rect.x1 + 1, rect.y1 + 1, bar - 1, rect.y2 - 1, Ecolor, Ecolor);
  }
  else
  {
    DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor);
    DrawRect(rect.x1, rect.y1, bar, rect.y2, Ecolor, Ecolor);
  }

  if (data->setting.time.slider || data->setting.volume.slider)
  {
    IMAGEID image = data->Image[IMG_SLIDER].ID;
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

void DrawText(int font, TEXTID text, int align, int x1, int y1, int x2, uint32_t TextColor)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(font, text, align, x1, y1, x2, y1 + (font & 0xFF), TextColor);
#else
    SetFont(font);
    int font_h = GetImageHeight(' ');
    DrawString(text, align, x1, y1, x2, y1 + font_h, 0, 0, TextColor, TextColor);
#endif
  }
}

void DrawTextEx(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, uint32_t TextColor)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(font, text, align, x1, y1, x2, y2, TextColor);
#else
    SetFont(font);
    DrawString(text, align, x1, y1, x2, y2, 0x14, 0x5, TextColor, TextColor);
#endif
  }
}

void DrawTextWithStyle(TEXTID text, int font, int align, int x1, int y1, int x2, uint32_t tcolor, uint32_t ocolor, int overlay)
{
  switch (overlay) //(Overlay type)
  {
  case TEXTOVERLAY_TYPE1: // (Full) v1
    DrawText(font, text, align, x1 - 1, y1 - 1, x2 - 1, ocolor);
    DrawText(font, text, align, x1 - 1, y1 + 1, x2 - 1, ocolor);
    DrawText(font, text, align, x1 + 1, y1 - 1, x2 + 1, ocolor);
    DrawText(font, text, align, x1 + 1, y1 + 1, x2 + 1, ocolor);
    break;
  case TEXTOVERLAY_TYPE2: // (Full) v2
    DrawText(font, text, align, x1 + 1, y1, x2, ocolor);
    DrawText(font, text, align, x1, y1 + 1, x2, ocolor);
    DrawText(font, text, align, x1 - 1, y1, x2, ocolor);
    DrawText(font, text, align, x1, y1 - 1, x2, ocolor);
    break;
  case TEXTOVERLAY_TYPE3: // (Shadow)
    DrawText(font, text, align, x1 + 1, y1 + 1, x2, ocolor);
    break;
  }
  DrawText(font, text, align, x1, y1, x2, tcolor);
}
