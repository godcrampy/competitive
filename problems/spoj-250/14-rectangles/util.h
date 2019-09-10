#ifndef _UTIL
#define _UTIL

#include <math.h>
int get_rectangle_permutations(int number)
{
  int count = 1; // The number itself
  for (int i = 2; i <= sqrt(number); i++)
    if (number % i == 0)
      ++count;
  return count;
}

int calculate_rectangles(int number)
{
  int rectangles = 0;
  for (int i = 1; i <= number; i++)
    rectangles += get_rectangle_permutations(i);
  return rectangles;
}
#endif