#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll x, r, m;
  cin >> x >> r >> m;
  r *= 60;
  m *= 60;
  if (r <= x) {
    if (r <= m) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else {
    ll timeReq = x + 2 * (r - x);
    if (timeReq <= m) {
      cout << "YES\n";

    } else {
      cout << "NO\n";
    }
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
