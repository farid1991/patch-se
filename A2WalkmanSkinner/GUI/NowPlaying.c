#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\LNG.h"

#include "..\\Pages\AlbumArt.h"
#include "..\\Pages\Skins.h"

#include "NowPlaying.h"

//==============================================================================

TEXTID MusicServerTime2ID(TMusicServer_Time Time)
{
  wchar_t Buffer[32];
  int minutes = Time.hours * 60 + Time.minutes;
  snwprintf(Buffer,
            MAXELEMS(Buffer),
            L"%02d:%02d",
            minutes,
            Time.seconds);
  return TextID_Create(Buffer, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetRemainingTime(Internal_Function *Data)
{
  int total_minutes = (Data->FullTime.hours * 60 + Data->FullTime.minutes);
  int elapsed_minutes = Data->ElapsedTime.minutes;
  int elapsed_seconds = Data->ElapsedTime.seconds;

  int remaining_minutes = total_minutes - elapsed_minutes;
  int remaining_seconds = Data->FullTime.seconds - elapsed_seconds;

  if (remaining_seconds < 0)
  {
    remaining_seconds += 60;
    remaining_minutes--;
  }

  if (remaining_minutes < 0)
  {
    remaining_minutes = 0;
    remaining_seconds = 0;
  }

  snwprintf(Data->Buffer, MAXELEMS(Data->Buffer), L"-%02d:%02d", remaining_minutes, remaining_seconds);

  return TextID_Create(Data->Buffer, ENC_UCS2, TEXTID_ANY_LEN);
}

void LoadImage(Internal_Function *Data)
{
  const wchar_t *MusicPlayer_Image[LastImage] =
      {
          L"MP_BG_LD.png",
          L"MP_BG_PT.png",
          L"NO_COVER_ICN.png",
          L"OVERLAY_IMAGE_P.png",
          L"BLOB.png",
          L"MP_EQ_STATUS_ICN.png",
          L"MP_MODE_LOOP_ICN.png",
          L"MP_MODE_RANDOM_ICN.png",
          L"MP_PAUSE_ICN.png",
          L"MP_PLAY_ICN.png",
          L"MP_REWIND_ICN.png",
          L"MP_FAST_FORWARD_ICN.png",
          L"MP_ALBUM_ICN.png",
          L"MP_ARTIST_ICN.png",
          L"MP_TRACK_ICN.png",
          L"MC_WHEEL_BACKGROUND_ICN.png",
          L"MC_WHEEL_DOWN_ICN.png",
          L"MC_WHEEL_FF_ICN.png",
          L"MC_WHEEL_NEXT_ICN.png",
          L"MC_WHEEL_PAUSE_ICN.png",
          L"MC_WHEEL_PLAY_ICN.png",
          L"MC_WHEEL_PREV_ICN.png",
          L"MC_WHEEL_REW_ICN.png",
          L"MC_WHEEL_UP_ICN.png",
          L"OVERLAY_IMAGE_L.png",
          L"REFLECT.png",
          L"MP_EQ_BASS_ICN.png",
          L"MP_EQ_MANUAL_ICN.png",
          L"MP_EQ_MEGABASS_ICN.png",
          L"MP_EQ_NORMAL_ICN.png",
          L"MP_EQ_TREBLEBOOST_ICN.png",
          L"MP_EQ_VOICE_ICN.png",
          L"PROGRESSBAR_OVERLAY.png",
          L"PROGRESSBAR_OVERLAY_LANDSCAPE.png",
#ifdef REPEATONE
          L"MP_MODE_REPEAT_ONE_ICN.png",
#endif
      };

  int File = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0);
  if (File >= 0)
  {
    SKIN *SkinData = (SKIN *)malloc(sizeof(SKIN));
    memset(SkinData, NULL, sizeof(SKIN));
    fread(File, SkinData, sizeof(SKIN));
    for (int i = 0; i < LastImage; i++)
    {
      if (FSX_IsFileExists(SkinData->SkinDataPath, (wchar_t *)MusicPlayer_Image[i]))
      {
        RegisterImage(&Data->MusicPlayer[i], SkinData->SkinDataPath, (wchar_t *)MusicPlayer_Image[i]);
      }
      else
      {
        Data->MusicPlayer[i].ImageID = NOIMAGE;
      }
    }
#if defined(DB3200) || defined(DB3210)
    Data->blob_w = dll_GetImageWidth(Data->MusicPlayer[4].ImageID) >> 1;
    Data->blob_h = dll_GetImageHeight(Data->MusicPlayer[4].ImageID) >> 1;
#else
    Data->blob_w = GetImageWidth(Data->MusicPlayer[4].ImageID) >> 1;
    Data->blob_h = GetImageHeight(Data->MusicPlayer[4].ImageID) >> 1;
#endif
    fclose(File);
    mfree(SkinData);
  }
}

void FreeImage(Internal_Function *Data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  for (int i = 0; i < LastImage; i++)
    if (Data->MusicPlayer[i].ImageID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, Data->MusicPlayer[i].ImageHandle, 0, 0, Data->MusicPlayer[i].ImageID, 1, &error_code);
}

extern "C" int New_Music_Gui_NowPlaying_OnCreate(DISP_OBJ *disp_obj)
{
  Music_Gui_NowPlaying_OnCreate(disp_obj);

  Internal_Function *Data = Get_Internal_Function();
  Data->Music_Gui_NowPlaying = disp_obj;
  Data->TextID = EMPTY_TEXTID;
  LoadImage(Data);

  return 1;
}

extern "C" void New_Music_Gui_NowPlaying_OnClose(DISP_OBJ *disp_obj)
{
  Music_Gui_NowPlaying_OnClose(disp_obj);

  Internal_Function *Data = Get_Internal_Function();
  DESTROY_TEXTID(Data->TextID);
  FreeImage(Data);
  Delete_Internal_Function(Data);
}

extern "C" void New_Music_Gui_NowPlaying_OnRedraw(DISP_OBJ *disp, int a, int b, int c)
{
  Internal_Function *Data = Get_Internal_Function();
  Data->VolumeLevel = GetMediaVolume();

  DISP_OBJ_NOWPLAYING *disp_obj = (DISP_OBJ_NOWPLAYING *)disp;

  GC *pGC = get_DisplayGC();

  if (Data->Main.Background_Image.Enable)
  {
    if (Data->Portrait)
    {
      DrawImage(Data->MusicPlayer[MP_BG_PT].ImageID, Data->Main.Background_Image.x, Data->Main.Background_Image.y);
    }
    else
    {
      DrawImage(Data->MusicPlayer[MP_BG_LD].ImageID, Data->Main.Background_Image.x, Data->Main.Background_Image.y);
    }
  }

  if (Data->Main.AlbumArtEnable && !Data->Main.VisualisationEnable)
  {
    if (Data->CoverArtID == NOIMAGE)
    {
      Data->CoverArtID = Data->MusicPlayer[NO_COVER_ICN].ImageID;
    }
    DrawImageEx(pGC, Data->Main.ARect.x1, Data->Main.ARect.y1, Data->Main.ARect.x2 - Data->Main.ARect.x1, Data->Main.ARect.y2 - Data->Main.ARect.y1, Data->CoverArtID);
    DrawImageEx(pGC, Data->Main.ARect.x1, Data->Main.ARect.y1, Data->Main.ARect.x2 - Data->Main.ARect.x1, Data->Main.ARect.y2 - Data->Main.ARect.y1, Data->MusicPlayer[REFLECT].ImageID);
  }

  if (Data->Main.Overlay_Image.Enable)
  {
    if (Data->Portrait)
    {
      DrawImage(Data->MusicPlayer[OVERLAY_IMAGE_P].ImageID, Data->Main.Overlay_Image.x, Data->Main.Overlay_Image.y);
    }
    else
    {
      DrawImage(Data->MusicPlayer[OVERLAY_IMAGE_L].ImageID, Data->Main.Overlay_Image.x, Data->Main.Overlay_Image.y);
    }
  }

  if (Data->Main.EQ_Image.Enable)
  {
    switch (Data->MusicBook->EqPreset)
    {
#ifdef CLEARAUDIO
    case TMMEEqPreset_Normal:
      DrawImage(Data->MusicPlayer[MP_EQ_NORMAL_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_Heavy:
      DrawImage(Data->MusicPlayer[MP_EQ_VOICE_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_Pops:
      DrawImage(Data->MusicPlayer[MP_EQ_BASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_Jazz:
      DrawImage(Data->MusicPlayer[MP_EQ_BASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_Unique:
      DrawImage(Data->MusicPlayer[MP_EQ_VOICE_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_Soul:
      DrawImage(Data->MusicPlayer[MP_EQ_MEGABASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_EasyListening:
      DrawImage(Data->MusicPlayer[MP_EQ_MEGABASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_BassBoost:
      DrawImage(Data->MusicPlayer[MP_EQ_MEGABASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_TrebleBoost:
      DrawImage(Data->MusicPlayer[MP_EQ_TREBLEBOOST_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMMEEqPreset_Last:
      DrawImage(Data->MusicPlayer[MP_EQ_MANUAL_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
#else
    case TMusicServerEqPreset_Normal:
      DrawImage(Data->MusicPlayer[MP_EQ_NORMAL_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMusicServerEqPreset_Bass:
      DrawImage(Data->MusicPlayer[MP_EQ_BASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMusicServerEqPreset_Megabass:
      DrawImage(Data->MusicPlayer[MP_EQ_MEGABASS_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMusicServerEqPreset_Voice:
      DrawImage(Data->MusicPlayer[MP_EQ_VOICE_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMusicServerEqPreset_TrebleBoost:
      DrawImage(Data->MusicPlayer[MP_EQ_TREBLEBOOST_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
    case TMusicServerEqPreset_Manual:
      DrawImage(Data->MusicPlayer[MP_EQ_MANUAL_ICON].ImageID, Data->Main.EQ_Image.x, Data->Main.EQ_Image.y);
      break;
#endif
    }
  }

  if (Data->Main.Loop_Image.Enable)
  {
#ifdef REPEATONE
    if (get_envp(NULL, "RepeatOne"))
    {
      DrawImage(Data->MusicPlayer[MP_MODE_REPEAT_ONE_ICN].ImageID, Data->Main.Loop_Image.x, Data->Main.Loop_Image.y);
    }
#endif
    if (Data->MusicBook->Loop)
    {
      DrawImage(Data->MusicPlayer[MP_MODE_LOOP_ICN].ImageID, Data->Main.Loop_Image.x, Data->Main.Loop_Image.y);
    }
  }

  if (Data->Main.Shuffle_Image.Enable)
  {
    if (Data->MusicBook->Random)
    {
      DrawImage(Data->MusicPlayer[MP_MODE_RANDOM_ICN].ImageID, Data->Main.Shuffle_Image.x, Data->Main.Shuffle_Image.y);
    }
  }

  if (Data->Main.Title_Image.Enable)
  {
    if (Data->MusicPlayer[MP_TRACK_ICN].ImageID != NOIMAGE)
      DrawImage(Data->MusicPlayer[MP_TRACK_ICN].ImageID, Data->Main.Title_Image.x, Data->Main.Title_Image.y);
    else
#ifdef DB3150v1
      DrawImage(disp_obj->Track1, Data->Main.Title_Image.x, Data->Main.Title_Image.y);
#else
      DrawImage(disp_obj->Track->ImageID, Data->Main.Title_Image.x, Data->Main.Title_Image.y);
#endif
  }
  if (Data->Main.Artist_Image.Enable)
  {
    if (Data->MusicPlayer[MP_ARTIST_ICN].ImageID != NOIMAGE)
      DrawImage(Data->MusicPlayer[MP_ARTIST_ICN].ImageID, Data->Main.Artist_Image.x, Data->Main.Artist_Image.y);
    else
#ifdef DB3150v1
      DrawImage(disp_obj->Artist, Data->Main.Title_Image.x, Data->Main.Title_Image.y);
#else
      DrawImage(disp_obj->Artist->ImageID, Data->Main.Artist_Image.x, Data->Main.Artist_Image.y);
#endif
  }
  if (Data->Main.Album_Image.Enable)
  {
    if (Data->MusicPlayer[MP_ALBUM_ICN].ImageID != NOIMAGE)
      DrawImage(Data->MusicPlayer[MP_ALBUM_ICN].ImageID, Data->Main.Album_Image.x, Data->Main.Album_Image.y);
    else
#ifdef DB3150v1
      DrawImage(disp_obj->Album, Data->Main.Title_Image.x, Data->Main.Title_Image.y);
#else
      DrawImage(disp_obj->Album->ImageID, Data->Main.Album_Image.x, Data->Main.Album_Image.y);
#endif
  }

  if (Data->Main.PlayerState_Image.Enable)
  {
    switch (Data->MusicBook->PlayerState)
    {
    case TMusicServerState_Playing:
      DrawImage(Data->MusicPlayer[MP_PLAY_ICN].ImageID, Data->Main.PlayerState_Image.x, Data->Main.PlayerState_Image.y);
      break;
    case TMusicServerState_Initiated:
    case TMusicServerState_Paused:
      DrawImage(Data->MusicPlayer[MP_PAUSE_ICN].ImageID, Data->Main.PlayerState_Image.x, Data->Main.PlayerState_Image.y);
      break;
    case TMusicServerState_FastForwarding:
      DrawImage(Data->MusicPlayer[MP_FAST_FORWARD_ICN].ImageID, Data->Main.PlayerState_Image.x, Data->Main.PlayerState_Image.y);
      break;
    case TMusicServerState_Rewinding:
      DrawImage(Data->MusicPlayer[MP_REWIND_ICN].ImageID, Data->Main.PlayerState_Image.x, Data->Main.PlayerState_Image.y);
      break;
    }
  }

  if (Data->Main.WhellBG_Image.Enable)
  {
    DrawImage(Data->MusicPlayer[MC_WHEEL_BACKGROUND_ICN].ImageID, Data->Main.Album_Image.x, Data->Main.Album_Image.y);
  }

  if (Data->Main.WhellUP_Image.Enable)
  {
    DrawImage(Data->MusicPlayer[MC_WHEEL_UP_ICN].ImageID, Data->Main.WhellUP_Image.x, Data->Main.WhellUP_Image.y);
  }

  if (Data->Main.WhellDOWN_Image.Enable)
  {
    DrawImage(Data->MusicPlayer[MC_WHEEL_DOWN_ICN].ImageID, Data->Main.WhellDOWN_Image.x, Data->Main.WhellDOWN_Image.y);
  }

  if (Data->Main.WhellLEFT_Image.Enable)
  {
    if (Data->MusicBook->PlayerState == TMusicServerState_Rewinding)
    {
      DrawImage(Data->MusicPlayer[MC_WHEEL_REW_ICN].ImageID, Data->Main.WhellLEFT_Image.x, Data->Main.WhellLEFT_Image.y);
    }
    else
    {
      DrawImage(Data->MusicPlayer[MC_WHEEL_PREV_ICN].ImageID, Data->Main.WhellLEFT_Image.x, Data->Main.WhellLEFT_Image.y);
    }
  }
  if (Data->Main.WhellRIGHT_Image.Enable)
  {
    if (Data->MusicBook->PlayerState == TMusicServerState_FastForwarding)
    {
      DrawImage(Data->MusicPlayer[MC_WHEEL_FF_ICN].ImageID, Data->Main.WhellRIGHT_Image.x, Data->Main.WhellRIGHT_Image.y);
    }
    else
    {
      DrawImage(Data->MusicPlayer[MC_WHEEL_NEXT_ICN].ImageID, Data->Main.WhellRIGHT_Image.x, Data->Main.WhellRIGHT_Image.y);
    }
  }

  if (Data->Main.WhellCENTER_Image.Enable)
  {
    if (Data->MusicBook->PlayerState == TMusicServerState_Playing)
    {
      DrawImage(Data->MusicPlayer[MC_WHEEL_PAUSE_ICN].ImageID, Data->Main.WhellCENTER_Image.x, Data->Main.WhellCENTER_Image.y);
    }
    else
    {
      DrawImage(Data->MusicPlayer[MC_WHEEL_PLAY_ICN].ImageID, Data->Main.WhellCENTER_Image.x, Data->Main.WhellCENTER_Image.y);
    }
  }

  if (Data->Main.Title.Enable)
  {
    DrawText(Data->Main.Title.Font,
             disp_obj->TextID.Title,
             Data->Main.Title.Align,
             Data->Main.Title.x1,
             Data->Main.Title.y1,
             Data->Main.Title.x2 - Data->Main.Title.x1,
             Data->Main.Title.Color);
  }

  if (Data->Main.Artist.Enable)
  {
    DrawText(Data->Main.Artist.Font,
             disp_obj->TextID.Artist,
             Data->Main.Artist.Align,
             Data->Main.Artist.x1,
             Data->Main.Artist.y1,
             Data->Main.Artist.x2 - Data->Main.Artist.x1,
             Data->Main.Artist.Color);
  }

  if (Data->Main.Album.Enable)
  {
    DrawText(Data->Main.Album.Font,
             disp_obj->TextID.Album,
             Data->Main.Album.Align,
             Data->Main.Album.x1,
             Data->Main.Album.y1,
             Data->Main.Album.x2 - Data->Main.Album.x1,
             Data->Main.Album.Color);
  }

  if (Data->Main.Extension.Enable)
  {
    Data->TextID = TextID_Create(Data->Extension, ENC_UCS2, TEXTID_ANY_LEN);
    DrawText(Data->Main.Extension.Font,
             Data->TextID,
             Data->Main.Extension.Align,
             Data->Main.Extension.x1,
             Data->Main.Extension.y1,
             Data->Main.Extension.x2 - Data->Main.Extension.x1,
             Data->Main.Extension.Color);
  }

  if (Data->Main.C_TrackID.Enable)
  {
    Data->TextID = TextID_CreateIntegerID(Data->MusicBook->current_track_id + 1);
    DrawText(Data->Main.C_TrackID.Font,
             Data->TextID,
             Data->Main.C_TrackID.Align,
             Data->Main.C_TrackID.x1,
             Data->Main.C_TrackID.y1,
             Data->Main.C_TrackID.x2 - Data->Main.C_TrackID.x1,
             Data->Main.C_TrackID.Color);
  }

  if (Data->Main.TotalTrackID.Enable)
  {
    Data->TextID = TextID_CreateIntegerID(Data->MusicBook->tracks_count);
    DrawText(Data->Main.TotalTrackID.Font,
             Data->TextID,
             Data->Main.TotalTrackID.Align,
             Data->Main.TotalTrackID.x1,
             Data->Main.TotalTrackID.y1,
             Data->Main.TotalTrackID.x2 - Data->Main.TotalTrackID.x1,
             Data->Main.TotalTrackID.Color);
  }

  if (Data->Main.Genre.Enable)
  {
    Data->TextID = TextID_Create(Data->Genre, ENC_UCS2, TEXTID_ANY_LEN);
    DrawText(Data->Main.Genre.Font,
             Data->TextID,
             Data->Main.Genre.Align,
             Data->Main.Genre.x1,
             Data->Main.Genre.y1,
             Data->Main.Genre.x2 - Data->Main.Genre.x1,
             Data->Main.Genre.Color);
  }

  if (Data->Main.TotalTime.Enable)
  {
    Data->TextID = MusicServerTime2ID(Data->FullTime);
    DrawText(Data->Main.TotalTime.Font,
             Data->TextID,
             Data->Main.TotalTime.Align,
             Data->Main.TotalTime.x1,
             Data->Main.TotalTime.y1,
             Data->Main.TotalTime.x2 - Data->Main.TotalTime.x1,
             Data->Main.TotalTime.Color);
  }

  if (Data->Main.ElapsedTime.Enable)
  {
    Data->TextID = MusicServerTime2ID(Data->ElapsedTime);
    DrawText(Data->Main.ElapsedTime.Font,
             Data->TextID,
             Data->Main.ElapsedTime.Align,
             Data->Main.ElapsedTime.x1,
             Data->Main.ElapsedTime.y1,
             Data->Main.ElapsedTime.x2 - Data->Main.ElapsedTime.x1,
             Data->Main.ElapsedTime.Color);
  }

  if (Data->Main.RemainingTime.Enable)
  {
    Data->TextID = GetRemainingTime(Data);
    DrawText(Data->Main.RemainingTime.Font,
             Data->TextID,
             Data->Main.RemainingTime.Align,
             Data->Main.RemainingTime.x1,
             Data->Main.RemainingTime.y1,
             Data->Main.RemainingTime.x2 - Data->Main.RemainingTime.x1,
             Data->Main.RemainingTime.Color);
  }

  if (Data->Main.BitRate.Enable)
  {
    snwprintf(Data->Buffer, MAXELEMS(Data->Buffer), L"%d Kbps", Data->Bitrate);
    Data->TextID = TextID_Create(Data->Buffer, ENC_UCS2, TEXTID_ANY_LEN);
    DrawText(Data->Main.BitRate.Font,
             Data->TextID,
             Data->Main.BitRate.Align,
             Data->Main.BitRate.x1,
             Data->Main.BitRate.y1,
             Data->Main.BitRate.x2 - Data->Main.BitRate.x1,
             Data->Main.BitRate.Color);
  }

  if (Data->Main.ProgressBar.Enable)
  {
    DrawProgressBar(Data->ElapsedTimeInSeconds, Data->FullTimeInSeconds, Data->Main.ProgressBar.Rect, Data->Main.ProgressBar.BColor, Data->Main.ProgressBar.FColor);
  }

  if (Data->Main.VolumeBar.Enable)
  {
    DrawProgressBar(Data->VolumeLevel, MAX_MEDIAVOLUME, Data->Main.VolumeBar.Rect, Data->Main.VolumeBar.BColor, Data->Main.VolumeBar.FColor);
  }
}
