#ifndef Bookman_H
#define Bookman_H

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

#define BOOKMAN_PATH L"/tpa/user/other/ini"
#define BOOKMAN_INI L"bookman.ini"

enum JAVA_APP_ID
{
  JAVAAPP_NAME,
  UNK_1,
  UNK_2,
  UNK_3,
  UNK_4,
  JAVAAPP_FULLPATH,
  LAST_ID
};

typedef struct
{
  BOOK *book;
  char *book_name;
  IMAGEID book_icon;
  u16 gui_count;
  bool isJava;
} BOOK_LIST_ITEM;

typedef struct BookManager : BOOK
{
  GUI *mainmenu;
  DISP_OBJ_ONKEY_METHOD oldOnKey;
  LIST *books_list;
  int books_count;
  int book_index;
  int buffer_size;
  char *cfg_buffer;
} BookManager;

int NextBook();
void Create_BookManager();
int pg_BookManager_CancelEvent(void *data, BOOK *book);
int pg_BookManager_EnterEvent(void *data, BOOK *book);
int pg_BookManager_AcceptEvent(void *data, BOOK *book);

const PAGE_MSG bm_msglst_base[] =
    {
        CANCEL_EVENT, pg_BookManager_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_BookManager_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC BookManager_Base_Page = {"BookManager_Base_Page", NULL, bm_msglst_base};

const PAGE_MSG bm_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_BookManager_EnterEvent,
        NIL_EVENT, NULL};
const PAGE_DESC BookManager_Main_Page = {"BookManager_Main_Page", NULL, bm_msglst_main};

#endif
