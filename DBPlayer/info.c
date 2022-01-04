#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#ifndef DB3150v1
#include "dll.h"
#endif

#include "Lib.h"
#include "main.h"
#include "data.h"
#include "info.h"

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
wchar_t *GetCoverType(uint8_t cover_type)
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

IMAGEID MetaData_GetCover(wchar_t *path, wchar_t *name)
{
    IMAGEID ret = NOIMAGE;
    IMAGEID imageID;
    METADATA_DESC *MetaData_Desc = (METADATA_DESC *)dll_MetaData_Desc_Create(path, name);

    char cover_type;
    int size;
    int cover_offset;
    if (dll_MetaData_Desc_GetCoverInfo(MetaData_Desc, &cover_type, &size, &cover_offset))
    {
        DBP_DATA *data = GetData();
        int file;
        if ((file = w_fopen(data->file.fullpath, WA_Read, 0x1FF, 0)))
        {
            if (w_lseek(file, cover_offset, WSEEK_SET))
            {
                char *buf = (char *)malloc(size);
                w_fread(file, buf, size);
                ImageID_GetIndirect(buf, size, NULL, GetCoverType(cover_type), &imageID);
                data->CoverSize = size;
                ret = imageID;
            }
            w_fclose(file);
        }
    }
    dll_MetaData_Desc_Destroy(MetaData_Desc);
    return ret;
}
#endif

IMAGEID GetCoverArt(DBP_DATA *Data)
{
    IMAGEID image_id;
#ifdef DB3150v1
    image_id = MetaData_GetCover(Data->file.fullpath);
#else
    image_id = MetaData_GetCover(Data->file.path, Data->file.name);
#endif
    if (image_id == NOIMAGE)
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

TEXTID GetTags(wchar_t *path, wchar_t *name, int tag_id)
{
    TEXTID text_id = EMPTY_TEXTID;
    wchar_t *tag = MetaData_GetTags(path, name, tag_id);
    if (tag)
    {
        text_id = TextID_Create(tag, ENC_UCS2, TEXTID_ANY_LEN);
        mfree(tag);
    }
    else if (tag_id == TMetadataTagId_Title)
    {
        return TextID_Create(name, ENC_UCS2, wstrlen(name) - 4);
    }
    else if (tag_id == TMetadataTagId_Artist || tag_id == TMetadataTagId_Album)
    {
        return TEXT_UNKNOWN;
    }
    return text_id;
}

wchar_t *GetFormatType(DBP_DATA *data)
{
    switch (data->fileFormatType)
    {
    case TMMEFileFormatIdType_AAC:
        return L"AAC";
    case TMMEFileFormatIdType_AMR:
        return L"AMR";
    case TMMEFileFormatIdType_M4A:
        return L"M4A";
    case TMMEFileFormatIdType_MP3:
        return L"MP3";
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
    int min = (data->track_time.Hours * 60 + data->track_time.Minutes) - data->elapsed_time.Minutes;
    int sec;
    int temp = data->track_time.Seconds - data->elapsed_time.Seconds;
    if (temp >= 0)
        sec = temp;
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

    size = sizeloc = 0;
    for (synchsafe = 31; synchsafe >= 0; synchsafe--)
    {
        if (GETBIT(tagSize, synchsafe))
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
    int tag_size = NULL;
    int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IWRITE | FSX_S_IREAD, NULL);
    char buf[10 + 1];
    fread(file, buf, 10);
    if (buf[0] == 'I' && buf[1] == 'D' && buf[2] == '3')
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

TEXTID GetBitrate(DBP_DATA *data)
{
    int tag_size = get_tag_size(data->file.path, data->file.path);

    int cover = NULL;
    if (data->IsCoverArt)
        cover = data->CoverSize;
    FSTAT stat;
    fstat(data->file.path, data->file.name, &stat);
    int bitrate = (stat.fsize - cover - tag_size) / 1000 * 8 / data->full_track_time;
    snwprintf(data->buf, MAXELEMS(data->buf), L"%d kb/s", bitrate);
    return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetSampleRate(DBP_DATA *data)
{
    snwprintf(data->buf, MAXELEMS(data->buf), L"%d KHz", data->SampleRate / 1000);
    return TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
}

TEXTID GetAudioOutput(DBP_DATA *data)
{
    switch (data->AudioOutput)
    {
    case TMMEAudioOutput_Mono:
        return TextID_Create(L"Mono", ENC_UCS2, TEXTID_ANY_LEN);
    case TMMEAudioOutput_Stereo:
        return TextID_Create(L"Stereo", ENC_UCS2, TEXTID_ANY_LEN);
    default:
        return TEXT_UNKNOWN;
    }
}
