#include <limits.h>

#include <algorithm>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  if (nums.size() == 0) {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == val) {
      nums[i] = INT_MAX;
      ++count;
    }
  }

  sort(nums.begin(), nums.end());

  return nums.size() - count;
}