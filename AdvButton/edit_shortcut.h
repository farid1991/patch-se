#ifndef _EDIT_SHORTCUT_H_
#define _EDIT_SHORTCUT_H_

static const char SelectJavaApps_Page[] = "BookManager_ChangeShortcuts_SelectJavaApps_Page";
static const char SelectShortcut_Page[] = "BookManager_ChangeShortcuts_SelectShortcut_Page";
static const char ChangeShortcuts_Page[] = "BookManager_ChangeShortcuts_Page";

typedef struct
{
  int str_id;
  int icon_id;
} SC_DATA;

typedef struct
{
  wchar_t *name;
  wchar_t *vendor;
  wchar_t *fullpath;
  wchar_t *hash_name;
  IMAGEID imageID;
} JAVA_LIST_ITEM;

void DestroyJavaList(BOOK *book);

int ButtonList_Enter_Event(void *data, BOOK *book);
int ButtonList_Exit_Event(void *data, BOOK *book);
int ButtonList_Accept_Event(void *data, BOOK *book);
int ButtonList_Cancel_Event(void *data, BOOK *book);

int SelectShortcut_Enter_Event(void *data, BOOK *book);
int SelectShortcut_Prev_Event(void *data, BOOK *book);
int SelectShortcut_Cancel_Event(void *data, BOOK *book);

int SelectJavaApps_Enter_Event(void *data, BOOK *book);
int SelectJavaApps_Exit_Event(void *data, BOOK *book);

const PAGE_MSG SetJava_PageEvents[] = {
    PAGE_ENTER_EVENT, SelectJavaApps_Enter_Event,
    PAGE_EXIT_EVENT, SelectJavaApps_Exit_Event,
    NIL_EVENT, NULL};

const PAGE_DESC ChangeShortcuts_SelectJavaApps_Page = {SelectJavaApps_Page, NULL, SetJava_PageEvents};

const PAGE_MSG SelectShortcut_PageEvents[] = {
    PAGE_ENTER_EVENT, SelectShortcut_Enter_Event,
    PREVIOUS_EVENT, SelectShortcut_Prev_Event,
    CANCEL_EVENT, SelectShortcut_Cancel_Event,
    NIL_EVENT, NULL};

const PAGE_DESC ChangeShortcuts_SelectShortcut_Page = {SelectShortcut_Page, NULL, SelectShortcut_PageEvents};

const PAGE_MSG ChangeShortcuts_PageEvents[] = {
    PAGE_ENTER_EVENT, ButtonList_Enter_Event,
    ACCEPT_EVENT, ButtonList_Enter_Event,
    CANCEL_EVENT, ButtonList_Cancel_Event,
    PAGE_EXIT_EVENT, ButtonList_Exit_Event,
    NIL_EVENT, NULL};

const PAGE_DESC BookManager_ChangeShortcuts_page = {ChangeShortcuts_Page, NULL, ChangeShortcuts_PageEvents};

#endif
