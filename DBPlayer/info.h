#ifndef _INFO_H_
#define _INFO_H_

#define HEADER_SIZE 4

#define INDEX(x) x / 8
#define SHIFT(x) x % 8
#define GETBIT(v, x) ((v[INDEX(x)] << SHIFT(x)) & 0x80) >> 7

IMAGEID GetCoverArt(DBP_DATA *data);
TEXTID GetTags(wchar_t *path, wchar_t *name, int id);
TEXTID GetFileExt(DBP_DATA *data);
TEXTID GetTotalTime(DBP_DATA *data);
void ElapsedTime(u16 timerID, LPARAM lparam);
TEXTID GetElapsedTime(DBP_DATA *data);
TEXTID GetRemainingTime(DBP_DATA *data);
TEXTID GetBitrate(DBP_DATA *data);
TEXTID GetSampleRate(DBP_DATA *data);
TEXTID GetAudioOutput(DBP_DATA *data);

#endif
