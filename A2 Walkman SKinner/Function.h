extern "C"
{
  int Music_Gui_NowPlaying_OnCreate(DISP_OBJ*);
  void Music_Gui_NowPlaying_OnRedraw (DISP_OBJ*,int a,int b,int c);
  void Music_Gui_NowPlaying_OnDestroy(DISP_OBJ*);
  void Music_Gui_NowPlaying_OnMethod0A(DISP_OBJ*);
  
  int Default_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT( void *Data, BOOK *book);
  int Default_PATCH_UI_MEDIAPLAYER_CREATED_EVENT( void *Data, BOOK *book);
  int pg_MusicApplication_Main_EnterAction( void *Data, BOOK *book);
  int DefaultOnNewTrack( void *Data, BOOK* book);

  void LoadLandscapeData();
  void LoadPortraitData();
  
  int pg_MusicApplication_UnplugPHF__PreviousAction( void *Data, BOOK* book );
  int pg_MusicApplication_UnplugPHF__CancelAction( void *Data, BOOK* book );
  int pg_MusicApplication_UnplugPHF__ExitAction( void *Data, BOOK* book );
  
  void MusicApp_PrevAction(BOOK *book, GUI *gui);
  void MusicApp_CancelAction(BOOK *book, GUI *gui);

};
