#include "..\\include\Types.h"
#include "..\\include\Function.h"

/*
;Добавить паузу при воспроизведение аудио через Диспетчер файлов
;(c) E1kolyan
*/

#define ACTION_PAUSE 0x76
#define ACTION_PLAY 0xFF

typedef struct SUB_EXECUTE1
{
  char dummy1[0x14];
  GUI* gui;
  GUI_FEEDBACK* gui_fb;
  char dummy2[0x2D4];
  IMMEPlayer* pIMMEPlayer;
}SUB_EXECUTE1;

extern "C"
void ActionPause(BOOK* book, GUI* gui)
{
  SUB_EXECUTE* sub_execute = (SUB_EXECUTE*)BrowserItem_Get_SUB_EXECUTE(book);
  TMMEState state;
  sub_execute->pIMMEPlayer->GetState(&state);
  if (state == TMMEState_Playing)
  {
    sub_execute->pIMMEPlayer->Pause();
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, TRUE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, FALSE);
  }
  else
  {
    sub_execute->pIMMEPlayer->Play(NULL, FALSE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, FALSE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, TRUE);
  }
}
