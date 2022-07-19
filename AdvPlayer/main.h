#ifndef _Main_h
#define _Main_h

extern "C"
{
  int MediaPlayer_Audio_OnCreate(DISP_OBJ *disp_obj);
  void MediaPlayer_Audio_OnClose(DISP_OBJ *disp_obj);
  int MediaPlayer_NowPlaying_OnCreate(DISP_OBJ *disp_obj);
  void MediaPlayer_NowPlaying_OnClose(DISP_OBJ *disp_obj);
  void MediaPlayer_NowPlaying_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c);
  void MediaPlayer_Audio_Sort(BOOK *book, GUI *gui);
  void MediaPlayer_Audio_ActionBack(BOOK *book, GUI *gui);
  void MediaPlayer_Audio_ActionLongBack(BOOK *book, GUI *gui);
  void MM_BrowserToplevel_Enter(BOOK *book, GUI *gui);
  int pg_MEDIAPLAYER_AUDIO_PLAYING_TIME(void *data, BOOK *book);
  int pg_MEDIAPLAYER_NEW_TRACK_EVENT(void *data, BOOK *book);
  int pg_MEDIAPLAYER_CREATED_EVENT(void *data, BOOK *book);
  int pg_MediaPlayer_Audio_Bk_ExitEvent(void *data, BOOK *book);
  int pg_MediaPlayer_Audio_Bk_PrevEvent(void *data, BOOK *book);
  int pg_MediaPlayer_Audio_Bk_CancelEvent(void *data, BOOK *book);

  int pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Cancel(void *data, BOOK *book);
  int pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Start(void *data, BOOK *book);
  int pg_MM_Browser_Toplevel_Bk_Videos(void *data, BOOK *book);

  int Call_MM_BrowserAlbumsMain(int book_id, void *__zero, void **pIShell);
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
  if (text != EMPTY_TEXTID)           \
  {                                   \
    TextID_Destroy(text);             \
  }


void *malloc(int size);
void mfree(void *mem);

int UnLoadSkinImage(ADVPLAYER_DATA *data);
void LoadSkinImage(ADVPLAYER_DATA *data, wchar_t *skinpath);

#endif
