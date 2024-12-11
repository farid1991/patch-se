#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#ifdef ENABLE_VISUALIZER
#include "draw.h"
#include "timer.h"
#include "visualizer.h"

void wait_for_player(uint16_t timer_id, ADVPLAYER_DATA *data)
{
  if (data->is_playing && !data->has_coverart)
  {
    KILL_TIMER(data->wait_timer);
    data->viz_ready = true;
    data->viz_timer = Timer_Set(80, MKTIMERPROC(refresh_viz), data);
  }
  else
  {
    data->viz_ready = false;
    Timer_ReSet(&data->wait_timer, 1000, MKTIMERPROC(wait_for_player), data);
  }
}

void refresh_viz(uint16_t timer_id, ADVPLAYER_DATA *data)
{
  if (data->is_playing && !data->has_coverart)
  {
    data->viz_ready = true;
    visualizer_update(data->skin_data->coverart_w, data->skin_data->coverart_h);

    DispObject_InvalidateRect(data->disp_obj_nowplaying, NULL);

    Timer_ReSet(&data->viz_timer, 80, MKTIMERPROC(refresh_viz), data);
  }
  else
  {
    data->viz_ready = false;
    KILL_TIMER(data->viz_timer);
    data->wait_timer = Timer_Set(1000, MKTIMERPROC(wait_for_player), data);
  }
}
#endif
