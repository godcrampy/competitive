#include <limits.h>
#include <cmath>
using namespace std;

// Bit manipulation IMP

int divide(int dividend, int divisor) {
  if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
  }
  long dvd = labs(dividend);
  long dvs = labs(divisor);

  bool negative = (dividend < 0) ^ (divisor < 0);

  long count = 0;

  while (dvd >= dvs) {
    long p = 1;    // power to raise
    long d = dvs;  // divisor to be raised to power
    while (d << 1 < dvd) {
      p <<= 1;
      d <<= 1;
    }
    dvd -= d;
    count += p;
  }

  return negative ? -1 * count : count;
}