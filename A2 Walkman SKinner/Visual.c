#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "Function.h"
#include "LNG.h"
#include "SaveLoad.h"
#include "Visual.h"
#include "Viz.h"
#include "Walkman.h"

int ColorGuiOnCreate( DISP_OBJ_COLOR* disp_obj )
{
  disp_obj->str_id = EMPTY_TEXTID;
  disp_obj->need_str = 1;
  disp_obj->current_column = 0;
  disp_obj->cstep = 1;
  return 1;
}

void ColorGuiOnClose( DISP_OBJ_COLOR* disp_obj )
{
  TEXT_FREE( disp_obj->str_id );
}

void ColorGuiOnRedraw( DISP_OBJ_COLOR* disp_obj, int, int, int )
{
  RECT rc_old;
  int font_old, gc_xx;
  int fsize = 20;
  GC* gc = get_DisplayGC();
  int column_height, column_width;
  int start_column, y_line;
  wchar_t ustr[32];
  int scr_w, scr_h, x1, y1;
  int testcolor;
  int colors[4] = { 0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0x80C6AAAF };
  
  GC_GetRect( gc, &rc_old );
  gc_xx = GC_GetXX( gc );
  GC_SetXX( gc, 1 );
  x1 = rc_old.x1;
  y1 = rc_old.y1;
  scr_w = rc_old.x2 - x1;
  scr_h = rc_old.y2 - y1;
  
  font_old = SetFont( FONT_E_20R );
  column_height = scr_h - (fsize*2); // - fsize;
  column_width = scr_w / 9;
  DrawRect( x1, y1, x1 + scr_w, y1 + scr_h, clWhite, clWhite );
  if( disp_obj->need_str )
  {
    snwprintf( ustr, MAXELEMS(ustr)-1, L"%02X, %02X, %02X, %02X", disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a );
    TextID_Destroy( disp_obj->str_id );
    disp_obj->str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
    disp_obj->need_str = 0;
  }
  DrawString(disp_obj->str_id, UITextAlignment_Left,
             x1 + 1, y1 + 1, x1 + scr_w - 30, y1 + 1 + fsize + 1,
             0, 0,
             clBlack, clEmpty );
  fsize += 3;
  
  for( int i = 0; i != 4; i++ )
  {
    start_column = column_width + 2 * i * column_width;
    column_height++; // Какая то фигня с DrawRect, координаты не совпадают с DrawLine. Оно и понятно, DrawRect не GC_.
    
    if( disp_obj->current_column == i )
      DrawRect( x1 + start_column - 2, y1 + fsize - 2, x1 + start_column + column_width + 2, y1 + fsize + column_height + 2, clBlack, clWhite );
    
    DrawRect( x1 + start_column, y1 + fsize, x1 + start_column + column_width, y1 + fsize + column_height, clBlack, colors[i] );
    column_height--;
    
    switch( i )
    {
    case 0:
      y_line = fsize + column_height - ( disp_obj->r * column_height ) / 0xFF;
      break;
    case 1:
      y_line = fsize + column_height - ( disp_obj->g * column_height ) / 0xFF;
      break;
    case 2:
      y_line = fsize + column_height - ( disp_obj->b * column_height ) / 0xFF;
      break;
    case 3:
      y_line = fsize + column_height - ( disp_obj->a * column_height ) / ( disp_obj->type == 0 ? 0x64 : 0xFF );
      break;
    }
    
    int old_pen = GC_GetPenColor( gc );
    GC_SetPenColor( gc, clBlack );
    GC_DrawLine( gc, x1 + start_column, y1 + y_line, x1 + start_column + column_width - 1, y1 + y_line );
    GC_SetPenColor( gc, old_pen );
  }
  testcolor = COLOR_RGBA( disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->type == 0 ? ( disp_obj->a * 0xFF / 0x64 ) : ( disp_obj->a ) );
  DrawRect( x1 + scr_w - fsize - 1, y1 + 1, x1 + scr_w - 1, y1 + fsize + 1, clBlack, testcolor );
  
  SetFont( font_old );
  GC_SetXX( gc, gc_xx );
}

