#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#ifndef DB3150v1
#include "dll.h"
#endif

#include "Lib.h"
#include "data.h"
#include "lyric.h"
#include "main.h"

int is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

int get_encoding_type(char *s)
{
  if (s[0] == 0xFF && s[1] == 0xFE) // unicode little-endian
  {
    return UTF16_LE;
  }
  else if (s[0] == 0xFE && s[1] == 0xFF) // unicode big-endian
  {
    return UTF16_BE;
  }
  else if (s[0] == 0xEF && s[1] == 0xBB && s[2] == 0xBF) // utf-8 with BOM
  {
    return UTF8_BOM;
  }
  else // expecting ANSI encoding =)
    return UTF8;
}

void TimerList_Free(TimerList *lrclist)
{
  int list_num;
  for (list_num = 0; list_num < MAX_TIMER; list_num++)
  {
    if (lrclist[list_num].lrcinfo)
    {
      mfree(lrclist[list_num].lrcinfo);
      lrclist[list_num].lrcinfo = NULL;
    }
  }
  mfree(lrclist);
}

void Lyric_FreeData(DISP_OBJ_DBP *disp_obj)
{
  if (disp_obj->lrclist)
    TimerList_Free(disp_obj->lrclist);
  FREE(disp_obj->lrcbuf);
}

