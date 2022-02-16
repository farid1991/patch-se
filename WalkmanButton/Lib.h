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
  int memcpy(void *dest, const void *source, int cnt);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

  int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
  int fclose(int file);
  int fread(int file, void *ptr, int size);
  int fwrite(int file, const void *ptr, int size);
  int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);
  int w_chdir(const wchar_t *path);
  int w_fopen(const wchar_t *name, int attr, int rights, int err);
  int w_fstat(const wchar_t *name, W_FSTAT *);
  int w_fwrite(int f, void *buf, int size);
  int w_fread(int f, void *buf, int size);
  int w_lseek(int f, int offs, int mode);
  int w_fclose(int f);
  int w_mkdir(const wchar_t *path, int mode);

  char *strcpy(char *dest, const char *source);
  wchar_t *str2wstr(wchar_t *wstr, const char *str);
  int strcmp(const char *str1, const char *str2);
  int strncmp(const char *s1, const char *s2, int len);
  int strlen(const char *str);
  char *strstr(const char *str1, const char *str2);
  char *wstr2strn(char *str, const wchar_t *wstr, int maxlen);
  int wstrncmp(const wchar_t *, const wchar_t *, int);
  int wstrlen(const wchar_t *wstr);
  wchar_t *wstrcpy(wchar_t *dest, const wchar_t *source);
  wchar_t *wstrncpy(wchar_t *dest, const wchar_t *source, int maxlen);
  wchar_t *wstrcat(wchar_t *wstr, const wchar_t *subwstr);
  wchar_t *wstrncat(wchar_t *wstr, const wchar_t *subwstr, int maxlen);

  TEXTID TextID_CreateIntegerID(int num);
  TEXTID TextID_Create(const void *wstr, TEXT_ENCODING flag, int len);
  void TextID_GetString(TEXTID, char *str, int maxlen);
  int TextID_GetWString(TEXTID, wchar_t *dest, int maxlen);
  int TextID_GetLength(TEXTID);
  void TextID_Destroy(TEXTID);
  int iconidname2id(const wchar_t *idname, int maxnamelen, int *id);
  int GetFreeBytesOnHeap(void);

  void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);

  GUI_LIST *CreateListMenu(BOOK *, int display);
  void ListMenu_SetNoItemText(GUI_LIST *, int str);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
  int ListMenu_GetSelectedItem(GUI_LIST *);
  void ListMenu_SetItemStyle(void *obj, int style);
  void ListMenu_SetItemCount(void *, int item_count);
  void ListMenu_SetCursorToItem(void *obj, int item);
  void ListMenu_SetTexts(GUI_LIST *, TEXTID *textids, int Count);
  void ListMenu_DestroyItems(GUI_LIST *);

  GUI_ONEOFMANY *CreateOneOfMany(BOOK *book);
  void OneOfMany_SetItemCount(GUI_ONEOFMANY *, int count);
  void OneOfMany_SetChecked(GUI_ONEOFMANY *, int checked);
  int OneOfMany_GetSelected(GUI_ONEOFMANY *);
  void OneOfMany_SetTexts(GUI_ONEOFMANY *, TEXTID *strids, int Count);
  void OneOfMany_SetOnMessage(GUI_ONEOFMANY *, int (*proc)(GUI_MESSAGE *));

  void GUIObject_SetTitleType(GUI *, int type);
  void GUIObject_SetTitleText(GUI *, TEXTID);
  void GUIObject_SetSecondRowTitleText(GUI *, TEXTID);
  void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
  GUI *GUIObject_Destroy(GUI *);
  void GUIObject_Show(GUI *);

  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  GUI *DispObject_GetGUI(DISP_OBJ *);
  BOOK *GUIObject_GetBook(GUI *);
  DISP_DESC *DispObject_GetDESC(DISP_OBJ *);
  void DISP_DESC_SetOnKey(DISP_DESC *, DISP_OBJ_ONKEY_METHOD);
  DISP_OBJ_ONKEY_METHOD DispObject_GetOnKey(DISP_OBJ *);
  void DispObject_SetAnimation(DISP_OBJ *, int style);

  int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
  BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
  GUI *GUIonMessage_GetGui(GUI_MESSAGE *msg);
  int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
  int GUIonMessage_GetSelectedItem(GUI_MESSAGE *msg);
  char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemInfoText(GUI_MESSAGE *msg, TEXTID);
  void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);

  void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
  void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
  void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);
  void GUIObject_SoftKeys_ExecuteAction(GUI *, u16 actionID);

  int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_ReturnPage(BOOK *book, int);
  void FreeBook(BOOK *book);
  int root_list_get_session_count(void);
  UI_APP_SESSION *root_list_get_session(int num_session);
  UI_APP_SESSION *BookObj_GetSession(BOOK *book);
  void BookObj_SetFocus(BOOK *book, int display);
  int BookObj_GetBookID(BOOK *book);

  int IsScreenSaverBook(BOOK *bk);
  int IsAudioPlayerBook(BOOK *bk);
  int IsRightNowBook(BOOK *book);
  int IsVolumeControllerBook(BOOK *book);
  BOOK *FindBookEx(int (*cmp_proc)(BOOK *book_from_list, int *param), int *param);
  BOOK *FindBook(IS_NEEDED_BOOK);
  BOOK *Find_StandbyBook(void);
  BOOK *MainDisplay_GetTopBook(void);
  void MediaPlayer_Audio_Minimize(BOOK *book, void *);

  int Display_GetHeight(int display);
  int Display_GetWidth(int display);

  BOOL GetSilent(void);
  void PlaySystemSound(int SndNumber);

  void GoMusic(void);
  void Create_QuickAccessBook(int);
  void Create_RightNowBook(int, int);

  void Shortcut_Run(wchar_t *shortcut_name);
  void UI_Event(int event);
  void UI_Event_toBookID(int event, int BookID);

  LIST *List_Create(void);
  void List_Destroy(LIST *lst);
  int List_InsertFirst(LIST *lst, void *item);
  void *List_Get(LIST *lst, int index);
  int List_GetCount(LIST *);
  void List_DestroyElements(LIST *lst, int (*cmp_proc)(void *item), void (*free_proc)(void *item));

  int JavaDialog_Open(int unk1, char *unk2, void **JavaDesc);
  void JavaDialog_Close(int unk1);
  int JavaAppDesc_Get(int unk1, void **JavaDesc);
  int JavaAppDesc_GetFirstApp(void *JavaDesc);
  int JavaAppDesc_GetNextApp(void *JavaDesc);
  int JavaAppDesc_GetJavaAppInfo(void *JavaDesc, int ID, wchar_t **wstr);
  int JavaApp_LogoImageID_Get(wchar_t *fullpath, IMAGEID *);
  TEXTID JavaSession_GetName(void);
  char *manifest_GetParam(const char *buf, const char *param_name, int unk);
};

#endif