void ColorGuiOnKey( DISP_OBJ_COLOR* disp_obj, int key, int, int repeat, int type )
{
  if( type == KBD_SHORT_RELEASE || type == KBD_REPEAT )
  {
    if( type == KBD_SHORT_RELEASE )
      disp_obj->cstep = 1;
    else
      if( type == KBD_REPEAT && repeat  >  10 )
        disp_obj->cstep = 8;
    
    if( key == KEY_UP || key == KEY_DIGITAL_0 + 2 )
    {
      switch( disp_obj->current_column )
      {
      case 0:
        if(( disp_obj->r += disp_obj->cstep ) >0xFF )
          disp_obj->r = 0;
        break;
      case 1:
        if(( disp_obj->g += disp_obj->cstep ) >0xFF )
          disp_obj->g = 0;
        break;
      case 2:
        if(( disp_obj->b += disp_obj->cstep ) >0xFF )
          disp_obj->b = 0;
        break;
      case 3:
        if(( disp_obj->a += disp_obj->cstep ) > ( disp_obj->type == 0 ? 0x64 : 0xFF ) )
          disp_obj->a = 0;
        break;
      }
      
      disp_obj->need_str = 1;
    }
    else if( key == KEY_DOWN || key == KEY_DIGITAL_0 + 8 )
    {
      switch( disp_obj->current_column )
      {
      case 0:
        if( ( disp_obj->r -= disp_obj->cstep ) < 0 )
          disp_obj->r = 0xFF;
        break;
      case 1:
        if( ( disp_obj->g -= disp_obj->cstep ) < 0 )
          disp_obj->g = 0xFF;
        break;
      case 2:
        if( ( disp_obj->b -= disp_obj->cstep ) < 0 )
          disp_obj->b = 0xFF;
        break;
      case 3:
        if( ( disp_obj->a -= disp_obj->cstep ) < 0 )
          disp_obj->a = disp_obj->type == 0 ? 0x64 : 0xFF;
          break;
      }
      
      disp_obj->need_str = 1;
    }
    else if( key == KEY_LEFT || key == KEY_DIGITAL_0 + 4 )
    {
      if( --disp_obj->current_column < 0 )
        disp_obj->current_column = 3;
    }
    else if( key == KEY_RIGHT || key == KEY_DIGITAL_0 + 6 )
    {
      if( ++disp_obj->current_column  >  3 )
        disp_obj->current_column = 0;
    }
  }
  
  if( type == KBD_LONG_RELEASE )
    disp_obj->cstep = 1;
  
  DispObject_InvalidateRect( disp_obj, NULL );
}

void EditColorGui_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, Gui_EditColor );
  DISP_DESC_SetSize( desc, sizeof(DISP_OBJ_COLOR) );
  DISP_DESC_SetOnCreate( desc, (DISP_OBJ_ONCREATE_METHOD) ColorGuiOnCreate );
  DISP_DESC_SetOnClose( desc, (DISP_OBJ_ONCLOSE_METHOD) ColorGuiOnClose );
  DISP_DESC_SetOnRedraw( desc, (DISP_OBJ_ONREDRAW_METHOD) ColorGuiOnRedraw );
  DISP_DESC_SetOnKey( desc, (DISP_OBJ_ONKEY_METHOD) ColorGuiOnKey );
}

void EditColorGui_destr( GUI* gui )
{
}

void OnBackColorEdit( BOOK* book, GUI* gui)
{
  MyBOOK* myBook = (MyBOOK*) book;
  FREE_GUI(myBook->color);
  //FreeBook(myBook);
}

void OnOkColorEdit( BOOK* bk, GUI* )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  myBook->ChangeMade = TRUE;
  
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*) GUIObject_GetDispObject( myBook->color );
  if( disp_obj->type == 0 )
  {
    //myBook->cur_hp.color->rgb[0] = disp_obj->r;
    //myBook->cur_hp.color->rgb[1] = disp_obj->g;
    //myBook->cur_hp.color->rgb[2] = disp_obj->b;
    //myBook->cur_hp.color->rgb[3] = disp_obj->a;
  }
  else
  {
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
    
  }
  FREE_GUI(myBook->color);
  //FreeBook(myBook);
  //RefreshEdList(bk);
}

