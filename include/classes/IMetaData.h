#ifndef _IMETADATA_H_
#define _IMETADATA_H_

#include "..\\include\types\IMetaData_types.h"

const UUID CID_CMetaData = {0x0B, 0xCD, 0x95, 0x0F, 0x9F, 0xB6, 0x4E, 0x7A, 0xA7, 0xCD, 0xCA, 0x1D, 0x87, 0xBA, 0x9A, 0x27};
const UUID IID_IMetaData = {0xB1, 0xEB, 0x4F, 0x97, 0xB0, 0xDD, 0x42, 0x09, 0xB6, 0x96, 0xCE, 0x11, 0x2D, 0x5E, 0xD8, 0xE8};

class IMetaData;

typedef struct
{
  wchar_t artist[0x100];
  wchar_t title[0x100];
  wchar_t album[0x100];
  wchar_t year[0x100];
  wchar_t genre[0x100];
  wchar_t x6[0x100];
  wchar_t x7[0x100];
  IMetaData *pIMetaData;
}METADATA_DESC;

class IMetaData: public IRoot
{
public:
  virtual int SetFile( wchar_t* path, wchar_t* name);
  virtual int unk_0x14( void* unk1, void* unk2 );
  virtual int GetTag( TMetadata_TagId tagID, wchar_t* tag );
  virtual int GetTrackNum( int unk, int* track_num );
  virtual int GetCoverInfo( COVER_INFO_DESC* cover_info );
  virtual int unk_0x24();
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int IsHaveCover( wchar_t* path, wchar_t* name );
};

#endif
