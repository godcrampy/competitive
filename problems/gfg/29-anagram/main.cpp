#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;

  if (a.length() != b.length()) {
    cout << "NO" << endl;
    return;
  }

  unordered_map<char, int> am, bm;

  for (char c : a) {
    am[c]++;
  }

  for (char c : b) {
    bm[c]++;
  }

  if (am.size() != bm.size()) {
    cout << "NO" << endl;
    return;
  }

  for (auto p : am) {
    if (bm[p.first] != p.second) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
