#ifndef _UTIL
#define _UTIL

int get_max(int number)
{
  if (number < 12)
    return number;
  if (number / 2 + number / 3 + number / 4 > number)
    return get_max(number / 2) + get_max(number / 3) + get_max(number / 4);
  return number;
}

#endif