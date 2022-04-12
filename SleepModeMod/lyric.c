#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "main.h"
#include "StrLib.h"
#include "lyric.h"

void TimerList_Free(TimerList *lrclist)
{
  int list_num;
  for (list_num = 0; list_num < MAX_TIMER; list_num++)
  {
    if (lrclist[list_num].lrcinfo != NULL)
    {
      mfree(lrclist[list_num].lrcinfo);
      lrclist[list_num].lrcinfo = NULL;
    }
  }
  mfree(lrclist);
}

void Lyric_FreeData(SLEEPMODE_DATA *data)
{
  if (data->lrclist)
    TimerList_Free(data->lrclist);
  FREE(data->lrcbuf);
}

int find_current_timer_list(time_t tm, SLEEPMODE_DATA *data)
{
  int i = 0;
  while (i <= data->total_offset)
  {
    if ((tm - data->lrclist[i].timer) <= 100 || (data->lrclist[i].timer - tm <= 100))
    {
      if ((tm - data->lrclist[i + 1].timer) <= 100 || (data->lrclist[i + 1].timer - tm <= 100))
      {
        return i + 1;
      }
      else if ((tm - data->lrclist[i + 2].timer) <= 100 || (data->lrclist[i + 2].timer - tm <= 100))
      {
        return i + 2;
      }
      else
      {
        return i;
      }
    }
    i++;
  }
  return MAX_TIMER;
}

int str_to_timer(char *s)
{
  int len = strlen(s);
  int i = 0;
  int ret = 0;
  while (i < len)
  {
    int j = len - i;
    int e = 1;
    while (j > 0)
    {
      e *= 10;
      j--;
    }
    e /= 10;
    ret += e * (s[i] - '0');
    i++;
  }
  return ret;
}

void sort_timer(SLEEPMODE_DATA *data)
{
  int i = 0;
  while (i <= data->total_offset)
  {
    int j = i;
    while (j <= data->total_offset)
    {
      if (data->lrclist[i].timer > data->lrclist[j].timer && data->lrclist[i].timer > 0 && data->lrclist[j].timer > 0)
      {
        TimerList tmp;
        memcpy(&tmp, &data->lrclist[i], sizeof(TimerList));
        memcpy(&data->lrclist[i], &data->lrclist[j], sizeof(TimerList));
        memcpy(&data->lrclist[j], &tmp, sizeof(TimerList));
      }
      j++;
    }
    i++;
  }
}

int songname_to_lrc(wchar_t *lrc, wchar_t *songname, int len)
{
  if (!len)
    return 0;

  int i = 0;
  wchar_t *wstr = wstrrchr(songname, '.');
  int extlen = (wstrlen(wstr) - 1);
  while (i < (len - extlen))
  {
    lrc[i] = songname[i];
    i++;
  }
  wstrcat(lrc, L"lrc");
  return 1;
}

