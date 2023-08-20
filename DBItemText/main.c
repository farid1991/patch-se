#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#define KBYTE (2 << 9)
#define MBYTE (2 << 21)
#define TO_KBYTE(i) (i >> 10)
#define TO_MBYTE(i) (i >> 20)

bool isDirectory(wchar_t *filename)
{
  W_FSTAT fs;
  if (w_fstat(filename, &fs) != -1)
    return (fs.attr & FSX_O_CHKPATH);
  else
    return false;
}

void readFolder(wchar_t *filename, int *retFiles, int *retFolders)
{
  int files = 0, folders = 0;
  void *dir = w_diropen(filename);
  if (dir)
  {
    wchar_t *next;
    w_chdir(filename);
    while (next = w_dirread(dir))
    {
      if (!isDirectory(next))
        files++;
      else
        folders++;
    }
    w_dirclose(dir);
  }
  *retFiles = files;
  *retFolders = folders;
}

TEXTID getFileData(wchar_t *filename, TEXTID space)
{
  W_FSTAT fs;
  w_fstat(filename, &fs);
  int i = 0x100, size = 0;
  i >>= 1;
  if ((fs.attr & ~FSX_O_ENCRYPT) & i)
    i = 0; // rw
  else
    i = 1; // ro

  TEXTID txt[5];

  if (fs.st_size < KBYTE)
  {
    size = fs.st_size;
    txt[2] = TXT_BYTES;
  }
  else if (fs.st_size < MBYTE)
  {
    size = TO_KBYTE(fs.st_size);
    txt[2] = TXT_KBYTES;
  }
  else if (fs.st_size >= MBYTE)
  {
    size = TO_MBYTE(fs.st_size);
    txt[2] = TXT_MBYTES;
  }

  if (i)
    txt[4] = TextID_Create("(ro)", ENC_LAT1, 4);
  else
    txt[4] = space;

  txt[0] = TextID_CreateIntegerID(size);
  txt[1] = space;
  txt[3] = space;
  return TextID_Create(txt, ENC_TEXTID, 5);
}

TEXTID getFolderData(wchar_t *filename, TEXTID space)
{
  int files, folders;
  readFolder(filename, &files, &folders);
  if (!files && !folders)
    return TXT_EMPTYFOLDER;

  if (files && !folders)
  {
    TEXTID txt[7];
    txt[0] = TextID_CreateIntegerID(files);
    txt[1] = space;
    txt[2] = FILES_TXT;
    txt[3] = space;
    txt[4] = TextID_CreateCharacterID('&');
    txt[5] = space;
    txt[6] = NOSUBFOLDERS_TXT;
    return TextID_Create(txt, ENC_TEXTID, 7);
  }
  else if (!files && folders)
  {
    TEXTID txt[5];
    txt[0] = TextID_CreateIntegerID(folders);
    txt[1] = space;
    txt[2] = TextID_CreateCharacterID('&');
    txt[3] = space;
    txt[4] = NOFILES_TXT;
    return TextID_Create(txt, ENC_TEXTID, 5);
  }
  else
  {
    TEXTID txt[7];
    txt[0] = TextID_CreateIntegerID(folders);
    txt[1] = space;
    txt[2] = TextID_CreateCharacterID('&');
    txt[3] = space;
    txt[4] = TextID_CreateIntegerID(files);
    txt[5] = space;
    txt[6] = FILES_TXT;
    return TextID_Create(txt, ENC_TEXTID, 7);
  }
}

extern "C" TEXTID SetSecondlineItemText(wchar_t *filename, TEXTID space)
{
  if (isDirectory(filename))
    return getFolderData(filename, space);

  TEXTID txt[3];
  txt[0] = TextID_CreateCharacterID(HELP_TEXT_ICN);
  txt[1] = space;
  txt[2] = getFileData(filename, space);
  return TextID_Create(txt, ENC_TEXTID, 3);
}
