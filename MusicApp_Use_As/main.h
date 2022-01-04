#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(gui)       \
  if (gui)                  \
  {                       \
    GUIObject_Destroy(gui); \
    gui = NULL;             \
  }

enum ITEM
{
  ITEM_1,
  ITEM_2,
  ITEM_3,
  ITEM_4,
  ITEM_LAST
};

static const int items_text[ITEM_LAST] =
    {
        RINGTONE_TXT,
        MESSAGEALERT_TXT,
        ALARMSIGNAL_TXT,
        CONTACTSIGNAL_TXT};

extern "C"
{
  int pg_MusicApplication_PreviousEvent(void *Data, BOOK *book);
  int pg_MusicApplication_CancelEvent(void *Data, BOOK *book);
  int pg_MusicApplication_ExitEvent(void *Data, BOOK *book);

  void MusicApp_PrevAction(BOOK *book, GUI *gui);
  void MusicApp_CancelAction(BOOK *book, GUI *gui);
};

#endif