void CreateEditColorGUI( MyBOOK* myBook, int type )
{
  //wchar_t ustr[32];
  GUI_COLOR* gui_color = (GUI_COLOR*)malloc(sizeof(GUI_COLOR));
  DISP_OBJ_COLOR* disp_obj;
  
  if( !GUIObject_Create( gui_color, EditColorGui_destr, EditColorGui_constr, myBook, NULL, UIDisplay_Main, sizeof(GUI_COLOR) ) )
  {
    myBook->color = NULL;
    mfree(gui_color);
    //return 0;
  }
  
  disp_obj = (DISP_OBJ_COLOR*) GUIObject_GetDispObject( gui_color );
  
  if( type == 0 )
  {
    //disp_obj->r = myBook->cur_hp.color->rgb[0];
    //disp_obj->g = myBook->cur_hp.color->rgb[1];
    //disp_obj->b = myBook->cur_hp.color->rgb[2];
    //disp_obj->a = myBook->cur_hp.color->rgb[3];
  }
  else
  {
    if((myBook->IsBbar)||(myBook->IsString))
    {
      int color = myBook->Str_Color;
      disp_obj->r = COLOR_GET_R( color );
      disp_obj->g = COLOR_GET_G( color );
      disp_obj->b = COLOR_GET_B( color );
      disp_obj->a = COLOR_GET_A( color );
    }
    else if(myBook->IsFbar)
    {
      int color = myBook->Str_Color_2;
      disp_obj->r = COLOR_GET_R( color );
      disp_obj->g = COLOR_GET_G( color );
      disp_obj->b = COLOR_GET_B( color );
      disp_obj->a = COLOR_GET_A( color );
    }
  }
  
  disp_obj->type = type;
  
  myBook->color = gui_color;
  
  if(myBook) BookObj_AddGUIObject( myBook, gui_color );
  
  // GUIObject_SetStyle( myBook->color, 4 );
  //win12512unicode( ustr, myBook->cur_hp.color->name, MAXELEMS( ustr ) - 1 );
  GUIObject_SetTitleText( gui_color, TEXT_COLOR );
  GUIObject_SetTitleType( gui_color, UI_TitleMode_Small );
  // GUIObject_SoftKeys_Hide( myBook->color );
  GUIObject_SoftKeys_SetAction( gui_color, ACTION_BACK, OnBackColorEdit );
  GUIObject_SoftKeys_SetActionAndText( gui_color, ACTION_SELECT1, OnOkColorEdit, TEXT_OK );
  GUIObject_SoftKeys_SetItemOnKey( gui_color, ACTION_SELECT1, KEY_DIGITAL_0+5, KBD_SHORT_PRESS );
  GUIObject_Show( gui_color );
  //return gui_color;
}

// --------------------------------------------------------------------------------------------------------------------------------


IMAGEID Get_Skin_ItemImageId( int id )
{
  WALKMAN_Function * WData = Get_WALKMAN_Function();
  int index = id - 11;
  
  return WData->SkinItemImageID[index].ImageID;
}

void LoadBGImage()
{
  WALKMAN_Function * WData = Get_WALKMAN_Function();
  
  WData->SkinItemName[1]=L"MP_MODE_RANDOM_ICN.png";   // book->ItemID=11;
  WData->SkinItemName[0]=L"MP_MODE_LOOP_ICN.png";   // book->ItemID=12;
  WData->SkinItemName[2]=L"MP_EQ_MANUAL_ICN.png";   // book->ItemID=13;
  WData->SkinItemName[3]=L"MP_PLAY_ICN.png";         // book->ItemID=14;
  WData->SkinItemName[4]=L"MP_ARTIST_ICN.png";      // book->ItemID=15;
  WData->SkinItemName[5]=L"MP_TRACK_ICN.png";       // book->ItemID=16;
  WData->SkinItemName[6]=L"MP_ALBUM_ICN.png";       // book->ItemID=17;
  WData->SkinItemName[7]=L"MC_WHEEL_BACKGROUND_ICN.png"; // book->ItemID=18;
  WData->SkinItemName[8]=L"MC_WHEEL_UP_ICN.png";    // book->ItemID=19;
  WData->SkinItemName[9]=L"MC_WHEEL_DOWN_ICN.png";  // book->ItemID=20;
  WData->SkinItemName[10]=L"MC_WHEEL_PREV_ICN.png";  // book->ItemID=21;
  WData->SkinItemName[11]=L"MC_WHEEL_NEXT_ICN.png";  // book->ItemID=22;
  WData->SkinItemName[12]=L"MC_WHEEL_PLAY_ICN.png";  // book->ItemID=23;
  WData->SkinItemName[13]=L"MP_BG_PT.png";            // book->ItemID=24;
  WData->SkinItemName[14]=L"MP_BG_LD.png";            // book->ItemID=24;

  int i;
  for (i = 0 ; i < 15 ; i++)
  {
    if(FSX_IsFileExists(WData->SkinPath,WData->SkinItemName[i]))
    {
      RegisterImage(&WData->SkinItemImageID[i], WData->SkinPath, WData->SkinItemName[i]);
    }
    else
    {
      WData->SkinItemImageID[i].ImageID = NOIMAGE;
    }
  }
}

