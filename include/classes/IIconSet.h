#ifndef _IUIICONSET_H_
#define _IUIICONSET_H_

#include "..\types\Basic_types.h"

/**
 * Used to identify the Id of an icon.
 * @ingroup Icon_Manager
 */
typedef FUint32 TIconId;

/**
 * Represents the header data of an icon
 * @ingroup Icon_Manager
 */
typedef struct
{
    TBool hasExtraData; /// True if the length of the extra data for the icon is grater then 0
} TIconHeader;

/**
 * Bitmasks used by UIImages to calculate iconID:s
 * @ingroup Icon_Manager
 */
typedef enum
{
    ICONID_MASK_ROTATION_ROTATIONBITS = 0xC0000000,       /// 2 top bits reserved for orientation
    ICONID_MASK_DISPLAY_DISPLAYBITS = 0x38000000,         /// 3 bits reserved for display
    ICONID_MASK_ROTATION_VERTICAL = 0x00000000,           /// Vertical 0
    ICONID_MASK_ROTATION_HORIZONTAL = 0x40000000,         /// Horesontal 1
    ICONID_MASK_ROTATION_HORIZONTALREVERSED = 0x80000000, /// Horesontal reversed 2
    ICONID_MASK_DISPLAY_MAIN = 0x00000000,                /// Main front display 0
    ICONID_MASK_DISPLAY_SECOND = 0x08000000               /// Second display 1
} TIconID_Mask;

// OBSOLETE
/**
 * Used to identify the set of icons to use.
 */
typedef FUint32 TIconSet;

const TIconSet TIconSet_Undefined = 0;

class IIconSet : public IUnknown
{
    virtual int GetIconData(TIconId iconId, IUnknown **ppISimpleLockableBuffer, FUint32 *pSize, char **ppMimeType);
    virtual int GetIconHeaderData(TIconId iconId, TIconHeader *pTIconHeader, IUnknown **ppISimpleLockableBufferExtraData);
    virtual int LoadIconFile(wchar_t *pIconFilePath);
    virtual int UnloadIconFile(wchar_t *pIconFilePath);
    virtual int GetIconVersion(TIconId iconId, FUint32 *pVersion);
};

#endif
