#ifndef _UTIL
#define _UTIL

int numberOfTrailingZerosInFactorial(int number) {
  // https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
  int zeroes = 0;
  while (number != 0) {
    zeroes += number / 5;
    number /= 5;
  }
  return zeroes;
}
#endif