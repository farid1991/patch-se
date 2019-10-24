#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "editor.h"
#include "strlib.h"
#include "FileFolder.h"

F_DATA* CreateFData()
{
  F_DATA* fdata = (F_DATA*)malloc(sizeof(F_DATA));
  memset(fdata, NULL, sizeof(F_DATA));
  set_envp(NULL, EMP_NAME, (OSADDRESS)fdata);
  return fdata;
}

F_DATA* GetFData()
{
  F_DATA* fdata = (F_DATA*)get_envp(NULL, EMP_NAME);
  if (fdata) return fdata;
  return CreateFData();
}

void DeleteFData()
{
  F_DATA* fdata = (F_DATA*)get_envp(NULL, EMP_NAME);
  if (fdata)
  {
    mfree(fdata);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void Free_FLIST( void )
{
  F_DATA* fdata = GetFData();
  FLIST* fl = (FLIST*) fdata->fltop;
  fdata->fltop = NULL;
  
  while( fl )
  {
    FLIST* fl_prev = fl;
    StringFree( fl_prev->fullname );
    StringFree( fl_prev->name );
    fl = (FLIST*) fl->next;
    mfree( fl_prev);
  }
}

FLIST* AddToFList( const wchar_t* full_name, const wchar_t* name, int is_folder )
{
  // int l_fname;
  F_DATA* fdata = GetFData();
  
  FLIST* fl;
  FLIST* fn = (FLIST*)malloc(sizeof(FLIST));
  
  fn->fullname = StringAlloc(wstrlen( full_name ));
  
  fn->name = StringAlloc(wstrlen( name ));
  
  wstrcpy( fn->fullname, full_name );
  wstrcpy( fn->name, name );
  fn->is_folder = is_folder;
  fn->next = 0;
  fl = (FLIST*) fdata->fltop;
  if ( fl )
  {
    FLIST* pr;
    pr = (FLIST*) &fdata->fltop;
    while( wstrcmpi( fl->name, fn->name ) < 0 )
    {
      pr = fl;
      fl = (FLIST*) fl->next;
      
      if ( !fl )
        break;
    }
    fn->next = fl;
    pr->next = fn;
  }
  else
  {
    fdata->fltop = fn;
  }
  return fn;
}

int FindFiles( wchar_t* str, int type ) // type == 0 SelectFolder, type == 1 SelectFile
{
  int i, c, n = 0;
  Free_FLIST();
  
  wchar_t* path = StringAlloc(255);
  wchar_t* name = StringAlloc(63);
  
  wchar_t* rev = NULL, * d = name, * s = str;
  
  while( ( c = *s++ ) )
  {
    *d = c;
    if ( c == '/' &&* s!= '\0' ) rev = d;
    d++;
  }
  if( rev )
  {
    if ( rev == name ) // ???? ???? ?? ??????
      * ( rev + 1 ) = 0;
    else
      * rev = 0;
    AddToFList( name, back, IS_BACK );
    n++;
  }
  void* dir = w_diropen( str );
  if ( dir )
  {
    wchar_t* next;
    w_chdir( str );
    while( ( next = w_dirread( dir ) ) )
    {
      W_FSTAT fs;
      w_fstat( next, &fs );
      i = wstrlen( str );
      wstrcpy( path, str );
      if ( rev )
      {
        path[ i++ ] = '/';
      }
      wstrcpy( path + i, next );
      if ( fs.attr&0x4000 )
      {
        snwprintf( name, 63, L"/%ls", next );
        AddToFList( path, name, IS_FOLDER );
        n++;
      }
      else
      {
        if ( type == SFILE )
        {
          AddToFList( path, next, IS_FILE );
          n++;
        }
      }
    }
    w_dirclose( dir );
  }
  StringFree( name );
  StringFree( path );
  return n;
}

FLIST* FindFLISTtByNS( int* i, int si )
{
  F_DATA* fdata = GetFData();
  
  FLIST* fl;
  fl = (FLIST*) fdata->fltop;
  while( fl )
  {
    if ( fl->is_folder == si )
    {
      if ( !(*i) )
        return fl;
      (*i)--;
    }
    fl = (FLIST*) fl->next;
  }
  return fl;
}

FLIST* FindFLISTtByN( int n )
{
  FLIST* fl;
  fl = FindFLISTtByNS( &n, IS_BACK );
 
  if ( !n && fl )
    return fl;

  fl = FindFLISTtByNS( &n, IS_FOLDER );
  if ( !n && fl )
    return fl;

  fl = FindFLISTtByNS( &n, IS_FILE );
  
  if ( !n && fl )
    return fl;
  
  return fl;
}


int OnMessage( GUI_MESSAGE* msg )
{
  TEXTID str = EMPTY_TEXTID;
  FLIST* fl;
  switch( GUIonMessage_GetMsg( msg ) )
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex( msg );
    fl = FindFLISTtByN( index );
    str = TextID_Get( fl->name );
    GUIonMessage_SetMenuItemText( msg, str );
    
    if(wstrcmp(fl->name,back))
      GUIonMessage_SetMenuItemIcon(msg, 0, TypesIcons[TYPE_FOLDER]);

    break;
  }
  return 1;
};

void Self_OnBack( BOOK* book, GUI* gui )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FREE_FLGUI( mbk->SelectFolder );
  DeleteFData();
}

