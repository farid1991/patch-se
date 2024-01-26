#ifndef _MAIN_H_
#define _MAIN_H_

static const wchar_t *CONFIG_NAME = L"sc.bin";

static const char *GT_MEM = "GT";
static const char *BOOKNAME = "GotoShortcutBook";
static const char BASE_PAGE_NAME[] = "Goto_Base_Page";
static const char MAIN_PAGE_NAME[] = "Goto_Main_Page";

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define TextID_Get(str) TextID_Create(str, ENC_UCS2, TEXTID_ANY_LEN)

enum Modes
{
  EDITING_MODE,
  ADDING_MODE
};

enum SHORTCUT_TYPE
{
  TYPE_SHORTCUT,
#ifdef USE_JAVA
  TYPE_JAVA,
#endif
#ifdef HAS_ELF
  TYPE_ELF,
#endif
  TYPE_UIEVENT,
  TYPE_FOLDER,
  TYPE_LAST
};

enum FILEFOLDERTYPES
{
  ITEM_BACK,
  ITEM_FOLDER,
  ITEM_FILE
};

enum SELF
{
  SEL_FOLDER,
  SEL_FILE
};

typedef struct
{
  wchar_t *name;
  wchar_t *fullpath;
  IMAGEID image_id;
} JAVA_LIST_ELEM;

#define SHORTCUT_TYPES_MAX_LEN 0x1D
#define CAPTION_MAX_LEN 0x1F

typedef struct
{
  char Type_f;
  wchar_t sData_f[SHORTCUT_TYPES_MAX_LEN];
  wchar_t Caption_f[CAPTION_MAX_LEN];
  int Icon_f;
} SHORTCUT_FILE;

typedef struct
{
  uint8_t ShortcutType;
  wchar_t *ShortcutLink;
  wchar_t *ShortcutText;
  IMAGEID ShortcutIcon;
} SC_LIST_ELEM;

typedef struct GotoShortcut_Book : BOOK
{
  GUI_LIST *MainMenu;
  GUI_LIST *Editor;
#ifdef USE_JAVA
  GUI_LIST *JavaMenu;
#endif
  GUI_LIST *TypesList;
  GUI *CaptionInput;
  GUI *YesNoQuestion;
  GUI *EventInput;
  GUI *FolderInput;
  GUI_LIST *SelectFolder;
  LIST *ShortcutList;
#ifdef USE_JAVA
  LIST *JavaList;
#endif
  SC_LIST_ELEM *ShortcutItem;
  uint8_t CurrentItem;
  uint8_t FType;
  int MainMenuID;
} GotoShortcut_Book;

int IsGotoShortcutBook(BOOK *bk);
int pg_Goto_Shortcut_AcceptEvent(void *data, BOOK *bk);
int pg_Goto_Shortcut_CancelEvent(void *data, BOOK *bk);
int pg_Goto_Shortcut_EnterEvent(void *data, BOOK *bk);

void ShortcutFree(void *Item);

__thumb void *malloc(int size);
__thumb void mfree(void *mem);

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_Goto_Shortcut_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_Goto_Shortcut_CancelEvent,
        NIL_EVENT, NULL};

const PAGE_DESC Goto_Shortcut_Base_Page = {BASE_PAGE_NAME, NULL, bk_msglst_base};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_Goto_Shortcut_EnterEvent,
        PAGE_EXIT_EVENT, pg_Goto_Shortcut_EnterEvent,
        ACCEPT_EVENT, pg_Goto_Shortcut_AcceptEvent,
        NIL_EVENT, NULL};

const PAGE_DESC Goto_Shortcut_Main_Page = {MAIN_PAGE_NAME, NULL, bk_msglst_main};

#endif
