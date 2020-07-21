#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  unordered_map<char, int> m;  // char, last index found;
  for (char c : s) {
    m[c] = -1;
  }
  int i = 0;  // starting index
  int res = -1;

  for (int j = 0; j < n; ++j) {
    i = max(i, m[s[j]] + 1);
    res = max(res, j - i + 1);
    m[s[j]] = j;
  }

  cout << res << endl;
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
