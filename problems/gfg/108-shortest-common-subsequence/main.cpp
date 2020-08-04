#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  int m = a.length(), n = b.length();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  cout << m + n - dp[m][n] << endl;
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
