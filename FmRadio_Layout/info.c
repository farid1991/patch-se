/*
;Fm Radio Layout Editor
;- Ability to hide/show all items.
;- Ability to change coordinates of each item in realtime.
;- Ability to choose Text color, font, etc.
;- Ability to use color or Theme Image on the background.
;v. 1.5
;(c) farid
*/
#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "main.h"
#include "data.h"
#include "info.h"

void Get_Channel(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  char CurrentChannel = fmbook->CurrentChannel;
  if (!CurrentChannel)
    Data->Channel = EMPTY_TEXTID;
  Data->Channel = TextID_CreateIntegerID(CurrentChannel);
}

void Get_ChannelName(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  char CurrentChannel = fmbook->CurrentChannel;
  wchar_t *ChannelName = fmbook->Channel[CurrentChannel - 1].Name;
  Data->ChannelName = TextID_Create(ChannelName, ENC_UCS2, TEXTID_ANY_LEN);
}

void Get_CurrentFrequency(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  uint16_t CurrentFrequency = fmbook->CurrentFrequency;
  snwprintf(Data->buf, MAXELEMS(Data->buf), L"%.1f", CurrentFrequency / 10.0);
  Data->Frequency = TextID_Create(Data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

void Get_GetPSName(FmRadio_Data *Data)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)Data->FmRadioBook;
  wchar_t *PSName = fmbook->ProgramServiceName;
  Data->PSName = TextID_Create(PSName, ENC_UCS2, TEXTID_ANY_LEN);
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
