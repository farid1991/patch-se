#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "cover.h"
#include "CurrentTrack.h"
#include "main.h"

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
    if (synchsafe % 8)
      sizeloc++;
  }
  return size;
}

int MetaData_ExtractCover(wchar_t *path, wchar_t *name)
{
  int ret = 0;

  if (FSX_IsFileExists(SLEEPMODE_PATH, L"albumart.png"))
  {
    int error;
    FileDelete(SLEEPMODE_PATH, L"albumart.png", &error);
  }

  int tag_id = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0);
  char CHUCK[100 + 1];
  fread(tag_id, CHUCK, 100);
  if (CHUCK[0] == 'I' && CHUCK[1] == 'D' && CHUCK[2] == '3')
  {
    char tagSize[4];
    tagSize[0] = CHUCK[6];
    tagSize[1] = CHUCK[7];
    tagSize[2] = CHUCK[8];
    tagSize[3] = CHUCK[9];
    int size = synchsafeToNormal(tagSize);
    int input = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0);
    char cm[4];
    bool HasPic = false;
    bool isMid = false;
    int NEEDPOS = 0;
    char *buff = (char *)malloc(size + 1);
    fread(input, buff, size);
    while (NEEDPOS < size)
    {
      if (buff[NEEDPOS] == 'P' && buff[NEEDPOS + 1] == 'I' && buff[NEEDPOS + 2] == 'C')
      {
        HasPic = true;
        break;
      }
      NEEDPOS++;
    }
    NEEDPOS++;
    mfree(buff);
    lseek(input, NEEDPOS - 2, FSX_SEEK_SET);
    if (HasPic == true)
    {
      int TotalSize;
      fread(input, cm, 1);
      if (cm[0] == ')')
      {
        lseek(input, 3, FSX_SEEK_CUR);
        fread(input, cm, 3);
        TotalSize = (cm[0] << 16) | (cm[1] << 8) | cm[2];
      }
      if (cm[0] == 'A')
      {
        lseek(input, 3, FSX_SEEK_CUR);
        fread(input, cm, 4);
        TotalSize = (cm[0] << 24) | (cm[1] << 16) | (cm[2] << 8) | cm[3];
        lseek(input, 3 + 12, FSX_SEEK_CUR);
        char checker;
        fread(input, &checker, 1);
        if (checker != 0)
        {
          isMid = true;
          lseek(input, -1, FSX_SEEK_CUR);
        }
      }
      int psize = 0;
      if (isMid == false)
      {
        psize = TotalSize - 1;
      }
      else
      {
        psize = TotalSize - 12 - 1;
      }
      char *picture = (char *)malloc(psize + 1);
      fread(input, picture, psize);
      int output;
      output = _fopen(SLEEPMODE_PATH, L"albumart.png", FSX_O_RDWR, FSX_S_IREAD | FSX_S_IWRITE, 0);
      fwrite(output, picture, psize);
      fclose(output);
      mfree(picture);
      ret = 1;
    }
    fclose(input);
  }
  fclose(tag_id);
  return ret;
}
