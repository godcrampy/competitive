#include <iostream>
#include "big-int.hpp"

int main(int argc, char const *argv[]) {
  BigInteger a("450");
  BigInteger c = a + (-4);
  std::cout << c.get_string() << std::endl;
  return 0;
}
