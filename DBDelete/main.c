#include "..\\include\Types.h"
#include "..\\include\Function.h"

void NewActionLongBack(BOOK* book, GUI* gui)
{
  SUB_EXECUTE* sub_execute = BrowserItem_Get_SUB_EXECUTE(book);
  FREE_GUI(sub_execute->gui);
  FREE_GUI(sub_execute->gui_fb);
  BookObj_ReturnPage(book,4);
}

extern "C"
void NewActionNo(BOOK* book, GUI* gui)
{
  SUB_EXECUTE* sub_execute = BrowserItem_Get_SUB_EXECUTE(book);
  FREE_GUI(sub_execute->gui_fb);
  BookObj_ReturnPage(book,4);
}

extern "C"
void NewGui(SUB_EXECUTE* sub_execute)
{
  GUIObject_SoftKeys_SetAction(sub_execute->gui,ACTION_LONG_BACK,NewActionLongBack);
}
