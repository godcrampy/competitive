#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<int> dp = v;
  // dp[0] = v[0];
  int maxSum = dp[0];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] < v[i]) {
        dp[i] = max(dp[i], v[i] + dp[j]);
        maxSum = max(maxSum, dp[i]);
      }
    }
  }

  cout << maxSum << endl;
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
