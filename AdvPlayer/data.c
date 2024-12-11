#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "data.h"

ADVPLAYER_DATA *env_data_get()
{
  ADVPLAYER_DATA *data = (ADVPLAYER_DATA *)get_envp(NULL, EMP_NAME);
  if (!data)
  {
    data = (ADVPLAYER_DATA *)malloc(sizeof(ADVPLAYER_DATA));
    memset(data, NULL, sizeof(ADVPLAYER_DATA));
    data->disp_w = Display_GetWidth(UIDisplay_Main);
    data->disp_h = Display_GetHeight(UIDisplay_Main);
    set_envp(NULL, EMP_NAME, (OSADDRESS)data);
  }
  return data;
}

void env_data_destroy(ADVPLAYER_DATA *data)
{
  if (data)
  {
    mfree(data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}
