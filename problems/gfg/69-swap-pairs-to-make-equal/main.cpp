#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;

  vector<int> a(m), b(n);
  unordered_set<int> s;
  long sumA = 0, sumB = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    sumA += a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    sumB += b[i];
    s.insert(b[i]);
  }

  int diff = sumA - sumB;
  if (diff % 2 == 1) {
    cout << -1 << endl;
    return;
  }

  for (int i : a) {
    if (s.find(i - diff / 2) != s.end()) {
      cout << 1 << endl;
      return;
    }
  }

  cout << -1 << endl;
  return;
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
