#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "id3v2.h"
#include "main.h"

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(NULL, size, 1, 5, "mp3info", NULL);
#elif defined(A2)
  return memalloc(-1, size, 1, 5, "mp3info", NULL);
#else
  return memalloc(size, 1, 5, "mp3info", NULL);
#endif
}

void mfree(void *mem)
{
  if (mem)
#if defined(DB2020) || defined(A2)
    memfree(NULL, mem, "mp3info", NULL);
#else
    memfree(mem, "mp3info", NULL);
#endif
}

extern "C" TEXTID patch_brw_mp3info(TEXTID text_id, SUB_EXECUTE *sub_exec)
{
  wchar_t *path = FILEITEM_GetPath(sub_exec->file_item);
  wchar_t *name = FILEITEM_GetFname(sub_exec->file_item);

  uint32_t version;
  uint32_t fpos;
  uint32_t tagsize;
  uint32_t header = id3v2_read_header(path, name, &tagsize, &version, &fpos);
  if (!header || !tagsize)
  {
    return text_id;
  }

  char *mp3_info = (char *)malloc(MAX_INFO_SIZE);
  if (!mp3_info)
  {
    return text_id;
  }

  snprintf(mp3_info, MAX_INFO_SIZE,
           "\nid3v2.%d\n"
           "Bitrate: %dkbps\n"
           "Frequency: %dKHz\n"
           "Mode: %s",
           version,
           get_bitrate(header),
           get_frequency(header),
           get_mode(header));

  TEXTID new_textid[2];
  new_textid[0] = text_id;
  new_textid[1] = TextID_Create(mp3_info, ENC_LAT1, MAX_INFO_SIZE);

  mfree(mp3_info);
  return TextID_Create(new_textid, ENC_TEXTID, 2);
}
