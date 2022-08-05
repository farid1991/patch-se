#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\SetBook.h"

#include "Lib.h"
#include "main.h"

TEXTID GetTitleText()
{
  wchar_t buff[32];
  snwprintf(buff, MAXELEMS(buff), L"Free HEAP: %dKB", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

void ShutdownMenu_onClose(BOOK *book, GUI *gui)
{
  SetBook *setbook = (SetBook *)book;
  FreeBook(setbook);
}

void ShutdownMenu_onSelect(BOOK *book, GUI *gui)
{
  SetBook *setbook = (SetBook *)book;
  int item = KnobOption_GetSelectedItem(setbook->gui);

  switch (item)
  {
  case SHUTDOWN_ITEM:
    REQUEST_SYSTEM_SHUTDOWN();
    break;
  case RESTART_ITEM:
    REQUEST_SYSTEM_RESTART();
    break;
  case FLIGHTMODE_ITEM:
    if (FlightMode_GetState())
      FlightMode_SetState(OFF);
    else
      FlightMode_SetState(ON);
    break;
  }

  FreeBook(setbook);
}

extern "C" void CreateShutdownMenu()
{
  SetBook *setbook = (SetBook *)DynamicMenu_CreateSetBook();

  setbook->gui = Create_KnobOption(setbook, UIDisplay_Main);
  KnobOption_SetItemCount(setbook->gui, LAST_ITEM);
  KnobOption_SetCursor(setbook->gui, SHUTDOWN_ITEM);
  KnobOption_SetTitleText(setbook->gui, GetTitleText());

  KnobOption_SetItems(setbook->gui, ITEM1_TEXT, SHUTDOWN_ITEM);
  KnobOption_SetItems(setbook->gui, ITEM2_TEXT, RESTART_ITEM);
  KnobOption_SetItems(setbook->gui, ITEM3_TEXT, FLIGHTMODE_ITEM);

  GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_SELECT1, ShutdownMenu_onSelect);
  GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_BACK, ShutdownMenu_onClose);
  GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_LONG_BACK, ShutdownMenu_onClose);
  GUIObject_Show(setbook->gui);
}
