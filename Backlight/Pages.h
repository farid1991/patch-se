#ifndef _PAGES_H_
#define _PAGES_H_

int Cancel_BasePage(void *r0, BOOK *book);
int BacklightControlBook_Main_Page_Enter_Event(void *r0, BOOK *book);
int BacklightControlBook_Main_Page_Exit_Event(void *r0, BOOK *book);

static const PAGE_MSG bk_base_msglst[] =
    {
        CANCEL_EVENT, Cancel_BasePage,
        RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
        NIL_EVENT, NULL};

static const PAGE_DESC BacklightControlBook_Base_Page = {"Backlight_Control_Base_Page", 0, bk_base_msglst};

static const PAGE_MSG bk_main_msglst[] =
    {
        PAGE_ENTER_EVENT, BacklightControlBook_Main_Page_Enter_Event,
        NIL_EVENT, NULL};

static const PAGE_DESC BacklightControlBook_Main_Page = {"BacklightControlBook_Main_Page", 0, bk_main_msglst};

#endif
