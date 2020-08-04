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

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 0; i < n - 1; ++i) {
    dp[i][i] = v[i];
    dp[i][i + 1] = max(v[i], v[i + 1]);
  }
  dp[n - 1][n - 1] = v[n - 1];

  for (int size = 4; size <= n; size++) {
    for (int i = 0; i < n - size + 1; ++i) {
      int j = i + size - 1;
      dp[i][j] = max(v[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                     v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
    }
  }

  cout << dp[0][n - 1] << endl;
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
