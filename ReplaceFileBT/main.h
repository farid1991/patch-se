#ifndef _MAIN_H_
#define _MAIN_H_

#define EMP_NAME "rf_emp"
#define VALUE_NAME "rf_mem"

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

typedef struct _FILE_DATA
{
  bool mode;
  // GUI *gui;
} FILE_DATA;

extern "C"
{
  void DataDownloadBook_onClose(BOOK *book);
};

  //  ----------------------------------------------------

#endif
