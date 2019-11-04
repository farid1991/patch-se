#ifndef _MAIN_H_
#define _MAIN_H_

#define CONFIG_PATH L"/usb/other/ZBin/Config/Equalizer"
#define CONFIG_NAME L"EqSettings.bin"

typedef signed char INT8;

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
const INT8 settings_table [9][6] = {
  {   0,    0,   0,   0,   1,   3   },  //Treble
  {   4,    0,  -2,   5,   5,   0   },  //Heavy
  {   0,    1,   1,   0,   0,  -2   },  //Pop
  {   4,    0,   0,  -2,   0,   5   },  //Jazz
  {   0,    0,   0,   0,   0,   0   },  //Normal
  {   4,    0,   5,   0,  -2,  10   },  //Special
  {   4,    0,   0,  10,   0,   0   },  //Soul
  {   4,   -2,   0,   5,   0,  10   },  //Light
  {   4,    0,   0,   0,   0,   0   }   //Bass
};
#else
const INT8 settings_table [9][5] = {
  {   0,    0,   2,   4,   6   },  //Treble
  {   0,   -2,   2,   2,   0   },  //Heavy
  {   2,    2,   0,   0,  -2   },  //Pop
  {   0,    0,  -2,   0,   2   },  //Jazz
  {   0,    0,   0,   0,   0   },  //Normal
  {   0,    2,   0,  -2,   4   },  //Special
  {   0,    0,   4,   0,   0   },  //Soul
  {  -0,    0,   2,   0,   4   },  //Light
  {   6,    4,   0,   0,  -2   }   //Bass
};
#endif

typedef struct {
  char preset;
  bool manual;
  
  INT8 boost_level;
  INT8 bar1_level;
  INT8 bar2_level;
  INT8 bar3_level;
  INT8 bar4_level;
  INT8 bar5_level;
}EQ_SETTINGS;

void Set_EqualiserGain(BOOK* book, int band, int level);
void SetEqualizerGain(BOOK* book, INT8 bar0, INT8 bar1, INT8 bar2, INT8 bar3, INT8 bar4, INT8 bar5);
void Save_LastPreset(int EqPreset);

void New_SetEqualizerGain(BOOK* MusicBook);

extern "C"
{
  int pg_MusicApplication_UnplugPHF__PreviousAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__CancelAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__ExitAction( void* Data, BOOK* bk );
  
  void MusicApp_PrevAction(BOOK *book, GUI *gui);
  void MusicApp_CancelAction(BOOK *book, GUI *gui);
};

#endif
