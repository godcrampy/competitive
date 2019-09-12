#include <iostream>
#include <iostream>
#include "util.h"

int main(int argc, char const *argv[])
{
  std::string a_value, b_value;
  std::getline(std::cin, a_value);
  std::getline(std::cin, b_value);
  BigInteger a(a_value), b(b_value), c;
  c = a / 2;
  std::cout << c.get_string() << std::endl;
  return 0;
}