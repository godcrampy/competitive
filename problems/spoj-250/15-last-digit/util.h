#ifndef _UTIL
#define _UTIL
#include <map>
#include <vector>
#include <math.h>

// int get_last_digit(int base, unsigned long long index, const std::vector<std::vector<int>> &key_map)
// {
//   int base_LSB = base % 10;
//   std::vector<int> key_vector = key_map.at(base_LSB);
//   return key_vector.at((index - 1) % (key_vector.size()));
// }

int get_power_LSB(int base, int index)
{
  int final = 1;
  for (int i = 0; i < index; i++)
    final *= base;
  return final % 10;
}

int get_last_digit(int base, unsigned long long index)
{
  int c = index % 4;
  a = a % 10;
  return get_power_LSB(base, c);
}
#endif