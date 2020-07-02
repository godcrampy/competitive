#include <limits.h>

#include <algorithm>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  if (nums.size() == 0) {
    return 0;
  }
  int count = 0;
  int temp = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == temp) {
      nums[i] = INT_MAX;
      ++count;
    } else {
      temp = nums[i];
    }
  }

  sort(nums.begin(), nums.end());

  return nums.size() - count;
}