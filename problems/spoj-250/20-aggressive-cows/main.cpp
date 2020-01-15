#include <algorithm>
#include <iostream>
#include <vector>
#include "util.hpp"

int main() {
  int t;
  std::cin >> t;
  long number_of_stalls, number_of_cows;
  for (int _ = 0; _ < t; _++) {
    long number_of_stalls, number_of_cows;  // N and C of the problem
    std::cin >> number_of_stalls >> number_of_cows;
    std::vector<long long> positions(number_of_stalls, 0);  // positions of the stall
    for (auto i = 0; i < number_of_stalls; ++i)
      std::cin >> positions.at(i);
    std::sort(positions.begin(), positions.end());

    std::cout << largest_minimun_position(positions, number_of_cows) << std::endl;
  }
  return 0;
}
