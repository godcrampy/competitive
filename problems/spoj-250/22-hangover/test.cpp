#include <iostream>

#include "util.hpp"

int number_of_cards(float length) {
  int i = 2;
  float current_length = 0;
  while (current_length < length) {
    current_length += 1 / static_cast<float>(i);
    ++i;
  }
  return i - 2;
}

int main(int argc, char const *argv[]) {
  float n;
  std::cin >> n;
  std::cout << number_of_cards(n) << std::endl;
  return 0;
}
