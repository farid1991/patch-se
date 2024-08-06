#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "Clearbass.h"
#include "main.h"

__thumb void *malloc(int size)
{
  return memalloc(-1, size, 1, 5, "EQ", NULL);
}

__thumb void mfree(void *mem)
{
  if (mem)
    memfree(NULL, mem, "EQ", NULL);
}

void Save_EqualiserData(bool is_manual, int32_t boost_level, int32_t b1, int32_t b2, int32_t b3, int32_t b4, int32_t b5)
{
  int file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    EQ_SETTINGS *FileData = (EQ_SETTINGS *)malloc(sizeof(EQ_SETTINGS));
    memset(FileData, NULL, sizeof(EQ_SETTINGS));
    FileData->manual = is_manual;
    FileData->boost_level = boost_level;
    FileData->bar1_level = b1;
    FileData->bar2_level = b2;
    FileData->bar3_level = b3;
    FileData->bar4_level = b4;
    FileData->bar5_level = b5;
    fwrite(file, FileData, sizeof(EQ_SETTINGS));
    fclose(file);
    mfree(FileData);
  }
}

void Get_EqualizerData(bool *is_manual, int32_t *boost_level, int32_t *bar1, int32_t *bar2, int32_t *bar3, int32_t *bar4, int32_t *bar5)
{
  int file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    EQ_SETTINGS *FileData = (EQ_SETTINGS *)malloc(sizeof(EQ_SETTINGS));
    memset(FileData, NULL, sizeof(EQ_SETTINGS));
    fread(file, FileData, sizeof(EQ_SETTINGS));
    *is_manual = FileData->manual;
    *boost_level = FileData->boost_level;
    *bar1 = FileData->bar1_level;
    *bar2 = FileData->bar2_level;
    *bar3 = FileData->bar3_level;
    *bar4 = FileData->bar4_level;
    *bar5 = FileData->bar5_level;
    fclose(file);
    mfree(FileData);
  }
}

extern "C" void SetEqualizerState()
{
  bool is_manual;
  int32_t boost_level, b1, b2, b3, b4, b5;
  Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);
  Save_EqualiserData(FALSE, boost_level, b1, b2, b3, b4, b5);
}

extern "C" bool GetEqualizerState()
{
  bool is_manual;
  int32_t boost_level, b1, b2, b3, b4, b5;
  Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);
  return is_manual;
}

extern "C" void SetManualEQ(BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  bool is_manual;
  int32_t boost_level, b1, b2, b3, b4, b5;
  Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);

  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_63, (b1 - Bar_Netral) * (boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_250, (b2 - Bar_Netral) * (boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000, (b3 - Bar_Netral) * (boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_4000, (b4 - Bar_Netral) * (boost_level + 2));
  MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000, (b5 - Bar_Netral) * (boost_level + 2));
}

void Clearbass_SelectAction(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  int32_t boost_level, b1, b2, b3, b4, b5;
  GUIObject_Clearbass_GetBarLevel(MusicBook->Gui_submenu, &boost_level, &b1, &b2, &b3, &b4, &b5);
  Save_EqualiserData(TRUE, boost_level, b1, b2, b3, b4, b5);

  FREE_GUI(MusicBook->Gui_submenu);
}

void Clearbass_PrevAction(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  if (GetEqualizerState())
  {
    SetManualEQ(MusicBook);
  }
  else //reactivate eq preset
  {
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_63, MusicBook->EqBand_63);
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_250, MusicBook->EqBand_250);
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000, MusicBook->EqBand_1000);
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_4000, MusicBook->EqBand_4000);
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000, MusicBook->EqBand_16000);
  }

  FREE_GUI(MusicBook->Gui_submenu);
}

int pg_MusicApplication_ManualEQ__EnterEvent(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  FREE_GUI(MusicBook->Gui_submenu);

  bool is_manual;
  int32_t boost_level, b1, b2, b3, b4, b5;
  Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);

  if (MusicBook->Gui_submenu = Create_ClearbassGUI(MusicBook))
  {
    GUIObject_Clearbass_SetBarLevel(MusicBook->Gui_submenu, boost_level, b1, b2, b3, b4, b5);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, Clearbass_SelectAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, Clearbass_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);
    GUIObject_Show(MusicBook->Gui_submenu);
  }
  return 1;
}

void Enter_ManualEqualizer(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;

  BookObj_CallPage(MusicBook, &page_MusicApplication_ManualEQ);
}

extern "C" void create_new_softkeys(GUI *Gui_submenu)
{
  GUIObject_SoftKeys_SetItemAsSubItem(Gui_submenu, ACTION_MP_SETTINGS, ACTION_MP_MANUALEQ);
  GUIObject_SoftKeys_SetAction(Gui_submenu, ACTION_MP_MANUALEQ, Enter_ManualEqualizer);
  GUIObject_SoftKeys_SetText(Gui_submenu, ACTION_MP_MANUALEQ, STR("Manual EQ"));
}
