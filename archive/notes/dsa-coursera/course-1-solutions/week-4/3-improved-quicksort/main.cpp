#include <iostream>
#include <utility>
#include <vector>

template <class T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int partition(std::vector<long> &vector, int l, int r) {
  long pivot = vector[l];
  int last_of_small_elements = l;
  for (auto i = l + 1; i <= r; ++i) {
    if (vector[i] < pivot) {
      ++last_of_small_elements;
      swap(vector[i], vector[last_of_small_elements]);
    }
  }
  swap(vector[l], vector[last_of_small_elements]);
  return last_of_small_elements;
}

std::pair<int, int> fast_partition(std::vector<long> &vector, int l, int r) {
  long pivot = vector[l];
  int first_of_pivots = l;
  int last_of_pivots = l;
  for (auto i = l + 1; i <= r; ++i) {
    if (vector[i] < pivot) {
      if (last_of_pivots + 1 == i) {
        swap(vector[first_of_pivots], vector[i]);
        ++first_of_pivots;
        ++last_of_pivots;
        continue;
      }
      ++first_of_pivots;
      ++last_of_pivots;
      swap(vector[first_of_pivots - 1], vector[last_of_pivots]);
      swap(vector[first_of_pivots - 1], vector[i]);
    }
    if (vector[i] == pivot) {
      ++last_of_pivots;
      swap(vector[i], vector[last_of_pivots]);
    }
  }
  return {first_of_pivots, last_of_pivots};
}

void fast_quick_sort(std::vector<long> &vector, int l, int r) {
  if (l >= r) return;
  auto positions = fast_partition(vector, l, r);
  fast_quick_sort(vector, l, positions.first - 1);
  fast_quick_sort(vector, positions.second + 1, r);
}

void quick_sort(std::vector<long> &vector, int l, int r) {
  if (l >= r) return;
  int mid = partition(vector, l, r);
  quick_sort(vector, l, mid - 1);
  quick_sort(vector, mid + 1, r);
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<long> test(n, 0);
  for (auto i = 0; i < n; ++i) std::cin >> test[i];
  fast_quick_sort(test, 0, test.size() - 1);
  for (auto number : test) std::cout << number << " ";
  std::cout << std::endl;
  return 0;
}
