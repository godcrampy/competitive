#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 998244353;

ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }

ll add(ll x, ll y) { return (x + y + mod) % mod; }

ll binPower(ll x, ll y) {
  ll ans = 1;

  while (y > 0) {
    if (y % 2 == 1) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
    y /= 2;
  }

  return ans;
}
ll divide(ll x, ll y) { return mul(x, binPower(y, mod - 2)); }

void solve() {
  ll n;
  cin >> n;
  vector<ll> fib(n + 1);
  fib[0] = 0;
  fib[1] = 1;
  for (ll i = 2; i <= n; ++i) {
    fib[i] = add(fib[i - 1], fib[i - 2]);
  }

  cout << divide(fib[n], binPower(2, n)) << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
