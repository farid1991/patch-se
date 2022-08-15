#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
#pragma swi_number = 0x10D
  __swi __arm int elfload(const wchar_t *filename, void *param1, void *param2, void *param3);
  
  void *memalloc(int size, int f1, int f2, const char *fname, int fline);
  void memfree(void *mem, const char *fname, int fline);

  void debug_printf(const char *fmt, ...);
  void *memset(void *mem, char chr, int size);
  int memcpy(void *dest, const void *source, int cnt);
  int sprintf(char *buf, const char *fmt, ...);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);
  int swscanf(const wchar_t *buffer, const wchar_t *format, ...);

  int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
  int fclose(int file);
  int fread(int file, void *ptr, int size);
  int fwrite(int file, const void *ptr, int size);
  int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);

  int IsExternalDisplay();
  int isKeylocked(void);
  BOOK *FindBook(IS_NEEDED_BOOK);
  BOOK *FindBookByID(int BookID);
  BOOK *Find_StandbyBook(void);
  int IsScreenSaverBook(BOOK *bk);
  int IsAudioPlayerBook(BOOK *bk);
  int IsRightNowBook(BOOK *book);
  int IsVolumeControllerBook(BOOK *book);

  int Display_GetHeight(int display);
  int Display_GetWidth(int display);
  void PlaySystemSound(int SndNumber);
  void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);

  char *strcpy(char *dest, const char *source);
  wchar_t *str2wstr(wchar_t *wstr, const char *str);
  int strcmp(const char *str1, const char *str2);
  int strncmp(const char *s1, const char *s2, int len);
  int strlen(const char *str);
  char *strncpy(char *dest, const char *source, int maxlen);
  char *strcat(char *dest, const char *src);
  char *strstr(const char *str1, const char *str2);
  char *wstr2strn(char *str, const wchar_t *wstr, int maxlen);
  int wstrcmp(const wchar_t *wstr1, const wchar_t *wstr2);
  int wstrncmp(const wchar_t *, const wchar_t *, int);
  int wstrlen(const wchar_t *wstr);
  wchar_t *wstrcpy(wchar_t *dest, const wchar_t *source);
  wchar_t *wstrncpy(wchar_t *dest, const wchar_t *source, int maxlen);
  wchar_t *wstrcat(wchar_t *wstr, const wchar_t *subwstr);
  wchar_t *wstrncat(wchar_t *wstr, const wchar_t *subwstr, int maxlen);
  wchar_t *wstrwstr(const wchar_t *wstr1, const wchar_t *wstr2);

  TEXTID TextID_CreateIntegerID(int num);
  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
  void TextID_GetString(TEXTID, char *str, int maxlen);
  int TextID_GetWString(TEXTID, wchar_t *dest, int maxlen);
  int TextID_GetLength(TEXTID);
  void TextID_Destroy(TEXTID);
  TEXTID TextID_Copy(TEXTID);
  int iconidname2id(const wchar_t *idname, int maxnamelen, int *id);
  void ImageID_Free(IMAGEID);

  int REQUEST_SYSTEM_SHUTDOWN(void);
  int REQUEST_SYSTEM_RESTART(void);
  int Bluetooth_SetState(int set);
  BOOL Bluetooth_GetState(void);
  BOOL Bluetooth_isBusy(void);
  BOOL FlightMode_GetState(void);
  int FlightMode_SetState(int set);
  int REQUEST_PROFILE_GETACTIVEPROFILE(const int *sync, int *level);
  int REQUEST_SETTING_SILENCE_SET(const int *sync, u16 profile, u16 value);
  BOOL GetSilent(void);

  int CreateBook(void *mem, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
  void FreeBook(void *book);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_ReturnPage(BOOK *book, int);
  void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_Hide(BOOK *book, int display);
  void BookObj_Show(BOOK *book, int display);
  void BookObj_SetFocus(BOOK *book, int display);
  int root_list_get_session_count(void);
  UI_APP_SESSION *root_list_get_session(int num_session);
  UI_APP_SESSION *BookObj_GetSession(BOOK *book);
  void BookObj_SetFocus(BOOK *book, int display);
  int BookObj_GetBookID(BOOK *book);
  BOOK *MenuBook_Desktop(int mode, int BookID);
  wchar_t *MenuBook_Desktop_GetSelectedItemID(BOOK *MenuBook_Desktop);
  void BookObj_SoftKeys_SetAction(BOOK *book, int actionID, SKACTIONPROC proc);
  void BookObj_SoftKeys_SetText(BOOK *book, int actionID, TEXTID);
  TEXTID Shortcut_Get_MenuItemName(void *);
  IMAGEID Shortcut_Get_MenuItemIconID(void *);
  void Shortcut_Run(wchar_t *shortcut_name);
  void UI_Event(int event);
  void UI_Event_toBookID(int event, int BookID);
  void UI_Event_toBookIDwData(int event, int BookID, void *message, void (*free_proc)(void *));

  void GUIObject_SoftKeys_SetAction(GUI *gui, u16 actionID, SKACTIONPROC);
  void GUIObject_SoftKeys_SetText(GUI *gui, u16 actionID, TEXTID);
  void GUIObject_SoftKeys_SetItemAsSubItem(GUI *gui, u16 actionID, int subitem);
  void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);
  void DispObject_SoftKeys_ExecuteAction(DISP_OBJ *, u16 actionID);

  GUI *GUIObject_Destroy(GUI *);
  void GUIObject_SetStyle(GUI *, int style);
  void GUIObject_SetTitleType(GUI *, int type);
  void GUIObject_SetTitleText(GUI *, TEXTID);
  void GUIObject_SetSecondRowTitleText(GUI *, TEXTID);
  void GUIObject_Show(GUI *);

  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  GUI *DispObject_GetGUI(DISP_OBJ *);
  BOOK *GUIObject_GetBook(GUI *);
  DISP_DESC *DispObject_GetDESC(DISP_OBJ *);
  void DISP_DESC_SetOnKey(DISP_DESC *, DISP_OBJ_ONKEY_METHOD);
  DISP_OBJ_ONKEY_METHOD DispObject_GetOnKey(DISP_OBJ *);
  void DispObject_SetAnimation(DISP_OBJ *, int style);

  GUI_TABMENUBAR *CreateTabMenuBar(BOOK *book);
  void TabMenuBar_SetTabCount(GUI_TABMENUBAR *, int count);
  void TabMenuBar_SetTabGui(GUI_TABMENUBAR *, int tab, GUI *);
  void TabMenuBar_SetTabTitle(GUI_TABMENUBAR *, int tab_num, TEXTID);
  void TabMenuBar_SetTabIcon(GUI_TABMENUBAR *, int tab, IMAGEID, int for_state);
  int TabMenuBar_GetFocusedTab(GUI_TABMENUBAR *);
  void TabMenuBar_SetFocusedTab(GUI_TABMENUBAR *, int tab_num);

  GUI_LIST *CreateListMenu(BOOK *, int display);
  void ListMenu_SetNoItemText(GUI_LIST *, int str);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
  int ListMenu_GetSelectedItem(GUI_LIST *);
  void ListMenu_SetItemStyle(GUI_LIST *, int style);
  void ListMenu_SetItemCount(GUI_LIST *, int item_count);
  void ListMenu_SetCursorToItem(GUI_LIST *, int item);
  void ListMenu_SetBackgroundImage(GUI_LIST *, IMAGEID);
  void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
  void ListMenu_DestroyItems(GUI_LIST *);

  int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
  BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
  GUI *GUIonMessage_GetGui(GUI_MESSAGE *msg);
  int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
  int GUIonMessage_GetSelectedItem(GUI_MESSAGE *msg);
  void GUIonMessage_SetItemDisabled(GUI_MESSAGE *msg, BOOL);
  char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemInfoText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemUnavailableText(GUI_MESSAGE *msg, TEXTID);
  void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);
  void GUIonMessage_SetNumberOfSubItems(GUI_MESSAGE *msg, int unk, int num_sub_items);
  void GUIonMessage_SubItem_SetText(GUI_MESSAGE *msg, TEXTID);
  int GUIonMessage_SubItem_GetCreatedParentIndex(GUI_MESSAGE *msg);
  int GUIonMessage_SubItem_GetSelectedIndex(GUI_MESSAGE *msg);
  void GUIonMessage_SubItem_SetDisabled(GUI_MESSAGE *msg, BOOL state);
  int GUIonMessage_SubItem_GetCreatedIndex(GUI_MESSAGE *msg);
  int GUIonMessage_SubItem_GetSelectedParentIndex(GUI_MESSAGE *msg);

  GUI_ONEOFMANY *CreateOneOfMany(BOOK *book);
  void OneOfMany_SetItemCount(GUI_ONEOFMANY *, int count);
  void OneOfMany_SetChecked(GUI_ONEOFMANY *, int checked);
  int OneOfMany_GetSelected(GUI_ONEOFMANY *);
  void OneOfMany_SetTexts(GUI_ONEOFMANY *, TEXTID *strids, int Count);
  void OneOfMany_SetOnMessage(GUI_ONEOFMANY *, int (*proc)(GUI_MESSAGE *));

  GUI *CreateStringInputVA(int, ...);

  int GetFreeBytesOnHeap(void);
  int MessageBox(TEXTID header_text, TEXTID message_text, IMAGEID, int style, int time, BOOK *book);
  void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time_in_ms, BOOK *book);

  LIST *List_Create(void);
  void List_Destroy(LIST *lst);
  int List_InsertFirst(LIST *lst, void *item);
  int List_InsertLast(LIST *lst, void *item);
  void *List_Get(LIST *lst, int index);
  int List_GetCount(LIST *);
  void List_DestroyElements(LIST *lst, int (*cmp_proc)(void *item), void (*free_proc)(void *item));

  int JavaDialog_Open(int unk1, char *unk2, void **JavaDesc);
  void JavaDialog_Close(int unk1);
  int JavaAppDesc_Get(int unk1, void **JavaDesc);
  int JavaAppDesc_GetFirstApp(void *JavaDesc);
  int JavaAppDesc_GetNextApp(void *JavaDesc);
  int JavaAppDesc_GetJavaAppID(void *JavaDesc);
  int JavaAppDesc_GetJavaAppInfo(void *JavaDesc, int ID, wchar_t **wstr);
  int JavaApp_LogoImageID_Get(wchar_t *fullpath, IMAGEID *);
  TEXTID JavaSession_GetName(void);
  char *manifest_GetParam(const char *buf, const char *param_name, int unk);
  void REQUEST_UI_OAF_START_APPLICATION(const int *sync, int appID, char *flag);
};

#endif
