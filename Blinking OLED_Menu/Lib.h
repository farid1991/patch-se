#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
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
    void *memset(void *mem, char chr, int size);
    int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, unsigned int __0);
    int fclose(int file);
    int fread(int file, void *ptr, int size);
    int fwrite(int file, const void *ptr, int size);

    PROCESS current_process(void);
    PROCESS get_bid(PROCESS pid);
    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);

    void Timer_ReSet(u16 *timer, int time, TIMERPROC onTimer, LPARAM lparam);
    void Timer_Kill(u16 *timerID);
    TEXTID TextID_CreateIntegerID(int num);
    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);

    int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, APP_DESC *);
    void BookObj_KillBook(BOOK *book);
    void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
    void BookObj_ReturnPage(BOOK *book, int);
    void FreeBook(BOOK *book);

    BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
    int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
    int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
    char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
    char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);
    GUI *GUIObject_Destroy(GUI *);
    GUI *CreateStringInputVA(int, ...);

    GUI_LIST *CreateListMenu(BOOK *, int display);
    void ListMenu_SetItemCount(GUI_LIST *, int item_count);
    void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
    void ListMenu_SetCursorToItem(GUI_LIST *, int item);
    void ListMenu_SetItemSecondLineText(GUI_LIST *, int elem_num, int);
    void ListMenu_SetBackgroundImage(GUI_LIST *, IMAGEID);
    void ListMenu_SetItemStyle(GUI_LIST *, int style);
    int ListMenu_GetSelectedItem(GUI_LIST *);

    void GUIObject_SetTitleIcon(GUI *, IMAGEID);
    void GUIObject_SetTitleType(GUI *, int type);
    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
    void GUIObject_Show(GUI *);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);

    GUI *CreateStringInput(BOOK *book);
    void StringInput_SetMode(GUI *, int mode);
    void StringInput_SetText(GUI *strinp, TEXTID);
    void StringInput_SetFixedText(GUI *strinp, TEXTID);
    void StringInput_SetMinLen(GUI *strinp, int len);
    void StringInput_SetMaxLen(GUI *strinp, int len);
    void StringInput_SetEnableEmptyText(GUI *strinp, BOOL state);
    void StringInput_SetActionOK(GUI *strinp, void (*proc)(BOOK *book, wchar_t *string, int len));
    void StringInput_SetActionBack(GUI *strinp, void (*proc)(BOOK *book, wchar_t *string, int len));
    int StringInput_GetStringAndLen(GUI *, wchar_t **, u16 *);

    int Illumination_LedID_Off(int LED_ID);
    int Illumination_LedID_SetLevel(int LED_ID, int level);
    int Illumination_LedID_SetLevel_Gradually(int LED_ID, int level, int fade_time);

    void DynamicMenu_SetElement_SecondLineText(DYNAMIC_MENU_ELEMENT *, TEXTID);
    int DynamicMenu_GetElementMsg(DYNAMIC_MENU_ELEMENT *);

    BOOL Battery_GetChargingState();
    int wtoi(const wchar_t *wstr, int len, int *dest);
    int MessageBox(TEXTID header_text, TEXTID message_text, wchar_t IconID, int style, int time, BOOK *book);
    void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time_in_ms, BOOK *book);
};

#endif
