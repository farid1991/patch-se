#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"
#include "image.h"
#include "visual.h"

__thumb void* malloc( int size )
{
  return(memalloc(0xFFFFFFFF, size, 1, 5, "eq", NULL));
}

__thumb void mfree( void* mem )
{
  if(mem) memfree(NULL, mem, "eq", NULL);
}

//==============================================================================
/**
 * The set of equalizer bands available.
 * 
 * The possible values are:
 *
 * TMMEEqBand_ClearBass1,   Only for Clear Audio
 * TMMEEqBand_ClearBass2,   Only for Clear Audio
 * TMMEEqBand_63,           Only for ordinary EQ
 * TMMEEqBand_250,          Only for ordinary EQ
 * TMMEEqBand_400,          Only for Clear Audio
 * TMMEEqBand_1000,         Both Clear Audio and ordinary EQ
 * TMMEEqBand_2500,         Only for Clear Audio
 * TMMEEqBand_4000,         Only for ordinary EQ
 * TMMEEqBand_6300,         Only for Clear Audio
 * TMMEEqBand_16000,        Both Clear Audio and ordinary EQ
 *
 */

void Set_EqualiserGain(BOOK* book, int band, int level)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  switch(band)
  {
  case Eq_Band0:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_ClearBass1, level);
    break;
  case Eq_Band1:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_400, level);
    break;
  case Eq_Band2:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000, level);
    break;
  case Eq_Band3:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_2500, level);
    break;
  case Eq_Band4:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_6300, level);
    break;
  case Eq_Band5:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000, level); 
    break;
  }
}

void SetEqualizerGain(BOOK* book, INT8 bar0, INT8 bar1, INT8 bar2, INT8 bar3, INT8 bar4, INT8 bar5)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  Set_EqualiserGain(MusicBook, Eq_Band0, bar0);
  Set_EqualiserGain(MusicBook, Eq_Band1, bar1);
  Set_EqualiserGain(MusicBook, Eq_Band2, bar2);
  Set_EqualiserGain(MusicBook, Eq_Band3, bar3);
  Set_EqualiserGain(MusicBook, Eq_Band4, bar4);
  Set_EqualiserGain(MusicBook, Eq_Band5, bar5);
}
/*
void Set_EqualiserPreset(BOOK* book, int pos)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  Set_EqualiserGain(MusicBook, Eq_Band0, settings_table[pos][0]);
  Set_EqualiserGain(MusicBook, Eq_Band1, settings_table[pos][1]);
  Set_EqualiserGain(MusicBook, Eq_Band2, settings_table[pos][2]);
  Set_EqualiserGain(MusicBook, Eq_Band3, settings_table[pos][3]);
  Set_EqualiserGain(MusicBook, Eq_Band4, settings_table[pos][4]);
  Set_EqualiserGain(MusicBook, Eq_Band5, settings_table[pos][5]); 
#else
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_63,settings_table[pos][0]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_250,settings_table[pos][1]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000,settings_table[pos][2]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_4000,settings_table[pos][3]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000,settings_table[pos][4]); 
#endif
}
*/
//==============================================================================

void Save_EqualiserData(int Preset, BOOL Manual, int b0, int b1, int b2, int b3, int b4, int b5)
{
  int file;
  if (( file =_fopen( CONFIG_PATH, CONFIG_NAME, FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >=0 )
  {
    EQ_SETTINGS* FileData = (EQ_SETTINGS*)malloc(sizeof(EQ_SETTINGS));
    memset(FileData,NULL,sizeof(EQ_SETTINGS));
    
    FileData->preset = Preset;
    FileData->manual = Manual;
    FileData->boost_level = b0;
    FileData->bar1_level = b1;
    FileData->bar2_level = b2;
    FileData->bar3_level = b3;
    FileData->bar4_level = b4;
    FileData->bar5_level = b5;
    fwrite(file,FileData,sizeof(EQ_SETTINGS));
    
    fclose(file);
    mfree(FileData);
  }
}

void Get_EqualizerData(int *preset, int *manual, int *bar0, int *bar1, int *bar2, int *bar3, int *bar4, int *bar5)
{
  int file;
  if ( (file=_fopen( CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    EQ_SETTINGS *FileData = (EQ_SETTINGS*)malloc(sizeof(EQ_SETTINGS));
    memset(FileData,NULL,sizeof(EQ_SETTINGS));
    fread(file, FileData, sizeof(EQ_SETTINGS) );
    
    *preset = FileData->preset;
    *manual = FileData->manual;
    *bar0 = FileData->boost_level;
    *bar1 = FileData->bar1_level;
    *bar2 = FileData->bar2_level;
    *bar3 = FileData->bar3_level;
    *bar4 = FileData->bar4_level;
    *bar5 = FileData->bar5_level;

    fclose(file);
    mfree(FileData);
  }
}

//==============================================================================

void ClearbassGUI_SelectAction(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  
  int preset, manual, bar0, bar1, bar2, bar3, bar4, bar5;
  preset = GUIObject_Clearbass_GetPresetCursor(MusicBook->Gui_submenu);
  GUIObject_Clearbass_GetBarLevel(MusicBook->Gui_submenu, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);
  
  if(GUIObject_Clearbass_GetState(MusicBook->Gui_submenu))
  {
    manual = TRUE;
    SetEqualizerGain(MusicBook, bar0-3, bar1-3, bar2-3, bar3-3, bar4-3, bar5-3);
  }
  else
  {
    manual = FALSE;
    SetEqualizerGain(MusicBook, 
                     settings_table[preset][Eq_Band0], 
                     settings_table[preset][Eq_Band1], 
                     settings_table[preset][Eq_Band2],
                     settings_table[preset][Eq_Band3], 
                     settings_table[preset][Eq_Band4],
                     settings_table[preset][Eq_Band5] );
  }
  Save_EqualiserData(preset, manual, bar0, bar1, bar2, bar3, bar4, bar5);
  FREE_GUI(MusicBook->Gui_submenu);
}

void ClearbassGUI_PrevAction(BOOK* book, GUI* gui)
{  
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  
  int preset, manual, bar0, bar1, bar2, bar3, bar4,bar5;
  Get_EqualizerData(&preset, &manual, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);
  
  if(GUIObject_Clearbass_GetState(MusicBook->Gui_submenu))
  {
    SetEqualizerGain(MusicBook, bar0-3, bar1-3, bar2-3, bar3-3, bar4-3, bar5-3);
  }
  else
  {
    SetEqualizerGain(MusicBook, 
                        settings_table[preset][Eq_Band0], 
                        settings_table[preset][Eq_Band1], 
                        settings_table[preset][Eq_Band2],
                        settings_table[preset][Eq_Band3], 
                        settings_table[preset][Eq_Band4], 
                        settings_table[preset][Eq_Band5] );
  }
  FREE_GUI(MusicBook->Gui_submenu);
}

#define MP_EQ_ACTIONSELECT 1
#define MP_EQ_ACTIONSWITCH 0

void ClearbassGUI_onSwitch(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;

  if(GUIObject_Clearbass_GetState(MusicBook->Gui_submenu))
  {
    GUIObject_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_EQUALIZER);
    GUIObject_Clearbass_Switch(MusicBook->Gui_submenu, FALSE);
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_MANUAL);
  }
  else
  {
    GUIObject_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_MANUAL);
    GUIObject_Clearbass_Switch(MusicBook->Gui_submenu, TRUE);
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_PRESET);
  }
}

