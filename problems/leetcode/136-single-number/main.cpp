#include <set>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
  set<int> s;
  for (int n : nums) {
    if (s.find(n) == s.end()) {
      s.insert(n);
    } else {
      s.erase(n);
    }
  }
  return *s.begin();
}