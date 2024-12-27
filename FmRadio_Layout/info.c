#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\FmRadio_Book.h"

#include "data.h"
#include "info.h"
#include "main.h"

void Get_Channel(FmRadio_Data *data, FmRadio_Book *fmbook)
{
  data->Channel = EMPTY_TEXTID;

  uint8_t CurrentChannel = fmbook->CurrentChannel;
  if (CurrentChannel)
    data->Channel = TextID_CreateIntegerID(CurrentChannel);
}

void Get_ChannelName(FmRadio_Data *data, FmRadio_Book *fmbook)
{
  wchar_t *ChannelName = fmbook->Channel[fmbook->CurrentChannel - 1].Name;
  data->ChannelName = TextID_Create(ChannelName, ENC_UCS2, TEXTID_ANY_LEN);
}

void Get_CurrentFrequency(FmRadio_Data *data, FmRadio_Book *fmbook)
{
  int frequency = fmbook->CurrentFrequency;

  int whole_part = frequency / 10;   // Integer division to get the whole part
  int decimal_part = frequency % 10; // Remainder for the decimal part
  snwprintf(data->buf, MAXELEMS(data->buf), L"%d.%d", whole_part, decimal_part);

  data->Frequency = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

void Get_GetPSName(FmRadio_Data *data, FmRadio_Book *fmbook)
{
  data->PSName = TextID_Create(fmbook->ProgramServiceName, ENC_UCS2, TEXTID_ANY_LEN);
}

IMAGEID Get_RDS_State(FmRadio_Data *data, FmRadio_Book *fmbook)
{
  if (fmbook->RDS)
    return data->Image[RDS_ACTIVE_ICN].ID;
  return data->Image[RDS_INACTIVE_ICN].ID;
}

IMAGEID Get_AF_State(FmRadio_Data *data, FmRadio_Book *fmbook)
{

  if (fmbook->AF)
    return data->Image[AF_ON_ICN].ID;
  return data->Image[AF_OFF_ICN].ID;
}

IMAGEID Get_Audio_State(FmRadio_Data *data, FmRadio_Book *fmbook)
{
  if (fmbook->Settings.StereoReception)
    return data->Image[MONO_ICN].ID;
  return data->Image[STEREO_ICN].ID;
}
