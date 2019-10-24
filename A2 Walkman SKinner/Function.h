extern "C"
{
  void WALKMAN_DefaultRedraw (DISP_OBJ*,int a,int b,int c);
  void WALKMAN_Default_ONCREATE(DISP_OBJ*);
  void WALKMAN_Default_ONDESTROY(DISP_OBJ*);
  void WALKMAN_Default_Method0A(DISP_OBJ*);
  
  void Default_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(void *mess, BOOK *bk);
  void Default_PATCH_UI_MEDIAPLAYER_CREATED_EVENT(void *mess, BOOK *bk);
  int Default_MUSIC_APP_ON_ENTER_PAGE(void *mess, BOOK *bk);
  void DefaultOnNewTrack(void* mess, BOOK* bk);
  
  void Default_VolumeControl_OnClose(DISP_OBJ*);
  int Default_VolumeControl_OnCreate(DISP_OBJ*);
  void Default_VolumeControl_OnRedraw(DISP_OBJ*,int a, int b, int c);
  
  void LoadLandscapeData();
  void LoadPortraitData();
  
  int pg_MusicApplication_SubMenu_PreviousAction( void* Data, BOOK* bk );
  int pg_MusicApplication_SubMenu_CancelAction( void* Data, BOOK* bk );
  int pg_MusicApplication_SubMenu_ExitAction( void* Data, BOOK* bk );
  
  void MusicApp_PrevAction(BOOK *bk, GUI *gui);
  void MusicApp_CancelAction(BOOK *bk, GUI *gui);

};
