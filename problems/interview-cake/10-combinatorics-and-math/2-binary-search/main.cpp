#include <iostream>
#include <vector>

using namespace std;

bool contains(const vector<int>& v, int n) {
  // check if an integer is present in the vector
  int l = 0;
  int r = v.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;

    if (v[m] == n) {
      return true;
    } else if (v[m] > n) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  // return binary_search(v.begin(), v.end(), n);
  return false;
}
