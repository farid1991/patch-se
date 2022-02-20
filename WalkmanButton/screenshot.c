#include "temp\target.h"

#include "..\\include\Types.h"

#include "bookman.h"
#include "main.h"
#include "Lib.h"
#include "screenshot.h"
#include "StrLib.h"

void PlaySound(int sndNbr)
{
  if (!GetSilent() && !FindBook(IsAudioPlayerBook))
    PlaySystemSound(sndNbr);
}

char *GetDisplayBuffer()
{
  SURFACE *surface = *get_Surfaces;
  while ((!surface->Display) && (surface->next))
    surface = surface->next;
  if (surface)
    return (char *)surface->Buffer;
  return NULL;
}

BMP_HEADER *CreateHeader(int width, int height)
{
  BMP_HEADER *hdr = (BMP_HEADER *)malloc(sizeof(BMP_HEADER));
  memset(hdr, NULL, sizeof(BMP_HEADER));
  hdr->ID = BMP_SIGNATURE;
  hdr->size = IMAGE_SIZE(width, height) + SIZE_WO_SIGNATURE;
  hdr->dataoffset = DATA_OFFSET;
  hdr->sizeofheader = HEADER_SIZE;
  hdr->width = width;
  hdr->height = height;
  hdr->planes = NBR_OF_PLANE;
  hdr->bpp = NBR_OF_BITS;
  hdr->sizeofimage = IMAGE_SIZE(width, height);
  return hdr;
}

void Screenshoter(int xsize, int ysize)
{
  BMP_HEADER *hdr = CreateHeader(xsize, ysize);

  int x;
  int y;
  u16 rgb = 0;
  int bmp_size = hdr->sizeofimage + hdr->dataoffset;
  char *bmp = (char *)malloc(bmp_size);
  char *img = bmp + hdr->dataoffset;
  char *display_buffer = GetDisplayBuffer();

  memcpy(bmp, hdr, hdr->dataoffset);
  y = ysize;
  do
  {
    char *pixels = display_buffer + (2 * xsize * (y - 1));
    x = 0;
    do
    {
      rgb = pixels[0] + (pixels[1] << 8);

      pixels += 2;
      *img++ = (rgb & 0x001F) << 3;
      *img++ = (rgb & 0x07E0) >> 3;
      *img++ = (rgb & 0xF800) >> 8;
    } while (++x < xsize);
  } while (--y);

  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);
  wchar_t *path = SNAPSHOT_PATH;
  wchar_t *fname = WStringAlloc(MAX_FILENAME_LEN);
  wchar_t *fpath = WStringAlloc(wstrlen(path) + 20);
  wstrcpy(fpath, path);
  snwprintf(fname, 25, L"/%02d-%02d-%02d", dt.date.day, dt.date.mon, dt.date.year);
  wstrcat(fpath, fname);
  snwprintf(fname, 25, L"scr%02d-%02d-%02d.bmp", dt.time.hour, dt.time.min, dt.time.sec);

  int file;
  if ((file = _fopen(fpath, fname, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
  {
    fwrite(file, bmp, bmp_size);
    fclose(file);
    PlaySound(0x19);
  }
  else
  {
    PlaySound(0xA);
  }

  mfree(bmp);
  WStringFree(fname);
  WStringFree(fpath);
}
