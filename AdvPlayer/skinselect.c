#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "data.h"
#include "main.h"
#include "skinselect.h"
#include "StrLib.h"

void Free_FLIST(void)
{
  ADVPLAYER_DATA *data = GetData();
  FILELIST *flist = (FILELIST *)data->fltop;
  data->fltop = NULL;

  while (flist)
  {
    FILELIST *fl_prev = flist;
    WStringFree(fl_prev->fullname);
    WStringFree(fl_prev->name);
    flist = (FILELIST *)flist->next;
    mfree(fl_prev);
  }
}

FILELIST *AddToFList(const wchar_t *full_name, const wchar_t *name, bool is_folder)
{
  ADVPLAYER_DATA *data = GetData();

  FILELIST *flist;
  FILELIST *fl_next = (FILELIST *)malloc(sizeof(FILELIST));

  fl_next->fullname = WStringAlloc(wstrlen(full_name));
  fl_next->name = WStringAlloc(wstrlen(name));

  wstrcpy(fl_next->fullname, full_name);
  wstrcpy(fl_next->name, name);
  fl_next->is_folder = is_folder;
  fl_next->next = NULL;
  flist = (FILELIST *)data->fltop;
  if (flist)
  {
    FILELIST *fl_prev;
    fl_prev = (FILELIST *)&data->fltop;
    while (wstrcmpi(flist->name, fl_next->name) < 0)
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
    data->fltop = fl_next;
  }
  return fl_next;
}

int FindFiles(wchar_t *str, int type) // type == 0 SelectFolder, type == 1 SelectFile
{
  int i, c, n = 0;
  Free_FLIST();

  wchar_t *path = WStringAlloc(255);
  wchar_t *name = WStringAlloc(255);

  wchar_t *rev = NULL, *d = name, *s = str;

  while ((c = *s++))
  {
    *d = c;
    if (c == '/' && *s != '\0')
      rev = d;
    d++;
  }
  if (rev)
  {
    if (rev == name)
      *(rev + 1) = 0;
    else
      *rev = 0;
  }
  void *dir = w_diropen(str);
  if (dir)
  {
    wchar_t *next;
    w_chdir(str);
    while ((next = w_dirread(dir)))
    {
      W_FSTAT fstat;
      w_fstat(next, &fstat);
      i = wstrlen(str);
      wstrcpy(path, str);
      if (rev)
      {
        path[i++] = '/';
      }
      wstrcpy(path + i, next);
      if (fstat.attr & FSX_O_CHKPATH)
      {
        snwprintf(name, 63, L"%ls", next);
        AddToFList(path, name, ITEM_FOLDER);
        n++;
      }
    }
    w_dirclose(dir);
  }
  WStringFree(name);
  WStringFree(path);
  return n;
}

FILELIST *FindFLISTtByNS(int *i, int si)
{
  ADVPLAYER_DATA *fdata = GetData();

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

int SkinSelect_OnMessage(GUI_MESSAGE *msg)
{
  FILELIST *flist;
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    flist = FindFLISTtByN(index);
    TEXTID str = TextID_Create(flist->name, ENC_UCS2, TEXTID_ANY_LEN);
    GUIonMessage_SetMenuItemText(msg, str);
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SKINSELECT_LIST_ICN);
    GUIonMessage_SetMenuItemIcon(msg, AlignRight, SKINSELECT_ARROW_ICN);
    break;
  }
  return 1;
}

void SkinSelect_onSelectPressed(BOOK *book, GUI *gui)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  int item = ListMenu_GetSelectedItem(audioBook->Gui_SubMenu);

  FILELIST *flist = FindFLISTtByN(item);
  if (flist && flist->is_folder)
  {
    SaveCurrentSkinPath(flist->fullname);

    ADVPLAYER_DATA *data = GetData();
    ReloadSkinData(data, flist->fullname);

    Free_FLIST();
    FREE_GUI(audioBook->Gui_SubMenu);

#ifdef OLD_PLAYER
    MediaPlayer_Audio_ActionLongBack(audioBook, gui);
#else
    if (data->fullscreen || (!data->Skin->fullscreen))
    {
      data->fullscreen = data->Skin->fullscreen;
      BookObj_GotoPage(audioBook, page_MediaPlayer_Audio_Bk_Main);
    }
#endif
  }
}

BOOL isDirectory(wchar_t *name)
{
  W_FSTAT fs;
  if (w_fstat(name, &fs) != -1)
    return fs.attr & FSX_O_CHKPATH;
  else
    return FALSE;
}

TEXTID GetTitleText(int count)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"Total Skins: %d", count);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

int pg_MediaPlayer_SkinSelector_EnterEvent(void *data, BOOK *book)
{
  wchar_t *str = SKIN_PATH;
  wchar_t *ustr = WStringAlloc(WStringLength(str));
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

  int count = FindFiles(str, SFOLDER);

  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  FREE_GUI(audioBook->Gui_SubMenu);

  if (audioBook->Gui_SubMenu = CreateListMenu(audioBook, UIDisplay_Main))
  {
    ListMenu_SetItemCount(audioBook->Gui_SubMenu, count);
    ListMenu_SetCursorToItem(audioBook->Gui_SubMenu, 0);
    ListMenu_SetOnMessage(audioBook->Gui_SubMenu, SkinSelect_OnMessage);
    ListMenu_SetHotKeyMode(audioBook->Gui_SubMenu, LKHM_SHORTCUT);
    GUIObject_SetTitleType(audioBook->Gui_SubMenu, UI_TitleMode_Large);
    GUIObject_SetTitleText(audioBook->Gui_SubMenu, STR("Select Skin"));
    GUIObject_SetTitleTextAlign(audioBook->Gui_SubMenu, AlignLeft);
    GUIObject_SetSecondRowTitleText(audioBook->Gui_SubMenu, GetTitleText(count));
    GUIObject_SetStyle(audioBook->Gui_SubMenu, UI_OverlayStyle_FullScreenNoStatus);
    if (count)
      GUIObject_SoftKeys_SetAction(audioBook->Gui_SubMenu, ACTION_SELECT1, SkinSelect_onSelectPressed);
    GUIObject_SoftKeys_SetAction(audioBook->Gui_SubMenu, ACTION_BACK, MediaPlayer_Audio_ActionBack);
    GUIObject_SoftKeys_SetAction(audioBook->Gui_SubMenu, ACTION_LONG_BACK, MediaPlayer_Audio_ActionLongBack);
    GUIObject_Show(audioBook->Gui_SubMenu);
  }
  WStringFree(ustr);
  return 1;
}
