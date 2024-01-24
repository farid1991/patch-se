#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
  int hz(int *);
  int REQUEST_SETTING_SILENCE_SET(const int *sync, u16 profile, u16 value);
  BOOL GetSilent(void);
  void SetSilent(int state);
  int BookObj_GetBookID(BOOK *book);
  void UI_Event_toBookID(int event, int BookID);
  BOOK *FindBook(IS_NEEDED_BOOK);
  char *strstr(const char *str1, const char *str2);
  UI_APP_SESSION *BookObj_GetSession(BOOK *book);
  int TextID2wstr(TEXTID, wchar_t *dest, int maxlen);
  int wstrncmp(const wchar_t *, const wchar_t *, int);
  int wstrcmp(const wchar_t *wstr1, const wchar_t *wstr2);
  int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
  char GUIonMessage_SetMenuItemUnavailableText(GUI_MESSAGE *msg, TEXTID);
  void GUIonMessage_SetItemDisabled(GUI_MESSAGE *msg, int unk);
  int ConnectionManager_Connection_GetState(void);
  int Request_ICA_ShutdownAllConnections(const int *sync);
  void GUIonMessage_SetLineSeparator(GUI_MESSAGE *msg, int _unk1);
  void BookObj_SetFocus(BOOK *book, int display);
  void Shortcut_Run(wchar_t *shortcut_name);
  int GetFreeBytesOnHeap(void);
  void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
  int GetVolumeSize(u16 *volume, VOLUMESIZE *);
  BOOK *Find_StandbyBook(void);
  void memset(void *mem, char chr, int size);
  int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);
  int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, unsigned int __0);
  int fclose(int file);
  int fread(int file, void *ptr, int size);
  int fwrite(int file, const void *ptr, int size);
  int CreateBook(void *mem, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int __0xFFFFFFFF, int __0);
  void FreeBook(void *book);
  void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
  void BookObj_Hide(BOOK *book, int display);
  void BookObj_Show(BOOK *book, int display);
  void BookObj_SetDisplayOrientation(BOOK *book, int orientation);
  GUI_LIST *CreateListMenu(BOOK *, int display);
  void ListMenu_SetNoItemText(GUI_LIST *, int str);
  void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
  int ListMenu_GetSelectedItem(GUI_LIST *);
  void ListMenu_SetItemStyle(void *obj, int style);
  void ListMenu_SetItemCount(void *, int item_count);
  void ListMenu_SetCursorToItem(void *obj, int item);
  void ListMenu_SetBackgroundImage(GUI_LIST *, wchar_t ImageID);
  void GUIObject_SetTitleType(void *gui, int type);
  void GUIObject_SetTitleIcon(void *gui, wchar_t);
  void GUIObject_SetTitleText(void *gui, int StrID);
  void GUIObject_SetSecondRowTitleText(void *gui, int StrID);
  void GUIObject_SoftKeys_SetAction(void *gui, u16 actionID, void (*proc)(BOOK *, GUI *));
  void GUIObject_SoftKeys_SetText(void *gui, u16 actionID, int StrID);
  void GUIObject_SoftKeys_SetItemAsSubItem(void *gui, u16 actionID, int subitem);
  GUI *GUIObject_Destroy(GUI *);
  void GUIObject_SetStyle(GUI *, int style);
  void GUIObject_Show(void *gui);
  BOOK *GUIObject_GetBook(GUI *gui);
  BOOK *GUIonMessage_GetBook(void *msg);
  int GUIonMessage_GetCreatedItemIndex(void *msg);
  int TextID_Create(const void *wstr, int flag, int len);
  char GUIonMessage_SetMenuItemText(GUI_MESSAGE *, int StrID);
  char GUIonMessage_SetMenuItemInfoText(GUI_MESSAGE *, int StrID);
  char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *, int StrID);
  void UI_Event(int event);
  void MessageBox(int HeaderStrID, int MessageStrID, wchar_t IconID, int style /*1 or 2*/, int time, BOOK *unk);
  void StatusIndication_SetItemText(GUI *gui, int item, int StrID);
  void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, wchar_t iconID);
  DISP_OBJ *DISP_OBJ_StatusIndication_SetItemText(DISP_OBJ *, int ID, int strid);
  DISP_OBJ *DISP_OBJ_StatusIndication_SetItemText1(DISP_OBJ *, int ID, int iconID, int strid);
  DISP_OBJ *GUIObject_GetDispObject(GUI *);
  GUI_ONEOFMANY *CreateOneOfMany(BOOK *);
  void OneOfMany_SetChecked(GUI_ONEOFMANY *, int checked);
  void OneOfMany_SetTexts(GUI_ONEOFMANY *, const int *StrID, int Count);
  int GetOperatorName(void *);
  int REQUEST_PROFILE_GETACTIVEPROFILE(const int *sync, int *level);
  int REQUEST_PROFILE_GETPROFILENAME(const int *sync, int unk, TEXTID_DATA *, char *error);
  void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);
  void DATE_GetWeekDay(DATE *, char *dest);
  void TextID_Destroy(TEXTID);

  int Display_GetWidth(int display);
  int Display_GetHeight(int display);
  int Time2ID(TIME *, char TimeFormat, int isSec);
  int SetFont(int);
  int GetImageHeight(wchar_t ImageID);
  int Date2ID(DATE *, int TimeFormat, int);
  void TabMenuBar_SetTabTitle(GUI_TABMENUBAR *, int tab_num, TEXTID);
  void DrawString(TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color);
  void DrawString_A2(TEXTID strid, int align, int x1, int y1, int x2, int y2, int colour, DISP_OBJ *disp, char *font);
  void DrawRect(int x1, int y1, int x2, int y2, int pen_color, int brush_color);
  void defpage(DISP_OBJ *, int a, int b, int c);
  int iconidname2id(const wchar_t idname, int maxnamelen, int *id);
  int GetSignalQuality(char *rssi, char *ber);
  TEXTID TextID_CreateIntegerID(int num);
  int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

  int ImageID_Get(const wchar_t *fpath, const wchar_t *fname, IMAGEID *);

  void REQUEST_SYSTEM_RESTART(void);
  void REQUEST_SYSTEM_SHUTDOWN(void);
  void Lock_Keyboard(void);
  int Bluetooth_SetState(int set);
  BOOL Bluetooth_GetState(void);
  BOOL Bluetooth_isBusy(void);
  BOOL FlightMode_GetState(void);
  int FlightMode_SetState(int set);
  int IrDa_GetState( char* state );
  void debug_printf(const char *fmt, ...);

  GUI *CreateYesNoQuestion(BOOK *book, int display);
  void YesNoQuestion_SetQuestionText(GUI *, TEXTID);
  void YesNoQuestion_SetDescriptionText(GUI *, TEXTID);
  void YesNoQuestion_SetIcon(GUI *, IMAGEID);
};

#endif
