#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_

void SaveSkinData(BOOK* bk, wchar_t* path,wchar_t* name);
void LoadSkinData(BOOK* bk, wchar_t* path,wchar_t* name);
void LoadTempDataToBookHeader(BOOK* book, int ID);

#endif

