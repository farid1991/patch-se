#ifndef _FILEFOLDER_H_
#define _FILEFOLDER_H_

static char *EMP_FLIST ="FL";

static const wchar_t *IFS = L"ifs";
static const wchar_t *back = L"...";

typedef struct FILELIST
{
  void *next;
  int is_folder;
  wchar_t *fullpath;
  wchar_t *str_name;
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
