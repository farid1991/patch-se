#ifndef _MAIN_H_
#define _MAIN_H_

#define CONFIG_PATH L"/usb/other/ZBin/Config/Equalizer"
#define CONFIG_NAME L"EqPreset.bin"

typedef struct {
  char preset;
  char manual;
  
  char boost_level;
  char bar1_level;
  char bar2_level;
  char bar3_level;
  char bar4_level;
  char bar5_level;
}EQ_PRESET;

void Set_EqualiserGain(BOOK* book, int band, int level);
void Set_EqualiserPreset(BOOK* book, int pos);
void Save_LastPreset(int EqPreset);
int Get_LastPreset();

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
