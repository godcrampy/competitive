#include <iostream>
#include <vector>

long merge(std::vector<long> &vector, int l, int m, int r)
{
  std::vector<int> temp(r - l + 1, 0);
  for (auto i = l; i <= r; ++i)
    temp[i - l] = vector[i];
  long count = 0;
  int iterator1 = l;
  int iterator2 = m + 1;
  int iterator = l;
  while (iterator1 != m + 1 && iterator2 != r + 1)
  {
    if (temp[iterator1 - l] > temp[iterator2 - l])
    {
      count += (m - iterator1 + 1);
      vector[iterator] = temp[iterator2 - l];
      ++iterator2;
    }
    else
    {
      vector[iterator] = temp[iterator1 - l];
      ++iterator1;
    }
    ++iterator;
  }
  while (iterator1 != m + 1)
  {
    vector[iterator] = temp[iterator1 - l];
    ++iterator1;
    ++iterator;
  }
  while (iterator2 != r + 1)
  {
    vector[iterator] = temp[iterator2 - l];
    ++iterator2;
    ++iterator;
  }
  return count;
}

long merge_sort(std::vector<long> &vector, int l, int r)
{
  if (l >= r)
    return 0;
  int mid = (l + r) / 2;
  long count = 0;
  count += merge_sort(vector, l, mid);
  count += merge_sort(vector, mid + 1, r);
  count += merge(vector, l, mid, r);
  return count;
}

int main(int argc, char const *argv[])
{
  int t;
  std::cin >> t;
  for (auto _ = 0; _ < t; ++_)
  {
    long n;
    std::cin >> n;
    std::vector<long> test(n, 0);
    for (auto i = 0; i < n; ++i)
    {
      long temp;
      std::cin >> temp;
      test[i] = temp;
    }
    std::cout << merge_sort(test, 0, test.size() - 1) << std::endl;
  }
  return 0;
}
