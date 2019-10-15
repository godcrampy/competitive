#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template <class T>
bool operator<(std::pair<T, T> &pair1, std::pair<T, T> &pair2)
{
  return pair1.first < pair2.second;
}

std::vector<long> intersection_of_arrays(std::vector<long> a, std::vector<long> b)
{
  std::vector<long> final;
  for (auto number : a)
    if (std::binary_search(b.begin(), b.end(), number))
      final.push_back(number);
  return final;
}

std::vector<long> pair_to_vector(std::pair<long, long> pair)
{
  std::vector<long> final;
  for (auto i = pair.first; i <= pair.second; ++i)
    final.push_back(i);
  return final;
}

std::vector<long> optimal_points(std::vector<std::pair<long, long>> &set)
{
  std::sort(set.begin(), set.end());               // sort pairs by the first point
  std::vector<long> points;                        // final vector to be returned
  std::vector<long> temp = pair_to_vector(set[0]); // we'll add points to this array that are allowed in certain case
  for (auto pair : set)
  {
    // some points already exist, see if the current pair will fit in it
    auto intersection = intersection_of_arrays(temp, pair_to_vector(pair)); // intersection of current pair points and points available in temp
    if (intersection.size() == 0)
    {
      // no common elements found
      points.push_back(*(temp.end() - 1));
      temp = pair_to_vector(pair);
    }
    else
      temp = intersection;
  }
  points.push_back(*(temp.end() - 1));
  return points;
}

int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  std::vector<std::pair<long, long>> set;
  for (auto i = 0; i < n; ++i)
  {
    std::pair<long, long> temp;
    std::cin >> temp.first;
    std::cin >> temp.second;
    set.push_back(temp);
  }
  auto output = optimal_points(set);
  std::cout << output.size() << std::endl;
  for (auto point : output)
    std::cout << point << " ";
  std::cout << std::endl;
  return 0;
}
