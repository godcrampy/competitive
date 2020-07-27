#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  int dp[x][y];
  dp[0][0] = 0;
  dp[1][0] = 1;
  dp[0][1] = 1;

  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      if (i + j == 1) continue;
      int val = 0;
      if (i - 1 >= 0) {
        val += dp[i - 1][j];
      }
      if (j - 1 >= 0) {
        val += dp[i][j - 1];
      }
      dp[i][j] = val;
    }
  }

  cout << dp[x - 1][y - 1] << endl;
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
