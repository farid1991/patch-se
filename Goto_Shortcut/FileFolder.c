#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "main.h"
#include "editor.h"
#include "strlib.h"
#include "FileFolder.h"

BOOL isDirectory(wchar_t *name)
{
  W_FSTAT fs;
  if (w_fstat(name, &fs) != -1)
    return fs.attr & 0x4000;
  else
    return FALSE;
}

FILEDATA *CreateFData()
{
  FILEDATA *fdata = (FILEDATA *)malloc(sizeof(FILEDATA));
  memset(fdata, NULL, sizeof(FILEDATA));
  set_envp(NULL, EMP_FLIST, (OSADDRESS)fdata);
  return fdata;
}

FILEDATA *GetFData()
{
  FILEDATA *fdata = (FILEDATA *)get_envp(NULL, EMP_FLIST);
  if (fdata)
    return fdata;
  return CreateFData();
}

void DeleteFData()
{
  FILEDATA *fdata = GetFData();
  if (fdata)
  {
    mfree(fdata);
    set_envp(NULL, EMP_FLIST, OSADDRESS(NULL));
  }
}

void Free_FLIST(void)
{
  FILEDATA *fdata = GetFData();
  FILELIST *flist = (FILELIST *)fdata->fltop;
  fdata->fltop = NULL;

  while (flist)
  {
    FILELIST *fl_prev = flist;
    mfree(fl_prev->fullpath);
    mfree(fl_prev->str_name);
    flist = (FILELIST *)flist->next;
    mfree(fl_prev);
  }
}

FILELIST *AddToFList(const wchar_t *full_name, const wchar_t *name, BOOL is_folder)
{
  FILEDATA *fdata = GetFData();
  FILELIST *fl_next = (FILELIST *)malloc(sizeof(FILELIST));

  fl_next->fullpath = WStringAlloc(wstrlen(full_name));
  fl_next->str_name = WStringAlloc(wstrlen(name));

  wstrcpy(fl_next->fullpath, full_name);
  wstrcpy(fl_next->str_name, name);
  fl_next->is_folder = is_folder;
  fl_next->next = NULL;

  FILELIST *flist = (FILELIST *)fdata->fltop;
  if (flist)
  {
    FILELIST *fl_prev;
    fl_prev = (FILELIST *)&fdata->fltop;
    while (wstrcmpi(flist->str_name, fl_next->str_name) < 0)
    {
      fl_prev = flist;
      flist = (FILELIST *)flist->next;

      if (!flist)
        break;
    }
    fl_next->next = flist;
    fl_prev->next = fl_next;
  }
  else
  {
    fdata->fltop = fl_next;
  }
  return fl_next;
}

int FindFiles(wchar_t *fpath, int type) // type == 0 SelectFolder, type == 1 SelectFile
{
  int i, c, count = 0;
  Free_FLIST();

  wchar_t *fullpath = WStringAlloc(255);
  wchar_t *fname = WStringAlloc(255);

  wchar_t *rev = NULL, *d = fname, *s = fpath;

  while ((c = *s++))
  {
    *d = c;
    if (c == '/' && *s != '\0')
      rev = d;
    d++;
  }

  if (rev)
  {
    if (rev == fname)
      *(rev + 1) = 0;
    else
      *rev = 0;
    AddToFList(fname, back, ITEM_BACK);
    count++;
  }

  void *dir = w_diropen(fpath);
  if (dir)
  {
    wchar_t *next;
    w_chdir(fpath);
    while ((next = w_dirread(dir)))
    {
      i = wstrlen(fpath);
      wstrcpy(fullpath, fpath);
      if (rev)
      {
        fullpath[i++] = '/';
      }
      wstrcpy(fullpath + i, next);
      if (isDirectory(next))
      {
        if (!wstrncmp(next, IFS, 3))
        {
          wstrnupr(fullpath, 4);
          wstrnupr(next, 4);
        }
        snwprintf(fname, 63, L"/%ls", next);
        AddToFList(fullpath, fname, ITEM_FOLDER);
        count++;
      }
    }
    w_dirclose(dir);
  }
  mfree(fname);
  mfree(fullpath);
  return count;
}

FILELIST *FindFLISTtByNS(int *i, int si)
{
  FILEDATA *fdata = GetFData();

  FILELIST *flist;
  flist = (FILELIST *)fdata->fltop;
  while (flist)
  {
    if (flist->is_folder == si)
    {
      if (!(*i))
        return flist;
      (*i)--;
    }
    flist = (FILELIST *)flist->next;
  }
  return flist;
}

