#ifndef _Visualizer_h_
#define _Visualizer_h_

typedef struct VISUALIZER
{
  int16_t x;
  int16_t y;
  int16_t dx;
  int16_t dy;
  uint16_t icon_size;
  int16_t gravity;
} VISUALIZER;

void visualizer_image_register();
void visualizer_init();
void visualizer_update(int max_x, int max_y);
void visualizer_draw_sine_wave(GC *disp_ctx, int x_dest, int y_dest, int w_src, int h_src);
void visualizer_draw_bouncing_walkman(GC *disp_ctx, int x_dest, int y_dest, int w_dest, int h_dest);

#endif
