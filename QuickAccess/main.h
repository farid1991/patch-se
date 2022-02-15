#ifndef _Main_H_
#define _Main_H_

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

enum MENU_ITEMS
{
  ITEM_RESTART,
  ITEM_SHUTDOWN,
  ITEM_FLIGHTMODE,
  ITEM_SEPARATOR1,
  ITEM_SILENT,
  ITEM_KEYLOCK,
  ITEM_BLUETOOTH,
  ITEM_PROFILES,
  ITEM_SEPARATOR2,
  ITEM_STANDBY,
  ITEM_SEPARATOR3,
  ITEM_LAST
};
#endif
