#ifndef _IUIICONSET_H_
#define _IUIICONSET_H_

#include "..\types\Basic_types.h"
#include "..\types\UIIcon_types.h"

class IIconSet : public IUnknown
{
public:
  virtual int GetIconData(TIconId iconId, IUnknown **ppISimpleLockableBuffer, FUint32 *pSize, char **ppMimeType);
  virtual int GetIconHeaderData(TIconId iconId, TIconHeader *pTIconHeader, IUnknown **ppISimpleLockableBufferExtraData);
  virtual int LoadIconFile(wchar_t *pIconFilePath);
  virtual int UnloadIconFile(wchar_t *pIconFilePath);
  virtual int GetIconVersion(TIconId iconId, FUint32 *pVersion);
};

#endif
