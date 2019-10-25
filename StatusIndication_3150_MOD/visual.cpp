/*
;Ability to move,show/hide items on standby
;(c) Ploik, BigHercules
;(e) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "cfg_items.h"
#include "StatusIndication.h"
#include "editor.h"
#include "visual.h"

int ColorGuiOnCreate( DISP_OBJ_COLOR* db )
{
  db->str_id = EMPTY_TEXTID;
  db->need_str = 1;
  db->current_column = 0;
  db->cstep = 1;
  return 1;
}

void ColorGuiOnClose( DISP_OBJ_COLOR* db )
{
  TextID_Destroy( db->str_id );
}

void ColorGuiOnRedraw( DISP_OBJ_COLOR* db, int, int, int )
{
  RECT rc_old;
  int font_old, gc_xx;
  int font = FONT_E_20R, fsize = 20;
  GC* gc = get_DisplayGC();
  int column_height, column_width;
  int start_column, y_line;
  wchar_t ustr[32];
  int scr_w, scr_h, x1, y1;
  int testcolor;
  
  GC_GetRect( gc, &rc_old );
  gc_xx = GC_GetXX( gc );
  GC_SetXX( gc, 1 );
  x1 = rc_old.x1;
  y1 = rc_old.y1;
  scr_w = rc_old.x2 - x1;
  scr_h = rc_old.y2 - y1;
  
  font_old = SetFont( font );
  column_height = scr_h - fsize - fsize;
  column_width = scr_w / 9;
  DrawRect( x1, y1, x1 + scr_w, y1 + scr_h, clWhite, clWhite );
  if ( db->need_str )
  {
    snwprintf( ustr, MAXELEMS( ustr ) - 1, L"%02X, %02X, %02X, %02X", db->r, db->g, db->b, db->a );
    TextID_Destroy( db->str_id );
    db->str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
    db->need_str = 0;
  }
  DrawString( db->str_id, 0, x1 + 1, y1 + 1, x1 + scr_w - 30, y1 + 1 + fsize + 1, 0, 0, clBlack, 0x00000000 );
  fsize += 3;

  for ( int i = 0; i != 4; i++ )
  {
    start_column = column_width + 2 * i * column_width;
    column_height++; // Какая то фигня с DrawRect, координаты не совпадают с DrawLine. Оно и понятно, DrawRect не GC_.

    if ( db->current_column == i )
      DrawRect( x1 + start_column - 2, y1 + fsize - 2, x1 + start_column + column_width + 2, y1 + fsize + column_height + 2, clBlack, clWhite );

    DrawRect( x1 + start_column, y1 + fsize, x1 + start_column + column_width, y1 + fsize + column_height, clBlack, colors[i] );
    column_height--;

    switch( i )
    {
    case 0:
      y_line = fsize + column_height - ( db->r * column_height ) / 0xFF;
      break;
    case 1:
      y_line = fsize + column_height - ( db->g * column_height ) / 0xFF;
      break;
    case 2:
      y_line = fsize + column_height - ( db->b * column_height ) / 0xFF;
      break;
    case 3:
      y_line = fsize + column_height - ( db->a * column_height ) / ( db->type == 0 ? 0x64 : 0xFF );
      break;
    }

    int old_pen = GC_GetPenColor( gc );
    GC_SetPenColor( gc, clBlack );
    GC_DrawLine( gc, x1 + start_column, y1 + y_line, x1 + start_column + column_width - 1, y1 + y_line );
    GC_SetPenColor( gc, old_pen );
  }
  testcolor = COLOR_RGBA( db->r, db->g, db->b, db->type == 0? ( db->a * 0xFF / 0x64 ) : ( db->a ) );
  DrawRect( x1 + scr_w - fsize - 1, y1 + 1, x1 + scr_w - 1, y1 + fsize + 1, clBlack, testcolor );
  
  SetFont( font_old );
  GC_SetXX( gc, gc_xx );
}

void ColorGuiOnKey( DISP_OBJ_COLOR* db, int key, int, int repeat, int type )
{
  if ( type == KBD_SHORT_RELEASE || type == KBD_REPEAT )
  {
    if ( type == KBD_SHORT_RELEASE )
      db->cstep = 1;
    else
      if ( type == KBD_REPEAT && repeat  >  10 )
        db->cstep = 8;

    if ( key == KEY_UP || key == KEY_DIGITAL_0 + 2 )
    {
      switch( db->current_column )
      {
      case 0:
        if ( ( db->r += db->cstep ) >0xFF )
          db->r = 0;
        break;
      case 1:
        if ( ( db->g += db->cstep ) >0xFF )
          db->g = 0;
        break;
      case 2:
        if ( ( db->b += db->cstep ) >0xFF )
          db->b = 0;
        break;
      case 3:
        if ( ( db->a += db->cstep ) > ( db->type == 0 ? 0x64 : 0xFF ) )
          db->a = 0;
        break;
      }

      db->need_str = 1;
    }
    else if ( key == KEY_DOWN || key == KEY_DIGITAL_0 + 8 )
    {
      switch( db->current_column )
      {
      case 0:
        if ( ( db->r -= db->cstep ) < 0 )
          db->r = 0xFF;
        break;
      case 1:
        if ( ( db->g -= db->cstep ) < 0 )
          db->g = 0xFF;
        break;
      case 2:
        if ( ( db->b -= db->cstep ) < 0 )
          db->b = 0xFF;
        break;
      case 3:
        if ( ( db->a -= db->cstep ) < 0 )
          db->a = ( db->type == 0 ? 0x64 : 0xFF );
          break;
      }

      db->need_str = 1;
    }
    else if ( key == KEY_LEFT || key == KEY_DIGITAL_0 + 4 )
    {
      if ( --db->current_column < 0 )
        db->current_column = 3;
    }
    else if ( key == KEY_RIGHT || key == KEY_DIGITAL_0 + 6 )
    {
      if ( ++db->current_column  >  3 )
        db->current_column = 0;
    }
  }

  if ( type == KBD_LONG_RELEASE )
    db->cstep = 1;

  DispObject_InvalidateRect( db, 0 );
}



void EditColorGui_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, EditColorGuiName );
  DISP_DESC_SetSize( desc, sizeof( DISP_OBJ_COLOR ) );
  DISP_DESC_SetOnCreate( desc, ( DISP_OBJ_ONCREATE_METHOD )ColorGuiOnCreate );
  DISP_DESC_SetOnClose( desc, ( DISP_OBJ_ONCLOSE_METHOD )ColorGuiOnClose );
  DISP_DESC_SetOnRedraw( desc, ( DISP_OBJ_ONREDRAW_METHOD )ColorGuiOnRedraw );
  DISP_DESC_SetOnKey( desc, ( DISP_OBJ_ONKEY_METHOD )ColorGuiOnKey );
}

void EditColorGui_destr( GUI* gui )
{
}

void OnBackColorEdit( BOOK* bk, GUI* )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FREE_GUI( myBook->color );
}

void OnOkColorEdit( BOOK* bk, GUI* )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*) GUIObject_GetDispObject( myBook->color );
  if ( disp_obj->type == 0 )
  {
    myBook->cur_hp.color->rgb[0] = disp_obj->r;
    myBook->cur_hp.color->rgb[1] = disp_obj->g;
    myBook->cur_hp.color->rgb[2] = disp_obj->b;
    myBook->cur_hp.color->rgb[3] = disp_obj->a;
  }
  else
  {
    myBook->cur_hp.color->color = COLOR_RGBA( disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a );
  }
  FREE_GUI( myBook->color );
  RefreshEdList(bk);
}

GUI_COLOR* CreateEditColorGUI( MyBOOK* myBook, int type )
{
  wchar_t ustr[32];
  GUI_COLOR* gui_color = (GUI_COLOR* )malloc(sizeof(GUI_COLOR));
  DISP_OBJ_COLOR* disp_obj;
  
  if ( !GUIObject_Create( gui_color, EditColorGui_destr, EditColorGui_constr, myBook, 0, 0, 0 ) )
  {
    myBook->color = 0;
    mfree( gui_color );
    return NULL;
  }

  disp_obj = (DISP_OBJ_COLOR*) GUIObject_GetDispObject( gui_color );

  if ( type == 0 )
  {
    disp_obj->r = myBook->cur_hp.color->rgb[0];
    disp_obj->g = myBook->cur_hp.color->rgb[1];
    disp_obj->b = myBook->cur_hp.color->rgb[2];
    disp_obj->a = myBook->cur_hp.color->rgb[3];
  }
  else
  {
    unsigned int color = myBook->cur_hp.color->color;
    disp_obj->r = COLOR_GET_R( color );
    disp_obj->g = COLOR_GET_G( color );
    disp_obj->b = COLOR_GET_B( color );
    disp_obj->a = COLOR_GET_A( color );
  }

  disp_obj->type = type;

  myBook->color = gui_color;

  if ( myBook ) BookObj_AddGUIObject( myBook, gui_color );

  win12512unicode( ustr, myBook->cur_hp.color->name, MAXELEMS(ustr) - 1 );
  GUIObject_SetTitleText( myBook->color, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ) );
  GUIObject_SetTitleType( myBook->color, 3 );
  GUIObject_SoftKeys_SetAction( myBook->color, ACTION_BACK, OnBackColorEdit );
  GUIObject_SoftKeys_SetAction( myBook->color, ACTION_SELECT1, OnOkColorEdit );
  GUIObject_SoftKeys_SetText( myBook->color, ACTION_SELECT1, STR( "OK" ) );
  GUIObject_Show( myBook->color );
  return gui_color;
}


// --------------------------------------------------------------------------------------------------------------------------------

wchar_t* Font_GetNameByFontId( int id )
{
  wchar_t* txt = L"Undefined";
  FONT_DESC* font = GETFONTDESC;
  for ( int i = 0, max = * GETFONTCOUNT; i < max; i++ )
  {
    if ( id == font[i].id )
    {
      txt = font[i].name;
      break;
    }
  }
  return txt;
}

int GetIdByFontId( int id )
{
  int r = 0;
  FONT_DESC* font = GETFONTDESC;
  for ( int i = 0, max = * GETFONTCOUNT; i < max; i++ )
  {
    if ( id == font[i].id )
    {
      r = i;
      break;
    }
  }
  return r;
}

int FontSelectGuiOnCreate( DISP_OBJ_FONT_SEL* db )
{
  wchar_t ustr[64];
  int font_old;
  win12512unicode( ustr, test_str, MAXELEMS( test_str ) - 1 );
  db->test_str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
  db->total_fonts = *GETFONTCOUNT;
  font_old = SetFont( FONT_E_20R );
  db->font_heights = (u16*)malloc(sizeof( u16) * db->total_fonts);
  for ( int i = 0; i < db->total_fonts; i++ )
  {
    FONT_DESC* font = GETFONTDESC;
    SetFont( font[i].id );
    db->font_heights[i] = GetImageHeight( ' ' );
  }
  SetFont( font_old );
  db->cur_offs = 0;
  db->req_check_vis = 1;
  return 1;
}

void FontSelectGuiOnClose( DISP_OBJ_FONT_SEL* db )
{
  TextID_Destroy( db->test_str_id );db->test_str_id = EMPTY_TEXTID;
  mfree( db->font_heights );
}


void CheckStringVisibility( DISP_OBJ_FONT_SEL* db, int x1, int y1, int x2, int y2, int y_offs )
{
  if ( db->cur_pos < db->cur_offs ) // строка выше смещения, поднимаем смещение
  {
    db->cur_offs = db->cur_pos;
  }
  else // иначе проверяем в зоне видимости ли мы, если нет то опускаемся пока не увидим
  {
    int f = 0;
    do {
      int cur_y = y_offs;
      for ( int i = db->cur_offs, k = 0; i < db->total_fonts; i++ )
      {
        int sum;
        if ( db->cur_pos == i )
          k = 1;

        if ( ( ( sum = cur_y + db->font_heights[i] + 2 ) + 1 ) < y2 && k )
          f = 1;

        cur_y = sum;

        if ( cur_y  >  y2 )
          break;
      }
    } while( !f && ++db->cur_offs < db->total_fonts );
  }
}

void FontSelectGuiOnRedraw( DISP_OBJ_FONT_SEL* db, int, RECT* cur_rc, int )
{
  int font_old, gc_xx;
  GC* gc = get_DisplayGC();
  int x1, y1, x2, y2;
  int y_offs;
  TEXTID selfont;
  
  gc_xx = GC_GetXX( gc );
  GC_SetXX( gc, 1 );
  x1 = cur_rc->x1;
  y1 = cur_rc->y1;
  x2 = cur_rc->x2;
  y2 = cur_rc->y2;
  y_offs = y1 + 20 + 2;
  if ( db->req_check_vis )
  {
    CheckStringVisibility( db, x1, y1, x2, y2, y_offs );
    db->req_check_vis = 0;
  }
  
  font_old = SetFont( FONT_E_20R );
  DrawRect( x1, y1, x2, y2, clBlack, clBlack );
  FONT_DESC* font_ = GETFONTDESC;
  
  selfont = TextID_Create( font_[db->cur_pos].name, ENC_UCS2, 9 );
  DrawString( selfont, 0, x1 + 3, y1 + 1, x2 - 2, y_offs - 1, 0, 0, 0xFF0080FF, 0x00000000 ); // Рисуем выбранный шрифт в шапке меню
  TextID_Destroy( selfont );
  
  int cur_y = y_offs;
  for ( int i = db->cur_offs; i < db->total_fonts; i++ )
  {
    int font, font_h;
    
    font = font_[i].id;
    SetFont( font );
    font_h = db->font_heights[i];
    if ( i == db->cur_pos ) // Если это выбранный шрифт
      DrawRect( x1 + 1, cur_y, x2 - 1, cur_y + font_h + 2, 0xFF00FF00, 0xFF408000 );
    DrawString( db->test_str_id, 0, x1 + 2, cur_y + 1, x2 - 2, cur_y + font_h + 1, 0, 0, clWhite, 0x00000000 );
    cur_y += font_h + 2;
    if ( cur_y>y2 ) break;
  }
  
  SetFont( font_old );
  GC_SetXX( gc, gc_xx );
  
}


void FontSelectGuiOnKey( DISP_OBJ_FONT_SEL* db, int key, int, int repeat, int type )
{
  if ( type == KBD_SHORT_RELEASE || type == KBD_REPEAT )
  {
    if ( key == KEY_UP || key == KEY_DIGITAL_0 + 2 )
    {
      if ( ( -- db->cur_pos ) < 0 ) db->cur_pos = db->total_fonts - 1;
    }
    else if ( key == KEY_DOWN || key == KEY_DIGITAL_0 + 8 )
    {
      if ( ++db->cur_pos  >= db->total_fonts )
        db->cur_pos = 0;
    }
    db->req_check_vis = 1;
    DispObject_InvalidateRect( db, 0 );
  }
}

void OnBackFontSelect( BOOK* bk, GUI* )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FREE_GUI( myBook->font_select );
}

void OnOkFontSelect( BOOK* bk, GUI* )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  DISP_OBJ_FONT_SEL* disp_obj = (DISP_OBJ_FONT_SEL*) GUIObject_GetDispObject( myBook->font_select );
  
  FONT_DESC* font = GETFONTDESC;
  myBook->cur_hp.font->font = font[disp_obj->cur_pos].id;
  
  FREE_GUI( myBook->font_select );
  RefreshEdList(bk);
}

void FontSelectGui_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, FontSelectGuiName );
  DISP_DESC_SetSize( desc, sizeof(DISP_OBJ_FONT_SEL) );
  DISP_DESC_SetOnCreate( desc, (DISP_OBJ_ONCREATE_METHOD) FontSelectGuiOnCreate );
  DISP_DESC_SetOnClose( desc, (DISP_OBJ_ONCLOSE_METHOD) FontSelectGuiOnClose );
  DISP_DESC_SetOnRedraw( desc, (DISP_OBJ_ONREDRAW_METHOD) FontSelectGuiOnRedraw );
  DISP_DESC_SetOnKey( desc, (DISP_OBJ_ONKEY_METHOD) FontSelectGuiOnKey );
}

void FontSelectGui_destr( GUI* gui )
{
}

GUI_FONT_SEL* CreateFontSelectGUI( MyBOOK* myBook )
{
  GUI_FONT_SEL* gui_fontsel = (GUI_FONT_SEL*)malloc( sizeof(GUI_FONT_SEL));
  DISP_OBJ_FONT_SEL* disp_obj;

  wchar_t ustr[64];
  if ( !GUIObject_Create( gui_fontsel, FontSelectGui_destr, FontSelectGui_constr, myBook, 0, 0, 0 ) )
  {
    mfree( gui_fontsel );
    return 0;
  }
  
  disp_obj = (DISP_OBJ_FONT_SEL*) GUIObject_GetDispObject( gui_fontsel );
  
  disp_obj->cur_pos = GetIdByFontId( myBook->cur_hp.font->font );
  
  myBook->font_select = gui_fontsel;
  
  if ( myBook ) BookObj_AddGUIObject( myBook, myBook->font_select );
  
  win12512unicode( ustr, myBook->cur_hp.font->name, MAXELEMS( ustr ) - 1 );
  GUIObject_SetTitleText( myBook->font_select, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ) );
  GUIObject_SetTitleType( myBook->font_select, 3 );
  GUIObject_SoftKeys_SetAction( myBook->font_select, ACTION_BACK, OnBackFontSelect );
  GUIObject_SoftKeys_SetAction( myBook->font_select, ACTION_SELECT1, OnOkFontSelect );
  GUIObject_Show( myBook->font_select );
  return gui_fontsel;
}
