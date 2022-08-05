#ifndef _ADDVLYRIC_H_
#define _ADDVLYRIC_H_

#define TIME_LIMIT 86399
#define LYRIC_GUI_ANIMATION 0x60021000
#define LYRIC_GUI_LAYERCOLOR 0x773F3F3F

static const char Gui_Lyric[] = "Music_Gui_Lyric";

typedef struct GUI GUI_Lyric;

typedef struct _DISP_OBJ_ADVLYRIC : DISP_OBJ
{
  int fastchanged;
  uint16_t disp_width;
  uint16_t disp_height;
  int media_volume;
  TEXTID TitleText;
  TEXTID LrcText[100];
} DISP_OBJ_ADVLYRIC;

GUI_Lyric *CreateAdvLyric(BOOK *book);

#endif
