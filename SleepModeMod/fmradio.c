#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\book\FmRadio_Book.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "main.h"
#include "fmradio.h"

TEXTID Get_ChannelName(BOOK *book)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  char CurrentChannel = fmbook->CurrentChannel;
  wchar_t *ChannelName = fmbook->Channel[CurrentChannel - 1].Name;
  return TextID_Create(ChannelName, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_CurrentFrequency(BOOK *book)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  u16 CurrentFrequency = fmbook->CurrentFrequency;

  wchar_t buffer[64];
  snwprintf(buffer, MAXELEMS(buffer), L"%.1f MHz", CurrentFrequency / 10.0);
  return TextID_Create(buffer, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID Get_GetPSName(BOOK *book)
{
  FmRadio_Book *fmbook = (FmRadio_Book *)book;
  return TextID_Create(fmbook->ProgramServiceName, ENC_UCS2, TEXTID_ANY_LEN);
}

void Draw_FMRadio(BOOK* fmbook, SLEEPMODE_DATA *data)
{
  data->text_id = Get_CurrentFrequency(fmbook);
  SetFont(FONT_FREQ);
  DrawString(data->text_id, AlignCenter, 1, FREQ_Y, data->disp_width, FREQ_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);

  data->text_id = Get_ChannelName(fmbook);
  SetFont(FONT_CHANNEL);
  DrawString(data->text_id, AlignCenter, 1, CHANNEL_Y, data->disp_width, CHANNEL_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);

  data->text_id = Get_GetPSName(fmbook);
  SetFont(FONT_PSNAME);
  DrawString(data->text_id, AlignCenter, 1, PSNAME_Y, data->disp_width, PSNAME_Y + GetImageHeight(30), 20, 5, clWhite2, clEmpty);
  TextID_Destroy(data->text_id);
}
