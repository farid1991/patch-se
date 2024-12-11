#ifndef _Main_h_
#define _Main_h_

#ifdef DEBUG
#define DBG(...) debug_printf(__VA_ARGS__);
#else
#define DBG(...)
#endif

#define FREE_GUI(gui) \
  if (gui)            \
    GUIObject_Destroy(gui);

extern "C"
{
  bool MediaPlayer_SoftKeys_Validate(GUI* gui);
  int MediaPlayer_Audio_OnCreate(DISP_OBJ *disp_obj);
  void MediaPlayer_Audio_OnClose(DISP_OBJ *disp_obj);
  void MediaPlayer_Audio_OnRefresh(DISP_OBJ *disp_obj);
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

  int pg_MM_Browser_Toplevel_Bk_Cancel(void *data, BOOK *book);
  int pg_MM_Browser_Toplevel_Bk_Start(void *data, BOOK *book);
  int pg_MM_Browser_Toplevel_Bk_Destroy(void *data, BOOK *book);
  int pg_MM_Browser_Toplevel_Bk_AlbumsPage_ExitEvent(void *data, BOOK *book);
#if defined(DB2010)
  int Call_MM_BrowserAlbumsMain(int book_id, wchar_t *wstr, void **pShell);
#elif defined(DB2020)
  int Call_MM_BrowserAlbumsMain(int book_id, wchar_t *wstr, int one, void **pShell);
#endif
  char MediaPlayer_State_Get(void *state);

  void GUIObject_SetAnimation(GUI *, int type);
};

#endif
