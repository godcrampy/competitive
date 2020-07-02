#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  if (nums.size() < 3) {
    return {};
  }

  set<vector<int>> s;  // to remove duplicates

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; ++i) {
    if (i == 0 || nums[i] != nums[i - 1]) {
      int a = nums[i];
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        if (nums[l] + nums[r] + a < 0) {
          // small
          ++l;
        } else if (nums[l] + nums[r] + a > 0) {
          // big
          --r;
        } else {
          // found
          s.insert({a, nums[l], nums[r]});
          ++l;
          --r;
        }
      }
    }
  }

  vector<vector<int>> res(s.begin(), s.end());

  return res;
}