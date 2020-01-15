#ifndef _UTIL
#define _UTIL

int isPrime(int number) {
  if (number == 1)
    return 0;
  for (int i = 2; i < number; i++)
    if (number % i == 0)
      return 0;
  return 1;
}

#endif