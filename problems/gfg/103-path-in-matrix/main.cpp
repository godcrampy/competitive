#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  int maxVal = 0;

  auto dp = g;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int curr = dp[i][j];
      dp[i][j] = max(dp[i][j], curr + dp[i - 1][j]);

      if (j > 0) {
        dp[i][j] = max(dp[i][j], curr + dp[i - 1][j - 1]);
      }

      if (j < n - 1) {
        dp[i][j] = max(dp[i][j], curr + dp[i - 1][j + 1]);
      }

      maxVal = max(maxVal, dp[i][j]);
    }
  }

  cout << maxVal << endl;
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
