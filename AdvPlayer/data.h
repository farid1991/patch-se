#ifndef _Data_h_
#define _Data_h_

#include "..\\include\book\AudioPlayerBook.h"

#include "image.h"
#include "skin_data.h"
#include "track_desc.h"

#ifdef ENABLE_VISUALIZER
#include "visualizer.h"
#endif

#define EMP_NAME "MP_EMP"

typedef struct
{
  DISP_OBJ *disp_obj_audio;
  DISP_OBJ_NOWPLAYING *disp_obj_nowplaying;
  SKIN_DATA *skin_data;
  LIST *skin_list;

  uint16_t disp_w;
  uint16_t disp_h;

  bool is_playing;

  uint8_t player_state;

  uint32_t sample_rate;

  TRACK_DESC *current_track;

  IMAGE_DESC skin_images[MP_LAST_IMG];
  IMAGE_DESC cover_image;
  bool has_coverart;

  bool skin_loaded;
  bool image_loaded;

  GVI_GC disp_gvi;
  GC *cv_canvas;
  GVI_GC cv_gvi;

#ifdef ENABLE_VISUALIZER
  uint16_t viz_timer;
  uint16_t wait_timer;
  bool viz_ready;
  VISUALIZER viz;
  IMAGE_DESC viz_image;
  GC *viz_canvas;
  GVI_GC viz_gvi;
#endif

} ADVPLAYER_DATA;

ADVPLAYER_DATA *env_data_get();
void env_data_destroy(ADVPLAYER_DATA *data);

#endif