FILELIST *FindFLISTtByN(int n)
{
  FILELIST *flist;
  flist = FindFLISTtByNS(&n, ITEM_BACK);

  if (!n && flist)
    return flist;

  flist = FindFLISTtByNS(&n, ITEM_FOLDER);
  if (!n && flist)
    return flist;

  flist = FindFLISTtByNS(&n, ITEM_FILE);

  if (!n && flist)
    return flist;

  return flist;
}

int OnMessage(GUI_MESSAGE *msg)
{
  TEXTID str = EMPTY_TEXTID;
  FILELIST *flist;
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    flist = FindFLISTtByN(index);
    str = TextID_Get(flist->str_name);
    GUIonMessage_SetMenuItemText(msg, str);

    if (wstrcmp(flist->str_name, back))
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, TypesIcons[TYPE_FOLDER]);

    break;
  }
  return 1;
};

void Self_OnBack(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_FLGUI(mbk->SelectFolder);
  DeleteFData();
}

void Self_onEnterPressed(BOOK *book, GUI *)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  int item = ListMenu_GetSelectedItem(mbk->SelectFolder);
  FILELIST *flist = FindFLISTtByN(item);
  if (!flist)
    return;

  wchar_t *path = WStringAlloc(255);
  if (flist->is_folder == ITEM_FOLDER || flist->is_folder == ITEM_BACK)
  {
    wstrncpy(path, flist->fullpath, 255);
    FREE_FLGUI(mbk->SelectFolder);
    mbk->SelectFolder = CreateFileFolderSelect(mbk, path);
  }
  else
  {
    TEXTID str = TextID_Get(flist->fullpath);
#if defined(DB2000) || defined(DB2010)
    StringInput_DispObject_SetText(GUIObject_GetDispObject(mbk->FolderInput), str);
#else
    StringInput_SetText(mbk->FolderInput, str);
#endif
    FREE_FLGUI(mbk->SelectFolder);
    DeleteFData();
  }
  mfree(path);
}

void Self_onSelectPressed(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  int item = ListMenu_GetSelectedItem(mbk->SelectFolder);

  FILELIST *flist = FindFLISTtByN(item);
  if (!flist)
    return;

  if ((flist->is_folder == ITEM_FOLDER && mbk->FType == SEL_FOLDER) || flist->is_folder == ITEM_FILE)
  {
    TEXTID str = TextID_Get(flist->fullpath);
#if defined(DB2000) || defined(DB2010)
    StringInput_DispObject_SetText(GUIObject_GetDispObject(mbk->FolderInput), str);
#else
    StringInput_SetText(mbk->FolderInput, str);
#endif
    FREE_FLGUI(mbk->SelectFolder);
    DeleteFData();
  }
}

GUI_LIST *CreateFileFolderSelect(BOOK *book, wchar_t *str)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

  wchar_t *ustr = WStringAlloc(255);
  wchar_t *s;

  wstrcpy(ustr, str);
  str = ustr;

  int f = 0;
  do
  {
    if (isDirectory(ustr))
    {
      f = 1;
      break;
    }
    s = wstrrchr(ustr, L'/');

    if (s == ustr)
      break;

    if (s)
      *s = 0;
  } while (s);

  if (!f)
    str = L"/";

  int count = FindFiles(str, mbk->FType);

  GUI_LIST *f_list_gui = CreateListMenu(mbk, UIDisplay_Main);
  GUIObject_SetTitleText(f_list_gui, TextID_Get(str));
  ListMenu_SetItemCount(f_list_gui, count);
  ListMenu_SetCursorToItem(f_list_gui, ITEM_BACK);
  ListMenu_SetOnMessage(f_list_gui, OnMessage);
  GUIObject_SoftKeys_SetText(f_list_gui, ACTION_SELECT1, OPEN_TXT);
  GUIObject_SoftKeys_SetAction(f_list_gui, ACTION_SELECT1, Self_onEnterPressed);
  GUIObject_SoftKeys_SetText(f_list_gui, 1, SELECT_TXT);
  GUIObject_SoftKeys_SetAction(f_list_gui, 1, Self_onSelectPressed);
  GUIObject_SoftKeys_SetAction(f_list_gui, ACTION_BACK, Self_OnBack);
  GUIObject_Show(f_list_gui);

  mfree(ustr);
  return f_list_gui;
}
