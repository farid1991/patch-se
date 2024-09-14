#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#define KBYTE (1 << 10)
#define MBYTE (1 << 20)

static inline int TO_KBYTE(int i) { return i >> 10; }
static inline int TO_MBYTE(int i) { return i >> 20; }
static inline int is_readonly(int attr) { return ((attr & ~FSX_O_ENCRYPT) & (0x100 >> 1)) ? FALSE : TRUE; }

static bool is_directory(wchar_t *fullpath)
{
  W_FSTAT fs;
  if (w_fstat(fullpath, &fs) == -1)
    return false;
  return (fs.attr & FSX_O_CHKPATH) != 0;
}

void read_directory(wchar_t *fullpath, int *files_count, int *dir_count)
{
  int files = 0, folders = 0;
  void *dir = w_diropen(fullpath);
  if (dir)
  {
    wchar_t *next;
    w_chdir(fullpath);
    while ((next = w_dirread(dir)) != NULL)
    {
      if (is_directory(next))
        folders++;
      else
        files++;
    }
    w_dirclose(dir);
  }
  *files_count = files;
  *dir_count = folders;
}

TEXTID file_count_to_textid(const wchar_t *fullpath, TEXTID space)
{
  W_FSTAT fs;
  w_fstat(fullpath, &fs);
  BOOL readonly = is_readonly(fs.attr);

  int size = 0;
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
  else
  {
    size = TO_MBYTE(fs.st_size);
    txt[2] = TXT_MBYTES;
  }

  txt[0] = TextID_CreateIntegerID(size);
  txt[1] = space;
  txt[3] = space;

  if (readonly)
    txt[4] = READ_ONLY_TXT;
  else
    txt[4] = space;

  return TextID_Create(txt, ENC_TEXTID, 5);
}

TEXTID dir_count_to_textid(wchar_t *fullpath, TEXTID space)
{
  int files, folders;
  read_directory(fullpath, &files, &folders);

  if (!files && !folders)
    return TXT_EMPTYFOLDER;

  TEXTID ret;
  if (files && folders)
  {
    TEXTID txt[7];
    txt[0] = TextID_CreateIntegerID(folders);
    txt[1] = TextID_CreateCharacterID(FOLDER_ICN);
    txt[2] = space;
    txt[3] = TextID_CreateCharacterID('&');
    txt[4] = space;
    txt[5] = TextID_CreateIntegerID(files);
    txt[6] = TextID_CreateCharacterID(FILE_ICN);
    ret = TextID_Create(txt, ENC_TEXTID, 7);
  }
  else if (folders)
  {
    TEXTID txt[3];
    txt[0] = TextID_CreateIntegerID(folders);
    txt[1] = space;
    txt[2] = TextID_CreateCharacterID(FOLDER_ICN);
    ret = TextID_Create(txt, ENC_TEXTID, 3);
  }
  else if (files)
  {
    TEXTID txt[3];
    txt[0] = TextID_CreateIntegerID(files);
    txt[1] = space;
    txt[2] = TextID_CreateCharacterID(FILE_ICN);
    ret = TextID_Create(txt, ENC_TEXTID, 3);
  }
  return ret;
}

extern "C" TEXTID db_set_secondline_text(wchar_t *fullpath, TEXTID space)
{
  if (is_directory(fullpath))
    return dir_count_to_textid(fullpath, space);

  TEXTID txt[3];
  txt[0] = TextID_CreateCharacterID(HELP_TEXT_ICN);
  txt[1] = space;
  txt[2] = file_count_to_textid(fullpath, space);
  return TextID_Create(txt, ENC_TEXTID, 3);
}
