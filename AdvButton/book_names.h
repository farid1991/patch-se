#ifndef _BOOK_NAMES_H_
#define _BOOK_NAMES_H_

int ChangeName_Enter_Event(void *data, BOOK *book);
int ChangeName_Exit_Event(void *data, BOOK *book);

void BookMan_RenameBook(BOOK *book, GUI *gui);

const PAGE_MSG ChangeName_PageEvents[] = {
    PAGE_ENTER_EVENT, ChangeName_Enter_Event,
    PAGE_EXIT_EVENT, ChangeName_Exit_Event,
    NIL_EVENT, 0};

const PAGE_DESC BookManager_ChangeName_page = {"BookManager_ChangeName_Page", 0, ChangeName_PageEvents};

#endif
