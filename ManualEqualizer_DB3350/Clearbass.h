#ifndef __Clearbass_H__
#define __Clearbass_H__

#define CONFIG_NAME L"eq.bin"
#define CONFIG_PATH L"/usb/other/Equalizer"

static const char Gui_Clearbass[] = "Clearbass_Equalizer_Display";

typedef struct IMG
{
  IMAGEID ImageID;
  u16 ImageHandle;
} IMG;

typedef struct
{
  bool manual;
  signed char boost_level;
  signed char bar1_level;
  signed char bar2_level;
  signed char bar3_level;
  signed char bar4_level;
  signed char bar5_level;
} EQ_SETTINGS;

const int redrect_positions[6][4] =
    {
        /* x    y   w   h */
        {  16, 168, 52, 5},
        {  75, 152, 27, 3},
        { 106, 152, 27, 3},
        { 137, 152, 27, 3},
        { 168, 152, 27, 3},
        { 199, 152, 27, 3},
};

enum Bar_Level
{
  Bar_Minus_3 = 0,
  Bar_Minus_2,
  Bar_Minus_1,
  Bar_Netral,
  Bar_Plus_1,
  Bar_Plus_2,
  Bar_Plus_3,
  LastBarLevel
};

enum Boost_Level
{
  Boost_0 = 0,
  Boost_1,
  Boost_2,
  Boost_3,
  LastBoostLevel
};

enum Eq_Band
{
  Eq_Band0 = 0,
  Eq_Band1,
  Eq_Band2,
  Eq_Band3,
  Eq_Band4,
  Eq_Band5,
  LastEQBand
};

typedef struct _DISP_OBJ_CLEARBASS : DISP_OBJ
{
  uint16_t height;
  uint16_t width;

  uint8_t cursor;

  int32_t boost_level;
  int32_t bar1_level;
  int32_t bar2_level;
  int32_t bar3_level;
  int32_t bar4_level;
  int32_t bar5_level;

  IMG Background;
  IMG Bar_Image[LastBarLevel];
  IMG Boost_Image[LastBoostLevel];
} DISP_OBJ_CLEARBASS;

GUI *Create_ClearbassGUI(BOOK *book);
void GUIObject_Clearbass_SetBarLevel(GUI *gui, int32_t b0, int32_t b1, int32_t b2, int32_t b3, int32_t b4, int32_t b5);
void GUIObject_Clearbass_GetBarLevel(GUI *gui, int32_t *b0, int32_t *b1, int32_t *b2, int32_t *b3, int32_t *b4, int32_t *b5);

#endif
