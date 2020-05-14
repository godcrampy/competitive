#include <algorithm>
#include <vector>

using namespace std;

// ! IMP

void rotate(vector<int>& nums, int k) {
  k = k % nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}