#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "String.h"

//==============================================================================

int GetEncodingType(char *str)
{
  if (str[0] == 0xEF && str[1] == 0xBB && str[2] == 0xBF) // utf-8 bom
  {
    return UTF8_BOM;
  }
  else if (str[0] == 0xFF && str[1] == 0xFE) // unicode little-endian
  {
    return UTF16_LE;
  }
  else if (str[0] == 0xFE && str[1] == 0xFF) // unicode big-endian
  {
    return UTF16_BE;
  }
  else
  {
    return ANSI;
  }
}

// Convert a UTF-8 string to an ANSI (single-byte character set) string
void UTF8_to_ANSI(char *ansi, const char *utf8, size_t max_len)
{
  size_t i = 0;
  size_t j = 0;

  // Iterate through the UTF-8 string
  while (utf8[i] != '\0' && j < max_len - 1)
  {
    // Handle ASCII characters (1-byte)
    if ((utf8[i] & 0x80) == 0)
    {
      ansi[j] = utf8[i];
      i++;
    }
    // Handle multi-byte UTF-8 sequences (up to 4 bytes)
    else
    {
      // Determine the number of bytes in the UTF-8 sequence
      int num_bytes = 0;
      char mask = 0x80;

      while ((utf8[i] & mask) != 0)
      {
        num_bytes++;
        mask >>= 1;
      }

      // Copy the UTF-8 sequence to the ANSI string
      if (num_bytes > 0 && j < max_len - num_bytes)
      {
        for (int k = 0; k < num_bytes; k++)
        {
          ansi[j + k] = utf8[i + k];
        }
        i += num_bytes;
      }
      else
      {
        // Handle insufficient space in the ANSI string
        break;
      }
    }

    j++;
  }

  // Null-terminate the ANSI string
  ansi[j] = '\0';
}

// Function to convert UTF-16 LE to ANSI
void UTF16LE_to_ANSI(const wchar_t *utf16, char *ansi, size_t max_len)
{
  size_t i = 0;
  size_t j = 0;

  while (utf16[i] != 0 && j < max_len - 1)
  {
    wchar_t ch = utf16[i++];

    if (ch <= 0x7F)
    {
      ansi[j++] = (char)ch;
    }
    else
    {
      ansi[j++] = (char)ch;
    }
  }

  // Null-terminate the ANSI string
  ansi[j] = '\0';
}

// Function to convert UTF-16 BE to ANSI
void UTF16BE_to_ANSI(const wchar_t *utf16be, char *ansi, size_t max_len)
{
  size_t i = 0;
  size_t j = 0;

  while (utf16be[i] != 0 && j < max_len - 1)
  {
    wchar_t ch = utf16be[i++];

    // Swap the byte order (big-endian to little-endian)
    wchar_t swapped_ch = ((ch & 0xFF) << 8) | ((ch & 0xFF00) >> 8);

    if (swapped_ch <= 0x7F)
    {
      // ASCII character (1 byte in ANSI)
      ansi[j++] = (char)swapped_ch;
    }
    else
    {
      ansi[j++] = (char)swapped_ch;
    }
  }

  // Null-terminate the ANSI string
  ansi[j] = '\0';
}

bool is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

char *StringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(char);
  char *s = (char *)malloc(size);
  memset(s, NULL, size);
  return (s);
}

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *ws = (wchar_t *)malloc(size);
  memset(ws, NULL, size);
  return (ws);
}
