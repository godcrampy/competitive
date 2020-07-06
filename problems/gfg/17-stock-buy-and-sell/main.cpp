#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  long profit = 0;
  vector<pair<int, int>> res;
  int i = 0;
  while (i < n) {
    int j = i + 1;
    int prev = v[i];
    while (j < n && v[j] >= prev) {
      prev = v[j];
      ++j;
    }
    if (v[j - 1] - v[i] > 0) {
      res.push_back(make_pair(i, j - 1));
      i = j;
    } else {
      ++i;
    }
  }
  if (res.size() == 0) {
    cout << "No Profit" << endl;
  } else {
    for (auto p : res) {
      cout << "(" << p.first << " " << p.second << ")"
           << " ";
    }
    cout << '\n';
  }
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
