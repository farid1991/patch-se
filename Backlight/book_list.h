#ifndef _BOOK_LISTS_H_
#define _BOOK_LISTS_H_

#define ITEM_BOOK_ICN 0xF874

void BookLists_FreeList( BOOK* book );
TEXTID GetJavaName( BOOK* book );
TEXTID GetBookName( BOOK* book );

void Backlight_BookListsMenu(BOOK *book);

#endif
