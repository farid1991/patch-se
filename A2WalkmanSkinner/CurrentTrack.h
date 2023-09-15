#ifndef __CURRENTTRACK_H__
#define __CURRENTTRACK_H__

#define EXT_LENGTH 3
#define MAX_GENRE_LENGTH 30

#define INDEX(x) x >> 3
#define SHIFT(x) x % 8
#define GETBIT(v, x) ((v[INDEX(x)] << SHIFT(x)) & 0x80) >> 7

typedef struct
{
  wchar_t *Filename;
  wchar_t *Filepath;
} TRACK_DESC;

TRACK_DESC *TrackDesc_Get(BOOK *book);
void TrackDesc_Free(TRACK_DESC *track_desc);
BOOL TrackDesc_Compare(TRACK_DESC *t1, TRACK_DESC *t2);

void GetCurrentTrackData(BOOK *book);
void GetNextTrackData(NEW_TRACK_DATA *TrackData, BOOK *book);

#endif
