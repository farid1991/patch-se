#ifndef _EDITOR_H
#define _EDITOR_H

typedef struct _ITEMSBOOK : BOOK
{
  GUI* gui;
}ITEMSBOOK;

typedef struct
{
  wchar_t name[16];
  unsigned char *cfg;
  int size_cfg;
  unsigned int level;
  CFG_HDR *levelstack[4];
}BCFG_DATA;

typedef struct _MyBOOK : BOOK
{
  GUI_LIST* bcfg;
  GUI_ONEOFMANY* cbox_gui;
  GUI* text_input;
  GUI* color;
  GUI* font_select;
  
  LIST* list;
	
  union
  {
    CFG_HDR* hdr;
    CFG_HDR_COLOR* color;
    CFG_HDR_FONT* font;
    CFG_HDR_CHECKBOX* checkbox;
    CFG_HDR_UNSIGNEDINT* unsignedint;
    CFG_HDR_CBOX* cbox;
    CFG_HDR_WSTR* wstr;
  } cur_hp;
  
  TEXTID check_box_unchecked;
  TEXTID check_box_checked;
  BCFG_DATA bdata;
}MyBOOK;

#define IDN_CHECKBOX_UNCHECKED_ICON L"OFF_TXT"
#define IDN_CHECKBOX_CHECKED_ICON L"ON_TXT"

void CreateItemsList();
void CreateItemsEditor();
void win12512unicode( wchar_t* ws, const char* s, int len );
void RefreshEdList(BOOK * bk);
GUI* create_ed( BOOK* book, CFG_HDR* need_to_focus );

extern "C" unsigned long wcstoul(const wchar_t *, wchar_t **, int);

#endif //_EDITOR_H
