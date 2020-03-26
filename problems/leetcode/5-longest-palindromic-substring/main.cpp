#include <string>

using namespace std;

string longestPalindrome(string s) {
  int max_length = 1;
  int max_length_center = 0;
  int length = s.length();

  if (length == 0) return "";

  for (int i = 0; i < 2 * length + 1; ++i) {
    int l = i / 2 - 1;
    int r = (i + 1) / 2;

    while (l >= 0 && r < length) {
      if (s[l] == s[r]) {
        // still valid
        if ((r - l) + 1 > max_length) {
          max_length = r - l + 1;
          max_length_center = l + r + (1 - i % 2);
        }
      } else
        break;
      --l;
      ++r;
    }
  }

  // return the max length palindrome
  int start = max_length_center / 2 - max_length / 2;
  return s.substr(start, max_length);
}