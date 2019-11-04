#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "visual.h"

void RegisterImage(IMG* img, wchar_t* path, wchar_t* fname);
void UnRegisterImage(DISP_OBJ_CLEARBASS* disp_obj);

void LoadBackgroundImage(DISP_OBJ_CLEARBASS* disp_obj);
void LoadBarImage(DISP_OBJ_CLEARBASS* disp_obj);
void LoadBoostImage(DISP_OBJ_CLEARBASS* disp_obj);
void LoadPresetImage(DISP_OBJ_CLEARBASS* disp_obj);

#endif
