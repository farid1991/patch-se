#ifndef _Main_H_
#define _Main_H_

#define MAX_PNGINFO_SIZE 256

typedef struct
{
  char *key;
  int key_len;
  char *value;
  int value_len;
} TEXT_LIST;

typedef struct
{
  png_uint_32 width;
  png_uint_32 height;
  int bit_depth;
  int pixel_depth;
  int color;
  int interlace;
  int compression;
  int filter;
  int channels;
#if defined(PNG_EXTRA_SUPPORTED)
  LIST *texts;
  int num_text;
#endif
} CHUNK_DATA;

#endif
