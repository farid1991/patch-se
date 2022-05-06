#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
#ifndef DB3350
#pragma swi_number = 0x10D
  __swi __arm int elfload(const wchar_t *filename, void *param1, void *param2, void *param3);
#endif
#if defined(DB2010)
  void *memalloc(int size, int f1, int f2, const char *fname, int fline);
  void memfree(void *mem, const char *fname, int fline);
#elif defined(DB2020)
  void *memalloc(int zero, int size, int f1, int f2, const char *fname, int fline);
  void memfree(int zero, void *mem, const char *fname, int fline);
#elif defined(A2)
  void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
  void memfree(int zero, void *mem, const char *fname, int fline);
#endif

#if defined(A1) || defined(DB3150v1) || defined(DB3150v2)
  int SetFont(int FontSize);
  void DrawString(TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color);
#endif

#if defined(A1) || defined(DB3150v1)
  void GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID img);
  void GC_DrawImage(int x, int y, IMAGEID);
  int GetImageHeight(IMAGEID);
  int GetImageWidth(IMAGEID);
  int Disp_GetTextIDHeight(TEXTID);
  int Disp_GetTextIDWidth(TEXTID, int len);
#endif
  int GetImageHeight_int(IMAGEID ImageID);

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
  int w_fopen(const wchar_t *name, int attr, int rights, int err);
  int w_fstat(const wchar_t *name, W_FSTAT *);
  int w_fwrite(int f, void *buf, int size);
  int w_fread(int f, void *buf, int size);
  int w_lseek(int f, int offs, int mode);
  int w_fclose(int f);

  int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
  void BookObj_Hide(BOOK *book, int display);
  void BookObj_Show(BOOK *book, int display);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_ReturnPage(BOOK *book, int);
  void FreeBook(BOOK *book);
  void UI_Event(int event);

  void GUIObject_SetBacklightTimeout(GUI *, int time);
  void GUIObject_SetTitleText(GUI *, TEXTID);
  void GUIObject_Show(GUI *);
  void ListMenu_SetCursorToItem(GUI_LIST *, int item);
  void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
  int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
  char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);
  BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
  int ListMenu_GetSelectedItem(GUI_LIST *);
  void ListMenu_SetItemStyle(GUI_LIST *, int style);
  GUI_ONEOFMANY *CreateOneOfMany(BOOK *book);
  void OneOfMany_SetItemCount(GUI_ONEOFMANY *, int count);
  void OneOfMany_SetChecked(GUI_ONEOFMANY *, int checked);
  void OneOfMany_SetTexts(GUI_ONEOFMANY *, TEXTID *strids, int Count);
  int OneOfMany_GetSelected(GUI_ONEOFMANY *);
  void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
  void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
  void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);
  void GUIObject_SoftKeys_Hide(GUI *);
  void GUIObject_SoftKeys_Show(GUI *);
  void GUIObject_SoftKeys_RemoveBackground(GUI *);
  void GUIObject_SoftKeys_RestoreBackground(GUI *);
  void GUIObject_SoftKeys_AllowKeylock(GUI *, BOOL allow);

  TEXTID TextID_CreateIntegerID(int num);
  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int maxlen);
  void TextID_GetString(TEXTID, char *str, int maxlen);
  int TextID_GetWString(TEXTID, wchar_t *dest, int maxlen);
  int TextID_GetLength(TEXTID);
  void TextID_Destroy(TEXTID);
  TEXTID TextID_Copy(TEXTID);
  int Disp_GetTextIDWidth(TEXTID, int len);
  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  int REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(const int *sync, u16 *ImageHandler, char *unk);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));

  PROCESS current_process(void);
  OSADDRESS get_envp(PROCESS pid, char *name);
  OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);
  PROCESS get_bid(PROCESS pid);

  GUI_LIST *CreateListMenu(BOOK *, int display);
  void ListMenu_SetItemCount(GUI_LIST *, int item_count);
  GUI *GUIObject_Destroy(GUI *);

  GC *get_DisplayGC(void);
  void GC_GetRect(GC *gc, RECT *);
  int GC_GetXX(GC *gc);
  void GC_SetXX(GC *gc, int);

  void BookObj_AddGUIObject(BOOK *book, GUI *);
  void DrawRect(int x1, int y1, int x2, int y2, int pen_color, int brush_color);
  void DispObject_InvalidateRect(DISP_OBJ *, RECT *);
  int GUIObject_Create(GUI *, void (*GuiDestroy)(GUI *), void (*DispDescCreate)(DISP_DESC *), BOOK *, void (*DispObjCallBack)(DISP_OBJ *, void *msg, GUI *), int display, int size_of_gui);
  void DispObject_SetLayerColor(DISP_OBJ *, int color);
  GUI *DispObject_GetGUI(DISP_OBJ *);

  void GUIObject_SetAnimationApp(GUI *, const wchar_t *anim);
  void DispObject_SetAnimationApp(DISP_OBJ *, const wchar_t *anim);
  void DispObject_SetAnimation(DISP_OBJ *, int style);

  void DispObject_SetBacklightMode(DISP_OBJ *, int mode);
  void DispObject_SetThemeImage(DISP_OBJ *, int theme_image);
  void DispObject_SetRefreshTimer(DISP_OBJ *, int time_in_ms);
  void DispObject_KillRefreshTimer(DISP_OBJ *);
  void Timer_ReSet(u16 *timer, int time, TIMERPROC onTimer, LPARAM lparam);
  u16 Timer_Set(int time, TIMERPROC onTimer, LPARAM lparam);
  void Timer_Kill(u16 *timerID);

  void DISP_DESC_SetName(DISP_DESC *, const char *name);
  void DISP_DESC_SetSize(DISP_DESC *, u16 size);
  void DISP_DESC_SetOnCreate(DISP_DESC *, DISP_OBJ_ONCREATE_METHOD);
  void DISP_DESC_SetOnClose(DISP_DESC *, DISP_OBJ_ONCLOSE_METHOD);
  void DISP_DESC_SetOnRedraw(DISP_DESC *, DISP_OBJ_ONREDRAW_METHOD);
  void DISP_DESC_SetOnKey(DISP_DESC *, DISP_OBJ_ONKEY_METHOD);
  void DISP_DESC_SetOnRefresh(DISP_DESC *, DISP_OBJ_METHOD);
  void DISP_DESC_SetOnLayout(DISP_DESC *, DISP_OBJ_ONLAYOUT_METHOD);

  int Display_GetHeight(int display);
  int Display_GetWidth(int display);

  int GC_GetPenColor(GC *gc);
  void GC_SetPenColor(GC *gc, int pen_color);
  void GC_DrawLine(GC *gc, int x1, int y1, int x2, int y2);

  void GUIObject_SetTitleType(GUI *, int type);
  void GUIonMessage_SetItemDisabled(GUI_MESSAGE *msg, BOOL);
  int REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(const int *sync, u16 ImageHandler, wchar_t *path, wchar_t *fname, int unk, IMAGEID *, char *error);
  int REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(const int *sync, u16 ImageHandler, u16 *, u16 *, IMAGEID, int unk_1, char *error);

  void ListMenu_SetItemSecondLineText(GUI_LIST *, u16 Item, TEXTID);
  int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
  BOOK *GUIObject_GetBook(GUI *);
  void ListMenu_DestroyItems(GUI_LIST *);

  void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time_in_ms, BOOK *book);

  void GUIObject_SoftKeys_SetActionAndText(GUI *gui, u16 actionID, SKACTIONPROC proc, TEXTID);

  GUI *CreateYesNoQuestion(BOOK *book, int display);
  void YesNoQuestion_SetQuestionText(GUI *, TEXTID);
  void YesNoQuestion_SetDescriptionText(GUI *, TEXTID);
  void YesNoQuestion_SetIcon(GUI *, IMAGEID);

  void CoCreateInstance(UUID *cid, UUID *iid, void **pInterface);
