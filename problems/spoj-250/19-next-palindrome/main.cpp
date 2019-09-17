#include <iostream>
#include "util.hpp"

int main()
{
  int t;
  std::cin >> t;
  long a;
  for (int _ = 0; _ < t; _++)
  {
    std::cin >> a;
    std::cout << next_palindrome(a) << std::endl;
  }
  return 0;
}
