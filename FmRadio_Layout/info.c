/*
;Fm Radio Layout Editor
;- Ability to hide/show all items.
;- Ability to change coordinates of each item in realtime.
;- Ability to choose Text color, font, etc.
;- Ability to use color or Theme Image on the background.
;v. 1.2
;(c) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "data.h"
#include "info.h"

TEXTID Get_Channel(FmRadio_Data* Data)
{
  char CurrentChannel = Data->FmRadioBook->CurrentChannel;
  if(!CurrentChannel) return EMPTY_TEXTID;
  else return TextID_CreateIntegerID(CurrentChannel);
}

TEXTID Get_ChannelName(FmRadio_Data* Data)
{
  char CurrentChannel = Data->FmRadioBook->CurrentChannel;
  wchar_t* ChannelName = Data->FmRadioBook->Channel[CurrentChannel-1].Name;
  
  return TextID_Create(ChannelName,ENC_UCS2,TEXTID_ANY_LEN);
}

TEXTID Get_CurrentFrequency(FmRadio_Data* Data)
{
  Uint16_t CurrentFrequency  = Data->FmRadioBook->CurrentFrequency;
  
  wchar_t buffer[10];
  snwprintf(buffer, MAXELEMS(buffer), L"%d", CurrentFrequency );
  
  int len = wstrlen(buffer);
  
  wchar_t* freq = (wchar_t*)malloc(sizeof(wchar_t)*len+1); 
  for(int i=0; i<len; i++)
  {
    freq[i]=buffer[i];
    if(i==(len-1))
    {
      freq[i]= 0x2e;
      freq[i+1] = buffer[i];
      freq[len+1] = L'\0';
    }
  }
  
  return TextID_Create(freq,ENC_UCS2,TEXTID_ANY_LEN);
}

TEXTID Get_GetPSName(FmRadio_Data* Data)
{
  wchar_t* PSName = Data->FmRadioBook->ProgramServiceName;
  return TextID_Create(PSName,ENC_UCS2,TEXTID_ANY_LEN);
}

IMAGEID Get_RDS_State(FmRadio_Data* Data)
{
  if(Data->FmRadioBook->RDS) return Data->Image[1].ID;
  else return Data->Image[2].ID;
}

IMAGEID Get_AF_State(FmRadio_Data* Data)
{
  if(Data->FmRadioBook->AF) return Data->Image[3].ID;
  else return Data->Image[4].ID;
}

IMAGEID Get_Audio_State(FmRadio_Data* Data)
{
  if(Data->FmRadioBook->Settings.StereoReception) return Data->Image[5].ID;
  else return Data->Image[6].ID;
}
