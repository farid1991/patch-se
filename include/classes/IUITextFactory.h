#ifndef _IUITEXTFACTORY_H_
#define _IUITEXTFACTORY_H_

const UUID CID_CUITextFactory = {0xEA,0xED,0x04,0x64,0x00,0x73,0x41,0x81,0xBD,0xE3,0xFB,0x31,0x9F,0xDB,0xDF,0xBC};
const UUID IID_IUITextFactory = {0xFB,0xE8,0xC1,0xCC,0x97,0x35,0x49,0xD9,0x95,0x8E,0x3E,0x9D,0x99,0x82,0x27,0xB3};
  
class IUIText: public IRoot
{
public:
    virtual int unk_0(); //0x10
    virtual int GetText( wchar_t* pString, int max_len, int* pLenght );
    virtual int unk_1();
    virtual int GetLenght(int* len);
};

class IUITextFactory: public IRoot
{
public:
    virtual int unk_0();
    virtual int CreateFromAscii();
    virtual int CreateFromRaw( wchar_t* pString, int pLenght, IUIText** pIUIText);
    virtual int CreateFromTextId();
    virtual int unk_1();
    virtual int unk_2();
    virtual int unk_3();
    virtual int ConcatenateIUITexts();
};

#endif
