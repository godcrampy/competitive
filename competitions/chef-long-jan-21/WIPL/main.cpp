#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll solveRec(ll a, ll b, ll *v, ll i) {
  if (a <= 0 && b <= 0) {
    return 0;
  }

  if (i < 0) {
    return LONG_LONG_MAX;
  }
  ll next = v[i];
  if (a <= 0) {
    --i;
    return 1 + solveRec(a, b - next, v, i);
  }

  if (b <= 0) {
    --i;
    return 1 + solveRec(a - next, b, v, i);
  }

  --i;
  ll x = solveRec(a - next, b, v, i);
  ll y = solveRec(a, b - next, v, i);
  x += x == LONG_LONG_MAX ? 0 : 1;
  y += y == LONG_LONG_MAX ? 0 : 1;

  return min(solveRec(a, b, v, i), min(x, y));
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll h[n];

  for (ll i = 0; i < n; ++i) {
    cin >> h[i];
  }
  sort(h, h + n);

  ll count = solveRec(k, k, h, n - 1);
  deb(count);
  if (count == LONG_LONG_MAX) {
    cout << "-1\n";
  } else {
    cout << count << "\n";
  }
}

int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}