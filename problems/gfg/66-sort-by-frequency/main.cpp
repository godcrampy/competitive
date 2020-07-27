#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }

  return a.second > b.second;
}

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    m[temp]++;
  }

  vector<pair<int, int>> res(m.begin(), m.end());
  sort(res.begin(), res.end(), compare);

  for (auto p : res) {
    for (int i = 0; i < p.second; ++i) {
      cout << p.first << " ";
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
