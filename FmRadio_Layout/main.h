#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(gui)           \
    if (gui)                    \
    {                           \
        GUIObject_Destroy(gui); \
        gui = NULL;             \
    }

#define FREE_IMAGE(a) \
    if (a != NOIMAGE) \
        ImageID_Free(a);

#define TEXT_FREE(text)       \
    if (text != EMPTY_TEXTID) \
        TextID_Destroy(text);

#define FILE_NAME L"FMRadio.cfg"
#define CONFIG_PATH L"/usb/other/ZBin/Config/FmRadio"

extern "C"
{
    int FmRadio_Gui_OnCreate(DISP_OBJ *disp_obj);
    void FmRadio_Gui_OnClose(DISP_OBJ *disp_obj);
    void FmRadio_Gui_OnRedraw(DISP_OBJ *disp_obj, int r1, int r2, int r3);
    void FmRadio_Gui_OnKey(DISP_OBJ *disp_obj, int key, int unk, int repeat, int mode);
    void FmRadio_Gui_OnLayout(DISP_OBJ *disp_obj, void *layoutstruct);

    int pg_FmRadio_Main__PAGE_ENTER_EVENT(void *, BOOK *book);
    int pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT(void *, BOOK *book);

    void FmRadio_SetActiveSoftKeys(BOOK *, BOOL);
};

#endif