int LoadLrc(wchar_t *fullname)
{
  SLEEPMODE_DATA *data = GetData();

  W_FSTAT _fstat;
  if (w_fstat(fullname, &_fstat) < NULL)
    return READ_FAIL;

  int fsize = _fstat.st_size;
  if (!fsize)
    return READ_FAIL;

  int file = w_fopen(fullname, WA_Read, 0x1FF, NULL);
  if (file < NULL)
    return READ_FAIL;

  char *f_buffer = NULL;
  char *utf8_buffer = NULL;
  // wchar_t *utf16_buffer = NULL;

  f_buffer = (char *)malloc(fsize + 1);
  memset(f_buffer, NULL, fsize + 1);
  w_fread(file, f_buffer, fsize);
  w_fclose(file);

  int buff_size;
  bool is_supported;
  switch (get_encoding_type(f_buffer))
  {
  case UTF8:
    FREE(data->lrcbuf);
    buff_size = strlen(f_buffer) + 1;
    data->lrcbuf = (char *)malloc(buff_size);
    memset(data->lrcbuf, NULL, sizeof(buff_size));
    strcpy(data->lrcbuf, f_buffer);
    is_supported = true;
    break;
  case UTF8_BOM:
    FREE(data->lrcbuf);
    buff_size = strlen(f_buffer) + 1;
    utf8_buffer = (char *)malloc(buff_size);
    memset(utf8_buffer, NULL, sizeof(buff_size));
    memcpy(utf8_buffer, f_buffer + 3, fsize - 2);

    data->lrcbuf = (char *)malloc(buff_size);
    memset(data->lrcbuf, NULL, sizeof(buff_size));
    strcpy(data->lrcbuf, utf8_buffer);

    FREE(utf8_buffer);
    is_supported = true;
    break;
  // case UTF16_LE:
  //   FREE(data->lrcbuf);
  //   utf16_buffer = (wchar_t *)malloc(fsize - 2);
  //   memset(utf16_buffer, NULL, sizeof(wchar_t) * (fsize - 2));
  //   wstrcpy(utf16_buffer, (wchar_t *)(f_buffer + 2));

  //   data->lrcbuf = (char *)malloc(fsize / 2 + 1);
  //   memset(data->lrcbuf, NULL, fsize / 2 + 1);
  //   unicode2win1251(data->lrcbuf, utf16_buffer, fsize / 2 + 1);

  //   debug_printf("\n utf16_buffer: %ls", utf16_buffer);
  //   debug_printf("\n lrcbuf: %s", data->lrcbuf);

  //   FREE(utf16_buffer);
  //   is_supported = true;
  //   break;
  default:
    is_supported = false;
    break;
  }

  FREE(f_buffer);

  if (!is_supported)
    return READ_FAIL;

  if (data->lrclist)
    TimerList_Free(data->lrclist);

  data->lrclist = (TimerList *)malloc(sizeof(TimerList) * (MAX_TIMER));
  memset(data->lrclist, NULL, sizeof(TimerList) * (MAX_TIMER));
  data->total_offset = 0;

  int i = 0;
  while (i < strlen(data->lrcbuf))
  {
    if (data->lrcbuf[i] == '[')
    {
      if (is_digit(data->lrcbuf[i + 1]))
      {
        int j = 1;
        char tmp[MAX_EXT + 1] = "";
        while (data->lrcbuf[i + j] != ']')
        {
          if (j <= MAX_EXT)
          {
            tmp[j - 1] = data->lrcbuf[i + j];
          }
          j++;
        }
        char mm[4] = "";
        char ss[4] = "";
        char ms[4] = "";
        strncpy(mm, tmp, strlen(tmp) - strlen(strstr(tmp, ":")));
        if (strstr(tmp, "."))
        {
          strncpy(ss, strstr(tmp, ":") + 1, strlen(strstr(tmp, ":")) - strlen(strstr(tmp, ".")) - 1);
          strncpy(ms, strstr(tmp, ".") + 1, strlen(strstr(tmp, ".")) - 1);
        }
        else
          strncpy(ss, strstr(tmp, ":") + 1, strlen(strstr(tmp, ":")) - 1);
        data->lrclist[data->total_offset].timer = str_to_timer(ms) + str_to_timer(ss) * 1000 + str_to_timer(mm) * 1000 * 60;

        int m = i;
        int k = i;
        char ttmp[MAX_STR * 2 + 1] = "";
        while (data->lrcbuf[m] != '\r' && data->lrcbuf[m] != '\n')
        {
          if (!data->lrcbuf[m])
            break;
          ttmp[k - i] = data->lrcbuf[m];
          k++;
          m++;
        }
        wchar_t wstr[MAX_STR * 2 + 1] = L"";
        str2wstr(wstr, ttmp);
        data->lrclist[data->total_offset].lrcinfo = (wchar_t *)malloc(MAX_EXT + 1);
        memset(data->lrclist[data->total_offset].lrcinfo, 0, MAX_EXT + 1);
        wstrcpy(data->lrclist[data->total_offset].lrcinfo, wstrrchr(wstr, ']') + 1);
        i += (strlen(tmp) + 1);
        data->total_offset++;
      }
    }
    i++;
  }
  return READ_OK;
}

void GetLyric(wchar_t *path, wchar_t *name)
{
  SLEEPMODE_DATA *data = GetData();

  int len_name = wstrlen(name);
  int len_path = wstrlen(path);

  wchar_t *lrc = (wchar_t *)malloc(sizeof(wchar_t) * (len_name + 2));
  memset(lrc, NULL, sizeof(wchar_t) * (len_name + 2));
  songname_to_lrc(lrc, name, len_name);

  wchar_t *fullname = FSX_MakeFullPath(path, lrc);

  Kill_LyricTimer(data);

  data->offset_len = 0;
  data->lrc_state = LoadLrc(fullname);

  if (data->lrc_state == READ_OK)
  {
    data->current_offset = WAIT;
    sort_timer(data);
  }
  else
    data->current_offset = NOLYRIC;

  refresh_screen(data->sleepmode);
  WStringFree(lrc);
  FSX_FreeFullPath(fullname);
}

void Kill_LyricTimer(SLEEPMODE_DATA *data)
{
  if (data->TimerLyric)
  {
    Timer_Kill(&data->TimerLyric);
    data->TimerLyric = NULL;
  }
}

void lyricOnTimer(u16 timerID, LPARAM lparam)
{
  SLEEPMODE_DATA *data = (SLEEPMODE_DATA *)lparam;
  data->offset_len++;
  refresh_screen(data->sleepmode);

  TEXTID textid = TextID_Create(data->lrclist[data->current_offset].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
  int width = Disp_GetTextIDWidth(textid, TextID_GetLength(textid));
  TextID_Destroy(textid);

  int betweentimer = data->lrclist[data->current_offset + 1].timer - data->lrclist[data->current_offset].timer;
  if (width <= data->disp_width)
    Timer_ReSet(&data->TimerLyric, betweentimer / 20, lyricOnTimer, (LPARAM *)data);
  if (width > data->disp_width && width <= data->disp_width * 2)
    Timer_ReSet(&data->TimerLyric, betweentimer / (20 * 2), lyricOnTimer, (LPARAM *)data);
  if (width > data->disp_width * 2 && width <= data->disp_width * 3)
    Timer_ReSet(&data->TimerLyric, betweentimer / (20 * 3), lyricOnTimer, (LPARAM *)data);
  if (width > data->disp_width * 3 && width <= data->disp_width * 4)
    Timer_ReSet(&data->TimerLyric, betweentimer / (20 * 4), lyricOnTimer, (LPARAM *)data);
}

void Start_LyricTimer(SLEEPMODE_DATA *data)
{
  data->TimerLyric = Timer_Set(0, lyricOnTimer, (LPARAM *)data);
}
