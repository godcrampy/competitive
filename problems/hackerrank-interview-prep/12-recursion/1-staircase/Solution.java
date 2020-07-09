public class Solution {
  // Complete the stepPerms function below.
  static int stepPerms(int n) {
    long mod = 10000000007L;
    long[] dp = new long[n + 1];

    for (int i = 0; i < dp.length; ++i) {
      dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < dp.length; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (i - j >= 0) {
          dp[i] = (dp[i] + dp[i - j]) % mod;
        }
      }
    }

    return (int) (dp[n] % mod);
  }
}
