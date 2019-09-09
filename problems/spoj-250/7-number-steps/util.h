#ifndef _UTIL
#define _UTIL

bool isValid(int x, int y)
{
  return x == y || x - y == 2 ? true : false;
}

int getNumber(int x, int y)
{
  return x % 2 == 0 ? x + y : x + y - 1;
}

#endif