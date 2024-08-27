#ifndef _BMP_H_
#define _BMP_H_

#pragma pack(1)
typedef struct
{
  uint16_t signature;
  uint32_t size;
  uint32_t reserved;
  uint32_t dataoffset;
  uint32_t headersize;
  uint32_t width;
  uint32_t height;
  uint16_t planes;
  uint16_t bpp;
  uint32_t compression;
  uint32_t imagesize;
  uint32_t hresolution;
  uint32_t vresolution;
  uint32_t colors;
  uint32_t important;
} BMP_HEADER;
#pragma pack()

#define BMP_SIGNATURE 0x4D42
#define HDR_SIZE_WO_SIGNATURE 0x34
#define HEADER_SIZE 0x28
#define DATA_OFFSET 0x36
#define NBR_OF_PLANE 1
#define NBR_OF_BITS 24
#define BMP_SIZE(w,h) (w*h*3)

#endif
