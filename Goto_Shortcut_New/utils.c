#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "strlib.h"

__arm void StartElf(wchar_t *Name)
{
  elfload(Name,NULL,NULL,NULL);
}

#ifdef A2
void* SHORTCUT_DESC_A2_Init(wchar_t * param)
{
  SHORTCUT_DESC_A2* w_buf = (SHORTCUT_DESC_A2*)malloc(sizeof(SHORTCUT_DESC_A2));
  memset( w_buf, NULL, sizeof(w_buf) );
  wstrcpy( w_buf->name, param );
  if (!wstrcmp( w_buf->name, MAIN_MENU ))
  {
    w_buf->item_type = SC_Type_MainMenu;
  }
  else
  {
    w_buf->item_type = SC_Type_Standard;
  }
  return(w_buf);
}
#endif

void StartJava_ByName(wchar_t* name)
{
  int _ASYNC = 1;
  int *ASYNC =&_ASYNC;
      
  wchar_t* sp;
  char sp1;
  void* Javadesc;
  
  JavaDialog_Open(0, &sp1, &Javadesc);
  if (!JavaAppDesc_GetFirstApp(Javadesc))
  {
    int result = 0;
    while(!result)
    {
      JavaAppDesc_GetJavaAppInfo(Javadesc, 0, &sp);
      if (!wstrcmp(sp,name))
      {
        int ID = JavaAppDesc_GetJavaAppID(Javadesc);
        char flag;
        REQUEST_UI_OAF_START_APPLICATION(ASYNC, ID+0x10000, &flag);
        break;
      }
      else result = JavaAppDesc_GetNextApp(Javadesc);
      StringFree(sp);
    }
  }
  JavaDialog_Close(sp1);
}


void ExecuteEvent(wchar_t *name)
{
  int event = wstr2h(name,wstrlen(name));
  UI_Event(event);
}

void OpenFolger(wchar_t * folders)
{
  const wchar_t * path[2];
  path[0] = folders;
  path[1] = 0;
    
  void* Folder_Desc = DataBrowserDesc_Create();
  DataBrowserDesc_SetHeaderText(Folder_Desc,TextID_Create(folders, ENC_UCS2, TEXTID_ANY_LEN));
  DataBrowserDesc_SetFolders(Folder_Desc,path);
  DataBrowserDesc_SetFoldersNumber(Folder_Desc,1);
  DataBrowserDesc_SetSelectAction(Folder_Desc,0);
  DataBrowserDesc_Menu_AddFSFunctions(Folder_Desc, 0);
  DataBrowserDesc_Menu_AddNewFolder(Folder_Desc, 1);
  DataBrowserDesc_Menu_AddMarkFiles(Folder_Desc, 1);
  DataBrowser_Create(Folder_Desc);
  DataBrowserDesc_Destroy(Folder_Desc);
}

void RunShortcut(SHORTCUT *Shortcut)
{
  switch(Shortcut->Type)
  {
  case TYPE_SHORTCUT:
    Shortcut_Run(Shortcut->sData);
    break;
  case TYPE_JAVA:
    StartJava_ByName(Shortcut->sData);
    break;
  case TYPE_ELF:
    StartElf(Shortcut->sData);
    break;
  case TYPE_EVENT:
    ExecuteEvent(Shortcut->sData);
    break;
  case TYPE_FOLDER:
    OpenFolger(Shortcut->sData);
    break;
  }
}

int ItemFilter(void* elem)
{
  return(elem != NULL);
}

void FreeList(LIST* &List, void (*FreeProc)(void *Item))
{
  if (List)
  {
    List_DestroyElements(List, ItemFilter, FreeProc);
    List_Destroy(List);
  }
}

void JavaFree(void* item)
{
  JAVA_LIST_ELEM* elem = (JAVA_LIST_ELEM*)item;
  if(elem)
  {
    StringFree(elem->Name);
    StringFree(elem->Fullpath);
    if (elem->ImageID) ImageID_Free(elem->ImageID);
    mfree(elem);
  }
}

JAVA_LIST_ELEM* CreateElem(void* JavaDesc)
{
  JAVA_LIST_ELEM* elem = (JAVA_LIST_ELEM*)malloc(sizeof(JAVA_LIST_ELEM));
  JavaAppDesc_GetJavaAppInfo(JavaDesc, 0, &elem->Name);
  JavaAppDesc_GetJavaAppInfo(JavaDesc, 5, &elem->Fullpath);
  JavaApp_LogoImageID_Get(elem->Fullpath, &elem->ImageID);
  return(elem);
}

LIST* Create_JavaList()
{
  LIST* java_list = List_Create();
  
  char sp1;
  wchar_t* sp;
  void* JavaDesc;
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
      StringFree(sp);
      result = JavaAppDesc_GetNextApp(JavaDesc);
    }
  }
  JavaDialog_Close(sp1);
  return java_list;
}

void SaveConfig(LIST *List)
{
  int File;
  
  if ((File = _fopen(F_PATH, F_NAME, FSX_O_TRUNC|FSX_O_RDWR, FSX_S_IRUSR|FSX_S_IWUSR, 0)) >= 0)
  {
    int CaptionLen = 0;
    int sDataLen = 0;
    
    fwrite(File, &List->FirstFree, sizeof(u16));
    
    int i;
    for (i = 0; i < List->FirstFree; i++)
    {
      SHORTCUT* Shortcut = (SHORTCUT*)List_Get(List, i);
      fwrite(File, &Shortcut->Type, sizeof(char));
      sDataLen = StringLength(Shortcut->sData);
      fwrite(File, &sDataLen, sizeof(int));
      fwrite(File, Shortcut->sData, sDataLen * sizeof(wchar_t));
      CaptionLen = StringLength(Shortcut->Caption);
      fwrite(File, &CaptionLen, sizeof(int));
      fwrite(File, Shortcut->Caption, CaptionLen * sizeof(wchar_t));
      fwrite(File, &Shortcut->Icon, sizeof(IMAGEID));
    }
    fclose(File);
  }
}

LIST* LoadConfig()
{
  LIST* Ret = List_Create();
  int File = NULL;
  
  FSTAT _fstat;
  if ((fstat(F_PATH, F_NAME, &_fstat)) >= 0)
  {
    if ((File = _fopen(F_PATH, F_NAME, FSX_O_RDONLY, FSX_S_IRUSR|FSX_S_IWUSR, 0)) >= 0)
    {
      int CaptionLen = 0;
      int sDataLen = 0;
      u16 Count;
      
      fread(File, &Count, sizeof(u16));
      
      int i = 0;
      while(/*Ret->FirstFree*/ i < Count)
      {
        SHORTCUT* Shortcut = (SHORTCUT*)malloc(sizeof(SHORTCUT));
        fread(File, &Shortcut->Type, sizeof(char));
        fread(File, &sDataLen, sizeof(int));
        Shortcut->sData = StringAlloc(sDataLen);
        fread(File, Shortcut->sData, sDataLen * sizeof(wchar_t));
        fread(File, &CaptionLen, sizeof(int));
        Shortcut->Caption = StringAlloc(CaptionLen);
        fread(File, Shortcut->Caption, CaptionLen * sizeof(wchar_t));
        fread(File, &Shortcut->Icon, sizeof(IMAGEID));
        List_InsertLast(Ret, Shortcut);
        i++;
      }
      fclose(File);
    }
  }
  return(Ret);
}
