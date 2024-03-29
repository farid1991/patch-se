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
  void GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID img);
  int GetImageHeight(IMAGEID);
#endif
  GC *get_DisplayGC(void);

  void debug_printf(const char *fmt, ...);
  void *memset(void *mem, char chr, int size);
  int memcpy(void *dest, const void *source, int cnt);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

  int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
  int fclose(int file);
  int fread(int file, void *ptr, int size);
  int fwrite(int file, const void *ptr, int size);
  int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);
  int lseek(int file, int offset, int mode);
  void FileDelete(wchar_t *path, wchar_t *filename, int *error);
  int w_chdir(const wchar_t *path);
  int w_fopen(const wchar_t *name, int attr, int rights, int err);
  int w_fstat(const wchar_t *name, W_FSTAT *);
  int w_fwrite(int f, void *buf, int size);
  int w_fread(int f, void *buf, int size);
  int w_lseek(int f, int offs, int mode);
  int w_fclose(int f);
  int w_mkdir(const wchar_t *path, int mode);

  PROCESS current_process(void);
  PROCESS get_bid(PROCESS pid);
  OSADDRESS get_envp(PROCESS pid, char *name);
  OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);
  
  char *strcpy(char *dest, const char *source);
  int strcmp(const char *str1, const char *str2);
  int strlen(const char *str);
  char *strstr(const char *str1, const char *str2);
  char *strncpy(char *dest, const char *source, int maxlen);
  wchar_t *str2wstr(wchar_t *wstr, const char *str);
  char *wstr2strn(char *str, const wchar_t *wstr, int maxlen);

  wchar_t *wstrcpy(wchar_t *dest, const wchar_t *source);
  wchar_t *wstrncpy(wchar_t *dest, const wchar_t *source, int maxlen);
  wchar_t *wstrcat(wchar_t *wstr, const wchar_t *subwstr);
  wchar_t *wstrncat(wchar_t *wstr, const wchar_t *subwstr, int maxlen);
  int wstrcmp(const wchar_t *wstr1, const wchar_t *wstr2);
  int wstrlen(const wchar_t *wstr);
  wchar_t *wstrrchr(const wchar_t *wstr, wchar_t wchar);

  int IsScreenSaverBook(BOOK *bk);
  int IsAudioPlayerBook(BOOK *bk);
  int IsFmRadioBook(BOOK *bk);
  BOOK *FindBook(IS_NEEDED_BOOK);

  int ImageID_Get(const wchar_t *fpath, const wchar_t *fname, IMAGEID *);
  void ImageID_Free(IMAGEID);

  int Display_GetHeight(int display);
  int Display_GetWidth(int display);

  void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);
  void DATE_GetWeekDay(DATE *, char *dest);
  TEXTID Date2ID(DATE *, int DateFormat, int);
  TEXTID Time2ID(TIME *, char TimeFormat, int isSec);

  void GUIObject_SetBacklightTimeout(GUI *, int time);
  void DispObject_SetBacklightTimeout(DISP_OBJ *, int time);
  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  void DispObject_InvalidateRect(DISP_OBJ *, RECT *);

  void Timer_ReSet(u16 *timer, int time, TIMERPROC onTimer, LPARAM lparam);
  u16 Timer_Set(int time, TIMERPROC onTimer, LPARAM lparam);
  void Timer_Kill(u16 *timerID);

  TEXTID TextID_CreateIntegerID(int num);
  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int maxlen);
  void TextID_GetString(TEXTID, char *str, int maxlen);
  int TextID_GetWString(TEXTID, wchar_t *dest, int maxlen);
  int TextID_GetLength(TEXTID);
  void TextID_Destroy(TEXTID);
  TEXTID TextID_Copy(TEXTID);
  int Disp_GetTextIDWidth(TEXTID, int len);

  void *MetaData_Desc_Create(wchar_t *path, wchar_t *name);
  void MetaData_Desc_Destroy(void *MetaData_Desc);
  wchar_t *MetaData_Desc_GetTags(void *MetaData_Desc, int tagID);

  BOOL FSX_IsFileExists(wchar_t *pDir, wchar_t *pFile);
  wchar_t *FSX_MakeFullPath(wchar_t *pDir, wchar_t *pFile);
  void FSX_FreeFullPath(wchar_t *fullpath);
};

#endif
