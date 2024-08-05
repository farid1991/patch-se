#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\dll.h"
#include "..\\main.h"
#include "..\\Function.h"

#include "..\\GUI\Clearbass.h"
#include "Equalizer.h"

#ifndef CLEARAUDIO
#ifndef STANDART_EQ
void SetEqualizerGain(BOOK *book, int band, int level)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  switch (band)
  {
  case Eq_Band1:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_63, level);
    break;
  case Eq_Band2:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_250, level);
    break;
  case Eq_Band3:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_1000, level);
    break;
  case Eq_Band4:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_4000, level);
    break;
  case Eq_Band5:
    MusicBook->pMusicServer->SetEqualizerGain(TMMEEqBand_16000, level);
    break;
  }
}

void SetEqualizerBands(BOOK *book, int8_t bar0, int8_t bar1, int8_t bar2, int8_t bar3, int8_t bar4, int8_t bar5)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  SetEqualizerGain(MusicBook, Eq_Band0, bar1 * (bar0 + 1));
  SetEqualizerGain(MusicBook, Eq_Band1, bar2 * (bar0 + 1));
  SetEqualizerGain(MusicBook, Eq_Band2, bar3 * (bar0 + 1));
  SetEqualizerGain(MusicBook, Eq_Band3, bar4 * (bar0 + 1));
  SetEqualizerGain(MusicBook, Eq_Band4, bar5 * (bar0 + 1));
}

void Save_EqualiserData(int Preset, BOOL Manual, int b0, int b1, int b2, int b3, int b4, int b5)
{
  int file = _fopen(EQ_CONFIG_PATH, EQ_CONFIG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    EQ_SETTINGS *FileData = (EQ_SETTINGS *)malloc(sizeof(EQ_SETTINGS));
    memset(FileData, NULL, sizeof(EQ_SETTINGS));

    FileData->preset = Preset;
    FileData->manual = Manual;
    FileData->boost_level = b0;
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

void Get_EqualizerData(int *preset, int *manual, int *bar0, int *bar1, int *bar2, int *bar3, int *bar4, int *bar5)
{
  int file = _fopen(EQ_CONFIG_PATH, EQ_CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0);
  if (file >= 0)
  {
    EQ_SETTINGS *FileData = (EQ_SETTINGS *)malloc(sizeof(EQ_SETTINGS));
    memset(FileData, NULL, sizeof(EQ_SETTINGS));
    fread(file, FileData, sizeof(EQ_SETTINGS));

    *preset = FileData->preset;
    *manual = FileData->manual;
    *bar0 = FileData->boost_level;
    *bar1 = FileData->bar1_level;
    *bar2 = FileData->bar2_level;
    *bar3 = FileData->bar3_level;
    *bar4 = FileData->bar4_level;
    *bar5 = FileData->bar5_level;

    fclose(file);
    mfree(FileData);
  }
}

void SaveDatatoBook(BOOK *book, int manual, int preset)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  if (manual)
  {
    MusicBook->EqPreset = TMusicServerEqPreset_Manual;
  }
  else
  {
    switch (preset)
    {
    case Eq_Treble:
      MusicBook->EqPreset = TMusicServerEqPreset_TrebleBoost;
      break;
    case Eq_Heavy:
      MusicBook->EqPreset = TMusicServerEqPreset_Voice;
      break;
    case Eq_Pop:
      MusicBook->EqPreset = TMusicServerEqPreset_Bass;
      break;
    case Eq_Jazz:
      MusicBook->EqPreset = TMusicServerEqPreset_Voice;
      break;
    case Eq_Normal:
      MusicBook->EqPreset = TMusicServerEqPreset_Normal;
      break;
    case Eq_Unique:
      MusicBook->EqPreset = TMusicServerEqPreset_Bass;
      break;
    case Eq_Soul:
      MusicBook->EqPreset = TMusicServerEqPreset_Voice;
      break;
    case Eq_Light:
      MusicBook->EqPreset = TMusicServerEqPreset_TrebleBoost;
      break;
    case Eq_Bass:
      MusicBook->EqPreset = TMusicServerEqPreset_Megabass;
      break;
    }
  }

  refresh_gui();
}

//==============================================================================

void ClearbassGUI_SelectAction(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  int preset, manual, bar0, bar1, bar2, bar3, bar4, bar5;
  preset = GUIObject_Clearbass_GetPresetCursor(MusicBook->Gui_submenu);
  GUIObject_Clearbass_GetBarLevel(MusicBook->Gui_submenu, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);

  manual = GUIObject_Clearbass_GetState(MusicBook->Gui_submenu);
  SaveDatatoBook(MusicBook, manual, preset);
  GUIObject_Clearbass_SetState(MusicBook->Gui_submenu, manual);
  Save_EqualiserData(preset, manual, bar0, bar1, bar2, bar3, bar4, bar5);
  DESTROY_GUI(MusicBook->Gui_submenu);
}

void ClearbassGUI_PrevAction(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  int preset, manual, bar0, bar1, bar2, bar3, bar4, bar5;
  Get_EqualizerData(&preset, &manual, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);
  SaveDatatoBook(MusicBook, manual, preset);
  GUIObject_Clearbass_SetState(MusicBook->Gui_submenu, manual);
  DESTROY_GUI(MusicBook->Gui_submenu);
}

void ClearbassGUI_onSwitch(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  if (GUIObject_Clearbass_GetState(MusicBook->Gui_submenu))
  {
    GUIObject_Clearbass_Switch(MusicBook->Gui_submenu, FALSE);
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_MANUAL);
  }
  else
  {
    GUIObject_Clearbass_Switch(MusicBook->Gui_submenu, TRUE);
    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_PRESET);
  }
}

