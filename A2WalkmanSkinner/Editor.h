#ifndef _SelectFont_H_
#define _SelectFont_H_

//==============================================================================

enum 
{
  COORD_POINT,
  COORD_RECT
};

void EditColor( BOOK* book );
void EditCoordinates( BOOK* book, int type );
void SelectFont( BOOK* book );

void Editor_Slider(BOOK* book);
void Editor_ItemIcon(BOOK* book);
void Editor_ItemText(BOOK* book);

#endif
