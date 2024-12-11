#ifndef _SkinList_h_
#define _SkinList_h_

typedef struct
{
  int name_len;
  wchar_t *fname;
  wchar_t *fpath;
} SKIN_LIST_ELEM;

void skin_list_destroy(LIST *&list);
LIST *skin_list_create(wchar_t *fullpath);

#endif
