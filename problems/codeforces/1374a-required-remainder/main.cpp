#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long long x, y, n;
  cin >> x >> y >> n;
  long long k = n - n % x + y;
  if (k > n) {
    k -= x;
  }
  cout << k << '\n';
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
