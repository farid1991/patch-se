/*
;A2 Walkman skinner
;Adds possibility to edit the Position,Color,Font
;Enable/Disable Title,Artist,Album,Genre,Total/Elapsed/Remaining time,Extension,Bit-rate,Total/Current track number,progress-bar,Album art
;Adds new items of Genre,Extension,Bit-rate,Overlay image to Walkman
;Adds possibility to edit position of icons shuffle/EQ/loop/state/wheel,Title/Artist/Album/Background/Overlay image
;Adds possibility to use skins in Walkman Player
;Adds skin editor for easy loading & editing of skins
;Adds possibility to use Walkman 4 visualization
;Redraws everything in Walkman,optimized for better Walkman experience
;v.1.3.3 mod
;(c) blacklizard
;(r) KreN
;(e) farid, D3mon
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "Function.h"
#include "LNG.h"
#include "SaveLoad.h"
#include "Visual.h"
#include "Viz.h"
#include "Walkman.h"

int GUI_EditColor_OnCreate( DISP_OBJ_COLOR* disp_obj )
{
  disp_obj->str_id = EMPTY_TEXTID;
  disp_obj->need_str = 1;
  disp_obj->current_column = 0;
  disp_obj->cstep = 1;
  return 1;
}

void GUI_EditColor_OnClose( DISP_OBJ_COLOR* disp_obj )
{
  TEXT_FREE( disp_obj->str_id );
}

void GUI_EditColor_OnRedraw( DISP_OBJ_COLOR* disp_obj, int, int, int )
{
  RECT rc_old;
  int gc_xx;
  int fsize = 20;
  GC* pGC = get_DisplayGC();
  int column_height, column_width;
  int start_column, y_line;
  wchar_t ustr[32];
  int scr_w, scr_h, x1, y1;
  
  int colors[4] =
  {
    clRed,
    clGreen,
    clBlue,
    0x80C6AAAF
  };
  
  GC_GetRect(pGC, &rc_old);
  gc_xx = GC_GetXX(pGC);
  GC_SetXX(pGC, 1);
  x1 = rc_old.x1;
  y1 = rc_old.y1;
  scr_w = rc_old.x2 - x1;
  scr_h = rc_old.y2 - y1;
  
  column_height = scr_h - fsize - fsize;
  column_width = scr_w / 9;
  DrawRect(x1, y1, x1 + scr_w, y1 + scr_h, clWhite, clWhite);
  
  if (disp_obj->need_str)
  {
    snwprintf(ustr, MAXELEMS(ustr) - 1, L"%02X, %02X, %02X, %02X", disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
    TextID_Destroy(disp_obj->str_id);
    disp_obj->str_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
    disp_obj->need_str = 0;
  }

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString(disp_obj->str_id,
                 FONT_E_20R,
                 UITextAlignment_Center,
                 x1 + 1,
                 y1 + 1,
                 x1 + scr_w - 1,
                 y1 + 1 + fsize + 1,
                 clBlack);
#else
  SetFont(FONT_E_20R);
  DrawString(disp_obj->str_id,
             UITextAlignment_Center,
             x1 + 1,
             y1 + 1,
             x1 + scr_w - 1,
             y1 + 1 + fsize + 1,
             0,0,
             clBlack,
             clEmpty);
#endif
  fsize += 3;
  
  for (int i = 0; i != 4; i++)
  {
    start_column = column_width + 2 * i * column_width + 4;
    column_height++;
    if (disp_obj->current_column == i) DrawRect(x1 + start_column - 2, y1 + fsize - 2 + 50, x1 + start_column + column_width + 2, y1 + fsize + column_height + 2, clBlack, clWhite); // ???????
    DrawRect(x1 + start_column, y1 + fsize + 50, x1 + start_column + column_width, y1 + fsize + column_height, clBlack, colors[i]);
    column_height--;
    
    switch(i)
    {
    case 0: y_line = fsize + column_height - (disp_obj->r * (column_height - 50)) / 0xFF; break;
    case 1: y_line = fsize + column_height - (disp_obj->g * (column_height - 50)) / 0xFF; break;
    case 2: y_line = fsize + column_height - (disp_obj->b * (column_height - 50)) / 0xFF; break;
    case 3: y_line = fsize + column_height - (disp_obj->a * (column_height - 50)) / 0xFF; break;
    }
    
    int old_pen = GC_GetPenColor(pGC);
    GC_SetPenColor(pGC, clBlack);
    GC_DrawLine(pGC, x1 + start_column, y1 + y_line, x1 + start_column + column_width - 1, y1 + y_line);
    GC_SetPenColor(pGC, old_pen);
  }
  
  int testcolor = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  DrawRect(x1 + 20, y1 + 1 + 30, x1 + scr_w - 20, y1 + fsize + 30, clBlack, testcolor);
  GC_SetXX(pGC, gc_xx);
}

void GUI_EditColor_OnKey( DISP_OBJ_COLOR* disp_obj, int key, int, int repeat, int mode )
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (mode == KBD_SHORT_RELEASE) disp_obj->cstep = 1;
    else if (mode == KBD_REPEAT && repeat > 10) disp_obj->cstep = 8;
    
    if (key == KEY_UP || key == KEY_DIGITAL_0 + 2)
    {
      switch(disp_obj->current_column)
      {
      case 0: if ((disp_obj->r += disp_obj->cstep) > 0xFF) disp_obj->r = 0; break;
      case 1: if ((disp_obj->g += disp_obj->cstep) > 0xFF) disp_obj->g = 0; break;
      case 2: if ((disp_obj->b += disp_obj->cstep) > 0xFF) disp_obj->b = 0; break;
      case 3: if ((disp_obj->a += disp_obj->cstep) > 0xFF) disp_obj->a = 0; break;
      }
      disp_obj->need_str = 1;
    }
    else if (key == KEY_DOWN || key == KEY_DIGITAL_0 + 8)
    {
      switch(disp_obj->current_column)
      {
      case 0: if ((disp_obj->r -= disp_obj->cstep) < 0) disp_obj->r = 0xFF; break;
      case 1: if ((disp_obj->g -= disp_obj->cstep) < 0) disp_obj->g = 0xFF; break;
      case 2: if ((disp_obj->b -= disp_obj->cstep) < 0) disp_obj->b = 0xFF; break;
      case 3: if ((disp_obj->a -= disp_obj->cstep) < 0) disp_obj->a = 0xFF; break;
      }
      disp_obj->need_str = 1;
    }
    else if (key == KEY_LEFT || key == KEY_DIGITAL_0 + 4)
    {
      if (--disp_obj->current_column < 0) disp_obj->current_column = 3;
    }
    else if (key == KEY_RIGHT || key == KEY_DIGITAL_0 + 6)
    {
      if (++disp_obj->current_column > 3) disp_obj->current_column = 0;
    }
    else if (key == KEY_DEL)
    {
      switch(disp_obj->current_column)
      {
      case 0: disp_obj->r = 0; break;
      case 1: disp_obj->g = 0; break;
      case 2: disp_obj->b = 0; break;
      case 3: disp_obj->a = 0; break;
      }
      disp_obj->need_str = 1;
    }
  }
  
  if (mode == KBD_LONG_RELEASE) disp_obj->cstep = 1;
  DispObject_InvalidateRect(disp_obj, NULL);
}

void GUI_EditColor_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, Gui_EditColor );
  DISP_DESC_SetSize( desc, sizeof(DISP_OBJ_COLOR) );
  DISP_DESC_SetOnCreate( desc, (DISP_OBJ_ONCREATE_METHOD) GUI_EditColor_OnCreate );
  DISP_DESC_SetOnClose( desc, (DISP_OBJ_ONCLOSE_METHOD) GUI_EditColor_OnClose );
  DISP_DESC_SetOnRedraw( desc, (DISP_OBJ_ONREDRAW_METHOD) GUI_EditColor_OnRedraw );
  DISP_DESC_SetOnKey( desc, (DISP_OBJ_ONKEY_METHOD) GUI_EditColor_OnKey );
}

void GUI_EditColor_destr( GUI* gui )
{
}

void GUI_EditColor_OnBack( BOOK* book, GUI* gui)
{
  WalkmanSkinEditor_Book* myBook = (WalkmanSkinEditor_Book*) book;
  FREE_GUI(myBook->color);
}

void GUI_EditColor_OnOk( BOOK* bk, GUI* )
{
  WalkmanSkinEditor_Book* myBook = (WalkmanSkinEditor_Book*) bk;
  myBook->ChangeMade = TRUE;
  
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*) GUIObject_GetDispObject( myBook->color );
  
  if(myBook->IsBbar)
  {
    myBook->Str_Color = COLOR_RGBA( disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a );
    snwprintf( myBook->buffer, 50, L"%X, %X, %X, %X", COLOR_GET_R(myBook->Str_Color),COLOR_GET_G(myBook->Str_Color),COLOR_GET_B(myBook->Str_Color),COLOR_GET_A(myBook->Str_Color) );
    ListMenu_SetItemSecondLineText( myBook->ProgressBar, 2,TextID_Create(myBook->buffer,ENC_UCS2,0xFF) );
  }
  else if(myBook->IsFbar)
  {
    myBook->Str_Color_2 = COLOR_RGBA( disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a );
    snwprintf( myBook->buffer, 50, L"%X, %X, %X, %X", COLOR_GET_R(myBook->Str_Color_2),COLOR_GET_G(myBook->Str_Color_2),COLOR_GET_B(myBook->Str_Color_2),COLOR_GET_A(myBook->Str_Color_2) );
    ListMenu_SetItemSecondLineText( myBook->ProgressBar, 3,TextID_Create(myBook->buffer,ENC_UCS2,0xFF) );
  }
  else if(myBook->IsString)
  {
    myBook->Str_Color = COLOR_RGBA( disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a );
    snwprintf( myBook->buffer, 50, L"%X, %X, %X, %X", COLOR_GET_R(myBook->Str_Color),COLOR_GET_G(myBook->Str_Color),COLOR_GET_B(myBook->Str_Color),COLOR_GET_A(myBook->Str_Color) );
    ListMenu_SetItemSecondLineText( myBook->StringEdit, 4,TextID_Create(myBook->buffer,ENC_UCS2,0xFF) );
  }
    
  FREE_GUI(myBook->color);
}

void Create_GUI_EditColor( BOOK* book )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  GUI_COLOR* gui_color = (GUI_COLOR*)malloc(sizeof(GUI_COLOR));
  DISP_OBJ_COLOR* disp_obj;
  
  if( !GUIObject_Create( gui_color, GUI_EditColor_destr, GUI_EditColor_constr, mbk, NULL, UIDisplay_Main, sizeof(GUI_COLOR) ) )
  {
    mbk->color = NULL;
    mfree(gui_color);
  }
  
  disp_obj = (DISP_OBJ_COLOR*) GUIObject_GetDispObject( gui_color );
  
  if((mbk->IsBbar)||(mbk->IsString))
  {
      int color = mbk->Str_Color;
      disp_obj->r = COLOR_GET_R( color );
      disp_obj->g = COLOR_GET_G( color );
      disp_obj->b = COLOR_GET_B( color );
      disp_obj->a = COLOR_GET_A( color );
  }
  else if(mbk->IsFbar)
  {
    int color = mbk->Str_Color_2;
    disp_obj->r = COLOR_GET_R( color );
    disp_obj->g = COLOR_GET_G( color );
    disp_obj->b = COLOR_GET_B( color );
    disp_obj->a = COLOR_GET_A( color );
  }
  
  mbk->color = gui_color;
  
  if(mbk) BookObj_AddGUIObject( mbk, gui_color );
  
  GUIObject_SetTitleText( gui_color, TEXT_COLOR );
  GUIObject_SetTitleType( gui_color, UI_TitleMode_Small );
  GUIObject_SoftKeys_SetAction( gui_color, ACTION_BACK, GUI_EditColor_OnBack );
  GUIObject_SoftKeys_SetActionAndText( gui_color, ACTION_SELECT1, GUI_EditColor_OnOk, TEXT_OK );
  GUIObject_SoftKeys_SetItemOnKey( gui_color, ACTION_SELECT1, KEY_DIGITAL_0+5, KBD_SHORT_PRESS );
  GUIObject_Show( gui_color );
}

// --------------------------------------------------------------------------------------------------------------------------------

void DrawOwnRect( int _x1, int _y1, int _x2, int _y2, int pen_color, int brush_color )
{
  int x1, x2, y1, y2;

  x1 = MIN( _x1, _x2 );
  x2 = MAX( _x1, _x2 );
  y1 = MIN( _y1, _y2 );
  y2 = MAX( _y1, _y2 );
  
  if( y1 == y2 || x1 == x2 )
  {
    GC* gc = get_DisplayGC();
    GC_SetPenColor( gc, pen_color );
    GC_SetBrushColor( gc, brush_color );
    GC_DrawLine( gc, x1, y1, x2, y2 );
  }
  else DrawRect( x1, y1, x2, y2, pen_color, brush_color );
}

void DrawArrow( int x, int y, int color )
{
  DrawOwnRect( x, y, x + 13, y + 2, clBlack, clBlack );
  DrawOwnRect( x + 11, y + 2, x + 13, y + 6, clBlack, clBlack );
  DrawOwnRect( x + 8, y + 5, x + 16, y + 6, clBlack, clBlack );
  DrawOwnRect( x + 9, y + 6, x + 15, y + 7, clBlack, clBlack );
  DrawOwnRect( x + 10, y + 7, x + 14, y + 8, clBlack, clBlack );
  DrawOwnRect( x + 11, y + 8, x + 13, y + 9, clBlack, clBlack );
};

int GUI_EditCoordinates_OnCreate( DISP_OBJ_COORD* disp_obj )
{
  disp_obj->str_id = EMPTY_TEXTID;
  disp_obj->need_str = 1;
  disp_obj->is_first_set = 0;
  disp_obj->cstep = 1;
  return 1;
}

void GUI_EditCoordinates_OnClose( DISP_OBJ_COORD* disp_obj )
{
  TEXT_FREE( disp_obj->str_id );
}

void GUI_EditCoordinates_OnRedraw( DISP_OBJ_COORD* disp_obj, int a, int b, int c )
{
  WALKMAN_Function * Data = Get_WALKMAN_Function();

  RECT rc_old, rc_new;
  //int font_old;
  int gc_xx;

  int fsize = 20;
  int colors[4] = { clRed, clGreen, clBlue, 0x80C6AAAF };
  
  GC* gc = get_DisplayGC();
  wchar_t ustr[32];
  int old_pen;
  
  int scr_w = Display_GetWidth(0);
  int scr_h = Display_GetHeight(0);
  
  GC_GetRect( gc, &rc_old );
  gc_xx = GC_GetXX( gc );
  GC_SetXX( gc, 1 );
  
  rc_new.x1 = 0;
  rc_new.x2 = scr_w;
  rc_new.y1 = 0;
  rc_new.y2 = scr_h;
  GC_ValidateRect( gc, &rc_new );
  
  DrawRect( 0, 0, scr_w, scr_h, clWhite, clWhite );

  old_pen = GC_GetPenColor( gc );
  GC_SetPenColor( gc, colors[3] );
  
  for ( int y_0 = 0; y_0 < scr_h; y_0 += 10 )
  {
    GC_DrawLine( gc, 0, y_0, scr_w, y_0 );
  }
  
  for ( int x_0 = 0; x_0 < scr_w; x_0 += 10 )
  {
    GC_DrawLine( gc, x_0, 0, x_0, scr_h );
  }
  
  GC_SetPenColor( gc, old_pen );
  
  if( disp_obj->type )
  {
    DrawOwnRect( disp_obj->old_rect.x1, disp_obj->old_rect.y1, disp_obj->old_rect.x2, disp_obj->old_rect.y2, 0xC0808080, clEmpty );
    if( disp_obj->is_first_set )
    {
      DrawOwnRect( disp_obj->x, disp_obj->y, disp_obj->x2, disp_obj->y2, clBlack, clEmpty );
      if( disp_obj->need_str )
      {
        snwprintf( ustr, MAXELEMS(ustr)-1, L"%d, %d, %d, %d", disp_obj->x2, disp_obj->y2, disp_obj->x, disp_obj->y );
        TextID_Destroy( disp_obj->str_id );
        disp_obj->str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
        disp_obj->need_str = 0;
      }
    }
    else
    {
      if( disp_obj->need_str )
      {
        snwprintf( ustr, MAXELEMS(ustr)-1, L"%d, %d, %d, %d", disp_obj->x, disp_obj->y, disp_obj->x2, disp_obj->y2 );
        TextID_Destroy( disp_obj->str_id );
        disp_obj->str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
        disp_obj->need_str = 0;
      }
    }
  }
  else
  {
    if( disp_obj->need_str )
    {
      snwprintf( ustr, MAXELEMS(ustr)-1, L"%d, %d", disp_obj->x, disp_obj->y );
      TextID_Destroy( disp_obj->str_id );
      disp_obj->str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      disp_obj->need_str = 0;
    }
  }
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString(FONT_E_20R,
                 disp_obj->str_id, 
                 UITextAlignment_Left,
                 3,
                 scr_h - fsize - 2, 
                 scr_w - 4, 
                 scr_h - 1,
                 clBlack );
#else
  SetFont( FONT_E_20R );
  DrawString(disp_obj->str_id, 
             UITextAlignment_Left,
             3, 
             scr_h - fsize - 2, 
             scr_w - 4, 
             scr_h - 1,
             0, 0,
             clBlack, clEmpty );
#endif
  
  old_pen = GC_GetPenColor( gc );
  GC_SetPenColor( gc, clBlack );
  GC_DrawLine( gc, disp_obj->x - 3, disp_obj->y, disp_obj->x + 3, disp_obj->y );
  GC_DrawLine( gc, disp_obj->x, disp_obj->y - 3, disp_obj->x, disp_obj->y + 3 );
  
  if( BookObj_GetDisplayOrientation( disp_obj->mbk ) == 0 )
  {
    DrawArrow( scr_w - 19, scr_h - 13, clBlack );
  }
  else
  {
    DrawArrow( scr_w - 19, 3, clBlack );
  }
  GC_SetPenColor( gc, old_pen );
  GC_ValidateRect( gc, &rc_old );
  GC_SetXX( gc, gc_xx );
}

void GUI_EditCoordinates_OnKey( DISP_OBJ_COORD* disp_obj, int key, int unk, int repeat, int mode )
{
  if( mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT )
  {
    int scr_w = Display_GetWidth( UIDisplay_Main );
    int scr_h = Display_GetHeight( UIDisplay_Main );
    
    if( mode == KBD_SHORT_RELEASE )
      disp_obj->cstep = 1;
    else
      if( mode == KBD_REPEAT && repeat > 10 )
        disp_obj->cstep = 8;
    
    if( key == KEY_DIGITAL_0 + 1 )
    {
      if( ( disp_obj->x -= disp_obj->cstep ) < 0 )
        disp_obj->x = 0;
      if( ( disp_obj->y -= disp_obj->cstep ) < 0 )
        disp_obj->y = 0;
    }
    else if( key == KEY_DIGITAL_0 + 2 || key == KEY_UP )
    {
      if( ( disp_obj->y -= disp_obj->cstep ) < 0 )
        disp_obj->y = 0;
    }
    else if( key == KEY_DIGITAL_0 + 3 )
    {
      if( ( disp_obj->x += disp_obj->cstep ) > scr_w ) disp_obj->x = scr_w;
      if( ( disp_obj->y -= disp_obj->cstep ) < 0 ) disp_obj->y = 0;
    }
    else if( key == KEY_DIGITAL_0 + 4 || key == KEY_LEFT )
    {
      if(( disp_obj->x -= disp_obj->cstep ) < 0 ) disp_obj->x = 0;
    }
    else if( key == KEY_DIGITAL_0 + 6 || key == KEY_RIGHT )
    {
      if( ( disp_obj->x += disp_obj->cstep )>scr_w )
        disp_obj->x = scr_w;
    }
    else if( key == KEY_DIGITAL_0 + 7 )
    {
      if( ( disp_obj->x -= disp_obj->cstep ) < 0 ) disp_obj->x = 0;
      if( ( disp_obj->y += disp_obj->cstep )>scr_h ) disp_obj->y = scr_h;
    }
    else if( key == KEY_DIGITAL_0 + 8 || key == KEY_DOWN )
    {
      if( ( disp_obj->y += disp_obj->cstep )>scr_h ) disp_obj->y = scr_h;
    }
    else if( key == KEY_DIGITAL_0 + 9 )
    {
      if( ( disp_obj->x += disp_obj->cstep )>scr_w ) disp_obj->x = scr_w;
      if( ( disp_obj->y += disp_obj->cstep )>scr_h ) disp_obj->y = scr_h;
    }
    disp_obj->need_str = 1;
    
    if( key == KEY_ENTER || key == KEY_LEFT_SOFT || key == KEY_DIGITAL_0+5)
      GUI_EditCoordinates_OnOk( disp_obj->mbk, 0 );
    
    if( key == KEY_ESC )
      GUI_EditCoordinates_OnBack( disp_obj->mbk, 0 );
    
    if( key == KEY_RIGHT_SOFT )
      GUI_EditCoordinates_OnOrientationChange( disp_obj->mbk, 0 );
  }
  
  if( mode == KBD_LONG_RELEASE )
    disp_obj->cstep = 1;
  
  DispObject_InvalidateRect( disp_obj, NULL );
}

void GUI_EditCoordinates_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, Gui_Coordinates );
  DISP_DESC_SetSize( desc, sizeof(DISP_OBJ_COORD) );
  DISP_DESC_SetOnCreate( desc, (DISP_OBJ_ONCREATE_METHOD) GUI_EditCoordinates_OnCreate );
  DISP_DESC_SetOnClose( desc, (DISP_OBJ_ONCLOSE_METHOD) GUI_EditCoordinates_OnClose );
  DISP_DESC_SetOnRedraw( desc, (DISP_OBJ_ONREDRAW_METHOD) GUI_EditCoordinates_OnRedraw );
  DISP_DESC_SetOnKey( desc, (DISP_OBJ_ONKEY_METHOD) GUI_EditCoordinates_OnKey );
}

void GUI_EditCoordinates_destr( GUI* gui )
{
}

void GUI_EditCoordinates_OnOrientationChange( BOOK* book, GUI* gui )
{
  BookObj_SetDisplayOrientation( book, BookObj_GetDisplayOrientation( book ) ? UIDisplayOrientationMode_Vertical : UIDisplayOrientationMode_Horizontal );
};

void GUI_EditCoordinates_OnBack( BOOK* book, GUI* )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  DISP_OBJ_COORD* disp_obj = (DISP_OBJ_COORD*) GUIObject_GetDispObject( mbk->coord );
  int f = 0;
  
  if( disp_obj->type )
  {
    if( disp_obj->is_first_set )
    {
      disp_obj->is_first_set = 0;
      f = 1;
      DispObject_InvalidateRect( disp_obj, NULL );
    }
  }
  
  if( !f )
  {
    BookObj_SetDisplayOrientation( mbk, UIDisplayOrientationMode_Vertical );
    FREE_GUI(mbk->coord);
  }
}

void GUI_EditCoordinates_OnOk( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*) book;
  DISP_OBJ_COORD* disp_obj = (DISP_OBJ_COORD*) GUIObject_GetDispObject( mbk->coord );
  int f = 0;
  if( disp_obj->type )
  {
    if( !disp_obj->is_first_set )
    {
      disp_obj->x2 = disp_obj->x;
      disp_obj->y2 = disp_obj->y;
      disp_obj->is_first_set = 1;
      f = 1;
    }
    else
    {
      mbk->Str_x1 = MIN( disp_obj->x2, disp_obj->x );
      mbk->Str_y1 = MIN( disp_obj->y2, disp_obj->y );
      mbk->Str_x2 = MAX( disp_obj->x2, disp_obj->x );
      mbk->Str_y2 = MAX( disp_obj->y2, disp_obj->y );
	  
      if(mbk->IsBbar && mbk->IsFbar)
      {
        //snwprintf( myBook->buffer, 50, L"X1: %d, Y1: %d, X2: %d, Y2: %s",myBook->Str_x1,myBook->Str_y1,myBook->Str_x2,myBook->Str_y2);
        TEXTID SID[7];
        TEXTID TempSID = TextID_Create(", ",ENC_GSM,2);
        SID[0] = TextID_CreateIntegerID(mbk->Str_x1);
        SID[1] = TempSID;
        SID[2] = TextID_CreateIntegerID(mbk->Str_y1);
        SID[3] = TempSID;
        SID[4] = TextID_CreateIntegerID(mbk->Str_x2);
        SID[5] = TempSID;
        SID[6] = TextID_CreateIntegerID(mbk->Str_y2);
        TEXTID IDSID = TextID_Create(SID,ENC_TEXTID,7);
        ListMenu_SetItemSecondLineText( mbk->ProgressBar, 1, IDSID );
        //TextID_Destroy(TempSID);
      }
      else if(mbk->IsString)
      {
        snwprintf( mbk->buffer, 50, L"X: %d, Y: %d, Width: %d",mbk->Str_x1,mbk->Str_y1,mbk->Str_x2-mbk->Str_x1);
        ListMenu_SetItemSecondLineText( mbk->StringEdit, 1,TextID_Create(mbk->buffer,ENC_UCS2,0xFF) );
      }
      else if(mbk->IsCover)
      {
        LoadTempDataToBookHeader(mbk, mbk->ItemID);
        mbk->IsCover=0;
      }
    }
  }
  else
  {
    mbk->Str_x1 = disp_obj->x;
    mbk->Str_y1 = disp_obj->y;
    snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"X: %d, Y: %d", mbk->Str_x1,mbk->Str_y1);
    ListMenu_SetItemSecondLineText( mbk->IconEdit, 1, TextID_Create(mbk->buffer,ENC_UCS2,0xFF) );
  }
  
  if( !f )
  {
    BookObj_SetDisplayOrientation( mbk, UIDisplayOrientationMode_Vertical );
    FREE_GUI(mbk->coord);
    //RefreshEdList(bk);
  }
  mbk->ChangeMade = TRUE;
}

void Create_GUI_EditCoordinates( BOOK* book, int type )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  GUI_COORDINATES* gui_coord = (GUI_COORDINATES*)malloc(sizeof(GUI_COORDINATES));
  DISP_OBJ_COORD* disp_obj;
  if( !GUIObject_Create( gui_coord, GUI_EditCoordinates_destr, GUI_EditCoordinates_constr, mbk, NULL, UIDisplay_Main, sizeof(GUI_COORDINATES) ) )
  {
    mfree(gui_coord);
    //return 0;
  }
  disp_obj = (DISP_OBJ_COORD*) GUIObject_GetDispObject( gui_coord );
  if( type == 0 )
  {
    disp_obj->x = mbk->Str_x1;
    disp_obj->y = mbk->Str_y1;
  }
  else
  {
    disp_obj->old_rect.x1 = disp_obj->x = mbk->Str_x1;
    disp_obj->old_rect.y1 = disp_obj->y = mbk->Str_y1;
    disp_obj->old_rect.x2 = disp_obj->x2 = mbk->Str_x2;
    disp_obj->old_rect.y2 = disp_obj->y2 = mbk->Str_y2;
  }
  disp_obj->type = type;
  disp_obj->mbk = mbk;
  mbk->coord = gui_coord;
  
  if(mbk) BookObj_AddGUIObject( mbk, gui_coord );
  
  GUIObject_SetStyle( gui_coord, UI_OverlayStyle_TrueFullScreen );
  GUIObject_SetTitleType( gui_coord, UI_TitleMode_None );
  GUIObject_SoftKeys_Hide( gui_coord );
  GUIObject_SoftKeys_SetAction( gui_coord, ACTION_LONG_BACK, GUI_EditCoordinates_OnBack );
  GUIObject_Show( gui_coord );
}

// --------------------------------------------------------------------------------------------------------------------------------

#if defined(DB3150v1) || defined(DB3150)
wchar_t* GetFontNameByFontId( int id )
{
  wchar_t* txt = L"Undefined";
  FONT_DESC* font = GetFontDesc();
  int count = *GetFontCount();
  for ( int i = 0, max = count; i < max; i++ )
  {
    if ( id == font[i].id )
    {
      txt = font[i].name;
      break;
    }
  }
  return txt;
}

int GetIdByFontId( int font_id )
{
  int id = 0;
  FONT_DESC* font = GetFontDesc();
  int count = *GetFontCount();
  for ( int i = 0, max = count; i < max; i++ )
  {
    if ( font_id == font[i].id )
    {
      id = i;
      break;
    }
  }
  return id;
}
#endif

void CheckStringVisibility( DISP_OBJ_FONT_SEL* disp_obj, int x1, int y1, int x2, int y2, int y_offs )
{
  if ( disp_obj->cur_pos < disp_obj->cur_offs )
  {
    disp_obj->cur_offs = disp_obj->cur_pos;
  }
  else
  {
    int f = 0;
    do {
      int cur_y = y_offs;
      for ( int i = disp_obj->cur_offs, k = 0; i < disp_obj->total_fonts; i++ )
      {
        int sum;
        if ( disp_obj->cur_pos == i )
          k = 1;
        
        if ( ( ( sum = cur_y + disp_obj->font_heights[i] + 2 ) + 1 ) < y2 && k )
          f = 1;
        
        cur_y = sum;
        
        if ( cur_y  >  y2 )
          break;
      }
    } while( !f && ++disp_obj->cur_offs < disp_obj->total_fonts );
  }
}

int GUI_SelectFont_OnCreate( DISP_OBJ_FONT_SEL* disp_obj )
{
  disp_obj->item_textid = EMPTY_TEXTID;
  
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  disp_obj->total_fonts = max_size/font_step;
  disp_obj->font_heights = (u16*)malloc(sizeof(u16)*disp_obj->total_fonts);
  for ( int i = 0; i < disp_obj->total_fonts; i++ )
  {
    disp_obj->font_heights[i] = (i+1)*font_step;
  }
#else
  int font_old;
  disp_obj->total_fonts = *GetFontCount();
  disp_obj->font_heights = (u16*)malloc(sizeof(u16)*disp_obj->total_fonts);
  
  font_old = SetFont( FONT_E_20R );
  FONT_DESC* FontDesc = GetFontDesc();
  for ( int i = 0; i < disp_obj->total_fonts; i++ )
  {
    SetFont( FontDesc[i].id );
    disp_obj->font_heights[i] = GetImageHeight( ' ' );
  }
  SetFont( font_old );
#endif
  
  disp_obj->cur_offs = 0;
  disp_obj->req_check_vis = 1;
  return 1;
}

void GUI_SelectFont_OnClose( DISP_OBJ_FONT_SEL* disp_obj )
{
  TEXT_FREE( disp_obj->item_textid ); 
  mfree(disp_obj->font_heights);
}

void GUI_SelectFont_OnLayout(DISP_OBJ_FONT_SEL *disp_obj, void* layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clBlack);
}

void GUI_SelectFont_OnRedraw( DISP_OBJ_FONT_SEL* disp_obj, int a, RECT* cur_rc, int c )
{
  GC* pGC = get_DisplayGC();
  int font_old;
  int gc_xx;
  int x1, y1, x2, y2;
  int y_offs;
  TEXTID selfont;
  
  TextID_Destroy(disp_obj->item_textid);
  disp_obj->item_textid = TextID_Create(L"Test String 123", ENC_UCS2, TEXTID_ANY_LEN);
  
  gc_xx = GC_GetXX( pGC );
  GC_SetXX( pGC, 1 );
  
  x1 = cur_rc->x1;
  y1 = cur_rc->y1;
  x2 = cur_rc->x2;
  y2 = cur_rc->y2;
  y_offs = y1 + 20 + 2;
  
  if ( disp_obj->req_check_vis )
  {
    CheckStringVisibility( disp_obj, x1, y1, x2, y2, y_offs );
    disp_obj->req_check_vis = 0;
  }
  //DrawRect( x1, y1, x2, y2, clBlack, clBlack );
  
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  
  int n = 1;
  int sp[5];
  sp[0] = TextID_CreateIntegerID((disp_obj->cur_pos+1)*font_step);
  if (disp_obj->style_bold)
  {
    sp[n] = 0x78000000 + '_';
    sp[n+1] = 0x78000000 + 'B';
    n = n + 2;
  }
  if (disp_obj->style_italic)
  {
    sp[n] = 0x78000000 + '_';
    sp[n+1] = 0x78000000 + 'I';
    n = n + 2;
  }
  selfont = TextID_Create(sp,ENC_TEXTID,n);
  
  IFont* pFont = NULL;
  font_old = dll_SetFont( FONT_E_20R, &pFont );
  dll_DrawString(FONT_E_22R,
                 selfont,
                 UITextAlignment_Center, 
                 x1 + 3, 
                 y1 + 1, 
                 x2 - 2, 
                 y_offs - 1, 
                 0xFF0080FF );
  TEXT_FREE( selfont );
  int cur_y = y_offs;
  for ( int i = disp_obj->cur_offs; i < disp_obj->total_fonts; i++ )
  {
    int font, font_h;
    font_h = disp_obj->font_heights[i];
    font = font_h + (disp_obj->style_bold<<8) + (disp_obj->style_italic<<9);

    if (i == disp_obj->cur_pos) 
    {
      DrawRect( x1 + 1, cur_y, x2 - 1, cur_y + font_h + 2, 0xFF00FF00, 0xFF408000 );
    }
    dll_DrawString(font,
                   disp_obj->item_textid, 
                   UITextAlignment_Left, 
                   x1 + 2,
                   cur_y + 1,
                   x2 - 2,
                   cur_y + font_h + 1,
                   clWhite );
    
    cur_y += font_h + 2;
    if ( cur_y > y2 ) break;
  }
  dll_SetFont( font_old, &pFont );
#else
  FONT_DESC* FontDesc = GetFontDesc();
  
  font_old = SetFont( FONT_E_20R );
  selfont = TextID_Create( FontDesc[disp_obj->cur_pos].name, ENC_UCS2, 9 );
  DrawString(selfont,
             UITextAlignment_Left,
             x1 + 3,
             y1 + 1,
             x2 - 2,
             y_offs - 1,
             0, 0,
             0xFF0080FF, clEmpty );
  TEXT_FREE( selfont );
  
  int cur_y = y_offs;
  for ( int i = disp_obj->cur_offs; i < disp_obj->total_fonts; i++ )
  {
    int font, font_h;
    font_h = disp_obj->font_heights[i];
    font = FontDesc[i].id;
    SetFont( font );
    if (i == disp_obj->cur_pos) 
    {
      DrawRect( x1 + 1, cur_y, x2 - 1, cur_y + font_h + 2, 0xFF00FF00, 0xFF408000 );
    }
    DrawString(disp_obj->item_textid,
               UITextAlignment_Left,
               x1 + 2,
               cur_y + 1,
               x2 - 2,
               cur_y + font_h + 1,
               0, 0,
               clWhite, clEmpty
              );
    
    cur_y += font_h + 2;
    if ( cur_y > y2 ) break;
  }
  SetFont( font_old );
#endif
  
  GC_SetXX( pGC, gc_xx );
}

void GUI_SelectFont_OnKey( DISP_OBJ_FONT_SEL* disp_obj, int key, int, int repeat, int mode )
{
  if ( mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT )
  {
    if ( key == KEY_UP || key == KEY_DIGITAL_0 + 2 )
    {
      if ( ( -- disp_obj->cur_pos ) < 0 ) disp_obj->cur_pos = disp_obj->total_fonts - 1;
    }
    else if ( key == KEY_DOWN || key == KEY_DIGITAL_0 + 8 )
    {
      if ( ++disp_obj->cur_pos  >= disp_obj->total_fonts )
        disp_obj->cur_pos = 0;
    }
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    else if ( key == KEY_DEL )
    {
      if ((!disp_obj->style_bold)&&(!disp_obj->style_italic))
      {
        disp_obj->style_bold=1;
      }
      else if ((disp_obj->style_bold)&&(!disp_obj->style_italic))
      {
        disp_obj->style_bold = 0;
        disp_obj->style_italic = 1;
      }
      else if ((!disp_obj->style_bold)&&(disp_obj->style_italic))
      {
        disp_obj->style_bold = 1;
      }
      else if ((disp_obj->style_bold)&&(disp_obj->style_italic))
      {
        disp_obj->style_bold = 0;
        disp_obj->style_italic = 0;
      }
    }
#endif
    disp_obj->req_check_vis = 1;
    DispObject_InvalidateRect( disp_obj, NULL );
  }
}

void GUI_SelectFont_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, Gui_FontSelect );
  DISP_DESC_SetSize( desc, sizeof( DISP_OBJ_FONT_SEL ) );
  DISP_DESC_SetOnCreate( desc, ( DISP_OBJ_ONCREATE_METHOD )GUI_SelectFont_OnCreate );
  DISP_DESC_SetOnClose( desc, ( DISP_OBJ_ONCLOSE_METHOD )GUI_SelectFont_OnClose );
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD) GUI_SelectFont_OnLayout);
  DISP_DESC_SetOnRedraw( desc, ( DISP_OBJ_ONREDRAW_METHOD )GUI_SelectFont_OnRedraw );
  DISP_DESC_SetOnKey( desc, ( DISP_OBJ_ONKEY_METHOD )GUI_SelectFont_OnKey );
}

void GUI_SelectFont_destr( GUI* gui )
{
}

void GUI_SelectFont_OnBack( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  FREE_GUI(mbk->font_select);
}

void GUI_SelectFont_OnSelect( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  mbk->ChangeMade = TRUE;
  
  DISP_OBJ_FONT_SEL* disp_obj = (DISP_OBJ_FONT_SEL*) GUIObject_GetDispObject(mbk->font_select);
  
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  mbk->Str_Font_Size = (disp_obj->cur_pos+1)*font_step + (disp_obj->style_bold<<8) + (disp_obj->style_italic<<9);
  int Style = mbk->Str_Font_Size>>8;
  if (Style == Font_Normal)
  {
    snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_R",mbk->Str_Font_Size);///< normal
  }
  else if (Style == Font_Bold)
  {
    snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_B",mbk->Str_Font_Size&0xFF);///< bold
  }
  else if (Style == Font_Italic)
  {
    snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_I",mbk->Str_Font_Size&0xFF);///< italic
  }
  else if (Style == Font_BoldItalic)
  {
    snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_B_I",mbk->Str_Font_Size&0xFF);///< bold italic
  }
  ListMenu_SetItemSecondLineText( mbk->StringEdit, 3,TextID_Create(mbk->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
#else
  FONT_DESC* font = GetFontDesc();
  mbk->Str_Font_Size = font[disp_obj->cur_pos].id;
  ListMenu_SetItemSecondLineText( mbk->StringEdit, 3, TextID_Create(GetFontNameByFontId(mbk->Str_Font_Size),ENC_UCS2,TEXTID_ANY_LEN) );
#endif
  FREE_GUI(mbk->font_select);
}

void Create_GUI_SelectFont( BOOK* book )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  GUI_FONT_SEL* gui_fontsel = (GUI_FONT_SEL*)malloc(sizeof(GUI_FONT_SEL));
  DISP_OBJ_FONT_SEL* disp_obj;
  
  if ( !GUIObject_Create( gui_fontsel, GUI_SelectFont_destr, GUI_SelectFont_constr, mbk, NULL, UIDisplay_Main, sizeof(GUI_FONT_SEL) ) )
  {
     mfree(gui_fontsel);
  }
  
  disp_obj = (DISP_OBJ_FONT_SEL*) GUIObject_GetDispObject( gui_fontsel );
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  disp_obj->cur_pos = (mbk->Str_Font_Size&0xFF)/font_step-1;
  int style_flags = mbk->Str_Font_Size >> 8;
  disp_obj->style_bold = style_flags&bold;
  disp_obj->style_italic = (style_flags&italic) >> 1;
#else
  disp_obj->cur_pos = GetIdByFontId( mbk->Str_Font_Size );
#endif
  
  mbk->font_select = gui_fontsel;
  
  if (mbk) BookObj_AddGUIObject( mbk, gui_fontsel );
  
  GUIObject_SetTitleText( gui_fontsel, TEXT_FONT_SIZE );
  GUIObject_SetTitleType( gui_fontsel, UI_TitleMode_Small );
  GUIObject_SoftKeys_SetAction( gui_fontsel, ACTION_BACK, GUI_SelectFont_OnBack );
  GUIObject_SoftKeys_SetAction( gui_fontsel, ACTION_SELECT1, GUI_SelectFont_OnSelect );
  GUIObject_SoftKeys_SetItemOnKey( gui_fontsel, ACTION_SELECT1, KEY_DIGITAL_0+5, KBD_SHORT_PRESS );
  GUIObject_Show( gui_fontsel );
}
