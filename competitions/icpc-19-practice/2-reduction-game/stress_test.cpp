#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

long get_sum_naive(std::vector<long> vector, long k) {
  if (vector.size() == 0) return 0;
  std::sort(vector.begin(), vector.end());
  for (auto i = 0; i < vector.size() - 1; ++i) {
    while (vector[i] > k) {
      vector[i] = vector[i] - 1;
      vector[i + 1] -= 1;
    }
  }
  long sum = 0;
  for (auto number : vector) sum += number;
  return sum;
}

long get_sum(std::vector<long> vector, long k) {
  if (vector.size() == 0) return 0;
  std::sort(vector.begin(), vector.end());
  for (auto i = 0; i < vector.size() - 1; ++i) {
    auto diff = vector[i] - k;
    vector[i] -= diff;
    vector[i + 1] -= diff;
  }
  long sum = 0;
  for (auto number : vector) sum += number;
  return sum;
}

int main(int argc, char const *argv[]) {
  while (true) {
    int n = rand() % 50 + 1;
    long k = rand() % 50000 + 1, sum = 0;
    std::cout << "n: " << n << " "
              << "k: " << k << std::endl;
    std::vector<long> vector;
    std::cout << "vector:" << std::endl;
    for (auto i = 0; i < n; ++i) {
      long temp = rand() % 50000 + 1;
      std::cout << temp << " ";
      if (temp <= k)
        sum += temp;
      else
        vector.push_back(temp);
    }
    std::cout << std::endl;
    if (get_sum(vector, k) == get_sum_naive(vector, k))
      std::cout << "OK" << std::endl;
    else {
      std::cout << "WA" << std::endl;
      std::cout << sum + get_sum(vector, k) << " "
                << sum + get_sum_naive(vector, k) << std::endl;
      break;
    }
  }
  return 0;
}
