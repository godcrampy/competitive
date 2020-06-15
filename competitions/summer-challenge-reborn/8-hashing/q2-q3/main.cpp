#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  unordered_map<int, set<int>> m;  // value => {indices}
  int temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    temp;
    if (m.find(temp) == m.end()) {
      m[temp] = {i + 1};
    } else {
      m[temp].insert(i + 1);
    }
  }

  // for (auto p : m) {
  //   cout << p.first << " : ";
  //   for (auto i : p.second) {
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }

  int d, k, l, r;
  for (int i = 0; i < q; ++i) {
    cin >> d >> k >> l >> r;
    if (m.find(d) == m.end()) {
      // not found
      cout << -1 << endl;
    } else {
      set<int> allowedNumbers(m[d].lower_bound(l), m[d].upper_bound(r));
      // cout << "set: ";
      // for (int i : allowedNumbers) {
      //   cout << i << " ";
      // }
      // cout << endl;
      if (allowedNumbers.size() < k) {
        cout << -1 << endl;
      } else {
        auto it = allowedNumbers.begin();
        advance(it, k - 1);
        cout << *it << endl;
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
