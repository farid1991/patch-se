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

  GC *get_DisplayGC(void);
#if defined(A1) || defined(DB3150v1) || defined(DB3150v2)
  int GetImageHeight(IMAGEID);
  int SetFont(int FontSize);
  void DrawString(TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color);
#else
  void DisplayGC_AddRef(GC *, void *pICanvas);
  void TextObject_SetText(void *pIUIRichText, TEXTID);
  void TextObject_SetFont(void *pIUIRichText, void *pIFont, const int pStartIndex, const int pCharsLeftToCompose);
  int RichTextLayout_GetTextWidth(TEXTID, void *pIUIRichTextLayout, void *pIUIFont);
#endif
  void CoCreateInstance(UUID *cid, UUID *iid, void **pInterface);
  void OSE_GetShell(void **pInterface);

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

  void Timer_ReSet(uint16_t *timer, int time, TIMERPROC onTimer, LPARAM lparam);
  uint16_t Timer_Set(int time, TIMERPROC onTimer, LPARAM lparam);
  void Timer_Kill(uint16_t *timerID);

  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
  void TextID_Destroy(TEXTID);
};

#endif