#ifdef A2
  void DisplayGC_AddRef(GC *, void *pICanvas);
  void TextObject_SetText(void *pIUIRichText, TEXTID textid);
  void TextObject_SetFont(void *pIUIRichText, void *pIFont, const int pStartIndex, const int pCharsLeftToCompose);
  int RichTextLayout_GetTextWidth(TEXTID strid, void *pRichTextLayout, void *pFont);
#endif

  char *strcpy(char *dest, const char *source);
  int strcmp(const char *str1, const char *str2);
  int strlen(const char *str);
  char *strstr(const char *str1, const char *str2);
  char *strncpy(char *dest, const char *source, int maxlen);
  wchar_t *str2wstr(wchar_t *wstr, const char *str);
  char *wstr2strn(char *str, const wchar_t *wstr, int maxlen);
  int sscanf(const char *buffer, const char *format, ...);
  int wstrlen(const wchar_t *wstr);
  wchar_t *wstrcpy(wchar_t *dest, const wchar_t *source);
  wchar_t *wstrncpy(wchar_t *dest, const wchar_t *source, int maxlen);
  wchar_t *wstrcat(wchar_t *wstr, const wchar_t *subwstr);
  wchar_t *wstrncat(wchar_t *wstr, const wchar_t *subwstr, int maxlen);
  int wstrcmp(const wchar_t *wstr1, const wchar_t *wstr2);
  wchar_t *wstrrchr(const wchar_t *wstr, wchar_t wchar);
  void wstrnupr(wchar_t *wstr, int maxlen);

  wchar_t *FILEITEM_GetFname(FILEITEM *);
  wchar_t *FILEITEM_GetPath(FILEITEM *);
  BOOL FSX_IsFileExists(wchar_t *fpath, wchar_t *fname);
  wchar_t *FSX_MakeFullPath(wchar_t *fpath, wchar_t *fname);
  void FSX_FreeFullPath(wchar_t *fullpath);
  wchar_t *getFileExtention(wchar_t *fname);

  int ImageID_GetIndirect(void *buf_image, int size, int __NULL, wchar_t *image_type, IMAGEID *);
  void ImageID_Free(IMAGEID);
  wchar_t *MetaData_GetTags(wchar_t *path, wchar_t *name, int tagID);
#ifdef DB3150v1
  IMAGEID MetaData_GetCover(wchar_t *fullpath);
#endif

  void Volume_Set(int TAudioControl_VolumeType, char volume);
  int Volume_Get(int TAudioControl_VolumeType, char *volume); // GetAudioSettings
};

#endif
