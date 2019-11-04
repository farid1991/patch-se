#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "..\\include\book\MusicApplication_book.h"

#include "image.h"
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
  return TextID_Create(PresetNames[disp_obj->preset_cursor], ENC_UCS2, TEXTID_ANY_LEN);
}

void GUIObject_Clearbass_SetBarLevel(GUI* gui, int b0, int b1, int b2, int b3, int b4, int b5)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  
  disp_obj->boost_level = b0;
  disp_obj->bar1_level = b1;
  disp_obj->bar2_level = b2;
  disp_obj->bar3_level = b3;
  disp_obj->bar4_level = b4;
  disp_obj->bar5_level = b5;
}

void GUIObject_Clearbass_GetBarLevel(GUI* gui, int *b0, int *b1, int *b2, int *b3, int *b4, int *b5)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  
  *b0 = disp_obj->boost_level;
  *b1 = disp_obj->bar1_level;
  *b2 = disp_obj->bar2_level;
  *b3 = disp_obj->bar3_level;
  *b4 = disp_obj->bar4_level;
  *b5 = disp_obj->bar5_level;
}

void GUIObject_Clearbass_SetState(GUI* gui, BOOL manual)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);

  disp_obj->manual = manual;
}

BOOL GUIObject_Clearbass_GetState(GUI* gui)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  
  return disp_obj->manual ? TRUE : FALSE;
}

int GUIObject_Clearbass_GetPresetCursor(GUI* gui)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  
  return (disp_obj->preset_cursor);
}

void GUIObject_Clearbass_Switch(GUI* gui, BOOL state)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  disp_obj->manual = state;
}

void GUIObject_Clearbass_SetCursorToItem(GUI* gui, int item)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  disp_obj->preset_cursor = item;
}

void GUIObject_Clearbass_SetTitleText(GUI* gui, TEXTID title)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui);
  disp_obj->Title = title;
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
  GC_DrawImage( xpos, ypos, imageID );
#endif
}

int ClearbassGUI_OnCreate(DISP_OBJ_CLEARBASS* disp_obj)
{
  disp_obj->width = Display_GetWidth(UIDisplay_Main);
  disp_obj->height = Display_GetHeight(UIDisplay_Main);
  
  disp_obj->preset_cursor = Eq_Normal;
  disp_obj->manual_cursor = 0;
  
  disp_obj->boost_level = Boost_1;
  disp_obj->bar1_level = Bar_Netral;
  disp_obj->bar2_level = Bar_Netral;
  disp_obj->bar3_level = Bar_Netral;
  disp_obj->bar4_level = Bar_Netral;
  disp_obj->bar5_level = Bar_Netral;
  
  disp_obj->level.bar1 = 0;
  disp_obj->level.bar2 = 0;
  disp_obj->level.bar3 = 0;
  disp_obj->level.bar4 = 0;
  disp_obj->level.bar5 = 0;
  
  disp_obj->manual = FALSE;
  
  disp_obj->Title = EMPTY_TEXTID;
  disp_obj->PresetName = EMPTY_TEXTID;
  
  LoadPresetImage(disp_obj);
  LoadBackgroundImage(disp_obj);
  LoadBarImage(disp_obj);
  LoadBoostImage(disp_obj);
  
  DispObject_SetRefreshTimer(disp_obj, 1000);
  return 1;
}

void ClearbassGUI_OnClose(DISP_OBJ_CLEARBASS* disp_obj)
{
  disp_obj->width = 0;
  disp_obj->height = 0;
  
  disp_obj->preset_cursor = 0;
  disp_obj->manual_cursor = 0;
  
  disp_obj->boost_level = 0;
  disp_obj->bar1_level = 0;
  disp_obj->bar2_level = 0;
  disp_obj->bar3_level = 0;
  disp_obj->bar4_level = 0;
  disp_obj->bar5_level = 0;
  
  disp_obj->level.bar1 = 0;
  disp_obj->level.bar2 = 0;
  disp_obj->level.bar3 = 0;
  disp_obj->level.bar4 = 0;
  disp_obj->level.bar5 = 0;
  
  TEXT_FREE(disp_obj->PresetName);
  UnRegisterImage(disp_obj);
  
  DispObject_KillRefreshTimer(disp_obj);
}

