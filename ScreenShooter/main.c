#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\bmp.h"
#include "..\\include\png.h"

#include "dll.h"
#include "main.h"

void *malloc(int size)
{
  return memalloc(0xFFFFFFFF, size, 1, 5, "SS", NULL);
}

void mfree(void *mem)
{
  if (mem)
    memfree(NULL, mem, "SS", NULL);
}

wchar_t *wstr_alloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, 0, size);
  return wstr;
}

void play_system_sound(int snd_nbr)
{
  if (!GetSilent() && !FindBook(IsAudioPlayerBook))
    PlaySystemSound(snd_nbr);
}

void *my_png_malloc(png_structp png_ptr, png_size_t size)
{
  return malloc(size);
}

void my_png_free(png_structp png_ptr, void *ptr)
{
  mfree(ptr);
}

void my_png_write(png_structp png_ptr, png_bytep data, png_size_t length)
{
  int *io_ptr = (int *)png_get_io_ptr(png_ptr);
  fwrite(*io_ptr, data, length);
}

void my_png_flush(png_structp png_ptr)
{
  int *io_ptr = (int *)png_get_io_ptr(png_ptr);
  fflush(*io_ptr);
}

int save_as_png(wchar_t *path, wchar_t *name, char *bookname, int width, int height, uint8_t *display_buffer, TDisplayManagerInfo *display_info)
{
  int file = _fopen(path, name, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    png_structp png_ptr;
    png_infop info_ptr;

    png_ptr = png_create_write_struct_2(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL, NULL, my_png_malloc, my_png_free);
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
                 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_set_bgr(png_ptr);

    char *driver_version = (char *)malloc(DISPLAY_VERSION_LEN);
    wstr2strn(driver_version, display_info->driver_version, DISPLAY_VERSION_LEN);

    png_text text_ptr[4];
    text_ptr[0].key = "x-author";
    text_ptr[0].text = "(c) farid";
    text_ptr[0].compression = PNG_TEXT_COMPRESSION_zTXt;
    text_ptr[1].key = "x-desc";
    text_ptr[1].text = "PNG Screenshooter";
    text_ptr[1].compression = PNG_TEXT_COMPRESSION_zTXt;
    text_ptr[2].key = "x-driver";
    text_ptr[2].text = driver_version;
    text_ptr[2].compression = PNG_TEXT_COMPRESSION_zTXt;
    text_ptr[3].key = "x-book";
    text_ptr[3].text = bookname;
    text_ptr[3].compression = PNG_TEXT_COMPRESSION_zTXt;
    png_set_text(png_ptr, info_ptr, text_ptr, 4);

    png_set_write_fn(png_ptr, &file, my_png_write, my_png_flush);

    png_set_compression_level(png_ptr, 6);

    png_write_info(png_ptr, info_ptr);

    int size = png_get_rowbytes(png_ptr, info_ptr);
    for (int y = 0; y < height; y++)
    {
      png_byte *ptr = (png_byte *)(display_buffer + y * size);
      png_write_row(png_ptr, ptr);
    }

    png_write_end(png_ptr, info_ptr);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    mfree(driver_version);

    fclose(file);
    return 1;
  }
  return 0;
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

int save_as_bmp(wchar_t *path, wchar_t *name, int width, int height, uint8_t *display_buffer)
{
  int file = _fopen(path, name, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= NULL)
  {
    BMP_HEADER *hdr = bmp_header_create(width, height);
    int bmp_size = hdr->imagesize + hdr->dataoffset;
    uint8_t *bmp = (uint8_t *)malloc(bmp_size);
    uint8_t *img = bmp + hdr->dataoffset;

    memcpy(bmp, hdr, hdr->dataoffset);

    int x = 0;
    int y = 0;
    for (y = height; y > 0; --y)
    {
      uint8_t *pixels = display_buffer + (4 * width * (y - 1));
      x = width;

      while (x >= 4)
      {
        memcpy(img, pixels, 3);
        img += 3;
        pixels += 4;
        memcpy(img, pixels, 3);
        img += 3;
        pixels += 4;
        memcpy(img, pixels, 3);
        img += 3;
        pixels += 4;
        memcpy(img, pixels, 3);
        img += 3;
        pixels += 4;
        x -= 4;
      }

      while (x--)
      {
        memcpy(img, pixels, 3);
        img += 3;
        pixels += 4;
      }
    }

    fwrite(file, bmp, bmp_size);
    fclose(file);

    mfree(hdr);
    mfree(bmp);
    return 1;
  }
  return 0;
}

void screenshot(int width, int height, int mode)
{
  int _SYNC = 0;
  int *SYNC = &_SYNC;
  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);

  wchar_t *bmp_name = wstr_alloc(MAX_NAME_LEN);
  wchar_t *png_name = wstr_alloc(MAX_NAME_LEN);
  wchar_t *ss_path = wstr_alloc(MAX_NAME_LEN);
  snwprintf(ss_path, MAX_NAME_LEN, L"/usb/picture/snapshots/%02d-%02d-%02d", dt.date.day, dt.date.mon, dt.date.year);

  char *bookname = MainDisplay_GetTopBook()->xbook->name;

  uint8_t *display_buffer = (uint8_t *)malloc(BUFFER_SIZE(width, height));
  TDisplayManagerInfo *display_info = (TDisplayManagerInfo *)malloc(sizeof(TDisplayManagerInfo));

  int res = get_display_data(display_info, display_buffer);
  if (res)
  {
    if (mode == SAVE_BMP)
    {
      snwprintf(bmp_name, MAX_NAME_LEN, L"ss-%s-%02d-%02d-%02d.bmp", bookname, dt.time.hour, dt.time.min, dt.time.sec);
      res = save_as_bmp(ss_path, bmp_name, width, height, display_buffer);
    }
    else
    {
      snwprintf(png_name, MAX_NAME_LEN, L"ss-%s-%02d-%02d-%02d.png", bookname, dt.time.hour, dt.time.min, dt.time.sec);
      res = save_as_png(ss_path, png_name, bookname, width, height, display_buffer, display_info);
    }
  }

  if (res)
    play_system_sound(AUDIOCONTROL_NOTIFICATION_SUCCESS);
  else
    play_system_sound(AUDIOCONTROL_NOTIFICATION_FAILURE);

  mfree(bmp_name);
  mfree(png_name);
  mfree(ss_path);
  mfree(display_info);
  mfree(display_buffer);
}

extern "C" void patch_keyhandler(int key, int r1, int action)
{
  // debug_printf("\nKey %s (%d) R1: %d Action: %s (%d)", keyhandler_get_key(key), key, r1, keyhandler_get_action(action), action);

  BOOK *audio_player = FindBook(IsAudioPlayerBook);
  int width = 240;
  int height = 320;

  if ((key == KEY_PREVTRACK || key == KEY_NEXTTRACK) && action == KBD_SHORT_PRESS)
  {
    if (!isKeylocked() && !audio_player)
    {
      if (key == KEY_PREVTRACK)
        screenshot(width, height, SAVE_BMP);
      else if (key == KEY_NEXTTRACK)
        screenshot(width, height, SAVE_PNG);
    }
  }
  else if (key == KEY_CAMERA_FOCUS && action == KBD_SHORT_PRESS)
  {
    if (audio_player)
      screenshot(width, height, SAVE_PNG);
    else
      keyhandler_action(key, r1, action);
  }
  else
  {
    keyhandler_action(key, r1, action);
  }
}
