#include <iostream>
#include "test.h"
#include <string>
#include <algorithm>

auto print_string(std::string string)
{
  std::cout << string << std::endl;
}

int main(int argc, char const *argv[])
{
  std::string name = "sahil";
  std::sort(name.begin(), name.end());
  print_string(name);
  return 0;
}
