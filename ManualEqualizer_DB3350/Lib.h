#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
  void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
  void memfree(int zero, void *mem, const char *fname, int fline);
  void debug_printf(const char *fmt, ...);
  void *memset(void *mem, char chr, int size);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);
  int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
  int fclose(int file);
  int fread(int file, void *ptr, int size);
  int fwrite(int file, const void *ptr, int size);
  int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);

  void CoCreateInstance(UUID *cid, UUID *iid, void **pInterface);

  GC *get_DisplayGC(void);
  void DisplayGC_AddRef(GC *, void *pICanvas);
  void TextObject_SetText(void *pIUIRichText, TEXTID);
  void TextObject_SetFont(void *pIUIRichText, void *pIFont, const int pStartIndex, const int pCharsLeftToCompose);

  void DispObject_InvalidateRect(DISP_OBJ *, RECT *);

  void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);

  GUI *GUIObject_Destroy(GUI *);
  void GUIObject_Show(GUI *);

  void MusicApplication_SetAnimation(GUI *, int mode);

  void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
  void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
  void GUIObject_SoftKeys_SetItemAsSubItem(GUI *, u16 actionID, int subitem);

  FILEITEM *FILEITEM_CreateCopy(FILEITEM *);
  void FILEITEM_Destroy(FILEITEM *);
  wchar_t *FILEITEM_GetFname(FILEITEM *);
  wchar_t *FILEITEM_GetPath(FILEITEM *);
  wchar_t *FSX_MakeFullPath(wchar_t *fpath, wchar_t *fname);
  void FSX_FreeFullPath(wchar_t *fullpath);

  void debug_printf(const char *fmt, ...);
  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
  void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time, BOOK *book);
};

#endif
