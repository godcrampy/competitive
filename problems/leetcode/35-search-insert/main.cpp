#include <algorithm>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}