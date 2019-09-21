#include <iostream>
#include <vector>
#include "util.hpp"
#include <algorithm>

int main(int argc, char const *argv[])
{
  long number_of_stamps, number_of_friends;
  std::cin >> number_of_stamps >> number_of_friends;
  std::vector<long> stamps;
  for (auto i = 0; i < number_of_friends; ++i)
  {
    long temp;
    std::cin >> temp;
    stamps.push_back(temp);
  }
  std::sort(stamps.begin(), stamps.end(), std::greater<long>());

  long collection = 0;
  bool flag = false;
  int count = 0;
  for (long number : stamps)
  {
    collection += number;
    ++count;
    if (collection >= number_of_stamps)
    {
      flag = true;
      break;
    }
  }
  if (flag)
    std::cout << "YES" << count << std::endl;
  else
    std::cout << "NO" << std::endl;

  return 0;
}
