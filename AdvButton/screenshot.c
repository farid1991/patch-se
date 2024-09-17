#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#ifdef USE_LIBPNG
#include "..\\include\png.h"
#else
#include "..\\include\bmp.h"
#endif

#include "main.h"
#include "screenshot.h"

wchar_t *wstr_alloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, 0, size);
  return (wstr);
}

void play_system_sound(int sndNbr)
{
  if (!GetSilent() && !FindBook(IsAudioPlayerBook))
    PlaySystemSound(sndNbr);
}

#ifdef USE_IDISPLAY_MANAGER
int get_display_buffer(int width, int height, uint8_t *buffer)
{
  IDisplayManager *pDisplayManager = NULL;
  IDisplaySession *pDisplaySession = NULL;
  IShell *pShell = NULL;

  OSE_GetShell(PPINTERFACE(&pShell));

  if (SUCCEEDED(pShell))
  {
    pShell->CreateInstance(CID_CDisplayManager, IID_IDisplayManager, PPINTERFACE(&pDisplayManager));
    pShell->Release();
  }

  if (SUCCEEDED(pDisplayManager))
  {
    pDisplayManager->CreateDisplaySession(0, 0, 0, 0, 0, &pDisplaySession);
    pDisplayManager->Release();
  }

  if (SUCCEEDED(pDisplaySession))
  {
    pDisplaySession->GetDisplayBuffer(0, 0, width, height, buffer);
    pDisplaySession->Release();
    return 1;
  }

  return 0;
}
#else

#if defined(DB2010)
uint8_t *get_display_buffer()
{
  return (uint8_t *)(**(int **)get_VBUFFER);
}
#elif defined(DB2020)
uint8_t *get_display_buffer()
{
  SURFACE *surface = *get_Surfaces;
  while ((surface->RefCount != 1) && (!surface->Display))
  {
    surface = surface->next;
  }
  return (uint8_t *)surface->Buffer;
}
#elif defined(PNX5230) || defined(A2)
uint8_t *get_display_buffer()
{
  SURFACE *surface = *get_Surfaces;
  while ((!surface->Display) && (surface->next))
  {
    surface = surface->next;
  }
  if (surface)
    return (uint8_t *)surface->Buffer;
  return NULL;
}
#else // DB2000
uint8_t *get_display_buffer()
{
  return NULL;
}
#endif
#endif

#ifdef USE_LIBPNG
void *my_png_malloc(png_structp png_ptr, png_size_t size)
{
  return malloc(size);
}

void my_png_free(png_structp png_ptr, png_voidp ptr)
{
  mfree(ptr);
}

void my_png_write(png_structp png_ptr, png_bytep data, png_size_t length)
{
  int *io_ptr = (int *)png_get_io_ptr(png_ptr);
  fwrite(*io_ptr, data, length);
}

