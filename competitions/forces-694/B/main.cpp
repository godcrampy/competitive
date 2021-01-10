#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, x, sum = 0, temp, y;
  cin >> n >> x;
  vector<ll> v(n), u(n, 1);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
    u[i] = 1;
  }

  bool run = true;
  for (ll i = 0; i < v.size(); ++i) {
    // deb2(v[i], u[i]);
    // deb2(i, v[i] * u[i]);
    sum += v[i] * u[i];
    if (run && v[i] % x == 0) {
      v.push_back(v[i] / x);
      u.push_back(x * u[i]);
    } else {
      run = false;
    }
  }

  cout << sum << "\n";
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
