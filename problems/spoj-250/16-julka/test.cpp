#include <iostream>
#include "util.h"

int main(int argc, char const *argv[]) {
  std::string a_value, b_value;
  std::getline(std::cin, a_value);
  std::getline(std::cin, b_value);
  BigInteger a(a_value), b(b_value), c, d;
  c = (a + b) / 2;
  d = (a - b) / 2;
  std::cout << c.get_string() << std::endl;
  std::cout << d.get_string() << std::endl;
  return 0;
}