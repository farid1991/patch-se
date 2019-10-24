#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "data.h"
#include "info.h"

IMAGEID GetCoverArt(DBP_DATA* Data)
{
  IMAGEID image_id;
  
  image_id = MetaData_GetCover(Data->file.fullpath);
  if(image_id==NOIMAGE)
  {
    Data->IsCoverArt = FALSE;
    image_id = Data->Image[1].ID;
  }
  else
  {
    Data->IsCoverArt = TRUE;
  }
  return image_id;
}

TEXTID GetTags(wchar_t* path, wchar_t* name, int tag_id)
{
  TEXTID text_id = EMPTY_TEXTID;
  wchar_t* tag = MetaData_GetTags(path, name, tag_id);
  if (tag)
  {
    text_id = TextID_Create(tag, ENC_UCS2, TEXTID_ANY_LEN);
    mfree(tag);
  }
  else if (tag_id == TMetadataTagId_Title)
  {
    return TextID_Create(name, ENC_UCS2, wstrlen(name)-4);
  }
  else if (tag_id == TMetadataTagId_Artist || tag_id == TMetadataTagId_Album)
  {
    return TEXT_UNKNOWN;
  }
  return text_id;
}

TEXTID GetFileExt(wchar_t* name)
{
  wchar_t* ext = getFileExtention(name);
  int len = wstrlen(ext);
  wstrnupr( ext, len );
  return TextID_Create(ext, ENC_UCS2, len);
}

TEXTID GetTotalTime(DBP_DATA* data)
{
  snwprintf(data->buf, MAXELEMS(data->buf), L"%02d:%02d", data->track_time.Hours * 60 + data->track_time.Minutes, data->track_time.Seconds);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetElapsedTime(DBP_DATA* data)
{
  snwprintf(data->buf, MAXELEMS(data->buf), L"%02d:%02d", data->elapsed_time.Hours * 60 + data->elapsed_time.Minutes, data->elapsed_time.Seconds);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetRemainingTime(DBP_DATA* data)
{
  int min = (data->track_time.Hours * 60 + data->track_time.Minutes) - data->elapsed_time.Minutes;
  int sec;
  int temp = data->track_time.Seconds - data->elapsed_time.Seconds;
  if (temp >= 0) sec = temp;
  else
  {
    min -= 1;
    sec = 60 + temp;
  }
  
  snwprintf(data->buf, MAXELEMS(data->buf), L"-%02d:%02d", min, sec);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

int synchsafeToNormal(char tagSize[4])
{
  int synchsafe, sizeloc, size, power, x;
  
  size = sizeloc=0;
  for (synchsafe = 31; synchsafe >= 0; synchsafe--)
  {
    if (GETBIT(tagSize, synchsafe))
    {
      power = 1;
      for(x = 0; x < sizeloc; x++) power *= 2;
      size += power;
    }
    if (SHIFT(synchsafe)) sizeloc++;
  }
  return size;
}

int get_tag_size(wchar_t* path, wchar_t* name)
{
  int tag_size = NULL;
  int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IWRITE|FSX_S_IREAD, NULL);
  char buf[10 + 1];
  fread(file, buf, 10);
  if (buf[0]=='I' && buf[1]=='D' && buf[2]=='3')
  {
    char tagSize[4];
    tagSize[0] = buf[6];
    tagSize[1] = buf[7];
    tagSize[2] = buf[8];
    tagSize[3] = buf[9];
    tag_size = synchsafeToNormal(tagSize);
  }
  fclose(file); 
  return tag_size;
}

TEXTID GetBitrate(DBP_DATA* data)
{
  int tag_size = get_tag_size(data->file.path, data->file.path);
  
  FSTAT stat;
  fstat(data->file.path, data->file.name, &stat);
  int bitrate = (stat.fsize - tag_size) / 1000 * 8 / data->full_track_time;
  snwprintf(data->buf, MAXELEMS(data->buf), L"%d kb/s", bitrate);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetSampleRate(DBP_DATA* data)
{
  snwprintf(data->buf, MAXELEMS(data->buf), L"%d KHz", data->SampleRate/1000);
  return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetAudioOutput(DBP_DATA* data)
{
  wchar_t* out;
  if (data->AudioOutput == TMMEAudioOutput_Mono) out = L"Mono";
  else if (data->AudioOutput == TMMEAudioOutput_Stereo) out = L"Stereo";
  else if (data->AudioOutput == TMMEAudioOutput_Unknown) return TEXT_UNKNOWN;
  return TextID_Create(out, ENC_UCS2, TEXTID_ANY_LEN);
}
