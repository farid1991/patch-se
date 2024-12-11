#ifndef _Draw_h_
#define _Draw_h_

#define FREE_GC(gc) \
  if (gc)           \
    GC_FreeGC(gc);

#define FREE_GVI(gvi) \
  if (gvi)            \
    gvi = 0;

void blend_color(uint32_t *c1, uint32_t c2);
void draw_image(GC *gc, int x, int y, IMAGEID image_id);
void draw_image_ex(GC *gc, int x, int y, int w, int h, IMAGEID image_id);
void DrawText(int font, TEXTID text_id, int align, int x_pos, int y_pos, int width, int height, uint32_t text_color);
void DrawProgressBar(GC *gc, IMAGEID blob_id, int start, int end, int x1, int y1, int x2, int y2, uint32_t bg_color, uint32_t bar_color, BOOL enable_indicator);
void draw_image_on_canvas(GC *disp_ctx, int x_dest, int y_dest, IMAGEID image_id);
void draw_coverart_on_canvas(GC *disp_ctx, int x_dest, int y_dest, int w_dest, int h_dest, IMAGEID image_id);

#endif
