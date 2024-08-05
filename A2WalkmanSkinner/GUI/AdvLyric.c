#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\classes\IMusicServer.h"

#include "..\\Colors.h"
#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\String.h"

#include "..\\Pages\Lyric.h"

#include "AdvLyric.h"

//==============================================================================

int AdvLyric_OnCreate(DISP_OBJ_ADVLYRIC *disp_obj)
{
  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main);
  disp_obj->line_space = disp_obj->disp_height >> 3;

  disp_obj->fastchanged = FALSE;
  disp_obj->show_inactive = FALSE;
  disp_obj->is_centered = TRUE;

  disp_obj->TitleText = EMPTY_TEXTID;
  for (int i = 0; i < 100; i++)
  {
    disp_obj->LrcText[i] = EMPTY_TEXTID;
  }
  DispObject_SetBacklightMode(disp_obj, UIBacklightMode_On);
  return 1;
}

void AdvLyric_OnClose(DISP_OBJ_ADVLYRIC *disp_obj)
{
  DESTROY_TEXTID(disp_obj->TitleText);
  for (int i = 0; i < 100; i++)
  {
    DESTROY_TEXTID(disp_obj->LrcText[i]);
  }
  DispObject_SetBacklightMode(disp_obj, UIBacklightMode_Automatic);
}

void AdvLyric_OnRedraw(DISP_OBJ_ADVLYRIC *disp_obj, int r1, int r2, int r3)
{
  GUI *gui = DispObject_GetGUI(disp_obj);
  AdvLyricBook *Lrc = (AdvLyricBook *)GUIObject_GetBook(gui);

  disp_obj->media_volume = GetMediaVolume();

  if (Lrc->CurrentIndex == LRC_NOTFOUND)
  {
    disp_obj->TitleText = STR("No Lyric Found");
    DrawTextEx(FONT_E_16B,
               disp_obj->TitleText,
               AlignCenter,
               0,
               (disp_obj->disp_height >> 1),
               disp_obj->disp_width,
               disp_obj->disp_height,
               SELECTION_COLOR);
  }

  if (Lrc->LrcList)
  {
    if (Lrc->CurrentIndex == LRC_PREPARING)
    {
      disp_obj->TitleText = STR("Prepare lyrics...");
      DrawTextEx(FONT_E_16B,
                 disp_obj->TitleText,
                 AlignCenter,
                 0,
                 (disp_obj->disp_height >> 1),
                 disp_obj->disp_width,
                 disp_obj->disp_height,
                 SELECTION_COLOR);
    }
    else if (Lrc->CurrentIndex >= LRC_READY)
    {
      int pos = 0;
      int pos1 = 0;

      for (int i = Lrc->CurrentIndex - 1; i >= 0; i--)
      {
        disp_obj->LrcText[i] = TextID_Create(Lrc->LrcList[i].LrcInfo, ENC_UCS2, TEXTID_ANY_LEN);

        int width1 = GetTextIDWidth(FONT_E_16R, disp_obj->LrcText[i], TextID_GetLength(disp_obj->LrcText[i]));

        if (width1 <= disp_obj->disp_width)
          pos1 -= disp_obj->line_space * 1;
        if ((width1 > disp_obj->disp_width) && (width1 <= (disp_obj->disp_width * 2)))
          pos1 -= disp_obj->line_space * 2;
        if (width1 > (disp_obj->disp_width * 2) && width1 <= (disp_obj->disp_width * 3))
          pos1 -= disp_obj->line_space * 3;
        if (width1 > (disp_obj->disp_width * 3) && width1 <= (disp_obj->disp_width * 4))
          pos1 -= disp_obj->line_space * 4;

        if (disp_obj->show_inactive)
          DrawTextEx(FONT_E_16R,
                     disp_obj->LrcText[i],
                     disp_obj->is_centered ? AlignCenter : AlignLeft,
                     0,
                     disp_obj->line_space * 5 + pos1 - Lrc->Length,
                     disp_obj->disp_width,
                     disp_obj->disp_height,
                     UNSELECTED_TEXT_COLOR);

        if (disp_obj->line_space * 4 + pos1 - Lrc->Length < (0 - (disp_obj->line_space * 2)))
          break;
      }

      if (Lrc->CurrentIndex >= 0)
      {
        disp_obj->LrcText[Lrc->CurrentIndex] = TextID_Create(Lrc->LrcList[Lrc->CurrentIndex].LrcInfo, ENC_UCS2, TEXTID_ANY_LEN);

        int width2 = GetTextIDWidth(FONT_E_16B, disp_obj->LrcText[Lrc->CurrentIndex], TextID_GetLength(disp_obj->LrcText[Lrc->CurrentIndex]));

        DrawTextEx(FONT_E_16B,
                   disp_obj->LrcText[Lrc->CurrentIndex],
                   disp_obj->is_centered ? AlignCenter : AlignLeft,
                   0,
                   disp_obj->line_space * 5 - Lrc->Length,
                   disp_obj->disp_width,
                   disp_obj->disp_height,
                   SELECTION_COLOR);

        if (width2 <= disp_obj->disp_width)
          pos += disp_obj->line_space * 1;
        if (width2 > disp_obj->disp_width && width2 <= disp_obj->disp_width * 2)
          pos += disp_obj->line_space * 2;
        if (width2 > disp_obj->disp_width * 2 && width2 <= disp_obj->disp_width * 3)
          pos += disp_obj->line_space * 3;
        if (width2 > disp_obj->disp_width * 3 && width2 <= disp_obj->disp_width * 4)
          pos += disp_obj->line_space * 4;
      }
      for (int i = (Lrc->CurrentIndex + 1); i < 100 && i >= 0; i++)
      {
        disp_obj->LrcText[i] = TextID_Create(Lrc->LrcList[i].LrcInfo, ENC_UCS2, TEXTID_ANY_LEN);

        int width3 = GetTextIDWidth(FONT_E_16R, disp_obj->LrcText[i], TextID_GetLength(disp_obj->LrcText[i]));
        if (disp_obj->show_inactive)
          DrawTextEx(FONT_E_16R,
                     disp_obj->LrcText[i],
                     disp_obj->is_centered ? AlignCenter : AlignLeft,
                     0,
                     disp_obj->line_space * 5 + pos - Lrc->Length,
                     disp_obj->disp_width,
                     disp_obj->disp_height,
                     UNSELECTED_TEXT_COLOR);

        if (disp_obj->line_space * 5 + pos - Lrc->Length > (disp_obj->line_space * 6))
          break;
        if (width3 <= disp_obj->disp_width)
          pos += disp_obj->line_space * 1;
        if (width3 > disp_obj->disp_width && width3 <= disp_obj->disp_width * 2)
          pos += disp_obj->line_space * 2;
        if (width3 > disp_obj->disp_width * 2 && width3 <= disp_obj->disp_width * 3)
          pos += disp_obj->line_space * 3;
        if (width3 > disp_obj->disp_width * 3 && width3 <= disp_obj->disp_width * 4)
          pos += disp_obj->line_space * 4;
      }
    }
  }
}

