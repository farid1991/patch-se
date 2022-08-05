#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
#if defined(DB2020)
  void *memalloc(int zero, int size, int f1, int f2, const char *fname, int fline);
  void memfree(int zero, void *mem, const char *fname, int fline);
#elif defined(A2)
  void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
  void memfree(int zero, void *mem, const char *fname, int fline);
#else
  void *memalloc(int size, int f1, int f2, const char *fname, int fline);
  void memfree(void *mem, const char *fname, int fline);
#endif

#if defined(A1) || defined(DB3150v1) || defined(DB3150v2)
  int SetFont(int FontSize);
  void DrawString(TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color);
#endif

#if defined(A1) || defined(DB3150v1)
  int GetImageHeight(IMAGEID);
#endif

  void debug_printf(const char *fmt, ...);
  void *memset(void *mem, char chr, int size);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

  PROCESS current_process(void);
  OSADDRESS get_envp(PROCESS pid, char *name);
  OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);
  PROCESS get_bid(PROCESS pid);

  int IsScreenSaverBook(BOOK *bk);
  int IsAudioPlayerBook(BOOK *bk);
  BOOK *FindBook(IS_NEEDED_BOOK);

  int Display_GetHeight(int display);
  int Display_GetWidth(int display);

  void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);
  void DATE_GetWeekDay(DATE *, char *dest);
  TEXTID Date2ID(DATE *, int DateFormat, int);
  TEXTID Time2ID(TIME *, char TimeFormat, int isSec);

  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  void DispObject_InvalidateRect(DISP_OBJ *, RECT *);

  void Timer_ReSet(u16 *timer, int time, TIMERPROC onTimer, LPARAM lparam);
  u16 Timer_Set(int time, TIMERPROC onTimer, LPARAM lparam);
  void Timer_Kill(u16 *timerID);

  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
  void TextID_Destroy(TEXTID);

  GUI *Create_KnobOption(BOOK *bk, int display);
  void KnobOption_SetTitleText(GUI *g, TEXTID);
  void KnobOption_SetItemCount(GUI *g, int item);
  void KnobOption_SetCursor(GUI *g, int pos);
  void KnobOption_SetItems(GUI *g, TEXTID, int num);
  int KnobOption_GetSelectedItem(GUI *g);
};

#endif
