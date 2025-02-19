#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"

#include "..\\include\Types.h"
#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "dll.h"
#include "Clearbass.h"
#include "main.h"

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ImageID = NOIMAGE;
  img->ImageHandle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->ImageHandle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->ImageHandle, path, fname, NULL, &img->ImageID, &error_code))
      if (error_code)
        img->ImageHandle = NOIMAGE;
}

void UnRegisterEQImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  if (disp_obj->Background.ImageID != NOIMAGE)
  {
    REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Background.ImageHandle, 0, 0, disp_obj->Background.ImageID, 1, &error_code);
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
    RegisterImage(&disp_obj->Background, CONFIG_PATH, BackgroundImage);
  else
    disp_obj->Background.ImageID = NOIMAGE;
}

void LoadBoostImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  const wchar_t *BoostImage[LastBoostLevel] =
      {
          L"BOOST_LEVEL1.png",
          L"BOOST_LEVEL2.png",
          L"BOOST_LEVEL3.png",
          L"BOOST_LEVEL4.png"};

  int i;
  for (i = 0; i < LastBoostLevel; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)BoostImage[i]))
      RegisterImage(&disp_obj->Boost_Image[i], CONFIG_PATH, (wchar_t *)BoostImage[i]);
    else
      disp_obj->Boost_Image[i].ImageID = NOIMAGE;
  }
}

void LoadBarImage(DISP_OBJ_CLEARBASS *disp_obj)
{
  const wchar_t *BarImage[LastBarLevel] =
      {
          L"BAR_MINUS3.png",
          L"BAR_MINUS2.png",
          L"BAR_MINUS1.png",
          L"BAR_NORMAL.png",
          L"BAR_PLUS1.png",
          L"BAR_PLUS2.png",
          L"BAR_PLUS3.png"};

  int i;
  for (i = 0; i < LastBarLevel; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)BarImage[i]))
      RegisterImage(&disp_obj->Bar_Image[i], CONFIG_PATH, (wchar_t *)BarImage[i]);
    else
      disp_obj->Bar_Image[i].ImageID = NOIMAGE;
  }
}

void DrawImage(int x, int y, IMAGEID img)
{
  if (img != NOIMAGE)
    dll_GC_PutChar(get_DisplayGC(), x, y, 0, 0, img);
}

void Clearbass_SetEqualizerGain(DISP_OBJ *disp)
{
  GUI *Clearbass = DispObject_GetGUI(disp);
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)GUIObject_GetBook(Clearbass);

  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)disp;

  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_63, (disp_obj->bar1_level - Bar_Netral) * (disp_obj->boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_250, (disp_obj->bar2_level - Bar_Netral) * (disp_obj->boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000, (disp_obj->bar3_level - Bar_Netral) * (disp_obj->boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_4000, (disp_obj->bar4_level - Bar_Netral) * (disp_obj->boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000, (disp_obj->bar5_level - Bar_Netral) * (disp_obj->boost_level + 2));
}

void GUIObject_Clearbass_SetBarLevel(GUI *gui, int32_t b0, int32_t b1, int32_t b2, int32_t b3, int32_t b4, int32_t b5)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  disp_obj->boost_level = b0;
  disp_obj->bar1_level = b1;
  disp_obj->bar2_level = b2;
  disp_obj->bar3_level = b3;
  disp_obj->bar4_level = b4;
  disp_obj->bar5_level = b5;
  Clearbass_SetEqualizerGain(disp_obj);
}

int GUIObject_Clearbass_GetCursor(GUI *gui)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  return disp_obj->cursor;
}

void GUIObject_Clearbass_GetBarLevel(GUI *gui, int32_t *b0, int32_t *b1, int32_t *b2, int32_t *b3, int32_t *b4, int32_t *b5)
{
  DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
  *b0 = disp_obj->boost_level;
  *b1 = disp_obj->bar1_level;
  *b2 = disp_obj->bar2_level;
  *b3 = disp_obj->bar3_level;
  *b4 = disp_obj->bar4_level;
  *b5 = disp_obj->bar5_level;
}

int ClearbassGUI_OnCreate(DISP_OBJ_CLEARBASS *disp_obj)
{
  disp_obj->width = Display_GetWidth(UIDisplay_Main);
  disp_obj->height = Display_GetHeight(UIDisplay_Main);

  disp_obj->cursor = Eq_Band0;

  disp_obj->boost_level = Boost_0;
  disp_obj->bar1_level = Bar_Netral;
  disp_obj->bar2_level = Bar_Netral;
  disp_obj->bar3_level = Bar_Netral;
  disp_obj->bar4_level = Bar_Netral;
  disp_obj->bar5_level = Bar_Netral;

  LoadBackgroundImage(disp_obj);
  LoadBarImage(disp_obj);
  LoadBoostImage(disp_obj);

  return 1;
}

void ClearbassGUI_OnClose(DISP_OBJ_CLEARBASS *disp_obj)
{
  disp_obj->width = NULL;
  disp_obj->height = NULL;

  disp_obj->boost_level = NULL;
  disp_obj->bar1_level = NULL;
  disp_obj->bar2_level = NULL;
  disp_obj->bar3_level = NULL;
  disp_obj->bar4_level = NULL;
  disp_obj->bar5_level = NULL;

  UnRegisterEQImage(disp_obj);
}

