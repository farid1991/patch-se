#include "temp\target.h"

#include "..\\include\ASCII.h"
#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "dll.h"
#include "Draw.h"
#include "FilesList.h"
#include "Function.h"
#include "LNG.h"
#include "main.h"
#include "String.h"

#include "GUI\NowPlaying.h"

#include "Pages\AlbumArt.h"
#include "Pages\EditTag.h"
#include "Pages\Lyric.h"
#include "Pages\SetTime.h"
#include "Pages\Shortcut.h"
#include "Pages\Skins.h"
#include "Pages\TimerOff.h"
#include "Pages\UseAs.h"

//==============================================================================

__thumb void *malloc(int size)
{
  return memalloc(-1, size, 1, 5, MEM_NAME, NULL);
}

__thumb void mfree(void *mem)
{
  if (mem)
    memfree(NULL, mem, MEM_NAME, NULL);
}

Internal_Function *Init_Internal_Function()
{
  Internal_Function *Data = (Internal_Function *)malloc(sizeof(Internal_Function));
  memset(Data, NULL, sizeof(Internal_Function));
  set_envp(NULL, EMP_NAME, (OSADDRESS)Data);
  return Data;
}

Internal_Function *Get_Internal_Function()
{
  Internal_Function *Data = (Internal_Function *)get_envp(NULL, EMP_NAME);
  if (Data)
    return Data;
  return Init_Internal_Function();
}

void Delete_Internal_Function(Internal_Function *Data)
{
  if (Data)
  {
    WStringFree(Data->Extension);
    WStringFree(Data->Genre);
    mfree(Data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

int division(int num1, int num2)
{
  int temp = 1, quotient = 0;
  while (num2 <= num1)
  {
    num2 <<= 1;
    temp <<= 1;
  }
  while (temp > 1)
  {
    num2 >>= 1;
    temp >>= 1;
    if (num1 >= num2)
    {
      num1 -= num2;
      quotient += temp;
    }
  }
  return quotient;
}

int GetMediaVolume()
{
  char media;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  return (media - 18);
}

void InvalidateRect(DISP_OBJ *disp_obj)
{
  if (disp_obj)
    DispObject_InvalidateRect(disp_obj, NULL);
}

extern "C" void RefreshScreen()
{
  Internal_Function *Data = Get_Internal_Function();
  InvalidateRect(Data->Music_Gui_NowPlaying);
}

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ImageID = NOIMAGE;
  img->ImageHandle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->ImageHandle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->ImageHandle, path, fname, NULL, &img->ImageID, &error_code))
      if (error_code)
        img->ImageHandle = NOIMAGE;
}

extern "C" int PATCH_UI_MEDIAPLAYER_AUDIO_ON_NEW_TRACK_EVENT(void *trackdata, BOOK *book)
{
  Internal_Function *Data = Get_Internal_Function();

  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  NEW_TRACK_DATA *TrackData = (NEW_TRACK_DATA *)trackdata;

  Data->FullTimeInSeconds = (TrackData->FullTime.hours * 60 * 60) + (TrackData->FullTime.minutes * 60) + TrackData->FullTime.seconds;
  Data->ElapsedTimeInSeconds = (TrackData->ElapsedTime.hours * 60 * 60) + (TrackData->ElapsedTime.minutes * 60) + TrackData->ElapsedTime.seconds;

  Data->FullTime.hours = TrackData->FullTime.hours;
  Data->FullTime.minutes = TrackData->FullTime.minutes;
  Data->FullTime.seconds = TrackData->FullTime.seconds;
  Data->ElapsedTime.hours = TrackData->ElapsedTime.hours;
  Data->ElapsedTime.minutes = TrackData->ElapsedTime.minutes;
  Data->ElapsedTime.seconds = TrackData->ElapsedTime.seconds;

  if (Data->MusicBook)
    GetNextTrackData(TrackData, MusicBook);

  int ret = pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT(TrackData, MusicBook);
  RefreshScreen();
  return ret;
}

extern "C" int PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(void *timedata, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  PLAYING_TIME_DATA *TimeData = (PLAYING_TIME_DATA *)timedata;
  int ret = pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(TimeData, MusicBook);

  Internal_Function *Data = Get_Internal_Function();
  Data->ElapsedTimeInSeconds = (TimeData->Hours * 60 * 60) + (TimeData->Minutes * 60) + TimeData->Seconds;
  Data->ElapsedTime.hours = TimeData->Hours;
  Data->ElapsedTime.minutes = TimeData->Minutes;
  Data->ElapsedTime.seconds = TimeData->Seconds;

  if (Find_AdvLyricBook())
    AdvLyric_GetLyric(TimeData, MusicBook);

  RefreshScreen();
  return ret;
}

extern "C" int PATCH_UI_MEDIAPLAYER_CREATED_EVENT(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  int ret = pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT(data, MusicBook);

  Internal_Function *Data = Get_Internal_Function();
  Data->MusicBook = MusicBook;
  Data->VolumeLevel = GetMediaVolume();

  if (MusicBook->DisplayOrientation == UIDisplayOrientationMode_Vertical)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }
  RefreshScreen();
  return ret;
}

extern "C" int PATCH_UI_MEDIAPLAYER_ON_ENTER_EVENT(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  int ret = pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT(data, MusicBook);

  Internal_Function *Data = Get_Internal_Function();
  Data->MusicBook = MusicBook;
  return ret;
}

