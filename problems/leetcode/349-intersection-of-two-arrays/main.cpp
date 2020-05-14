#include <set>
#include <vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  set<int> m1(nums1.begin(), nums1.end());
  set<int> m2(nums2.begin(), nums2.end());

  vector<int> res;
  for (auto n : m1) {
    if (m2.find(n) != m2.end()) {
      res.push_back(n);
      m2.erase(m2.find(n));
    }
  }

  return res;
}