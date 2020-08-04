#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }

  int halfSum = sum / 2;
  int dp[n + 1][halfSum + 1];

  for (int i = 0; i <= n; ++i) {
    for (int s = 0; s <= halfSum; ++s) {
      dp[i][s] = 0;
      if (i == 0 || s == 0) continue;
      if (s - v[i - 1] >= 0) {
        dp[i][s] = max(dp[i - 1][s], v[i - 1] + dp[i - 1][s - v[i - 1]]);
      } else {
        dp[i][s] = dp[i - 1][s];
      }
    }
  }

  int diff = sum - 2 * dp[n][halfSum];
  cout << diff << endl;
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
