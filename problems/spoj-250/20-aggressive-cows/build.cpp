#include <algorithm>
#include <iostream>
#include <vector>

bool is_feasable(std::vector<long long> positions, long long value,
                 long number_of_cows) {
  long cows_covered = 1;  // the first cow
  long long last_cow_covered_position = positions.at(0);
  for (auto position : positions) {
    if (position - last_cow_covered_position >= value) {
      // fill in this cow
      last_cow_covered_position = position;
      ++cows_covered;
    }
    if (cows_covered == number_of_cows)
      // we fit all the cows
      return true;
  }
  return false;
}

long long largest_minimun_position(std::vector<long long> positions,
                                   long number_of_cows) {
  long long low = 1;  // minimum possible answer
  long long high = positions.at(positions.size() - 1) -
                   positions.at(0);  // maximum possible answer
  long long mid;
  while (high - low > 1) {
    mid = (low + high) / 2;
    if (is_feasable(positions, mid, number_of_cows))
      // try for a larger value
      low = mid;
    else
      // not feasable, try for lower value
      high = mid;
  }
  return low;
}

int main() {
  int t;
  std::cin >> t;
  long number_of_stalls, number_of_cows;
  for (int _ = 0; _ < t; _++) {
    long number_of_stalls, number_of_cows;  // N and C of the problem
    std::cin >> number_of_stalls >> number_of_cows;
    std::vector<long long> positions(number_of_stalls,
                                     0);  // positions of the stall
    for (auto i = 0; i < number_of_stalls; ++i) std::cin >> positions.at(i);
    std::sort(positions.begin(), positions.end());

    std::cout << largest_minimun_position(positions, number_of_cows)
              << std::endl;
  }
  return 0;
}
