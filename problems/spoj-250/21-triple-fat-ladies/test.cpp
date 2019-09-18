#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "util.hpp"

bool does_cube_end_with_888(long long number)
{
  int last_three_digits = number % 1000;
  switch (last_three_digits)
  {
  case 192:
  case 442:
  case 692:
  case 942:
    return true;
  default:
    return false;
  }
}

long long get_kth_cube_888(long long k)
{
  int map[] = {192, 442, 692, 942};
  return ((k - 1) / 4) * 1000 + map[(k - 1) % 4];
}

int main(int argc, char const *argv[])
{
  // long long n_th_cube_888 = 0; // cube which ends with 888
  // long long n_th_cube = 0;     // number counter
  // while (n_th_cube != k)
  // {
  // }
  long long k;
  std::cin >> k;
  std::cout << get_kth_cube_888(k) << std::endl;

  return 0;
}
