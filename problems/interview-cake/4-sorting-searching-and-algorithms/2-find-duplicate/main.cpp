#include <iostream>
#include <vector>

using namespace std;

// ! IMP Binary Search Answer [Needle in Haystack]

unsigned int findRepeat(const vector<unsigned int>& numbers) {
  // find a number that appears more than once
  int l = 1;
  int r = numbers.size() - 1;

  while (l < r) {
    int m = l + ((r - l) / 2);

    int lowerHalfNos = m - l + 1;  // [l, m]

    // check if it's in lower half
    int lowerHalfCount = 0;
    for (int n : numbers) {
      if (n >= l && n <= m) {
        ++lowerHalfCount;
      }
    }

    if (lowerHalfCount > lowerHalfNos) {
      // extra is in lower half
      r = m;
    } else {
      l = m + 1;
    }
  }

  return r;
}
