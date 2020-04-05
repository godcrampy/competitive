#include <iostream>
#include <string>

using namespace std;

int getCount(string s, int i) {
  char c = s[i];
  int count = 0;
  while (s[i] == c) {
    ++i;
    ++count;
  }

  return count;
}

string compress(string &s) {
  // * Time: O(|s|)
  // * Space: O(|s|)
  string res = "";
  int i = 0;
  while (i < s.length()) {
    char c = s[i];
    int count = getCount(s, i);
    res += c;
    res += to_string(count);
    i += count;
  }

  return res.length() < s.length() ? res : s;
}

int main(int argc, char const *argv[]) {
  string s = "aabcccccaaa";
  cout << compress(s) << endl;
  return 0;
}
