/*
;Total volume setting
;Change the volume of media, call, talk
;Ability to change the look of the windows
;v.1
;(c) D3mon
;(p) 
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\types\AudioControl_types.h"

#include "ReadFile.h"
#include "main.h"


__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF,size,1,5,"vs",0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,"vs",0);
}



void RegisterImage(MyDISP_OBJ * DispObj)
{
  const wchar_t * ImageName[] = {L"Background.png", L"Overlay.png", L"Column.png", L"Slider.png", L"Cursor.png", L"Media.png", L"Ring.png", L"Call.png"};
  IMG * img;
  char error_code;
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  for(int i = 0; i < img_count; i++)
  {
    img = &DispObj->Images[i];
    img->ImageID = NOIMAGE;
    img->ImageHandle = NOIMAGE;
    if (!fstat(ImagePath, ImageName[i], 0))
    {
      if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->ImageHandle, &error_code))
      {
        if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->ImageHandle, ImagePath, (wchar_t*)ImageName[i], 0, &img->ImageID, &error_code))
        {
          if (error_code) img->ImageHandle = NOIMAGE;
        }
      }
    }
  }
}
void UnregisterImage(MyDISP_OBJ * DispObj)
{
  IMG * img;
  char error_code;
  int _SYNC = 0;
  int *SYNC = &_SYNC;
  
  for(int i = 0; i < img_count; i++)
  {
    img = &DispObj->Images[i];
    if (img->ImageID != NOIMAGE) REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, img->ImageHandle, 0, 0, img->ImageID, 1, &error_code);
  }
}

int onCreate(DISP_OBJ * disp)
{
  MyDISP_OBJ * DispObj = (MyDISP_OBJ*)disp;
  char media, call;
  
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &DispObj->Ring);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  
  DispObj->Call = call - 9;
  DispObj->Media = media - 18;
  
  RegisterImage(DispObj);
  DispObj->data = (FILE_DATA*)malloc(sizeof(FILE_DATA));
  if (DispObj->isData = ReadConfig(DispObj->data)) DispObj->cursor = DispObj->data->Cursor_Position;
  
  return 1;
}

void onClose(DISP_OBJ * disp)
{
  MyDISP_OBJ * DispObj = (MyDISP_OBJ*)disp;
  UnregisterImage(DispObj);
  mfree(DispObj->data);
}


void onRedraw(DISP_OBJ * disp, int, int, int)
{
  MyDISP_OBJ * DispObj = (MyDISP_OBJ*)disp;
  FILE_DATA * data = DispObj->data;
  
  TEXTID text;
  int image_height,image_width, image_height2,image_width2, rect_height, x,y;
  RECT rect;
  
  if (DispObj->isData)
  {
    GC * gc = get_DisplayGC();
    
    if ((DispObj->Images[0].ImageID != NOIMAGE)) GC_DrawIcon( 0, 35, DispObj->Images[0].ImageID); // BACKGROUND
    else if (DispObj->data->Background_Color) DispObject_SetLayerColor(DispObj, DispObj->data->Background_Color);
    
    if (DispObj->Images[2].ImageID != NOIMAGE) // COLUMNS
    {
      GC_DrawIcon( data->Column_Media_x, data->Column_Media_y, DispObj->Images[2].ImageID);
      GC_DrawIcon( data->Column_Ring_x, data->Column_Ring_y, DispObj->Images[2].ImageID);
      GC_DrawIcon( data->Column_Call_x, data->Column_Call_y, DispObj->Images[2].ImageID);

      image_width = GetImageWidth(DispObj->Images[2].ImageID);
      image_height = GetImageHeight(DispObj->Images[2].ImageID);
    }
    else
    {
      image_width = data->Column_Width;
      image_height = data->Column_Height;
      
      GC_DrawFRect(gc, data->Column_Fll_Color, data->Column_Media_x, data->Column_Media_y, image_width, image_height);
      GC_DrawFRect(gc, data->Column_Fll_Color, data->Column_Ring_x, data->Column_Ring_y, image_width, image_height);
      GC_DrawFRect(gc, data->Column_Fll_Color, data->Column_Call_x, data->Column_Call_y, image_width, image_height);
    }
    rect_height = image_height - (DispObj->Media*image_height/15);
    GC_DrawFRect(gc, data->Column_BG_Color, data->Column_Media_x, data->Column_Media_y, image_width, rect_height);
    
    rect_height = image_height - (DispObj->Ring*image_height/8);
    GC_DrawFRect(gc, data->Column_BG_Color, data->Column_Ring_x, data->Column_Ring_y, image_width, rect_height);
    
    rect_height = image_height - (DispObj->Call*image_height/8);
    GC_DrawFRect(gc, data->Column_BG_Color, data->Column_Call_x, data->Column_Call_y, image_width, rect_height);
    
    
    if (DispObj->Images[1].ImageID != NOIMAGE) // OVERLAY
    {
      GC_DrawIcon( data->Overlay_x, data->Overlay_y, DispObj->Images[1].ImageID);
    }
    if (DispObj->Images[4].ImageID != NOIMAGE) // CURSOR
    {
      switch (DispObj->cursor)
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
      GC_PutChar( gc, x, y, 0, 0, DispObj->Images[4].ImageID);
    }
    else
    {
      switch (DispObj->cursor)
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
      GC_DrawIcon( data->Icon_Media_x, data->Icon_Media_y, DispObj->Images[5].ImageID);
      GC_DrawIcon( data->Icon_Ring_x, data->Icon_Ring_y, DispObj->Images[6].ImageID);
      GC_DrawIcon( data->Icon_Call_x, data->Icon_Call_y, DispObj->Images[7].ImageID);
    }
    if (data->Level_Enable) // LEVELS
    {
      text = TextID_CreateIntegerID(DispObj->Media);
      SetFont(data->Font_Level);
      DrawString(text, data->Align_Level_Media, data->Level_Media_x1, data->Level_Media_y1, data->Level_Media_x2, data->Level_Media_y2, 0, 1, data->Level_Color, data->Level_Color);
      TextID_Destroy(text);
      
      text = TextID_CreateIntegerID(DispObj->Ring);SetFont(data->Font_Level);
      DrawString(text, data->Align_Level_Ring, data->Level_Ring_x1, data->Level_Ring_y1, data->Level_Ring_x2, data->Level_Ring_y2, 0, 1, data->Level_Color, data->Level_Color);
      TextID_Destroy(text);
      
      text = TextID_CreateIntegerID(DispObj->Call);
      SetFont(data->Font_Level);
      DrawString(text, data->Align_Level_Call, data->Level_Call_x1, data->Level_Call_y1, data->Level_Call_x2, data->Level_Call_y2, 0, 1, data->Level_Color, data->Level_Color);
      TextID_Destroy(text);
    }
    if (DispObj->Images[3].ImageID != NOIMAGE) // SLIDER
    {
      image_width = GetImageWidth(DispObj->Images[3].ImageID);
      image_height = GetImageHeight(DispObj->Images[3].ImageID);
      if (DispObj->Images[2].ImageID != NOIMAGE)
      {
        image_width2 = GetImageWidth(DispObj->Images[2].ImageID);
        image_height2 = GetImageHeight(DispObj->Images[2].ImageID);
      }
      else
      {
        image_width2 =  data->Column_Width;
        image_height2 = data->Column_Height;
      }
      x = data->Column_Media_x + image_width2/2 - image_width/2;
      y = data->Column_Media_y + image_height2 - image_height/2 - (DispObj->Media*image_height2/15);
      GC_PutChar( gc, x, y, 0, 0, DispObj->Images[3].ImageID);
      
      x = data->Column_Ring_x + image_width2/2 - image_width/2;
      y = data->Column_Ring_y + image_height2 - image_height/2 - (DispObj->Ring*image_height2/8);
      GC_PutChar( gc, x, y, 0, 0, DispObj->Images[3].ImageID);
      
      x = data->Column_Call_x + image_width2/2 - image_width/2;
      y = data->Column_Call_y + image_height2 - image_height/2 - (DispObj->Call*image_height2/8);
      GC_PutChar( gc, x, y, 0, 0, DispObj->Images[3].ImageID);
    }
  }
}


void onKey(DISP_OBJ * disp, int key, int unk, int repeat, int mode)
{
  MyDISP_OBJ * DispObj = (MyDISP_OBJ*)disp;
  
  int _SYNC = 0;
  int *SYNC = &_SYNC;
  
  if (DispObj->isData)
  {
    if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
    {
      // ÂÏÐÀÂÎ
      if (key == KEY_RIGHT || key == KEY_DIGITAL_0+6)
      {
        if (++DispObj->cursor == 3 ) DispObj->cursor = 0;
      }
      // ÂËÅÂÎ
      else if (key == KEY_LEFT || key == KEY_DIGITAL_0+4)
      {
        if (--DispObj->cursor < 0 ) DispObj->cursor = 2;
      }
      // ÂÂÅÐÕ
      else if (key == KEY_UP || key == KEY_DIGITAL_0+2)
      {
        switch (DispObj->cursor)
        {
        case 0:
          if (DispObj->Media < 15) Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, ++DispObj->Media+18);
          break;
        case 1:
          if (DispObj->Ring < 8)
          {
            Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, ++DispObj->Ring);
            REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, DispObj->Ring);
          }
          break;
        case 2:
          if (DispObj->Call < 8) Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, ++DispObj->Call+9);
          break;
        }
      }
      // ÂÍÈÇ
      else if (key == KEY_DOWN || key == KEY_DIGITAL_0+8)
      {
        switch (DispObj->cursor)
        {
        case 0:
          if (DispObj->Media) Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, --DispObj->Media+18);
          break;
        case 1:
          if (DispObj->Ring)
          {
            Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, --DispObj->Ring);
            REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, DispObj->Ring);
          }
          break;
        case 2:
          if (DispObj->Call) Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, --DispObj->Call+9);
          break;
        }
      }
      DispObject_InvalidateRect(DispObj, 0);
    }
    // "C"
    if (key == KEY_DEL)
    {
      if (mode == KBD_SHORT_RELEASE)
      {
        switch (DispObj->cursor)
        {
        case 0:
          DispObj->Media = 0;
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, 18);
          break;
        case 1:
          DispObj->Ring = 0;
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, 0);
          REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, 0);
          break;
        case 2:
          DispObj->Call = 0;
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, 9);
          break;
        }
      }
      else if (mode == KBD_LONG_PRESS)
      {
        DispObj->Media = DispObj->Ring = DispObj->Call = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, 18);
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, 0);
        REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, 0);
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, 9);
      }
      DispObject_InvalidateRect(DispObj, 0);
    }
  }
}

void onDispDesc( DISP_DESC * DispDesc )
{
  DISP_DESC_SetName(DispDesc, "Volume_Settings");
  DISP_DESC_SetSize(DispDesc, sizeof(MyDISP_OBJ));
  DISP_DESC_SetOnCreate(DispDesc, (DISP_OBJ_ONCREATE_METHOD)onCreate);
  DISP_DESC_SetOnClose(DispDesc, (DISP_OBJ_ONCLOSE_METHOD)onClose);
  DISP_DESC_SetOnRedraw(DispDesc, (DISP_OBJ_ONREDRAW_METHOD)onRedraw);
  DISP_DESC_SetOnKey(DispDesc, (DISP_OBJ_ONKEY_METHOD)onKey);
}

void onDestroy(GUI*)
{
}

GUI * CreateGui(MyBOOK * book)
{
  GUI* VS_gui = (GUI*)malloc(sizeof(GUI));
  if (!GUIObject_Create(VS_gui, onDestroy, onDispDesc, book, 0, 0, 0))
  {
    mfree(VS_gui);
    return 0;
  }
  GUIObject_SetStyle(VS_gui, UI_OverlayStyle_FullScreenNoSoftkeys);
  GUIObject_SetTitleText(VS_gui, 0x1E13);
  GUIObject_SoftKeys_SetAction(VS_gui, ACTION_BACK, onBackPressed);
  GUIObject_SoftKeys_SetAction(VS_gui, ACTION_LONG_BACK, onLongBackPressed);
  GUIObject_SoftKeys_RemoveBackground(VS_gui);
  BookObj_AddGUIObject(book, VS_gui);
  GUIObject_Show(VS_gui);
  return VS_gui;
}

int cmp_proc_name(BOOK* book, int* param)
{
  if(!strcmp(book->xbook->name, (char*)param)) return 1;
  return 0;
}

const PAGE_MSG base_page[] = 
{
  RETURN_TO_STANDBY_EVENT,  OnStandyEvent,
  NIL_EVENT,                NULL
};
const PAGE_DESC to_base_page = {"Volume_Setting_BasePage", 0, base_page};


void Main()
{
  BOOK * book = FindBookEx(cmp_proc_name, (int*)BOOK_NAME);
  if (book) BookObj_SetFocus(book, 0);
  else
  {
    MyBOOK * VSettingBook = (MyBOOK*)malloc(sizeof(MyBOOK));
    if (!CreateBook(VSettingBook, onCloseBook, &to_base_page, BOOK_NAME, -1, 0)) mfree(VSettingBook);
    else VSettingBook->Gui = CreateGui(VSettingBook);
  }
}

TEXTID GetSecondRow()
{
  wchar_t buf[16];
  char media, ring, call;
  
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &ring);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  
  snwprintf(buf, 15, L" %d, %d, %d", media-18, ring, call-9);
  int text[2] = {0x1E13,TextID_Create(buf, ENC_UCS2, 0xF)};
  return TextID_Create(text, ENC_TEXTID, 0xFF);
}



void MyMenu(DYNAMIC_MENU_ELEMENT* DME)
{
  switch(DynamicMenu_GetElementMsg(DME))
  {
  case MENU_onCall:
    Main();
    break;
  case MENU_onText:
    DynamicMenu_SetElement_FirstLineText(DME, 0x13B9);
    DynamicMenu_SetElement_SecondLineText(DME, GetSecondRow());
    break;
  }
}

__thumb void ToCompareMenuItem(DYNAMIC_MENU_ELEMENT* DME)
{
  if (FindBookEx(cmp_proc_name, (int*)ProfileBook)) StandartRingMenu(DME);
  else MyMenu(DME);
}

#pragma diag_suppress=Pe177
//__root  const int PATCH_Volume @ "PATCH_Volume" =(int)VOLUME_SETTINGS_ID;
__root  const int PATCH_VolumeFunc @ "PATCH_VolumeFunc" =(int)ToCompareMenuItem;
