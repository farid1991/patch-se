#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#include "dll.h"

#include "Lib.h"
#include "main.h"
#include "data.h"
#include "info.h"

wchar_t *GetCoverType(char cover_type)
{
  if (cover_type <= 3)
  {
    switch (cover_type)
    {
    case 0:
      return L"jpg";
    case 1:
      return L"gif";
    case 2:
      return L"png";
    case 3:
      return L"bmp";
    }
    return 0;
  }
  return 0;
}

IMAGEID MetaData_GetCover(DBP_DATA *Data)
{
  IMAGEID imageID = NOIMAGE;
  METADATA_DESC *MetaData_Desc = dll_MetaData_Desc_Create(Data->path, Data->name);

  char cover_type;
  int size;
  int cover_offset;
  if (dll_MetaData_Desc_GetCoverInfo(MetaData_Desc, &cover_type, &size, &cover_offset))
  {
    int file = _fopen(Data->path, Data->name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (file >= NULL)
    {
      if (lseek(file, cover_offset, SEEK_SET))
      {
        char *buf = (char *)malloc(size);
        fread(file, buf, size);
        ImageID_GetIndirect(buf, size, NULL, GetCoverType(cover_type), &imageID);
        Data->CoverSize = size;
      }
      fclose(file);
    }
  }
  dll_MetaData_Desc_Destroy(MetaData_Desc);
  return imageID;
}

IMAGEID GetCoverArt(DBP_DATA *Data)
{
  IMAGEID image_id = MetaData_GetCover(Data);
  if (image_id == NOIMAGE)
  {
    Data->HasCoverArt = FALSE;
    image_id = Data->Image[IMG_NO_COVER].ID;
  }
  else
  {
    Data->HasCoverArt = TRUE;
  }
  return image_id;
}

TEXTID GetTags(wchar_t *path, wchar_t *name, int tag_id)
{
  TEXTID text_id;
  wchar_t *tag = MetaData_GetTags(path, name, tag_id);
  if (tag)
  {
    text_id = TextID_Create(tag, ENC_UCS2, TEXTID_ANY_LEN);
    mfree(tag);
    return text_id;
  }
  else if (tag_id == TMetadataTagId_Title)
  {
    return TextID_Create(name, ENC_UCS2, wstrlen(name) - 4);
  }
  else if (tag_id == TMetadataTagId_Artist || tag_id == TMetadataTagId_Album)
  {
    return TEXT_UNKNOWN;
  }
  return EMPTY_TEXTID;
}

wchar_t *GetFormatType(DBP_DATA *data)
{
  switch (data->fileFormatType)
  {
  case TMMEFileFormatIdType_3GP:
    return L"3GP";
  case TMMEFileFormatIdType_AAC:
    return L"AAC";
  case TMMEFileFormatIdType_AMR:
    return L"AMR";
  case TMMEFileFormatIdType_M4A:
    return L"M4A";
  case TMMEFileFormatIdType_MP3:
    return L"MP3";
  case TMMEFileFormatIdType_MP4:
    return L"MP4";
  case TMMEFileFormatIdType_WAV:
    return L"WAV";
  case TMMEFileFormatIdType_WMA:
    return L"WMA";
  default:
    return L"UNK";
  }
}

TEXTID GetFileExt(DBP_DATA *data)
{
  return TextID_Create(GetFormatType(data), ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetTotalTime(DBP_DATA *data)
{
  snwprintf(data->buf, MAXELEMS(data->buf), L"%02d:%02d", data->track_time.Hours * 60 + data->track_time.Minutes, data->track_time.Seconds);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetElapsedTime(DBP_DATA *data)
{
  snwprintf(data->buf, MAXELEMS(data->buf), L"%02d:%02d", data->elapsed_time.Hours * 60 + data->elapsed_time.Minutes, data->elapsed_time.Seconds);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetRemainingTime(DBP_DATA *data)
{
  int totalMinutes = data->track_time.Hours * 60 + data->track_time.Minutes;
  int remainingMinutes = totalMinutes - data->elapsed_time.Minutes;
  int remainingSeconds = data->track_time.Seconds - data->elapsed_time.Seconds;

  if (remainingSeconds < 0)
  {
    remainingMinutes--;
    remainingSeconds += 60;
  }

  snwprintf(data->buf, MAXELEMS(data->buf), L"-%02d:%02d", remainingMinutes, remainingSeconds);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

int synchsafeToNormal(uint8_t header[HEADER_SIZE])
{
  int synchsafe, sizeloc, size, power, x;

  size = sizeloc = 0;
  for (synchsafe = 31; synchsafe >= 0; synchsafe--)
  {
    if (GETBIT(header, synchsafe))
    {
      power = 1;
      for (x = 0; x < sizeloc; x++)
        power *= 2;
      size += power;
    }
    if (SHIFT(synchsafe))
      sizeloc++;
  }
  return size;
}

int get_tag_size(wchar_t *path, wchar_t *name)
{
  int ret = 0;
  int file = _fopen(path, name, FSX_O_RDONLY, (FSX_S_IWRITE | FSX_S_IREAD), NULL);
  if (file >= 0)
  {
    uint8_t buf[10];
    fread(file, buf, 10);
    if (buf[0] == 'I' && buf[1] == 'D' && buf[2] == '3')
    {
      uint8_t header[HEADER_SIZE];
      header[0] = buf[6];
      header[1] = buf[7];
      header[2] = buf[8];
      header[3] = buf[9];
      ret = synchsafeToNormal(header);
    }
    fclose(file);
  }
  return ret;
}

TEXTID GetBitrate(DBP_DATA *data)
{
  int id3size = get_tag_size(data->path, data->name);
  FSTAT stat;
  fstat(data->path, data->name, &stat);
  int size_in_kb = (stat.fsize - id3size - data->CoverSize) / 1000;
  int bitrate = (size_in_kb * 8) / data->full_track_time;

  snwprintf(data->buf, MAXELEMS(data->buf), L"%d Kbps", bitrate);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

wchar_t *getSampleRate(int index)
{
  switch (index)
  {
  case 8000:
    return L"8.0 KHz";
  case 11025:
    return L"11.02 KHz";
  case 16000:
    return L"16.0 KHz";
  case 22050:
    return L"22.05 KHz";
  case 24000:
    return L"24.0 KHz";
  case 32000:
    return L"32.0 KHz";
  case 44100:
    return L"44.1 KHz";
  case 48000:
    return L"48.0 KHz";
  }
  return NULL;
}

TEXTID GetSampleRate(DBP_DATA *data)
{
  return TextID_Create(getSampleRate(data->SampleRate), ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetAudioOutput(DBP_DATA *data)
{
  switch (data->AudioOutput)
  {
  case TMMEAudioOutput_Mono:
    return STR("Mono");
  case TMMEAudioOutput_Stereo:
    return STR("Stereo");
  default:
    return TEXT_UNKNOWN;
  }
}
