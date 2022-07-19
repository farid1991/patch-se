#ifndef _Main_H_
#define _Main_H_

extern "C"
{
  int MediaPlayer_Audio_OnCreate(DISP_OBJ *disp_obj);
  void MediaPlayer_Audio_OnClose(DISP_OBJ *disp_obj);
  int MediaPlayer_NowPlaying_OnCreate(DISP_OBJ *disp_obj);
  void MediaPlayer_NowPlaying_OnClose(DISP_OBJ *disp_obj);
  void MediaPlayer_NowPlaying_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c);
  void MediaPlayer_Audio_ActionBack(BOOK *book, GUI *gui);
  void MediaPlayer_Audio_ActionLongBack(BOOK *book, GUI *gui);
 
  int pg_MEDIAPLAYER_AUDIO_PLAYING_TIME(void *data, BOOK *book);
  int pg_MEDIAPLAYER_NEW_TRACK_EVENT(void *data, BOOK *book);
  int pg_MEDIAPLAYER_CREATED_EVENT(void *data, BOOK *book);
};

#define FREE_GUI(gui)       \
  if (gui)                  \
  {                         \
    GUIObject_Destroy(gui); \
    gui = NULL;             \
  };

#define IMAGE_FREE(img)             \
  if (img != NOIMAGE)               \
  {                                 \
    ImageID_Free(img);              \
  }

#define TEXT_FREE(text)               \
  if (text)           \
  {                                   \
    TextID_Destroy(text);             \
  }

#define InvalidateNowPlaying(disp) DispObject_InvalidateRect(disp,NULL)

#define SKIN_CFG_NAME L"skin.cfg"
#define SKIN_CFG_PATH L"/usb/other/WALKMAN"

#define SKIN_PATH L"/usb/other/WALKMAN/skins"
#define SKIN_NAME L"walkman.ini"

#define DEFAULT_SKIN_PATH L"/usb/other/WALKMAN/skins/WALKMAN"
#define TOPLEVEL_PATH L"/usb/other/WALKMAN/TopLevel"

void *malloc(int size);
void mfree(void *mem);

int UnLoadSkinImage(ADVPLAYER_DATA *data);
void LoadSkinImage(ADVPLAYER_DATA *data, wchar_t *skinpath);

#endif
