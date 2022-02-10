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
  void GC_DrawImage(int x, int y, IMAGEID);
  int GetImageHeight(IMAGEID);
  int GetImageWidth(IMAGEID);
  int Disp_GetTextIDHeight(TEXTID);
  int Disp_GetTextIDWidth(TEXTID, int len);
#endif

  void debug_printf(const char *fmt, ...);
  void *memset(void *mem, char chr, int size);
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
  void *w_diropen(const wchar_t *dir);
  wchar_t *w_dirread(void *);
  int w_dirclose(void *);
  int w_rename(const wchar_t *dst, const wchar_t *src);
  int w_remove(const wchar_t *dir);

  int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
  void BookObj_Hide(BOOK *book, int display);
  void BookObj_Show(BOOK *book, int display);
  void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_ReturnPage(BOOK *book, int);
  int BookObj_GetBookID(BOOK *book);
  void FreeBook(BOOK *book);
  void UI_Event(int event);

  void GUIObject_SetAnimation(GUI *, int mode);
  void GUIObject_SetBacklightTimeout(GUI *, int time);
  void GUIObject_SetTitleType(GUI *, int type);
  void GUIObject_SetTitleText(GUI *, TEXTID);
  void GUIObject_SetTitleTextAlign(GUI *, int align);
  void GUIObject_SetTitleTextColor(GUI *, int color);
  void GUIObject_SetSecondRowTitleText(GUI *, TEXTID);
  void GUIObject_SetTitleBackgroundImage(GUI *, IMAGEID);
  void GUIObject_Show(GUI *);
  void ListMenu_SetCursorToItem(GUI_LIST *, int item);
  void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
  int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
  char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
  void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);
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

  TEXTID TextID_CreateFromChar(int num);
  TEXTID TextID_CreateIntegerID(int num);
  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
  void TextID_GetString(TEXTID, char *str, int maxlen);
  int TextID_GetLength(TEXTID);
  void TextID_Destroy(TEXTID);
  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  int REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(const int *sync, u16 *ImageHandler, char *unk);

  void ListMenu_SetHotKeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
  void GUIObject_SetListTextColor(GUI *, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro);
  void GUIObject_SetCursorImage(GUI *, IMAGEID);
  void GUIObject_SetBackgroundImage(GUI *, IMAGEID);

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
  void DrawObject(int x, int y, IMAGEID img, int w, int h, int color);

  void BookObj_AddGUIObject(BOOK *book, GUI *);
  void DrawRect(int x1, int y1, int x2, int y2, int pen_color, int brush_color);
  void DispObject_InvalidateRect(DISP_OBJ *, RECT *);
  int GUIObject_Create(GUI *, void (*GuiDestroy)(GUI *), void (*DispDescCreate)(DISP_DESC *), BOOK *, void (*DispObjCallBack)(DISP_OBJ *, void *msg, GUI *), int display, int size_of_gui);
  void DispObject_SetLayerColor(DISP_OBJ *, int color);
  GUI *DispObject_GetGUI(DISP_OBJ *);
  void DispObject_SetAnimation(DISP_OBJ *, int mode);
  void DispObject_SetStyle(DISP_OBJ *, int style);
  int DispObject_GetStyle(DISP_OBJ *);
  void DispObject_SetThemeImage(DISP_OBJ *, int theme_image);
  void DispObject_SetRefreshTimer(DISP_OBJ *, int time);
  void DispObject_KillRefreshTimer(DISP_OBJ *);
  void DispObject_WindowSetSize(DISP_OBJ *, int w, int h);
  void DispObject_SetBackgroundColor(DISP_OBJ *, unsigned int color);
  void DispObject_SetListTextColor(DISP_OBJ *, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro);
  int DispObject_ListMenu_GetItemCount(DISP_OBJ *);
  void DispObject_SetTitleType(DISP_OBJ *, int type);
  void DispObject_SetTitleText(DISP_OBJ *, TEXTID);
  void DispObject_SetTitleTextAlign(DISP_OBJ *, int align);
  void DispObject_SetSecondRowTitleText(DISP_OBJ *, TEXTID);
  void DispObject_SetBackgroundImage(DISP_OBJ *, IMAGEID);

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
  BOOK *Display_GetTopBook(int display);
  int GetThemeColor(int, int);

  int GC_GetPenColor(GC *gc);
  void GC_SetPenColor(GC *gc, int pen_color);
  void GC_DrawLine(GC *gc, int x1, int y1, int x2, int y2);

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

  int sscanf(const char *buffer, const char *format, ...);
  void wstrnupr(wchar_t *wstr, int maxlen);
  wchar_t *wstrcpy(wchar_t *dest, const wchar_t *source);
  wchar_t *wstrncpy(wchar_t *dest, const wchar_t *source, int maxlen);
  int wstrcmp(const wchar_t *wstr1, const wchar_t *wstr2);
  int wstrlen(const wchar_t *wstr);
  wchar_t *wstrcat(wchar_t *wstr, const wchar_t *subwstr);
  wchar_t *wstrrchr(const wchar_t *wstr, wchar_t wchar);
  int wstrcmpi(const wchar_t *ws1, const wchar_t *ws2);

  wchar_t *FILEITEM_GetFname(FILEITEM *);
  wchar_t *FILEITEM_GetPath(FILEITEM *);
  BOOL FSX_IsFileExists(wchar_t *fpath, wchar_t *fname);
  wchar_t *FSX_MakeFullPath(wchar_t *fpath, wchar_t *fname);
  void FSX_FreeFullPath(wchar_t *fullpath);
  wchar_t *getFileExtention(wchar_t *fname);

  int ImageID_Get(const wchar_t *fpath, const wchar_t *fname, IMAGEID *);
  int ImageID_GetIndirect(void *buf_image, int size, int __NULL, wchar_t *image_type, IMAGEID *);
  void ImageID_Free(IMAGEID);
  wchar_t *MetaData_GetTags(wchar_t *path, wchar_t *name, int tagID);
#ifdef DB3150v1
  IMAGEID MetaData_GetCover(wchar_t *fullpath);
#endif

  int Format_Time(int begin_time, int end_time, int __zero1, int __zero2, void *, int __one);
  int TextIteratorSetTextId(const void *wstr, TEXT_ENCODING flag, int len);

  void *List_Get(LIST *lst, int index);
  int List_GetCount(LIST *);
  LIST *DispObject_SoftKeys_GetList(DISP_OBJ *, BOOK *book, char __zero);

  void Volume_Set(int TAudioControl_VolumeType, char volume);
  int Volume_Get(int TAudioControl_VolumeType, char *volume); // GetAudioSettings

  void DynamicMenu_SetElement_SecondLineText(DYNAMIC_MENU_ELEMENT *dme, TEXTID);
};

#endif
