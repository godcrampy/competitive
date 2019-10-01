#include <iostream>
#include <vector>

long long merge(std::vector<int> &vector, long start, long mid, long end)
{
  std::vector<int> copy = vector;
  long i = start, j = mid + 1, k = start;
  long long inversions = 0;
  while ((i <= mid) && (j <= end))
  {
    if (copy[i] <= copy[j])
    {
      vector[k] = copy[i];
      ++i;
    }
    else
    {
      vector[k] = copy[j];
      inversions += mid - i + 1;
      ++j;
    }
    ++k;
  }
  while (i <= mid)
  {
    vector[k] = copy[i];
    ++k;
    ++i;
  }

  while (j <= end)
  {
    vector[k] = copy[j];
    ++k;
    ++j;
  }
  return inversions;
}

long long inversion_count(std::vector<int> &vector, long start, long end)
{
  long mid = (start + end) / 2;
  long long count = 0;
  if (start < end)
  {
    count += inversion_count(vector, start, mid);
    count += inversion_count(vector, mid + 1, end);
    count += merge(vector, start, mid, end);
  }
  return count;
}

int main(int argc, char const *argv[])
{
  int t;
  std::cin >> t;
  for (int _ = 0; _ < t; _++)
  {
    std::getchar();
    long n;
    std::cin >> n;
    std::vector<int> test;
    for (auto i = 0; i < n; ++i)
    {
      int temp;
      std::cin >> temp;
      test.push_back(temp);
    }
    long long a = inversion_count(test, 0, test.size() - 1);
    std::cout << a << std::endl;
  }
  return 0;
}
