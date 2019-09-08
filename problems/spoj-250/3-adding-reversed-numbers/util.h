#ifndef _UTIL
#define _UTIL

#include <math.h>

int stripZeroes(int number)
{
  // works
  // strips the ending zeroes of a positive number
  while (true)
  {
    if (number % 10 == 0)
      number /= 10;
    else
      break;
  }
  return number;
}

int lengthOfNumber(int number)
{
  // works
  // returns length of a positve number
  return log10(number) + 1;
}

int reverseNumber(int number)
{
  number = stripZeroes(number);
  int final = 0;
  int length = lengthOfNumber(number);
  for (int i = 0; i < length; i++)
  {
    int lsb = number % 10;
    final += lsb * pow(10, length - i - 1);
    number /= 10;
  }
  return final;
}

#endif