void ClearbassGUI_OnRedraw(DISP_OBJ_CLEARBASS* disp_obj, int r1, int r2, int r3)
{
  if(disp_obj->manual) // Manual
  {
    DrawImage(0,
              22,
              0,
              0,
              disp_obj->Background.ID );
    
    DrawImage(14,
              96,
              0,
              0,
              disp_obj->Boost_Image[disp_obj->boost_level].ID );
    
    DrawImage(75,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar1_level].ID );
    
    DrawImage(106,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar2_level].ID );
    
    DrawImage(137,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar3_level].ID );
    
    DrawImage(168,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar4_level].ID );
    
    DrawImage(199,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar5_level].ID );
    
    DrawRect(redrect_positions[disp_obj->manual_cursor][0],
             redrect_positions[disp_obj->manual_cursor][1], 
             redrect_positions[disp_obj->manual_cursor][0] + redrect_positions[disp_obj->manual_cursor][2],
             redrect_positions[disp_obj->manual_cursor][1] + redrect_positions[disp_obj->manual_cursor][3],
             0x00000000, 0xFFF23F22 );
    
    wchar_t buf[32];
    snwprintf(buf,MAXELEMS(buf),L"%d %d %d %d %d %d",
              (disp_obj->boost_level),
              (disp_obj->bar1_level-3) * (disp_obj->boost_level+1),
              (disp_obj->bar2_level-3),
              (disp_obj->bar3_level-3),
              (disp_obj->bar4_level-3),
              (disp_obj->bar5_level-3) * (disp_obj->boost_level+1) );
    int textid = TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
    
    DrawString_Params(FONT_E_20R,
                      textid,
                      UITextAlignment_Center,
                      0,
                      division(disp_obj->height,8),
                      disp_obj->width,
                      clWhite);
    TEXT_FREE(textid);
  }
  else // Preset
  {
    DrawImage(0,
              12,
              0,
              0,
              disp_obj->Preset_Image[disp_obj->preset_cursor].ID );

    DrawString_Params(FONT_E_20R,
                      DispObj_Clearbass_GetPresetName(disp_obj),
                      UITextAlignment_Center,
                      0,
                      division(disp_obj->height,8),
                      disp_obj->width,
                      clWhite);
    
    TEXT_FREE(disp_obj->PresetName);
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
  
  if(mode==KBD_SHORT_PRESS || mode==KBD_REPEAT)
  {
    if(disp_obj->manual)
    {
      switch(key)
      {
      case KEY_RIGHT:
        if (disp_obj->manual_cursor < Eq_Band5) disp_obj->manual_cursor++;
        else disp_obj->manual_cursor = Eq_Band5;
        break;
      case KEY_LEFT:
        if (disp_obj->manual_cursor > Eq_Band0) disp_obj->manual_cursor--;
        else disp_obj->manual_cursor = Eq_Band0;
        break;
      case KEY_UP:
        if( disp_obj->manual_cursor == Eq_Band0)
        {
          if ( disp_obj->boost_level < Boost_3) disp_obj->boost_level++;
          else disp_obj->boost_level = Boost_3;
          
          disp_obj->level.boost = disp_obj->boost_level;
          disp_obj->level.bar1 = (disp_obj->bar1_level-3) * (disp_obj->boost_level+1);
          disp_obj->level.bar5 = (disp_obj->bar5_level-3) * (disp_obj->boost_level+1);
          
          Set_EqualiserGain(MusicBook, Eq_Band0, disp_obj->level.boost);
          Set_EqualiserGain(MusicBook, Eq_Band1, disp_obj->level.bar1);
          Set_EqualiserGain(MusicBook, Eq_Band5, disp_obj->level.bar5);
        }
        else if( disp_obj->manual_cursor == Eq_Band1)
        {
          if ( disp_obj->bar1_level < Bar_Plus_3) disp_obj->bar1_level++;
          else disp_obj->bar1_level = Bar_Plus_3;
          
          disp_obj->level.bar1 = (disp_obj->bar1_level-3) * (disp_obj->boost_level+1);
          Set_EqualiserGain(MusicBook, Eq_Band1, disp_obj->level.bar1);
        }
        else if( disp_obj->manual_cursor == Eq_Band2)
        {
          if ( disp_obj->bar2_level < Bar_Plus_3) disp_obj->bar2_level++;
          else disp_obj->bar2_level = Bar_Plus_3;
          
          disp_obj->level.bar2 = (disp_obj->bar2_level-3);
          Set_EqualiserGain(MusicBook, Eq_Band2, disp_obj->level.bar2);
        }
        else if( disp_obj->manual_cursor == Eq_Band3)
        {
          if ( disp_obj->bar3_level < Bar_Plus_3) disp_obj->bar3_level++;
          else disp_obj->bar3_level = Bar_Plus_3;
          
          disp_obj->level.bar3 = (disp_obj->bar3_level-3);
          Set_EqualiserGain(MusicBook, Eq_Band3, disp_obj->level.bar3);
        }
        else if( disp_obj->manual_cursor == Eq_Band4)
        {
          if ( disp_obj->bar4_level < Bar_Plus_3) disp_obj->bar4_level++;
          else disp_obj->bar4_level = Bar_Plus_3;
          
          disp_obj->level.bar4 = (disp_obj->bar4_level-3);
          Set_EqualiserGain(MusicBook, Eq_Band4, disp_obj->level.bar4);
        }
        else if( disp_obj->manual_cursor == Eq_Band5)
        {
          if ( disp_obj->bar5_level < Bar_Plus_3) disp_obj->bar5_level++;
          else disp_obj->bar5_level = Bar_Plus_3;
          
          disp_obj->level.bar5 = (disp_obj->bar5_level-3) * (disp_obj->boost_level+1);
          Set_EqualiserGain(MusicBook, Eq_Band5, disp_obj->level.bar5);
        }
        break;
      case KEY_DOWN:
        if( disp_obj->manual_cursor == Eq_Band0)
        {
          if ( disp_obj->boost_level > Boost_0) disp_obj->boost_level--;
          else disp_obj->boost_level = Boost_0;
          
          disp_obj->level.boost = disp_obj->boost_level;
          disp_obj->level.bar1 = (disp_obj->bar1_level-3) * (disp_obj->boost_level+1);
          disp_obj->level.bar5 = (disp_obj->bar5_level-3) * (disp_obj->boost_level+1);
          
          Set_EqualiserGain(MusicBook, Eq_Band0, disp_obj->level.boost);
          Set_EqualiserGain(MusicBook, Eq_Band1, disp_obj->level.bar1);
          Set_EqualiserGain(MusicBook, Eq_Band5, disp_obj->level.bar5);
        }
        else if( disp_obj->manual_cursor == Eq_Band1)
        {
          if ( disp_obj->bar1_level > Bar_Minus_3) disp_obj->bar1_level--;
          else disp_obj->bar1_level = Bar_Minus_3;
          
          disp_obj->level.bar1 = (disp_obj->bar1_level-3) * (disp_obj->boost_level+1);
          Set_EqualiserGain(MusicBook, Eq_Band1, disp_obj->level.bar1);
        }
        else if( disp_obj->manual_cursor == Eq_Band2)
        {
          if ( disp_obj->bar2_level > Bar_Minus_3) disp_obj->bar2_level--;
          else disp_obj->bar2_level = Bar_Minus_3;
          
          disp_obj->level.bar2 = (disp_obj->bar2_level-3);
          Set_EqualiserGain(MusicBook, Eq_Band2, disp_obj->level.bar2);
        }
        else if( disp_obj->manual_cursor == Eq_Band3)
        {
          if ( disp_obj->bar3_level > Bar_Minus_3) disp_obj->bar3_level--;
          else disp_obj->bar3_level = Bar_Minus_3;
          
          disp_obj->level.bar3 = (disp_obj->bar3_level-3);
          Set_EqualiserGain(MusicBook, Eq_Band3, disp_obj->level.bar3);
        }
        else if( disp_obj->manual_cursor == Eq_Band4)
        {
          if ( disp_obj->bar4_level > Bar_Minus_3) disp_obj->bar4_level--;
          else disp_obj->bar4_level = Bar_Minus_3;
          
          disp_obj->level.bar4 = (disp_obj->bar4_level-3);
          Set_EqualiserGain(MusicBook, Eq_Band4, disp_obj->level.bar4);
        }
        else if( disp_obj->manual_cursor == Eq_Band5)
        {
          if ( disp_obj->bar5_level > Bar_Minus_3) disp_obj->bar5_level--;
          else disp_obj->bar5_level = Bar_Minus_3;
          
          disp_obj->level.bar5 = (disp_obj->bar5_level-3) * (disp_obj->boost_level+1);
          Set_EqualiserGain(MusicBook, Eq_Band5, disp_obj->level.bar5);
        }
        break;
      }
    }
    else
    {
      switch(key)
      {
      case KEY_RIGHT:
        if(disp_obj->preset_cursor < Eq_Bass) disp_obj->preset_cursor++;
        else disp_obj->preset_cursor = Eq_Treble;
        break;
      case KEY_LEFT:
        if(disp_obj->preset_cursor > Eq_Treble) disp_obj->preset_cursor--;
        else disp_obj->preset_cursor = Eq_Bass;
        break;
      }
      SetEqualizerGain(MusicBook, 
                       settings_table[disp_obj->preset_cursor][Eq_Band0], 
                       settings_table[disp_obj->preset_cursor][Eq_Band1],
                       settings_table[disp_obj->preset_cursor][Eq_Band2],
                       settings_table[disp_obj->preset_cursor][Eq_Band3], 
                       settings_table[disp_obj->preset_cursor][Eq_Band4], 
                       settings_table[disp_obj->preset_cursor][Eq_Band5] );
    }
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
  
  GUIObject_SetStyle(gui_cb, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_cb, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_cb);
 
  return gui_cb;
}
