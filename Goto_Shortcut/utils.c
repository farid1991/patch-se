#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "strlib.h"
#include "utils.h"

#ifdef HAS_ELF
__arm void StartElf(wchar_t *elfname)
{
  elfload(elfname, NULL, NULL, NULL);
}
#endif

void *SHORTCUT_DESC_Init(wchar_t *param)
{
#if defined(A1)
  SHORTCUT_DESC *desc = (SHORTCUT_DESC *)malloc(sizeof(SHORTCUT_DESC));
  memset(desc, NULL, sizeof(SHORTCUT_DESC));
  wstrcpy(desc->name, param);
  desc->shortcut_state = !wstrcmp(desc->name, L"MainMenu") ? SC_State_MainMenu : SC_State_Activated;
  return desc;
#elif defined(A2)
  SHORTCUT_DESC_A2 *desc = (SHORTCUT_DESC_A2 *)malloc(sizeof(SHORTCUT_DESC_A2));
  memset(desc, NULL, sizeof(SHORTCUT_DESC_A2));
  wstrcpy(desc->name, param);
  desc->item_type = !wstrcmp(desc->name, L"MainMenu") ? SC_Type_MainMenu : SC_Type_Standard;
  return desc;
#endif
}

#ifdef USE_JAVA
void StartJava_ByName(wchar_t *name)
{
  wchar_t *buff;
  char java_dialog;
  void *java_desc;

  JavaDialog_Open(0, &java_dialog, &java_desc);

  if (!JavaAppDesc_GetFirstApp(java_desc))
  {
    int next = 0;
    while (!next)
    {
      JavaAppDesc_GetJavaAppInfo(java_desc, JAVA_APP_NAME, &buff);
      if (!wstrcmp(buff, name))
      {
        int app_id = JavaAppDesc_GetJavaAppID(java_desc);
        char flag;

        int _ASYNC = 1;
        int *ASYNC = &_ASYNC;
        REQUEST_UI_OAF_START_APPLICATION(ASYNC, app_id + 0x10000, &flag);
        break;
      }
      else
      {
        next = JavaAppDesc_GetNextApp(java_desc);
      }
      mfree(buff);
    }
  }
  JavaDialog_Close(java_dialog);
}
#endif

void ExecuteEvent(wchar_t *name)
{
  int event = wstr2h(name, wstrlen(name));
  UI_Event(event);
}

void OpenFolder(const wchar_t *folders)
{
  BOOK *book = Display_GetTopBook(UIDisplay_Main);//FindBook(IsGotoShortcutBook);
  if (!book)
    return;

  int bookID = BookObj_GetBookID(book);

  if (void *DBDesc = DataBrowserDesc_Create())
  {
    const wchar_t *Folders[2];
    Folders[0] = folders;
    Folders[1] = NULL;
    DataBrowserDesc_SetHeaderText(DBDesc, TextID_Get(folders));
    DataBrowserDesc_SetBookID(DBDesc, bookID);
    DataBrowserDesc_SetFolders(DBDesc, Folders);
    DataBrowserDesc_SetFoldersNumber(DBDesc, 1);
    DataBrowserDesc_SetSelectAction(DBDesc, 1);
    DataBrowserDesc_SetSelectActionOnFolders(DBDesc, 1);
    DataBrowserDesc_Menu_AddFSFunctions(DBDesc, 0);
    DataBrowserDesc_Menu_AddNewFolder(DBDesc, TRUE);
    DataBrowserDesc_Menu_AddMarkFiles(DBDesc, TRUE);
#ifndef DB2000
    DataBrowserDesc_SetOpenEmptyFolder(DBDesc, TRUE);
#endif
    char actions[4];
    actions[0] = DB_CMD_RUN;
    actions[1] = DB_CMD_DELETE;
    actions[2] = DB_CMD_LAST;
    DataBrowserDesc_SetActions(DBDesc, actions);
  
    DataBrowser_Create(DBDesc);
    DataBrowserDesc_Destroy(DBDesc);
  }
  else
  {
    UI_Event_toBookID(PREVIOUS_EVENT, bookID);
  }
}

void RunShortcut(SC_LIST_ELEM *ShortcutItem)
{
  switch (ShortcutItem->ShortcutType)
  {
  case TYPE_SHORTCUT:
    Shortcut_Run(ShortcutItem->ShortcutLink);
    break;
#ifdef USE_JAVA
  case TYPE_JAVA:
    StartJava_ByName(ShortcutItem->ShortcutLink);
    break;
#endif
#ifdef HAS_ELF
  case TYPE_ELF:
    StartElf(ShortcutItem->ShortcutLink);
    break;
#endif
  case TYPE_UIEVENT:
    ExecuteEvent(ShortcutItem->ShortcutLink);
    break;
  case TYPE_FOLDER:
    OpenFolder(ShortcutItem->ShortcutLink);
    break;
  }
}

