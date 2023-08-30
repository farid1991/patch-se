#ifndef C510_R1FA035_Orange
#error C510_R1FA035_Orange configuration needed for this header!
#else
#ifndef _C510_R1FA035_Orange_
#define _C510_R1FA035_Orange_

#include "..\\include\dynconst\C510_R1FA035_Orange.h"

//#define VOLUME_SETTINGS_ID            L"Volume_Setttings_Id"
#define BOOK_NAME                     "Volume Settings"
#define FirstRow_Text                 L"Настройки громкости"
#define SecondRow_Format              L"Громкость: %d, %d, %d"

#define ImagePath                     L"/card/other/ZBin/Config/VolumeSettings"
#define CfgName                       L"VolumeSettings.ini"

#define ProfileBook                   0x15CA92E8
#define StandartRingMenu              0x1450F60D

#define onCloseBook                   0x14326EDD
#define OnStandyEvent                 0x1548476D
//#define OnShutdownEvent               0x15484779

#endif
#endif