int find_current_timer_list(DISP_OBJ_DBP *disp_obj, time_t tm)
{
  int i = 0;
  while (i <= disp_obj->total_offset)
  {
    if ((tm - disp_obj->lrclist[i].timer) <= 100 || (disp_obj->lrclist[i].timer - tm <= 100))
    {
      if ((tm - disp_obj->lrclist[i + 1].timer) <= 100 || (disp_obj->lrclist[i + 1].timer - tm <= 100))
      {
        return i + 1;
      }
      else if ((tm - disp_obj->lrclist[i + 2].timer) <= 100 || (disp_obj->lrclist[i + 2].timer - tm <= 100))
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

void sort_timer(DISP_OBJ_DBP *disp_obj)
{
  int i = 0;
  while (i <= disp_obj->total_offset)
  {
    int j = i;
    while (j <= disp_obj->total_offset)
    {
      if (disp_obj->lrclist[i].timer > disp_obj->lrclist[j].timer && disp_obj->lrclist[i].timer > 0 && disp_obj->lrclist[j].timer > 0)
      {
        TimerList tmp;
        memcpy(&tmp, &disp_obj->lrclist[i], sizeof(TimerList));
        memcpy(&disp_obj->lrclist[i], &disp_obj->lrclist[j], sizeof(TimerList));
        memcpy(&disp_obj->lrclist[j], &tmp, sizeof(TimerList));
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

int LoadLrc(DISP_OBJ_DBP *disp_obj, wchar_t *path, wchar_t *name)
{
  FSTAT _fstat;
  if (fstat(path, name, &_fstat) < 0)
    return READ_FAIL;

  int fsize = _fstat.fsize;

  if (!fsize)
    return READ_FAIL;

  int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file < 0)
    return READ_FAIL;

  char *f_buffer;
  char *utf8_buffer;
  // wchar_t *utf16_buffer;

  f_buffer = (char *)malloc(fsize + 1);
  memset(f_buffer, NULL, fsize + 1);
  fread(file, f_buffer, fsize);
  fclose(file);

  int buff_size;
  BOOL is_supported;
  FREE(disp_obj->lrcbuf);

  int encoding = get_encoding_type(f_buffer);

  switch (encoding)
  {
  case UTF8:
    buff_size = strlen(f_buffer) + 1;
    disp_obj->lrcbuf = (char *)malloc(buff_size);
    memset(disp_obj->lrcbuf, NULL, buff_size);
    strcpy(disp_obj->lrcbuf, f_buffer);
    is_supported = TRUE;
    break;
  case UTF8_BOM:
    buff_size = strlen(f_buffer) + 1;
    utf8_buffer = (char *)malloc(buff_size);
    memset(utf8_buffer, NULL, buff_size);
    memcpy(utf8_buffer, f_buffer + 3, fsize - 2);

    disp_obj->lrcbuf = (char *)malloc(buff_size);
    memset(disp_obj->lrcbuf, NULL, buff_size);
    strcpy(disp_obj->lrcbuf, utf8_buffer);

    FREE(utf8_buffer);
    is_supported = TRUE;
    break;
  // case UTF16_LE:
  //   buff_size = fsize / 2;
  //   utf16_buffer = (wchar_t *)malloc(buff_size);
  //   memset(utf16_buffer, NULL, buff_size);
  //   memcpy(utf16_buffer, f_buffer + 2, fsize - 1);

  //   disp_obj->lrcbuf = (char *)malloc(buff_size);
  //   memset(disp_obj->lrcbuf, NULL, buff_size);
  //   unicode2win1251(disp_obj->lrcbuf, utf16_buffer, wstrlen(utf16_buffer));

  //   debug_printf("\n utf16_buffer: %ls", utf16_buffer);
  //   debug_printf("\n lrcbuf: %s", disp_obj->lrcbuf);

  //   FREE(utf16_buffer);
  //   is_supported = TRUE;
  //   break;
  default:
    is_supported = FALSE;
    break;
  }

  FREE(f_buffer);

  if (!is_supported)
    return READ_FAIL;

  if (disp_obj->lrclist)
    TimerList_Free(disp_obj->lrclist);

  int list_size = sizeof(TimerList) * MAX_TIMER;
  disp_obj->lrclist = (TimerList *)malloc(list_size);
  memset(disp_obj->lrclist, NULL, list_size);
  disp_obj->total_offset = 0;

  int i = 0;
  while (i < strlen(disp_obj->lrcbuf))
  {
    if (disp_obj->lrcbuf[i] == '[')
    {
      if (is_digit(disp_obj->lrcbuf[i + 1]))
      {
        int j = 1;
        char tmp[MAX_EXT + 1] = "";
        while (disp_obj->lrcbuf[i + j] != ']')
        {
          if (j <= MAX_EXT)
          {
            tmp[j - 1] = disp_obj->lrcbuf[i + j];
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
        disp_obj->lrclist[disp_obj->total_offset].timer = str_to_timer(ms) + str_to_timer(ss) * 1000 + str_to_timer(mm) * 1000 * 60;

        int m = i;
        int k = i;
        char ttmp[MAX_STR * 2 + 1] = "";
        while (disp_obj->lrcbuf[m] != '\r' && disp_obj->lrcbuf[m] != '\n')
        {
          if (!disp_obj->lrcbuf[m])
            break;
          ttmp[k - i] = disp_obj->lrcbuf[m];
          k++;
          m++;
        }
        wchar_t wstr[MAX_STR * 2 + 1] = L"";
        str2wstr(wstr, ttmp);
        disp_obj->lrclist[disp_obj->total_offset].lrcinfo = (wchar_t *)malloc(MAX_EXT + 1);
        memset(disp_obj->lrclist[disp_obj->total_offset].lrcinfo, NULL, MAX_EXT + 1);
        wstrcpy(disp_obj->lrclist[disp_obj->total_offset].lrcinfo, wstrrchr(wstr, ']') + 1);
        i += (strlen(tmp) + 1);
        disp_obj->total_offset++;
      }
    }
    i++;
  }
  return READ_OK;
}

void GetLyric(DISP_OBJ_DBP *disp_obj, wchar_t *path, wchar_t *name)
{
  int len_name = wstrlen(name);

  wchar_t *lrc = (wchar_t *)malloc(sizeof(wchar_t) * (len_name + 2));
  memset(lrc, NULL, sizeof(wchar_t) * (len_name + 2));
  songname_to_lrc(lrc, name, len_name);

  disp_obj->offset_len = 0;
  disp_obj->lrc_state = LoadLrc(disp_obj, path, lrc);

  if (disp_obj->lrc_state == READ_OK)
  {
    disp_obj->current_offset = WAIT;
    sort_timer(disp_obj);
  }
  else
    disp_obj->current_offset = NOLYRIC;

  DispObject_InvalidateRect(disp_obj, NULL);
  FREE(lrc);
}

void lyricOnTimer(u16 timerID, LPARAM lparam)
{
  DISP_OBJ_DBP *disp_obj = (DISP_OBJ_DBP *)lparam;
  disp_obj->offset_len++;
  DispObject_InvalidateRect(disp_obj, NULL);

  TEXTID textid = TextID_Create(disp_obj->lrclist[disp_obj->current_offset].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int width = dll_Disp_GetTextIDWidth(textid, TextID_GetLength(textid));
#else
  int width = Disp_GetTextIDWidth(textid, TextID_GetLength(textid));
#endif
  TextID_Destroy(textid);

  int betweentimer = disp_obj->lrclist[disp_obj->current_offset + 1].timer - disp_obj->lrclist[disp_obj->current_offset].timer;
  if (width <= disp_obj->disp_width)
    Timer_ReSet(&disp_obj->TimerLyric, betweentimer / 20, lyricOnTimer, (LPARAM *)disp_obj);
  if (width > disp_obj->disp_width && width <= disp_obj->disp_width * 2)
    Timer_ReSet(&disp_obj->TimerLyric, betweentimer / (20 * 2), lyricOnTimer, (LPARAM *)disp_obj);
  if (width > disp_obj->disp_width * 2 && width <= disp_obj->disp_width * 3)
    Timer_ReSet(&disp_obj->TimerLyric, betweentimer / (20 * 3), lyricOnTimer, (LPARAM *)disp_obj);
  if (width > disp_obj->disp_width * 3 && width <= disp_obj->disp_width * 4)
    Timer_ReSet(&disp_obj->TimerLyric, betweentimer / (20 * 4), lyricOnTimer, (LPARAM *)disp_obj);
}

void Start_LyricTimer(DISP_OBJ_DBP *disp_obj)
{
  disp_obj->TimerLyric = Timer_Set(0, lyricOnTimer, (LPARAM *)disp_obj);
}

void Kill_LyricTimer(DISP_OBJ_DBP *disp_obj)
{
  if (disp_obj->TimerLyric)
  {
    Timer_Kill(&disp_obj->TimerLyric);
    disp_obj->TimerLyric = NULL;
  }
}
