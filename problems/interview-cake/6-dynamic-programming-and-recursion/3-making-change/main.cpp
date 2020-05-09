#include <iostream>
#include <vector>

using namespace std;

// ! IMP

size_t changePossibilities(int amount, const vector<int>& denominations) {
  // calculate the number of ways to make change
  vector<int> dp(amount + 1, 0);
  dp[0] = 1;

  for (auto d : denominations) {
    for (int i = d; i < dp.size(); ++i) {
      dp[i] += dp[i - d];
    }
  }
  return dp[amount];
}
