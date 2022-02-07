#ifndef Cover_h
#define Cover_h

#define INDEX(x) x / 8
#define SHIFT(x) x % 8
#define GETBIT(v, x) ((v[INDEX(x)] << SHIFT(x)) & 0x80) >> 7

int MetaData_ExtractCover(wchar_t *path, wchar_t *name);

#endif
