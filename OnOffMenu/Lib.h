#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
  void *memalloc(int size, int f1, int f2, const char *fname, int fline);
  void memfree(void *mem, const char *fname, int fline);

  void debug_printf(const char *fmt, ...);
  void *memset(void *mem, char chr, int size);
  int strcmp(const char *str1, const char *str2);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

  int isKeylocked(void);
  BOOK *FindBook(IS_NEEDED_BOOK);

  TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
  void TextID_Destroy(TEXTID);

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
  void Shortcut_Run(wchar_t *shortcut_name);

  int CreateBook(void *mem, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
  void FreeBook(void *book);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_Hide(BOOK *book, int display);
  void BookObj_Show(BOOK *book, int display);
  void BookObj_SetFocus(BOOK *book, int display);
  void UI_Event(int event);

  void GUIObject_SoftKeys_SetAction(GUI *gui, u16 actionID, SKACTIONPROC);
  void GUIObject_SoftKeys_SetText(GUI *gui, u16 actionID, TEXTID);
  void GUIObject_SoftKeys_SetItemAsSubItem(GUI *gui, u16 actionID, int subitem);
  GUI *GUIObject_Destroy(GUI *);
  void GUIObject_SetStyle(GUI *, int style);
  void GUIObject_SetTitleType(GUI *, int type);
  void GUIObject_SetTitleText(GUI *, TEXTID);
  void GUIObject_SetSecondRowTitleText(GUI *, TEXTID);
  void GUIObject_Show(GUI *);

  GUI_LIST *CreateListMenu(BOOK *, int display);
  void ListMenu_SetNoItemText(GUI_LIST *, int str);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
  int ListMenu_GetSelectedItem(GUI_LIST *);
  void ListMenu_SetItemStyle(GUI_LIST *, int style);
  void ListMenu_SetItemCount(GUI_LIST *, int item_count);
  void ListMenu_SetCursorToItem(GUI_LIST *, int item);
  void ListMenu_SetBackgroundImage(GUI_LIST *, IMAGEID);
  void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);

  int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
  int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
  BOOK *GUIonMessage_GetBook(void *msg);
  void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);
  char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
  char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);

  int GetFreeBytesOnHeap(void);
  int MessageBox(TEXTID header_text, TEXTID message_text, IMAGEID, int style, int time, BOOK *book);
};

#endif
