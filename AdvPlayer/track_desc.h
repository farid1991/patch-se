#ifndef _PlaylistItem_h_
#define _PlaylistItem_h_

typedef struct TRACK_DESC
{
  wchar_t *fpath;
  wchar_t *fname;
} TRACK_DESC;

bool track_desc_compare(TRACK_DESC *t1, TRACK_DESC *t2);
TRACK_DESC *track_desc_get(AudioPlayerBook *audio_book);
void track_desc_free(TRACK_DESC * track);

#endif
