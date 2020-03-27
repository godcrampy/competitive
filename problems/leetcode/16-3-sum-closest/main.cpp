#include <algorithm>
#include <vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
  if (nums.size() < 3) {
    return 0;
  }

  int closest = nums[0] + nums[1] + nums[2];

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; ++i) {
    if (i == 0 || nums[i] != nums[i - 1]) {
      int a = nums[i];
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        if (nums[l] + nums[r] + a < target) {
          // small
          if (abs(nums[l] + nums[r] + a - target) < abs(closest - target)) {
            closest = nums[l] + nums[r] + a;
          }
          ++l;
        } else if (nums[l] + nums[r] + a > target) {
          // big
          if (abs(nums[l] + nums[r] + a - target) < abs(closest - target)) {
            closest = nums[l] + nums[r] + a;
          }
          --r;
        } else {
          // found
          return target;
        }
      }
    }
  }

  return closest;
}