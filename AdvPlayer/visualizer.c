#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\Function.h"

#ifdef ENABLE_VISUALIZER
#include "data.h"
#include "draw.h"
#include "visualizer.h"

// data->v_pos = 0;
// data->v_step = 5;
// data->v_angle = (data->timer_count * 2) % 360;
// data->v_pos = (data->v_pos + data->v_step) % 360;

void visualizer_image_register()
{
  ADVPLAYER_DATA *data = env_data_get();

  data->viz_image.handle = NOIMAGE;
  data->viz_image.id = NOIMAGE;
  data->viz_image.exist = FALSE;

  if (FSX_IsFileExists(SKIN_CFG_PATH, L"viz.png"))
  {
    image_register(&data->viz_image, SKIN_CFG_PATH, L"viz.png");
  }
}

void visualizer_init()
{
  ADVPLAYER_DATA *data = env_data_get();
  data->viz.dx = 2;
  data->viz.dy = 2;
  data->viz.gravity = 1;
}

void visualizer_update(int max_x, int max_y)
{
  ADVPLAYER_DATA *data = env_data_get();

  int icon_w, icon_h;
  icon_w = icon_h = max_x >> 1;
  data->viz.icon_size = icon_w;

  data->viz.x += data->viz.dx;
  data->viz.y += data->viz.dy;
  data->viz.dy += data->viz.gravity;

  if (data->viz.x <= 0)
  {
    data->viz.dx = -data->viz.dx;
    data->viz.x = 0;
  }
  else if ((data->viz.x + icon_w) >= max_x)
  {
    data->viz.dx = -data->viz.dx;
    data->viz.x = max_x - icon_w;
  }

  if ((data->viz.y + icon_h) >= max_y)
  {
    data->viz.dy = -(data->viz.dy * 0.9);
    data->viz.y = max_y - icon_h;
  }

  if (data->viz.y <= 0)
  {
    data->viz.dy = -data->viz.dy;
    data->viz.y = 0;
  }
}

void visualizer_draw_bouncing_walkman(GC *disp_ctx, int x_dest, int y_dest, int w_dest, int h_dest)
{
  ADVPLAYER_DATA *data = env_data_get();

  if (data->viz_gvi == NULL)
  {
    data->viz_canvas = GC_CreateMemoryGC(w_dest, h_dest, 16, 0, 0, 0);
    CANVAS_Get_GviGC(data->viz_canvas->pcanvas, &data->viz_gvi);

    GVI_BRUSH backbrush = GVI_CreateSolidBrush(clEmpty);
    GVI_FillRectangle(data->viz_gvi, 0, 0, w_dest, h_dest, backbrush);
    GVI_Delete_GVI_Object(&backbrush);
  }

  GVI_FillSolidRoundRect(data->viz_gvi, 0, 0, w_dest, h_dest, 4, 4, clAlpha);

  GC_PutChar(data->viz_canvas,
             data->viz.x, data->viz.y,
             data->viz.icon_size, data->viz.icon_size,
             data->viz_image.id);

  CANVAS_Get_GviGC(disp_ctx->pcanvas, &data->disp_gvi);
  GVI_TransformBlt(data->disp_gvi, x_dest, y_dest, data->viz_gvi, 0, 0, w_dest, h_dest, 0, 0);
}

// void visualizer_draw_sine_wave(GC *disp_ctx, int x_dest, int y_dest, int w_dest, int h_dest)
// {
//   ADVPLAYER_DATA *data = env_data_get();

//   GVI_GC viz_gvi;
//   GC *viz_canvas = GC_CreateMemoryGC(w_dest, h_dest, 16, 0, 0, 0);
//   CANVAS_Get_GviGC(viz_canvas->pcanvas, &viz_gvi);

//   GVI_BRUSH backbrush = GVI_CreateSolidBrush(clBlack);
//   GVI_FillRectangle(viz_gvi, 0, 0, w_dest, h_dest, backbrush);

//   int half_h = h_dest >> 1;
//   for (int wave = 0; wave < 3; wave++)
//   {
//     int amplitude = 20 + wave * 8;
//     int rmax = (sin((data->v_angle + wave) * 3) * amplitude / SINE_RESOLUTION) + 20;
//     int phase_shift = wave * half_h;

//     POINT point[MAX_POINT];
//     for (int i = 0; i < MAX_POINT; i++)
//     {
//       point[i].x = i * w_dest / MAX_POINT - 1;
//       point[i].y = ((rmax * sin(i * 20 + (data->v_pos + phase_shift))) >> 8) + half_h;
//     }

//     GVI_PEN pen = GVI_CreatePen(3, COLOR_RGB[wave]);
//     GVI_DrawPolyLine(viz_gvi, point, MAX_POINT, pen, FALSE);
//     GVI_Delete_GVI_Object(&pen);
//   }

//   GVI_Delete_GVI_Object(&backbrush);

//   CANVAS_Get_GviGC(disp_ctx->pcanvas, &data->disp_gvi);
//   GVI_TransformBlt(data->disp_gvi, x_dest, y_dest, viz_gvi, 0, 0, w_dest, h_dest, 0, 0);

//   GC_FreeGC(viz_canvas);
//   GVI_DeleteMemoryGC(viz_gvi);
// }

#endif
