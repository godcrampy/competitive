#ifndef _UTIL
#define _UTIL

int sumOfArray(int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++)
    sum += array[i];
  return sum;
}

#endif