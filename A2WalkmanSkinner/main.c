#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "dll.h"
#include "Draw.h"
#include "FilesList.h"
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
  return memalloc(0xFFFFFFFF, size, 1, 5, MEM_NAME, NULL);
}

__thumb void mfree(void *mem)
{
  if (mem)
    memfree(NULL, mem, MEM_NAME, NULL);
}

Internal_Function *Create_Internal_Function()
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
  return Create_Internal_Function();
}

void Delete_Internal_Function(Internal_Function *Data)
{
  if (Data)
  {
    mfree(Data->Extension);
    mfree(Data->Genre);
    mfree(Data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

int division(int num1, int num2)
{
  if (num2 == 0)
  {
    // Handle division by zero here, if necessary.
    return 0; // Or some appropriate value or error handling.
  }

  int quotient = 0;
  int sign = 1; // Store the sign of the result.

  // Handle negative numbers.
  if (num1 < 0)
  {
    num1 = -num1;
    sign = -sign;
  }
  if (num2 < 0)
  {
    num2 = -num2;
    sign = -sign;
  }

  while (num1 >= num2)
  {
    num1 -= num2;
    quotient++;
  }

  // Apply the sign.
  return sign * quotient;
}

int GetMediaVolume()
{
  char media;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  return (media - 18);
}

extern "C" void refresh_gui()
{
  Internal_Function *Data = Get_Internal_Function();
  if (Data->Music_Gui_NowPlaying)
  {
    DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
  }
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

  int ret = pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT(TrackData, MusicBook);

  Data->FullTimeInSeconds = (TrackData->FullTime.hours * 60 * 60) + (TrackData->FullTime.minutes * 60) + TrackData->FullTime.seconds;
  Data->ElapsedTimeInSeconds = (TrackData->ElapsedTime.hours * 60 * 60) + (TrackData->ElapsedTime.minutes * 60) + TrackData->ElapsedTime.seconds;

  Data->FullTime.hours = TrackData->FullTime.hours;
  Data->FullTime.minutes = TrackData->FullTime.minutes;
  Data->FullTime.seconds = TrackData->FullTime.seconds;
  Data->ElapsedTime.hours = TrackData->ElapsedTime.hours;
  Data->ElapsedTime.minutes = TrackData->ElapsedTime.minutes;
  Data->ElapsedTime.seconds = TrackData->ElapsedTime.seconds;

  if (Data->MusicBook)
  {
    GetNextTrackData(TrackData, MusicBook);
  }

  refresh_gui();
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
  {
    AdvLyric_GetLyric(TimeData, MusicBook);
  }

  refresh_gui();
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

  refresh_gui();
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

void set_gui_state(GUI *gui)
{
  Internal_Function *Data = Get_Internal_Function();

  if (Data->Fullscreen)
  {
    GUIObject_SetStyle(gui, UI_OverlayStyle_TrueFullScreen);
    DispObject_SetStyle(Data->Music_Gui_NowPlaying, UI_OverlayStyle_TrueFullScreen);
  }
  else
  {
    GUIObject_SetStyle(gui, UI_OverlayStyle_Default);
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

  refresh_gui();
}

void Load_skin_GUI(const wchar_t *fpath, const wchar_t *fname)
{
  int skin_file = _fopen(fpath, fname, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (skin_file >= 0)
  {
    WALKMAN_Skin *skin_data = (WALKMAN_Skin *)malloc(sizeof(WALKMAN_Skin));
    memset(skin_data, NULL, sizeof(WALKMAN_Skin));
    fread(skin_file, skin_data, sizeof(WALKMAN_Skin));
    fclose(skin_file);

    Internal_Function *Data = Get_Internal_Function();
    Data->Fullscreen = skin_data->FullScreen;
    Data->SoftKeys = skin_data->SoftKeys;
    mfree(skin_data);
  }
}

extern "C" void Set_WALKMAN_GUI_STYLE(GUI *gui)
{
  int settings_file = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (settings_file >= 0)
  {
    SKIN *current_skin = (SKIN *)malloc(sizeof(SKIN));
    memset(current_skin, NULL, sizeof(SKIN));
    fread(settings_file, current_skin, sizeof(SKIN));
    fclose(settings_file);

    Load_skin_GUI(current_skin->Path, current_skin->Name);
    mfree(current_skin);

    set_gui_state(gui);
    refresh_gui();
  }
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
  MediaPlayer_SoftKeys_AddHelpStr(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, STR(TXT_EDIT_THE_APPEARANCE_OF_WALKMAN_LAYOUT));

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
  GC *gc = get_DisplayGC();
  IMAGEID image_id;

  if (Data->CoverArtID != NOIMAGE)
  {
    image_id = Data->CoverArtID;
  }
  else
  {
    image_id = Data->MusicPlayer[NO_COVER_ICN].ImageID;
  }
  DrawImageEx(gc, 2, 2, 36, 36, image_id);
}
