#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  int count = 0;

  int i = 0;
  while (k > 0 && i < n) {
    if (v[i] <= k) {
      k -= v[i];
      ++i;
      ++count;
    } else {
      break;
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
