/*
;Fm Radio Layout Editor
;- Ability to hide/show all items.
;- Ability to change coordinates of each item in realtime.
;- Ability to choose Text color, font, etc.
;- Ability to use color or Theme Image on the background.
;v. 1.2
;(c) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\FmRadio_Book.h"

#include "main.h"
#include "data.h"
#include "setting.h"
#include "lang.h"
#include "editor.h"

#define EMP_NAME "FmRadio"

FmRadio_Data* Create_Data()
{
  FmRadio_Data* Data = (FmRadio_Data*)malloc(sizeof(FmRadio_Data));
  memset(Data, NULL, sizeof(FmRadio_Data));
  set_envp(NULL, EMP_NAME, (OSADDRESS)Data);
  return Data;
}

FmRadio_Data* Get_Data()
{
  FmRadio_Data* Data = (FmRadio_Data*) get_envp(NULL, EMP_NAME);
  if (Data) return Data;
  return Create_Data();
}

extern "C"
void DeleteData()
{
  FmRadio_Data* data = (FmRadio_Data*)get_envp(NULL, EMP_NAME);
  if (data)
  {
    mfree(data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void SaveData(bool save, int item)
{
  FmRadio_Data* data = Get_Data();
  
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#define temp_font data->temp.font + (data->style_bold<<8) + (data->style_italic<<9);
#else
#define temp_font data->temp.font;
#endif
  if (item == ITEM_FREQUENCY)
  {
    data->setting.frequency.state = data->temp.activate1;
    data->setting.frequency.align = data->temp.align;
    data->setting.frequency.tcolor = data->temp.color1;
    data->setting.frequency.ocolor = data->temp.color2;
    data->setting.frequency.overlay = data->temp.overlay;
    data->setting.frequency.font = temp_font;
    data->setting.frequency.coord.x1 = data->temp.x1;
    data->setting.frequency.coord.y1 = data->temp.y1;
    data->setting.frequency.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_CHANNEL)
  {
    data->setting.channel.state = data->temp.activate1;
    data->setting.channel.align = data->temp.align;
    data->setting.channel.tcolor = data->temp.color1;
    data->setting.channel.ocolor = data->temp.color2;
    data->setting.channel.overlay = data->temp.overlay;
    data->setting.channel.font = temp_font;
    data->setting.channel.coord.x1 = data->temp.x1;
    data->setting.channel.coord.y1 = data->temp.y1;
    data->setting.channel.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_CHANNELNAME)
  {
    data->setting.channel_name.state = data->temp.activate1;
    data->setting.channel_name.align = data->temp.align;
    data->setting.channel_name.tcolor = data->temp.color1;
    data->setting.channel_name.ocolor = data->temp.color2;
    data->setting.channel_name.overlay = data->temp.overlay;
    data->setting.channel_name.font = temp_font;
    data->setting.channel_name.coord.x1 = data->temp.x1;
    data->setting.channel_name.coord.y1 = data->temp.y1;
    data->setting.channel_name.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_RDS_DATA)
  {
    data->setting.RDS_data.state = data->temp.activate1;
    data->setting.RDS_data.align = data->temp.align;
    data->setting.RDS_data.tcolor = data->temp.color1;
    data->setting.RDS_data.ocolor = data->temp.color2;
    data->setting.RDS_data.overlay = data->temp.overlay;
    data->setting.RDS_data.font = temp_font;
    data->setting.RDS_data.coord.x1 = data->temp.x1;
    data->setting.RDS_data.coord.y1 = data->temp.y1;
    data->setting.RDS_data.coord.x2 = data->temp.x2;
  }
  
  else if (item == ITEM_FREQ_INDICATOR)
  {
    data->setting.freq_indicator.state = data->temp.activate1;
    data->setting.freq_indicator.slider = data->temp.activate2;
    data->setting.freq_indicator.round = data->temp.activate3;
    data->setting.freq_indicator.progress_bcolor = data->temp.color1;
    data->setting.freq_indicator.progress_fcolor = data->temp.color2;
    data->setting.freq_indicator.progress_rect.x1 = data->temp.x1;
    data->setting.freq_indicator.progress_rect.y1 = data->temp.y1;
    data->setting.freq_indicator.progress_rect.x2 = data->temp.x2;
    data->setting.freq_indicator.progress_rect.y2 = data->temp.y2;
  }

  else if (item == ITEM_RDS_ICN)
  { 
    data->setting.rds_icn.state = data->temp.activate1;
    data->setting.rds_icn.pos.x = data->temp.x1;
    data->setting.rds_icn.pos.y = data->temp.y1;
  }
  else if (item == ITEM_AF_ICN)
  { 
    data->setting.af_icn.state = data->temp.activate1;
    data->setting.af_icn.pos.x = data->temp.x1;
    data->setting.af_icn.pos.y = data->temp.y1;
  }
  else if (item == ITEM_AUDIO_ICN)
  { 
    data->setting.audio_icn.state = data->temp.activate1;
    data->setting.audio_icn.pos.x = data->temp.x1;
    data->setting.audio_icn.pos.y = data->temp.y1;
  }
  
  else if (item == ITEM_ARROW_LEFT)
  { 
    data->setting.arrow_left.state = data->temp.activate1;
    data->setting.arrow_left.pos.x = data->temp.x1;
    data->setting.arrow_left.pos.y = data->temp.y1;
  }
  else if (item == ITEM_ARROW_RIGHT)
  { 
    data->setting.arrow_right.state = data->temp.activate1;
    data->setting.arrow_right.pos.x = data->temp.x1;
    data->setting.arrow_right.pos.y = data->temp.y1;
  }
  else if (item == ITEM_ARROW_UP)
  { 
    data->setting.arrow_up.state = data->temp.activate1;
    data->setting.arrow_up.pos.x = data->temp.x1;
    data->setting.arrow_up.pos.y = data->temp.y1;
  }
  else if (item == ITEM_ARROW_DOWN)
  { 
    data->setting.arrow_down.state = data->temp.activate1;
    data->setting.arrow_down.pos.x = data->temp.x1;
    data->setting.arrow_down.pos.y = data->temp.y1;
  }

  else if (item == ITEM_BACKROUND)
  {
    data->setting.background.state = data->temp.activate1;
    data->setting.background_color = data->temp.color1;
    data->setting.background.pos.x = data->temp.x1;
    data->setting.background.pos.y = data->temp.y1;
  }
  else if (item == ITEM_ADDITIONAL)
  {
    data->setting.screen = data->temp.activate1;
    data->setting.soft = data->temp.activate2;
    data->setting.animation = data->temp.activate3;
  }
  
  if (save)
  {
    int file = _fopen( FILE_PATH, FILE_NAME, FSX_O_WRONLY, FSX_S_IWRITE|FSX_S_IREAD, NULL );
    if(file >= NULL) 
    {
      fwrite(file, &data->setting, sizeof(SETTING_DATA));
      fclose(file);
    }
  }
}

void LoadData()
{
  FmRadio_Data* data = Get_Data();
  int file = _fopen( FILE_PATH, FILE_NAME, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL );
  if(file >= 0) 
  {
    fread(file, &data->setting, sizeof(SETTING_DATA));
    fclose(file);
  }
}
