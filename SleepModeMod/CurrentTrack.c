#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\include\book\AudioPlayerBook.h"
#include "..\\include\book\FmRadio_Book.h"
#include "..\include\book\ScreenSaverBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "main.h"
#include "StrLib.h"

void TrackDesc_Free(TRACK_DESC *track_desc)
{
  if (track_desc)
  {
    if (track_desc->path)
    {
      WStringFree(track_desc->path);
    }
    if (track_desc->name)
    {
      WStringFree(track_desc->name);
    }
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
    if (wstrcmp(t1->path, t2->path) == 0 && wstrcmp(t1->name, t2->name) == 0)
    {
      return TRUE;
    }
    else
    {
      return FALSE;
    }
  }
  else
  {
    return FALSE;
  }
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
