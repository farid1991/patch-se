#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

TEXTID GetFreeHeap();

__thumb void *malloc(int size);
__thumb void mfree(void *mem);

#endif
