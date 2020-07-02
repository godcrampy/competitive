#include <stdlib.h>

#include <iostream>
#include <vector>

template <class T>
void print_vector(std::vector<T> vector) {
  for (auto item : vector) std::cout << item << " ";
  std::cout << std::endl;
}

template <class T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <class T>
void selection_sort(std::vector<T> &vector) {
  auto length = vector.size();
  for (auto i = 0; i < length - 1; ++i) {
    // i is the first element of unsorted part
    int min_index = i;
    for (auto j = i + 1; j < length; ++j)
      if (vector[j] < vector[min_index]) min_index = j;
    swap(vector[i], vector[min_index]);
  }
}

template <class T>
void bubble_sort(std::vector<T> &vector) {
  auto length = vector.size();
  for (auto i = 0; i < length; ++i)
    for (int j = 0; j < length - i - 1; ++j)
      if (vector[j] > vector[j + 1]) swap(vector[j], vector[j + 1]);
}

template <class T>
void _merge(std::vector<T> &vector, int start, int mid, int end) {
  std::vector<T> temp = vector;
  int iterator = start;
  int iterator1 = start;
  int iterator2 = mid + 1;
  while (iterator1 != mid + 1 && iterator2 != end + 1) {
    if (temp[iterator1] < temp[iterator2]) {
      vector[iterator] = temp[iterator1];
      ++iterator1;
    } else {
      vector[iterator] = temp[iterator2];
      ++iterator2;
    }
    ++iterator;
  }
  while (iterator1 != mid + 1) {
    vector[iterator] = temp[iterator1];
    ++iterator1;
    ++iterator;
  }
  while (iterator2 != end + 1) {
    vector[iterator] = temp[iterator2];
    ++iterator2;
    ++iterator;
  }
}

template <class T>
void _merge_sort(std::vector<T> &vector, int start, int end) {
  if (start == end) return;
  int mid = (start + end) / 2;
  _merge_sort(vector, start, mid);
  _merge_sort(vector, mid + 1, end);
  _merge(vector, start, mid, end);
}

template <class T>
void merge_sort(std::vector<T> &vector) {
  _merge_sort(vector, 0, vector.size() - 1);
}

template <class T>
int partition(std::vector<T> &vector, int start, int end) {
  auto length = end - start + 1;
  int last_index_of_small_section = start;
  for (auto i = start + 1; i != end + 1; ++i) {
    if (vector[i] < vector[start]) {
      swap(vector[i], vector[last_index_of_small_section + 1]);
      ++last_index_of_small_section;
    }
  }
  swap(vector[start], vector[last_index_of_small_section]);
  return last_index_of_small_section;
}

template <class T>
void _quick_sort(std::vector<T> &vector, int start, int end) {
  if (start >= end) return;
  int mid = partition(vector, start, end);
  _quick_sort(vector, start, mid - 1);
  _quick_sort(vector, mid + 1, end);
}

template <class T>
void quick_sort(std::vector<T> &vector) {
  _quick_sort(vector, 0, vector.size() - 1);
}

int main(int argc, char const *argv[]) {
  int n = 10;
  std::vector<int> a;
  for (auto i = 0; i < n; ++i) a.push_back(rand() % 100 + 1);
  print_vector(a);
  quick_sort(a);
  print_vector(a);
  return 0;
}
