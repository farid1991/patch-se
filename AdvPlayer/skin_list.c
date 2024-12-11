#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "skin_list.h"
#include "str_lib.h"

BOOL is_directory(wchar_t *path)
{
  W_FSTAT fs;
  if (w_fstat(path, &fs) == -1)
    return FALSE;
  return (fs.attr & FSX_O_CHKPATH) != 0;
}

BOOL skin_list_filter(void *elem)
{
  return (elem != NULL);
}

void skin_list_remove_elem(void *item)
{
  SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)item;
  if (skin)
  {
    mfree(skin->fname);
    mfree(skin->fpath);
    mfree(skin);
  }
}

void skin_list_destroy(LIST *&list)
{
  if (list)
  {
    List_DestroyElements(list, skin_list_filter, skin_list_remove_elem);
    List_Destroy(list);
    list = NULL;
  }
}

SKIN_LIST_ELEM *skin_list_create_elem(wchar_t *name, wchar_t *skinpath)
{
  SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)malloc(sizeof(SKIN_LIST_ELEM));

  skin->name_len = wstrlen(name);
  skin->fname = wstr_alloc(skin->name_len);
  wstrcpy(skin->fname, name);

  int path_len = wstrlen(skinpath) + skin->name_len + 1;
  skin->fpath = wstr_alloc(path_len);
  wstrcpy(skin->fpath, skinpath);
  wstrcat(skin->fpath, L"/");
  wstrcat(skin->fpath, name);

  return skin;
}

LIST *skin_list_create(wchar_t *skinpath)
{
  void *dir = w_diropen(skinpath);
  if (!dir)
  {
    return NULL;
  }

  LIST *skin_list = List_Create();

  wchar_t *next;
  w_chdir(skinpath);
  while ((next = w_dirread(dir)) != NULL)
  {
    if (is_directory(next))
    {
      SKIN_LIST_ELEM *skin = skin_list_create_elem(next, skinpath);
      if (skin)
      {
        List_InsertLast(skin_list, skin);
      }
    }
  }
  w_dirclose(dir);

  return skin_list;
}
