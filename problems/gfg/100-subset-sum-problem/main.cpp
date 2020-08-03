#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);

  long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }

  if (sum % 2) {
    cout << "NO" << endl;
    return;
  }
  sum /= 2;

  bool dp[n + 1][sum + 1];

  for (int i = 0; i <= n; ++i) {
    for (int s = 0; s <= sum; ++s) {
      if (s == 0)
        dp[i][s] = true;
      else if (i == 0)
        dp[i][s] = false;
      else if (s >= v[i - 1]) {
        dp[i][s] = dp[i - 1][s] || dp[i - 1][s - v[i - 1]];
      } else {
        dp[i][s] = dp[i - 1][s];
      }
    }
  }

  if (dp[n][sum]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
