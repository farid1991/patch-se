#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "bookman.h"
#include "main.h"
#include "book_names.h"

char *GetOriginalBookName(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BOOK_LIST_ITEM *elem = GetBookListItem(bookman, bookman->active_tab);
  return (elem->book_name);
}

void onPrevious_SI(BOOK *book, wchar_t *new_name, int len)
{
  BookObj_ReturnPage(book, ACCEPT_EVENT);
}

void onAccept_SI(BOOK *book, wchar_t *new_name, int len)
{
  BookManager *bookman = (BookManager *)book;
  int file;
  wchar_t *pos;
  wchar_t *pos_uni_pair;
  wchar_t cur_name[MAX_BOOK_NAME_LEN + 1];
  wchar_t orig_name[MAX_BOOK_NAME_LEN + 1];

  str2wstr(orig_name, GetOriginalBookName(bookman));

  pos_uni_pair = GetUserBookName(bookman->booknames_buf, orig_name, cur_name);

  int new_name_len = wstrlen(new_name);
  int cur_name_len = wstrlen(cur_name);
  int orig_name_len = wstrlen(orig_name);

  if ((!len) || ((!wstrcmp(orig_name, new_name)) && (new_name_len == orig_name_len)))
  {
    if (pos_uni_pair)
    {
      if ((file = _fopen(BOOKMAN_PATH, INI_BOOK_NAMES, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= NULL)
      {
        // Delete
        pos = wstrwstr(pos_uni_pair, L"\r\n") + sizeof("\r\n") - sizeof("");

        fwrite(file, bookman->booknames_buf, (pos_uni_pair - bookman->booknames_buf) * sizeof(wchar_t));   // write the beginning of the file
        fwrite(file, pos, bookman->booknames_buf_size - (pos - bookman->booknames_buf) * sizeof(wchar_t)); // write the rest of the file
        fclose(file);
      }
    }
  }
  else
  {
    if ((wstrcmp(cur_name, new_name)) || ((!wstrcmp(cur_name, new_name)) && (new_name_len != cur_name_len)))
    {
      if (pos_uni_pair)
      {
        if ((file = _fopen(BOOKMAN_PATH, INI_BOOK_NAMES, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= NULL)
        {
          // ReWrite
          pos = pos_uni_pair + wstrlen(orig_name) + sizeof(": ") - sizeof("");
          int len_minus = wstrlen(cur_name); // length of the old name

          fwrite(file, bookman->booknames_buf, (pos - bookman->booknames_buf) * sizeof(wchar_t));                                      // write the beginning of the file
          fwrite(file, new_name, new_name_len * sizeof(wchar_t));                                                                      // write a new name
          fwrite(file, pos + len_minus, bookman->booknames_buf_size - ((pos - bookman->booknames_buf) + len_minus) * sizeof(wchar_t)); // write the rest of the file
          fclose(file);
        }
      }
      else
      {
        if ((file = _fopen(BOOKMAN_PATH, INI_BOOK_NAMES, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= NULL)
        {
          // Append
          fwrite(file, bookman->booknames_buf, bookman->booknames_buf_size); // write old file
          fwrite(file, orig_name, wstrlen(orig_name) * sizeof(wchar_t));
          fwrite(file, L": ", (sizeof(L": ") - sizeof(wchar_t)));
          fwrite(file, new_name, wstrlen(new_name) * sizeof(wchar_t));
          fwrite(file, L"\r\n", (sizeof(L"\r\n") - sizeof(wchar_t)));
          fclose(file);
        }
      }
    }
  }
  LoadBookNames(bookman);
  BookObj_ReturnPage(bookman, ACCEPT_EVENT);
}

int ChangeName_Enter_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  TEXTID editable_strID = GetUserBookNameTEXTID(GetOriginalBookName(bookman));

  bookman->string_input = CreateStringInputVA(NULL,
                                              VAR_ARG_BOOK, bookman,
                                              VAR_ARG_STRINP_TEXT, editable_strID,
                                              VAR_ARG_STRINP_MAX_LEN, MAX_BOOK_NAME_LEN,
                                              VAR_ARG_STRINP_MIN_LEN, 0,
                                              VAR_ARG_CALL_BACK_PREV_ACT, onPrevious_SI,
                                              VAR_ARG_CALL_BACK_LONG_BACK, onPrevious_SI,
                                              VAR_ARG_CALL_BACK_OK, onAccept_SI,
                                              NULL);
  return 1;
}

int ChangeName_Exit_Event(void *data, BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  FREE_GUI(bookman->string_input);
  return 1;
}

void BookMan_RenameBook(BOOK *book, GUI *)
{
  BookManager *bookman = (BookManager *)book;
  bookman->active_tab = GetActiveTab(bookman);
  BookObj_CallPage(bookman, &BookManager_ChangeName_Page);
}