int save_as_png(wchar_t *path, wchar_t *name, int width, int height, uint8_t *display_buffer)
{
  int file = _fopen(path, name, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file < 0)
  {
    return 0;
  }

  png_structp png_ptr;
  png_infop info_ptr;

  png_ptr = png_create_write_struct_2(DEF_LIBPNG_VER_STRING,
                                      NULL, NULL, NULL, NULL,
                                      my_png_malloc, my_png_free);
  if (!png_ptr)
  {
    fclose(file);
    return 0;
  }

  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
  {
    png_destroy_write_struct(&png_ptr, NULL);
    fclose(file);
    return 0;
  }

  png_set_IHDR(png_ptr, info_ptr, width, height,
               8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
               PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

  png_set_write_fn(png_ptr, &file, my_png_write, NULL);

  png_write_info(png_ptr, info_ptr);

#ifdef USE_IDISPLAY_MANAGER
  // RGBA display_buffer
  png_set_filler(png_ptr, 0, PNG_FILLER_AFTER);

  png_set_bgr(png_ptr);

  for (int row = 0; row < height; row++)
  {
    uint8_t *png_row = display_buffer + (row * width * 4);
    png_write_row(png_ptr, png_row);
  }
#else
  // RGB565 display_buffer
  uint8_t *rgb888 = (uint8_t *)malloc(width * height * 3);
  uint8_t *img = rgb888;
  for (int y = 0; y < height; ++y)
  {
    uint8_t *rgb565 = display_buffer + (2 * width * (y - 1));
    for (int x = 0; x < width; ++x)
    {
#if defined(DB2010)
      uint16_t rgb = rgb565[1] | (rgb565[0] << 8); // Little Endian
#else
      uint16_t rgb = rgb565[0] | (rgb565[1] << 8); // Big Endian
#endif
      rgb565 += 2;

      *img++ = ((rgb & 0xF800) >> 8); // Red
      *img++ = ((rgb & 0x07E0) >> 3); // Green
      *img++ = ((rgb & 0x001F) << 3); // Blue
    }
  }

  for (int row = 0; row < height; ++row)
  {
    uint8_t *png_row = rgb888 + (row * width * 3);
    png_write_row(png_ptr, png_row);
  }
  mfree(rgb888);
#endif
  png_write_end(png_ptr, info_ptr);
  png_destroy_write_struct(&png_ptr, &info_ptr);

  fclose(file);
  return 1;
}
#else
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

int save_as_bmp(wchar_t *path, wchar_t *name, int width, int height, uint8_t *display_buffer)
{
  int file = _fopen(path, name, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file < 0)
  {
    return 0;
  }

  BMP_HEADER *bmp_hdr = bmp_header_create(width, height);
  int bmp_size = bmp_hdr->imagesize + bmp_hdr->dataoffset;
  uint8_t *bmp_img = (uint8_t *)malloc(bmp_size);
  uint8_t *img = bmp_img + bmp_hdr->dataoffset;

  memcpy(bmp_img, bmp_hdr, bmp_hdr->dataoffset);

  int x = 0;
  int y = 0;
#ifdef USE_IDISPLAY_MANAGER
  // RGBA display_buffer
  for (y = height; y > 0; --y)
  {
    uint8_t *rgba = display_buffer + (4 * width * (y - 1));
    x = width;

    while (x >= 4)
    {
      memcpy(img, rgba, 3);
      img += 3;
      rgba += 4;
      memcpy(img, rgba, 3);
      img += 3;
      rgba += 4;
      memcpy(img, rgba, 3);
      img += 3;
      rgba += 4;
      memcpy(img, rgba, 3);
      img += 3;
      rgba += 4;
      x -= 4;
    }

    while (x--)
    {
      memcpy(img, pixels, 3);
      img += 3;
      pixels += 4;
    }
  }
#else
  // RGB565 display_buffer
  for (y = height; y > 0; --y)
  {
    uint8_t *rgb565 = display_buffer + (2 * width * (y - 1));
    for (x = 0; x < width; ++x)
    {
#if defined(DB2010)
      uint16_t rgb = rgb565[1] | (rgb565[0] << 8); // Little Endian
#else
      uint16_t rgb = rgb565[0] | (rgb565[1] << 8); // Big Endian
#endif
      rgb565 += 2;

      *img++ = (rgb & 0x001F) << 3; // Blue
      *img++ = (rgb & 0x07E0) >> 3; // Green
      *img++ = (rgb & 0xF800) >> 8; // Red
    }
  }
#endif
  fwrite(file, bmp_img, bmp_size);
  fclose(file);

  mfree(bmp_hdr);
  mfree(bmp_img);

  return 1;
}
#endif

void Screenshoter(int width, int height)
{
  int res;
#ifdef USE_IDISPLAY_MANAGER
  uint8_t *display_buffer = (uint8_t *)malloc(width * height * 4);
  res = get_display_buffer(width, height, display_buffer);
  if (!res)
  {
    MessageBox(EMPTY_TEXTID, TextID_Create("Could not get display_buffer", ENC_LAT1, TEXTID_ANY_LEN), NOIMAGE, 0, 0, 0);
    mfree(display_buffer);
    return;
  }
#else
  uint8_t *display_buffer = get_display_buffer();
    if (!display_buffer)
  {
    MessageBox(EMPTY_TEXTID, TextID_Create("Could not get display_buffer", ENC_LAT1, TEXTID_ANY_LEN), NOIMAGE, 0, 0, 0);
    return;
  }
#endif

  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);

  wchar_t *fpath = wstr_alloc(MAX_FILENAME_LEN);
#ifdef SAVE_AT_USB
  snwprintf(fpath, MAX_FILENAME_LEN, L"/usb/image/SnapShots/%02d-%02d-%02d", dt.date.day, dt.date.mon, dt.date.year);
#else
  snwprintf(fpath, MAX_FILENAME_LEN, L"/tpa/user/image/SnapShots/%02d-%02d-%02d", dt.date.day, dt.date.mon, dt.date.year);
#endif
  wchar_t *fname = wstr_alloc(MAX_FILENAME_LEN);
#ifdef USE_LIBPNG
  snwprintf(fname, MAX_FILENAME_LEN, L"scr%02d-%02d-%02d.png", dt.time.hour, dt.time.min, dt.time.sec);
  res = save_as_png(fpath, fname, width, height, display_buffer);
#else
  snwprintf(fname, MAX_FILENAME_LEN, L"scr%02d-%02d-%02d.bmp", dt.time.hour, dt.time.min, dt.time.sec);
  res = save_as_bmp(fpath, fname, width, height, display_buffer);
#endif

  if (res)
    play_system_sound(AUDIO_NOTIFICATION_SUCCESS);
  else
    play_system_sound(AUDIO_NOTIFICATION_FAILURE);

#ifdef USE_IDISPLAY_MANAGER
  mfree(display_buffer);
#endif

  mfree(fpath);
  mfree(fname);
}
