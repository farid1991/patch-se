#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#define BUFFER_SIZE(w,h) (w*h*4)

int get_display_data(TDisplayManagerInfo* info, uint8_t *buffer);

#endif
