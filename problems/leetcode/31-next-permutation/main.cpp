#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// IMP: Case Analysis Algorithm

void nextPermutation(vector<int>& nums) {
  // find first member of last decreasing sequence
  int i = nums.size() - 1;

  if (nums.size() == 0) {
    return;
  }

  while (i != 0 && nums[i - 1] >= nums[i]) {
    i--;
  }

  if (i == 0) {
    // this is the last sequence
    sort(nums.begin(), nums.end());
    return;
  }

  // find first smallest number larger than nums[i - 1] in the decreasing
  // sequence
  int j = nums.size() - 1;

  while (j != 0 && nums[j] <= nums[i - 1]) {
    --j;
  }

  swap(nums[i - 1], nums[j]);

  // reverse the decreasing sequence
  reverse(nums.begin() + i, nums.end());
}