extern "C"
int New_MusicApplication_Equalizer_EnterAction( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FREE_GUI(MusicBook->Gui_submenu);
  
  int preset, manual, bar0, bar1, bar2, bar3, bar4,bar5;
  Get_EqualizerData(&preset, &manual, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);
  
  if(MusicBook->Gui_submenu = Create_ClearbassGUI(MusicBook))
  {
    GUIObject_Clearbass_SetCursorToItem(MusicBook->Gui_submenu, preset);
    GUIObject_Clearbass_SetState(MusicBook->Gui_submenu, manual);
    GUIObject_Clearbass_SetBarLevel(MusicBook->Gui_submenu, bar0, bar1, bar2, bar3, bar4, bar5);
    
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSELECT, TEXT_SELECT);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, MP_EQ_ACTIONSELECT, ClearbassGUI_SelectAction);
    
    if(GUIObject_Clearbass_GetState(MusicBook->Gui_submenu))
    {
      GUIObject_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_MANUAL);
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_PRESET);
      
      SetEqualizerGain(MusicBook, bar0-3, bar1-3, bar2-3, bar3-3, bar4-3, bar5-3);
    }
    else
    {
      GUIObject_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_EQUALIZER);
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_MANUAL);
      
      SetEqualizerGain(MusicBook,
                    settings_table[preset][Eq_Band0],
                    settings_table[preset][Eq_Band1],
                    settings_table[preset][Eq_Band2],
                    settings_table[preset][Eq_Band3], 
                    settings_table[preset][Eq_Band4], 
                    settings_table[preset][Eq_Band5] );
    }
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, ClearbassGUI_onSwitch);

    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, ClearbassGUI_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApp_CancelAction);
    DispObject_SetAnimation( GUIObject_GetDispObject(MusicBook->Gui_submenu), 0xA0001021 );
    GUIObject_Show( MusicBook->Gui_submenu );
  }
  return 1;
}

//==============================================================================

extern "C"
void New_SetEqualizerGain(MusicApplication_Book* MusicBook)
{
  int preset, manual, bar0, bar1, bar2, bar3, bar4,bar5;
  Get_EqualizerData(&preset, &manual, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);
  
  if(manual)
  {
    SetEqualizerGain(MusicBook, bar0, bar1, bar2, bar3, bar4, bar5);
  }
  else
  {
    SetEqualizerGain(MusicBook, 
                  settings_table[preset][Eq_Band0],
                  settings_table[preset][Eq_Band1], 
                  settings_table[preset][Eq_Band2],
                  settings_table[preset][Eq_Band3], 
                  settings_table[preset][Eq_Band4], 
                  settings_table[preset][Eq_Band5] );
  }
}

extern "C"
int New_MusicApplication_Equalizer_CancelAction( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  
  New_SetEqualizerGain(MusicBook);
  
  BookObj_ReturnPage(MusicBook, CANCEL_EVENT);
  return 1;
}

/*
const PAGE_MSG MusicApplication_Equalizer[] = 
{
  PAGE_ENTER_EVENT,           New_MusicApplication_Equalizer_MainPage,
  PREVIOUS_EVENT,             pg_MusicApplication_UnplugPHF__PreviousAction,
  CANCEL_EVENT,               New_MusicApplication_Equalizer_CancelAction,
  UI_MEDIAPLAYER_UPDATE_EVENT,pg_MusicApplication_UnplugPHF__PreviousAction,
  PAGE_EXIT_EVENT,            pg_MusicApplication_UnplugPHF__ExitAction,
  NIL_EVENT,                  NULL
};

const PAGE_DESC MusicApplication_Equalizer_Page = {"MusicApplication_Equalizer_Page",NULL,MusicApplication_Equalizer};
*/
