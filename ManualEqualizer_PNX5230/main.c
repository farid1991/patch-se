#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\book\AudioPlayerBook.h"

// #include "Lib.h"
// #include "main.h"

extern "C" void New_EQ_SetActive_SoftKeys(GUI *gui)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)GUIObject_GetBook(gui);
  int state = audioBook->EQ_State;
  if (state == 6)
  {
    GUIObject_SoftKeys_SetVisible(gui, ACTION_DONE, TRUE);
    GUIObject_SoftKeys_SetVisible(gui, ACTION_PRESET, TRUE);
    GUIObject_SoftKeys_SetVisible(gui, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetVisible(gui, ACTION_MANUAL, FALSE);
  }
  else
  {
    GUIObject_SoftKeys_SetVisible(gui, ACTION_DONE, FALSE);
    GUIObject_SoftKeys_SetVisible(gui, ACTION_PRESET, FALSE);
    GUIObject_SoftKeys_SetVisible(gui, ACTION_SELECT1, TRUE);
    if (state == 2)
      GUIObject_SoftKeys_SetVisible(gui, ACTION_MANUAL, FALSE);
    else
      GUIObject_SoftKeys_SetVisible(gui, ACTION_MANUAL, TRUE);
  }
}
