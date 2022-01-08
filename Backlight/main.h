#ifndef _MAIN_H_
#define _MAIN_H_

#define TI_GET_HOUR(x) ((unsigned int)x & 0xFF)
#define TI_GET_MIN(x) (((unsigned int)x >> 8) & 0xFF)
#define TI_GET_SEC(x) (((unsigned int)x >> 16) & 0xFF)

//#define FILE_PATH L"/tpa/system/settings/"
#define FILE_NAME L"Backlight.bin"

#define TIME_LIMIT 86399
#define BOOKNAME_MAX_LEN 31
#define FLASH_MASK 0xF8000000

#define FREE_GUI(g)           \
    if (g)                    \
    {                         \
        GUIObject_Destroy(g); \
        g = NULL;             \
    }

__thumb void *malloc(int size);
__thumb void mfree(void *mem);

typedef struct
{
  TEXTID book_name;
  IMAGEID book_icon;
} BOOK_ITEM;

typedef struct
{
  char bookname[BOOKNAME_MAX_LEN + 1];
  int time;
  int bright;
} FILEDATA;

typedef struct
{
  int count;
  FILEDATA fdata;
} TEMPDATA;

typedef struct _BacklightControlBook : BOOK
{
  GUI *main_menu;
  GUI *books_list;
  GUI *string_input;
  GUI *time_input;
  GUI *bright_input;
  GUI *delete_item;

  FILEDATA fdata;
  void *mydata;
  int itemcount;
  LIST *book_list;
  int bookcount;

  TIME *time;
  int bright;
} BacklightControlBook;

void MainList_Cancel_Action(BOOK *book, GUI *gui);

//  ----------------------------------------------------

#endif
