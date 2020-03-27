#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  if (nums.size() < 4) {
    return {};
  }
  sort(nums.begin(), nums.end());

  set<vector<int>> s;

  for (int i = 0; i < nums.size() - 3; ++i) {
    for (int j = i + 1; j < nums.size() - 2; ++j) {
      int l = j + 1;
      int r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[j] + nums[l] + nums[r];
        if (sum < target) {
          ++l;
        } else if (sum > target) {
          --r;
        } else {
          s.insert({nums[i], nums[j], nums[l], nums[r]});
          ++l;
          --r;
        }
      }
    }
  }

  vector<vector<int>> res(s.begin(), s.end());

  return res;
}