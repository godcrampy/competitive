#include <algorithm>
#include <iostream>
#include <vector>

long long maximum_sum(std::vector<long> a, std::vector<long> b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  long long sum = 0;
  for (auto i = 0; i < a.size(); ++i)
    sum += a[i] * b[i];
  return sum;
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<long> a, b;
  for (auto i = 0; i < n; ++i) {
    long temp;
    std::cin >> temp;
    a.push_back(temp);
  }
  for (auto i = 0; i < n; ++i) {
    long temp;
    std::cin >> temp;
    b.push_back(temp);
  }
  std::cout << maximum_sum(a, b) << std::endl;
  return 0;
}
