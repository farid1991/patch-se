#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "lang.h"
#include "setting.h"

TEXTID TextID_Global(int id)
{
  wchar_t *result;
  switch (id)
  {
  case ID_PTYPE:
    result = TEXT_ID_PTYPE;
    break;
  case ID_PTYPE_1:
    result = TEXT_ID_PTYPE_1;
    break;
  case ID_PTYPE_2:
    result = TEXT_ID_PTYPE_2;
    break;
  case ID_ARTIST:
    result = TEXT_ID_ARTIST;
    break;
  case ID_TITLE:
    result = TEXT_ID_TITLE;
    break;
  case ID_ALBUM:
    result = TEXT_ID_ALBUM;
    break;
  case ID_YEAR:
    result = TEXT_ID_YEAR;
    break;
  case ID_GENRE:
    result = TEXT_ID_GENRE;
    break;
  case ID_FILEFORMAT:
    result = TEXT_ID_FILEFORMAT;
    break;
  case ID_TOTAL:
    result = TEXT_ID_TIME_T;
    break;
  case ID_ELAPSED:
    result = TEXT_ID_TIME_E;
    break;
  case ID_REMAINING:
    result = TEXT_ID_TIME_R;
    break;
  case ID_BITRATE:
    result = TEXT_ID_BITRATE;
    break;
  case ID_TIME_PROGRESS:
    result = TEXT_ID_TIME_PROGRESS;
    break;
  case ID_VOLUME_PROGRESS:
    result = TEXT_ID_VOLUME_PROGRESS;
    break;
  case ID_COVERART:
    result = TEXT_ID_COVERART;
    break;
  case ID_FRAME:
    result = TEXT_ID_FRAME;
    break;
  case ID_TEXT_COLOR:
    result = TEXT_ID_TEXT_COLOR;
    break;
  case ID_COLOR_OVERLAY:
    result = TEXT_ID_COLOR_OVERLAY;
    break;
  case ID_ALIGN:
    result = TEXT_ID_ALIGN;
    break;
  case ID_ALIGN_LEFT:
    result = TEXT_ID_ALIGN_LEFT;
    break;
  case ID_ALIGN_RIGHT:
    result = TEXT_ID_ALIGN_RIGHT;
    break;
  case ID_ALIGN_CENTER:
    result = TEXT_ID_ALIGN_CENTER;
    break;
  case ID_VISUAL_CONFIG:
    result = TEXT_ID_VISUAL_CONFIG;
    break;
  case ID_SLIDER:
    result = TEXT_ID_SLIDER;
    break;
  case ID_COLOR_F:
    result = TEXT_ID_COLOR_F;
    break;
  case ID_FULLSCREEN:
    result = TEXT_ID_FULLSCREEN;
    break;
  case ID_SOFTKEYS:
    result = TEXT_ID_SOFTKEYS;
    break;
  case ID_SAMPLERATE:
    result = TEXT_ID_SAMPLERATE;
    break;
  case ID_AUDIOOUTPUT:
    result = TEXT_ID_AUDIOOUTPUT;
    break;
  case ID_STATE:
    result = TEXT_ID_STATE;
    break;
  case ID_ARTIST_ICN:
    result = TEXT_ID_ARTIST_ICN;
    break;
  case ID_TITLE_ICN:
    result = TEXT_ID_TITLE_ICN;
    break;
  case ID_ALBUM_ICN:
    result = TEXT_ID_ALBUM_ICN;
    break;
  case ID_PLAYERSTATE_ICN:
    result = TEXT_ID_PLAYERSTATE_ICN;
    break;
  case ID_BACKGROUND:
    result = TEXT_ID_BACKGROUND;
    break;
  case ID_BACKGROUND_IMAGE:
    result = TEXT_ID_BACKGROUND_IMAGE;
    break;
  case ID_BACKGROUND_THEME:
    result = TEXT_ID_BACKGROUND_THEME;
    break;
  case ID_BACKGROUND_COLOR:
    result = TEXT_ID_BACKGROUND_COLOR;
    break;
  case ID_ADDITIONAL:
    result = TEXT_ID_ADDITIONAL;
    break;
#ifndef DB3350
  case ID_TAG_EDITOR:
    result = TEXT_ID_TAG_EDITOR;
    break;
#endif
  }
  return TextID_Create(result, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID TextID_Setting(int id)
{
  switch (id)
  {
  case ITEM_ARTIST:
    return TextID_Global(ID_ARTIST);
  case ITEM_TITLE:
    return TextID_Global(ID_TITLE);
  case ITEM_ALBUM:
    return TextID_Global(ID_ALBUM);
  case ITEM_YEAR:
    return TextID_Global(ID_YEAR);
  case ITEM_GENRE:
    return TextID_Global(ID_GENRE);
  case ITEM_FILEFORMAT:
    return TextID_Global(ID_FILEFORMAT);
  case ITEM_TOTAL:
    return TextID_Global(ID_TOTAL);
  case ITEM_ELAPSED:
    return TextID_Global(ID_ELAPSED);
  case ITEM_REMAINING:
    return TextID_Global(ID_REMAINING);
  case ITEM_BITRATE:
    return TextID_Global(ID_BITRATE);
  case ITEM_SAMPLERATE:
    return TextID_Global(ID_SAMPLERATE);
  case ITEM_AUDIOOUTPUT:
    return TextID_Global(ID_AUDIOOUTPUT);
  case ITEM_TIME_PROGRESS:
    return TextID_Global(ID_TIME_PROGRESS);
  case ITEM_VOLUME_PROGRESS:
    return TextID_Global(ID_VOLUME_PROGRESS);
  case ITEM_COVERART:
    return TextID_Global(ID_COVERART);
  case ITEM_FRAME:
    return TextID_Global(ID_FRAME);
  case ITEM_ARTIST_ICN:
    return TextID_Global(ID_ARTIST_ICN);
  case ITEM_TITLE_ICN:
    return TextID_Global(ID_TITLE_ICN);
  case ITEM_ALBUM_ICN:
    return TextID_Global(ID_ALBUM_ICN);
  case ITEM_PLAYERSTATE_ICN:
    return TextID_Global(ID_PLAYERSTATE_ICN);
  case ITEM_BACKROUND:
    return TextID_Global(ID_BACKGROUND);
  case ITEM_ADDITIONAL:
    return TextID_Global(ID_ADDITIONAL);
  default:
    return EMPTY_TEXTID;
  }
}
