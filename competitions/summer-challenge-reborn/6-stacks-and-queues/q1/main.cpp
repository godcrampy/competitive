#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> start(n), fin(n);
  unordered_set<int> bad;

  for (int i = 0; i < n; ++i) {
    cin >> start[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> fin[i];
  }

  auto l = start.begin();
  auto r = fin.begin();

  while (l != start.end() && r != fin.end()) {
    if (*l == *r) {
      // cout << "same: " << *l << " " << *r << endl;
      ++l;
      ++r;
      continue;
    }
    // numbers are different
    // cout << "diff: " << *l << " " << *r << endl;

    if (bad.find(*l) == bad.end()) {
      // cout << "not in set" << endl;

      // *r is not in set as well => insert in bad
      bad.insert(*r);
      ++r;
      // ++l;
    } else {
      // cout << "in set" << endl;
      // *r is in set
      ++l;
    }
  }

  cout << bad.size() << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
