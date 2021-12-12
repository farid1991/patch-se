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
  
  void MusicApplication_PrevAction(BOOK *book, GUI *gui);
  void MusicApplication_CancelAction(BOOK *book, GUI *gui);
  void MusicApplication_ExecuteSubroutine(BOOK *book, int action, wchar_t *fullpath);
};

#endif
