#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "lang.h"
#include "setting.h"

TEXTID TextID_Global(int text_id)
{
  char *str;
  switch (text_id)
  {
  case ID_PTYPE:
    str = TEXT_PTYPE;
    break;
  case ID_PTYPE_1:
    str = TEXT_PTYPE_1;
    break;
  case ID_PTYPE_2:
    str = TEXT_PTYPE_2;
    break;
  case ID_ARTIST:
    str = TEXT_ARTIST;
    break;
  case ID_TITLE:
    str = TEXT_TITLE;
    break;
  case ID_ALBUM:
    str = TEXT_ALBUM;
    break;
  case ID_YEAR:
    str = TEXT_YEAR;
    break;
  case ID_GENRE:
    str = TEXT_GENRE;
    break;
  case ID_FILETYPE:
    str = TEXT_FILETYPE;
    break;
  case ID_TOTAL:
    str = TEXT_TIME_T;
    break;
  case ID_ELAPSED:
    str = TEXT_TIME_E;
    break;
  case ID_REMAINING:
    str = TEXT_TIME_R;
    break;
  case ID_BITRATE:
    str = TEXT_BITRATE;
    break;
  case ID_TIME_PROGRESS:
    str = TEXT_TIME_PROGRESS;
    break;
  case ID_VOLUME_PROGRESS:
    str = TEXT_VOLUME_PROGRESS;
    break;
  case ID_COVERART:
    str = TEXT_COVERART;
    break;
  case ID_FRAME:
    str = TEXT_FRAME;
    break;
  case ID_TEXT_COLOR:
    str = TEXT_TEXT_COLOR;
    break;
  case ID_COLOR_OVERLAY:
    str = TEXT_COLOR_OVERLAY;
    break;
  case ID_ALIGN:
    str = TEXT_ALIGN;
    break;
  case ID_ALIGN_LEFT:
    str = TEXT_ALIGN_LEFT;
    break;
  case ID_ALIGN_RIGHT:
    str = TEXT_ALIGN_RIGHT;
    break;
  case ID_ALIGN_CENTER:
    str = TEXT_ALIGN_CENTER;
    break;
  case ID_VISUAL_CONFIG:
    str = TEXT_VISUAL_CONFIG;
    break;
  case ID_SLIDER:
    str = TEXT_SLIDER;
    break;
  case ID_COLOR_F:
    str = TEXT_COLOR_F;
    break;
  case ID_FULLSCREEN:
    str = TEXT_FULLSCREEN;
    break;
  case ID_SOFTKEYS:
    str = TEXT_SOFTKEYS;
    break;
  case ID_SAMPLERATE:
    str = TEXT_SAMPLERATE;
    break;
  case ID_AUDIOOUTPUT:
    str = TEXT_AUDIOOUTPUT;
    break;
  case ID_STATE:
    str = TEXT_STATE;
    break;
  case ID_ARTIST_ICN:
    str = TEXT_ARTIST_ICN;
    break;
  case ID_TITLE_ICN:
    str = TEXT_TITLE_ICN;
    break;
  case ID_ALBUM_ICN:
    str = TEXT_ALBUM_ICN;
    break;
  case ID_PLAYERSTATE_ICN:
    str = TEXT_PLAYERSTATE_ICN;
    break;
  case ID_BACKGROUND:
    str = TEXT_BACKGROUND;
    break;
  case ID_BACKGROUND_IMAGE:
    str = TEXT_BACKGROUND_IMAGE;
    break;
  case ID_BACKGROUND_THEME:
    str = TEXT_BACKGROUND_THEME;
    break;
  case ID_BACKGROUND_COLOR:
    str = TEXT_BACKGROUND_COLOR;
    break;
  case ID_ADDITIONAL:
    str = TEXT_ADDITIONAL;
    break;
#ifndef DB3350
  case ID_TAG_EDITOR:
    str = TEXT_TAG_EDITOR;
    break;
#endif
  }
  return TextID_Create(str, ENC_LAT1, TEXTID_ANY_LEN);
}

TEXTID TextID_Setting(int id)
{
  TEXTID text_id;
  switch (id)
  {
  case ITEM_ARTIST:
    text_id = TextID_Global(ID_ARTIST);
    break;
  case ITEM_TITLE:
    text_id = TextID_Global(ID_TITLE);
    break;
  case ITEM_ALBUM:
    text_id = TextID_Global(ID_ALBUM);
    break;
  case ITEM_YEAR:
    text_id = TextID_Global(ID_YEAR);
    break;
  case ITEM_GENRE:
    text_id = TextID_Global(ID_GENRE);
    break;
  case ITEM_FILETYPE:
    text_id = TextID_Global(ID_FILETYPE);
    break;
  case ITEM_TOTAL:
    text_id = TextID_Global(ID_TOTAL);
    break;
  case ITEM_ELAPSED:
    text_id = TextID_Global(ID_ELAPSED);
    break;
  case ITEM_REMAINING:
    text_id = TextID_Global(ID_REMAINING);
    break;
  case ITEM_BITRATE:
    text_id = TextID_Global(ID_BITRATE);
    break;
  case ITEM_SAMPLERATE:
    text_id = TextID_Global(ID_SAMPLERATE);
    break;
  case ITEM_AUDIOOUTPUT:
    text_id = TextID_Global(ID_AUDIOOUTPUT);
    break;
  case ITEM_TIME_PROGRESS:
    text_id = TextID_Global(ID_TIME_PROGRESS);
    break;
  case ITEM_VOLUME_PROGRESS:
    text_id = TextID_Global(ID_VOLUME_PROGRESS);
    break;
  case ITEM_COVERART:
    text_id = TextID_Global(ID_COVERART);
    break;
  case ITEM_FRAME:
    text_id = TextID_Global(ID_FRAME);
    break;
  case ITEM_ARTIST_ICN:
    text_id = TextID_Global(ID_ARTIST_ICN);
    break;
  case ITEM_TITLE_ICN:
    text_id = TextID_Global(ID_TITLE_ICN);
    break;
  case ITEM_ALBUM_ICN:
    text_id = TextID_Global(ID_ALBUM_ICN);
    break;
  case ITEM_PLAYERSTATE_ICN:
    text_id = TextID_Global(ID_PLAYERSTATE_ICN);
    break;
  case ITEM_BACKROUND:
    text_id = TextID_Global(ID_BACKGROUND);
    break;
  case ITEM_ADDITIONAL:
    text_id = TextID_Global(ID_ADDITIONAL);
    break;
  }
  return text_id;
}
