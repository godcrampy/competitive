#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k1, k2, w, b;
  cin >> n >> k1 >> k2 >> w >> b;

  ll fw = min(k1, k2);
  ll fb = n - max(k1, k2);
  ll mix = abs(k1 - k2);
  mix /= 2;
  if ((fw + mix >= w) && (fb + mix >= b)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
