#ifndef ScreenShot_H
#define ScreenShot_H

#define MAGIC_WORD 0x4D42
#define SIZE_WO_MAGIC 52
#define HEADER_SIZE 40
#define DATA_OFFSET 54
#define NBR_OF_PLANE 1
#define BITSPERPLANE 24

#pragma pack(1)
typedef struct
{
  u16 ID;
  int size;
  u16 zero;
  u16 zero1;
  int dataoffset;
  int sizeofheader;
  int width;
  int height;
  u16 planes;
  u16 bpp;
  int compression;
  int sizeofimage;
  int hresolution;
  int vresolution;
  int colors;
  int important;
} BMP_HEADER;
#pragma pack()

void Screenshoter(int xsize, int ysize);

#endif
