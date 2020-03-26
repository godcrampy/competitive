#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSumSlow(vector<int>& nums, int target) {
  vector<pair<int, int>> seq(nums.size(), {0, 0});  // <val, index>

  // transform
  for (auto i = nums.begin(); i != nums.end(); ++i) {
    seq[i - nums.begin()] = {*i, i - nums.begin()};
  }

  // sort
  sort(seq.begin(), seq.end());

  // compare
  auto i = seq.begin();
  auto j = seq.end() - 1;

  while ((*i).first + (*j).first != target) {
    if ((*i).first + (*j).first > target) {
      --j;
    } else {
      ++i;
    }
  }

  return {(*i).second, (*j).second};
}

vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> m;  // compliment -> index

  for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];

    if (m.find(nums[i]) != m.end()) {
      // found
      return {m[nums[i]], i};
    }

    // insert
    m.insert({complement, i});
  }

  return {0, 0};
}