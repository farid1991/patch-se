#ifndef _FILEFOLDER_H_
#define _FILEFOLDER_H_

#define EMP_NAME "FList"

const wchar_t back[] = L"...";

typedef struct FILELIST
{
  void *next;
  int is_folder;
  wchar_t *fullname;
  wchar_t *name;
} FILELIST;

typedef struct FILEDATA
{
  FILELIST *fltop;
} FILEDATA;

#define FREE_FLGUI(a) \
  Free_FLIST();       \
  FREE_GUI(a);

GUI_LIST *CreateFileFolderSelect(BOOK *book, wchar_t *str);
int isdir(wchar_t *name);

#endif
