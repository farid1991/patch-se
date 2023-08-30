#ifndef _READFILE_H_
#define _READFILE_H_

typedef struct
{
  unsigned int Background_Color;
  unsigned int Column_BG_Color;
  unsigned int Column_Fll_Color;
  unsigned int Level_Color;
  unsigned int Cursor_Color;

  int Level_Enable;
  int Icon_Enable;

  int Cursor_Position;

  int Overlay_x;
  int Overlay_y;

  int Column_Width;
  int Column_Height;

  int Column_Media_x;
  int Column_Media_y;
  int Column_Ring_x;
  int Column_Ring_y;
  int Column_Call_x;
  int Column_Call_y;

  int Icon_Media_x;
  int Icon_Media_y;
  int Icon_Ring_x;
  int Icon_Ring_y;
  int Icon_Call_x;
  int Icon_Call_y;

  int Font_Level;

  int Align_Level_Media;
  int Align_Level_Ring;
  int Align_Level_Call;

  int Level_Media_x1;
  int Level_Media_y1;
  int Level_Media_x2;
  int Level_Media_y2;
  int Level_Ring_x1;
  int Level_Ring_y1;
  int Level_Ring_x2;
  int Level_Ring_y2;
  int Level_Call_x1;
  int Level_Call_y1;
  int Level_Call_x2;
  int Level_Call_y2;

  int Cursor_Media_x;
  int Cursor_Media_y;
  int Cursor_Ring_x;
  int Cursor_Ring_y;
  int Cursor_Call_x;
  int Cursor_Call_y;
} FILE_DATA;

#define data_count sizeof(FILE_DATA) / sizeof(int)

int ReadConfig(FILE_DATA *data);

#endif
