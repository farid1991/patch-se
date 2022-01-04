#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(g)           \
    if (g)                    \
    {                         \
        GUIObject_Destroy(g); \
        g = NULL;             \
    }

// #define FREE_IMAGE(a) \
//     if (a != NOIMAGE) \
//         ImageID_Free(a);

#define TEXT_FREE(text)       \
    if (text != EMPTY_TEXTID) \
        TextID_Destroy(text);

#define FILE_NAME L"FMRadio.cfg"
#define CONFIG_PATH L"/usb/other/ZBin/Config/FmRadio"

void DrawImage(int x, int y, IMAGEID img);
void *malloc(int size);
void mfree(void *mem);

#endif