void Self_onEnterPressed( BOOK* book, GUI* )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  int item = ListMenu_GetSelectedItem( mbk->SelectFolder );
  FLIST* fl = FindFLISTtByN( item );
  if ( fl )
  {
    wchar_t* path = StringAlloc(255);
    if ( fl->is_folder == IS_FOLDER || fl->is_folder == IS_BACK )
    {
      wstrncpy( path, fl->fullname, 255 );
      FREE_FLGUI( mbk->SelectFolder );
      mbk->SelectFolder = CreateFileFolderSelect( mbk, path );
    }
    else
    {
      TEXTID str = TextID_Get( fl->fullname );
      StringInput_DispObject_SetText( GUIObject_GetDispObject( mbk->FolderInput ), str );
      FREE_FLGUI( mbk->SelectFolder );
      DeleteFData();
    }
    StringFree( path );
  }
}

void Self_onSelectPressed( BOOK* book, GUI* gui )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  int item = ListMenu_GetSelectedItem( mbk->SelectFolder );
  
  FLIST* fl = FindFLISTtByN( item );
  if ( fl )
  {
    if ( ( fl->is_folder == IS_FOLDER && mbk->FType == SFOLDER ) || fl->is_folder == IS_FILE )
    {
      TEXTID str = TextID_Get( fl->fullname );
      StringInput_DispObject_SetText( GUIObject_GetDispObject( mbk->FolderInput ), str );
      FREE_FLGUI( mbk->SelectFolder );
      DeleteFData();
    }
  }
}

int isdir( wchar_t* name )
{
  W_FSTAT fs;
  if ( w_fstat( name, &fs )!= - 1 )
    return fs.attr&0x4000;
  else return 0;
}

GUI_LIST* CreateFileFolderSelect( BOOK* book, wchar_t* str )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  
  wchar_t* ustr = StringAlloc(255);
  wchar_t* s;
  GUI_LIST* f_list_gui;
  int n;
  
  wstrcpy( ustr, str );
  str = ustr;
  
  int f = 0;
  do 
  {
    if ( isdir( ustr ) )
    {
      f = 1;
      break;
    }
    s = wstrrchr( ustr, L'/' );

    if ( s == ustr )
      break;

    if ( s )
      *s = 0;
  }while( s );

  if ( !f )
    str = L"/";
  
  n = FindFiles( str, mbk->FType );
  
  f_list_gui = CreateListMenu( mbk, UIDisplay_Main );
  GUIObject_SetTitleText( f_list_gui, TextID_Get(str) ); //SELECT_FOLDER_TXT );
  ListMenu_SetItemCount( f_list_gui, n );
  ListMenu_SetCursorToItem( f_list_gui, 0 );
  ListMenu_SetOnMessage( f_list_gui, OnMessage );
  GUIObject_SoftKeys_SetActionAndText( f_list_gui, ACTION_SELECT1, Self_onEnterPressed, OPEN_TXT );
  GUIObject_SoftKeys_SetActionAndText( f_list_gui, 1, Self_onSelectPressed, SELECT_TXT );
  GUIObject_SoftKeys_SetAction( f_list_gui, ACTION_BACK, Self_OnBack );
  GUIObject_Show( f_list_gui );
  
  StringFree( ustr );
  return f_list_gui;
}

