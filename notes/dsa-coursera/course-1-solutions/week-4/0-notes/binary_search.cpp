#include <iostream>
#include <vector>

template <class T>
auto binary_search(std::vector<T> vector, T key, int low = 0, int high = 0) {
  if (high < low)
    return -1;
  int mid = (low + high) / 2;
  if (vector[mid] == key)
    return mid;
  else if (vector[mid] > key)
    return binary_search(vector, key, low, mid - 1);
  return binary_search(vector, key, mid + 1, high);
}

template <class T>
auto bin_search(std::vector<>::iterator begin, )

    int main(int argc, char const *argv[]) {
  std::vector<int> vec = {1, 1, 34, 56, 789};
  std::cout << binary_search(vec, 5, 0, vec.size() - 1) << std::endl;
  return 0;
}
