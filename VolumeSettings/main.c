/*
;Total volume setting
;Change the volume of media, call, talk
;Ability to change the look of the windows
;v.1
;(c) D3mon
*/
#include "temp\target.h"

#include "..\\include\Color.h"
#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "main.h"
#include "ReadFile.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(NULL, size, 1, 5, "VS", NULL));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "VS", NULL));
#else
  return (memalloc(size, 1, 5, "VS", NULL));
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, "VS", NULL);
#elif defined(A2)
    memfree(NULL, mem, "VS", NULL);
#else
    memfree(mem, "VS", NULL);
#endif
}

int Image_GetHeight(IMAGEID image_id)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  return dll_GetImageHeight(image_id);
#else
  return GetImageHeight(image_id);
#endif
}

int Image_GetWidth(IMAGEID image_id)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  return dll_GetImageWidth(image_id);
#else
  return GetImageWidth(image_id);
#endif
}

void DrawImage(GC *gc, int x, int y, int w, int h, IMAGEID img)
{
#ifdef DB3150v1
  GC_PutChar(gc, x, y, w, h, img);
#else
  dll_GC_PutChar(gc, x, y, w, h, img);
#endif
}

void DrawTexts(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int TextColor)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(font, text, align, x1, y1, x2, y2, TextColor);
#else
    SetFont(font);
    DrawString(text, align, x1, y1, x2, y2, 0, 1, TextColor, clEmpty);
#endif
  }
}

void RegisterImage(IMG *img, wchar_t *fpath, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ImageID = NOIMAGE;
  img->ImageHandle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->ImageHandle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->ImageHandle, fpath, fname, NULL, &img->ImageID, &error_code))
      if (error_code)
        img->ImageHandle = NOIMAGE;
}

void UnregisterImage(VOLUME_DISPOBJ *disp_obj)
{
  // IMG *img;
  char error_code;
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  for (int i = 0; i < LastImage; i++)
  {
    if (disp_obj->Images[i].ImageID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Images[i].ImageHandle, 0, 0, disp_obj->Images[i].ImageID, 1, &error_code);
  }
}

void InitImage(VOLUME_DISPOBJ *disp_obj)
{
  const wchar_t *ImageName[LastImage] = {
      L"Background.png",
      L"Overlay.png",
      L"Column.png",
      L"Slider.png",
      L"Cursor.png",
      L"Media.png",
      L"Ring.png",
      L"Call.png"};

  for (int i = 0; i < LastImage; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)ImageName[i]))
    {
      RegisterImage(&disp_obj->Images[i], CONFIG_PATH, (wchar_t *)ImageName[i]);
    }
    else
    {
      disp_obj->Images[i].ImageID = NOIMAGE;
    }
  }
}

int onCreate(VOLUME_DISPOBJ *disp_obj)
{
  char media, call, ring;
  InitImage(disp_obj);

  Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &ring);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);

  disp_obj->Ring = ring;
  disp_obj->Call = call - 9;
  disp_obj->Media = media - 18;

  disp_obj->data = (FILE_DATA *)malloc(sizeof(FILE_DATA));
  memset(disp_obj->data, NULL, sizeof(FILE_DATA));
  if (disp_obj->isData = ReadConfig(disp_obj->data))
  {
    disp_obj->cursor = disp_obj->data->Cursor_Position;
  }
  return TRUE;
}

void onClose(VOLUME_DISPOBJ *disp_obj)
{
  mfree(disp_obj->data);
  UnregisterImage(disp_obj);
}

