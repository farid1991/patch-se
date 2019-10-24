extern "C"
{
  int pg_MusicApplication_UnplugPHF__PreviousAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__CancelAction( void* Data, BOOK* bk );
  int pg_MusicApplication_UnplugPHF__ExitAction( void* Data, BOOK* bk );
  
  void MusicApp_PrevAction(BOOK *bk, GUI *gui);
  void MusicApp_CancelAction(BOOK *bk, GUI *gui);
  
};
