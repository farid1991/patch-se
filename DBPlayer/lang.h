#ifndef _LANG_H_
#define _LANG_H_

typedef enum TEXT_ID
{
  ID_PTYPE,
  ID_PTYPE_1,
  ID_PTYPE_2,
  ID_ARTIST,
  ID_TITLE,
  ID_ALBUM,
  ID_YEAR,
  ID_GENRE,
  ID_FILEFORMAT,
  ID_TOTAL,
  ID_ELAPSED,
  ID_REMAINING,
  ID_BITRATE,
  ID_TIME_PROGRESS,
  ID_VOLUME_PROGRESS,
  ID_COVERART,
  ID_FRAME,
  ID_TEXT_COLOR,
  ID_COLOR_OVERLAY,
  ID_ALIGN,
  ID_ALIGN_LEFT,
  ID_ALIGN_RIGHT,
  ID_ALIGN_CENTER,
  ID_VISUAL_CONFIG,
  ID_SLIDER,
  ID_COLOR_F,
  ID_FULLSCREEN,
  ID_SOFTKEYS,
  ID_SAMPLERATE,
  ID_AUDIOOUTPUT,
  ID_STATE,
  ID_ARTIST_ICN,
  ID_TITLE_ICN,
  ID_ALBUM_ICN,
  ID_PLAYERSTATE_ICN,
  ID_BACKGROUND,
  ID_BACKGROUND_IMAGE,
  ID_BACKGROUND_THEME,
  ID_BACKGROUND_COLOR,
  ID_ADDITIONAL,
  ID_TAG_EDITOR,
} TEXT_ID;

#define TEXT_ID_PTYPE L"Type"
#define TEXT_ID_TAG_EDITOR L"Edit tag"
#define TEXT_ID_PTYPE_1 L"Type 1"
#define TEXT_ID_PTYPE_2 L"Type 2"
#define TEXT_ID_ARTIST L"Artist"
#define TEXT_ID_TITLE L"Title"
#define TEXT_ID_ALBUM L"Album"
#define TEXT_ID_YEAR L"Year"
#define TEXT_ID_GENRE L"Genre"
#define TEXT_ID_FILEFORMAT L"File Format"
#define TEXT_ID_TIME_T L"Total time"
#define TEXT_ID_TIME_E L"Elapsed time"
#define TEXT_ID_TIME_R L"Remaining time"
#define TEXT_ID_BITRATE L"Bitrate"
#define TEXT_ID_TIME_PROGRESS L"Time (bar)"
#define TEXT_ID_VOLUME_PROGRESS L"Volume (bar)"
#define TEXT_ID_COVERART L"Cover Art"
#define TEXT_ID_FRAME L"Frame"
#define TEXT_ID_TEXT_COLOR L"Text color"
#define TEXT_ID_COLOR_OVERLAY L"Overlay color"
#define TEXT_ID_ALIGN L"Align"
#define TEXT_ID_ALIGN_LEFT L"Left"
#define TEXT_ID_ALIGN_RIGHT L"Right"
#define TEXT_ID_ALIGN_CENTER L"Center"
#define TEXT_ID_VISUAL_CONFIG L"Visual editor"
#define TEXT_ID_SLIDER L"Slider"
#define TEXT_ID_COLOR_F L"Fill color"
#define TEXT_ID_FULLSCREEN L"Fullscreen"
#define TEXT_ID_SOFTKEYS L"SoftKeys"
#define TEXT_ID_SAMPLERATE L"Samplerate"
#define TEXT_ID_AUDIOOUTPUT L"Audio output"
#define TEXT_ID_STATE L"State"
#define TEXT_ID_ARTIST_ICN L"Artist Icon"
#define TEXT_ID_TITLE_ICN L"Title Icon"
#define TEXT_ID_ALBUM_ICN L"Album Icon"
#define TEXT_ID_PLAYERSTATE_ICN L"State Icon"
#define TEXT_ID_BACKGROUND L"Background"
#define TEXT_ID_BACKGROUND_IMAGE L"Image"
#define TEXT_ID_BACKGROUND_THEME L"Theme Image"
#define TEXT_ID_BACKGROUND_COLOR L"Custom Color"
#define TEXT_ID_ADDITIONAL L"Additional"

TEXTID TextID_Global(int id);
TEXTID TextID_Setting(int id);

#endif
