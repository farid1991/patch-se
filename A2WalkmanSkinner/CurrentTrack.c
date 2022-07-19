#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\classes\classes.h"

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "CurrentTrack.h"
#include "dll.h"
#include "Function.h"
#include "main.h"
#include "String.h"

//==============================================================================

wchar_t *GetFileFormat(wchar_t *fullpath)
{
  wchar_t *extension = WStringAlloc(3);
  char *tmpext = StringAlloc(wstrlen(fullpath));
  wchar_t *wtmpext = WStringAlloc(wstrlen(fullpath));
  wstr2strn(tmpext, fullpath, wstrlen(fullpath));

  extension[0] = tmpext[strlen(tmpext) - 3];
  extension[1] = tmpext[strlen(tmpext) - 2];
  extension[2] = tmpext[strlen(tmpext) - 1];
  StringFree(tmpext);
  WStringFree(wtmpext);

  wstrnupr(extension, wstrlen(extension));
  return extension;
}

wchar_t *MetaData_GetGenre(wchar_t *fullpath)
{
  wchar_t *genre = WStringAlloc(MAX_GENRE_LENGTH);
  wchar_t *path = WStringAlloc(wstrlen(fullpath));
  wstrcpy(path, fullpath);
  wchar_t *fname = wstrrchr(path, '/');
  *fname = NULL;
  genre = MetaData_GetTags(path, fname + 1, TMetadataTagId_Genre);
  WStringFree(path);
  return genre;
}

wchar_t *Get_CoverType(int cover_type)
{
  switch (cover_type)
  {
  case TMusicServer_AlbumArt_ImageType_Jpeg:
    return L"jpg";
  case TMusicServer_AlbumArt_ImageType_Gif:
    return L"gif";
  case TMusicServer_AlbumArt_ImageType_Png:
    return L"png";
  case TMusicServer_AlbumArt_ImageType_Bmp:
    return L"bmp";
  default:
    return NULL;
  }
}

IMAGEID GetCoverArt(wchar_t *fullpath, int size, int offset, char type)
{
  IMAGEID ImageID = NOIMAGE;
  int file = w_fopen(fullpath, WA_Read, (FSX_S_IWRITE | FSX_S_IREAD), NULL);
  if (w_lseek(file, offset, WSEEK_SET))
  {
    char *buffer = (char *)malloc(size);
    w_fread(file, buffer, size);
    ImageID_GetIndirect(buffer, size, NULL, Get_CoverType(type), &ImageID);
  }
  w_fclose(file);
  return ImageID;
}

