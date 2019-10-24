#ifndef _METADATA_H_
#define _METADATA_H_

void* MetaData_Desc_Create( wchar_t* fpath, wchar_t* fname );
void MetaData_Desc_Destroy( void* MetaData_Desc );
int MetaData_Desc_GetCoverInfo( void* MetaData_Desc, char* cover_type, int* size, int* cover_offset );
wchar_t* MetaData_Desc_GetTags( void* MetaData_Desc, int tagID );
  
#endif
