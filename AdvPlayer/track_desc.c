#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\include\book\AudioPlayerBook.h"

#include "str_lib.h"
#include "track_desc.h"

bool track_desc_compare(TRACK_DESC *t1, TRACK_DESC *t2)
{
  if (t1 && t2)
  {
    if (!wstrcmp(t1->fpath, t2->fpath) && !wstrcmp(t1->fname, t2->fname))
    {
      return true;
    }
  }
  return false;
}

void track_desc_free(TRACK_DESC * track)
{
  if(track)
  {
    mfree(track->fpath);
    mfree(track->fname);
    mfree(track);
  }
}

TRACK_DESC *track_desc_get(AudioPlayerBook *audio_book)
{
  if (audio_book->dsc)
  {
    TRACK_DESC *track = (TRACK_DESC *)malloc(sizeof(TRACK_DESC));

    track->fpath = wstr_alloc(wstrlen(audio_book->dsc->fpath));
    wstrcpy(track->fpath, audio_book->dsc->fpath);

    track->fname = wstr_alloc(wstrlen(audio_book->dsc->fname));
    wstrcpy(track->fname, audio_book->dsc->fname);

    return track;
  }
  return NULL;
}
