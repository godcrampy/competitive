#include <iostream>

using namespace std;

string compressed_string(string& s) {
  string copy = s + s;
  int c = 0, i = 0;
  while (i < s.length()) {
    int j = 1;
    while (i + j < s.length() && s[i] == s[i + j]) {
      ++j;
    }
    copy[c] = s[i];
    copy[c + 1] = j + '0';
    c += 2;
    i += j;
  }
  copy.erase(c);
  if (copy.length() < s.length()) {
    return copy;
  }
  return s;
}

int main() {
  string s = "aabcccccaaa";
  cout << compressed_string(s) << endl;
  return 0;
}
