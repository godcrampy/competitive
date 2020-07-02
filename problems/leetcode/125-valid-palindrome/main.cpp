#include <string>

using namespace std;

bool is_skip(char c) {
  return !((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9'));
}

bool equal(char a, char b) {
  if (a >= 'A' && a <= 'Z') a += 'a' - 'A';
  if (b >= 'A' && b <= 'Z') b += 'a' - 'A';
  return a == b;
}
bool isPalindrome(string s) {
  if (s.length() == 0) {
    return true;
  }
  int l = 0;
  int r = s.length() - 1;

  while (l <= r) {
    // space or symbol comes
    if (is_skip(s[l])) {
      ++l;
      continue;
    }

    if (is_skip(s[r])) {
      --r;
      continue;
    }

    if (equal(s[l], s[r])) {
      ++l;
      --r;
    } else {
      return false;
    }
  }

  return true;
}