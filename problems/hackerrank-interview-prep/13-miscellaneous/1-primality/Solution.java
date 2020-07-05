public class Solution {
  // Complete the primality function below.
  static String primality(int n) {
    if (n == 2) {
      return "Prime";
    }
    if (n == 1) {
      return "Not prime";
    }
    int sq = (int) Math.sqrt(n) + 1;
    for (int i = 2; i <= sq; ++i) {
      if (n % i == 0) {
        return "Not prime";
      }
    }
    return "Prime";
  }
}
