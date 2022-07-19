#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\include\book\DB3350\MusicApplication_Book.h"
#endif

extern "C"
{
  int Music_Gui_NowPlaying_OnCreate(DISP_OBJ *);
  void Music_Gui_NowPlaying_OnRedraw(DISP_OBJ *, int a, int b, int c);
  void Music_Gui_NowPlaying_OnClose(DISP_OBJ *);
  void Music_Gui_NowPlaying_OnMethod0A(DISP_OBJ *);

  void FeedbackTicker_OnRedraw(DISP_OBJ *, int a, int b, int c);

  int pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(void *Data, BOOK *book);
  int pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT(void *Data, BOOK *book);
  int pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT(void *Data, BOOK *book);
  int pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT(void *Data, BOOK *book);
  int pg_MusicApplication_UI_MEDIAPLAYER_EXIT_EVENT(void *Data, BOOK *book);

  void LoadLandscapeData();
  void LoadPortraitData();

  int pg_MusicApplication_PreviousEvent(void *Data, BOOK *book);
  int pg_MusicApplication_CancelEvent(void *Data, BOOK *book);
  int pg_MusicApplication_ExitEvent(void *Data, BOOK *book);

  void MusicApplication_PrevAction(BOOK *book, GUI *gui);
  void MusicApplication_CancelAction(BOOK *book, GUI *gui);
  void MusicApplication_Keyboard(BOOK *book, int key, int repeat, int mode, void *unk);
  void MusicApplication_Minimize(BOOK *book, GUI *gui);

#ifdef DB3150v1
  IMAGEID MetaData_GetCover(wchar_t *fullpath);
#endif

  wchar_t *getFileName(wchar_t *fullpath, void *filename);
  wchar_t *getFilePath(wchar_t *fullpath, void *filepath);
};

#endif
