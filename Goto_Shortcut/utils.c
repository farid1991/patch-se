#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "main.h"
#include "strlib.h"

#ifndef DB3350
#ifndef PNX5320
__arm void StartElf(wchar_t *Name)
{
  elfload(Name, NULL, NULL, NULL);
}
#endif
#endif

#if defined(A1)
void *SHORTCUT_DESC_Init(wchar_t *param)
{
  SHORTCUT_DESC *w_buf = (SHORTCUT_DESC *)malloc(sizeof(SHORTCUT_DESC));
  memset(w_buf, NULL, sizeof(w_buf));
  wstrcpy(w_buf->name, param);
  return (w_buf);
}
#elif defined(A2)
void *SHORTCUT_DESC_A2_Init(wchar_t *param)
{
  SHORTCUT_DESC_A2 *w_buf = (SHORTCUT_DESC_A2 *)malloc(sizeof(SHORTCUT_DESC_A2));
  memset(w_buf, NULL, sizeof(w_buf));
  wstrcpy(w_buf->name, param);
  if (!wstrcmp(w_buf->name, L"MainMenu"))
  {
    w_buf->item_type = SC_Type_MainMenu;
  }
  else
  {
    w_buf->item_type = SC_Type_Standard;
  }
  return (w_buf);
}
#endif

#ifndef DB3350
void StartJava_ByName(wchar_t *name)
{
  int _ASYNC = 1;
  int *ASYNC = &_ASYNC;

  wchar_t *sp;
  char sp1;
  void *Javadesc;

  JavaDialog_Open(0, &sp1, &Javadesc);
  if (!JavaAppDesc_GetFirstApp(Javadesc))
  {
    int result = 0;
    while (!result)
    {
      JavaAppDesc_GetJavaAppInfo(Javadesc, 0, &sp);
      if (!wstrcmp(sp, name))
      {
        int ID = JavaAppDesc_GetJavaAppID(Javadesc);
        char flag;
        REQUEST_UI_OAF_START_APPLICATION(ASYNC, ID + 0x10000, &flag);
        break;
      }
      else
        result = JavaAppDesc_GetNextApp(Javadesc);
      WStringFree(sp);
    }
  }
  JavaDialog_Close(sp1);
}
#endif

void ExecuteEvent(wchar_t *name)
{
  int event = wstr2h(name, wstrlen(name));
  UI_Event(event);
}

void OpenFolder(wchar_t *folders)
{
  BOOK *book = FindBook(IsMyBook);
  if (book)
  {
    int BookID = BookObj_GetBookID(book);
    void *DBDesc = DataBrowserDesc_Create();
    if (DBDesc)
    {
      const wchar_t *Folders[2];
      Folders[0] = folders;
      Folders[1] = 0;
      DataBrowserDesc_SetHeaderText(DBDesc, TextID_Get(folders));
      DataBrowserDesc_SetFolders(DBDesc, Folders);
      DataBrowserDesc_SetFoldersNumber(DBDesc, 1);
      DataBrowserDesc_SetSelectAction(DBDesc, 0);
      DataBrowserDesc_Menu_AddFSFunctions(DBDesc, 0);
      DataBrowserDesc_Menu_AddNewFolder(DBDesc, TRUE);
      DataBrowserDesc_Menu_AddMarkFiles(DBDesc, TRUE);
      DataBrowser_Create(DBDesc);
      DataBrowserDesc_Destroy(DBDesc);
    }
    else
    {
      UI_Event_toBookID(PREVIOUS_EVENT, BookID);
    }
  }
}

void RunShortcut(SC_LIST_ELEM *ShortcutItem)
{
  switch (ShortcutItem->ShortcutType)
  {
  case TYPE_SHORTCUT:
    Shortcut_Run(ShortcutItem->ShortcutLink);
    break;
#ifndef DB3350
  case TYPE_JAVA:
    StartJava_ByName(ShortcutItem->ShortcutLink);
    break;
#ifndef PNX5230
  case TYPE_ELF:
    StartElf(ShortcutItem->ShortcutLink);
    break;
#endif
#endif
  case TYPE_EVENT:
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
  }
}
#ifndef DB3350
void JavaFree(void *item)
{
  JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)item;
  if (elem)
  {
    WStringFree(elem->Name);
    WStringFree(elem->Fullpath);
    if (elem->ImageID)
      ImageID_Free(elem->ImageID);
    mfree(elem);
  }
}

JAVA_LIST_ELEM *CreateElem(void *JavaDesc)
{
  JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)malloc(sizeof(JAVA_LIST_ELEM));
  JavaAppDesc_GetJavaAppInfo(JavaDesc, 0, &elem->Name);
  JavaAppDesc_GetJavaAppInfo(JavaDesc, 5, &elem->Fullpath);
  JavaApp_LogoImageID_Get(elem->Fullpath, &elem->ImageID);
  return (elem);
}

LIST *Create_JavaList()
{
  LIST *java_list = List_Create();

  char sp1;
  wchar_t *sp;
  void *JavaDesc;
  JavaDialog_Open(0, &sp1, &JavaDesc);

  if (!JavaAppDesc_GetFirstApp(JavaDesc))
  {
    int result = 0;
    while (!result)
    {
      JavaAppDesc_GetJavaAppInfo(JavaDesc, 6, &sp);
      if (sp[0])
      {
        List_InsertLast(java_list, CreateElem(JavaDesc));
      }
      WStringFree(sp);
      result = JavaAppDesc_GetNextApp(JavaDesc);
    }
  }
  JavaDialog_Close(sp1);
  return java_list;
}
#endif

void SaveConfig(LIST *List)
{
  int File;

  if ((File = _fopen(F_PATH, F_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IRUSR | FSX_S_IWUSR, 0)) >= 0)
  {
    int CaptionLen = 0;
    int sDataLen = 0;

    fwrite(File, &List->FirstFree, sizeof(uint16_t));

    int i;
    for (i = 0; i < List_GetCount(List); i++)
    {
      SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(List, i);
      fwrite(File, &Shortcut->ShortcutType, sizeof(char));
      sDataLen = WStringLength(Shortcut->ShortcutLink);
      fwrite(File, &sDataLen, sizeof(int));
      fwrite(File, Shortcut->ShortcutLink, sDataLen * sizeof(wchar_t));
      CaptionLen = WStringLength(Shortcut->ShortcutText);
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
  int File = NULL;

  FSTAT _fstat;
  if ((fstat(F_PATH, F_NAME, &_fstat)) >= 0)
  {
    if ((File = _fopen(F_PATH, F_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, 0)) >= 0)
    {
      int CaptionLen = 0;
      int sDataLen = 0;
      u16 Count;

      fread(File, &Count, sizeof(uint16_t));

      int i = 0;
      while (/*Ret->FirstFree*/ i < Count)
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
