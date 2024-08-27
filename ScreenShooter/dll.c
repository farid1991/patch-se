#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"

int get_display_data(TDisplayManagerInfo* info, uint8_t *buffer)
{
  IDisplayManager *pDisplayManager = NULL;
  IDisplaySession *pDisplaySession = NULL;
  IShell *pShell = NULL;

  OSE_GetShell(PPINTERFACE(&pShell));

  if (pShell)
  {
    pShell->CreateInstance(CID_CDisplayManager, IID_IDisplayManager, PPINTERFACE(&pDisplayManager));
    pShell->Release();
  }

  if (pDisplayManager)
  {
    pDisplayManager->GetInfo(UIDisplay_Main, info);
    pDisplayManager->CreateDisplaySession(0, 0, 0, 0, 0, &pDisplaySession);
    pDisplayManager->Release();
  }

  if (pDisplaySession)
  {
    pDisplaySession->GetDisplayBuffer(0, 0, info->width, info->height, buffer);
    pDisplaySession->Release();
    return 1;
  }

  return 0;
}
