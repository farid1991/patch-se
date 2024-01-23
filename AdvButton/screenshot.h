#ifndef _SCREENSHOT_H_
#define _SCREENSHOT_H_
/*
;00 - "Sony Ericsson" (vibra) !!!dont stop
;01 - "Greeting" (vibra) !!!dont stop
;02 - "Notification"
;03 - "DISCREET"
;04 - "retrysuccess"
;05 - "REQUEST"
;06 - "FAILURE"
;07 - "PROGRESS"
;08 - "notification" (vibra)
;09 - "REMINDER" (vibra)
;0A - "disconnected"
;0B - "CHARGING"
;0C - "lowbattery" (vibra)
;0D - "emptybattery" (vibra)
;0E - "DISCREET"
;0F - "camerashutter"
;10 - "cameratimer"
;11 - "VIDEO"
;12 - "SUCCESS"
;13 - "TIMER" (vibra)
;14 - (vibra)
;15 - "messageclick" (vibra)
;16 - "messagealert1" (vibra)
;17 - "messagealert2" (vibra)
;18 - "messagealert3" (vibra)
;19 - "messagealert4" (vibra)
;1A - "messagealert5" (vibra)
;1B - "messagealert6" (vibra)
;1C - "camerashutter2"
;1D - "camerashutter3"
;1E - "camerashutter4"
;1F - "camerafocus"
;20 - "cameraburst"
;25 - "FAILURE"
;2A - "beepbeepbeep"
;2B - "jackopen1"
;2C - "jackopen2"
;2D - "jackopen3"
;30 - "Chimeslow"
;32 - "beep"
*/

#pragma pack(1)
typedef struct
{
  u16 ID;
  int size;
  u16 zero;
  u16 zero1;
  int dataoffset;
  int sizeofheader;
  int width;
  int height;
  u16 planes;
  u16 bpp;
  int compression;
  int sizeofimage;
  int hresolution;
  int vresolution;
  int colors;
  int important;
} BMP_HEADER;
#pragma pack()

#define BMP_SIGNATURE 0x4D42
#define SIZE_WO_SIGNATURE 52
#define HEADER_SIZE 40
#define DATA_OFFSET 54
#define NBR_OF_PLANE 1
#define NBR_OF_BITS 24
#define IMAGE_SIZE(w,h) (w*h*3)
#define MAX_FILENAME_LEN 50

#define SNAPSHOT_PATH L"/tpa/user/image/SnapShots"

void Screenshoter(int xsize, int ysize);

#endif
