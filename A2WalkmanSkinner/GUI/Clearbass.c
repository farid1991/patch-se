#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\Color.h"

#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\Function.h"

#include "..\\Pages\Equalizer.h"
#include "Clearbass.h"

void UnRegisterEQImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  if (disp_obj->Background.ImageID != NOIMAGE)
  {
    REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Background.ImageHandle, 0, 0, disp_obj->Background.ImageID, 1, &error_code);
  }

  for (int i = 0; i < LastPreset; i++)
  {
    if (disp_obj->Preset_Image[i].ImageID != NOIMAGE)
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Preset_Image[i].ImageHandle, 0, 0, disp_obj->Preset_Image[i].ImageID, 1, &error_code);
    }
  }
  for (int j = 0; j < LastBoostLevel; j++)
  {
    if (disp_obj->Boost_Image[j].ImageID != NOIMAGE)
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Boost_Image[j].ImageHandle, 0, 0, disp_obj->Boost_Image[j].ImageID, 1, &error_code);
    }
  }
  for (int k = 0; k < LastBarLevel; k++)
  {
    if (disp_obj->Bar_Image[k].ImageID != NOIMAGE)
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Bar_Image[k].ImageHandle, 0, 0, disp_obj->Bar_Image[k].ImageID, TRUE, &error_code);
    }
  }
}

void LoadBackgroundImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  wchar_t *BackgroundImage = L"MP_EQ_BACKGROUND_V_ICN.png";

  if (FSX_IsFileExists(CONFIG_PATH, BackgroundImage))
  {
    RegisterImage(&disp_obj->Background, CONFIG_PATH, BackgroundImage);
  }
  else
    disp_obj->Background.ImageID = NOIMAGE;
}

void LoadPresetImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  const wchar_t *ImagePreset[LastPreset] =
      {
          L"MP_EQ_TREBLE_H_ICN.png", // 0
          L"MP_EQ_HEAVY_H_ICN.png",  // 1
          L"MP_EQ_POP_H_ICN.png",    // 2
          L"MP_EQ_JAZZ_H_ICN.png",   // 3
          L"MP_EQ_NORMAL_H_ICN.png", // 4
          L"MP_EQ_UNIQUE_H_ICN.png", // 5
          L"MP_EQ_SOUL_H_ICN.png",   // 6
          L"MP_EQ_LIGHT_H_ICN.png",  // 7
          L"MP_EQ_BASS_H_ICN.png"    // 8
      };

  int i;
  for (i = 0; i < LastPreset; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)ImagePreset[i]))
    {
      RegisterImage(&disp_obj->Preset_Image[i], CONFIG_PATH, (wchar_t *)ImagePreset[i]);
    }
    else
      disp_obj->Preset_Image[i].ImageID = NOIMAGE;
  }
}

void LoadBoostImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  const wchar_t *BoostImage[LastBoostLevel] =
      {
          L"BOOST_LEVEL1.png", // 0
          L"BOOST_LEVEL2.png", // 1
          L"BOOST_LEVEL3.png", // 2
          L"BOOST_LEVEL4.png"  // 3
      };

  int i;
  for (i = 0; i < LastBoostLevel; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)BoostImage[i]))
    {
      RegisterImage(&disp_obj->Boost_Image[i], CONFIG_PATH, (wchar_t *)BoostImage[i]);
    }
    else
      disp_obj->Boost_Image[i].ImageID = NOIMAGE;
  }
}

void LoadBarImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  const wchar_t *BarImage[LastBarLevel] =
      {
          L"BAR_MINUS3.png", // 0
          L"BAR_MINUS2.png", // 1
          L"BAR_MINUS1.png", // 2
          L"BAR_NORMAL.png", // 3
          L"BAR_PLUS1.png",  // 4
          L"BAR_PLUS2.png",  // 5
          L"BAR_PLUS3.png"   // 6
      };

  int i;
  for (i = 0; i < LastBarLevel; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)BarImage[i]))
    {
      RegisterImage(&disp_obj->Bar_Image[i], CONFIG_PATH, (wchar_t *)BarImage[i]);
    }
    else
      disp_obj->Bar_Image[i].ImageID = NOIMAGE;
  }
}

