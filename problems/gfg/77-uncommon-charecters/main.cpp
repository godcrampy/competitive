#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;

  unordered_set<char> sa, sb;

  for (char c : a) {
    sa.insert(c);
  }

  for (char c : b) {
    sb.insert(c);
  }

  set<char> uncommon;

  for (char c : sa) {
    if (sb.find(c) == sb.end()) {
      uncommon.insert(c);
    }
  }

  for (char c : sb) {
    if (sa.find(c) == sa.end()) {
      uncommon.insert(c);
    }
  }

  for (char c : uncommon) {
    cout << c;
  }
  cout << endl;
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
