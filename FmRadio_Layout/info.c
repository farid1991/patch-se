#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\FmRadio_Book.h"

#include "data.h"
#include "info.h"
#include "main.h"

void Get_Channel(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  char CurrentChannel = fmbook->CurrentChannel;
  if (!CurrentChannel)
    Data->Channel = EMPTY_TEXTID;
  else
    Data->Channel = TextID_CreateIntegerID(CurrentChannel);
}

void Get_ChannelName(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  wchar_t *ChannelName = fmbook->Channel[fmbook->CurrentChannel - 1].Name;
  Data->ChannelName = TextID_Create(ChannelName, ENC_UCS2, TEXTID_ANY_LEN);
}

void Get_CurrentFrequency(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  int frequency = fmbook->CurrentFrequency;

  int whole_part = frequency / 10;   // Integer division to get the whole part
  int decimal_part = frequency % 10; // Remainder for the decimal part
  snwprintf(Data->buf, MAXELEMS(Data->buf), L"%d.%d", whole_part, decimal_part);

  Data->Frequency = TextID_Create(Data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

void Get_GetPSName(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  Data->PSName = TextID_Create(fmbook->ProgramServiceName, ENC_UCS2, TEXTID_ANY_LEN);
}

IMAGEID Get_RDS_State(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  if (fmbook->RDS)
    return Data->Image[RDS_ACTIVE_ICN].ID;
  else
    return Data->Image[RDS_INACTIVE_ICN].ID;
}

IMAGEID Get_AF_State(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  if (fmbook->AF)
    return Data->Image[AF_ON_ICN].ID;
  else
    return Data->Image[AF_OFF_ICN].ID;
}

IMAGEID Get_Audio_State(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  if (fmbook->Settings.StereoReception)
    return Data->Image[MONO_ICN].ID;
  else
    return Data->Image[STEREO_ICN].ID;
}
