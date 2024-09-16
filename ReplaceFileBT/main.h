#ifndef _MAIN_H_
#define _MAIN_H_

#define EMP_NAME "r_emp"
#define MEM_NAME "r_mem"

typedef struct _FILE_DATA
{
  bool state;
} FILE_DATA;

int pg_ReplaceFile_EnterEvent(void *data, BOOK *book);
int pg_ReplaceFile_ExitEvent(void *data, BOOK *book);

const PAGE_MSG evtlst_DataDownload_ReplaceFile[] =
    {
        PAGE_ENTER_EVENT, pg_ReplaceFile_EnterEvent,
        PAGE_EXIT_EVENT, pg_ReplaceFile_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC DataDownload_ReplaceFile_Page = {"DataDownload_ReplaceFile_Page", NULL, evtlst_DataDownload_ReplaceFile};

extern "C" void DataDownloadBook_onClose(BOOK *book);

#endif
