#ifndef _Timer_h_
#define _Timer_h_

#include "data.h"

#define KILL_TIMER(timer) \
  if (timer)              \
  {                       \
    Timer_Kill(&timer);   \
    timer = 0;            \
  }

void wait_for_player(uint16_t timer_id, ADVPLAYER_DATA *data);
void refresh_viz(uint16_t timer_id, ADVPLAYER_DATA *data);

#endif
