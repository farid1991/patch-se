#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"

/*
;Отображение количества контактов и номеров во второй строке заголовка
;(c) E1kolyan
*/

#define MEMORY 2

extern "C" void TitleText(int mem, GUI *gui)
{
  IMAGEID image;
  TEXTID title;
  wchar_t buf[64];

  if (mem != MEMORY)
  {
    image = IMAGEID_SIM;
    title = TEXTID_SIM;
    snwprintf(buf, MAXELEMS(buf), L"Contacts: %d", AB_GETNBROFITEMS(4, 0));
  }
  else
  {
    image = IMAGEID_PHONE;
    title = TEXTID_PHONE;
    snwprintf(buf, MAXELEMS(buf), L"Contacts: %d(%d)", AB_GETNBROFITEMS(0, 0), AB_GETNBROFITEMS(3, 0));
  }

  GUIObject_SetTitleIcon(gui, image);
  GUIObject_SetTitleType(gui, UI_TitleMode_Large);
  GUIObject_SetTitleText(gui, title);
  GUIObject_SetSecondRowTitleText(gui, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}
