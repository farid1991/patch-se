#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "data.h"
#include "main.h"
#include "draw.h"

void InvalidateDispObj(DISP_OBJ *disp_obj)
{
  if (disp_obj)
    DispObject_InvalidateRect(disp_obj, NULL);
}

void DrawImage(int x, int y, IMAGEID img)
{
  if (img != NOIMAGE)
    GC_PutChar(get_DisplayGC(), x, y, 0, 0, img);
}

void DrawImageEx(int x, int y, int w, int h, IMAGEID img)
{
  if (img != NOIMAGE)
    GC_PutChar(get_DisplayGC(), x, y, w, h, img);
}

void DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, unsigned int text_color)
{
  if (text != EMPTY_TEXTID)
  {
    SetFont(font);
    DrawString(text, align, x_pos, y_pos, x_pos + width, y_pos + height, 0, 1, text_color, text_color);
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
