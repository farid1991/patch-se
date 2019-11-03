#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"
#include "visual.h"

int division(int num1, int num2)
{
  int temp = 1, quotient = 0;
  while (num2 <= num1)
  {
    num2 <<= 1;
    temp <<= 1;
  }
  while (temp > 1)
  {
    num2 >>= 1;
    temp >>= 1;
    if(num1 >= num2)
    {
      num1 -= num2;
      quotient += temp;
    }
  }
  return quotient;
}

void RegisterImage(IMG* img, wchar_t* path, wchar_t* fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ID = NOIMAGE;
  img->Handle = NOIMAGE;
  
  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->Handle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->Handle, path, fname, 0, &img->ID, &error_code))
      if (error_code) img->Handle = NOIMAGE;
}

void UnRegisterImage(DISP_OBJ_CLEARBASS* disp_obj)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  
  for (int i = 0; i < LastPreset; i++)
    if (disp_obj->Image[i].ID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Image[i].Handle, 0, 0, disp_obj->Image[i].ID, 1, &error_code);
}

void LoadImage(DISP_OBJ_CLEARBASS* disp_obj)
{
  const wchar_t* ImageName[] =
  {
    L"IMG_Treble.png",      //0
    L"IMG_Heavy.png",       //1
    L"IMG_Pop.png",         //2
    L"IMG_Jazz.png",        //3
    L"IMG_Normal.png",      //4
    L"IMG_Unique.png",      //5
    L"IMG_Soul.png",        //6
    L"IMG_Light.png",       //7
    L"IMG_Bass.png",        //8
    L"BACKGROUND.png"       //9
  };
  
  int i;
  for (i = 0; i < 10; i++)
  {
    if( FSX_IsFileExists(CONFIG_PATH, (wchar_t*)ImageName[i]))
    {
      RegisterImage(&disp_obj->Image[i], CONFIG_PATH, (wchar_t*)ImageName[i]);
    }
    else disp_obj->Image[i].ID = NOIMAGE;
  }
}

TEXTID DispObj_Clearbass_GetPresetName(DISP_OBJ_CLEARBASS* disp_obj)
{
  const wchar_t* PresetNames[LastPreset]=
  {
    L"Treble",
    L"Heavy",
    L"Pop",
    L"Jazz",
    L"Normal",
    L"Unique",
    L"Soul",
    L"Light",
    L"Bass"
  };
  return TextID_Create(PresetNames[disp_obj->cursor], ENC_UCS2, TEXTID_ANY_LEN);
}

BOOL DispObj_Clearbass_GetState(DISP_OBJ_CLEARBASS* disp_obj)
{
  return disp_obj->preset ? TRUE : FALSE;
}

BOOL GUI_Clearbass_GetState(GUI* gui)
{
  return DispObj_Clearbass_GetState((DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui));
}

int DispObj_Clearbass_GetCursor(DISP_OBJ_CLEARBASS* disp_obj)
{
  return (disp_obj->cursor);
}

int GUI_Clearbass_GetCursor(GUI* gui)
{
  return DispObj_Clearbass_GetCursor((DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui));
}

void DispObj_Clearbass_Switch(DISP_OBJ_CLEARBASS* disp_obj, BOOL state)
{
  disp_obj->preset = state;
}

void GUI_Clearbass_Switch(GUI* gui, BOOL state)
{
  DispObj_Clearbass_Switch((DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui), state);
}

void DispObj_Clearbass_SetCursorToItem(DISP_OBJ_CLEARBASS* disp_obj, int cursor)
{
  disp_obj->cursor = cursor;
}

void GUI_Clearbass_SetCursorToItem(GUI* gui, int item)
{
  DispObj_Clearbass_SetCursorToItem((DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui), item);
}

void DispObj_Clearbass_SetTitleText(DISP_OBJ_CLEARBASS* disp_obj, TEXTID title)
{
  disp_obj->Title = title;
}

void GUI_Clearbass_SetTitleText(GUI* gui, TEXTID title)
{
  DispObj_Clearbass_SetTitleText((DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui), title);
}

void DrawString_Params(int font, TEXTID text , int align, int XPos, int YPos, int width ,int NormalColor)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString( text, font, align, XPos, YPos, XPos+width, YPos+(font&0xFF), NormalColor);
#else
  SetFont(font);
  DrawString( text, align, XPos, YPos, XPos+width, YPos+(font&0xFF), 0, 0, NormalColor, clEmpty);
#endif
}

void DrawImage(int xpos, int ypos, int width, int height, IMAGEID imageID)
{
#if defined (DB3200) || defined (DB3210)
  if(imageID!=NOIMAGE) dll_GC_PutChar(get_DisplayGC(),
                                      xpos,
                                      ypos,
                                      width,
                                      height,
                                      imageID );
#else
  if(imageID!=NOIMAGE) GC_PutChar(get_DisplayGC(),
                                  xpos,
                                  ypos,
                                  width,
                                  height,
                                  imageID);
#endif
}

int ClearbassGUI_OnCreate(DISP_OBJ_CLEARBASS* disp_obj)
{
  disp_obj->width = Display_GetWidth(UIDisplay_Main);
  disp_obj->height = Display_GetHeight(UIDisplay_Main);
  
  disp_obj->preset = TRUE;
  disp_obj->cursor = 0;
  disp_obj->Title = EMPTY_TEXTID;
  disp_obj->PresetName = EMPTY_TEXTID;
  LoadImage(disp_obj);
  
  DispObject_SetRefreshTimer(disp_obj, 1000);
  return 1;
}

