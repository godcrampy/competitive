#include <iostream>
#include <vector>

long pisano_period(long number) {
  // works
  // had to use vector as length is unknown
  std::vector<long> cache;
  cache.push_back(0);
  cache.push_back(1);
  for (auto i = 2; i < number * number; ++i) {
    cache.push_back((cache[i - 1] + cache[i - 2]) % number);
    if (cache[i] == 1 && cache[i - 1] == 0)
      return i - 1;
  }
  return 1;
}

long fibonacci_mod(long long number, long mod) {
  long period = pisano_period(mod);
  long sequence[period];
  sequence[0] = 0;
  sequence[1] = 1;
  for (int i = 2; i < period; ++i)
    sequence[i] = (sequence[i - 1] + sequence[i - 2]) % mod;
  return sequence[number % period];
}

int main(int argc, char const *argv[]) {
  long m;
  long long n;
  std::cin >> n >> m;
  std::cout << fibonacci_mod(n, m) << std::endl;
  return 0;
}
