#ifndef _MAIN_H_
#define _MAIN_H_

#define CONFIG_PATH L"/usb/other/ZBin/Config/Equalizer"
#define CONFIG_NAME L"EqPreset.bin"

typedef struct
{
  char EqPreset;
} EqPreset_File;

void Set_ClearbassPreset(MusicApplication_Book* MusicBook, int pos);
void Save_LastPreset(int EqPreset);
int Get_LastPreset();

extern "C"
{
  int pg_MusicApplication_UnplugPHF__PreviousAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__CancelAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__ExitAction( void* Data, BOOK* bk );
  
  void MusicApp_PrevAction(BOOK *book, GUI *gui);
  void MusicApp_CancelAction(BOOK *book, GUI *gui);
  
};

#endif
