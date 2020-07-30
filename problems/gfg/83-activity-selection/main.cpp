#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; ++i) {
    // starting time
    cin >> v[i].second;
  }

  for (int i = 0; i < n; ++i) {
    // ending time
    cin >> v[i].first;
  }

  sort(v.begin(), v.end());

  int endingTime = 0;
  int count = 0;

  for (auto p : v) {
    if (p.second >= endingTime) {
      ++count;
      endingTime = p.first;
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
