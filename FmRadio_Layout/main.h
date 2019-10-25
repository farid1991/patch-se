#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(gui) if(gui) gui=GUIObject_Destroy(gui);
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a);
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

#define CONFIG_PATH L"/usb/other/ZBin/Config/FmRadio"

void DrawImage(int x, int y, IMAGEID img);
#endif
