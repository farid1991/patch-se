#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(0, size, 1, 5, "LC", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "LC", 0));
#else
  return (memalloc(size, 1, 5, "LC", 0));
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(0, mem, "LC", 0);
#elif defined(A2)
    memfree(0, mem, "LC", 0);
#else
    memfree(mem, "LC", 0);
#endif
}

extern "C" wchar_t *ReadOnFile()
{
  FSTAT _fstat;
  if (fstat((wchar_t *)FILE_PATH, (wchar_t *)FILE_NAME, &_fstat) < 0)
    return NULL;

  wchar_t *wstr = (wchar_t *)malloc(_fstat.fsize + sizeof(wchar_t));
  if (wstr == NULL)
    return NULL;

  int file = _fopen((wchar_t *)FILE_PATH, (wchar_t *)FILE_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
  if (file >= 0)
  {
    fread(file, wstr, _fstat.fsize);
    wstr[_fstat.fsize / sizeof(wchar_t)] = L'\0';
    fclose(file);
  }
  else
  {
    mfree(wstr);
    return NULL;
  }

  return wstr;
}

void WriteOnFile(const wchar_t *wstr)
{
  int file = _fopen((wchar_t *)FILE_PATH, (wchar_t *)FILE_NAME, FSX_O_WRONLY | FSX_O_CREAT, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
  if (file >= 0)
  {
    fwrite(file, wstr, wstrlen(wstr) * sizeof(wchar_t));
    fclose(file);
  }
}

void OnAcceptInput(BOOK *book, GUI *gui)
{
  PhoneNameBook *pbook = (PhoneNameBook *)book;
  if (FSX_IsFileExists((wchar_t *)FILE_PATH, (wchar_t *)FILE_NAME))
  {
    FileDelete((wchar_t *)FILE_PATH, (wchar_t *)FILE_NAME, NULL);
  }

  uint16_t len;
  wchar_t *wstr;
  StringInput_GetStringAndLen(pbook->gui, &wstr, &len);

  if (len)
  {
    WriteOnFile(wstr);
    MessageBox(EMPTY_TEXTID, TextID_Create(wstr, ENC_UCS2, len), 0, 1, 0, pbook);
    SetOperatorName(TextID_Create(wstr, ENC_UCS2, len), NULL);
  }
  else
  {
    MessageBox(EMPTY_TEXTID, STR("Operator name set to default"), 0, 1, 0, pbook);
#ifdef DB3350
    TEXTID network_name = INetworkServices_GetNetworkName();
#else
    wchar_t buf[32];
    TEXTID network_name = GetOperatorName(buf);
#endif
    SetOperatorName(network_name, NULL);
  }

  FreeBook(pbook);
}

void OnPatchInfo(BOOK *book, GUI *gui)
{
  MessageBox(EMPTY_TEXTID, STR("Logo Changer\nv2024\n\n(c) farid"), 0, 1, 0, book);
}

int pg_EditOperatorName_EnterEvent(void *, BOOK *book)
{
  PhoneNameBook *pbook = (PhoneNameBook *)book;

  if (pbook->gui = CreateStringInput(pbook))
  {
    GUIObject_SetTitleText(pbook->gui, OPERATOR_TXT);
#ifdef DB3350
    TEXTID network_name = INetworkServices_GetNetworkName();
#else
    wchar_t buf[32];
    TEXTID network_name = GetOperatorName(buf);
#endif
    StringInput_SetText(pbook->gui, network_name);
    StringInput_SetMaxLen(pbook->gui, 32);
    StringInput_SetMode(pbook->gui, IT_STRING);
    StringInput_SetEnableEmptyText(pbook->gui, TRUE);
    GUIObject_SoftKeys_SetAction(pbook->gui, ACTION_ACCEPT, OnAcceptInput);
    GUIObject_SoftKeys_SetAction(pbook->gui, ACTION_BACK, onBackPressed);
    GUIObject_SoftKeys_SetAction(pbook->gui, ACTION_LONG_BACK, onLongBackPressed);
    GUIObject_Show(pbook->gui);
  }
  return 1;
}

void onEnterList(BOOK *book, GUI *gui)
{
  PhoneNameBook *pbook = (PhoneNameBook *)book;

  if (ListMenu_GetSelectedItem(pbook->gui) == 0)
  {
    BookObj_GotoPage(pbook, &EditOperatorName_page);
  }
  else
  {
    BookObj_GotoPage(pbook, &EditBluetoothName_page);
  }
}

int List_onCallback(GUI_MESSAGE *msg)
{
  if (GUIonMessage_GetMsg(msg) == 1)
  {
    if (GUIonMessage_GetCreatedItemIndex(msg) == 0)
    {
      GUIonMessage_SetMenuItemText(msg, OPERATOR_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, OPERATOR_ICN);
    }
    else
    {
      GUIonMessage_SetMenuItemText(msg, BLUETOOTH_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, BLUETOOTH_ICN);
    }
  }
  return 1;
}

int new_EditPhoneName_EnterEvent(void *r0, BOOK *book)
{
  PhoneNameBook *pbook = (PhoneNameBook *)book;

  if (pbook->gui = CreateListMenu(pbook, UIDisplay_Main))
  {
    GUIObject_SetTitleText(pbook->gui, PHONE_NAME_TXT);
    GUIObject_SetTitleIcon(pbook->gui, TITLE_ICON);
    ListMenu_SetItemCount(pbook->gui, 2);
    ListMenu_SetCursorToItem(pbook->gui, 0);
    ListMenu_SetOnMessage(pbook->gui, List_onCallback);
    ListMenu_SetHotkeyMode(pbook->gui, LKHM_SHORTCUT);
    GUIObject_SoftKeys_SetText(pbook->gui, 0, ABOUT_TXT);
    GUIObject_SoftKeys_SetAction(pbook->gui, 0, OnPatchInfo);
    GUIObject_SoftKeys_SetAction(pbook->gui, ACTION_BACK, onBackPressed);
    GUIObject_SoftKeys_SetAction(pbook->gui, ACTION_LONG_BACK, onLongBackPressed);
    GUIObject_SoftKeys_SetAction(pbook->gui, ACTION_SELECT1, onEnterList);
    GUIObject_Show(pbook->gui);
  }
  return 1;
}
