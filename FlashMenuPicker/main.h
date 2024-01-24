#ifndef _MAIN_H_
#define _MAIN_H_

static char *MEM_NAME = "swf_mem";
static char *EMP_NAME = "swf_emp";

#if defined(DB2000) || defined(DB2010)
#define URI_MODE 1
#else
#define URI_MODE 2
#endif

static const wchar_t *CUSTOM_NAME = L"Flash_Menu_Custom.swf";
static const char *BOOKNAME = "FlashMenuPickerBook";

static const char FlashMenuPicker_Pick_Page_Name[] = "FlashMenuPicker_Pick_Page";
static const char FlashMenuPicker_Base_Page_Name[] = "FlashMenuPicker_Base_Page";
static const char FlashMenuPicker_Main_Page_Name[] = "FlashMenuPicker_Main_Page";

enum
{
  ITEM_SYS,
  ITEM_INT,
#ifdef EXT_FLASH_PATH
  ITEM_EXT,
#endif
  ITEM_LAST
};

enum FILEFOLDERTYPES
{
  ITEM_FOLDER,
  ITEM_FILE
};

enum SELF
{
  SEL_FOLDER,
  SEL_FILE
};

typedef struct FILELIST
{
  void *next;
  int is_folder;
  wchar_t *fullname;
  wchar_t *name;
} FILELIST;

typedef struct _MM_DATA
{
  int type;
  FILELIST *fltop;
} MM_DATA;

typedef struct FlashMenuPickerBook : BOOK
{
  GUI_LIST *MainMenu;
  GUI_LIST *SubMenu;
  int type;
} FlashMenuPickerBook;

typedef struct FlashDesktopBook : BOOK
{
  GUI *main_menu;
  IMAGEID img;
} FlashDesktopBook;

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

__thumb void *malloc(int size);
__thumb void mfree(void *mem);

int pg_FlashMenuPicker_EnterEvent(void *data, BOOK *book);
int pg_FlashMenuPicker_ExitEvent(void *data, BOOK *book);
int pg_FlashMenuPicker_CancelEvent(void *data, BOOK *book);

int pg_FlashMenuPicker_Pick_EnterEvent(void *data, BOOK *book);
int pg_FlashMenuPicker_Pick_ExitEvent(void *data, BOOK *book);

const PAGE_MSG bk_msglst_skin[] =
    {
        PAGE_ENTER_EVENT, pg_FlashMenuPicker_Pick_EnterEvent,
        PAGE_EXIT_EVENT, pg_FlashMenuPicker_Pick_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC FlashMenuPicker_Pick_Page = {FlashMenuPicker_Pick_Page_Name, NULL, bk_msglst_skin};

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_FlashMenuPicker_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_FlashMenuPicker_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC FlashMenuPicker_Base_Page = {FlashMenuPicker_Base_Page_Name, NULL, bk_msglst_base};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_FlashMenuPicker_EnterEvent,
        PAGE_EXIT_EVENT, pg_FlashMenuPicker_ExitEvent,
        NIL_EVENT, NULL};
const PAGE_DESC FlashMenuPicker_Main_Page = {FlashMenuPicker_Main_Page_Name, NULL, bk_msglst_main};

#endif