void onRedraw(VOLUME_DISPOBJ *disp_obj, int a, int b, int c)
{
  // if (disp_obj->isData)
  // {
  FILE_DATA *data = disp_obj->data;

  TEXTID text;
  int image_height, image_width, image_height2, image_width2, rect_height, x, y;
  RECT rect;
  GC *gc = get_DisplayGC();

  if (disp_obj->Images[BACKGROUND].ImageID != NOIMAGE)
  {
    DrawImage(gc, 0, 35, 0, 0, disp_obj->Images[BACKGROUND].ImageID); // BACKGROUND
  }
  else if (disp_obj->data->Background_Color)
  {
    DispObject_SetLayerColor(disp_obj, disp_obj->data->Background_Color);
  }

  if (disp_obj->Images[COLUMN].ImageID != NOIMAGE) // COLUMNS
  {
    DrawImage(gc, data->Column_Media_x, data->Column_Media_y, 0, 0, disp_obj->Images[COLUMN].ImageID);
    DrawImage(gc, data->Column_Ring_x, data->Column_Ring_y, 0, 0, disp_obj->Images[COLUMN].ImageID);
    DrawImage(gc, data->Column_Call_x, data->Column_Call_y, 0, 0, disp_obj->Images[COLUMN].ImageID);

    image_width = Image_GetWidth(disp_obj->Images[COLUMN].ImageID);
    image_height = Image_GetHeight(disp_obj->Images[COLUMN].ImageID);
  }
  else
  {
    image_width = data->Column_Width;
    image_height = data->Column_Height;

    GC_DrawFRect(gc, data->Column_Fll_Color, data->Column_Media_x, data->Column_Media_y, image_width, image_height);
    GC_DrawFRect(gc, data->Column_Fll_Color, data->Column_Ring_x, data->Column_Ring_y, image_width, image_height);
    GC_DrawFRect(gc, data->Column_Fll_Color, data->Column_Call_x, data->Column_Call_y, image_width, image_height);
  }
  rect_height = image_height - ((disp_obj->Media * image_height) >> 4);
  GC_DrawFRect(gc, data->Column_BG_Color, data->Column_Media_x, data->Column_Media_y, image_width, rect_height);

  rect_height = image_height - ((disp_obj->Ring * image_height) >> 3);
  GC_DrawFRect(gc, data->Column_BG_Color, data->Column_Ring_x, data->Column_Ring_y, image_width, rect_height);

  rect_height = image_height - ((disp_obj->Call * image_height) >> 3);
  GC_DrawFRect(gc, data->Column_BG_Color, data->Column_Call_x, data->Column_Call_y, image_width, rect_height);

  if (disp_obj->Images[1].ImageID != NOIMAGE) // OVERLAY
  {
    DrawImage(gc, data->Overlay_x, data->Overlay_y, 0, 0, disp_obj->Images[OVERLAY].ImageID);
  }

  if (disp_obj->Images[CURSOR].ImageID != NOIMAGE) // CURSOR
  {
    switch (disp_obj->cursor)
    {
    case 0:
      x = data->Cursor_Media_x;
      y = data->Cursor_Media_y;
      break;
    case 1:
      x = data->Cursor_Ring_x;
      y = data->Cursor_Ring_y;
      break;
    case 2:
      x = data->Cursor_Call_x;
      y = data->Cursor_Call_y;
      break;
    }
    DrawImage(gc, x, y, 0, 0, disp_obj->Images[CURSOR].ImageID);
  }
  else
  {
    switch (disp_obj->cursor)
    {
    case 0:
      rect.x1 = data->Column_Media_x;
      rect.y1 = data->Column_Media_y;
      break;
    case 1:
      rect.x1 = data->Column_Ring_x;
      rect.y1 = data->Column_Ring_y;
      break;
    case 2:
      rect.x1 = data->Column_Call_x;
      rect.y1 = data->Column_Call_y;
      break;
    }
    rect.x2 = rect.x1-- + data->Column_Width + 1;
    rect.y2 = rect.y1-- + data->Column_Height + 1;

    GC_SetPenColor(gc, data->Cursor_Color);
    GC_DrawRoundRect(gc, &rect, 0, 0, 1, 0);
  }

  if (data->Icon_Enable) // ICONS
  {
    DrawImage(gc, data->Icon_Media_x, data->Icon_Media_y, 0, 0, disp_obj->Images[MEDIA].ImageID);
    DrawImage(gc, data->Icon_Ring_x, data->Icon_Ring_y, 0, 0, disp_obj->Images[RING].ImageID);
    DrawImage(gc, data->Icon_Call_x, data->Icon_Call_y, 0, 0, disp_obj->Images[CALL].ImageID);
  }

  if (data->Level_Enable) // LEVELS
  {
    text = TextID_CreateIntegerID(disp_obj->Media);
    DrawTexts(data->Font_Level, text, data->Align_Level_Media, data->Level_Media_x1, data->Level_Media_y1, data->Level_Media_x2, data->Level_Media_y2, data->Level_Color);
    TextID_Destroy(text);

    text = TextID_CreateIntegerID(disp_obj->Ring);
    DrawTexts(data->Font_Level, text, data->Align_Level_Ring, data->Level_Ring_x1, data->Level_Ring_y1, data->Level_Ring_x2, data->Level_Ring_y2, data->Level_Color);
    TextID_Destroy(text);

    text = TextID_CreateIntegerID(disp_obj->Call);
    DrawTexts(data->Font_Level, text, data->Align_Level_Call, data->Level_Call_x1, data->Level_Call_y1, data->Level_Call_x2, data->Level_Call_y2, data->Level_Color);
    TextID_Destroy(text);
  }

  if (disp_obj->Images[SLIDER].ImageID != NOIMAGE) // SLIDER
  {
    image_width = Image_GetWidth(disp_obj->Images[SLIDER].ImageID);
    image_height = Image_GetHeight(disp_obj->Images[SLIDER].ImageID);

    if (disp_obj->Images[COLUMN].ImageID != NOIMAGE)
    {
      image_width2 = Image_GetWidth(disp_obj->Images[COLUMN].ImageID);
      image_height2 = Image_GetHeight(disp_obj->Images[COLUMN].ImageID);
    }
    else
    {
      image_width2 = data->Column_Width;
      image_height2 = data->Column_Height;
    }

    x = data->Column_Media_x + (image_width2 >> 1) - (image_width >> 1);
    y = data->Column_Media_y + image_height2 - (image_height >> 1) - ((disp_obj->Media * image_height2) >> 4);
    DrawImage(gc, x, y, 0, 0, disp_obj->Images[SLIDER].ImageID);

    x = data->Column_Ring_x + (image_width2 >> 1) - (image_width >> 1);
    y = data->Column_Ring_y + image_height2 - (image_height >> 1) - ((disp_obj->Ring * image_height2) >> 3);
    DrawImage(gc, x, y, 0, 0, disp_obj->Images[SLIDER].ImageID);

    x = data->Column_Call_x + (image_width2 >> 1) - (image_width >> 1);
    y = data->Column_Call_y + image_height2 - (image_height >> 1) - ((disp_obj->Call * image_height2) >> 3);
    DrawImage(gc, x, y, 0, 0, disp_obj->Images[SLIDER].ImageID);
  }
  // }
}