void AdvLyric_OnLayout(DISP_OBJ_ADVLYRIC *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, BG_TRANSPARENT_COLOR);
}

void AdvLyric_OnKey(DISP_OBJ_ADVLYRIC *disp_obj, int key, int count, int repeat, int mode)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)FindBook(IsAudioPlayerBook);

  GUI *gui = DispObject_GetGUI(disp_obj);
  AdvLyricBook *Lrc = (AdvLyricBook *)GUIObject_GetBook(gui);

  switch (mode)
  {
  case KBD_LONG_PRESS:
    switch (key)
    {
    case KEY_LEFT:
    case KEY_DIGITAL_4:
      MusicBook->pMusicServer->Rewind();
      Kill_LyricShowTimer(Lrc);
      break;
    case KEY_RIGHT:
    case KEY_DIGITAL_6:
      MusicBook->pMusicServer->FastFoward();
      Kill_LyricShowTimer(Lrc);
      break;
    }
    break;
  case KBD_LONG_RELEASE:
    switch (key)
    {
    case KEY_LEFT:
    case KEY_DIGITAL_4:
    case KEY_RIGHT:
    case KEY_DIGITAL_6:
      MusicBook->pMusicServer->Play(MusicBook->current_track_id);
      disp_obj->fastchanged = TRUE;
      break;
    }
    break;
  case KBD_SHORT_RELEASE:
    switch (key)
    {
    case KEY_DIGITAL_0:
      disp_obj->show_inactive ? disp_obj->show_inactive = FALSE : disp_obj->show_inactive = TRUE;
      break;
    case KEY_DIGITAL_5:
      disp_obj->is_centered ? disp_obj->is_centered = FALSE : disp_obj->is_centered = TRUE;
      break;
    case KEY_UP:
      if (disp_obj->media_volume < MAX_MEDIAVOLUME)
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, ++disp_obj->media_volume + 18);
      break;
    case KEY_DOWN:
      if (disp_obj->media_volume)
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, --disp_obj->media_volume + 18);
      break;
    case KEY_LEFT:
    case KEY_DIGITAL_4:
      MusicBook->pMusicServer->Previous();
      break;
    case KEY_RIGHT:
    case KEY_DIGITAL_6:
      MusicBook->pMusicServer->Next(TRUE);
      break;
    case KEY_ENTER:
      if (MusicBook->PlayerState == TMusicServerState_Playing)
      {
        MusicBook->pMusicServer->Pause();
      }
      else if (MusicBook->PlayerState == TMusicServerState_Initiated || MusicBook->PlayerState == TMusicServerState_Paused)
      {
        MusicBook->pMusicServer->Play(MusicBook->current_track_id);
      }
      Kill_LyricShowTimer(Lrc);
      break;
    }
    break;
  }
  DispObject_InvalidateRect(disp_obj, NULL);
}

void AdvLyric_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_Lyric);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_ADVLYRIC));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)AdvLyric_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)AdvLyric_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)AdvLyric_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)AdvLyric_OnKey);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)AdvLyric_OnLayout);
}

void AdvLyric_destruct(GUI_Lyric *gui)
{
}

void AdvLyric_callback(DISP_OBJ *disp, void *msg, GUI *gui)
{
}

GUI_Lyric *CreateAdvLyric(BOOK *book)
{
  GUI_Lyric *gui_lyric = (GUI_Lyric *)malloc(sizeof(GUI_Lyric));
  if (!GUIObject_Create(gui_lyric, AdvLyric_destruct, AdvLyric_construct, book, AdvLyric_callback, UIDisplay_Main, sizeof(GUI_Lyric)))
  {
    mfree(gui_lyric);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gui_lyric);

  GUIObject_SetStyle(gui_lyric, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_lyric, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_lyric);

  return gui_lyric;
}
