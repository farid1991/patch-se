#ifndef _LANG_H_
#define _LANG_H_

typedef enum
{
  ID_TAG_EDITOR = 0,
  ID_PTYPE_1,
  ID_PTYPE_2,
  ID_ARTIST,
  ID_TITLE,
  ID_ALBUM,
  ID_EXT,
  ID_TOTAL,
  ID_ELAPSED,
  ID_REMAINING,
  ID_BITRATE,
  ID_TIME_PROGRESS,
  ID_VOLUME_PROGRESS,
  ID_FRAME,
  ID_COLOR_OVERLAY,
  ID_ALIGN,
  ID_VISUAL,
  ID_SLIDER,
  ID_COLOR_F,
  ID_SOFT,
  ID_SAMPLERATE,
  ID_AUDIOOUTPUT,
  ID_SHOW,
  ID_ARTIST_ICN,
  ID_TITLE_ICN,
  ID_ALBUM_ICN,
  ID_PLAYERSTATE_ICN
}TEXT_ID;

#define TEXT_TAG_EDITOR       L"Edit tag"
#define TEXT_PTYPE_1          L"Type 1"
#define TEXT_PTYPE_2          L"Type 2"
#define TEXT_ARTIST           L"Artist"
#define TEXT_TITLE            L"Title"
#define TEXT_ALBUM            L"Album"
#define TEXT_EXT              L"File Extension"
#define TEXT_TIME_T           L"Total time"
#define TEXT_TIME_E           L"Elapsed time"
#define TEXT_TIME_R           L"Remaining time"
#define TEXT_BITRATE          L"Bitrate"
#define TEXT_TIME_PROGRESS    L"Time (bar)"
#define TEXT_VOLUME_PROGRESS  L"Volume (bar)"
#define TEXT_FRAME            L"Frame"
#define TEXT_COLOR_OVERLAY    L"Overlay color"
#define TEXT_ALIGN            L"Align"
#define TEXT_VISUAL           L"Visual"
#define TEXT_SLIDER           L"Slider"
#define TEXT_COLOR_F          L"Fill Color"
#define TEXT_SOFT             L"Softkeys"
#define TEXT_SAMPLERATE       L"Samplerate"
#define TEXT_AUDIOOUTPUT      L"Audio Output"
#define TEXT_SHOW             L"Show"
#define TEXT_ARTIST_ICN       L"Artist Icon"
#define TEXT_TITLE_ICN        L"Title Icon"
#define TEXT_ALBUM_ICN        L"Album Icon"
#define TEXT_PLAYERSTATE_ICN  L"State Icon"

TEXTID TextID_Global(int id);
TEXTID TextID_Setting(int id);

#endif
