#include "temp\target.h"

#include "..\\include\Types.h"

#include "bookman.h"
#include "main.h"
#include "Lib.h"
#include "book_names.h"

char *GetOriginalBookName(BOOK *book)
{
  BookManager *bookman = (BookManager *)book;
  BOOK_LIST_ITEM *elem = GetBookListItem(bookman);
  return (elem->book_name);
}

void onCancel_SI(BOOK *book, wchar_t *new_name, int len)
{
  BookObj_ReturnPage(book, ACCEPT_EVENT);
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
      if ((file = _fopen(BOOKMAN_PATH, INI_BOOK_NAMES, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
      {
        // Delete
        pos = wstrwstr(pos_uni_pair, L"\r\n") + sizeof("\r\n") - sizeof("");

        fwrite(file, bookman->booknames_buf, (pos_uni_pair - bookman->booknames_buf) * sizeof(wchar_t));   //пишем начало файла
        fwrite(file, pos, bookman->booknames_buf_size - (pos - bookman->booknames_buf) * sizeof(wchar_t)); //пишем остаток файла
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
        if ((file = _fopen(BOOKMAN_PATH, INI_BOOK_NAMES, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
        {
          // ReWrite
          pos = pos_uni_pair + wstrlen(orig_name) + sizeof(": ") - sizeof("");
          int len_minus = wstrlen(cur_name); //длина старого названия

          fwrite(file, bookman->booknames_buf, (pos - bookman->booknames_buf) * sizeof(wchar_t));                                      //пишем начало файла
          fwrite(file, new_name, new_name_len * sizeof(wchar_t));                                                                      //пишем новое название
          fwrite(file, pos + len_minus, bookman->booknames_buf_size - ((pos - bookman->booknames_buf) + len_minus) * sizeof(wchar_t)); //пишем остаток файла
          fclose(file);
        }
      }
      else
      {
        if ((file = _fopen(BOOKMAN_PATH, INI_BOOK_NAMES, FSX_O_RDWR | FSX_O_TRUNC, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
        {
          // Append
          fwrite(file, bookman->booknames_buf, bookman->booknames_buf_size); //пишем старый файл
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

  bookman->string_input = CreateStringInput(bookman);
  StringInput_SetMode(bookman->string_input, IT_STRING);
  StringInput_SetEnableEmptyText(bookman->string_input, FALSE);
  StringInput_SetText(bookman->string_input, editable_strID);
  StringInput_SetMaxLen(bookman->string_input, MAX_BOOK_NAME_LEN);
  StringInput_SetActionOK(bookman->string_input, onAccept_SI);
  StringInput_SetActionBack(bookman->string_input, onPrevious_SI);
  StringInput_SetActionCancel(bookman->string_input, onCancel_SI);
  GUIObject_Show(bookman->string_input);
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
  BookObj_CallPage(bookman, &BookManager_ChangeName_page);
}
