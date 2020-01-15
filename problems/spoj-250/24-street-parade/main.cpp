#include <iostream>
#include <vector>
#include "util.hpp"

int main() {
  int number_of_mobiles, n;
  while (true) {
    std::cin >> number_of_mobiles;
    if (number_of_mobiles == 0)
      break;
    std::vector<int> sequence, sorted_sequence;
    for (auto i = 0; i < number_of_mobiles; ++i) {
      std::cin >> n;
      sequence.push_back(n);
    }
    print_yes_or_no(sequence);
  }
  return 0;
}
