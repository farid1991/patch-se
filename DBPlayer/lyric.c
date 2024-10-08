#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "data.h"
#include "lyric.h"
#include "main.h"
#include "String.h"

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
  {
    TimerList_Free(disp_obj->lrclist);
  }
  mfree(disp_obj->lrcbuf);
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

int str_to_timer(char *str)
{
  int len = strlen(str);
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
    ret += e * (str[i] - '0');
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

int songname_to_lrc(const wchar_t *songname, wchar_t *lrc, int len)
{
  if (!songname || !len)
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

int LoadLrc(DISP_OBJ_DBP *disp_obj, const wchar_t *path, const wchar_t *name)
{
  mfree(disp_obj->lrcbuf);

  FSTAT _fstat;
  if (fstat(path, name, &_fstat) < 0)
    return READ_FAIL;

  int fsize = _fstat.fsize;

  if (!fsize)
    return READ_FAIL;

  int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file < 0)
    return READ_FAIL;

  char *utf8_buffer;
  wchar_t *utf16_buffer;

  utf8_buffer = StringAlloc(fsize);
  fread(file, utf8_buffer, fsize);
  fclose(file);

  int encoding = Encoding_GetType(utf8_buffer);
  switch (encoding)
  {
  case ANSI:
    disp_obj->lrcbuf = StringAlloc(strlen(utf8_buffer));
    strcpy(disp_obj->lrcbuf, utf8_buffer);
    break;
  case UTF16_LE:
    utf16_buffer = WStringAlloc(fsize / 2);
    memcpy(utf16_buffer, utf8_buffer + 2, fsize - 1);
    disp_obj->lrcbuf = StringAlloc(fsize);
    UTF16LE_to_ANSI(utf16_buffer, disp_obj->lrcbuf, fsize + 1);
    mfree(utf16_buffer);
    break;
  case UTF16_BE:
    utf16_buffer = WStringAlloc(fsize / 2);
    memcpy(utf16_buffer, utf8_buffer + 2, fsize - 1);
    disp_obj->lrcbuf = StringAlloc(fsize);
    UTF16BE_to_ANSI(utf16_buffer, disp_obj->lrcbuf, fsize + 1);
    mfree(utf16_buffer);
    break;
  case UTF8:
    disp_obj->lrcbuf = StringAlloc(strlen(utf8_buffer));
    UTF8_to_ANSI(disp_obj->lrcbuf, utf8_buffer, strlen(utf8_buffer));
    break;
  default:
    encoding = ERROR;
    break;
  }

  mfree(utf8_buffer);

  if (encoding == ERROR)
    return READ_FAIL;

  if (disp_obj->lrclist)
  {
    TimerList_Free(disp_obj->lrclist);
  }

  disp_obj->lrclist = (TimerList *)malloc(sizeof(TimerList) * MAX_TIMER);
  memset(disp_obj->lrclist, NULL, sizeof(TimerList) * MAX_TIMER);
  disp_obj->total_offset = 0;

  int i = 0;
  while (i < strlen(disp_obj->lrcbuf))
  {
    if (disp_obj->lrcbuf[i] == '[')
    {
      if (is_digit(disp_obj->lrcbuf[i + 1]))
      {
        int j = 1;
        char *tmp = StringAlloc(MAX_EXT);
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
        char *ttmp = StringAlloc(MAX_STR * 2);
        while (disp_obj->lrcbuf[m] != '\r' && disp_obj->lrcbuf[m] != '\n')
        {
          if (!disp_obj->lrcbuf[m])
            break;
          ttmp[k - i] = disp_obj->lrcbuf[m];
          k++;
          m++;
        }
        wchar_t *wstr = WStringAlloc(MAX_STR * 2);
        str2wstr(wstr, ttmp);
        disp_obj->lrclist[disp_obj->total_offset].lrcinfo = WStringAlloc(MAX_EXT);
        wstrcpy(disp_obj->lrclist[disp_obj->total_offset].lrcinfo, wstrrchr(wstr, ']') + 1);
        i += (strlen(tmp) + 1);
        disp_obj->total_offset++;
        mfree(wstr);
        mfree(ttmp);
        mfree(tmp);
      }
    }
    i++;
  }
  return READ_OK;
}

void GetLyric(DISP_OBJ_DBP *disp_obj, const wchar_t *path, const wchar_t *name)
{
  wchar_t *lrc = WStringAlloc(wstrlen(name));
  songname_to_lrc(name, lrc, wstrlen(name));

  disp_obj->offset_len = 0;
  disp_obj->lrc_state = LoadLrc(disp_obj, path, lrc);

  if (disp_obj->lrc_state == READ_OK)
  {
    disp_obj->current_offset = WAIT;
    sort_timer(disp_obj);
  }
  else
  {
    disp_obj->current_offset = NOLYRIC;
  }

  DispObject_InvalidateRect(disp_obj, NULL);
  mfree(lrc);
}

void lyricOnTimer(u16 timerID, LPARAM lparam)
{
  DISP_OBJ_DBP *disp_obj = (DISP_OBJ_DBP *)lparam;
  disp_obj->offset_len++;
  DispObject_InvalidateRect(disp_obj, NULL);

  TEXTID textid = TextID_Create(disp_obj->lrclist[disp_obj->current_offset].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
  int width = GetTextIDWidth(FONT_E_16B, textid, TextID_GetLength(textid));
  TextID_Destroy(textid);

  int betweentimer = disp_obj->lrclist[disp_obj->current_offset + 1].timer - disp_obj->lrclist[disp_obj->current_offset].timer;
  if (width <= disp_obj->disp_width)
  {
    Timer_ReSet(&disp_obj->lrc_timer_id, betweentimer / 20, lyricOnTimer, (LPARAM *)disp_obj);
  }
  if (width > disp_obj->disp_width && width <= disp_obj->disp_width * 2)
  {
    Timer_ReSet(&disp_obj->lrc_timer_id, betweentimer / (20 * 2), lyricOnTimer, (LPARAM *)disp_obj);
  }
  if (width > disp_obj->disp_width * 2 && width <= disp_obj->disp_width * 3)
  {
    Timer_ReSet(&disp_obj->lrc_timer_id, betweentimer / (20 * 3), lyricOnTimer, (LPARAM *)disp_obj);
  }
  if (width > disp_obj->disp_width * 3 && width <= disp_obj->disp_width * 4)
  {
    Timer_ReSet(&disp_obj->lrc_timer_id, betweentimer / (20 * 4), lyricOnTimer, (LPARAM *)disp_obj);
  }
}

void Start_LyricTimer(DISP_OBJ_DBP *disp_obj)
{
  disp_obj->lrc_timer_id = Timer_Set(0, lyricOnTimer, (LPARAM *)disp_obj);
}

void Kill_LyricTimer(DISP_OBJ_DBP *disp_obj)
{
  if (disp_obj->lrc_timer_id)
  {
    Timer_Kill(&disp_obj->lrc_timer_id);
    disp_obj->lrc_timer_id = NULL;
  }
}
