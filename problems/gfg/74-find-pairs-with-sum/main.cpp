#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int m, n, target;
  cin >> m >> n >> target;

  vector<int> a(m), b(n);

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  unordered_set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    s.insert(b[i]);
  }

  vector<pair<int, int>> res;
  // bool found = false, first = true;
  for (auto i : a) {
    int compliment = target - i;
    if (s.find(compliment) != s.end()) {
      res.push_back({i, compliment});
    }
  }

  bool first = true;
  sort(res.begin(), res.end());
  for (auto p : res) {
    if (!first) cout << ", ";
    first = false;
    cout << p.first << " " << p.second;
  }

  if (!res.size()) cout << -1;
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
