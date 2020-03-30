#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
  if (s.size() == 0) return;

  int l = 0;
  int r = s.size() - 1;

  while (l < r) {
    swap(s[l], s[r]);
    ++l;
    --r;
  }
}