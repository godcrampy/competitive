#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long n, k;
  cin >> n >> k;
  vector<long long> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  auto l = v.begin();
  while (l < v.end()) {
    auto r = min(v.end(), l + k);
    reverse(l, r);
    l += k;
  }

  for (int i : v) {
    cout << i << " ";
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
