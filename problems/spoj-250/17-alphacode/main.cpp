#include <iostream>
#include "util.hpp"

int main() {
  while (true) {
    std::string a;
    std::getline(std::cin, a);
    if (a == "0")
      break;
    std::cout << get_number_of_decodings(a) << std::endl;
  }
}
