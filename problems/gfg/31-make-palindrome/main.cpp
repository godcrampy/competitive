#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<vector<int>> dp(n + 1,
                         vector<int>(n + 1, 0));  // dp[i][j] => ans for i to j

  for (int size = 2; size <= n; ++size) {
    for (int i = 0; i < n - size + 1; ++i) {
      // cout << i << endl;
      int j = i + size - 1;
      dp[i][j] =
          s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;
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