void ClearbassGUI_OnClose(DISP_OBJ_CLEARBASS* disp_obj)
{
  disp_obj->width = 0;
  disp_obj->height = 0;
  disp_obj->cursor = 0;
  
  TEXT_FREE(disp_obj->PresetName);
  UnRegisterImage(disp_obj);
  
  DispObject_KillRefreshTimer(disp_obj);
}

void ClearbassGUI_OnRedraw(DISP_OBJ_CLEARBASS* disp_obj, int r1, int r2, int r3)
{
  GC *pGC = get_DisplayGC();
 
  if(disp_obj->preset)
  {
#if defined(DB3200) || defined(DB3210)
    int img_w = dll_GetImageWidth( disp_obj->Image[disp_obj->cursor].ID );
    int img_h = dll_GetImageHeight( disp_obj->Image[disp_obj->cursor].ID );
#else
    int img_w = GetImageWidth( disp_obj->Image[disp_obj->cursor].ID );
    int img_h = GetImageHeight( disp_obj->Image[disp_obj->cursor].ID );
#endif
    DrawImage(division((disp_obj->width-img_w),2),
              division((disp_obj->height-img_h),2),
              img_w,
              img_h,
              disp_obj->Image[disp_obj->cursor].ID );
    /*
    DrawString_Params(FONT_E_24R,
                      TEXT_EQUALIZER,
                      UITextAlignment_Center,
                      0,
                      division(disp_obj->height,20),
                      disp_obj->width,
                      clWhite);
    */
    DrawString_Params(FONT_E_22R,
                      DispObj_Clearbass_GetPresetName(disp_obj),
                      UITextAlignment_Center,
                      0,
                      division(disp_obj->height,8),
                      disp_obj->width,
                      clWhite);
    
    TEXT_FREE(disp_obj->PresetName);
  }
  else
  {
#if defined(DB3200) || defined(DB3210)
    int img_w = dll_GetImageWidth( disp_obj->Image[disp_obj->cursor].ID );
    int img_h = dll_GetImageHeight( disp_obj->Image[disp_obj->cursor].ID );
#else
    int img_w = GetImageWidth( disp_obj->Image[disp_obj->cursor].ID );
    int img_h = GetImageHeight( disp_obj->Image[disp_obj->cursor].ID );
#endif
    DrawImage(division((disp_obj->width-img_w),2),
              division((disp_obj->height-img_h),2),
              img_w,
              img_h,
              disp_obj->Image[9].ID );
  }
  DrawString_Params(FONT_E_24R,
                    disp_obj->Title,
                    UITextAlignment_Center,
                    0,
                    division(disp_obj->height,20),
                    disp_obj->width,
                    clWhite);
}

void ClearbassGUI_OnKey(DISP_OBJ_CLEARBASS* disp_obj, int key, int unk, int repeat, int mode)
{
  GUI* ClearbassGUI = DispObject_GetGUI( disp_obj );
  MusicApplication_Book *MusicBook = (MusicApplication_Book*)GUIObject_GetBook( ClearbassGUI );
  
  if(disp_obj->preset==1)
  {
    if(mode==KBD_SHORT_PRESS || mode==KBD_REPEAT)
    {
      switch(key)
      {
      case KEY_RIGHT:
        if(disp_obj->cursor < Eq_Bass) disp_obj->cursor++;
        else disp_obj->cursor = Eq_Treble;
        Set_ClearbassPreset(MusicBook,disp_obj->cursor);
        break;
      case KEY_LEFT:
        if(disp_obj->cursor > Eq_Treble) disp_obj->cursor--;
        else disp_obj->cursor = Eq_Bass;
        Set_ClearbassPreset(MusicBook,disp_obj->cursor);
        break;
      }
    }
  }
  else
  {
  }
  DispObject_InvalidateRect(disp_obj, NULL);
}

void ClearbassGUI_OnLayout(DISP_OBJ_CLEARBASS* disp_obj, void* layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clBlack);
}

void ClearbassGUI_OnRefresh(DISP_OBJ_CLEARBASS* disp_obj)
{
  DispObject_InvalidateRect(disp_obj, NULL);
  DispObject_SetRefreshTimer(disp_obj, 1000);
}

void ClearbassGUI_constr(DISP_DESC* desc)
{
  DISP_DESC_SetName(desc, Gui_Clearbass);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_CLEARBASS));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD) ClearbassGUI_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD) ClearbassGUI_OnClose );
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD) ClearbassGUI_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD) ClearbassGUI_OnKey);
  DISP_DESC_SetOnRefresh( desc, (DISP_OBJ_METHOD) ClearbassGUI_OnRefresh);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD) ClearbassGUI_OnLayout);
}

void ClearbassGUI_destr( GUI* desc )
{
}

GUI* Create_ClearbassGUI(BOOK* book)
{
  GUI* gui_cb = (GUI*)malloc(sizeof(GUI));
  if(!GUIObject_Create(gui_cb, ClearbassGUI_destr, ClearbassGUI_constr, book, NULL, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(gui_cb);
    return NULL;
  }
  if(book) BookObj_AddGUIObject(book,gui_cb);
  
  GUI_Clearbass_SetCursorToItem(gui_cb, Get_LastPreset());
  GUIObject_SetStyle(gui_cb, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_cb, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_cb);
 
  //GUIObject_SoftKeys_SetText(gui_cb, 1, STR("Get"));
  //GUIObject_SoftKeys_SetAction(gui_cb, 1, Get_EqGain);
  
  return gui_cb;
}
