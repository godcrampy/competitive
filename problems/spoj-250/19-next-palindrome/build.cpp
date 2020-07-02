#include <algorithm>
#include <iostream>
#include <string>

bool is_all_nines(const std::string &input) {
  for (auto charecter : input)
    if (charecter != '9') return false;
  return true;
}
std::string next_palindrome_odd(std::string input) {
  int length = input.length();
  int midpoint = length / 2;  // 423 => 4 *2* 3
  std::string reverse = input, final = input;
  std::reverse(reverse.begin(), reverse.end());
  std::copy(reverse.begin() + midpoint + 1, reverse.end(),
            final.begin() + midpoint + 1);
  if (final > input) return final;
  int iterator = midpoint;
  while (input.at(iterator) == '9') {
    input.at(iterator) = '0';
    --iterator;
  }
  input.at(iterator) = input.at(iterator) + 1;
  final = input;
  std::reverse(input.begin(), input.end());
  std::copy(input.begin() + midpoint + 1, input.end(),
            final.begin() + midpoint + 1);
  return final;
}

std::string next_palindrome_even(std::string input) {
  int length = input.length();
  int midpoint = length / 2 - 1;  // 4242 => 4 *2* 4 2
  std::string reverse = input, final = input;
  std::reverse(reverse.begin(), reverse.end());
  std::copy(reverse.begin() + midpoint + 1, reverse.end(),
            final.begin() + midpoint + 1);
  if (final > input) return final;
  int iterator = midpoint;
  while (input.at(iterator) == '9') {
    input.at(iterator) = '0';
    --iterator;
  }
  input.at(iterator) = input.at(iterator) + 1;
  final = input;
  std::reverse(input.begin(), input.end());
  std::copy(input.begin() + midpoint + 1, input.end(),
            final.begin() + midpoint + 1);
  return final;
}

int main() {
  int t;
  std::cin >> t;
  getchar();
  std::string input;
  int length_of_string;
  for (int _ = 0; _ < t; _++) {
    getline(std::cin, input);
    length_of_string = input.length();
    if (is_all_nines(input))
      std::cout << std::stoi(input) + 2 << std::endl;
    else if (length_of_string == 1)
      std::cout << input[0] - '0' + 1 << std::endl;
    else if (length_of_string % 2 == 0)
      std::cout << next_palindrome_even(input) << std::endl;
    else
      std::cout << next_palindrome_odd(input) << std::endl;
  }
  return 0;
}
