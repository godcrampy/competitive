#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll solveRec(ll a, ll b, vector<ll> &v) {
  if (a <= 0 && b <= 0) {
    return 0;
  }

  if (v.empty()) {
    return LONG_LONG_MAX;
  }
  ll next = v.back();
  deb(next);
  if (a <= 0) {
    v.pop_back();
    return 1 + solveRec(a, b - next, v);
  }

  if (b <= 0) {
    v.pop_back();
    return 1 + solveRec(a - next, b, v);
  }

  v.pop_back();
  ll x = solveRec(a - next, b, v);
  ll y = solveRec(a, b - next, v);
  x += x == LONG_LONG_MAX ? 0 : 1;
  y += y == LONG_LONG_MAX ? 0 : 1;

  return min(solveRec(a, b, v), min(x, y));
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n);

  for (ll i = 0; i < n; ++i) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());

  ll count = solveRec(k, k, h);

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