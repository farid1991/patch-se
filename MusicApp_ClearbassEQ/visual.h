#ifndef _VISUAL_H_
#define _VISUAL_H_

static const char Gui_Clearbass[] = "Clearbass_Equalizer_Display";

#define FREE_GUI(gui) if (gui) { gui=GUIObject_Destroy(gui); gui = NULL; }
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a)
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

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

typedef struct _DISP_OBJ_CLEARBASS : DISP_OBJ
{
  u16 height;
  u16 width;
  BOOL preset;
  char cursor;
  
  char manual;
  char boost;
  char bar1;
  char bar2;
  char bar3;
  char bar4;
  char bar5;
  
  char boost_level;
  char bar1_level;
  char bar2_level;
  char bar3_level;
  char bar4_level;
  char bar5_level;
  
  TEXTID Title;
  TEXTID PresetName;
  IMG Image[11];
} DISP_OBJ_CLEARBASS;

GUI* Create_ClearbassGUI(BOOK* book);

BOOL DispObj_Clearbass_GetState(DISP_OBJ_CLEARBASS* disp_obj);
int DispObject_Clearbass_GetCursor(DISP_OBJ_CLEARBASS* disp_obj);
void DispObj_Clearbass_SetCursorToItem(DISP_OBJ_CLEARBASS* disp_obj, int item);
void GUI_Clearbass_Switch(GUI* gui, BOOL state);
void DispObj_Clearbass_SetTitleText(DISP_OBJ_CLEARBASS* disp_obj, TEXTID title);

BOOL GUI_Clearbass_GetState(GUI* gui);
int GUI_Clearbass_GetCursor(GUI* gui);
void GUI_Clearbass_SetCursorToItem(GUI* gui, int item);
void GUI_Clearbass_Switch(GUI* gui, BOOL state);
void GUI_Clearbass_SetTitleText(GUI* gui, TEXTID title);

#endif
