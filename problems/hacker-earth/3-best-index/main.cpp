#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

auto get_prefix(std::vector<long long> &array, std::vector<long long> &prefix_sum)
{
  // * works
  prefix_sum = {};
  long long sum = 0;
  for (auto number : array)
  {
    sum += number;
    prefix_sum.push_back(sum);
  }
}

long number_of_allowed_charecters(long space)
{
  long final = (std::sqrt(1 + 8 * space) - 1) / 2;
  return (final) * (final + 1) / 2;
}

long long get_prefix_sum(const std::vector<long long> &prefix, long start, long end)
{
  if (start == 0)
    return prefix.at(end);
  return prefix.at(end) - prefix.at(start - 1);
}

long get_special_sum(std::vector<long long> &prefix, int postion)
{
  long valid_space = number_of_allowed_charecters(prefix.size() - postion);
  return get_prefix_sum(prefix, postion, postion + valid_space - 1);
}

long get_best_index(std::vector<long long> &prefix)
{
  long size = prefix.size();
  long max = LONG_MIN;
  for (auto i = 0; i < size; ++i)
  {
    long temp = get_special_sum(prefix, i);
    if (temp > max)
      max = temp;
  }
  return max;
}

int main()
{
  long size;
  std::cin >> size;
  std::vector<long long> array, prefix;
  for (auto i = 0; i < size; ++i)
  {
    long temp;
    std::cin >> temp;
    array.push_back(temp);
  }
  get_prefix(array, prefix);
  std::cout << get_best_index(prefix) << std::endl;
  return 0;
}
