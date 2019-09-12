#include <iostream>
#include "Account.hpp"

int main(int argc, char const *argv[])
{
  Account sahil;
  std::cout << sahil.get_name() << std::endl;
  sahil.set_name("Sahil Bondre");
  std::cout << sahil.get_name() << std::endl;
  sahil.deposit(1000);
  sahil.withdraw(500);
  sahil.deposit(100000);
  sahil.withdraw(1000);
  return 0;
}
