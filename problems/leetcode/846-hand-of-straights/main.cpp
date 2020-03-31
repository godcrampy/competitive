#include <map>
#include <vector>

using namespace std;

// IMP

bool isNStraightHand(vector<int>& hand, int W) {
  map<int, int> m;

  for (int i : hand) {
    ++m[i];  // if m[i] does not exists, accessing m[i] inserts {i, 0} by default
  }

  while (!m.empty()) {
    int itr = (*m.begin()).first;
    for (int i = 0; i < W; ++i) {
      if (m[itr + i] > 0) {
        // element exists
        --m[itr + i];
        if (m[itr + i] == 0) m.erase(itr + i);
      } else {
        return false;
      }
    }
  }

  return true;
}