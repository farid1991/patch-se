#ifndef __IMETADATATYPES_H__
#define __IMETADATATYPES_H__

typedef struct
{
  char cover_type;
  int size;
  int cover_offset;
}COVER_INFO_DESC;

typedef enum
{
  TMetadataTagId_Artist,
  TMetadataTagId_Title,
  TMetadataTagId_Album,
  TMetadataTagId_Year,
  TMetadataTagId_Genre,
  TMetadataTagId_x6,
  TMetadataTagId_x7,
} TMetadata_TagId;

#endif