void FreeBGImage()
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  WALKMAN_Function * WData = Get_WALKMAN_Function();
  
  WData->SkinItemName[1]=L"MP_MODE_RANDOM_ICN.png";   // book->ItemID=11;
  WData->SkinItemName[0]=L"MP_MODE_LOOP_ICN.png";   // book->ItemID=12;
  WData->SkinItemName[2]=L"MP_EQ_MANUAL_ICN.png";   // book->ItemID=13;
  WData->SkinItemName[3]=L"MP_PLAY_ICN.png";         // book->ItemID=14;
  WData->SkinItemName[4]=L"MP_ARTIST_ICN.png";      // book->ItemID=15;
  WData->SkinItemName[5]=L"MP_TRACK_ICN.png";       // book->ItemID=16;
  WData->SkinItemName[6]=L"MP_ALBUM_ICN.png";       // book->ItemID=17;
  WData->SkinItemName[7]=L"MC_WHEEL_BACKGROUND_ICN.png"; // book->ItemID=18;
  WData->SkinItemName[8]=L"MC_WHEEL_UP_ICN.png";    // book->ItemID=19;
  WData->SkinItemName[9]=L"MC_WHEEL_DOWN_ICN.png";  // book->ItemID=20;
  WData->SkinItemName[10]=L"MC_WHEEL_PREV_ICN.png";  // book->ItemID=21;
  WData->SkinItemName[11]=L"MC_WHEEL_NEXT_ICN.png";  // book->ItemID=22;
  WData->SkinItemName[12]=L"MC_WHEEL_PLAY_ICN.png";  // book->ItemID=23;
  WData->SkinItemName[13]=L"MP_BG_PT.png";            // book->ItemID=24;
  WData->SkinItemName[14]=L"MP_BG_LD.png";            // book->ItemID=24;
  //WData->SkinItemName[15]=L"OVERLAY_IMAGE_P.png";   // book->ItemID=24;
  //WData->SkinItemName[16]=L"OVERLAY_IMAGE_L.png";   // book->ItemID=24;
  
  for (int i = 0 ; i < 15 ; i++)
  {
    if( FSX_IsFileExists(WData->SkinPath,WData->SkinItemName[i])) 
    {
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC,WData->SkinItemImageID[i].ImageHandle,0,0,WData->SkinItemImageID[i].ImageID,1,&error_code);
    }
    else
    {
      WData->SkinItemImageID[i].ImageID = NOIMAGE;
    }
  }
}

int CoordinatesGuiOnCreate( DISP_OBJ_COORD* disp_obj )
{
  LoadBGImage();
  disp_obj->str_id = EMPTY_TEXTID;
  disp_obj->need_str = 1;
  disp_obj->is_first_set = 0;
  disp_obj->cstep = 1;
  return 1;
}

void CoordinatesGuiOnClose( DISP_OBJ_COORD* disp_obj )
{
  TEXT_FREE( disp_obj->str_id );
  FreeBGImage();
}

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
  else
    DrawRect( x1, y1, x2, y2, pen_color, brush_color );
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

