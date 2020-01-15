#include <iostream>

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
  long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
