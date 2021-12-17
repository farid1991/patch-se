#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
#if defined(DB2010)
    void *memalloc(int size, int f1, int f2, const char *fname, int fline);
    void memfree(void *mem, const char *fname, int fline);
#elif defined(DB2020)
    void *memalloc(int zero, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
#elif defined(A2)
    void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
#endif

    int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);
    void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);
    int datetime2unixtime(DATETIME *dt);
    void unixtime2datetime(int, DATETIME *);

    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
}

#endif
