#include <algorithm>
#include <iostream>
#include <vector>

#include "util.hpp"

int main(int argc, char const *argv[]) {
  int n = 0;
  std::cin >> n;
  std::vector<Pair> list;
  for (int i = 0; i < n; i++) {
    long initial, final;
    std::cin >> initial >> final;
    list.push_back(Pair(final, initial));
  }
  std::sort(list.begin(), list.end());
  std::cout << number_of_bars(list) << std::endl;
  return 0;
}
