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

  vector<int> dp(n, 1);

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] < v[i]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
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
