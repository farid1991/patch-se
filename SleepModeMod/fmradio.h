#ifndef FMRadio_H
#define FMRadio_H

#include "main.h"

TEXTID Get_ChannelName(BOOK *book);
TEXTID Get_CurrentFrequency(BOOK *book);
TEXTID Get_GetPSName(BOOK *book);
void Draw_FMRadio(BOOK* fmbook, SLEEPMODE_DATA *data);

#endif
