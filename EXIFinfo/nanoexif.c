/*
The MIT License

Copyright (c) 2010 Tokuhiro Matsuno

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/**
 * @file nanoexif.c
 */

/**
 * \defgroup nanoexif
 */
/**
 * @{
 */

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "nanoexif.h"

static inline uint32_t read_32(nanoexif_endian endian, const uint8_t *buf)
{
  if (endian == NANOEXIF_LITTLE_ENDIAN)
  {
    return (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
  }
  else
  {
    return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
  }
}

static inline uint16_t read_16(nanoexif_endian endian, const uint8_t *buf)
{
  if (endian == NANOEXIF_LITTLE_ENDIAN)
  {
    return (buf[1] << 8) | buf[0];
  }
  else
  {
    return (buf[0] << 8) | buf[1];
  }
}

static inline uint16_t swap_endian_16(uint16_t i)
{
  return ((i & 0xff) << 8) | ((i & 0xff00) >> 8);
}
static inline uint32_t swap_endian_32(uint32_t i)
{
  return ((i & 0x000000ff) << 24) | ((i & 0x0000ff00) << 8) | ((i & 0x00ff0000) >> 8) | ((i & 0xff000000) >> 24);
}

static inline nanoexif *parse_app1(int fd, size_t app1_len, uint32_t *ifd_offset)
{
  if (app1_len < 6)
  {
    return NULL;
  }

  // check exif header
  {
    uint8_t exif_header[6];
    if (fread(fd, exif_header, 6) != 6)
    {
      DBG("CANNOT read exif header\n");
      return NULL;
    }
    const char *EXIF_HEADER = "\x45\x78\x69\x66\x00\x00";
    if (memcmp(exif_header, EXIF_HEADER, 6) != 0)
    {
      DBG("EXIFHEADER\n");
      return NULL;
    }
  }

  uint8_t *buf = (uint8_t *)malloc(app1_len - 6);
  if (!buf)
  {
    return NULL;
  }

  if (fread(fd, buf, app1_len - 6) != app1_len - 6)
  {
    DBG("\nCANNOT read app1 header\n");
    mfree(buf);
    return NULL;
  }

  nanoexif_endian endian;
  if (memcmp(buf, "\x4d\x4d", 2) == 0)
  {
    DBG("\nBIG ENDIAN\n");
    endian = NANOEXIF_BIG_ENDIAN;
  }
  else
  { // 4949
    DBG("\nLITTLE ENDIAN\n");
    endian = NANOEXIF_LITTLE_ENDIAN;
  }

  uint16_t tag_mark = read_16(endian, buf + 2);
  if (tag_mark == 0x2A00)
  {
    DBG("\ntiff header fail\n");
    mfree(buf);
    return NULL; // tiff
  }
  *ifd_offset = read_32(endian, buf + 4);

  nanoexif *ne = (nanoexif *)malloc(sizeof(nanoexif));
  if (!ne)
  {
    mfree(buf);
    return NULL;
  }
  ne->endian = endian;
  ne->buf = buf;
  return ne;
}

/** initialize nanoexif struct.
 * @param int fd: file descriptor for reading exif
 * @param uint32_t *ifd_offset: offset bytes for first ifd entry.
 * @return pointer of struct nanoexif if succeeded, return NULL otherwise.
 *
 * You should call nanoexif_free(ne) if return value is not null.
 */
nanoexif *nanoexif_init(int fd, uint32_t *ifd_offset)
{
  char soi[2];
  if (fread(fd, soi, 2) != 2)
  {
    DBG("\ncannot read soi\n");
    return NULL;
  }
  if (soi[0] != '\xff' && soi[1] != '\xd8')
  {
    DBG("\nerr, not soi");
    return NULL;
  }

  /* some jpeg file put APP0 header before APP1 header. Yes, this is invalid. */
  while (1)
  {
    uint8_t marker_len[4];
    if (fread(fd, marker_len, sizeof(marker_len)) != sizeof(marker_len))
    {
      DBG("\ncannot read marker\n");
      return NULL;
    }
    if (marker_len[0] != (uint8_t)'\xFF')
    {
      DBG("\ninvalid marker\n");
      return NULL;
    }

    /* marker length is always big endian */
    uint16_t len = read_16(NANOEXIF_BIG_ENDIAN, marker_len + 2);

    if (marker_len[1] == (uint8_t)'\xE1')
    { // APP1
      DBG("\napp1 header : %d\n", len);
      return parse_app1(fd, len, ifd_offset);
    }
    else if (marker_len[1] == (uint8_t)'\xDA')
    {
      // SOS
      /* reach to image.. hmm. this jpeg doesn't contains exif. */
      return NULL; /* missing exif */
    }
    else
    {
      /* skip this part... */
      if (lseek(fd, len - 2, SEEK_CUR) != 0)
      {
        DBG("\ncannot seek\n");
        return NULL;
      }
    }
  }
  // return NULL; // should not reach here
}

/** destruct the struct nanoexif*.
 * @param nanoeixf * ne: pointer for destructing
 */
void nanoexif_free(nanoexif *ne)
{
  if (ne)
  {
    mfree(ne->buf);
    mfree(ne);
  }
}

/** read ifd entries
 * @param nanoeixf * ne: pointer for struct nanoexif.
 * @param uint16_t offset: offset for the ifd entry
 * @param uint32_t *next_offset: offset for the next ifd entry will be set.
 * @param uint16_t * cnt: count of entries will be set.
 * @return array of nanoeixf_ifd_entry.the number of elements will set to argument 'cnt'.return NULL if error occurred.
 *
 * You should call free(entries), after use it.
 */
nanoexif_ifd_entry *nanoexif_read_ifd(nanoexif *ne, uint16_t offset, uint32_t *next_offset, uint16_t *cnt)
{
  *cnt = read_16(ne->endian, ne->buf + offset);
  nanoexif_ifd_entry *entries = (nanoexif_ifd_entry *)malloc(sizeof(nanoexif_ifd_entry) * (*cnt));
  if (!entries)
  {
    return NULL;
  }
  memcpy(entries, ne->buf + offset + 2, sizeof(nanoexif_ifd_entry) * (*cnt));
  int i;
  for (i = 0; i < *cnt; i++)
  {
    if (NANOEXIF_MACHINE_ENDIAN != ne->endian)
    {
      entries[i].tag = swap_endian_16(entries[i].tag);
      entries[i].type = swap_endian_16(entries[i].type);
      entries[i].count = swap_endian_32(entries[i].count);
    }
  }
  uint32_t next_ifd_offset_pos = offset + 2 + sizeof(nanoexif_ifd_entry) * (*cnt);
  *next_offset = read_32(ne->endian, ne->buf + next_ifd_offset_pos);
  return entries;
}

#define ENTRY_DATA_COPY(x, y, z) memcpy(x, ne->buf + y, z);

/** read short value from ifd entry
 * @param nanoeixf * ne: pointer for struct nanoexif.
 * @param nanoexif_ifd_entry * entry
 * @return array of uint16_t.return NULL if error occurred.
 *
 * You should free(2) the return value, after used.
 */
uint16_t *nanoexif_get_ifd_entry_data_short(nanoexif *ne, nanoexif_ifd_entry *entry)
{
  if (entry->count <= 4 / sizeof(uint16_t))
  {
    uint16_t *ret = (uint16_t *)malloc(sizeof(uint16_t) * entry->count);
    if (!ret)
    {
      return NULL;
    }
    *ret = read_16(ne->endian, entry->offset);
    if (entry->count == 2)
    {
      *(ret + 1) = read_16(ne->endian, entry->offset + 2);
    }
    return ret;
  }
  else
  {
    uint32_t offset = read_32(ne->endian, entry->offset);
    uint16_t *buf = (uint16_t *)malloc(entry->count * sizeof(uint16_t));
    if (!buf)
    {
      return NULL;
    }
    ENTRY_DATA_COPY(buf, offset, sizeof(uint16_t) * entry->count);
    if (NANOEXIF_MACHINE_ENDIAN != ne->endian)
    {
      uint16_t i;
      uint16_t *p = buf;
      for (i = 0; i < entry->count; i++)
      {
        *p = swap_endian_16(*p);
        p++;
      }
    }
    return buf;
  }
}

/** ditto.
 */
uint32_t *nanoexif_get_ifd_entry_data_long(nanoexif *ne, nanoexif_ifd_entry *entry)
{
  if (entry->count <= 4 / sizeof(uint32_t))
  {
    uint32_t *ret = (uint32_t *)malloc(sizeof(uint32_t));
    if (!ret)
    {
      return NULL;
    }
    *ret = read_32(ne->endian, entry->offset);
    return ret;
  }
  else
  {
    uint32_t offset = read_32(ne->endian, entry->offset);
    uint32_t *buf = (uint32_t *)malloc(entry->count * sizeof(uint32_t));
    if (!buf)
    {
      return NULL;
    }
    ENTRY_DATA_COPY(buf, offset, sizeof(uint32_t) * entry->count);
    if (NANOEXIF_MACHINE_ENDIAN != ne->endian)
    {
      uint16_t i;
      uint32_t *p = (uint32_t *)buf;
      for (i = 0; i < entry->count; i++)
      {
        *p = swap_endian_32(*p);
        p++;
      }
    }
    return buf;
  }
}

/** ditto.
 */
char *nanoexif_get_ifd_entry_data_ascii(nanoexif *ne, nanoexif_ifd_entry *entry)
{
  if (entry->count <= 4)
  {
    char *ret = (char *)malloc(sizeof(char) * entry->count);
    if (!ret)
    {
      return NULL;
    }
    memcpy(ret, entry->offset, entry->count);
    return ret;
  }
  else
  {
    uint32_t offset = read_32(ne->endian, entry->offset);
    char *buf = (char *)malloc(entry->count);
    if (!buf)
    {
      return NULL;
    }
    ENTRY_DATA_COPY(buf, offset, entry->count);
    return buf;
  }
}

/** ditto.
 */
uint32_t *nanoexif_get_ifd_entry_data_rational(nanoexif *ne, nanoexif_ifd_entry *entry)
{
  /* rational's minimal size is 8 bytes.cannot put on the offset. */
  uint32_t offset = read_32(ne->endian, entry->offset);
  uint8_t *buf = (uint8_t *)malloc(entry->count * sizeof(uint32_t) * 2);
  if (!buf)
  {
    return NULL;
  }

  ENTRY_DATA_COPY(buf, offset, sizeof(uint32_t) * entry->count * 2);
  if (NANOEXIF_MACHINE_ENDIAN != ne->endian)
  {
    uint16_t i;
    uint32_t *p = (uint32_t *)buf;
    for (i = 0; i < entry->count * 2; i++)
    {
      *p = swap_endian_32(*p);
      p++;
    }
  }
  return (uint32_t *)buf;
}

/**
 * @}
 */

/**

@mainpage

This is nanoexif's programmer's docs.

If you want to know more details, please see http://github.com/tokuhirom/nanoexif

*/
