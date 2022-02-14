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

  int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
  int fclose(int file);
  int fread(int file, void *ptr, int size);
  int fwrite(int file, const void *ptr, int size);
  int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);

  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);

  GUI_LIST *CreateListMenu(BOOK *, int display);
  void ListMenu_SetNoItemText(GUI_LIST *, int str);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
  int ListMenu_GetSelectedItem(GUI_LIST *);
  void ListMenu_SetItemStyle(void *obj, int style);
  void ListMenu_SetItemCount(void *, int item_count);
  void ListMenu_SetCursorToItem(void *obj, int item);
  void ListMenu_SetTexts(GUI_LIST *, TEXTID *textids, int Count);

  GUI_ONEOFMANY *CreateOneOfMany(BOOK *book);
  void OneOfMany_SetItemCount(GUI_ONEOFMANY *, int count);
  void OneOfMany_SetChecked(GUI_ONEOFMANY *, int checked);
  int OneOfMany_GetSelected(GUI_ONEOFMANY *);
  void OneOfMany_SetTexts(GUI_ONEOFMANY *, TEXTID *strids, int Count);
  void OneOfMany_SetOnMessage(GUI_ONEOFMANY *, int (*proc)(GUI_MESSAGE *));

  void GUIObject_SetTitleText(GUI *, TEXTID);
  void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
  GUI *GUIObject_Destroy(GUI *);
  void GUIObject_Show(GUI *);

  void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
  void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);

  int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void FreeBook(BOOK *book);

  int IsScreenSaverBook(BOOK *bk);
  int IsAudioPlayerBook(BOOK *bk);
  BOOK *FindBook(IS_NEEDED_BOOK);
  BOOK *MainDisplay_GetTopBook(void);
  void MediaPlayer_Audio_Minimize(BOOK *book, void *);

  void Create_QuickAccessBook(int);
  void Create_RightNowBook(int, int);

  void Shortcut_Run(wchar_t *shortcut_name);
  void UI_Event(int event);
};

#endif
