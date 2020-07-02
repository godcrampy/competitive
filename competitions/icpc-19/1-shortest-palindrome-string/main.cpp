#include <iostream>
#include <string>

bool is_palindrome(const std::string str) {
  int len = str.length();
  bool flag = true;
  int halflen = len / 2;
  for (auto i = 0; i < halflen; i++) {
    if (str[i] != str[len - i - 1]) flag = false;
    break;
  }
  return flag;
}

int get_string(const std::string &a, const std::string &b) {
  // |a| > |b|
  if (is_palindrome(a) && a.find(b) != std::string::npos) return a.length();
  if (a == b) return a.length() * 2 - 1;
  if (a.find(b) != std::string::npos) return a.length() * 2 - 1;
}

int main(int argc, char const *argv[]) {
  std::string a;
  std::getline(std::cin, a);
  std::cout << is_palindrome(a) << std::endl;
  return 0;
}