void CoordinatesGuiOnRedraw( DISP_OBJ_COORD* disp_obj, int a, int b, int c )
{
  WALKMAN_Function * Data = Get_WALKMAN_Function();

  RECT rc_old, rc_new;
  int font_old, gc_xx;

  int fsize = 20;
  int colors[4] = { clRed, clGreen, clBlue, 0x80C6AAAF };
  
  GC* gc = get_DisplayGC();
  wchar_t ustr[32];
  int old_pen;
  
  int scr_w = 240; //Display_GetWidth(0);
  int scr_h = 320; //Display_GetHeight(0);
  
  GC_GetRect( gc, &rc_old );
  gc_xx = GC_GetXX( gc );
  GC_SetXX( gc, 1 );
  
  rc_new.x1 = 0;
  rc_new.x2 = scr_w;
  rc_new.y1 = 0;
  rc_new.y2 = scr_h;
  GC_ValidateRect( gc, &rc_new );
  
  font_old = SetFont( FONT_E_20R );
  DrawRect( 0, 0, scr_w, scr_h, clWhite, clWhite );
  
  /*
  if(BookObj_GetDisplayOrientation(disp_obj->mb)==0)
  {
    DrawIcon( Data->BGImageID[1].ImageID, 0, 0 );
  }
  else 
  {
    DrawIcon( Data->BGImageID[0].ImageID, 0, 0 );
  }
  */
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
  
  if( disp_obj->type ) // Если нужен рект
  {
    DrawOwnRect( disp_obj->old_rect.x1, disp_obj->old_rect.y1, disp_obj->old_rect.x2, disp_obj->old_rect.y2, 0xC0808080, clEmpty ); // Нарисуем старый рект
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
    WALKMAN_Function* Data = Get_WALKMAN_Function();
    if(BookObj_GetDisplayOrientation(disp_obj->mb)==0)
    {
      DrawIcon(Data->SkinItemImageID[13].ImageID,0,0);
    }
    else
    {
      DrawIcon(Data->SkinItemImageID[14].ImageID,0,0);
    }
    
    int itemID = ((MyBOOK*)(disp_obj->mb))->ItemID;
    
    if(itemID>10 && itemID<24)
    {
      DrawIcon(Get_Skin_ItemImageId(itemID),disp_obj->x, disp_obj->y);
    }
    
    if( disp_obj->need_str )
    {
      snwprintf( ustr, MAXELEMS(ustr)-1, L"%d, %d", disp_obj->x, disp_obj->y );
      TextID_Destroy( disp_obj->str_id );
      disp_obj->str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      disp_obj->need_str = 0;
    }
  }
  
  DrawString(disp_obj->str_id, 0,
             3, scr_h - fsize - 2, scr_w - 4, scr_h - 1,
             0, 0,
             clBlack, clEmpty );
  
  old_pen = GC_GetPenColor( gc );
  GC_SetPenColor( gc, clBlack );
  GC_DrawLine( gc, disp_obj->x - 3, disp_obj->y, disp_obj->x + 3, disp_obj->y );
  GC_DrawLine( gc, disp_obj->x, disp_obj->y - 3, disp_obj->x, disp_obj->y + 3 );
  
  if( BookObj_GetDisplayOrientation( disp_obj->mb ) == 0 )
  {
    DrawArrow( scr_w - 19, scr_h - 13, clBlack );
  }
  else
  {
    DrawArrow( scr_w - 19, 3, clBlack );
  }
  GC_SetPenColor( gc, old_pen );
  GC_ValidateRect( gc, &rc_old );
  SetFont( font_old );
  GC_SetXX( gc, gc_xx );
}

void CoordinatesGuiOnKey( DISP_OBJ_COORD* disp_obj, int key, int unk, int repeat, int type )
{
  if( type == KBD_SHORT_RELEASE || type == KBD_REPEAT )
  {
    int scr_w = SCN_WIDTH; //Display_GetWidth( 0 );
    int scr_h = SCN_HEIGHT; //Display_GetHeight( 0 );
    
    if( type == KBD_SHORT_RELEASE )
      disp_obj->cstep = 1;
    else
      if( type == KBD_REPEAT && repeat > 10 )
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
      OnOkCoordinatesEdit( disp_obj->mb, 0 );
    
    if( key == KEY_ESC )
      OnBackCoordinatesEdit( disp_obj->mb, 0 );
    
    if( key == KEY_RIGHT_SOFT )
      OnOrientationChangeCoordinatesEdit( disp_obj->mb, 0 );
  }
  
  if( type == KBD_LONG_RELEASE )
    disp_obj->cstep = 1;
  
  DispObject_InvalidateRect( disp_obj, NULL );
}

void EditCoordinatesGui_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, Gui_Coordinates );
  DISP_DESC_SetSize( desc, sizeof(DISP_OBJ_COORD) );
  DISP_DESC_SetOnCreate( desc, (DISP_OBJ_ONCREATE_METHOD) CoordinatesGuiOnCreate );
  DISP_DESC_SetOnClose( desc, (DISP_OBJ_ONCLOSE_METHOD) CoordinatesGuiOnClose );
  DISP_DESC_SetOnRedraw( desc, (DISP_OBJ_ONREDRAW_METHOD) CoordinatesGuiOnRedraw );
  DISP_DESC_SetOnKey( desc, (DISP_OBJ_ONKEY_METHOD) CoordinatesGuiOnKey );
}

void EditCoordinatesGui_destr( GUI* gui )
{
}

