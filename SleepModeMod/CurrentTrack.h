#ifndef _CurrentTrack_H_
#define _CurrentTrack_H_

typedef struct
{
  wchar_t *path;
  wchar_t *name;
  TEXTID Artist;
  TEXTID Title;
  TEXTID Album;
} TRACK_DESC;

void TrackDesc_Free(TRACK_DESC *track_desc);
bool TrackDesc_Compare(TRACK_DESC *t1, TRACK_DESC *t2);
TRACK_DESC *TrackDesc_Get(BOOK *book);
void GetTags(BOOK *book);

#endif
