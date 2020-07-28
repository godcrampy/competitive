#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int temp;

  unordered_set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    s.insert(temp);
  }

  int maxLen = -1;
  for (int i : s) {
    if (s.find(i - 1) == s.end()) {
      // this is the first guy
      int j = i;
      int size = 0;
      while (s.find(j) != s.end()) {
        ++j;
        ++size;
      }
      maxLen = max(maxLen, size);
    }
  }

  cout << maxLen << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
