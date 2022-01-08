#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "Data.h"
#include "Pages.h"

void BI_Accept_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  BCBook->fdata.bright = PercentInput_GetPercent(BCBook->bright_input);

  WriteData(BCBook, BCBook->itemcount);
  FREE_GUI(BCBook->bright_input);
  FREE_GUI(BCBook->time_input);
  FREE_GUI(BCBook->books_list);
  BookObj_GotoPage(BCBook, &BacklightControlBook_Main_Page);
}

void BI_Prev_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->bright_input);
}

void BI_Cancel_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->bright_input);
  FREE_GUI(BCBook->time_input);
  FREE_GUI(BCBook->books_list);
}

void Backlight_BrightInput(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  BCBook->bright_input = CreatePercentInputVA(0,
                                              VAR_BOOK, BCBook,
                                              VAR_HEADER_TEXT, STR("Brightness"),
                                              VAR_PERINP_ROWNUM, 9,
                                              VAR_PERINP_CURPERC, BCBook->bright,
                                              0);
  GUIObject_SoftKeys_SetAction(BCBook->bright_input, ACTION_SELECT1, BI_Accept_Action);
  GUIObject_SoftKeys_SetText(BCBook->bright_input, ACTION_SELECT1, STR("OK"));
  GUIObject_SoftKeys_SetAction(BCBook->bright_input, ACTION_BACK, BI_Prev_Action);
  GUIObject_SoftKeys_SetAction(BCBook->bright_input, ACTION_LONG_BACK, BI_Cancel_Action);
}
