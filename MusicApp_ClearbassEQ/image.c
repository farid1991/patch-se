#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "visual.h"

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
  
  if (disp_obj->Background.ID != NOIMAGE)
  {
    REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Background.Handle, 0, 0, disp_obj->Background.ID, 1, &error_code);
  }
  
  for (int i = 0; i < LastPreset; i++)
  {
    if (disp_obj->Preset_Image[i].ID != NOIMAGE)
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Preset_Image[i].Handle, 0, 0, disp_obj->Preset_Image[i].ID, 1, &error_code);
    }
  }
  for (int j = 0; j < LastBoostLevel; j++)
  {
    if (disp_obj->Boost_Image[j].ID != NOIMAGE)
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Boost_Image[j].Handle, 0, 0, disp_obj->Boost_Image[j].ID, 1, &error_code);
    }
  }
  for (int k = 0; k < LastBarLevel; k++)
  {
    if (disp_obj->Bar_Image[k].ID != NOIMAGE)
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->Bar_Image[k].Handle, 0, 0, disp_obj->Bar_Image[k].ID, TRUE, &error_code);
    }
  }
}

void LoadBackgroundImage(DISP_OBJ_CLEARBASS* disp_obj)
{
  wchar_t* BackgroundImage = L"MP_EQ_BACKGROUND_V_ICN.png";
  
  if( FSX_IsFileExists(CONFIG_PATH, BackgroundImage) )
  {
    RegisterImage(&disp_obj->Background, CONFIG_PATH, BackgroundImage);
  }
  else disp_obj->Background.ID = NOIMAGE;
}

void LoadPresetImage(DISP_OBJ_CLEARBASS* disp_obj)
{
  const wchar_t* ImagePreset[LastPreset] =
  {
    L"MP_EQ_TREBLE_H_ICN.png",    //0
    L"MP_EQ_HEAVY_H_ICN.png",     //1
    L"MP_EQ_POP_H_ICN.png",       //2
    L"MP_EQ_JAZZ_H_ICN.png",      //3
    L"MP_EQ_NORMAL_H_ICN.png",    //4
    L"MP_EQ_UNIQUE_H_ICN.png",    //5
    L"MP_EQ_SOUL_H_ICN.png",      //6
    L"MP_EQ_LIGHT_H_ICN.png",     //7
    L"MP_EQ_BASS_H_ICN.png"       //8
  };
  
  int i;
  for (i = 0; i < LastPreset; i++)
  {
    if( FSX_IsFileExists(CONFIG_PATH, (wchar_t*)ImagePreset[i]))
    {
      RegisterImage(&disp_obj->Preset_Image[i], CONFIG_PATH, (wchar_t*)ImagePreset[i]);
    }
    else disp_obj->Preset_Image[i].ID = NOIMAGE;
  }
}

void LoadBoostImage(DISP_OBJ_CLEARBASS* disp_obj)
{
  const wchar_t* BoostImage[LastBoostLevel] =
  {
    L"BOOST_LEVEL1.png",    //0
    L"BOOST_LEVEL2.png",    //1
    L"BOOST_LEVEL3.png",    //2
    L"BOOST_LEVEL4.png"     //3
  };
  
  int i;
  for (i = 0; i < LastBoostLevel; i++)
  {
    if( FSX_IsFileExists(CONFIG_PATH, (wchar_t*)BoostImage[i]))
    {
      RegisterImage(&disp_obj->Boost_Image[i], CONFIG_PATH, (wchar_t*)BoostImage[i]);
    }
    else disp_obj->Boost_Image[i].ID = NOIMAGE;
  }
}

void LoadBarImage(DISP_OBJ_CLEARBASS* disp_obj)
{
  const wchar_t* BarImage[LastBarLevel] =
  {
    L"BAR_MINUS3.png",  //0
    L"BAR_MINUS2.png",  //1
    L"BAR_MINUS1.png",  //2
    L"BAR_NORMAL.png",  //3
    L"BAR_PLUS1.png",   //4
    L"BAR_PLUS2.png",   //5
    L"BAR_PLUS3.png"    //6
  };
  
  int i;
  for (i = 0; i < LastBarLevel; i++)
  {
    if( FSX_IsFileExists(CONFIG_PATH, (wchar_t*)BarImage[i]))
    {
      RegisterImage(&disp_obj->Bar_Image[i], CONFIG_PATH, (wchar_t*)BarImage[i]);
    }
    else disp_obj->Bar_Image[i].ID = NOIMAGE;
  }
}
