#ifndef _VIZ_H_
#define _VIZ_H_

void DestroyVizOOM( BOOK* book, GUI* gui);
void VizOOM_onEnter( BOOK* book, GUI* gui);
int VIZOOM_callback( GUI_MESSAGE* msg );
int GetChecked();
void SetChecked( int level, BOOK* book );
int VizPageOnCreate( void* mess, BOOK* book );
int GetSkinID();
int GetVizCount();
void Enter_VizSelector(BOOK* book, GUI* gui);

typedef enum 
{
  ITEM_ALBUMART=0,
  ITEM_VIZ,
  ITEM_OFF,
  ITEM_LAST
}SelectViz;

static const char Gui_VizBoard[] = "Gui_VizBoard";

typedef struct _DISP_OBJ_VIZBOARD : DISP_OBJ
{
  int count;
  int cursor;
  TEXTID text_id;
  IMAGEID VizIMG_ID;
} DISP_OBJ_VIZBOARD;

#endif
