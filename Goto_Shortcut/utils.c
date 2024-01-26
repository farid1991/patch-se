#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "main.h"
#include "strlib.h"
#include "utils.h"

#ifdef HAS_ELF
__arm void StartElf(wchar_t *Name)
{
  elfload(Name, NULL, NULL, NULL);
}
#endif

#if defined(A1)
void *SHORTCUT_DESC_Init(wchar_t *param)
{
  SHORTCUT_DESC *desc = (SHORTCUT_DESC *)malloc(sizeof(SHORTCUT_DESC));
  memset(desc, NULL, sizeof(SHORTCUT_DESC));
  wstrcpy(desc->name, param);
  if (!wstrcmp(desc->name, L"MainMenu"))
  {
    desc->shortcut_state = SC_State_MainMenu;
  }
  else
  {
    desc->shortcut_state = SC_State_Activated;
  }
  return (desc);
}
#elif defined(A2)
void *SHORTCUT_DESC_A2_Init(wchar_t *param)
{
  SHORTCUT_DESC_A2 *desc = (SHORTCUT_DESC_A2 *)malloc(sizeof(SHORTCUT_DESC_A2));
  memset(desc, NULL, sizeof(SHORTCUT_DESC_A2));
  wstrcpy(desc->name, param);
  if (!wstrcmp(desc->name, L"MainMenu"))
  {
    desc->item_type = SC_Type_MainMenu;
  }
  else
  {
    desc->item_type = SC_Type_Standard;
  }
  return (desc);
}
#endif

#ifdef USE_JAVA
void StartJava_ByName(wchar_t *name)
{
  wchar_t *buff;
  char jDialog;
  void *Javadesc;

  JavaDialog_Open(0, &jDialog, &Javadesc);
  if (!JavaAppDesc_GetFirstApp(Javadesc))
  {
    int result = 0;
    while (!result)
    {
      JavaAppDesc_GetJavaAppInfo(Javadesc, JAVA_APP_NAME, &buff);
      if (!wstrcmp(buff, name))
      {
        int AppID = JavaAppDesc_GetJavaAppID(Javadesc);
        char flag;

        int _ASYNC = 1;
        int *ASYNC = &_ASYNC;
        REQUEST_UI_OAF_START_APPLICATION(ASYNC, AppID + 0x10000, &flag);
        break;
      }
      else
      {
        result = JavaAppDesc_GetNextApp(Javadesc);
      }
      mfree(buff);
    }
  }
  JavaDialog_Close(jDialog);
}
#endif

void ExecuteEvent(wchar_t *name)
{
  int event = wstr2h(name, wstrlen(name));
  UI_Event(event);
}

void OpenFolder(const wchar_t *folders)
{
  BOOK *book = FindBook(IsGotoShortcutBook);
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
    DataBrowserDesc_SetSelectAction(DBDesc, 0);
    DataBrowserDesc_Menu_AddFSFunctions(DBDesc, TRUE);
    DataBrowserDesc_Menu_AddNewFolder(DBDesc, TRUE);
    DataBrowserDesc_Menu_AddMarkFiles(DBDesc, TRUE);
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

int ItemFilter(void *elem)
{
  return (elem != NULL);
}

void FreeList(LIST *&List, void (*FreeProc)(void *Item))
{
  if (List)
  {
    List_DestroyElements(List, ItemFilter, FreeProc);
    List_Destroy(List);
    List = NULL;
  }
}

#ifdef USE_JAVA
void JavaFree(void *item)
{
  JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)item;
  if (elem)
  {
    mfree(elem->name);
    mfree(elem->fullpath);
    if (elem->image_id)
      ImageID_Free(elem->image_id);
    mfree(elem);
  }
}

JAVA_LIST_ELEM *CreateElem(void *JavaDesc)
{
  JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)malloc(sizeof(JAVA_LIST_ELEM));
  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_NAME, &elem->name);
  JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_FULLPATH, &elem->fullpath);
  JavaApp_LogoImageID_Get(elem->fullpath, &elem->image_id);
  return elem;
}

LIST *Create_JavaList()
{
  LIST *java_list = List_Create();

  char jDialog;
  wchar_t *semclet;
  void *JavaDesc;
  JavaDialog_Open(0, &jDialog, &JavaDesc);

  if (!JavaAppDesc_GetFirstApp(JavaDesc))
  {
    int result = 0;
    while (!result)
    {
      JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVA_APP_SEMCLET, &semclet);
      if (semclet[0])
      {
        List_InsertLast(java_list, CreateElem(JavaDesc));
      }
      WStringFree(semclet);
      result = JavaAppDesc_GetNextApp(JavaDesc);
    }
  }
  JavaDialog_Close(jDialog);
  return java_list;
}
#endif

void SaveConfig(LIST *List)
{
  int File = _fopen(F_PATH, CONFIG_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IRUSR | FSX_S_IWUSR, NULL);

  if (File >= 0)
  {
    int CaptionLen = 0;
    int sDataLen = 0;

    fwrite(File, &List->FirstFree, sizeof(uint16_t));

    int i;
    for (i = 0; i < List_GetCount(List); i++)
    {
      SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(List, i);
      fwrite(File, &Shortcut->ShortcutType, sizeof(char));
      sDataLen = wstrlen(Shortcut->ShortcutLink);
      fwrite(File, &sDataLen, sizeof(int));
      fwrite(File, Shortcut->ShortcutLink, sDataLen * sizeof(wchar_t));
      CaptionLen = wstrlen(Shortcut->ShortcutText);
      fwrite(File, &CaptionLen, sizeof(int));
      fwrite(File, Shortcut->ShortcutText, CaptionLen * sizeof(wchar_t));
      fwrite(File, &Shortcut->ShortcutIcon, sizeof(IMAGEID));
    }
    fclose(File);
  }
}

LIST *LoadConfig()
{
  LIST *Ret = List_Create();

  if (FSX_IsFileExists(F_PATH, CONFIG_NAME))
  {
    int File = _fopen(F_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
    if (File >= 0)
    {
      int CaptionLen = 0;
      int sDataLen = 0;
      u16 Count;

      fread(File, &Count, sizeof(uint16_t));

      int i = 0;
      while (i < Count)
      {
        SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)malloc(sizeof(SC_LIST_ELEM));
        fread(File, &Shortcut->ShortcutType, sizeof(char));
        fread(File, &sDataLen, sizeof(int));
        Shortcut->ShortcutLink = WStringAlloc(sDataLen);
        fread(File, Shortcut->ShortcutLink, sDataLen * sizeof(wchar_t));
        fread(File, &CaptionLen, sizeof(int));
        Shortcut->ShortcutText = WStringAlloc(CaptionLen);
        fread(File, Shortcut->ShortcutText, CaptionLen * sizeof(wchar_t));
        fread(File, &Shortcut->ShortcutIcon, sizeof(IMAGEID));
        List_InsertLast(Ret, Shortcut);
        i++;
      }
      fclose(File);
    }
  }
  return (Ret);
}