void OnOrientationChangeCoordinatesEdit( BOOK* book, GUI* gui )
{
  BookObj_SetDisplayOrientation( book, BookObj_GetDisplayOrientation( book ) ? UIDisplayOrientationMode_Vertical : UIDisplayOrientationMode_Horizontal );
};

void OnBackCoordinatesEdit( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
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

void OnBackCoordEdit( BOOK* book, GUI* )
{
  OnBackCoordinatesEdit(book, NULL);
}

void OnOkCoordinatesEdit( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*) book;
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

void CreateEditCoordinatesGUI( MyBOOK* mbk, int type )
{
  GUI_COORDINATES* gui_coord = (GUI_COORDINATES*)malloc(sizeof(GUI_COORDINATES));
  DISP_OBJ_COORD* disp_obj;
  if( !GUIObject_Create( gui_coord, EditCoordinatesGui_destr, EditCoordinatesGui_constr, mbk, NULL, UIDisplay_Main, sizeof(GUI_COORDINATES) ) )
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
  disp_obj->mb = mbk;
  mbk->coord = gui_coord;
  
  if(mbk) BookObj_AddGUIObject( mbk, gui_coord );
  
  GUIObject_SetStyle( gui_coord, UI_OverlayStyle_TrueFullScreen );
  GUIObject_SetTitleType( gui_coord, UI_TitleMode_None );
  GUIObject_SoftKeys_Hide( gui_coord );
  GUIObject_SoftKeys_SetAction( gui_coord, ACTION_LONG_BACK, OnBackCoordEdit );
  GUIObject_Show( gui_coord );
  //return gui_coord;
}

// --------------------------------------------------------------------------------------------------------------------------------

void OnBackFontSelect( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FREE_GUI(mbk->font_select);
  //FreeBook(myBook);
}

wchar_t* Font_GetNameByFontId( int id )
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

void OnOkFontSelect( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  mbk->ChangeMade = TRUE;
    
  FONT_DESC* font = GetFontDesc();
  DISP_OBJ_FONT_SEL* disp_obj = (DISP_OBJ_FONT_SEL*) GUIObject_GetDispObject(mbk->font_select);
  mbk->Str_Font_Size = font[disp_obj->cur_pos].id;
  ListMenu_SetItemSecondLineText( mbk->StringEdit, 3, TextID_Create(Font_GetNameByFontId(mbk->Str_Font_Size),ENC_UCS2,TEXTID_ANY_LEN) );
  FREE_GUI(mbk->font_select);
}

int FontSelectGuiOnCreate( DISP_OBJ_FONT_SEL* disp_obj )
{
  //WALKMAN_Function * Data = Get_WALKMAN_Function();
  int font_old;
  disp_obj->test_str_id = STR("Test string 123");
  disp_obj->total_fonts =  *GetFontCount();
  //disp_obj->font_heights = new u16[disp_obj->total_fonts];
  disp_obj->font_heights = (u16*)malloc(sizeof(u16)*disp_obj->total_fonts);
  
  font_old = SetFont( FONT_E_20R );
  FONT_DESC* OnCreateFontDescp = GetFontDesc();
  for ( int i = 0; i < disp_obj->total_fonts; i++ )
  {
    SetFont( OnCreateFontDescp[i].id );
    disp_obj->font_heights[i] = GetImageHeight( ' ' );
  }
  SetFont( font_old );
  
  disp_obj->cur_offs = 0;
  disp_obj->req_check_vis = 1;
  return 1;
}

void FontSelectGuiOnClose( DISP_OBJ_FONT_SEL* disp_obj )
{
  TEXT_FREE( disp_obj->test_str_id ); 
  mfree(disp_obj->font_heights);
}

void CheckStringVisibility( DISP_OBJ_FONT_SEL* disp_obj, int x1, int y1, int x2, int y2, int y_offs )
{
  if ( disp_obj->cur_pos < disp_obj->cur_offs ) // no?iea auoa niauaiey, iiaieiaai niauaiea
  {
    disp_obj->cur_offs = disp_obj->cur_pos;
  }
  else // eia?a i?iaa?yai a ciia aeaeiinoe ee iu, anee iao oi iioneaainy iiea ia oaeaei
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

void FontSelectGuiOnRedraw( DISP_OBJ_FONT_SEL* disp_obj, int, RECT* cur_rc, int )
{
  int font_old, gc_xx;
  GC* gc = get_DisplayGC();
  int x1, y1, x2, y2;
  int y_offs;
  int selfont;
  
  FONT_DESC* OnCreateFontDescp = GetFontDesc();
  gc_xx = GC_GetXX( gc );
  GC_SetXX( gc, 1 );
  
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
  
  font_old = SetFont( FONT_E_20R );
  DrawRect( x1, y1, x2, y2, clBlack, clBlack );
  selfont = TextID_Create( OnCreateFontDescp[disp_obj->cur_pos].name, ENC_UCS2, 9 );
  DrawString(selfont, UITextAlignment_Left,
             x1 + 3, y1 + 1, x2 - 2, y_offs - 1,
             0, 0,
             0xFF0080FF, 0x00000000 
            ); // ?enoai aua?aiiue o?eoo a oaiea iai?
  
  TextID_Destroy( selfont ); 
  int cur_y = y_offs;
  for ( int i = disp_obj->cur_offs; i < disp_obj->total_fonts; i++ )
  {
    int font, font_h;
    font_h = disp_obj->font_heights[i];
    font = OnCreateFontDescp[i].id;
    SetFont( font );
    if ( i == disp_obj->cur_pos ) DrawRect( x1 + 1, cur_y, x2 - 1, cur_y + font_h + 2, 0xFF00FF00, 0xFF408000 );
    DrawString(disp_obj->test_str_id, UITextAlignment_Left,
               x1 + 2, cur_y + 1, x2 - 2, cur_y + font_h + 1,
               0, 0,
               clWhite, clEmpty
              );
    cur_y += font_h + 2;
    if ( cur_y>y2 ) break;
  }
  SetFont( font_old );
  GC_SetXX( gc, gc_xx );
}


void FontSelectGuiOnKey( DISP_OBJ_FONT_SEL* disp_obj, int key, int, int repeat, int type )
{
  if ( type == KBD_SHORT_RELEASE || type == KBD_REPEAT )
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
    disp_obj->req_check_vis = 1;
    DispObject_InvalidateRect( disp_obj, NULL );
  }
}

void FontSelectGui_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, Gui_FontSelect );
  DISP_DESC_SetSize( desc, sizeof( DISP_OBJ_FONT_SEL ) );
  DISP_DESC_SetOnCreate( desc, ( DISP_OBJ_ONCREATE_METHOD )FontSelectGuiOnCreate );
  DISP_DESC_SetOnClose( desc, ( DISP_OBJ_ONCLOSE_METHOD )FontSelectGuiOnClose );
  DISP_DESC_SetOnRedraw( desc, ( DISP_OBJ_ONREDRAW_METHOD )FontSelectGuiOnRedraw );
  DISP_DESC_SetOnKey( desc, ( DISP_OBJ_ONKEY_METHOD )FontSelectGuiOnKey );
}

