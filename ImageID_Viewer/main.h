#ifndef _MAIN_H_
#define _MAIN_H_

const int items_text[] = 
{
  ITEM_1,
  ITEM_2,
  ITEM_3,
  ITEM_4,
  ITEM_5
};

extern "C"
{
  void onBackPressed(BOOK *book, GUI* gui);
  void onLongBackPressed(BOOK *book, GUI* gui);
  
  int pg_ServiceMenu_Test_Security_ExitAction(void* mess, BOOK* book);
  int pg_ServiceMenu_TestMenu_ReturnStandbyAction(void* mess, BOOK* book);
};

#endif
