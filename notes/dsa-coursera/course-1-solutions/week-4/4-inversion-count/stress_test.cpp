#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

void merge(std::vector<long> &vector, int l, int m, int r)
{
  auto temp = vector;
  int iterator1 = l;
  int iterator2 = m + 1;
  int iterator = l;
  while (iterator1 != m + 1 && iterator2 != r + 1)
  {
    if (temp[iterator1] > temp[iterator2])
    {
      vector[iterator] = temp[iterator2];
      ++iterator2;
    }
    else
    {
      vector[iterator] = temp[iterator1];
      ++iterator1;
    }
    ++iterator;
  }
  while (iterator1 != m + 1)
  {
    vector[iterator] = temp[iterator1];
    ++iterator1;
    ++iterator;
  }
  while (iterator2 != r + 1)
  {
    vector[iterator] = temp[iterator2];
    ++iterator2;
    ++iterator;
  }
}

void merge_sort(std::vector<long> &vector, int l, int r)
{
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  merge_sort(vector, l, mid);
  merge_sort(vector, mid + 1, r);
  merge(vector, l, mid, r);
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    int n = rand() % 100000 + 1;
    std::vector<long> test;
    for (auto i = 0; i < n; ++i)
      test.push_back(rand() % 1000000000 + 1);
    auto copy = test;
    merge_sort(test, 0, test.size() - 1);
    std::sort(copy.begin(), copy.end());
    for (auto number : test)
      std::cout << number << " ";
    std::cout << std::endl;
    if (copy != test)
      break;
  }
  return 0;
}