#ifndef _MAIN_H_
#define _MAIN_H_

static const char Gui_Clearbass[] = "Clearbass_Equalizer_Display";

#define FREE_GUI(a) if(a) a=GUIObject_Destroy(a)
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a)

typedef struct _DISP_OBJ_CLEARBASS : DISP_OBJ
{
  int count;
  int cursor;
  //TEXTID text_id;
  IMAGEID EqIMG_ID;
  MusicApplication_Book* MusicBook;
} DISP_OBJ_CLEARBASS;

typedef struct
{
  char EqPreset;
} EqPreset_File;

extern "C"
{
  int pg_MusicApplication_UnplugPHF__PreviousAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__CancelAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__ExitAction( void* Data, BOOK* bk );
  
  void MusicApp_PrevAction(BOOK *bk, GUI *gui);
  void MusicApp_CancelAction(BOOK *bk, GUI *gui);
  
};

#endif
