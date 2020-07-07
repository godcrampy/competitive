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

  vector<int> leftMax(n), rightMin(n);
  leftMax[0] = v[0];
  rightMin[n - 1] = v[n - 1];

  for (int i = 1; i < n; ++i) {
    leftMax[i] = max(v[i], leftMax[i - 1]);
  }

  for (int i = n - 2; i >= 0; --i) {
    rightMin[i] = min(v[i], rightMin[i + 1]);
  }

  for (int i = 1; i < n - 1; ++i) {
    if (leftMax[i] <= v[i] && rightMin[i] >= v[i]) {
      cout << v[i] << endl;
      return;
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
