#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "id3v2.h"

uint32_t id3_header_get_tag_size(uint8_t *data, int byte_count)
{
  uint32_t normal_size = 0;

  for (int i = 0; i < byte_count; i++)
  {
    normal_size = (normal_size << 7) | (data[i] & 0x7F);
  }

  return normal_size;
}

uint32_t id3_frame_get_size(uint8_t *data, uint32_t fpos, int version)
{
  uint32_t res = 0;
  if (version == ID3V2_4)
  {
    // ID3v2.4 uses synchsafe integers (4 bytes)
    for (int i = 0; i < 4; i++)
    {
      res = (res << 7) | (data[i + fpos] & 0x7F);
    }
  }
  else if (version == ID3V2_3)
  {
    // ID3v2.3 uses normal 4-byte integers
    for (int i = 0; i < 4; i++)
    {
      res = (res << 8) | data[i + fpos];
    }
  }
  else if (version == ID3V2_2)
  {
    // ID3v2.2 uses 3-byte integers
    for (int i = 0; i < 3; i++)
    {
      res = (res << 8) | data[i + fpos];
    }
  }
  return res;
}

static int get_frame_sync(uint32_t header)
{
  return (header >> 21);
}

static int get_bitrate_index(uint32_t header)
{
  return (header >> 12) & 15;
}

static int get_frequency_index(uint32_t header)
{
  return (header >> 10) & 3;
}

static int get_layer(uint32_t header)
{
  return (header >> 17) & 3;
}

static int get_mode_index(uint32_t header)
{
  return (header >> 6) & 3;
}

static int get_version_id(uint32_t header)
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

uint32_t get_header(uint8_t *data)
{
  return ((data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]);
}

int get_bitrate(uint32_t header)
{
  int version_id = get_version_id(header);       // MPEG version ID
  int layer = get_layer(header);                 // Layer description
  int bitrate_index = get_bitrate_index(header); // Bitrate index
  int version_index = (version_id == 3) ? 1 : 0; // MPEG-1 is index 1, MPEG-2/2.5 is index 0

  return 2 * bitrate_table[version_index][layer - 1][bitrate_index];
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

uint32_t id3v2_read_header(const wchar_t *path, const wchar_t *name, uint32_t *tagsize, uint32_t *version, uint32_t *fpos)
{
  int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file < 0)
  {
    return 0;
  }

  uint8_t header_buf[ID3_HEADER_SIZE];
  fread(file, header_buf, ID3_HEADER_SIZE);

  *fpos = 0;
  if (!memcmp(header_buf, "ID3", ID3_HEADER_ID_LENGTH))
  {
    *version = header_buf[3];
    uint8_t flags = header_buf[5];

    if (*version == ID3V2_2)
    {
      uint8_t temp_data[ID3V2_2_BYTE] = {header_buf[6], header_buf[7], header_buf[8]};
      *tagsize = id3_header_get_tag_size(temp_data, ID3V2_2_BYTE);

      *fpos = ID3_HEADER_SIZE;
    }
    else if (*version == ID3V2_3 || *version == ID3V2_4)
    {
      uint8_t temp_data[ID3V2_X_BYTE] = {header_buf[6], header_buf[7], header_buf[8], header_buf[9]};
      *tagsize = id3_header_get_tag_size(temp_data, ID3V2_X_BYTE);

      *fpos = ID3_HEADER_SIZE;
      if (flags & 0x40)
        *fpos += ID3_EXTENDED_HEADER_FLAGS + ID3_EXTENDED_HEADER_SIZE + ID3_EXTENDED_HEADER_PADDING_SIZE;
    }
    else
    {
      fclose(file);
      return 0;
    }

    lseek(file, *tagsize + ID3_HEADER_SIZE, SEEK_SET);
  }
  else
  {
    fclose(file);
    return 0;
  }

  uint8_t mp3_frame_header[ID3_FRAME_SIZE];
  fread(file, mp3_frame_header, ID3_FRAME_SIZE);
  fclose(file);

  uint32_t header = get_header(mp3_frame_header);
  if (is_valid_id3_header(header))
    return header;
  return 0;
}
