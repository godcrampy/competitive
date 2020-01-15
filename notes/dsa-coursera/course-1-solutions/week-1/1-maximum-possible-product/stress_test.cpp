#include <stdlib.h>
#include <climits>
#include <iostream>
#include <vector>

auto max_pair_product(std::vector<long long> vector) {
  long long result = LONG_LONG_MIN;
  for (int i = 0; i < vector.size(); ++i)
    for (int j = i + 1; j < vector.size(); ++j)
      if (vector[i] * vector[j] > result)
        result = vector[i] * vector[j];
  return result;
}

auto max_pair_product_fast(std::vector<long long> vector) {
  int max_index_1 = 0;
  for (auto i = 0; i < vector.size(); ++i)
    if (vector[i] > vector[max_index_1])
      max_index_1 = i;

  int max_index_2 = max_index_1 == 0 ? 1 : 0;
  for (auto i = 0; i < vector.size(); ++i)
    if (i != max_index_1 && vector[i] > vector[max_index_2])
      max_index_2 = i;
  return (vector[max_index_1] * vector[max_index_2]);
}

int main(int argc, char const *argv[]) {
  while (true) {
    int n = rand() % 10 + 2;
    std::vector<long long> vec(n);
    for (auto i = 0; i < n; ++i)
      vec.at(i) = rand() % 10000;
    for (auto i = 0; i < n; ++i)
      std::cout << vec.at(i) << ' ';
    std::cout << '\n';
    if (max_pair_product(vec) == max_pair_product_fast(vec))
      std::cout << "OKAY" << '\n';
    else {
      std::cout << "WA" << '\n';
      std::cout << max_pair_product(vec) << ' ' << max_pair_product_fast(vec) << '\n';
      break;
    }
  }
  return 0;
}
