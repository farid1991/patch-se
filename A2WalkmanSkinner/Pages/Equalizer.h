#ifndef __Equalizer_H__
#define __Equalizer_H__

#define CONFIG_PATH L"/usb/other/ZBin/Config/Equalizer"
#define CONFIG_NAME L"EqSettings.bin"

#define MP_EQ_ACTIONSWITCH 0
#define MP_EQ_ACTIONSELECT 1

typedef struct
{
  uint8_t preset;
  bool manual;

  int8_t boost_level;
  int8_t bar1_level;
  int8_t bar2_level;
  int8_t bar3_level;
  int8_t bar4_level;
  int8_t bar5_level;
} EQ_SETTINGS;

void SetEqualizerGain(BOOK *book, int band, int level);
void SetEqualizerBands(BOOK *book, int8_t bar0, int8_t bar1, int8_t bar2, int8_t bar3, int8_t bar4, int8_t bar5);

#endif
