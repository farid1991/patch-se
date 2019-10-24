#include "..\\include\Types.h"
#include "..\\include\Function.h"


int getFileSize(wchar_t* fpath,wchar_t* fname)
{
  FSTAT fst;
  fstat(fpath,fname,&fst);
  return (fst.fsize/1024);
}

TEXTID SetTexts( SUB_EXECUTE* sub , int tag )
{
  wchar_t* fpath = sub->file_item->__path;
  wchar_t* fname = sub->file_item->__fname;
  
  wchar_t* wstr;
  wstr = MetaData_GetTags( fpath, fname, tag );
  
  TEXTID tag_id = TextID_Create(wstr,ENC_UCS2,TEXTID_ANY_LEN);
  TEXTID space = TextID_CreateFromASCII(0x20);
  
  TEXTID tmp[3];
  tmp[1] = space;
    
  TEXTID ret;
  if(tag_id!=EMPTY_TEXTID)
  { 
    tmp[2] = tag_id;
    if(tag==TAG_ARTIST) tmp[0] = TextID_CreateFromASCII(0xEDD8);
    else tmp[0] = TextID_CreateFromASCII(0xEDDA); 
    ret = TextID_Create(tmp,ENC_TEXTID,3);
  }
  else
  {
    if(tag==TAG_TITLE) 
    {
       tmp[0] = TextID_CreateFromASCII(0xEDDA); 
       tmp[2] = TextID_Create(fname,ENC_UCS2,TEXTID_ANY_LEN);;
       ret = TextID_Create(tmp,ENC_TEXTID,3);
    }
    else
    {
      TEXTID tmp2[5];
      tmp2[0] = TextID_CreateFromASCII(0xF8F0);
      tmp2[1] = space;
      tmp2[2] = TextID_CreateIntegerID(getFileSize(fpath,fname));
      tmp2[3] = space;
      tmp2[4] = TXT_KBYTES;
      ret = TextID_Create(tmp2,ENC_TEXTID,5); 
    }
  }
  return ret;
}

extern "C"
int SetItemText( SUB_EXECUTE * sub_execute, TEXTID *txt)
{
  *txt = SetTexts( sub_execute, TAG_TITLE );
  return 0;
}

extern "C"
int SetSecondlineItemText( SUB_EXECUTE* sub_execute, TEXTID *txt)
{
  *txt = SetTexts( sub_execute, TAG_ARTIST );
  return 0;
}