void ClearbassGUI_OnRedraw(DISP_OBJ_CLEARBASS *disp_obj, int r1, int r2, int r3)
{
  DrawImage(0, 22,
            disp_obj->Background.ImageID);

  DrawImage(14, 96,
            disp_obj->Boost_Image[disp_obj->boost_level].ImageID);

  DrawImage(75, 96,
            disp_obj->Bar_Image[disp_obj->bar1_level].ImageID);

  DrawImage(106, 96,
            disp_obj->Bar_Image[disp_obj->bar2_level].ImageID);

  DrawImage(137, 96,
            disp_obj->Bar_Image[disp_obj->bar3_level].ImageID);

  DrawImage(168, 96,
            disp_obj->Bar_Image[disp_obj->bar4_level].ImageID);

  DrawImage(199, 96,
            disp_obj->Bar_Image[disp_obj->bar5_level].ImageID);

  DrawRect(redrect_positions[disp_obj->cursor][0],
           redrect_positions[disp_obj->cursor][1],
           redrect_positions[disp_obj->cursor][0] + redrect_positions[disp_obj->cursor][2],
           redrect_positions[disp_obj->cursor][1] + redrect_positions[disp_obj->cursor][3],
           clEmpty, 0xFFF23F22);

  dll_DrawString(FONT_E_20R, EQUALIZER_TXT, AlignCenter, 0, 40, disp_obj->width, 60, clWhite);
}

void ClearbassGUI_OnKey(DISP_OBJ_CLEARBASS *disp_obj, int key, int count, int repeat, int mode)
{
  if (mode == KBD_SHORT_PRESS || mode == KBD_REPEAT)
  {
    switch (key)
    {
    case KEY_RIGHT:
      if (disp_obj->cursor < Eq_Band5)
        disp_obj->cursor++;
      else
        disp_obj->cursor = Eq_Band5;
      break;
    case KEY_LEFT:
      if (disp_obj->cursor > Eq_Band0)
        disp_obj->cursor--;
      else
        disp_obj->cursor = Eq_Band0;
      break;
    case KEY_UP:
      if (disp_obj->cursor == Eq_Band0)
      {
        if (disp_obj->boost_level < Boost_3)
          disp_obj->boost_level++;
        else
          disp_obj->boost_level = Boost_3;
      }
      else if (disp_obj->cursor == Eq_Band1)
      {
        if (disp_obj->bar1_level < Bar_Plus_3)
          disp_obj->bar1_level++;
        else
          disp_obj->bar1_level = Bar_Plus_3;
      }
      else if (disp_obj->cursor == Eq_Band2)
      {
        if (disp_obj->bar2_level < Bar_Plus_3)
          disp_obj->bar2_level++;
        else
          disp_obj->bar2_level = Bar_Plus_3;
      }
      else if (disp_obj->cursor == Eq_Band3)
      {
        if (disp_obj->bar3_level < Bar_Plus_3)
          disp_obj->bar3_level++;
        else
          disp_obj->bar3_level = Bar_Plus_3;
      }
      else if (disp_obj->cursor == Eq_Band4)
      {
        if (disp_obj->bar4_level < Bar_Plus_3)
          disp_obj->bar4_level++;
        else
          disp_obj->bar4_level = Bar_Plus_3;
      }
      else if (disp_obj->cursor == Eq_Band5)
      {
        if (disp_obj->bar5_level < Bar_Plus_3)
          disp_obj->bar5_level++;
        else
          disp_obj->bar5_level = Bar_Plus_3;
      }
      break;
    case KEY_DOWN:
      if (disp_obj->cursor == Eq_Band0)
      {
        if (disp_obj->boost_level > Boost_0)
          disp_obj->boost_level--;
        else
          disp_obj->boost_level = Boost_0;
      }
      else if (disp_obj->cursor == Eq_Band1)
      {
        if (disp_obj->bar1_level > Bar_Minus_3)
          disp_obj->bar1_level--;
        else
          disp_obj->bar1_level = Bar_Minus_3;
      }
      else if (disp_obj->cursor == Eq_Band2)
      {
        if (disp_obj->bar2_level > Bar_Minus_3)
          disp_obj->bar2_level--;
        else
          disp_obj->bar2_level = Bar_Minus_3;
      }
      else if (disp_obj->cursor == Eq_Band3)
      {
        if (disp_obj->bar3_level > Bar_Minus_3)
          disp_obj->bar3_level--;
        else
          disp_obj->bar3_level = Bar_Minus_3;
      }
      else if (disp_obj->cursor == Eq_Band4)
      {
        if (disp_obj->bar4_level > Bar_Minus_3)
          disp_obj->bar4_level--;
        else
          disp_obj->bar4_level = Bar_Minus_3;
      }
      else if (disp_obj->cursor == Eq_Band5)
      {
        if (disp_obj->bar5_level > Bar_Minus_3)
          disp_obj->bar5_level--;
        else
          disp_obj->bar5_level = Bar_Minus_3;
      }
      break;
    }
    Clearbass_SetEqualizerGain(disp_obj);
    DispObject_InvalidateRect(disp_obj, NULL);
  }
}

void ClearbassGUI_OnLayout(DISP_OBJ_CLEARBASS *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clEmpty);
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

  GUIObject_SetTitleType(gui_cb, UI_TitleMode_None);
  GUIObject_SetStyle(gui_cb, UI_OverlayStyle_FullScreenNoStatus);
  GUIObject_SoftKeys_RemoveBackground(gui_cb);

  return gui_cb;
}
