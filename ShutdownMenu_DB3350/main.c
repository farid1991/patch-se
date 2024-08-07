#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\SetBook.h"

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
  switch (KnobOption_GetSelectedItem(setbook->gui))
  {
  case ITEM_1:
    REQUEST_SYSTEM_SHUTDOWN();
    break;
  case ITEM_2:
    REQUEST_SYSTEM_RESTART();
    break;
  case ITEM_3:
    FlightMode_GetState() ? FlightMode_SetState(OFF) : FlightMode_SetState(ON);
    break;
  }
  FreeBook(setbook);
}

extern "C" void CreateShutdownMenu()
{
  SetBook *setbook = (SetBook *)DynamicMenu_CreateSetBook();

  setbook->gui = Create_KnobOption(setbook, UIDisplay_Main);
  KnobOption_SetItemCount(setbook->gui, LAST_ITEM);
  KnobOption_SetCursor(setbook->gui, ITEM_1);
  KnobOption_SetTitleText(setbook->gui, GetTitleText());
  KnobOption_SetItems(setbook->gui, ITEM1_TEXT, ITEM_1);
  KnobOption_SetItems(setbook->gui, ITEM2_TEXT, ITEM_2);
  KnobOption_SetItems(setbook->gui, ITEM3_TEXT, ITEM_3);
  GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_SELECT1, ShutdownMenu_onSelect);
  GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_BACK, ShutdownMenu_onClose);
  GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_LONG_BACK, ShutdownMenu_onClose);
  GUIObject_Show(setbook->gui);
}
