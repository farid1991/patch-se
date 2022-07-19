#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"

void DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, unsigned int text_color)
{
  if (text != EMPTY_TEXTID)
  {
    SetFont(font);
    DrawString(text, align, x_pos, y_pos, x_pos + width, y_pos + height, 0, 1, text_color, text_color);
  }
}

void DrawImage(int x, int y, IMAGEID imgid)
{
  if (imgid != NOIMAGE)
  {
    GC_DrawImage(x, y, imgid);
  }
}

void DrawImageEx(int x, int y, int w, int h, IMAGEID imgid)
{
  if (imgid != NOIMAGE)
  {
    GC_PutChar(get_DisplayGC(), x, y, w, h, imgid);
  }
}

void DrawProgressBar(IMAGEID blob_id, int value, int max_value, int x1, int y1, int x2, int y2, int Bcolor, int Ecolor, bool enable_indicator)
{
  int width = x2 - x1;
  int nx2 = x1 + (value * width / max_value);
  DrawRect(x1, y1, x2, y2, Bcolor, Bcolor);
  DrawRect(x1, y1, nx2, y2, Ecolor, Ecolor);

  if (enable_indicator)
  {
    int blob_w = GetImageWidth(blob_id) >> 1;
    int blob_h = GetImageHeight(blob_id) >> 1;
    int blob_x = nx2 - blob_w;
    int blob_y = (y1 - blob_h) + ((y2 - y1) >> 1);
    DrawImage(blob_x, blob_y, blob_id);
  }
}
