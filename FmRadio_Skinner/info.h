#ifndef _INFO_H_
#define _INFO_H_

TEXTID Get_Channel(FmRadio_Data* Data);
TEXTID Get_ChannelName(FmRadio_Data* Data);
TEXTID Get_CurrentFrequency(FmRadio_Data* Data);
TEXTID Get_GetPSName(FmRadio_Data* Data);

IMAGEID Get_RDS_State(FmRadio_Data* Data);
IMAGEID Get_AF_State(FmRadio_Data* Data);
IMAGEID Get_Audio_State(FmRadio_Data* Data);

#endif
