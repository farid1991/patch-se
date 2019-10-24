#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "ReadFile.h"
#include "main.h"

int ReadConfig(FILE_DATA * data)
{
  const char * format = "BG color: %x\r\nColumn empty color: %x\r\nColumn fill color: %x\r\nLevel color: %x\r\nCursor color: %x\r\n"
    "Enable level: %x\r\nEnable icon: %x\r\n"
    "Cursor position: %x\r\n"
    "Overlay: %d,%d\r\n"
    "Column width: %d\r\nColumn height: %d\r\n"
    "Column Media: %d,%d\r\n"
    "Column Ring: %d,%d\r\n"
    "Column Call: %d,%d\r\n"
    "Cursor Media: %d,%d\r\n"
    "Cursor Ring: %d,%d\r\n"
    "Cursor Call: %d,%d\r\n"
    "Level font: %x\r\n"
    "Level align media: %d\r\nLevel align ring: %d\r\nLevel align call: %d\r\n"
    "Level Media: %d,%d,%d,%d\r\n"
    "Level Ring: %d,%d,%d,%d\r\n"
    "Level Call: %d,%d,%d,%d\r\n"
    "Icon Media: %d,%d\r\n"
    "Icon Ring: %d,%d\r\n"
    "Icon Call: %d,%d\r\n";
  
  int res = 0;
  FSTAT fs;
  
  if (!fstat(ImagePath, CfgName, &fs) && fs.fsize)
  {
    char * buf = (char*)malloc(fs.fsize);
    int f = _fopen(ImagePath, CfgName, FSX_O_RDONLY, FSX_S_IRUSR|FSX_S_IWUSR, 0);
    fread(f, buf, fs.fsize);
    fclose(f);
    
    if (sscanf(buf, format, &data->Background_Color, &data->Column_BG_Color, &data->Column_Fll_Color, &data->Level_Color, &data->Cursor_Color,
               &data->Level_Enable, &data->Icon_Enable,
               &data->Cursor_Position,
               &data->Overlay_x, &data->Overlay_y,
               &data->Column_Width, &data->Column_Height,
               &data->Column_Media_x, &data->Column_Media_y,
               &data->Column_Ring_x, &data->Column_Ring_y,
               &data->Column_Call_x, &data->Column_Call_y,
               &data->Cursor_Media_x, &data->Cursor_Media_y,
               &data->Cursor_Ring_x, &data->Cursor_Ring_y,
               &data->Cursor_Call_x, &data->Cursor_Call_y,
               &data->Font_Level,
               &data->Align_Level_Media, &data->Align_Level_Ring, &data->Align_Level_Call,
               &data->Level_Media_x1, &data->Level_Media_y1, &data->Level_Media_x2, &data->Level_Media_y2,
               &data->Level_Ring_x1, &data->Level_Ring_y1, &data->Level_Ring_x2, &data->Level_Ring_y2,
               &data->Level_Call_x1, &data->Level_Call_y1, &data->Level_Call_x2, &data->Level_Call_y2,
               &data->Icon_Media_x, &data->Icon_Media_y,
               &data->Icon_Ring_x, &data->Icon_Ring_y,
               &data->Icon_Call_x, &data->Icon_Call_y) == data_count ) res = 1;
    mfree(buf);
  }
  return res;
}

