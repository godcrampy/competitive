#include <limits.h>

#include <string>

using namespace std;

bool is_digit(char c) { return c >= '0' && c <= '9'; }

int to_digit(char c) { return c - '0'; }

int myAtoi(string str) {
  int i = 0;
  int length = str.length();
  long long val = 0;
  // discard whitespace
  while (str[i] == ' ' && i < length) {
    ++i;
  }

  if (i == length) return 0;

  // take optional plus minus
  bool negative = false;

  if (str[i] == '+') {
    ++i;
  } else if (str[i] == '-') {
    ++i;
    negative = true;
  }

  if (i == length) return 0;

  // consume till digits
  while (is_digit(str[i]) && i < length) {
    val = val * 10 + to_digit(str[i]);
    if (val > (long)INT_MAX + 2) {
      return negative ? INT_MIN : INT_MAX;
    }
    ++i;
  }

  if (negative) val *= -1;
  if (val > INT_MAX) return INT_MAX;
  if (val < INT_MIN) return INT_MIN;
  return val;
}