BOOL MetaData_GetCoverInfo(wchar_t *fullpath, char *cover_type, int *size, int *cover_offset)
{
  int ret;
  METADATA_DESC *MetaData_Desc = (METADATA_DESC *)malloc(sizeof(METADATA_DESC));
  MetaData_Desc->pIMetaData = NULL;
  IShell *pIShell = NULL;
  OSE_GetShell(PPINTERFACE(&pIShell));
  pIShell->CreateInstance(CID_CMetaData, IID_IMetaData, PPINTERFACE(&MetaData_Desc->pIMetaData));

  wchar_t *fpath = WStringAlloc(wstrlen(fullpath));
  wstrcpy(fpath, fullpath);
  wchar_t *fname = wstrrchr(fpath, '/');
  *fname = NULL;
  MetaData_Desc->pIMetaData->SetFile(fpath, fname + 1);
  WStringFree(fpath);

  COVER_INFO_DESC cover_info;
  if (MetaData_Desc->pIMetaData->GetCoverInfo(&cover_info) < 0)
  {
    ret = FALSE;
  }
  else
  {
    *cover_type = cover_info.cover_type;
    *size = cover_info.size;
    *cover_offset = cover_info.cover_offset;
    ret = TRUE;
  }

  if (MetaData_Desc->pIMetaData)
    MetaData_Desc->pIMetaData->Release();
  if (MetaData_Desc)
    mfree(MetaData_Desc);
  if (pIShell)
    pIShell->Release();

  return ret;
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

int get_tag_size(wchar_t *fullpath)
{
  int tag_size = NULL;
  char buf[10 + 1];
  int file = w_fopen(fullpath, WA_Read, (FSX_S_IWRITE | FSX_S_IREAD), NULL);
  w_fread(file, buf, 10);
  if (buf[0] == 'I' && buf[1] == 'D' && buf[2] == '3')
  {
    char tagSize[4];
    tagSize[0] = buf[6];
    tagSize[1] = buf[7];
    tagSize[2] = buf[8];
    tagSize[3] = buf[9];
    tag_size = synchsafeToNormal(tagSize);
  }
  w_fclose(file);
  return tag_size;
}

int GetTrackBitrate(wchar_t *fullpath, int fulltime)
{
  W_FSTAT wstat;
  w_fstat(fullpath, &wstat);
  int tag_size = get_tag_size(fullpath);
  int size_in_kb = (wstat.st_size - tag_size) / 1000;
  return (size_in_kb * 8) / fulltime;
}

void GetNextTrackData(NEW_TRACK_DATA *TrackData, BOOK *book)
{
  Internal_Function *Data = Get_Internal_Function();

  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
#ifdef DB3150v1
  wchar_t *Fullpath = WStringAlloc(256);
  MusicBook->pMusicServer->GetFilename(TrackData->Track_ID,
                                       256,
                                       Fullpath);

  Data->Bitrate = GetTrackBitrate(Fullpath, Data->FullTimeInSeconds);
  Data->Extension = GetFileFormat(Fullpath);
#ifdef K660_R1FA037
  MusicBook->pMusicServer->GetFilename(TrackData->Track_ID,
                                       256,
                                       Fullpath);
  Data->CoverArtID = MetaData_GetCover(Fullpath);
#endif

#ifndef K660_R1FA037
  Data->Genre = MetaData_GetGenre(Fullpath);

  int pFileOffset;
  int pAlbumArtSize;
  char pImageType;
  if (MetaData_GetCoverInfo(Fullpath, &pImageType, &pAlbumArtSize, &pFileOffset))
  {
    ImageID_Free(Data->CoverArtID);
    Data->CoverArtID = GetCoverArt(Fullpath, pAlbumArtSize, pFileOffset, pImageType);
  }
  else
  {
    Data->CoverArtID = NOIMAGE;
  }
#endif

#else
  wchar_t *Fullpath = WStringAlloc(MUSIC_SERVER_MAX_URI_LENGTH);
  wchar_t *Artist = WStringAlloc(MUSIC_SERVER_MAX_URI_LENGTH);
  wchar_t *Album = WStringAlloc(MUSIC_SERVER_MAX_URI_LENGTH);
  wchar_t *Title = WStringAlloc(MUSIC_SERVER_MAX_URI_LENGTH);

  bool ContainsAlbumart;
  bool IsRealMediaFile;
  TMusicServer_Time ElapsedTime;
  TMusicServer_Time FullTime;
  MusicBook->pMusicServer->GetFocusedItem(TrackData->Track_ID,
                                          MUSIC_SERVER_MAX_URI_LENGTH,
                                          Artist,
                                          Album,
                                          Title,
                                          Fullpath,
                                          &FullTime,
                                          &ElapsedTime,
                                          &ContainsAlbumart,
                                          &IsRealMediaFile);

  Data->Extension = GetFileFormat(Fullpath);

  if (ContainsAlbumart)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    FUint32 pFileOffset;
    FUint32 pAlbumArtSize;
    TMusicServer_AlbumArt_ImageType pImageType;
    TBool pIsDRM;

    MusicBook->pMusicServer->GetAlbumArt(TrackData->Track_ID,
                                         MUSIC_SERVER_MAX_URI_LENGTH,
                                         Fullpath,
                                         &pFileOffset,
                                         &pAlbumArtSize,
                                         &pImageType,
                                         &pIsDRM);
    Data->CoverArtID = GetCoverArt(Fullpath, pAlbumArtSize, pFileOffset, pImageType);
#else
    MusicBook->pMusicServer->GetFilename(TrackData->Track_ID,
                                         MUSIC_SERVER_MAX_URI_LENGTH,
                                         Fullpath);

    int pFileOffset;
    int pAlbumArtSize;
    char pImageType;
    ImageID_Free(Data->CoverArtID);
    if (MetaData_GetCoverInfo(Fullpath, &pImageType, &pAlbumArtSize, &pFileOffset))
    {
      Data->CoverArtID = GetCoverArt(Fullpath, pAlbumArtSize, pFileOffset, pImageType);
    }
    else
    {
      Data->CoverArtID = NOIMAGE;
    }
#endif
  }
  else
  {
    Data->CoverArtID = NOIMAGE;
  }

  Data->Bitrate = GetTrackBitrate(Fullpath, Data->FullTimeInSeconds);
  Data->Genre = MetaData_GetGenre(Fullpath);

  WStringFree(Artist);
  WStringFree(Album);
  WStringFree(Title);
#endif
  WStringFree(Fullpath);
}

TRACK_DESC *TrackDesc_Init()
{
  TRACK_DESC *TrackDesc = (TRACK_DESC *)malloc(sizeof(TRACK_DESC));
  memset(TrackDesc, NULL, sizeof(TRACK_DESC));
  TrackDesc->Filename = NULL;
  TrackDesc->Filepath = NULL;
  return TrackDesc;
}

void TrackDesc_Free(TRACK_DESC *TrackDesc)
{
  if (TrackDesc)
  {
    WStringFree(TrackDesc->Filepath);
    WStringFree(TrackDesc->Filename);
    mfree(TrackDesc);
  }
}

BOOL TrackDesc_Compare(TRACK_DESC *track1, TRACK_DESC *track2)
{
  if (track1 && track2)
  {
    if ((!wstrcmp(track1->Filename, track2->Filename)) && (!wstrcmp(track1->Filepath, track2->Filepath)))
      return TRUE;
    else
      return FALSE;
  }
  else
    return NULL;
}

TRACK_DESC *TrackDesc_Get(BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  if (MusicBook)
  {
    TRACK_DESC *TrackDesc = TrackDesc_Init();

    wchar_t *Filename = FILEITEM_GetFname(MusicBook->CurrentTrack->file_item);
    wchar_t *Filepath = FILEITEM_GetPath(MusicBook->CurrentTrack->file_item);

    TrackDesc->Filename = WStringAlloc(wstrlen(Filename));
    TrackDesc->Filepath = WStringAlloc(wstrlen(Filepath));

    wstrcpy(TrackDesc->Filename, Filename);
    wstrcpy(TrackDesc->Filepath, Filepath);

    return TrackDesc;
  }
  return NULL;
}
