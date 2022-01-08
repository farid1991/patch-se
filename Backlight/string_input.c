#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "Data.h"
#include "time_input.h"

void SI_Accept_Action(BOOK *book, wchar_t *string, int len)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;

  wstr2strn(BCBook->fdata.bookname, string, BOOKNAME_MAX_LEN);
  TIME time;
  time.hour = 0;
  time.min = 0;
  time.sec = 0;
  BCBook->time = &time;
  Backlight_TimeInput(BCBook);
}

void SI_Prev_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->string_input);
}

void Backlight_BooknameInput(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  BCBook->string_input = CreateStringInputVA(0,
                                             VAR_BOOK, BCBook,
                                             VAR_STRINP_MODE, IT_STRING,
                                             VAR_STRINP_NEW_LINE, 1,
                                             VAR_STRINP_MAX_LEN, BOOKNAME_MAX_LEN,
                                             VAR_STRINP_MIN_LEN, 1,
                                             VAR_STRINP_FIXED_TEXT, STR("Book Name:"),
                                             VAR_BACK_PROC, SI_Prev_Action,
                                             VAR_LONG_BACK_PROC, MainList_Cancel_Action,
                                             VAR_OK_PROC, SI_Accept_Action,
                                             0);
}
