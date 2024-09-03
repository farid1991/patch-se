#ifndef _FILELIST_H_
#define _FILELIST_H_

typedef struct
{
  wchar_t* name;
  wchar_t* filename;
} FILELIST_ELEM;

bool is_directory(wchar_t *path);
void file_list_remove_item(void *item);
void file_list_destroy(LIST *&list, void (*free_list)(void *item));
LIST *file_list_create(wchar_t *path);

#endif
