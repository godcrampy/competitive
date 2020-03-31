#include <vector>

using namespace std;

// IMP

int findDuplicateTrivial(vector<int>& nums) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] == nums[i]) {
        return nums[i];
      }
    }
  }
  return -1;
}

int findDuplicate(vector<int>& nums) {
  // see lc solution or nick white
  int slow = nums[0];
  int fast = nums[0];

  slow = nums[slow];
  fast = nums[nums[fast]];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }

  int a = nums[0];
  int b = slow;

  while (a != b) {
    a = nums[a];
    b = nums[b];
  }

  return a;
}