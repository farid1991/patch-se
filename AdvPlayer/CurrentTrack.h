#ifndef _CurrentTrack_H_
#define _CurrentTrack_H_

typedef struct
{
  wchar_t *path;
  wchar_t *name;
} TRACK_DESC;

void TrackDesc_Free(TRACK_DESC *track_desc);
BOOL TrackDesc_Compare(TRACK_DESC *t1, TRACK_DESC *t2);
TRACK_DESC *TrackDesc_Get(BOOK *book);

#endif
