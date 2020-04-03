#include <string>

using namespace std;

bool validPalindrome(string s) {
  int l = 0;
  int r = s.length() - 1;
  while (l < r) {
    if (s[l] == s[r]) {
      ++l;
      --r;
    } else {
      return helper(s, l + 1, r) || helper(s, l, r - 1);
    }
  }
  return true;
}

bool helper(string &s, int l, int r) {
  while (l < r) {
    if (s[l] == s[r]) {
      ++l;
      --r;
    } else
      return false;
  }
  return true;
}