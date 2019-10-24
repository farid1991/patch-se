#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(gui) if (gui) { GUIObject_Destroy(gui); gui = NULL; }

#define TI_GET_HOUR(x) ((unsigned int)x&0xFF)
#define TI_GET_MIN(x) (((unsigned int)x>>8)&0xFF)

#define EMP_NAME "AudioTimer"

typedef struct
{
  bool TimerOn;
  u16 TimerID;
  char Hour;
  char Min;
} TIMER_DATA;

extern "C"
{
  int pg_MusicApplication_UnplugPHF__PreviousAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__CancelAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__ExitAction( void* Data, BOOK* bk );
  
  void MusicApp_PrevAction(BOOK *bk, GUI *gui);
  void MusicApp_CancelAction(BOOK *bk, GUI *gui);
  
};

#endif