void onKey(VOLUME_DISPOBJ *disp_obj, int key, int unk, int repeat, int mode)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  // if (disp_obj->isData)
  // {
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    //
    if (key == KEY_RIGHT || key == KEY_DIGITAL_6)
    {
      if (++disp_obj->cursor == 3)
        disp_obj->cursor = 0;
    }
    //
    else if (key == KEY_LEFT || key == KEY_DIGITAL_4)
    {
      if (--disp_obj->cursor < 0)
        disp_obj->cursor = 2;
    }
    //
    else if (key == KEY_UP || key == KEY_DIGITAL_2)
    {
      switch (disp_obj->cursor)
      {
      case 0:
        if (disp_obj->Media < 15)
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, ++disp_obj->Media + 18);
        break;
      case 1:
        if (disp_obj->Ring < 8)
        {
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, ++disp_obj->Ring);
          REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, disp_obj->Ring);
        }
        break;
      case 2:
        if (disp_obj->Call < 8)
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, ++disp_obj->Call + 9);
        break;
      }
    }
    //
    else if (key == KEY_DOWN || key == KEY_DIGITAL_8)
    {
      switch (disp_obj->cursor)
      {
      case 0:
        if (disp_obj->Media)
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, --disp_obj->Media + 18);
        break;
      case 1:
        if (disp_obj->Ring)
        {
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, --disp_obj->Ring);
          REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, disp_obj->Ring);
        }
        break;
      case 2:
        if (disp_obj->Call)
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, --disp_obj->Call + 9);
        break;
      }
    }
  }
  // "C"
  if (key == KEY_DEL)
  {
    if (mode == KBD_SHORT_RELEASE)
    {
      switch (disp_obj->cursor)
      {
      case 0:
        disp_obj->Media = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, 18);
        break;
      case 1:
        disp_obj->Ring = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, 0);
        REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, 0);
        break;
      case 2:
        disp_obj->Call = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, 9);
        break;
      }
    }
    else if (mode == KBD_LONG_PRESS)
    {
      disp_obj->Media = disp_obj->Ring = disp_obj->Call = 0;
      Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, 18);
      Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, 0);
      REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, NULL, 0);
      Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, 9);
    }
  }
  DispObject_InvalidateRect(disp_obj, NULL);
  // }
}

