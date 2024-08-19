#ifndef _IUICLIPBOARDMANAGER_H_
#define _IUICLIPBOARDMANAGER_H_

// UUID CID_CUIClipboardManager = {0x4E, 0xFE, 0x6C, 0x65, 0x6D, 0xE8, 0x4B, 0xC2, 0xB5, 0xC, 0x12, 0x3B, 0x65, 0xD1, 0x5F, 0x72};
// UUID IID_IUIClipboardManager = {0x9B, 0x5D, 0xF1, 0xA9, 0xE3, 0x6A, 0x44, 0x7E, 0x9A, 0xB2, 0x47, 0x21, 0x4E, 0xA, 0x35, 3};

class IUIText : public IUnknown
{
public:
  virtual int unk_0(); // 0x10
  virtual int get_text(wchar_t *ws, int max_len, int *len);
  virtual int unk_1();
  virtual int get_len(int *len);
};

class IUITextFactory : public IUnknown
{
public:
  virtual int unk_0();
  virtual int CreateFromAscii();
  virtual int CreateFromRaw(wchar_t *ws, int len, IUIText **pIUITextPointer);
  virtual int CreateFromTextId();
  virtual int unk_1();
  virtual int unk_2();
  virtual int unk_3();
  virtual int ConcatenateIUITexts();
};

class IUIClipboard : public IUnknown
{
public:
  virtual int GetBuffer(void **buffer);
  virtual int SetIUIText(IUIText *pIUIText);
  virtual int GetIUIText(IUIText **ppIUITextPointer);
  virtual int Clear();
  virtual int isEmpty();
};

class IUIClipboardManager : public IUnknown
{
public:
  virtual int GetBuffer(void **buffer);
  virtual int GetIUIClipboard(IUIClipboard **pIUIClipboardPointer);
};

#endif
