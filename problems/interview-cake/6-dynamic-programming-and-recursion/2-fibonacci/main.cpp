#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
  // compute the nth Fibonacci number
  if (n < 0) {
    throw "";
  }

  if (n == 0 || n == 1) {
    return n;
  }

  int dp0 = 0;
  int dp1 = 1;
  int current = 0;

  for (int i = 1; i < n; ++i) {
    current = dp0 + dp1;
    dp0 = dp1;
    dp1 = current;
  }

  return current;
}
