#ifndef C510_R1HA035
#error C510_R1HA035 configuration needed for this header!
#else
#ifndef _C510_R1HA035_
#define _C510_R1HA035_

#include "..\\include\dynconst\C510_R1HA035.h"

//#define VOLUME_SETTINGS_ID            L"Volume_Setttings_Id"
#define BOOK_NAME                     "Volume Settings"
#define FirstRow_Text                 L"Настройки громкости"
#define SecondRow_Format              L"Громкость: %d, %d, %d"

#define ImagePath                     L"/card/other/ZBin/Config/VolumeSettings"
#define CfgName                       L"VolumeSettings.ini"

#define ProfileBook                   0x15D563D8
#define StandartRingMenu              0x1450F60D

#define onCloseBook                   0x14D662BD
#define OnStandyEvent                 0x15505029
//#define OnShutdownEvent               0x15505035

#endif
#endif
