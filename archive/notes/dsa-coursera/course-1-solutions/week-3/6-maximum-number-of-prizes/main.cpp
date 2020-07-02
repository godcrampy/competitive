#include <cmath>
#include <iostream>

long number_of_kids(long n) {
  return (std::sqrt(1 + 8 * n) - 1) / 2;
}

int main(int argc, char const *argv[]) {
  /* code */
  long n;
  std::cin >> n;
  long kids = number_of_kids(n);
  std::cout << kids << std::endl;
  for (auto i = 1; i < kids; ++i) {
    std::cout << i << " ";
    n -= i;
  }
  std::cout << n << std::endl;
  return 0;
}
