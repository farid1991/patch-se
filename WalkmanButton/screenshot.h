#ifndef ScreenShot_H
#define ScreenShot_H

#define BMP_SIGNATURE 0x4D42
#define SIZE_WO_SIGNATURE 52
#define HEADER_SIZE 40
#define DATA_OFFSET 54
#define NBR_OF_PLANE 1
#define NBR_OF_BITS 24
#define IMAGE_SIZE(w,h) (w*h*3)
#define MAX_FILENAME_LEN 50


#define SNAPSHOT_PATH L"/tpa/user/picture/SnapShots"

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
