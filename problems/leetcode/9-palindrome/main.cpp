#include <algorithm>
#include <string>

using namespace std;

bool isPalindrome(int x) {
  if (x < 0) return false;

  string s1 = to_string(x);

  reverse(s1.begin(), s1.end());

  return x == stol(s1);
}