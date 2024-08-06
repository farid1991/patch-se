#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct : BOOK
{
  GUI *gui;
} PhoneNameBook;

extern "C"
{
  void onBackPressed(BOOK *bk, GUI *gui);
  void onLongBackPressed(BOOK *bk, GUI *gui);

  int pg_EditPhoneName_EnterEvent(void *, BOOK *bk);
  int pg_EditPhoneName_ExitEvent(void *, BOOK *bk);
  int pg_EditPhoneName_ReturnEvent(void *, BOOK *bk);

  int INetworkServices_GetNetworkName();
};

static const char EditOperatorNamePage[] = "EditOperatorName_Page";

int pg_EditOperatorName_EnterEvent(void *, BOOK *book);
int new_EditPhoneName_EnterEvent(void *r0, BOOK *book);

const PAGE_MSG evtlst_EditOperatorName[] =
    {
        PAGE_ENTER_EVENT, pg_EditOperatorName_EnterEvent,
#ifdef DB3350
        RETURN_TO_STANDBY_EVENT, pg_EditPhoneName_ReturnEvent,
#endif
        PAGE_EXIT_EVENT, pg_EditPhoneName_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_MSG evtlst_EditBluetoothName[] =
    {
        PAGE_ENTER_EVENT, pg_EditPhoneName_EnterEvent,
#ifdef DB3350
        RETURN_TO_STANDBY_EVENT, pg_EditPhoneName_ReturnEvent,
#endif
        PAGE_EXIT_EVENT, pg_EditPhoneName_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC EditBluetoothName_page = {(char *)EditPhoneNamePage, NULL, evtlst_EditBluetoothName};
const PAGE_DESC EditOperatorName_page = {EditOperatorNamePage, NULL, evtlst_EditOperatorName};

extern "C" const PAGE_MSG evtlst_EditPhoneName_new[] =
    {
        PAGE_ENTER_EVENT, new_EditPhoneName_EnterEvent,
#ifdef DB3350
        RETURN_TO_STANDBY_EVENT, pg_EditPhoneName_ReturnEvent,
#endif
        PAGE_EXIT_EVENT, pg_EditPhoneName_ExitEvent,
        NIL_EVENT, NULL};
#endif
