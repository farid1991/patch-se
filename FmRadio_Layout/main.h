#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(gui) if (gui) { gui=GUIObject_Destroy(gui); gui = NULL; }
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a);
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

void DrawImage(int x, int y, IMAGEID img);

#endif
