#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; ++i) {
    dp[i] = 1 + min(dp[i - 1], i % 2 == 0 ? dp[i / 2] : INT_MAX);
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
