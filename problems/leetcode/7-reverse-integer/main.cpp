#include <limits.h>

int reverse(int x) {
  bool negative = x < 0;
  long res = 0;
  while (x != 0) {
    res = res * 10 + x % 10;
    x /= 10;
  }

  return (res > INT_MAX || res < INT_MIN) ? 0 : res;
}