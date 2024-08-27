#ifndef _IILLUMINATIONCONTROL_H_
#define _IILLUMINATIONCONTROL_H_

#include "..\types\Basic_types.h"

// UUID CID_CIlluminationControl = { 0xBF, 0x60, 0xD1, 0x6E, 0xC0, 0xEF, 0x41, 0xFC, 0xA7, 0x37, 0x81, 0x64, 0x8F, 0x45, 0x23, 0xF6 };
// UUID IID_IIlluminationControl = { 0x16, 0xE2, 0x36, 0xF4, 0x00, 0x15, 0x4E, 0x02, 0x97, 0xC6, 0x3A, 0x29, 0x58, 0xBE, 0x9B, 0xCE };

class IIlluminationControl : public IUnknown // C902 AS 0x11DD12C8
{
public:
  virtual int Illumination_LedID_SetLevel(int LedID, int level);
  virtual int Illumination_LedID_Off(int LedID);
  virtual int Illumination_LedID_SetLevel_Gradually(int LedID, int fade, int level);
};

#endif
