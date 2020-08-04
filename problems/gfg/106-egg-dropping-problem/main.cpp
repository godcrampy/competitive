#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int eggs, floors;
  cin >> eggs >> floors;

  vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, INT_MAX));

  for (int i = 0; i <= eggs; ++i) {
    dp[i][0] = 0;
    dp[i][1] = 1;
  }

  for (int i = 1; i <= floors; ++i) {
    dp[1][i] = i;
  }

  for (int i = 2; i <= eggs; ++i) {
    for (int j = 2; j <= floors; ++j) {
      for (int tf = 1; tf <= j; ++tf) {
        dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][tf - 1], dp[i][j - tf]));
      }
    }
  }

  cout << dp[eggs][floors] << endl;
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
