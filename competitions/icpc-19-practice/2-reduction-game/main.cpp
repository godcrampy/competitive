#include <algorithm>
#include <iostream>
#include <vector>

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
  int t = 0;
  std::cin >> t;
  for (auto _ = 0; _ < t; ++_) {
    int n;
    long k, sum = 0;
    std::cin >> n >> k;
    std::vector<long> vector;
    for (auto i = 0; i < n; ++i) {
      long temp;
      std::cin >> temp;
      if (temp <= k)
        sum += temp;
      else
        vector.push_back(temp);
    }
    std::cout << sum + get_sum(vector, k) << std::endl;
  }
  return 0;
}
