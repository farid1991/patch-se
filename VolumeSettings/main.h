#ifndef _MAIN_H_
#define _MAIN_H_

#include "ReadFile.h"

static const char GUI_NAME[] = "VolumeSettingsGUI";
static const char BOOK_NAME[] = "VolumeSettingsBook";

#define CONFIG_PATH L"/usb/other/ZBin/Config/VolumeSettings"
#define CONFIG_NAME L"VolumeSettings.ini"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#define DrawImage dll_GC_PutChar
#define Image_GetHeight dll_GetImageHeight
#define Image_GetWidth dll_GetImageWidth
#else
#define DrawImage GC_PutChar
#define Image_GetHeight GetImageHeight
#define Image_GetWidth GetImageWidth
#endif

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
  uint8_t media;
  uint8_t ring;
  uint8_t call;
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
  int onReturntoStandbyEvent(void *, BOOK *);
  void StandartRingMenu(DYNAMIC_MENU_ELEMENT *DME);
};

static const char VolumeSettings_BasePage[] = "VolumeSettings_BasePage";

const PAGE_MSG base_page[] =
    {
        RETURN_TO_STANDBY_EVENT,
        onReturntoStandbyEvent,
        NIL_EVENT,
        NULL,
};
const PAGE_DESC VS_Base_Page = {VolumeSettings_BasePage, NULL, base_page};

#endif
