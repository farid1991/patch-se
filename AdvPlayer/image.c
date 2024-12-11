#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "data.h"
#include "image.h"
#include "skin_data.h"

void image_register(IMAGE_DESC *img_desc, wchar_t *path, wchar_t *fname)
{
  char error;
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  img_desc->id = NOIMAGE;
  img_desc->handle = NOIMAGE;
  img_desc->exist = true;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img_desc->handle, &error))
  {
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img_desc->handle, path, fname, 0, &img_desc->id, &error))
    {
      if (error)
      {
        img_desc->handle = NOIMAGE;
        img_desc->exist = false;
      }
    }
  }
}

void image_unregister(IMAGE_DESC *img_desc)
{
  if (img_desc->id != NOIMAGE && img_desc->exist)
  {
    char error;
    int _SYNC = NULL;
    int *SYNC = &_SYNC;
    REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, img_desc->handle, NULL, NULL, img_desc->id, 1, &error);
    img_desc->id = NOIMAGE;
    img_desc->handle = NOIMAGE;
    img_desc->exist = false;
  }
}
