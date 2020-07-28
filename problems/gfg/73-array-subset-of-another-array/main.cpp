#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;
  vector<int> a(m), b(n);

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  unordered_map<int, int> ma, mb;

  for (int i : a) {
    ma[i]++;
  }

  for (int i : b) {
    mb[i]++;
  }

  for (auto p : mb) {
    if (ma[p.first] < p.second) {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
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
