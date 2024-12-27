#include "temp\target.h"

#include "..\\include\Color.h"
#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "main.h"
#include "slider.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(NULL, size, 1, 5, MEM_NAME, NULL));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, MEM_NAME, NULL));
#else
  return (memalloc(size, 1, 5, MEM_NAME, NULL));
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, MEM_NAME, NULL);
#elif defined(A2)
    memfree(NULL, mem, MEM_NAME, NULL);
#else
    memfree(mem, MEM_NAME, NULL);
#endif
}

int cmp_proc_name(BOOK *book, int *param)
{
  return strcmp(book->xbook->name, (char *)param) == 0;
}

const PAGE_MSG base_page[] =
    {
        RETURN_TO_STANDBY_EVENT, onStandyEvent,
        NIL_EVENT, NULL};
const PAGE_DESC to_base_page = {"VolumeSettings_BasePage", NULL, base_page};

BOOK *Create_VSettingBook()
{
  VSBook *VSettingBook = (VSBook *)malloc(sizeof(VSBook));
  memset(VSettingBook, NULL, sizeof(VSBook));
  if (!CreateBook(VSettingBook, onCloseBook, &to_base_page, BOOK_NAME, NO_BOOK_ID, NULL))
  {
    mfree(VSettingBook);
    return NULL;
  }
  return VSettingBook;
}

void CreateSlider_gui(VSBook *VSettingBook)
{
  if (VSettingBook->Gui = Create_Slider(VSettingBook))
  {
    GUIObject_SoftKeys_SetAction(VSettingBook->Gui, ACTION_BACK, onBackPressed);
    GUIObject_SoftKeys_SetAction(VSettingBook->Gui, ACTION_LONG_BACK, onLongBackPressed);
    GUIObject_Show(VSettingBook->Gui);
  }
}

void Call_VSettingBook()
{
  BOOK *book = FindBookEx(cmp_proc_name, (int *)BOOK_NAME);
  if (book)
  {
    BookObj_SetFocus(book, UIDisplay_Main);
    return;
  }

  VSBook *VSettingBook = (VSBook *)Create_VSettingBook();
  if (VSettingBook)
    CreateSlider_gui(VSettingBook);
}

TEXTID GetSecondRow()
{
  char media, ring, call;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &ring);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);

  char buf[40];
  sprintf(buf, "M:%d%% R:%d%% C:%d%%", vol_table_media[media - 18], vol_table_ring[ring], vol_table_ring[call - 9]);
  return TextID_Create(buf, ENC_LAT1, TEXTID_ANY_LEN);
}

void NewMenuItem(DYNAMIC_MENU_ELEMENT *DME)
{
  switch (DynamicMenu_GetElementMsg(DME))
  {
  case DYNAMIC_MENU_onCall:
    Call_VSettingBook();
    break;
  case DYNAMIC_MENU_onText:
    DynamicMenu_SetElement_FirstLineText(DME, RING_VOLUME_TXT);
    DynamicMenu_SetElement_SecondLineText(DME, GetSecondRow());
    break;
  }
}

__thumb void LaunchNewMenuItem(DYNAMIC_MENU_ELEMENT *DME)
{
  if (FindBookEx(cmp_proc_name, (int *)ProfileBook))
  {
    StandartRingMenu(DME);
  }
  else
  {
    NewMenuItem(DME);
  }
}

#pragma diag_suppress = Pe177
__root const int PATCH_VolumeFunc @ "PATCH_VolumeFunc" = (int)LaunchNewMenuItem;
