#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"
#include "visual.h"

__thumb void* malloc( int size )
{
  return(memalloc(0xFFFFFFFF, size, 1, 5, "eq", NULL));
}

__thumb void mfree( void* mem )
{
  if(mem) memfree(NULL, mem, "eq", NULL);
}

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
const int settings_table [9][6] = {
  {   0,    0,   0,   2,   4,   6   },  //Treble
  {   0,   -2,   0,   2,   2,   0   },  //Heavy
  {   2,    2,   0,   0,   0,  -2   },  //Pop
  {   0,    0,   0,  -2,   0,   2   },  //Jazz
  {   0,    0,   0,   0,   0,   0   },  //Normal
  {   0,    2,   0,   0,  -2,   4   },  //Special
  {   0,    0,   0,   4,   0,   0   },  //Soul
  {  -2,    0,   0,   2,   0,   4   },  //Light
  {   6,    4,   0,   0,   0,  -2   }   //Bass
};
#else
const int settings_table [9][5] = {
  {   0,    0,   2,   4,   6   },  //Treble
  {   0,   -2,   2,   2,   0   },  //Heavy
  {   2,    2,   0,   0,  -2   },  //Pop
  {   0,    0,  -2,   0,   2   },  //Jazz
  {   0,    0,   0,   0,   0   },  //Normal
  {   0,    2,   0,  -2,   4   },  //Special
  {   0,    0,   4,   0,   0   },  //Soul
  {  -2,    0,   2,   0,   4   },  //Light
  {   6,    4,   0,   0,  -2   }   //Bass
};
#endif

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

void Set_ClearbassPreset(MusicApplication_Book* MusicBook, int pos)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_ClearBass1,settings_table[pos][0]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_400,settings_table[pos][1]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000,settings_table[pos][2]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_2500,settings_table[pos][3]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_6300,settings_table[pos][4]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000,settings_table[pos][5]); 
#else
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_63,settings_table[pos][0]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_250,settings_table[pos][1]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000,settings_table[pos][2]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_4000,settings_table[pos][3]);
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000,settings_table[pos][4]); 
#endif
}

void Save_LastPreset(int EqPreset)
{
  int file;
  if (( file =_fopen( CONFIG_PATH, CONFIG_NAME, FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >=0 )
  {
    EqPreset_File* FileData = (EqPreset_File*)malloc(sizeof(EqPreset_File));
    memset(FileData,NULL,sizeof(EqPreset_File));
    
    FileData->EqPreset = EqPreset;
    fwrite(file,FileData,sizeof(EqPreset_File));
    
    fclose(file);
    mfree(FileData);
  }
}

int Get_LastPreset()
{
  int file, ret = 0;
  if ( (file=_fopen( CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    EqPreset_File *FileData = (EqPreset_File*)malloc(sizeof(EqPreset_File));
    memset(FileData,NULL,sizeof(EqPreset_File));
    fread(file, FileData, sizeof(EqPreset_File) );
    
    ret = FileData->EqPreset;

    fclose(file);
    mfree(FileData);
  }
  return ret;
}

/*
void Get_EqGain(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;

  //int a,b,c,d;
  //a = music_book->unk_37;
  //b = music_book->unk_4C;
  //c = music_book->unk_4D;
  //d = music_book->unk_60;
  //e=music_book->Eq.Band_16000;
  
  TMusicServer_Time time;
  MusicBook->pMusicServer->GetTime(&time);
  
  FUint32 Index;
  MusicBook->pMusicServer->GetCurrentItemIndex( &Index );
  
  wchar_t buf[512];
  snwprintf(buf,MAXELEMS(buf),L"%02d %02d %02d %d",time.hours,time.minutes,time.seconds,Index);
  MessageBox_NoImage(EMPTY_TEXTID,TextID_Create(buf,ENC_UCS2,TEXTID_ANY_LEN),0,0,book);
}
*/
void ClearbassGUI_SelectAction(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  int cur_pos = GUI_Clearbass_GetCursor(MusicBook->Gui_submenu);
  Set_ClearbassPreset(MusicBook,cur_pos);
  Save_LastPreset(cur_pos);
  FREE_GUI(MusicBook->Gui_submenu);
}

void ClearbassGUI_PrevAction(BOOK* book, GUI* gui)
{  
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  Set_ClearbassPreset(MusicBook, Get_LastPreset());
  FREE_GUI(MusicBook->Gui_submenu);
}

void ClearbassGUI_onSwitch(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;

  if(GUI_Clearbass_GetState(MusicBook->Gui_submenu))
  {
    GUI_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_MANUAL);
    GUI_Clearbass_Switch(MusicBook->Gui_submenu, FALSE);
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, 1, TEXT_MANUAL);
  }
  else
  {
    GUI_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_EQUALIZER);
    GUI_Clearbass_Switch(MusicBook->Gui_submenu, TRUE);
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, 1, TEXT_PRESET);
  }
}

extern "C"
int New_MusicApplication_Equalizer_EnterAction( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FREE_GUI(MusicBook->Gui_submenu);
  
  if(MusicBook->Gui_submenu = Create_ClearbassGUI(MusicBook))
  {
    if(GUI_Clearbass_GetState(MusicBook->Gui_submenu))
    {
      GUI_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_EQUALIZER);
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, 1, TEXT_MANUAL);
    }
    else
    {
      GUI_Clearbass_SetTitleText(MusicBook->Gui_submenu, TEXT_MANUAL);
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, 1, TEXT_PRESET);
    }
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, 1, ClearbassGUI_onSwitch);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, ClearbassGUI_SelectAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, ClearbassGUI_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApp_CancelAction);
    DispObject_SetAnimation( GUIObject_GetDispObject(MusicBook->Gui_submenu), 0xA0001021 );
    GUIObject_Show( MusicBook->Gui_submenu );
  }
  return 1;
}

extern "C"
int New_MusicApplication_Equalizer_CancelAction( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  Set_ClearbassPreset(MusicBook, Get_LastPreset());
  
  BookObj_ReturnPage(MusicBook, CANCEL_EVENT);
  return 1;
}

extern "C"
void New_SetEqualizerGain(MusicApplication_Book* MusicBook)
{
  Set_ClearbassPreset(MusicBook, Get_LastPreset());
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
