#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  long long n, k;
  cin >> n >> k;
  vector<long> dp(n, 0);
  dp[0] = 1;
  dp[1] = 1;
  long long sum = 2;
  for (auto i = 2; i < k; ++i) {
    dp[i] = sum;
    sum += dp[i];
    sum %= 1000000007;
  }
  for (auto i = k; i < n; ++i) {
    dp[i] = sum;
    sum += dp[i];
    sum -= dp[i - k];
    sum %= 1000000007;
  }
  cout << dp[n - 1] << endl;
  return 0;
}
