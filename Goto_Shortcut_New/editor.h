#ifndef _EDITOR_H_
#define _EDITOR_H

int CreateCaptionInput(void* data, BOOK* book);
int CloseCaptionInput(void* data, BOOK* book);
int CreateTypesList(void* data, BOOK* book);
int CloseTypesList(void* data, BOOK* book);
    
const IMAGEID TypesIcons[TYPE_LAST] =
{
  SHORTCUT_LIST_ICN,
  DB_LIST_JAVA_ICN,
  ENTERTAINMENT_ICN,
  GUI_UNAVAILABLE_ICN,
  DB_LIST_FOLDER_ICN
};

const IMAGEID EditorIcons[2] = 
{
  HPB_OTHER_ICN,
  MENU_SETTINGS_ICN
};

#define EDITOR_MAIN_BASEPAGE_NAME "SC_Editor_Main_Page"
#define EDITOR_CAPTIONINPUT_BASEPAGE_NAME "SC_Editor_LabelInput_Page"
#define EDITOR_TYPESLIST_BASEPAGE_NAME "SC_Editor_TypesList_Page"

#define EDITOR_MAINMENU_BASEPAGE_NAME "SC_Editor_SelectShortcut_Page"
#define EDITOR_JAVALIST_BASEPAGE_NAME "SC_Editor_SetJava_Page"
#define EDITOR_DATABROWSER_BASEPAGE_NAME "SC_Editor_SelectElf_Page"
#define EDITOR_EVENTINPUT_BASEPAGE_NAME "SC_Editor_EventInput_Page"
#define EDITOR_SELECTFOLDER_BASEPAGE_NAME "SC_Editor_SelectFolder_Page"

void EditorRun( BOOK* book, int mode );
int pg_SC_Editor_Main_AcceptAction( void* data, BOOK* book );

#define FREE_JAVAGUI( gui, list, free ) FreeList(list, free); \
  FREE_GUI( gui );

#endif
