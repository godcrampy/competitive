#include <iostream>
#include <string>
#include <vector>

bool is_in_range(const std::vector<int> &vector, int position) {
  return (position >= 0 && position < vector.size());
}

bool mark_cells(std::vector<int> &spaces, int position, int range) {
  for (auto i = position - range; i <= position + range; ++i)
    if (is_in_range(spaces, i)) {
      ++spaces[i];
      if (spaces[i] > 1) return false;
    }
  return true;
}

bool is_possible(std::string string) {
  int length_of_string = string.length();
  std::vector<int> spaces(length_of_string, 0);
  for (auto i = 0; i < length_of_string; ++i) {
    if (string[i] != '.')
      if (!mark_cells(spaces, i, string[i] - '0')) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int t = 0;
  std::cin >> t;
  getchar();
  for (auto _ = 0; _ < t; ++_) {
    std::string input;
    std::getline(std::cin, input);
    if (is_possible(input))
      std::cout << "safe" << std::endl;
    else
      std::cout << "unsafe" << std::endl;
  }
  return 0;
}
