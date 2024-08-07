#ifndef _MAIN_H_
#define _MAIN_H_

enum MENU_ITEMS
{
  ITEM_1,
  ITEM_2,
  ITEM_3,
  LAST_ITEM
};

extern "C"
{
  GUI *Create_KnobOption(BOOK *bk, int display);
  void KnobOption_SetTitleText(GUI *g, TEXTID);
  void KnobOption_SetItemCount(GUI *g, int item);
  void KnobOption_SetCursor(GUI *g, int pos);
  void KnobOption_SetItems(GUI *g, TEXTID, int num);
  int KnobOption_GetSelectedItem(GUI *g);
};

#endif
