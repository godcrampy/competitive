#include <iostream>
#include <vector>

int merge(std::vector<long> &vector, int l, int m, int r) {
  auto temp = vector;
  int count = 0;
  int iterator1 = l;
  int iterator2 = m + 1;
  int iterator = l;
  while (iterator1 != m + 1 && iterator2 != r + 1) {
    if (temp[iterator1] > temp[iterator2]) {
      count += (m - iterator1 + 1);
      vector[iterator] = temp[iterator2];
      ++iterator2;
    } else {
      vector[iterator] = temp[iterator1];
      ++iterator1;
    }
    ++iterator;
  }
  while (iterator1 != m + 1) {
    vector[iterator] = temp[iterator1];
    ++iterator1;
    ++iterator;
  }
  while (iterator2 != r + 1) {
    vector[iterator] = temp[iterator2];
    ++iterator2;
    ++iterator;
  }
  return count;
}

int merge_sort(std::vector<long> &vector, int l, int r) {
  if (l >= r) return 0;
  int mid = (l + r) / 2;
  int count = 0;
  count += merge_sort(vector, l, mid);
  count += merge_sort(vector, mid + 1, r);
  count += merge(vector, l, mid, r);
  return count;
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<long> test(n, 0);
  for (auto i = 0; i < n; ++i) {
    long temp;
    std::cin >> temp;
    test[i] = temp;
  }
  std::cout << merge_sort(test, 0, test.size() - 1) << std::endl;
  return 0;
}