TEXTID DispObj_Clearbass_GetPresetName(DISP_OBJ_CLEARBASS *disp_obj)
{
  const wchar_t *PresetNames[LastPreset] =
      {
          L"Treble",
          L"Heavy",
          L"Pop",
          L"Jazz",
          L"Normal",
          L"Unique",
          L"Soul",
          L"Light",
          L"Bass"};
  return TextID_Create(PresetNames[disp_obj->preset_cursor], ENC_UCS2, TEXTID_ANY_LEN);
}

void SetEqualizer(DISP_OBJ_CLEARBASS *disp_obj)
{
  GUI *ClearbassGUI = DispObject_GetGUI(disp_obj);
  BOOK *MusicBook = GUIObject_GetBook(ClearbassGUI);
  if (disp_obj->manual)
  {
    SetEqualizerBands(MusicBook,
                      disp_obj->boost_level,
                      (disp_obj->bar1_level - Bar_Netral),
                      (disp_obj->bar2_level - Bar_Netral),
                      (disp_obj->bar3_level - Bar_Netral),
                      (disp_obj->bar4_level - Bar_Netral),
                      (disp_obj->bar5_level - Bar_Netral));
  }
  else
  {
    SetEqualizerBands(MusicBook,
                      settings_table[disp_obj->preset_cursor][Eq_Band0],
                      settings_table[disp_obj->preset_cursor][Eq_Band1],
                      settings_table[disp_obj->preset_cursor][Eq_Band2],
                      settings_table[disp_obj->preset_cursor][Eq_Band3],
                      settings_table[disp_obj->preset_cursor][Eq_Band4],
                      settings_table[disp_obj->preset_cursor][Eq_Band5]);
  }
}

void GUIObject_Clearbass_SetBarLevel(GUI *gui, int b0, int b1, int b2, int b3, int b4, int b5)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  disp_obj->boost_level = b0;
  disp_obj->bar1_level = b1;
  disp_obj->bar2_level = b2;
  disp_obj->bar3_level = b3;
  disp_obj->bar4_level = b4;
  disp_obj->bar5_level = b5;
}

void GUIObject_Clearbass_GetBarLevel(GUI *gui, int *b0, int *b1, int *b2, int *b3, int *b4, int *b5)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  *b0 = disp_obj->boost_level;
  *b1 = disp_obj->bar1_level;
  *b2 = disp_obj->bar2_level;
  *b3 = disp_obj->bar3_level;
  *b4 = disp_obj->bar4_level;
  *b5 = disp_obj->bar5_level;
}

void GUIObject_Clearbass_SetState(GUI *gui, bool manual)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  disp_obj->manual = manual;
  SetEqualizer(disp_obj);
}

BOOL GUIObject_Clearbass_GetState(GUI *gui)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  return disp_obj->manual ? TRUE : FALSE;
}

int GUIObject_Clearbass_GetPresetCursor(GUI *gui)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  return disp_obj->preset_cursor;
}

void GUIObject_Clearbass_Switch(GUI *gui, bool state)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  disp_obj->manual = state;
  SetEqualizer(disp_obj);
  InvalidateRect(disp_obj);
}

void GUIObject_Clearbass_SetCursorToItem(GUI *gui, int item)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  disp_obj->preset_cursor = item;
}

int ClearbassGUI_OnCreate(DISP_OBJ_CLEARBASS *disp_obj)
{
  disp_obj->width = Display_GetWidth(UIDisplay_Main);
  disp_obj->height = Display_GetHeight(UIDisplay_Main);

  disp_obj->preset_cursor = Eq_Normal;
  disp_obj->manual_cursor = Eq_Band0;

  disp_obj->boost_level = Boost_0;
  disp_obj->bar1_level = Bar_Netral;
  disp_obj->bar2_level = Bar_Netral;
  disp_obj->bar3_level = Bar_Netral;
  disp_obj->bar4_level = Bar_Netral;
  disp_obj->bar5_level = Bar_Netral;

  disp_obj->manual = FALSE;

  disp_obj->PresetName = EMPTY_TEXTID;

  LoadPresetImage(disp_obj);
  LoadBackgroundImage(disp_obj);
  LoadBarImage(disp_obj);
  LoadBoostImage(disp_obj);

  return 1;
}

