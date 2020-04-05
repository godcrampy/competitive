#include <iostream>
#include <string>

using namespace std;

void urlify(string &s, int n) {
  // * Time: O(|s|)
  // * Space: O(1)
  int l = n - 1;
  int r = s.length() - 1;
  while (l >= 0) {
    if (s[l] != ' ') {
      swap(s[l], s[r]);
      --l;
      --r;
    } else {
      // space
      s[r--] = '0';
      s[r--] = '2';
      s[r--] = '%';
      --l;
    }
  }
}

int main(int argc, char const *argv[]) {
  string s = "Mr John Smith    ";
  urlify(s, 13);
  cout << s << endl;
  return 0;
}
