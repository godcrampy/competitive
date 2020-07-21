#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
void solve() {
  string a, b;
  cin >> a >> b;
  int m = a.length();
  int n = b.length();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1));
  int res = 0;

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          res = max(res, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }
  }

  cout << res << endl;
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
