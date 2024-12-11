#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "data.h"
#include "id3_parser.h"
#include "image.h"
#include "main.h"
#include "str_lib.h"

inline int get_frame_sync(uint32_t header)
{
  return (header >> 21);
}

inline int get_bitrate_index(uint32_t header)
{
  return (header >> 12) & 15;
}

inline int get_frequency_index(uint32_t header)
{
  return (header >> 10) & 3;
}

inline int get_layer(uint32_t header)
{
  return (header >> 17) & 3;
}

inline int get_mode_index(uint32_t header)
{
  return (header >> 6) & 3;
}

inline int get_version_id(uint32_t header)
{
  return (header >> 19) & 3;
}

BOOL is_valid_id3_header(uint32_t header)
{
  return get_frame_sync(header) == 0x7FF && // Frame sync (first 11 bits must be 0x7FF)
         get_version_id(header) != 1 &&     // Version ID cannot be reserved (1)
         get_layer(header) != 0 &&          // Layer cannot be 0 (invalid layer)
         get_bitrate_index(header) != 15 && // Bitrate index cannot be 15 (invalid bitrate)
         get_frequency_index(header) != 3;  // Frequency index cannot be 3 (invalid frequency)
}

uint32_t get_header(uint8_t *mp3_data)
{
  return ((mp3_data[0] << 24) | (mp3_data[1] << 16) | (mp3_data[2] << 8) | mp3_data[3]);
}

int get_bitrate(uint32_t header)
{
  int version_id = get_version_id(header);       // MPEG version ID
  int layer = get_layer(header);                 // Layer description
  int bitrate_index = get_bitrate_index(header); // Bitrate index
  int version_index = (version_id == 3) ? 1 : 0; // MPEG-1 is index 1, MPEG-2/2.5 is index 0

  return BITRATE_SCALE * bitrate_table[version_index][layer - 1][bitrate_index];
}

int get_frequency(uint32_t header)
{
  int version_id = get_version_id(header);           // MPEG version ID
  int frequency_index = get_frequency_index(header); // Frequency index
  int version_index = (version_id == 3) ? 3 : (version_id == 2) ? 2
                                                                : 0;
  return frequency_table[version_index][frequency_index];
}

const char *get_mode(uint32_t header)
{
  const char *mode[4] = {"Stereo", "Joint Stereo", "Dual Channel", "Single Channel"};
  return mode[get_mode_index(header)];
}

uint32_t int_decode(uint8_t *bytes, int size, int offset)
{
  uint32_t result = 0x00;
  int i = 0;
  for (i = 0; i < size; i++)
  {
    result = result << 8;
    result = result | (uint8_t)bytes[offset + i];
  }

  return result;
}

uint32_t synch_decode(uint32_t value)
{
  uint32_t a, b, c, d, result = 0x0;
  a = (value >> 0) & 0xFF;
  b = (value >> 8) & 0xFF;
  c = (value >> 16) & 0xFF;
  d = (value >> 24) & 0xFF;

  result = result | (a << 0);
  result = result | (b << 7);
  result = result | (c << 14);
  result = result | (d << 21);

  return result;
}

uint32_t id3v2_get_header(wchar_t *path, wchar_t *name)
{
  int mp3_f = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (mp3_f >= 0)
  {
    uint8_t header_buf[ID3V2_HEADER_SIZE];
    fread(mp3_f, header_buf, ID3V2_HEADER_SIZE);

    if (memcmp(header_buf, "ID3", ID3V2_HEADER_ID_LENGTH) != 0)
    {
      fclose(mp3_f);
      return 0;
    }

    uint8_t version = header_buf[3];
    if (version == ID3V2_3 || version == ID3V2_4)
    {
      uint32_t tag_size = synch_decode(int_decode(header_buf, 4, 6));

      lseek(mp3_f, tag_size + ID3V2_HEADER_SIZE, SEEK_SET);

      uint8_t frame_header[ID3V2_FRAME_SIZE];
      fread(mp3_f, frame_header, ID3V2_FRAME_SIZE);
      fclose(mp3_f);

      uint32_t header = get_header(frame_header);
      if (is_valid_id3_header(header))
        return header;
    }
  }
  return NULL;
}

uint8_t *id3v2_tag_get(wchar_t *path, wchar_t *name, int *tag_size, int *version)
{
  int mp3_f = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (mp3_f >= 0)
  {
    uint8_t header[ID3V2_HEADER_SIZE];
    fread(mp3_f, header, ID3V2_HEADER_SIZE);

    if (memcmp(header, "ID3", ID3V2_HEADER_ID_LENGTH) == 0)
    {
      *version = header[3];
      if (*version == ID3V2_3 || *version == ID3V2_4)
      {
        *tag_size = synch_decode(int_decode(header, 4, 6));

        uint8_t *tag_buffer = (uint8_t *)malloc(*tag_size);
        fread(mp3_f, tag_buffer, *tag_size);
        fclose(mp3_f);

        return tag_buffer;
      }
    }
    fclose(mp3_f);
  }
  return NULL;
}

