#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "lang.h"

TEXTID TextID_Global(int id)
{
  wchar_t* result;
  switch (id)
  {
  case ID_TAG_EDITOR: result = TEXT_TAG_EDITOR; break;
  case ID_PTYPE_1: result = TEXT_PTYPE_1; break;
  case ID_PTYPE_2: result = TEXT_PTYPE_2; break;
  case ID_ARTIST: result = TEXT_ARTIST; break;
  case ID_TITLE: result = TEXT_TITLE; break;
  case ID_ALBUM: result = TEXT_ALBUM; break;
  case ID_EXT: result = TEXT_EXT; break;
  case ID_TOTAL: result = TEXT_TIME_T; break;
  case ID_ELAPSED: result = TEXT_TIME_E; break;
  case ID_REMAINING: result = TEXT_TIME_R; break;
  case ID_BITRATE: result = TEXT_BITRATE; break;
  case ID_TIME_PROGRESS: result = TEXT_TIME_PROGRESS; break;
  case ID_VOLUME_PROGRESS: result = TEXT_VOLUME_PROGRESS; break;
  case ID_FRAME: result = TEXT_FRAME; break;
  case ID_COLOR_OVERLAY: result = TEXT_COLOR_OVERLAY; break;
  case ID_ALIGN: result = TEXT_ALIGN; break;
  case ID_VISUAL: result = TEXT_VISUAL; break;
  case ID_SLIDER: result = TEXT_SLIDER; break;
  case ID_COLOR_F: result = TEXT_COLOR_F; break;
  case ID_SOFT: result = TEXT_SOFT; break;
  case ID_SAMPLERATE: result = TEXT_SAMPLERATE; break;
  case ID_AUDIOOUTPUT: result = TEXT_AUDIOOUTPUT; break;
  case ID_SHOW: result = TEXT_SHOW; break;
  case ID_ARTIST_ICN: result = TEXT_ARTIST_ICN; break;
  case ID_TITLE_ICN: result = TEXT_TITLE_ICN; break;
  case ID_ALBUM_ICN: result = TEXT_ALBUM_ICN; break;
  case ID_PLAYERSTATE_ICN: result = TEXT_PLAYERSTATE_ICN; break;
  }
  return TextID_Create(result, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID TextID_Setting(int id)
{
  TEXTID text = EMPTY_TEXTID;
  switch (id)
  {
  case 0: text = TextID_Global(ID_ARTIST); break;
  case 1: text = TextID_Global(ID_TITLE); break;
  case 2: text = TextID_Global(ID_ALBUM); break;
  case 3: text = TEXT_YEAR; break;
  case 4: text = TEXT_GENRE; break;
  case 5: text = TextID_Global(ID_EXT); break;
  case 6: text = TextID_Global(ID_TOTAL); break;
  case 7: text = TextID_Global(ID_ELAPSED); break;
  case 8: text = TextID_Global(ID_REMAINING); break;
  case 9: text = TextID_Global(ID_BITRATE); break;
  case 10: text = TextID_Global(ID_SAMPLERATE); break;
  case 11: text = TextID_Global(ID_AUDIOOUTPUT); break;
  case 12: text = TextID_Global(ID_TIME_PROGRESS); break;
  case 13: text = TextID_Global(ID_VOLUME_PROGRESS); break;
  case 14: text = TEXT_COVER; break;
  case 15: text = TextID_Global(ID_FRAME); break;
  case 16: text = TextID_Global(ID_ARTIST_ICN); break;
  case 17: text = TextID_Global(ID_TITLE_ICN); break;
  case 18: text = TextID_Global(ID_ALBUM_ICN); break;
  case 19: text = TextID_Global(ID_PLAYERSTATE_ICN); break;
  case 20: text = TEXT_BACKROUND; break;
  case 21: text = TEXT_ADDITIONAL; break;
  }
  return text;
}