//==============================================================================

extern "C" void New_SetEqualizerGain(BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  int preset, manual, bar0, bar1, bar2, bar3, bar4, bar5;
  Get_EqualizerData(&preset, &manual, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);

  if (manual)
  {
    SetEqualizerBands(MusicBook,
                      bar0,
                      bar1 - Bar_Netral,
                      bar2 - Bar_Netral,
                      bar3 - Bar_Netral,
                      bar4 - Bar_Netral,
                      bar5 - Bar_Netral);
  }
  else
  {
    SetEqualizerBands(MusicBook,
                      settings_table[preset][Eq_Band0],
                      settings_table[preset][Eq_Band1],
                      settings_table[preset][Eq_Band2],
                      settings_table[preset][Eq_Band3],
                      settings_table[preset][Eq_Band4],
                      settings_table[preset][Eq_Band5]);
  }
  SaveDatatoBook(MusicBook, manual, preset);
}

extern "C" int New_MusicApplication_Equalizer_EnterEvent(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);

  int preset, manual, bar0, bar1, bar2, bar3, bar4, bar5;
  Get_EqualizerData(&preset, &manual, &bar0, &bar1, &bar2, &bar3, &bar4, &bar5);

  if (MusicBook->Gui_submenu = Create_ClearbassGUI(MusicBook))
  {
    GUIObject_Clearbass_SetCursorToItem(MusicBook->Gui_submenu, preset);
    GUIObject_Clearbass_SetBarLevel(MusicBook->Gui_submenu, bar0, bar1, bar2, bar3, bar4, bar5);
    GUIObject_Clearbass_SetState(MusicBook->Gui_submenu, manual);

    GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSELECT, TEXT_SELECT);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, MP_EQ_ACTIONSELECT, ClearbassGUI_SelectAction);

    if (GUIObject_Clearbass_GetState(MusicBook->Gui_submenu))
    {
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_PRESET);
    }
    else
    {
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, TEXT_MANUAL);
    }
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, MP_EQ_ACTIONSWITCH, ClearbassGUI_onSwitch);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, ClearbassGUI_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);
    GUIObject_SetAnimation(MusicBook->Gui_submenu, 0xA0001021);
    GUIObject_Show(MusicBook->Gui_submenu);
  }
  return 1;
}

extern "C" int New_MusicApplication_Equalizer_CancelEvent(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  New_SetEqualizerGain(MusicBook);
  BookObj_ReturnPage(MusicBook, CANCEL_EVENT);
  return 1;
}
#endif
#endif
