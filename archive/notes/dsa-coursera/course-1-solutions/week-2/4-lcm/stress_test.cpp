#include <stdlib.h>
#include <iostream>
#include <numeric>

long gcd(long a, long b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a > b)
    return gcd(a % b, b);
  return gcd(b % a, a);
}

long long lcm(long a, long b) {
  return (a * b) / gcd(a, b);
}

int main(int argc, char const *argv[]) {
  while (true) {
    long a = rand() % 1000000 + 1, b = rand() % 1000000 + 1;
    if (lcm(a, b) == std::lcm(a, b))
      std::cout << "OK" << std::endl;
    else {
      std::cout << "WA" << std::endl;
      std::cout << lcm(a, b) << " " << std::lcm(a, b) << std::endl;
      break;
    }
  }
  return 0;
}
