#ifndef _VISUAL_H_
#define _VISUAL_H_

typedef signed char INT8;

static const char Gui_Clearbass[] = "Clearbass_Equalizer_Display";

#define FREE_GUI(gui) if (gui) { gui=GUIObject_Destroy(gui); gui = NULL; }
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a)
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

const int redrect_positions[6][4] = 
{ /*  x      y      w    h   */
  {   16,   168,   52,   5   },
  {   75,   152,   27,   3   },
  {  106,   152,   27,   3   },
  {  137,   152,   27,   3   },
  {  168,   152,   27,   3   },
  {  199,   152,   27,   3   },
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
  Boost_1 = 0,
  Boost_2,
  Boost_3,
  Boost_4,
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

typedef struct _IMG
{
  IMAGEID ID;
  u16 Handle;
} IMG;

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

typedef struct _EQ_LEVEL
{
  INT8 boost;
  INT8 bar1;
  INT8 bar2;
  INT8 bar3;
  INT8 bar4;
  INT8 bar5;
} EQ_LEVEL;

typedef struct _DISP_OBJ_CLEARBASS : DISP_OBJ
{
  u16 height;
  u16 width;
  bool preset;
  
  char preset_cursor;
  char manual_cursor;

  INT8 boost_level;
  INT8 bar1_level;
  INT8 bar2_level;
  INT8 bar3_level;
  INT8 bar4_level;
  INT8 bar5_level;
  
  EQ_LEVEL level;
  
  TEXTID Title;
  TEXTID PresetName;
  
  IMG Background;
  IMG Preset_Image[LastPreset];
  IMG Bar_Image[LastBarLevel];
  IMG Boost_Image[LastBoostLevel];
} DISP_OBJ_CLEARBASS;

GUI* Create_ClearbassGUI(BOOK* book);
BOOL GUI_Clearbass_GetState(GUI* gui);
int GUI_Clearbass_GetPresetCursor(GUI* gui);
void GUI_Clearbass_SetCursorToItem(GUI* gui, int item);
void GUI_Clearbass_Switch(GUI* gui, BOOL state);
void GUI_Clearbass_SetTitleText(GUI* gui, TEXTID title);
void GUI_Clearbass_SetState(GUI* gui, BOOL manual);
void GUI_Clearbass_SetBarLevel(GUI* gui, int b0, int b1, int b2, int b3, int b4, int b5);
void GUI_Clearbass_GetBarLevel(GUI* gui, int *b0, int *b1, int *b2, int *b3, int *b4, int *b5);

#endif
