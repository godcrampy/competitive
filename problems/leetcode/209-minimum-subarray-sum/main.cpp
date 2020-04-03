#include <limits.h>

#include <algorithm>
#include <vector>

// ! I didn't understand this solution properly

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
  vector<int> sum(nums.size() + 1, 0);
  for (int i = 1; i < sum.size(); ++i) {
    sum[i] = sum[i - 1] + nums[i - 1];
  }

  // sum[i] is the sum of elements from 0 to i - 1
  // sum[j] - sum[i] is the sum of elements from i to j - 1

  int res = INT_MAX;

  for (int i = sum.size() - 1; i >= 0 && sum[i] >= s; --i) {
    int j = upper_bound(sum.begin(), sum.end(), sum[i] - s) - sum.begin();
    res = min(res, i - j + 1);
  }
  return res == INT_MAX ? 0 : res;
}