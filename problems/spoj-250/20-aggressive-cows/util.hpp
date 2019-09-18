#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <vector>

bool is_feasable(std::vector<long long> positions, long long value, long number_of_cows)
{
  long cows_covered = 1; // the first cow
  long long last_cow_covered_position = positions.at(0);
  for (auto position : positions)
  {
    if (position - last_cow_covered_position >= value)
    {
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

long long largest_minimun_position(std::vector<long long> positions, long number_of_cows)
{
  long long low = 1;                                                     // minimum possible answer
  long long high = positions.at(positions.size() - 1) - positions.at(0); // maximum possible answer
  long long mid;
  while (high - low > 1)
  {
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

#endif