#include "temp\target.h"

#include "..\\include\ASCII.h"
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

BOOL songname_to_lrc(wchar_t *lrc, wchar_t *songname, int len)
{
  if (!len)
    return FALSE;

  int i = 0;
  wchar_t *wstr = wstrrchr(songname, DOT);
  int extlen = (wstrlen(wstr) - 1);
  while (i < (len - extlen))
  {
    lrc[i] = songname[i];
    i++;
  }
  wstrcat(lrc, L"lrc");
  return TRUE;
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

  char *utf8_buffer = NULL;
  wchar_t *utf16_buffer = NULL;

  utf8_buffer = StringAlloc(fsize);
  w_fread(file, utf8_buffer, fsize);
  w_fclose(file);

  bool is_supported;
  int encoding = get_encoding_type(utf8_buffer);
  StringFree(data->lrcbuf);

  switch (encoding)
  {
  case UTF8:
    data->lrcbuf = StringAlloc(strlen(utf8_buffer));
    strcpy(data->lrcbuf, utf8_buffer);
    is_supported = true;
    break;
  case UTF8_BOM:
    data->lrcbuf = StringAlloc(strlen(utf8_buffer));
    utf16_buffer = WStringAlloc(strlen(utf8_buffer) * 2);
    UTF82unicode(utf16_buffer, utf8_buffer, strlen(utf8_buffer));
    wstr2strn(data->lrcbuf, utf16_buffer, strlen(utf8_buffer));
    WStringFree(utf16_buffer);
    is_supported = true;
    break;
  case UTF16_LE:
    utf16_buffer = WStringAlloc(fsize / 2);
    memcpy(utf16_buffer, utf8_buffer + 2, fsize - 1);
    data->lrcbuf = StringAlloc(fsize);
    wstr2strn(data->lrcbuf, utf16_buffer, fsize + 1);
    WStringFree(utf16_buffer);
    is_supported = true;
    break;
  default:
    is_supported = false;
    break;
  }

  StringFree(utf8_buffer);

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
        char *tmp = StringAlloc(MAX_EXT);
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
        char *ttmp = StringAlloc(MAX_STR * 2);
        while (data->lrcbuf[m] != CR && data->lrcbuf[m] != LF)
        {
          if (!data->lrcbuf[m])
            break;
          ttmp[k - i] = data->lrcbuf[m];
          k++;
          m++;
        }
        wchar_t *wstr = WStringAlloc(MAX_STR * 2);
        str2wstr(wstr, ttmp);
        data->lrclist[data->total_offset].lrcinfo = WStringAlloc(MAX_EXT);

        wstrcpy(data->lrclist[data->total_offset].lrcinfo, wstrrchr(wstr, BRACKET_CLOSE) + 1);
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

  wchar_t *lrc = WStringAlloc(wstrlen(name));
  songname_to_lrc(lrc, name, wstrlen(name));

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
