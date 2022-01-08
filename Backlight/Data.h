#ifndef _DATA_H_
#define _DATA_H_

int FindNameFromData( char* name, FILEDATA wd[], int count );
void WriteData( BOOK* book, int count );
void DeleteData( int num, BOOK* book, int count );
char* GetNameFromData( FILEDATA wd[],int num );
int GetTimeFromData( FILEDATA wd[],int num );
int GetBrightFromData( FILEDATA wd[],int num );
void GetData( void* mydata, int size );

#endif
