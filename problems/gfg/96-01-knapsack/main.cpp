#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, w;
  cin >> n >> w;
  vector<int> val(n), weights(n);

  for (int i = 0; i < n; ++i) {
    cin >> val[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> weights[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(w + 1));  // [n][w]

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (weights[i - 1] <= j) {
        dp[i][j] =
            max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - weights[i - 1]]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][w] << endl;
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
