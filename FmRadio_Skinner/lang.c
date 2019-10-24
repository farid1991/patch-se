#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "lang.h"

TEXTID TextID_Global(int item_id)
{
  wchar_t* result;
  switch (item_id)
  {
  case ID_PTYPE_1: result = TEXT_PTYPE_1; break;
  case ID_PTYPE_2: result = TEXT_PTYPE_2; break;
  case ID_COLOR_OVERLAY: result = TEXT_COLOR_OVERLAY; break;
  case ID_ALIGN: result = TEXT_ALIGN; break;
  case ID_VISUAL: result = TEXT_VISUAL; break;
  case ID_SLIDER: result = TEXT_SLIDER; break;
  case ID_COLOR_F: result = TEXT_COLOR_F; break;
  case ID_SOFT: result = TEXT_SOFT; break;
  case ID_SHOW: result = TEXT_SHOW; break;
  case ID_FREQUENCY: result = TEXT_FREQUENCY; break;
  case ID_CHANNEL: result = TEXT_CHANNEL; break;
  case ID_CHANNEL_NAME: result = TEXT_CHANNEL_NAME; break;
  case ID_FREQ_INDICATOR: result = TEXT_FREQ_INDICATOR; break;
  case ID_RDS_ICN: result = TEXT_RDS_ICN; break;
  case ID_AF_ICN: result = TEXT_AF_ICN; break;
  case ID_AUDIO_ICN: result = TEXT_AUDIO_ICN; break;
  }
  return TextID_Create(result, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID TextID_Setting(int item_id)
{
  TEXTID text = EMPTY_TEXTID;
  switch (item_id)
  {
  case 0: text = TextID_Global(ID_FREQUENCY); break;
  case 1: text = TextID_Global(ID_CHANNEL); break;
  case 2: text = TextID_Global(ID_CHANNEL_NAME); break;
  case 3: text = TEXT_RDS; break;
  case 4: text = TextID_Global(ID_FREQ_INDICATOR); break;
  case 5: text = TextID_Global(ID_RDS_ICN); break;
  case 6: text = TextID_Global(ID_AF_ICN); break;
  case 7: text = TextID_Global(ID_AUDIO_ICN); break;
  case 8: text = TEXT_NAV_LEFT; break;
  case 9: text = TEXT_NAV_RIGHT; break;
  case 10: text = TEXT_NAV_UP; break;
  case 11: text = TEXT_NAV_DOWN; break;
  case 12: text = TEXT_BACKROUND; break;
  case 13: text = TEXT_ADDITIONAL; break;
  }
  return text;
}