void ClearbassGUI_OnClose(DISP_OBJ_CLEARBASS *disp_obj)
{
  disp_obj->width = NULL;
  disp_obj->height = NULL;

  disp_obj->preset_cursor = NULL;
  disp_obj->manual_cursor = NULL;

  disp_obj->boost_level = NULL;
  disp_obj->bar1_level = NULL;
  disp_obj->bar2_level = NULL;
  disp_obj->bar3_level = NULL;
  disp_obj->bar4_level = NULL;
  disp_obj->bar5_level = NULL;

  DESTROY_TEXTID(disp_obj->PresetName);
  UnRegisterEQImage(disp_obj);
}

void ClearbassGUI_OnRedraw(DISP_OBJ_CLEARBASS *disp_obj, int r1, int r2, int r3)
{
  GC *pGC = get_DisplayGC();
  if (disp_obj->manual) // Manual
  {
    DrawImage(pGC,
              0,
              22,
              0,
              0,
              disp_obj->Background.ImageID);

    DrawImage(pGC,
              14,
              96,
              0,
              0,
              disp_obj->Boost_Image[disp_obj->boost_level].ImageID);

    DrawImage(pGC,
              75,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar1_level].ImageID);

    DrawImage(pGC,
              106,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar2_level].ImageID);

    DrawImage(pGC,
              137,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar3_level].ImageID);

    DrawImage(pGC,
              168,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar4_level].ImageID);

    DrawImage(pGC,
              199,
              96,
              0,
              0,
              disp_obj->Bar_Image[disp_obj->bar5_level].ImageID);

    DrawRect(redrect_positions[disp_obj->manual_cursor][0],
             redrect_positions[disp_obj->manual_cursor][1],
             redrect_positions[disp_obj->manual_cursor][0] + redrect_positions[disp_obj->manual_cursor][2],
             redrect_positions[disp_obj->manual_cursor][1] + redrect_positions[disp_obj->manual_cursor][3],
             clEmpty, 0xFFF23F22);

    DrawString_Params(FONT_E_18R,
                      TEXT_MANUAL,
                      AlignCenter,
                      0,
                      division(disp_obj->height, 8),
                      disp_obj->width,
                      clWhite);
  }
  else // Preset
  {
    DrawImage(pGC,
              0,
              12,
              0,
              0,
              disp_obj->Preset_Image[disp_obj->preset_cursor].ImageID);

    DrawString_Params(FONT_E_18R,
                      DispObj_Clearbass_GetPresetName(disp_obj),
                      AlignCenter,
                      0,
                      division(disp_obj->height, 8),
                      disp_obj->width,
                      clWhite);

    DESTROY_TEXTID(disp_obj->PresetName);
  }

  DrawString_Params(FONT_E_20R,
                    TEXT_EQUALIZER,
                    AlignCenter,
                    0,
                    division(disp_obj->height, 20),
                    disp_obj->width,
                    clWhite);
}

