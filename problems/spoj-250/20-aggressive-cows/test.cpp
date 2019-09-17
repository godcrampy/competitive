#include <iostream>
#include "util.hpp"
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{

  /*--------  Initial Input Taking  --------*/
  long number_of_stalls, number_of_cows;
  std::cin >> number_of_stalls >> number_of_cows;
  std::vector<long long> positions(number_of_stalls, 0), differences(number_of_stalls - 1, 0);
  for (auto i = 0; i < number_of_stalls; ++i)
    std::cin >> positions.at(i);
  std::sort(positions.begin(), positions.end());
  for (auto i = 1; i < number_of_stalls; ++i)
    differences.at(i - 1) = positions.at(i) - positions.at(i - 1);

  /*--------  Output  --------*/
  while (positions.size() != number_of_cows)
  {
    // get min element
    auto min_difference_index = std::distance(differences.begin(), std::min_element(differences.begin(), differences.end()));
    if (min_difference_index == 0)
    {
      positions.erase(positions.begin() + 1);
      differences.at(1) += differences.at(0);
      differences.erase(differences.begin());
    }
    else if (min_difference_index == differences.size() - 1)
    {
      positions.erase(positions.end() - 2);
      differences.at(positions.size() - 2) += differences.at(positions.size() - 1);
      differences.erase(differences.end() - 1);
    }
    else
    {
      auto left_difference = differences.at(min_difference_index - 1);
      auto right_difference = differences.at(min_difference_index + 1);
      auto temp = differences.at(min_difference_index);
      if (left_difference > right_difference)
      {
        positions.erase(positions.begin() + min_difference_index + 1);
        differences.at(min_difference_index - 1) += temp;
      }
      else
      {
        positions.erase(positions.begin() + min_difference_index);
        differences.at(min_difference_index + 1) += temp;
      }
      differences.erase(differences.begin() + min_difference_index);
    }
  }
  std::cout << *std::min_element(differences.begin(), differences.end()) << std::endl;
  return 0;
}
