#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "str_lib.h"

int parse_value(const char *str)
{
  if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
  {
    return hex2int(str);
  }
  else
  {
    return ascii2int(str);
  }
}

void parse_values(const char *input, int *output)
{
  const char *start = input;
  int i = 0;

  while (*start)
  {
    const char *end = start;
    while (*end && *end != ',')
      end++;

    char temp[32] = {0};
    memcpy(temp, start, end - start);
    output[i++] = parse_value(temp);

    if (*end == ',')
      start = end + 1;
    else
      break;
  }
}
