#include <iostream>

using namespace std;

bool is_substring(string s, string a) { return s.find(a) != s.npos; }

bool are_strings_rotated(string s1, string s2) {
  string s1s1 = s1 + s1;
  if (s1.length() != s2.length()) {
    return false;
  }
  return is_substring(s1s1, s2);
}

int main() {
  string s = "hacktoberfest", str = "aesthacktober";
  cout << are_strings_rotated(s, str) << endl;
  return 0;
}
