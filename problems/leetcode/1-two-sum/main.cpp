/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<int, int> find_sum(vector<int>& nums, int target) {
  map<int, int> m;
  for (int i = 0; i < nums.size(); ++i) {
    int c = target - nums[i];
    if (m.find(c) != m.end()) {
      // pair found
      return {m[c], i};
    }
    m.insert({nums[i], i});
  }
  return {-1, -1};
}

int main(int argc, char const* argv[]) {
  vector<int> vec = {7, 21, 2, 15};
  cout << find_sum(vec, 9).first << " " << find_sum(vec, 9).second << endl;
  return 0;
}