void FontSelectGui_destr( GUI* gui )
{
}

void CreateFontSelectGUI( MyBOOK* myBook )
{
  GUI_FONT_SEL* gui_fontsel = (GUI_FONT_SEL*)malloc(sizeof(GUI_FONT_SEL));
  DISP_OBJ_FONT_SEL* disp_obj;
  
  if ( !GUIObject_Create( gui_fontsel, FontSelectGui_destr, FontSelectGui_constr, myBook, NULL, UIDisplay_Main, sizeof(GUI_FONT_SEL) ) )
  {
     mfree(gui_fontsel);
  }
  
  disp_obj = (DISP_OBJ_FONT_SEL*) GUIObject_GetDispObject( gui_fontsel );
  disp_obj->cur_pos = GetIdByFontId( myBook->Str_Font_Size );
  myBook->font_select = gui_fontsel;
  
  if (myBook) BookObj_AddGUIObject( myBook, gui_fontsel );
  
  GUIObject_SetTitleText( gui_fontsel, TEXT_FONT_SIZE );
  GUIObject_SetTitleType( gui_fontsel, UI_TitleMode_Small );
  GUIObject_SoftKeys_SetAction( gui_fontsel, ACTION_BACK, OnBackFontSelect );
  GUIObject_SoftKeys_SetAction( gui_fontsel, ACTION_SELECT1, OnOkFontSelect );
  GUIObject_SoftKeys_SetItemOnKey( gui_fontsel, ACTION_SELECT1, KEY_DIGITAL_0+5, KBD_SHORT_PRESS );
  GUIObject_Show( gui_fontsel );
}
