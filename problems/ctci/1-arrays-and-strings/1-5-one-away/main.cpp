#include <iostream>
#include <string>

using namespace std;

bool equal(string &a, int l, string &b, int r) {
  while (l < a.length() && r < b.length()) {
    if (a[l] != b[r]) {
      return false;
    }
    ++l;
    ++r;
  }

  if (l < a.length() || r < b.length()) return false;

  return true;
}

bool oneAway(string &a, string &b) {
  // * Time: O(max(|a|, |b|))
  // * Space: O(1)
  int l = 0, r = 0;
  while (l < a.length() && r < b.length()) {
    if (a[l] == b[r]) {
      ++l;
      ++r;
    } else {
      return equal(a, l + 1, b, r) || equal(a, l, b, r + 1) || equal(a, l + 1, b, r + 1);
    }
  }

  if (abs(l - r) > 1) return false;

  return true;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    cout << oneAway(a, b) << endl;
  }
  return 0;
}
