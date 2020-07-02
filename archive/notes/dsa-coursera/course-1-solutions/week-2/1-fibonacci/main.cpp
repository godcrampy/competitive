#include <iostream>

long fibonacci(long number) {
  if (number <= 1) return number;
  return fibonacci(number - 1) + fibonacci(number - 2);
}

long fibonacci_fast(long number) {
  // no need of static. non recursive solution
  long cache[number + 1];
  cache[0] = 0;
  cache[1] = 1;
  for (int i = 2; i <= number; ++i) cache[i] = cache[i - 1] + cache[i - 2];
  return cache[number];
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::cout << fibonacci_fast(n) << '\n';
  return 0;
}
