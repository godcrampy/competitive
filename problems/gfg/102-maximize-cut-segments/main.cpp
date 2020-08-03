#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;

  int count = 0;
  vector<int> dp(n + 1, 0);
  if (x <= n) dp[x] = 1;
  if (y <= n) dp[y] = 1;
  if (z <= n) dp[z] = 1;

  for (int i = 0; i <= n; ++i) {
    if (i - x >= 0 && dp[i - x] != 0) {
      dp[i] = max(dp[i], dp[i - x] + 1);
    }
    if (i - y >= 0 && dp[i - y] != 0) {
      dp[i] = max(dp[i], dp[i - y] + 1);
    }
    if (i - z >= 0 && dp[i - z] != 0) {
      dp[i] = max(dp[i], dp[i - z] + 1);
    }
  }

  cout << dp[n] << endl;
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
