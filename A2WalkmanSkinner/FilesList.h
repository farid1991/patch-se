#ifndef _FILESLIST_H_
#define _FILESLIST_H_

typedef struct
{
  wchar_t* filepath;
  wchar_t* filename;
  wchar_t* skinname;
}FILELIST;

GUI* Create_SelectSkin(BOOK* book);
int ItemFilter(void* elem);
void FreeList(LIST* &List, void (*FreeProc)(void *Item));
void FilesFree(void* item);
FILELIST* CreateElement(wchar_t* Folder, wchar_t* File);
BOOL IsDir( wchar_t* name );
LIST* LoadFiles(wchar_t* Folder);

#endif
