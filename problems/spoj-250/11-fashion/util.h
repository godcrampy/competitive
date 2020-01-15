#ifndef _UTIL
#define _UTIL

#include <algorithm>

int get_hotness(int men_rating[], int women_rating[], int length) {
  int sum = 0;  // sum of optimum hotness
  std::sort(men_rating, men_rating + length);
  std::sort(women_rating, women_rating + length);
  for (int i = 0; i < length; i++)
    sum += men_rating[i] * women_rating[i];
  return sum;
}

#endif