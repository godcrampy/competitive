#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  // write your code here
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
