#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\book\AudioPlayerBook.h"
#include "..\\include\book\FmRadio_Book.h"
#include "..\\include\book\ScreenSaverBook.h"

#include "Lib.h"
#include "cover.h"
#include "CurrentTrack.h"
#include "lyric.h"
#include "main.h"
#include "StrLib.h"

void TrackDesc_Free(TRACK_DESC *track_desc)
{
  if (track_desc)
  {
    WStringFree(track_desc->path);
    WStringFree(track_desc->name);
    TextID_Destroy(track_desc->Album);
    TextID_Destroy(track_desc->Artist);
    TextID_Destroy(track_desc->Title);
    mfree(track_desc);
  }
}

bool TrackDesc_Compare(TRACK_DESC *t1, TRACK_DESC *t2)
{
  if (t1 && t2)
  {
    if (!wstrcmp(t1->path, t2->path) && !wstrcmp(t1->name, t2->name))
      return TRUE;
    else
      return FALSE;
  }
  else
    return FALSE;
}

TRACK_DESC *TrackDesc_Get(BOOK *book)
{
  if (book)
  {
    AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
    TRACK_DESC *track_desc = (TRACK_DESC *)malloc(sizeof(TRACK_DESC));
    memset(track_desc, NULL, sizeof(TRACK_DESC));
    wchar_t *path = audioBook->dsc->fpath;
    wchar_t *name = audioBook->dsc->fname;
    track_desc->path = WStringAlloc(WStringLength(path));
    wstrcpy(track_desc->path, path);
    track_desc->name = WStringAlloc(WStringLength(name));
    wstrcpy(track_desc->name, name);

    void *desc = MetaData_Desc_Create(path, name);
    track_desc->Artist = TextID_Create(MetaData_Desc_GetTags(desc, TAG_ARTIST), ENC_UCS2, TEXTID_ANY_LEN);
    track_desc->Title = TextID_Create(MetaData_Desc_GetTags(desc, TAG_TITLE), ENC_UCS2, TEXTID_ANY_LEN);
    track_desc->Album = TextID_Create(MetaData_Desc_GetTags(desc, TAG_ALBUM), ENC_UCS2, TEXTID_ANY_LEN);
    MetaData_Desc_Destroy(desc);

    return track_desc;
  }
  return NULL;
}

void GetTags(BOOK *book)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  SLEEPMODE_DATA *data = GetData();

  TRACK_DESC *NewTrack = TrackDesc_Get(audioBook);
  if (!TrackDesc_Compare(data->CurrentTrack, NewTrack))
  {
    if (data->has_cover)
      IMAGE_FREE(data->CoverArt);

    TrackDesc_Free(data->CurrentTrack);
    data->CurrentTrack = NewTrack;

    GetLyric(data->CurrentTrack->path, data->CurrentTrack->name);

    if (MetaData_ExtractCover(data->CurrentTrack->path, data->CurrentTrack->name))
    {
      ImageID_Get(SLEEPMODE_PATH, L"albumart.png", &data->CoverArt);
      data->has_cover = TRUE;
    }
    else
    {
      data->CoverArt = NOIMAGE;
      data->has_cover = FALSE;
    }
  }
  else
  {
    TrackDesc_Free(NewTrack);
  }

  if (data->lrc_state == READ_OK)
  {
    int currenttime = SECOND(audioBook->elapsed_time);
    int current_offset = find_current_timer_list(currenttime, data);
    if (current_offset <= data->total_offset && current_offset >= READY)
    {
      data->current_offset = current_offset;
      Kill_LyricTimer(data);
      data->offset_len = 0;
      Start_LyricTimer(data);
    }
  }
}
