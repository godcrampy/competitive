#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<long, int>> nums(n);  // {bit, size}

  string s;
  long bit = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    bit = 0;
    for (char c : s) {
      bit |= 1L << c - 'a';
    }
    nums[i] = {bit, s.size()};
  }
  int maxSoFar = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((nums[i].first & nums[j].first) == 0) {
        maxSoFar = max(maxSoFar, nums[i].second * nums[j].second);
      }
    }
  }

  cout << maxSoFar << endl;
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
