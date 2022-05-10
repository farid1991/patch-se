#ifndef _Main_H_
#define _Main_H_

#define CONFIG_NAME L"OnOffButton.bin"


#define FREE(mem) \
  if (mem)        \
  {               \
    mfree(mem);   \
    mem = NULL;   \
  }

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

__thumb void *malloc(int size);
__thumb void mfree(void *mem);
TEXTID GetFreeHeap();

#define mfree_adr()			mfree

#endif
