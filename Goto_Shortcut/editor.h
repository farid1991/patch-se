#ifndef _EDITOR_H_
#define _EDITOR_H

static const wchar_t *ELF_EXT = L"*.elf";

#ifdef ELFS_EXT_PATH
#define ELFS_PATH_COUNT 2
#else
#define ELFS_PATH_COUNT 1
#endif

static const IMAGEID TypesIcons[TYPE_LAST] =
    {
        SHORTCUT_LIST_ICN,
#ifdef USE_JAVA
        DB_LIST_JAVA_ICN,
#endif
#ifdef HAS_ELF
        ENTERTAINMENT_ICN,
#endif
        GUI_UNAVAILABLE_ICN,
        DB_LIST_FOLDER_ICN};

const IMAGEID EditorIcons[2] = {HPB_OTHER_ICN, MENU_SETTINGS_ICN};

static const char EDITOR_MAIN_BASEPAGE_NAME[] = "SCEdit_Main_Page";
static const char EDITOR_CAPTIONINPUT_BASEPAGE_NAME[] = "SCEdit_LabelInput_Page";
static const char EDITOR_TYPESLIST_BASEPAGE_NAME[] = "SCEdit_TypesList_Page";

static const char EDITOR_MAINMENU_BASEPAGE_NAME[] = "SCEdit_SelectShortcut_Page";
static const char EDITOR_JAVALIST_BASEPAGE_NAME[] = "SCEdit_SetJava_Page";
static const char EDITOR_DATABROWSER_BASEPAGE_NAME[] = "SCEdit_SelectElf_Page";
static const char EDITOR_EVENTINPUT_BASEPAGE_NAME[] = "SCEdit_EventInput_Page";
static const char EDITOR_SELECTFOLDER_BASEPAGE_NAME[] = "SCEdit_SelectFolder_Page";

int CreateCaptionInput(void *data, BOOK *book);
int CloseCaptionInput(void *data, BOOK *book);
int CreateTypesList(void *data, BOOK *book);
int CloseTypesList(void *data, BOOK *book);
void EditorRun(BOOK *book, int mode);
int pg_SC_Editor_Main_AcceptAction(void *data, BOOK *book);

#endif
