#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;

  vector<int> a1(m), a2(n);

  for (int i = 0; i < m; ++i) {
    cin >> a1[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> a2[i];
  }

  // set of a2
  unordered_set<int> s;
  unordered_map<int, int> um;  // int-> freq
  for (int i : a2) {
    s.insert(i);
    um[i] = 0;
  }

  for (int i : a1) {
    if (s.find(i) != s.end()) {
      um[i]++;
    }
  }

  sort(a1.begin(), a1.end());
  // vector<int> res(m);

  // fill a2 portion
  for (int i : a2) {
    while (um[i]-- > 0) {
      cout << i << " ";
    }
  }

  // fill a1 portion
  for (int i : a1) {
    if (s.find(i) == s.end()) {
      cout << i << " ";
    }
  }
  cout << endl;
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