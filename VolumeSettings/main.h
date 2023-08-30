#ifndef _MAIN_H_
#define _MAIN_H_

#include "ReadFile.h"

#define BOOK_NAME "VolumeSettingsBook"
#define CONFIG_PATH L"/usb/other/ZBin/Config/VolumeSettings"
#define CONFIG_NAME L"VolumeSettings.ini"

typedef struct _VSBook : BOOK
{
  GUI *Gui;
} VSBook;

enum VS_IMAGE
{
  BACKGROUND,
  OVERLAY,
  COLUMN,
  SLIDER,
  CURSOR,
  MEDIA,
  RING,
  CALL,
  LastImage
};

typedef struct
{
  IMAGEID ImageID;
  u16 ImageHandle;
} IMG;

typedef struct _VOLUME_DISPOBJ : DISP_OBJ
{
  uint8_t Media;
  uint8_t Ring;
  uint8_t Call;
  bool isData;
  int8_t cursor;
  IMG Images[LastImage];
  FILE_DATA *data;
} VOLUME_DISPOBJ;

extern "C"
{
  void onBackPressed(BOOK *, GUI *gui);
  void onLongBackPressed(BOOK *, GUI *gui);
  void onCloseBook(BOOK *);
  int onStandyEvent(void *, BOOK *);
  void StandartRingMenu(DYNAMIC_MENU_ELEMENT *DME);
};

#endif
