#ifndef __Clearbass_H__
#define __Clearbass_H__

static const char Gui_Clearbass[] = "Clearbass_Equalizer_Display";

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

enum ClearbassPreset
{
  Eq_Treble = 0,
  Eq_Heavy,
  Eq_Pop,
  Eq_Jazz,
  Eq_Normal,
  Eq_Unique,
  Eq_Soul,
  Eq_Light,
  Eq_Bass,
  LastPreset
};

const int8_t settings_table [LastPreset][LastEQBand] = {
  {   0,   0,   0,   0,   0,   3   },  //Treble
  {   3,   0,  -1,   1,   1,   0   },  //Heavy
  {   0,   1,   1,   0,   0,  -1   },  //Pop
  {   3,   0,   0,  -2,   0,   1   },  //Jazz
  {   0,   0,   0,   0,   0,   0   },  //Normal
  {   3,   0,   1,   0,  -1,   2   },  //Unique
  {   3,   0,   0,   2,   0,   0   },  //Soul
  {   3,  -2,   0,   1,   0,   2   },  //Light
  {   3,   3,   0,   0,   0,   0   }   //Bass
};

typedef struct _DISP_OBJ_CLEARBASS : DISP_OBJ
{
  uint16_t height;
  uint16_t width;
  bool manual;

  uint8_t preset_cursor;
  uint8_t manual_cursor;

  int8_t boost_level;
  int8_t bar1_level;
  int8_t bar2_level;
  int8_t bar3_level;
  int8_t bar4_level;
  int8_t bar5_level;

  TEXTID PresetName;

  IMG Background;
  IMG Preset_Image[LastPreset];
  IMG Bar_Image[LastBarLevel];
  IMG Boost_Image[LastBoostLevel];
} DISP_OBJ_CLEARBASS;

GUI *Create_ClearbassGUI(BOOK *book);
BOOL GUIObject_Clearbass_GetState(GUI *gui);
int GUIObject_Clearbass_GetPresetCursor(GUI *gui);
void GUIObject_Clearbass_SetCursorToItem(GUI *gui, int item);
void GUIObject_Clearbass_Switch(GUI *gui, bool state);
void GUIObject_Clearbass_SetState(GUI *gui, bool manual);
void GUIObject_Clearbass_SetBarLevel(GUI *gui, int b0, int b1, int b2, int b3, int b4, int b5);
void GUIObject_Clearbass_GetBarLevel(GUI *gui, int *b0, int *b1, int *b2, int *b3, int *b4, int *b5);

#endif
