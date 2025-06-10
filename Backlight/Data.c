#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"

int FindNameFromData(char *name, FILEDATA *fdata, int count)
{
  for (int i = 0; i < count; i++)
  {
    if (strcmp(name, fdata[i].bookname) == FALSE)
      return i;
  }
  return -1;
}

void WriteData(BOOK *book, int count)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;

  FILEDATA *fdata = &((TEMPDATA *)BCBook->mydata)->fdata;

  int num = FindNameFromData(BCBook->fdata.bookname, fdata, count);

  int new_count = count;

  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0);
  if (file >= 0)
  {
    if (num == -1)
    {
      new_count += 1;
      fwrite(file, &new_count, sizeof(int));
      fwrite(file, fdata, sizeof(FILEDATA) * count);
      fwrite(file, &BCBook->fdata, sizeof(FILEDATA));
    }
    else
    {
      fdata[num].time = BCBook->fdata.time;
      fdata[num].bright = BCBook->fdata.bright;
      fwrite(file, &new_count, sizeof(int));
      fwrite(file, fdata, sizeof(FILEDATA) * new_count);
    }
    fclose(file);
  }
}

void DeleteData(int num, BOOK *book, int count)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;

  FILEDATA *fdata = &((TEMPDATA *)BCBook->mydata)->fdata;
  int new_count = count - 1;

  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0);
  if (file >= 0)
  {
    fwrite(file, &new_count, sizeof(int));
    for (int i = 0; i < count; i++)
    {
      if (i != num)
        fwrite(file, &fdata[i], sizeof(FILEDATA));
    }
    fclose(file);
  }
}

char *GetNameFromData(FILEDATA *fdata, int index)
{
  return (fdata[index].bookname);
}

int GetTimeFromData(FILEDATA *fdata, int index)
{
  return (fdata[index].time);
}

int GetBrightFromData(FILEDATA *fdata, int index)
{
  return (fdata[index].bright);
}

void GetData(void *mydata, int size)
{
  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0);
  if (file >= 0)
  {
    fread(file, mydata, size);
    fclose(file);
  }
}
