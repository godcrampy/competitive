#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long n;
  cin >> n;
  vector<long long> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long m;
  cin >> m;

  sort(v.begin(), v.end());
  long long minDiff = LLONG_MAX;

  for (long i = 0; i + m - 1 < n; ++i) {
    minDiff = min(minDiff, v[i + m - 1] - v[i]);
  }

  cout << minDiff << endl;
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
