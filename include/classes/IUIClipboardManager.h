#ifndef _IUICLIPBOARDMANAGER_H_
#define _IUICLIPBOARDMANAGER_H_

const UUID CID_CUIClipboardManager = {0x4E, 0xFE, 0x6C, 0x65, 0x6D, 0xE8, 0x4B, 0xC2, 0xB5, 0x0C, 0x12, 0x3B, 0x65, 0xD1, 0x5F, 0x72};
const UUID IID_IUIClipboardManager = {0x9B, 0x5D, 0xF1, 0xA9, 0xE3, 0x6A, 0x44, 0x7E, 0x9A, 0xB2, 0x47, 0x21, 0x4E, 0x0A, 0x35, 0x03};

class IUIClipboard: public IRoot
{
public:
  virtual int GetBuffer( void** buffer );
  virtual int SetText( IUIText* pIUIText );
  virtual int GetText( IUIText** ppIUIText );
  virtual int Clear( void );
  virtual int isEmpty( void );
};

class IUIClipboardManager: public IRoot
{
public:
  virtual int GetBuffer(IRoot** ppBuffer);
  virtual int GetIUIClipboard(IUIClipboard** ppIUIClipboard);
};

#endif
