#include <iostream>

#include "util.hpp"

int main(int argc, char const *argv[]) {
  long long n;
  std::cin >> n;
  if (n & (n - 1) == 0)
    // square number: it'll end
    std::cout << "TAK" << std::endl;
  else
    std::cout << "NIE" << std::endl;
  return 0;
}
