#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\Function.h"

#include "data.h"
#include "draw.h"
#include "main.h"

void draw_image_ex(GC *gc, int x, int y, int w, int h, IMAGEID image_id)
{
  if (image_id != NOIMAGE)
  {
    GC_PutChar(gc, x, y, w, h, image_id);
  }
}

void draw_image(GC *gc, int x, int y, IMAGEID image_id)
{
  if (image_id != NOIMAGE)
  {
    GC_PutChar(gc, x, y, 0, 0, image_id);
  }
}

void draw_image_on_canvas(GC *disp_gc, int x_dest, int y_dest, IMAGEID image_id)
{
  if (image_id == NOIMAGE)
    return;

  int img_width = GetImageWidth(image_id);
  int img_height = GetImageHeight(image_id);

  GVI_GC gvi = NULL;
  GC *img_gc = GC_CreateMemoryGC(img_width, img_height, 16, 0, NULL, 0);
  CANVAS_Get_GviGC(img_gc->pcanvas, &gvi);

  GVI_BRUSH backbrush = GVI_CreateSolidBrush(clBlack);
  GVI_FillRectangle(gvi, 0, 0, img_width, img_height, backbrush);
  GVI_Delete_GVI_Object(&backbrush);

  GC_PutChar(img_gc, 0, 0, img_width, img_height, image_id);

  GVI_GC disp_gvi = NULL;
  CANVAS_Get_GviGC(disp_gc->pcanvas, &disp_gvi);
  GVI_TransformBlt(disp_gvi, x_dest, y_dest, gvi, 0, 0, img_height, img_height, 0, 0);

  GC_FreeGC(img_gc);
  GVI_DeleteMemoryGC(gvi);
}

void DrawProgressBar(GC *gc, IMAGEID blob_id, int start, int end,
                     int x1, int y1, int x2, int y2,
                     uint32_t bg_color, uint32_t bar_color, BOOL indicator)
{
  int w = x2 - x1;
  int h = y2 - y1;
  int nx2 = x1 + (start * w / end);

  DrawRect(x1, y1, x2, y2, bg_color, bg_color);
  DrawRect(x1, y1, nx2, y2, bar_color, bar_color);

  if (indicator)
  {
    int blob_w = GetImageWidth(blob_id) / 2;
    int blob_h = GetImageHeight(blob_id) / 2;
    int blob_x = nx2 - blob_w;
    int blob_y = (y1 - blob_h) + (h / 2);
    draw_image(gc, blob_x, blob_y, blob_id);
  }
}

void DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, uint32_t text_color)
{
  if (text == EMPTY_TEXTID)
    return;

  SetFont(font);
  DrawString(text, align, x_pos, y_pos, x_pos + width, y_pos + height, 0, 1, text_color, text_color);
}
