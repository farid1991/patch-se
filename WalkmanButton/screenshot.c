#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\bmp.h"

#include "bookman.h"
#include "main.h"
#include "Lib.h"
#include "screenshot.h"
#include "StrLib.h"

void play_system_sound(int sndNbr)
{
  if (!GetSilent() && !FindBook(IsAudioPlayerBook))
    PlaySystemSound(sndNbr);
}

char *get_display_buffer()
{
  SURFACE *surface = *get_Surfaces;
  while ((!surface->Display) && (surface->next))
    surface = surface->next;
  if (surface)
    return (char *)surface->Buffer;
  return NULL;
}

BMP_HEADER *bmp_header_create(int width, int height)
{
  BMP_HEADER *hdr = (BMP_HEADER *)malloc(sizeof(BMP_HEADER));
  memset(hdr, 0, sizeof(BMP_HEADER));
  hdr->signature = BMP_SIGNATURE;
  hdr->size = BMP_SIZE(width, height) + HDR_SIZE_WO_SIGNATURE;
  hdr->dataoffset = DATA_OFFSET;
  hdr->headersize = HEADER_SIZE;
  hdr->width = width;
  hdr->height = height;
  hdr->planes = NBR_OF_PLANE;
  hdr->bpp = NBR_OF_BITS;
  hdr->imagesize = BMP_SIZE(width, height);
  return hdr;
}

void Screenshoter(int width, int height)
{
  BMP_HEADER *hdr = bmp_header_create(width, height);
  int bmp_size = hdr->imagesize + hdr->dataoffset;
  char *bmp = (char *)malloc(bmp_size);
  char *img = bmp + hdr->dataoffset;
  char *display_buffer = get_display_buffer();

  memcpy(bmp, hdr, hdr->dataoffset);

  int x;
  int y;
  u16 rgb = 0;
  y = height;
  do
  {
    char *pixels = display_buffer + (2 * width * (y - 1));
    x = 0;
    do
    {
      rgb = pixels[0] + (pixels[1] << 8);

      pixels += 2;
      *img++ = (rgb & 0x001F) << 3;
      *img++ = (rgb & 0x07E0) >> 3;
      *img++ = (rgb & 0xF800) >> 8;
    } while (++x < width);
  } while (--y);

  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);
  
  wchar_t *fname = WStringAlloc(MAX_FILENAME_LEN);
  wchar_t *fpath = WStringAlloc(MAX_FILENAME_LEN);
  
  snwprintf(fpath, MAX_FILENAME_LEN, L"/tpa/user/picture/SnapShots/%02d-%02d-%02d", dt.date.day, dt.date.mon, dt.date.year);
  snwprintf(fname, MAX_FILENAME_LEN, L"scr%02d-%02d-%02d.bmp", dt.time.hour, dt.time.min, dt.time.sec);

  int file = _fopen(fpath, fname, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0);
  if (file >= 0)
  {
    fwrite(file, bmp, bmp_size);
    fclose(file);
    play_system_sound(0x19);
  }
  else
  {
    play_system_sound(0xA);
  }

  mfree(bmp);
  mfree(fname);
  mfree(fpath);
}
