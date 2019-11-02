#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "string.h"
#include "Utils.h"

__arm void runElf(const wchar_t* elfpath, const wchar_t* filepath, const wchar_t* filename)
{
  elfload(elfpath, (void*)filepath, (void*)filename, NULL);
}

void LoadBcfgedit(const wchar_t* bcfgpath, const wchar_t* bcfgname)
{
  runElf(L"/usb/other/ZBin/BcfgEdit.elf", bcfgpath, bcfgname);
}

void GetIconByName(wchar_t* name, int &id)
{
  if( name[0]=='0' && name[1]=='x' )
  {
    id = 0;
    int N = 0x1000;
    for( int i=0;i<4;i++)
    {
      id+=wcharh2int(name[2+i])*N;
      N = N/0x10;
    }
  }
  else
  {
    iconidname2id(name,-1,&id);
  }
}

TEXTID GetJavaName( BOOK* bk )
{
  char s[100];
  TextID_GetString( BookObj_GetSession(bk)->name, s, MAXELEMS(s) );
  
  if ( !strncmp( s, Foreign_app, 11 ) )
  {
    return JavaSession_GetName();
  }
  
  if ( !strcmp( s, Java ) )
  {
    return JavaSession_GetName();
  }
  return 0;
}

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
      mfree(sp);
    }
  }
  JavaDialog_Close(sp1);
}

void ExecuteEvent(wchar_t *name)
{
  int event = wstr2h(name,wstrlen(name));
  UI_Event(event);
}

void OpenFolder(wchar_t * folders)
{
  const wchar_t * path[2];
  path[0] = folders;
  path[1] = 0;

  void* DB_Desc = DataBrowserDesc_Create();
  DataBrowserDesc_SetHeaderText(DB_Desc,TextID_Create(folders, ENC_UCS2, TEXTID_ANY_LEN));
  DataBrowserDesc_SetFolders(DB_Desc,path);
  DataBrowserDesc_SetFoldersNumber(DB_Desc,1);
  DataBrowserDesc_SetSelectAction(DB_Desc,0);
  DataBrowserDesc_Menu_AddFSFunctions(DB_Desc, 0);
  DataBrowserDesc_Menu_AddNewFolder(DB_Desc, 1);
  DataBrowserDesc_Menu_AddMarkFiles(DB_Desc, 1);
  DataBrowser_Create(DB_Desc);
  DataBrowserDesc_Destroy(DB_Desc);
}

LIST* LoadShortcut()
{
  LIST* SC_LIST = List_Create();

  int File = NULL;
  
  FSTAT _fstat;
  if ((fstat(SC_PATH, SC_NAME, &_fstat)) >= 0)
  {
    if ((File = _fopen(SC_PATH, SC_NAME, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >= 0)
    {
      int CaptionLen = 0;
      int sDataLen = 0;
      u16 Count;
      
      fread(File, &Count, sizeof(u16));
      
      int i = 0;
      while(i < Count)
      {
        SHORTCUT *Shortcut = (SHORTCUT*) malloc(sizeof(SHORTCUT));
        fread(File, &Shortcut->Type, sizeof(char));
        fread(File, &sDataLen, sizeof(int));
        Shortcut->sData = WStringAlloc(sDataLen);
        fread(File, Shortcut->sData, sDataLen * sizeof(wchar_t));
        fread(File, &CaptionLen, sizeof(int));
        Shortcut->Caption = WStringAlloc(CaptionLen);
        fread(File, Shortcut->Caption, CaptionLen * sizeof(wchar_t));
        fread(File, &Shortcut->Icon, sizeof(IMAGEID));
        List_InsertLast(SC_LIST, Shortcut);
        i++;
      }
      fclose(File);
    }
  }
  return(SC_LIST);
}
