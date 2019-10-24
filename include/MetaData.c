#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\interface\IMetaData.h"
#include "..\\include\types\IMetaData_types.h"

#if defined(A2)
void* MetaData_Desc_Create( wchar_t* fpath, wchar_t* fname )
{
  METADATA_DESC * MetaData_Desc = new METADATA_DESC;
  MetaData_Desc->pMetaData = NULL;
  MetaData_Desc->artist[0] = NULL;
  MetaData_Desc->title[0] = NULL;
  MetaData_Desc->album[0] = NULL;
  MetaData_Desc->year[0] = NULL;
  MetaData_Desc->genre[0] = NULL;
  MetaData_Desc->x6[0] = NULL;
  MetaData_Desc->x7[0] = NULL;
  CoCreateInstance(CID_CMetaData, IID_IMetaData, PPINTERFACE(&MetaData_Desc->pMetaData));
  MetaData_Desc->pMetaData->SetFile(fpath,fname);
  return(MetaData_Desc);
}
#endif

#if defined(A2)
void MetaData_Desc_Destroy( void* MetaData_Desc )
{
  if (((METADATA_DESC*)MetaData_Desc)->pMetaData) ((METADATA_DESC*)MetaData_Desc)->pMetaData->Release();
  delete(MetaData_Desc);
}
#endif

#if defined(A2)
wchar_t* MetaData_Desc_GetTags( void* MetaData_Desc, int tagID )
{
  METADATA_DESC * meta_desc = (METADATA_DESC*)MetaData_Desc;
  wchar_t* buf;
  switch(tagID)
  {
  case TMetadataTagId_Artist:
    buf = meta_desc->artist;
    break;
  case TMetadataTagId_Title:
    buf = meta_desc->title;
    break;
  case TMetadataTagId_Album:
    buf = meta_desc->album;
    break;
  case TMetadataTagId_Year:
    buf = meta_desc->year;
    break;
  case TMetadataTagId_Genre:
    buf = meta_desc->genre;
    break;
  case TMetadataTagId_x6:
    buf = meta_desc->x6;
    break;
  case TMetadataTagId_x7:
    buf = meta_desc->x7;
    break;
  }
  meta_desc->pMetaData->GetTag(tagID,buf);
  return(buf);
}
#endif

#if defined(A2)
int MetaData_Desc_GetTrackNum( void* MetaData_Desc, int __NULL )
{
  int track_num;
  ((METADATA_DESC*)MetaData_Desc)->pMetaData->GetTrackNum(__NULL,&track_num);
  return(track_num);
}
#endif

#if defined(A2)
int MetaData_Desc_GetCoverInfo( void* MetaData_Desc, char* cover_type, int* size, int* cover_offset )
{
  COVER_INFO_DESC CoverInfo;
  if( ((METADATA_DESC*)MetaData_Desc)->pMetaData->GetCoverInfo(&CoverInfo)<0) return FALSE;
  *cover_type = CoverInfo.cover_type;
  *size = CoverInfo.size;
  *cover_offset = CoverInfo.cover_offset;
  return TRUE;
}
#endif
