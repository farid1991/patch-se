#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

extern "C"
{
  int pg_MusicApplication_PreviousAction(void *Data, BOOK *book);
  int pg_MusicApplication_CancelAction(void *Data, BOOK *book);
  int pg_MusicApplication_ExitAction(void *Data, BOOK *book);

  void MusicApp_PrevAction(BOOK *book, GUI *gui);
  void MusicApp_CancelAction(BOOK *book, GUI *gui);
};

#endif
