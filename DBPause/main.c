/*
;Добавить паузу при воспроизведение аудио через Диспетчер файлов
;(c) E1kolyan
*/

#include "..\\include\Types.h"

#include "Lib.h"
#include "IMMEPlayer.h"

extern "C"
void ActionPause(BOOK* book, GUI* gui)
{
  SUB_EXECUTE* sub_execute = (SUB_EXECUTE*)BrowserItem_Get_SUB_EXECUTE(book);
  TMMEState state;

  IMMEPlayer *pIMMEPlayer = (IMMEPlayer*)sub_execute->pIMMEPlayer;
  pIMMEPlayer->GetState(&state);
  if (state == TMMEState_Playing)
  {
    pIMMEPlayer->Pause();
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, TRUE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, FALSE);
  }
  else
  {
    pIMMEPlayer->Play(NULL, FALSE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, FALSE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, TRUE);
  }
}
