#include <bits/stdc++.h>

using namespace std;

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
  int n = arr.size();
  vector<int> dp(n);
  dp[0] = arr[0];
  dp[1] = max(arr[0], arr[1]);

  for (int i = 2; i < n; ++i) {
    dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 2], max(dp[i - 1], arr[i])));
  }

  return dp[n - 1];
}
