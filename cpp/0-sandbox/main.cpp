#include <iostream>
#include <vector>
#include "test.h"
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
  int *sizes = new int[3];
  *(sizes) = 1;
  *(sizes + 1) = 2;
  *(sizes + 2) = 3;
  print_pointer(sizes, 3);
  delete sizes;
  return 0;
}
