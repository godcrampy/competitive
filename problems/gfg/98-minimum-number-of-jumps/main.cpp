#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  if (n <= 1) {
    cout << 0 << endl;
    return;
  }

  if (v[0] == 0) {
    cout << -1 << endl;
    return;
  }

  int maxReach = v[0];
  int steps = v[0];
  int jumps = 1;

  for (int i = 1; i < n; ++i) {
    if (i == n - 1) {
      cout << jumps << endl;
      return;
    }

    maxReach = max(maxReach, i + v[i]);
    --steps;
    if (steps == 0) {
      ++jumps;
      if (i >= maxReach) {
        cout << -1 << endl;
        return;
      }
      steps = maxReach - i;
    }
  }
  cout << -1 << endl;
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
