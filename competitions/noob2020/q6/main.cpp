#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n + 1, 0);
  vector<ll> res(n + 1, 0);

  for (ll i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  for (ll i = 1; i <= n; ++i) {
    if (v[i] <= n) {
      res[i] = v[i] + v[v[i]];
    } else {
      ll k = v[i];
      while (k >= n) {
        k /= 2;
      }
      ll d = n - k;
      res[i] = v[d];
    }
  }

  for (ll i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
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
