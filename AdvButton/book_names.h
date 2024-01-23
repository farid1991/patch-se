#ifndef _BOOK_NAMES_H_
#define _BOOK_NAMES_H_

static const char ChangeName_Page[] = "BookManager_ChangeName_Page";

int ChangeName_Enter_Event(void *data, BOOK *book);
int ChangeName_Exit_Event(void *data, BOOK *book);

void BookMan_RenameBook(BOOK *book, GUI *gui);

const PAGE_MSG ChangeName_PageEvents[] = {
    PAGE_ENTER_EVENT, ChangeName_Enter_Event,
    PAGE_EXIT_EVENT, ChangeName_Exit_Event,
    NIL_EVENT, NULL};

const PAGE_DESC BookManager_ChangeName_Page = {ChangeName_Page, NULL, ChangeName_PageEvents};

#endif
