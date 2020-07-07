#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  int l = 0;
  int r = 0;

  while (l < s.length()) {
    while (r < s.length() && s[r] != '.') {
      ++r;
    }

    reverse(s.begin() + l, s.begin() + r);
    ++r;
    l = r;
  }

  cout << s << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