uint8_t *id3v2_apic_frame_get(wchar_t *path, wchar_t *name, wchar_t *cover_type, int *cover_size)
{
  int tag_size, version;
  uint8_t *tag_buffer = id3v2_tag_get(path, name, &tag_size, &version);
  if (!tag_buffer)
  {
    return NULL;
  }

  int cur_pos = 0;
  bool has_cover_art = false;
  while (cur_pos < (tag_size - 4))
  {
    if (tag_buffer[cur_pos + 0] == 'A' &&
        tag_buffer[cur_pos + 1] == 'P' &&
        tag_buffer[cur_pos + 2] == 'I' &&
        tag_buffer[cur_pos + 3] == 'C')
    {
      has_cover_art = true;
      break;
    }
    cur_pos++;
  }
  cur_pos += ID3V2_FRAME_ID_SIZE;

  if (!has_cover_art)
  {
    mfree(tag_buffer);
    return NULL;
  }

  int frame_size = int_decode(tag_buffer, 4, cur_pos);
  if (version == ID3V2_4)
  {
    frame_size = synch_decode(frame_size);
  }
  cur_pos += ID3V2_FRAME_SIZE;

  // skip flag
  cur_pos += ID3V2_FRAME_FLAGS_SIZE;

  // get mime type
  int mime_len = 0;
  while (tag_buffer[(cur_pos + mime_len)] != '\0')
  {
    mime_len++;
  }
  char mime[11] = {0};
  memcpy(mime, tag_buffer + cur_pos, mime_len);
  cur_pos += mime_len;

  // convert mime type to cover type
  if (strcmp(MIMETYPE_BMP, mime) == 0)
  {
    wstrcpy(cover_type, L"bmp");
  }
  else if (strcmp(MIMETYPE_GIF, mime) == 0)
  {
    wstrcpy(cover_type, L"gif");
  }
  else if ((strcmp(MIMETYPE_JPG, mime) == 0) || (strcmp(MIMETYPE_JPEG, mime) == 0))
  {
    wstrcpy(cover_type, L"jpg");
  }
  else if (strcmp(MIMETYPE_PNG, mime) == 0)
  {
    wstrcpy(cover_type, L"png");
  }

  // skip picture type
  cur_pos++;

  // skip description
  int offset = 0;
  while (tag_buffer[(cur_pos + offset)] != '\0')
  {
    offset++;
  }
  // description should be at least 1 byte (null terminator)
  if (offset == 0)
  {
    offset++;
  }
  cur_pos += offset;

  // remove any 0x00 bytes before image
  while (tag_buffer[cur_pos] == 0x00)
  {
    cur_pos++;
  }

  *cover_size = frame_size - mime_len - offset;

  uint8_t *cover_art = (uint8_t *)malloc(*cover_size);
  memcpy(cover_art, tag_buffer + cur_pos, *cover_size);
  mfree(tag_buffer);

  return cover_art;
}

bool id3v2_extract_coverart(PLAYLIST_ITEM *item)
{
  wchar_t cover_type[4] = {0};
  int cover_size;
  uint8_t *cover_art = id3v2_apic_frame_get(item->fpath, item->fname, cover_type, &cover_size);

  wchar_t cover_name[128];
  snwprintf(cover_name, sizeof(cover_name), L"%ls_%ls.coverart.%ls", item->artist, item->album, cover_type);

  if (FSX_IsFileExists(item->fpath, cover_name))
  {
    FileDelete(item->fpath, cover_name, NULL);
  }

  if (cover_art)
  {
    int out_f = _fopen(item->fpath, cover_name, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (out_f >= 0)
    {
      fwrite(out_f, cover_art, cover_size);
      fclose(out_f);
    }

    IMAGEID image_id;
    ImageID_GetIndirect(cover_art, cover_size, 0, cover_type, &image_id);

    MessageBox(EMPTY_TEXTID, TextID_Create("Saved", ENC_LAT1, TEXTID_ANY_LEN), image_id, 0, 0, NULL);

    ImageID_Free(image_id);
    return true;
  }
  MessageBox(EMPTY_TEXTID, TextID_Create("Failed", ENC_LAT1, TEXTID_ANY_LEN), NOIMAGE, 0, 0, NULL);
  return false;
}

bool id3v2_get_coverart(TRACK_DESC *track)
{
  ADVPLAYER_DATA *data = env_data_get();

  wchar_t cover_type[4] = {0};
  int cover_size;
  uint8_t *cover_art = id3v2_apic_frame_get(track->fpath, track->fname, cover_type, &cover_size);

  if (cover_art)
  {
    IMAGEID image_id;
    if (ImageID_GetIndirect(cover_art, cover_size, 0, cover_type, &image_id) == 0)
    {
      data->cover_image.id = image_id;
      data->cover_image.exist = true;
      data->cover_image.handle = 0;
      data->has_coverart = true;
      return true;
    }
  }
  return false;
}