int list_item_filter(void *elem)
{
  return (elem != NULL);
}

void list_destroy(LIST *&list, void (*list_free_elem)(void *item))
{
  if (list)
  {
    List_DestroyElements(list, list_item_filter, list_free_elem);
    List_Destroy(list);
    list = NULL;
  }
}

#ifdef USE_JAVA
void java_list_free_item(void *item)
{
  JAVA_LIST_ELEM *j_elem = (JAVA_LIST_ELEM *)item;
  if (j_elem)
  {
    mfree(j_elem->name);
    mfree(j_elem->fullpath);

    if (j_elem->image_id != NOIMAGE)
      ImageID_Free(j_elem->image_id);

    mfree(j_elem);
  }
}

JAVA_LIST_ELEM *java_list_create_elem(void *java_desc)
{
  JAVA_LIST_ELEM *j_elem = (JAVA_LIST_ELEM *)malloc(sizeof(JAVA_LIST_ELEM));
  JavaAppDesc_GetJavaAppInfo(java_desc, JAVA_APP_NAME, &j_elem->name);
  JavaAppDesc_GetJavaAppInfo(java_desc, JAVA_APP_FULLPATH, &j_elem->fullpath);
  JavaApp_LogoImageID_Get(j_elem->fullpath, &j_elem->image_id);
  return j_elem;
}

LIST *java_list_create()
{
  LIST *java_list = List_Create();

  char java_dialog;
  wchar_t *semclet;
  void *java_desc;

  JavaDialog_Open(0, &java_dialog, &java_desc);

  if (!JavaAppDesc_GetFirstApp(java_desc))
  {
    int next = 0;
    while (!next)
    {
      JavaAppDesc_GetJavaAppInfo(java_desc, JAVA_APP_SEMCLET, &semclet);
      if (semclet[0])
      {
        List_InsertLast(java_list, java_list_create_elem(java_desc));
      }
      mfree(semclet);
      next = JavaAppDesc_GetNextApp(java_desc);
    }
  }
  JavaDialog_Close(java_dialog);
  return java_list;
}
#endif

void SaveConfig(LIST *list)
{
  int file = _fopen(F_PATH, CONFIG_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IRUSR | FSX_S_IWUSR, NULL);

  if (file >= 0)
  {
    int text_len = 0;
    int link_len = 0;
    uint16_t list_count = List_GetCount(list);

    fwrite(file, &list_count, sizeof(uint16_t));

    for (int i = 0; i < list_count; i++)
    {
      SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(list, i);
      fwrite(file, &Shortcut->ShortcutType, sizeof(char));
      link_len = wstrlen(Shortcut->ShortcutLink);
      fwrite(file, &link_len, sizeof(int));
      fwrite(file, Shortcut->ShortcutLink, link_len * sizeof(wchar_t));
      text_len = wstrlen(Shortcut->ShortcutText);
      fwrite(file, &text_len, sizeof(int));
      fwrite(file, Shortcut->ShortcutText, text_len * sizeof(wchar_t));
      fwrite(file, &Shortcut->ShortcutIcon, sizeof(IMAGEID));
    }
    fclose(file);
  }
}

LIST *LoadConfig()
{
  LIST *list = List_Create();

  if (FSX_IsFileExists(F_PATH, CONFIG_NAME))
  {
    int file = _fopen(F_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
    if (file >= 0)
    {
      int text_len = 0;
      int link_len = 0;
      uint16_t list_count;

      fread(file, &list_count, sizeof(uint16_t));

      int i = 0;
      while (i < list_count)
      {
        SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)malloc(sizeof(SC_LIST_ELEM));
        fread(file, &Shortcut->ShortcutType, sizeof(char));
        fread(file, &link_len, sizeof(int));
        Shortcut->ShortcutLink = WStringAlloc(link_len);
        fread(file, Shortcut->ShortcutLink, link_len * sizeof(wchar_t));
        fread(file, &text_len, sizeof(int));
        Shortcut->ShortcutText = WStringAlloc(text_len);
        fread(file, Shortcut->ShortcutText, text_len * sizeof(wchar_t));
        fread(file, &Shortcut->ShortcutIcon, sizeof(IMAGEID));
        List_InsertLast(list, Shortcut);
        i++;
      }
      fclose(file);
    }
  }
  return (list);
}
