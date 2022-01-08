#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "Data.h"
#include "bright_input.h"

void TI_UnlimitAccept_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  BCBook->fdata.time = TIME_LIMIT;

  FILEDATA *fdata = &((TEMPDATA *)BCBook->mydata)->fdata;
  int num = ListMenu_GetSelectedItem(BCBook->main_menu);

  BCBook->bright = GetBrightFromData(fdata, num);
  Backlight_BrightInput(BCBook);
}

void TI_Accept_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  unsigned int time_i = TimeInput_GetTimeInt(BCBook->time_input);

  BCBook->fdata.time = (TI_GET_HOUR(time_i) * 60 * 60) + (TI_GET_MIN(time_i) * 60) + TI_GET_SEC(time_i);

  if (BCBook->fdata.time > TIME_LIMIT)
    BCBook->fdata.time = TIME_LIMIT;

  FILEDATA *fdata = &((TEMPDATA *)BCBook->mydata)->fdata;
  int index = ListMenu_GetSelectedItem(BCBook->main_menu);

  BCBook->bright = GetBrightFromData(fdata, index);
  Backlight_BrightInput(BCBook);
}

void TI_Cancel_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->time_input);
  FREE_GUI(BCBook->books_list);
  BCBook->time = NULL;
}

void TI_Prev_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->time_input);
  BCBook->time = NULL;
}

void Backlight_TimeInput(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  BCBook->time_input = CreateTimeInputVA(0,
                                         VAR_BOOK, BCBook,
                                         VAR_HEADER_TEXT, STR("Backlight time"),
                                         VAR_TIMEINP_TIMEFORMAT_SEC, 1,
                                         VAR_TIMEINP_TIMEFORMAT, 1,
                                         VAR_TIMEINP_TIME, BCBook->time,
                                         0);
  GUIObject_SoftKeys_SetAction(BCBook->time_input, ACTION_SELECT1, TI_Accept_Action);
  GUIObject_SoftKeys_SetText(BCBook->time_input, ACTION_SELECT1, STR("OK"));
  GUIObject_SoftKeys_SetVisible(BCBook->time_input, ACTION_SELECT1, TRUE);
  GUIObject_SoftKeys_SetAction(BCBook->time_input, 0, TI_UnlimitAccept_Action);
  GUIObject_SoftKeys_SetText(BCBook->time_input, 0, STR("Unlimited"));
  GUIObject_SoftKeys_SetVisible(BCBook->time_input, 0, TRUE);
  GUIObject_SoftKeys_SetAction(BCBook->time_input, ACTION_BACK, TI_Prev_Action);
  GUIObject_SoftKeys_SetAction(BCBook->time_input, ACTION_LONG_BACK, MainList_Cancel_Action);
  GUIInput_SetIcon(BCBook->time_input, TIMEINPUT_ICN);
}
