#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(g)           \
    if (g)                    \
    {                         \
        GUIObject_Destroy(g); \
        g = NULL;             \
    }

#define EMP_NAME "rb_emp"

typedef struct _RECYCLER
{
    bool state;
    bool is_marked;
} RECYCLER;

#endif
