#include <iostream>
#include <vector>

int binary_search_recursive(const std::vector<long> &vector, long key, int start, int end)
{
  if (start >= end && vector[start] != key)
    return -1;
  int mid = (start + end) / 2;
  if (vector[mid] == key)
    return mid;
  else if (vector[mid] > key)
    return binary_search_recursive(vector, key, start, mid - 1);
  else
    return binary_search_recursive(vector, key, mid + 1, end);
}

int binary_search(const std::vector<long> &vector, long key)
{
  return binary_search_recursive(vector, key, 0, vector.size() - 1);
}

int main(int argc, char const *argv[])
{
  int n, k;
  std::vector<long> input;
  std::vector<long> keys;
  std::cin >> n;
  for (auto i = 0; i < n; ++i)
  {
    long temp;
    std::cin >> temp;
    input.push_back(temp);
  }
  std::cin >> k;
  for (auto i = 0; i < k; ++i)
  {
    long temp;
    std::cin >> temp;
    std::cout << binary_search(input, temp) << " ";
  }
  std::cout << std::endl;
  return 0;
}
