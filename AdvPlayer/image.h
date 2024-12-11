#ifndef _Image_h_
#define _Image_h_

enum MP_NOWPLAYING_IMAGE
{
  BACKGROUND_ICN,
  MP_NOCOVER_ICN,
  MP_REFLECT_ICN,
  MP_OVERLAY_ICN,
  MP_ARTIST_ICN,
  MP_TITLE_ICN,
  MP_ALBUM_ICN,
  MP_PLAY_ICN,
  MP_PAUSE_ICN,
  MP_NEXT_ICN,
  MP_PREV_ICN,
  MP_FF_ICN,
  MP_RW_ICN,
  MP_MODE_RANDOM_ICN,
  MP_MODE_REPEAT_ICN,
  MP_EQ_BASS_ICN,
  MP_EQ_MEGABASS_ICN,
  MP_EQ_MANUAL_ICN,
  MP_EQ_NORMAL_ICN,
  MP_EQ_TREBLEBOOST_ICN,
  MP_EQ_VOICE_ICN,
  MP_PB_INDICATOR_ICN,
  WALKMAN_ICN,
  MP_LAST_IMG
};

typedef struct
{
  IMAGEID id;
  uint16_t handle;
  bool exist;
} IMAGE_DESC;

void image_register(IMAGE_DESC *img, wchar_t *path, wchar_t *fname);
void image_unregister(IMAGE_DESC *img);

#endif