void onLayout(VOLUME_DISPOBJ *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, disp_obj->data->Background_Color);
}

void VS_constr(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, "VolumeSettingsGUI");
  DISP_DESC_SetSize(desc, sizeof(VOLUME_DISPOBJ));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)onCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)onClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)onRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)onKey);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)onLayout);
}

void VS_destr(GUI *)
{
}

void VS_callback(DISP_OBJ *, void *msg, GUI *)
{
}

GUI *CreateVolumeGui(VSBook *VS_book)
{
  GUI *VS_gui = (GUI *)malloc(sizeof(GUI));
  if (!GUIObject_Create(VS_gui, VS_destr, VS_constr, VS_book, VS_callback, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(VS_gui);
    return NULL;
  }

  if (VS_book)
    BookObj_AddGUIObject(VS_book, VS_gui);

  GUIObject_SetStyle(VS_gui, UI_OverlayStyle_Default);

  return VS_gui;
}

int cmp_proc_name(BOOK *book, int *param)
{
  if (!strcmp(book->xbook->name, (char *)param))
    return TRUE;
  return FALSE;
}

const PAGE_MSG base_page[] =
    {
        RETURN_TO_STANDBY_EVENT, onStandyEvent,
        NIL_EVENT, NULL};
const PAGE_DESC to_base_page = {"VolumeSettings_BasePage", NULL, base_page};

void CallMenu()
{
  BOOK *book = FindBookEx(cmp_proc_name, (int *)BOOK_NAME);
  if (book)
  {
    BookObj_SetFocus(book, UIDisplay_Main);
    return;
  }

  VSBook *VSettingBook = (VSBook *)malloc(sizeof(VSBook));
  memset(VSettingBook, NULL, sizeof(VSBook));
  if (!CreateBook(VSettingBook, onCloseBook, &to_base_page, BOOK_NAME, NO_BOOK_ID, NULL))
  {
    mfree(VSettingBook);
    return;
  }

  if (VSettingBook->Gui = CreateVolumeGui(VSettingBook))
  {
    GUIObject_SetTitleType(VSettingBook->Gui, UI_TitleMode_Normal);
    GUIObject_SetTitleText(VSettingBook->Gui, VOLUME_TXT);
    GUIObject_SoftKeys_SetAction(VSettingBook->Gui, ACTION_BACK, onBackPressed);
    GUIObject_SoftKeys_SetAction(VSettingBook->Gui, ACTION_LONG_BACK, onLongBackPressed);
    GUIObject_Show(VSettingBook->Gui);
  }
}

TEXTID GetSecondRow()
{
  char buf[20];
  char media, ring, call;

  Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &ring);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);

  sprintf(buf, "Volume: %d, %d, %d", media - 18, ring, call - 9);
  return TextID_Create(buf, ENC_LAT1, TEXTID_ANY_LEN);
}

void NewMenuItem(DYNAMIC_MENU_ELEMENT *DME)
{
  switch (DynamicMenu_GetElementMsg(DME))
  {
  case DYNAMIC_MENU_onCall:
    CallMenu();
    break;
  case DYNAMIC_MENU_onText:
    DynamicMenu_SetElement_FirstLineText(DME, RING_VOLUME_TXT);
    DynamicMenu_SetElement_SecondLineText(DME, GetSecondRow());
    break;
  }
}

__thumb void LaunchNewMenuItem(DYNAMIC_MENU_ELEMENT *DME)
{
  if (FindBookEx(cmp_proc_name, (int *)ProfileBook))
    StandartRingMenu(DME);
  else
    NewMenuItem(DME);
}

#pragma diag_suppress = Pe177
//__root  const int PATCH_Volume @ "PATCH_Volume" =(int)VOLUME_SETTINGS_ID;
__root const int PATCH_VolumeFunc @ "PATCH_VolumeFunc" = (int)LaunchNewMenuItem;
