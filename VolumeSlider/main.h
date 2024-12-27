#ifndef _MAIN_H_
#define _MAIN_H_

static char *MEM_NAME = "VS";
static char *BOOK_NAME = "VolumeSettingsBook";

typedef struct _VSBook : BOOK
{
  GUI *Gui;
} VSBook;

extern "C"
{
  void onBackPressed(BOOK *, GUI *gui);
  void onLongBackPressed(BOOK *, GUI *gui);
  void onCloseBook(BOOK *);
  int onStandyEvent(void *, BOOK *);
  void StandartRingMenu(DYNAMIC_MENU_ELEMENT *DME);
};

#endif
