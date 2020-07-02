#include <iostream>

#include "util.hpp"

int main(int argc, char const *argv[]) {
  std::string a;
  std::getline(std::cin, a);
  std::cout << get_number_of_decodings(a) << std::endl;
  return 0;
}
