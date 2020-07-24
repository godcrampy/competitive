import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
  // Complete the maxSubsetSum function below.
  static int maxSubsetSum(int[] arr) {
    int n = arr.length;
    int[] dp = new int[n];
    dp[0] = arr[0];
    dp[1] = Math.max(arr[0], arr[1]);

    for (int i = 2; i < n; ++i) {
      dp[i] = Math.max(dp[i - 2], Math.max(dp[i - 2] + arr[i], Math.max(dp[i - 1], arr[i])));
    }

    return dp[n - 1];
  }
}
