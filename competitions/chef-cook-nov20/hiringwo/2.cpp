#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll k, x;
  cin >> k >> x;

  ll minSum = LONG_LONG_MAX;

  for (int i = 1; i <= x; ++i) {
    if (x % i == 0) {
      minSum = min(minSum, i + (x / i));
    }
  }

  minSum += (k - 2);
  cout << minSum << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
