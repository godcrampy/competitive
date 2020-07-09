#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
  vector<long> dp(n + 1, 0);
  const long mod = 10000000007;
  dp[0] = 1;
  for (int i = 1; i < dp.size(); ++i) {
    for (int j = 1; j <= 3; ++j) {
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % mod;
      }
    }
  }

  return dp[n] % mod;
}
