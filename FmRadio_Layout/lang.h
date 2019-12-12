#ifndef _LANG_H_
#define _LANG_H_

typedef enum
{
  ID_PTYPE_1,
  ID_PTYPE_2,
  ID_COLOR_OVERLAY,
  ID_ALIGN,
  ID_VISUAL,
  ID_SLIDER,
  ID_COLOR_F,
  ID_SOFT,
  ID_SHOW,
  ID_FREQUENCY,
  ID_CHANNEL,
  ID_CHANNEL_NAME,
  ID_FREQ_INDICATOR,
  ID_RDS_ICN,
  ID_AF_ICN,
  ID_AUDIO_ICN
}TEXT_ID;

#define TEXT_PTYPE_1          L"Type 1"
#define TEXT_PTYPE_2          L"Type 2"
#define TEXT_COLOR_OVERLAY    L"Overlay color"
#define TEXT_ALIGN            L"Align"
#define TEXT_VISUAL           L"Visual"
#define TEXT_SLIDER           L"Slider"
#define TEXT_COLOR_F          L"Fill Color"
#define TEXT_SOFT             L"Softkeys"
#define TEXT_SAMPLERATE       L"Samplerate"
#define TEXT_AUDIOOUTPUT      L"Audio Output"
#define TEXT_SHOW             L"Show"

#define TEXT_FREQUENCY      L"Frequency"
#define TEXT_CHANNEL        L"Channel"
#define TEXT_RDS_DATA       L"RDS Info"
#define TEXT_CHANNEL_NAME   L"Channel Name"
#define TEXT_FREQ_INDICATOR L"Frequency Indicator"

#define TEXT_RDS_ICN          L"RDS Icon"
#define TEXT_AF_ICN           L"AF Icon"
#define TEXT_AUDIO_ICN        L"Audio Icon"

TEXTID TextID_Global(int id);
TEXTID TextID_Setting(int id);

#endif
