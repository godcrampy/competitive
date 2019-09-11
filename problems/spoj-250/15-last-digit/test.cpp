#include <iostream>
#include "util.h"
#include <vector>

int main(int argc, char const *argv[])
{
  int a;
  unsigned long long b;
  std::cin >> a >> b;
  std::cout << get_last_digit(a, b) << std::endl;

  return 0;
}
