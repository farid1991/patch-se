#ifndef _UTILS_H_
#define _UTILS_H_

enum JAVA_APP_ID
{
  JAVA_APP_NAME,
  JAVA_APP_UNK,
  JAVA_APP_VENDOR,
  JAVA_APP_CERT,
  JAVA_APP_HASH,
  JAVA_APP_FULLPATH,
  JAVA_APP_SEMCLET,
  LAST_ID
};

void RunShortcut(SC_LIST_ELEM *Shortcut);
void *SHORTCUT_DESC_Init(wchar_t *param);
void list_destroy(LIST *&List, void (*FreeProc)(void *Item));
void java_list_free_item(void *item);
LIST *java_list_create();
void SaveConfig(LIST *List);
LIST *LoadConfig();

#endif
