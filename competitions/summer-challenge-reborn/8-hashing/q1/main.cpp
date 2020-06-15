#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n), b(n);
  unordered_set<int> store;
  map<int, set<int>> valuesToIndex;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    store.insert(v[i]);
    if (valuesToIndex.find(v[i]) == valuesToIndex.end()) {
      valuesToIndex[v[i]] = {i};
    } else {
      valuesToIndex[v[i]].insert(i);
    }
  }

  // for (auto p : valuesToIndex) {
  //   cout << p.first << " : ";
  //   for (auto i : p.second) {
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (store.find(b[i]) == store.end()) {
      cout << -10099 << endl;
      return;
    }
  }

  long count = 1;
  int j = 0;

  for (int i = 0; i < n; ++i) {
    int target = b[i];

    auto itr = valuesToIndex[target].upper_bound(j);
    if (itr == valuesToIndex[target].end()) {
      // not found
      ++count;
      j = *valuesToIndex[target].begin();
      // cout << "j: " << j << endl;
    } else {
      j = *itr;
    }
  }

  cout << count << endl;
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
