#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  for (ll i = 0; i < n; ++i) {
    ll count = 0;
    ll l = i - 1, r = i + 1;

    while (l >= 0) {
      if (v[l] > v[i]) break;
      if (v[l] == v[i]) count++;
      --l;
    }

    while (r < n) {
      if (v[r] > v[i]) break;
      if (v[r] == v[i]) count++;
      ++r;
    }

    cout << count << " ";
  }

  cout << "\n";
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
