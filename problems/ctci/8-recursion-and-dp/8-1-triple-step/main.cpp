#include <iostream>
#include <vector>

using namespace std;

int number_of_steps(int n) {
  // * Time: O(n)
  // * Space: O(n)
  vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  return dp[n];
}

int main(int argc, char const *argv[]) {
  cout << number_of_steps(5) << endl;
  return 0;
}
