#include <iostream>
#include <string>
#include <vector>

using namespace std;

size_t findRotationPoint(const vector<string>& words) {
  // find the rotation point in the array
  int l = 0;
  int r = words.size() - 1;

  while (l < r) {
    int m = l + ((r - l) / 2);
    int next = m < words.size() - 1 ? m + 1 : 0;
    string a = words[m];
    string b = words[next];

    if (a > b) {
      // found breaking point
      return next;
    }

    if (a > words[0]) {
      l = m;
    } else {
      r = m;
    }
  }

  return 0;
}
