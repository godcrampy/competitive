#include <iostream>
#include <vector>

std::vector<long> get_prefix_sum(std::vector<long> vector)
{
  long sum = 0;
  std::vector<long> final = {0};
  for (auto i = 0; i < vector.size(); ++i)
  {
    sum += vector[i];
    final.push_back(sum);
  }
  return final;
}

long sum(std::vector<long> prefix_sum, int start, int end)
{
  return prefix_sum[end + 1] - prefix_sum[start];
}

int number_indices_to_consider(int space_remaining)
{
  if (space_remaining < 2)
    return space_remaining;
  for (int i = 1; i < space_remaining; i++)
    if ((i) * (i + 1) / 2 > space_remaining)
      return (i) * (i - 1) / 2;
  return space_remaining;
}

long special_sum(std::vector<long> &prefix_sum, int index)
{
  int end = number_indices_to_consider(prefix_sum.size() - index - 1);
  return sum(prefix_sum, index, index + end - 1);
}

int main(int argc, char const *argv[])
{
  int i;
  std::vector<long> vec = {-3, 2, 3, -4, 3, 1};
  auto pref = get_prefix_sum(vec);
  long max = special_sum(pref, 0);
  for (auto i = 0; i < vec.size(); ++i)
    max = std::max(special_sum(pref, i), max);
  std::cout << max << std::endl;
  return 0;
}
