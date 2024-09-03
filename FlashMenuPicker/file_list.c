#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "file_list.h"
#include "main.h"

bool is_directory(wchar_t *path)
{
  W_FSTAT fs;
  if (w_fstat(path, &fs) != -1)
    return fs.attr & FSX_O_CHKPATH;
  return FALSE;
}

int file_list_item_filter(void *elem)
{
  return (elem != NULL);
}

void file_list_remove_item(void *item)
{
  FILELIST_ELEM *flist = (FILELIST_ELEM *)item;
  if (flist)
  {
    mfree(flist->name);
    mfree(flist->filename);
    mfree(flist);
  }
}

FILELIST_ELEM *file_list_add_item(wchar_t *filename)
{
  FILELIST_ELEM *flist = (FILELIST_ELEM *)malloc(sizeof(FILELIST_ELEM));
  if(!flist)
  {
    return NULL;
  }

  int filename_len = wstrlen(filename);
  int filename_size = (filename_len + 1);
  flist->filename = (wchar_t *)malloc(filename_size * sizeof(wchar_t));
  memset(flist->filename, L'\0', filename_size * sizeof(wchar_t));
  wstrncpy(flist->filename, filename, filename_len);
  flist->filename[filename_len] = L'\0';

  int name_len = filename_len - 4;
  int name_size = filename_size - 4;
  flist->name = (wchar_t *)malloc(name_size * sizeof(wchar_t));
  memset(flist->name, L'\0', name_size * sizeof(wchar_t));
  wstrncpy(flist->name, filename, name_len);
  flist->name[name_len] = L'\0';

  return flist;
}

void file_list_destroy(LIST *&flist, void (*free_list)(void *item))
{
  if (flist)
  {
    List_DestroyElements(flist, file_list_item_filter, free_list);
    List_Destroy(flist);
    flist = NULL;
  }
}

LIST *file_list_create(wchar_t *path)
{
  LIST *list = List_Create();

  void *dir = w_diropen(path);
  if (!dir)
  {
    return list;
  }

  w_chdir(path);
  wchar_t *next;
  while (next = w_dirread(dir))
  {
    if (!is_directory(next))
    {
      wchar_t *ext = getFileExtention(next);
      if (wstrcmpi(ext, L"swf") == 0)
      {
        FILELIST_ELEM *flist_elem = file_list_add_item(next);
        if (flist_elem)
        {
          List_InsertLast(list, flist_elem);
        }
      }
    }
  }
  w_dirclose(dir);

  return list;
}