void ClearbassGUI_OnKey(DISP_OBJ_CLEARBASS *disp_obj, int key, int count, int repeat, int mode)
{
  GUI *ClearbassGUI = DispObject_GetGUI(disp_obj);
  BOOK *MusicBook = GUIObject_GetBook(ClearbassGUI);

  if (mode == KBD_SHORT_PRESS || mode == KBD_REPEAT)
  {
    if (disp_obj->manual)
    {
      switch (key)
      {
      case KEY_RIGHT:
        if (disp_obj->manual_cursor < Eq_Band5)
          disp_obj->manual_cursor++;
        else
          disp_obj->manual_cursor = Eq_Band5;
        break;
      case KEY_LEFT:
        if (disp_obj->manual_cursor > Eq_Band0)
          disp_obj->manual_cursor--;
        else
          disp_obj->manual_cursor = Eq_Band0;
        break;
      case KEY_UP:
        if (disp_obj->manual_cursor == Eq_Band0)
        {
          if (disp_obj->boost_level < Boost_3)
            disp_obj->boost_level++;
          else
            disp_obj->boost_level = Boost_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band1)
        {
          if (disp_obj->bar1_level < Bar_Plus_3)
            disp_obj->bar1_level++;
          else
            disp_obj->bar1_level = Bar_Plus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band2)
        {
          if (disp_obj->bar2_level < Bar_Plus_3)
            disp_obj->bar2_level++;
          else
            disp_obj->bar2_level = Bar_Plus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band3)
        {
          if (disp_obj->bar3_level < Bar_Plus_3)
            disp_obj->bar3_level++;
          else
            disp_obj->bar3_level = Bar_Plus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band4)
        {
          if (disp_obj->bar4_level < Bar_Plus_3)
            disp_obj->bar4_level++;
          else
            disp_obj->bar4_level = Bar_Plus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band5)
        {
          if (disp_obj->bar5_level < Bar_Plus_3)
            disp_obj->bar5_level++;
          else
            disp_obj->bar5_level = Bar_Plus_3;
        }
        break;
      case KEY_DOWN:
        if (disp_obj->manual_cursor == Eq_Band0)
        {
          if (disp_obj->boost_level > Boost_0)
            disp_obj->boost_level--;
          else
            disp_obj->boost_level = Boost_0;
        }
        else if (disp_obj->manual_cursor == Eq_Band1)
        {
          if (disp_obj->bar1_level > Bar_Minus_3)
            disp_obj->bar1_level--;
          else
            disp_obj->bar1_level = Bar_Minus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band2)
        {
          if (disp_obj->bar2_level > Bar_Minus_3)
            disp_obj->bar2_level--;
          else
            disp_obj->bar2_level = Bar_Minus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band3)
        {
          if (disp_obj->bar3_level > Bar_Minus_3)
            disp_obj->bar3_level--;
          else
            disp_obj->bar3_level = Bar_Minus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band4)
        {
          if (disp_obj->bar4_level > Bar_Minus_3)
            disp_obj->bar4_level--;
          else
            disp_obj->bar4_level = Bar_Minus_3;
        }
        else if (disp_obj->manual_cursor == Eq_Band5)
        {
          if (disp_obj->bar5_level > Bar_Minus_3)
            disp_obj->bar5_level--;
          else
            disp_obj->bar5_level = Bar_Minus_3;
        }
        break;
      }
    }
    else
    {
      switch (key)
      {
      case KEY_RIGHT:
        if (disp_obj->preset_cursor < Eq_Bass)
          disp_obj->preset_cursor++;
        else
          disp_obj->preset_cursor = Eq_Treble;
        break;
      case KEY_LEFT:
        if (disp_obj->preset_cursor > Eq_Treble)
          disp_obj->preset_cursor--;
        else
          disp_obj->preset_cursor = Eq_Bass;
        break;
      }
    }
  }
  SetEqualizer(disp_obj);
  InvalidateRect(disp_obj);
}

void ClearbassGUI_OnLayout(DISP_OBJ_CLEARBASS *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clBlack);
}

void ClearbassGUI_constr(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_Clearbass);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_CLEARBASS));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)ClearbassGUI_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)ClearbassGUI_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)ClearbassGUI_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)ClearbassGUI_OnKey);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)ClearbassGUI_OnLayout);
}

void ClearbassGUI_destr(GUI *desc)
{
}

void ClearbassGUI_callback(DISP_OBJ *, void *msg, GUI *)
{
}

GUI *Create_ClearbassGUI(BOOK *book)
{
  GUI *gui_cb = (GUI *)malloc(sizeof(GUI));
  if (!GUIObject_Create(gui_cb, ClearbassGUI_destr, ClearbassGUI_constr, book, ClearbassGUI_callback, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(gui_cb);
    return NULL;
  }
  if (book)
    BookObj_AddGUIObject(book, gui_cb);

  GUIObject_SetStyle(gui_cb, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_cb, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_cb);

  return gui_cb;
}
