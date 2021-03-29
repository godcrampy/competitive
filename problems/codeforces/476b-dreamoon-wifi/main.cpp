#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll nChooseK(ll n, ll k) {
  ll res = 1;

  if (k > n - k) k = n - k;

  for (ll i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }

  return res;
}

void solve() {
  string a, b;
  cin >> a >> b;

  ll target = 0;
  ll x = 0;

  for (char c : a) {
    if (c == '+') ++target;
    if (c == '-') --target;
  }

  for (char c : b) {
    if (c == '+') --target;
    if (c == '-') ++target;
    if (c == '?') ++x;
  }

  target = abs(target);

  if (target > x || (target + x) % 2 != 0) {
    printf("%.12f\n", 0.0);
    return;
  }

  ll k = (target + x) / 2;
  printf("%.12f\n", (double)(nChooseK(x, k)) / (double)(1 << x));
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
