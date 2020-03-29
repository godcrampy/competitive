#include <vector>
using namespace std;

// IMP

int search(vector<int>& nums, int target) {
  if (nums.size() == 0) return -1;
  // binary search pivot

  int l = 0;
  int r = nums.size() - 1;

  while (l < r) {
    int mid = (l + r) / 2;

    if (nums[mid] > nums[r]) {
      // pivot belongs to mid + 1 to r
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  int pivot = l;
  l = 0;
  r = nums.size() - 1;

  if (target >= nums[pivot] && target <= nums[r]) {
    l = pivot;
  } else {
    r = pivot - 1;
  }

  // binary search target
  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return -1;
}