#ifndef _TagList_H_
#define _TagList_H_

typedef struct
{
  uint16_t tag;
  uint16_t type;
  uint16_t name_len;
  uint16_t value_len;
  char *name;
  char *value;
} TAG_LIST_ELEM;

int tag_list_item_filter(void *elem);
void tag_list_destroy(LIST *&list, void (*free_list)(void *item));
void tag_list_remove_elem(void *item);
TAG_LIST_ELEM *tag_list_create_elem(int tag, char *name, char *value);

#endif
