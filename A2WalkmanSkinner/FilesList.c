#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "FilesList.h"
#include "main.h"
#include "String.h"

//==============================================================================

int ItemFilter(void *elem)
{
  return (elem != NULL);
}

void FreeList(LIST *&List, void (*FreeProc)(void *Item))
{
  if (List)
  {
    List_DestroyElements(List, ItemFilter, FreeProc);
    List_Destroy(List);
    List = NULL;
  }
}

void FilesFree(void *item)
{
  FILELIST *files = (FILELIST *)item;
  if (!files)
    return;

  mfree(files->fpath);
  mfree(files->fname);
  mfree(files->name);
  mfree(files);
}

FILELIST *Files_AddElement(wchar_t *FPath, wchar_t *FName)
{
  FILELIST *files = (FILELIST *)malloc(sizeof(FILELIST));

  files->fpath = WStringAlloc(wstrlen(FPath));
  files->fname = WStringAlloc(wstrlen(FName));
  wchar_t *temp_fname = WStringAlloc(wstrlen(FName));
  
  wstrcpy(files->fpath, FPath);
  wstrcpy(files->fname, FName);
  wstrcpy(temp_fname, FName);

  wchar_t *ext = wstrrchr(temp_fname, '.');
  *ext = 0;

  files->name = WStringAlloc(wstrlen(temp_fname));
  wstrcpy(files->name, temp_fname);
  mfree(temp_fname);

  return files;
}

BOOL IsDir(wchar_t *name)
{
  W_FSTAT fs;
  if (w_fstat(name, &fs) != -1)
    return fs.attr & FSX_O_CHKPATH;
  else
    return FALSE;
}

LIST *LoadFiles(wchar_t *Folder)
{
  LIST *Lst = List_Create();

  void *dir = w_diropen(Folder);
  if (!dir)
  {
    return Lst; // Return an empty list if the directory can't be opened.
  }

  w_chdir(Folder);
  wchar_t *next;
  while ((next = w_dirread(dir)))
  {
    if (!IsDir(next))
    {
      wchar_t *ext = getFileExtention(next);
      if (wstrcmpi(ext, L"WSK") == 0)
      {
        FILELIST *skinList = Files_AddElement(Folder, next);
        if (skinList)
        {
          List_InsertLast(Lst, skinList);
        }
      }
    }
  }
  w_dirclose(dir);

  return Lst;
}
