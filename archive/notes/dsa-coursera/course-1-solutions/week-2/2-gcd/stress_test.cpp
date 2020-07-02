#include <stdlib.h>

#include <iostream>

long gcd(long a, long b) {
  // O(min(a, b))
  long min = std::min(a, b);
  long final = 1;
  for (int i = 2; i <= min; ++i)
    if (a % i == 0 && b % i == 0) final = i;
  return final;
}

long gcd_fast(long a, long b) {
  // gcd(a, b) = gcd(a%b, b)
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd_fast(a % b, b);
  return gcd_fast(b % a, a);
}

int main(int argc, char const *argv[]) {
  while (true) {
    long a, b;
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    std::cout << a << " " << b << '\n';
    if (gcd(a, b) == gcd_fast(a, b))
      std::cout << "OK" << '\n';
    else {
      std::cout << "WA" << '\n';
      std::cout << gcd(a, b) << '\n';
      std::cout << gcd_fast(a, b) << '\n';
      break;
    }
  }
  return 0;
}
