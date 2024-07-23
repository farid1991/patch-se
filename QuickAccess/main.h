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
#ifndef FLIP_PHONE
  ITEM_KEYLOCK,
#endif
#ifdef HAVE_BT
  ITEM_BLUETOOTH,
#endif
#ifdef HAVE_IRDA
  ITEM_IRDA,
#endif
  ITEM_PROFILES,
  ITEM_SEPARATOR2,
  ITEM_STANDBY,
  ITEM_SEPARATOR3,
  ITEM_LAST
};
#endif
