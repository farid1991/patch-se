#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "data.h"
#include "lang.h"
#include "setting.h"

DBP_DATA *CreateData()
{
  DBP_DATA *data = (DBP_DATA *)malloc(sizeof(DBP_DATA));
  memset(data, NULL, sizeof(DBP_DATA));
  data->mute = FALSE;
  data->path = NULL;
  data->name = NULL;
  data->fullpath = NULL;
  set_envp(NULL, EMP_NAME, (OSADDRESS)data);
  return data;
}

DBP_DATA *GetData()
{
  DBP_DATA *data = (DBP_DATA *)get_envp(NULL, EMP_NAME);
  if (data)
    return data;
  return CreateData();
}

void DeleteData(DBP_DATA *data)
{
  if (data)
  {
    FSX_FreeFullPath(data->fullpath);
    FREE_GUI(data->time_input);
    mfree(data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void SaveData(bool save, int item)
{
  DBP_DATA *data = GetData();

  if (item == ITEM_ARTIST)
  {
    data->setting.artist.state = data->temp.activate1;
    data->setting.artist.align = data->temp.align;
    data->setting.artist.tcolor = data->temp.color1;
    data->setting.artist.ocolor = data->temp.color2;
    data->setting.artist.overlay = data->temp.overlay;
    data->setting.artist.font = data->temp.font;
    data->setting.artist.coord.x1 = data->temp.x1;
    data->setting.artist.coord.y1 = data->temp.y1;
    data->setting.artist.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_TITLE)
  {
    data->setting.title.state = data->temp.activate1;
    data->setting.title.align = data->temp.align;
    data->setting.title.tcolor = data->temp.color1;
    data->setting.title.ocolor = data->temp.color2;
    data->setting.title.overlay = data->temp.overlay;
    data->setting.title.font = data->temp.font;
    data->setting.title.coord.x1 = data->temp.x1;
    data->setting.title.coord.y1 = data->temp.y1;
    data->setting.title.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_ALBUM)
  {
    data->setting.album.state = data->temp.activate1;
    data->setting.album.align = data->temp.align;
    data->setting.album.tcolor = data->temp.color1;
    data->setting.album.ocolor = data->temp.color2;
    data->setting.album.overlay = data->temp.overlay;
    data->setting.album.font = data->temp.font;
    data->setting.album.coord.x1 = data->temp.x1;
    data->setting.album.coord.y1 = data->temp.y1;
    data->setting.album.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_YEAR)
  {
    data->setting.year.state = data->temp.activate1;
    data->setting.year.align = data->temp.align;
    data->setting.year.tcolor = data->temp.color1;
    data->setting.year.ocolor = data->temp.color2;
    data->setting.year.overlay = data->temp.overlay;
    data->setting.year.font = data->temp.font;
    data->setting.year.coord.x1 = data->temp.x1;
    data->setting.year.coord.y1 = data->temp.y1;
    data->setting.year.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_GENRE)
  {
    data->setting.genre.state = data->temp.activate1;
    data->setting.genre.align = data->temp.align;
    data->setting.genre.tcolor = data->temp.color1;
    data->setting.genre.ocolor = data->temp.color2;
    data->setting.genre.overlay = data->temp.overlay;
    data->setting.genre.font = data->temp.font;
    data->setting.genre.coord.x1 = data->temp.x1;
    data->setting.genre.coord.y1 = data->temp.y1;
    data->setting.genre.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_FILETYPE)
  {
    data->setting.ext.state = data->temp.activate1;
    data->setting.ext.align = data->temp.align;
    data->setting.ext.tcolor = data->temp.color1;
    data->setting.ext.ocolor = data->temp.color2;
    data->setting.ext.overlay = data->temp.overlay;
    data->setting.ext.font = data->temp.font;
    data->setting.ext.coord.x1 = data->temp.x1;
    data->setting.ext.coord.y1 = data->temp.y1;
    data->setting.ext.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_TOTAL)
  {
    data->setting.time_t.state = data->temp.activate1;
    data->setting.time_t.align = data->temp.align;
    data->setting.time_t.tcolor = data->temp.color1;
    data->setting.time_t.ocolor = data->temp.color2;
    data->setting.time_t.overlay = data->temp.overlay;
    data->setting.time_t.font = data->temp.font;
    data->setting.time_t.coord.x1 = data->temp.x1;
    data->setting.time_t.coord.y1 = data->temp.y1;
    data->setting.time_t.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_ELAPSED)
  {
    data->setting.time_e.state = data->temp.activate1;
    data->setting.time_e.align = data->temp.align;
    data->setting.time_e.tcolor = data->temp.color1;
    data->setting.time_e.ocolor = data->temp.color2;
    data->setting.time_e.overlay = data->temp.overlay;
    data->setting.time_e.font = data->temp.font;
    data->setting.time_e.coord.x1 = data->temp.x1;
    data->setting.time_e.coord.y1 = data->temp.y1;
    data->setting.time_e.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_REMAINING)
  {
    data->setting.time_r.state = data->temp.activate1;
    data->setting.time_r.align = data->temp.align;
    data->setting.time_r.tcolor = data->temp.color1;
    data->setting.time_r.ocolor = data->temp.color2;
    data->setting.time_r.overlay = data->temp.overlay;
    data->setting.time_r.font = data->temp.font;
    data->setting.time_r.coord.x1 = data->temp.x1;
    data->setting.time_r.coord.y1 = data->temp.y1;
    data->setting.time_r.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_BITRATE)
  {
    data->setting.bitrate.state = data->temp.activate1;
    data->setting.bitrate.align = data->temp.align;
    data->setting.bitrate.tcolor = data->temp.color1;
    data->setting.bitrate.ocolor = data->temp.color2;
    data->setting.bitrate.overlay = data->temp.overlay;
    data->setting.bitrate.font = data->temp.font;
    data->setting.bitrate.coord.x1 = data->temp.x1;
    data->setting.bitrate.coord.y1 = data->temp.y1;
    data->setting.bitrate.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_SAMPLERATE)
  {
    data->setting.samplerate.state = data->temp.activate1;
    data->setting.samplerate.align = data->temp.align;
    data->setting.samplerate.tcolor = data->temp.color1;
    data->setting.samplerate.ocolor = data->temp.color2;
    data->setting.samplerate.overlay = data->temp.overlay;
    data->setting.samplerate.font = data->temp.font;
    data->setting.samplerate.coord.x1 = data->temp.x1;
    data->setting.samplerate.coord.y1 = data->temp.y1;
    data->setting.samplerate.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_AUDIOOUTPUT)
  {
    data->setting.audiooutput.state = data->temp.activate1;
    data->setting.audiooutput.align = data->temp.align;
    data->setting.audiooutput.tcolor = data->temp.color1;
    data->setting.audiooutput.ocolor = data->temp.color2;
    data->setting.audiooutput.overlay = data->temp.overlay;
    data->setting.audiooutput.font = data->temp.font;
    data->setting.audiooutput.coord.x1 = data->temp.x1;
    data->setting.audiooutput.coord.y1 = data->temp.y1;
    data->setting.audiooutput.coord.x2 = data->temp.x2;
  }
  else if (item == ITEM_TIME_PROGRESS)
  {
    data->setting.time.state = data->temp.activate1;
    data->setting.time.slider = data->temp.activate2;
    data->setting.time.round = data->temp.activate3;
    data->setting.time.progress_bcolor = data->temp.color1;
    data->setting.time.progress_fcolor = data->temp.color2;
    data->setting.time.progress_rect.x1 = data->temp.x1;
    data->setting.time.progress_rect.y1 = data->temp.y1;
    data->setting.time.progress_rect.x2 = data->temp.x2;
    data->setting.time.progress_rect.y2 = data->temp.y2;
  }
  else if (item == ITEM_VOLUME_PROGRESS)
  {
    data->setting.volume.state = data->temp.activate1;
    data->setting.volume.slider = data->temp.activate2;
    data->setting.volume.round = data->temp.activate3;
    data->setting.volume.progress_bcolor = data->temp.color1;
    data->setting.volume.progress_fcolor = data->temp.color2;
    data->setting.volume.progress_rect.x1 = data->temp.x1;
    data->setting.volume.progress_rect.y1 = data->temp.y1;
    data->setting.volume.progress_rect.x2 = data->temp.x2;
    data->setting.volume.progress_rect.y2 = data->temp.y2;
  }
  else if (item == ITEM_COVERART)
  {
    data->setting.cover = data->temp.activate1;
    data->setting.cover_rect.x1 = data->temp.x1;
    data->setting.cover_rect.y1 = data->temp.y1;
    data->setting.cover_rect.x2 = data->temp.x2;
    data->setting.cover_rect.y2 = data->temp.y2;
  }
  else if (item == ITEM_FRAME)
  {
    data->setting.frame.state = data->temp.activate1;
    data->setting.frame.pos.x = data->temp.x1;
    data->setting.frame.pos.y = data->temp.y1;
  }
  else if (item == ITEM_ARTIST_ICN)
  {
    data->setting.artist_icn.state = data->temp.activate1;
    data->setting.artist_icn.pos.x = data->temp.x1;
    data->setting.artist_icn.pos.y = data->temp.y1;
  }
  else if (item == ITEM_TITLE_ICN)
  {
    data->setting.title_icn.state = data->temp.activate1;
    data->setting.title_icn.pos.x = data->temp.x1;
    data->setting.title_icn.pos.y = data->temp.y1;
  }
  else if (item == ITEM_ALBUM_ICN)
  {
    data->setting.album_icn.state = data->temp.activate1;
    data->setting.album_icn.pos.x = data->temp.x1;
    data->setting.album_icn.pos.y = data->temp.y1;
  }
  else if (item == ITEM_PLAYERSTATE_ICN)
  {
    data->setting.playerstate_icn.state = data->temp.activate1;
    data->setting.playerstate_icn.pos.x = data->temp.x1;
    data->setting.playerstate_icn.pos.y = data->temp.y1;
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
#ifndef DB3350
    data->setting.animation = data->temp.activate3;
#endif
  }

  if (save)
  {
    int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_WRONLY, FSX_S_IWRITE | FSX_S_IREAD, NULL);
    if (file >= NULL)
    {
      fwrite(file, &data->setting, sizeof(SETTING_DATA));
      fclose(file);
    }
  }
}

void LoadData(DBP_DATA *Data)
{
  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= NULL)
  {
    memset(&Data->setting, NULL, sizeof(SETTING_DATA));
    fread(file, &Data->setting, sizeof(SETTING_DATA));
    fclose(file);
  }
}
