#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
  vector<int> dp(nums.size(), 0);
  // dp[i] => maxSubArray for nums[0:i] with last element in the sum
  dp[0] = nums[0];
  int max_sum = dp[0];
  for (int i = 1; i < dp.size(); ++i) {
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    max_sum = max(max_sum, dp[i]);
  }
  return max_sum;
}