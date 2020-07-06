#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long n;
  cin >> n;
  vector<long> v(n), left(n), right(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  left[0] = v[0];
  right[n - 1] = v[n - 1];

  for (int i = 1; i < n; ++i) {
    left[i] = max(v[i], left[i - 1]);
  }

  for (int i = n - 2; i >= 0; --i) {
    right[i] = max(v[i], right[i + 1]);
  }

  long water = 0;

  for (int i = 0; i < n; ++i) {
    water += min(left[i], right[i]) - v[i];
  }
  cout << water << endl;
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
