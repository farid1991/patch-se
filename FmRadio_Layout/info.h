#ifndef _INFO_H_
#define _INFO_H_

void Get_Channel(FmRadio_Data* Data, FmRadio_Book *fmbook);
void Get_ChannelName(FmRadio_Data* Data, FmRadio_Book *fmbook);
void Get_CurrentFrequency(FmRadio_Data* Data, FmRadio_Book *fmbook);
void Get_GetPSName(FmRadio_Data* Data, FmRadio_Book *fmbook);

IMAGEID Get_RDS_State(FmRadio_Data* Data, FmRadio_Book *fmbook);
IMAGEID Get_AF_State(FmRadio_Data* Data, FmRadio_Book *fmbook);
IMAGEID Get_Audio_State(FmRadio_Data* Data, FmRadio_Book *fmbook);

#endif
