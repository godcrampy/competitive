#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> v(n);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll odd = 0, even = 0;

  for (ll i = 0; i < n; ++i) {
    if (v[i] % 2)
      ++odd;
    else
      ++even;
  }

  for (ll i = 1; i <= x && i <= odd; i += 2) {
    ll evenReq = x - i;
    if (evenReq <= even) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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
