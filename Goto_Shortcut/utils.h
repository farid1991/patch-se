#ifndef _UTILS_H_
#define _UTILS_H_

void RunShortcut(SC_LIST_ELEM *Shortcut);
void *SHORTCUT_DESC_Init(wchar_t *param);
void *SHORTCUT_DESC_A2_Init(wchar_t *param);
void FreeList(LIST *&List, void (*FreeProc)(void *Item));
void JavaFree(void *item);
LIST *Create_JavaList();
void SaveConfig(LIST *List);
LIST *LoadConfig();

#endif