void SetGUIData(GUI *gui)
{
  Internal_Function *Data = Get_Internal_Function();

  if (Data->Fullscreen)
  {
    GUIObject_SetStyle(gui, UI_OverlayStyle_TrueFullScreen);
    if (DispObject_GetStyle(Data->Music_Gui_NowPlaying) != UI_OverlayStyle_TrueFullScreen)
      DispObject_SetStyle(Data->Music_Gui_NowPlaying, UI_OverlayStyle_TrueFullScreen);
  }
  else
  {
    GUIObject_SetStyle(gui, UI_OverlayStyle_Default);
    if (DispObject_GetStyle(Data->Music_Gui_NowPlaying) != UI_OverlayStyle_Default)
      DispObject_SetStyle(Data->Music_Gui_NowPlaying, UI_OverlayStyle_Default);
  }

  if (Data->SoftKeys)
  {
    GUIObject_SoftKeys_Show(gui);
    DispObject_SoftKeys_Show(Data->Music_Gui_NowPlaying);
  }
  else
  {
    GUIObject_SoftKeys_Hide(gui);
    DispObject_SoftKeys_Hide(Data->Music_Gui_NowPlaying);
  }
}

extern "C" void Set_WALKMAN_GUI_STYLE(GUI *gui)
{
  int File;
  if ((File = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= 0)
  {
    SKIN *CurrentSkin = (SKIN *)malloc(sizeof(SKIN));
    memset(CurrentSkin, NULL, sizeof(SKIN));
    fread(File, CurrentSkin, sizeof(SKIN));
    int FSkin = _fopen(CurrentSkin->Path, CurrentSkin->Name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (FSkin >= 0)
    {
      SkinData *FSkinData = (SkinData *)malloc(sizeof(SkinData));
      memset(FSkinData, NULL, sizeof(SkinData));
      fread(FSkin, FSkinData, sizeof(SkinData));
      fclose(FSkin);

      Internal_Function *Data = Get_Internal_Function();
      Data->Fullscreen = FSkinData->FullScreen;
      Data->SoftKeys = FSkinData->SoftKeys;
      mfree(FSkinData);
    }
    fclose(File);
    mfree(CurrentSkin);
  }
  SetGUIData(gui);
  RefreshScreen();
}

extern "C" void New_SoftKeys(BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  // Settings --------------------------------------------------------------------
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SKINEDITOR);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, Enter_SkinEditor);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, TEXT_SKINS);
  GUIObject_SoftKeys_SetInfoText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, STR(TXT_EDIT_THE_APPEARANCE_OF_WALKMAN_LAYOUT));
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SKINEDITOR);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, Enter_SkinEditor);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, TEXT_SKINS);
  MediaPlayer_SoftKeys_SetInfoText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, STR(TXT_EDIT_THE_APPEARANCE_OF_WALKMAN_LAYOUT));

  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_ALBUM_ART);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_ALBUM_ART, Enter_SelectAlbumArt);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_ALBUM_ART, TEXT_ALBUM_ART);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_ALBUM_ART);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_ALBUM_ART, Enter_SelectAlbumArt);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_ALBUM_ART, TEXT_ALBUM_ART);
#if defined(DB3200) || defined(DB3210)
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SETTIME);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SETTIME, Enter_SetTime);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SETTIME, TEXT_GO_TO);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SETTIME);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SETTIME, Enter_SetTime);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SETTIME, TEXT_GO_TO);
#endif
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_TIMEROFF);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_TIMEROFF, Call_TimerOff);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_TIMEROFF, TEXT_TIMER);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_TIMEROFF);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_TIMEROFF, Call_TimerOff);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_TIMEROFF, TEXT_TIMER);

  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SHORTCUT);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, Call_ShortcutPage);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, TEXT_SHORTCUT);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SHORTCUT);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, Call_ShortcutPage);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, TEXT_SHORTCUT);

  // File ------------------------------------------------------------------------
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_FILE, ACTION_MP_LYRIC);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_LYRIC, Enter_Lyric);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_LYRIC, TEXT_LYRIC);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_FILE, ACTION_MP_LYRIC);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_LYRIC, Enter_Lyric);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_LYRIC, TEXT_LYRIC);

  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_FILE, ACTION_MP_USE_AS);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_USE_AS, Enter_UseAs);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_USE_AS, TEXT_USE_AS);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_FILE, ACTION_MP_USE_AS);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_USE_AS, Enter_UseAs);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_USE_AS, TEXT_USE_AS);

  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_FILE, ACTION_MP_EDITTAG);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_EDITTAG, Enter_EditTag);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_EDITTAG, TEXT_EDIT_TAG);
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_FILE, ACTION_MP_EDITTAG);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_EDITTAG, Enter_EditTag);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_EDITTAG, TEXT_EDIT_TAG);
  // -----------------------------------------------------------------------------
}

extern "C" void Feedback_DrawCoverArt(DISP_OBJ *disp_obj, int a, int b, int c)
{
  FeedbackTicker_OnRedraw(disp_obj, a, b, c);

  Internal_Function *Data = Get_Internal_Function();
  GC *pGC = get_DisplayGC();

  if (Data->CoverArtID != NOIMAGE)
  {
    DrawImage(pGC, 0, 0, 40, 40, Data->CoverArtID);
  }
  else
  {
    DrawImage(pGC, 0, 0, 40, 40, Data->MusicPlayer[NO_COVER_ICN].ImageID);
  }
}
