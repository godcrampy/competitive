#include <algorithm>
#include <vector>

using namespace std;

// Using STL algs
vector<int> searchRangeSTL(vector<int>& nums, int target) {
  int i1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  int i2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
  if (binary_search(nums.begin(), nums.end(), target))
    return {i1, i2};
  return {-1, -1};
}

// without stl
vector<int> searchRange(vector<int>& nums, int target) {
  if (nums.size() == 0)
    return {-1, -1};
  int l = 0;
  int r = nums.size() - 1;
  vector<int> result = {-1, -1};
  // find left first
  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      if (mid == 0 || nums[mid - 1] < target) {
        // found
        result[0] = mid;
        break;
      }
      r = mid - 1;
    } else if (nums[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  // find right last
  l = 0;
  r = nums.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      if (mid == nums.size() - 1 || nums[mid + 1] > target) {
        // found
        result[1] = mid;
        break;
      }
      l = mid + 1;
    } else if (nums[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return result;
}