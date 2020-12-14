#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll toggle(ll n, ll k) { return (n ^ (1 << (k - 1))); }

ll rightMostSetBit(ll n) {
  if (n == 0) return 0;

  ll msb = 1;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }

  return msb;
}

void construct(unordered_set<ll> &s, ll nextK, ll fixedK, ll n) {
  if (nextK >= 20) return;
  if (nextK == fixedK) {
    construct(s, nextK + 1, fixedK, n);
    return;
  }
  ll initialSize = s.size();
  for (ll i : s) {
    ll temp = toggle(i, nextK);
    if (temp <= n) {
      s.insert(temp);
    }
  }

  if (initialSize < s.size()) {
    construct(s, nextK + 1, fixedK, n);
  }
}

bool kthBit(ll n, ll k) { return ((n & (1 << (k - 1))) >> (k - 1)); }

void solve() {
  ll x, y, n;
  cin >> x >> y >> n;
  if (x == y) {
    cout << "0\n";
    return;
  }
  ll firstWrong = rightMostSetBit(x ^ y);
  ll xK = kthBit(x, firstWrong);
  ll yK = kthBit(y, firstWrong);
  ll start = 0;
  unordered_set<ll> s;
  if (xK) {
    start = toggle(start, firstWrong);
  }
  if (start > n) {
    cout << "0\n";
    return;
  }
  s.insert(start);
  construct(s, 1, firstWrong, n);
  cout << s.size() << "\n";
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
