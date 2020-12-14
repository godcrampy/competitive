#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll toggle(ll n, ll k) { return (n ^ (1 << (k - 1))); }

ll leftMostSetBit(ll n) {
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
  if (n == 0) {
    cout << "0\n";
    return;
  }
  if (n == 1) {
    cout << "2\n";
    return;
  }
  ll firstBitDifferentFromLeft = leftMostSetBit(x ^ y);
  ll xK = kthBit(x, firstBitDifferentFromLeft);
  ll yK = kthBit(y, firstBitDifferentFromLeft);
  ll nFirstBitDifferent = leftMostSetBit(n);
  ll count = 0;

  ll str = 0;
  if (xK) {
    ll start = 1 << (min(nFirstBitDifferent, firstBitDifferentFromLeft) - 1);
    for (ll i = start; i <= n; ++i) {
      if ((i ^ x) < (y ^ i)) {
        ++count;
      }
    }
    cout << count << "\n";
    return;
  }

  for (ll i = 1; i < nFirstBitDifferent; ++i) {
    // cout << i << "\n";
    if (i == firstBitDifferentFromLeft) continue;
    if (count == 0) {
      count = 2;
    } else {
      count *= 2;
    }
  }

  ll start = 1 << (nFirstBitDifferent - 1);
  for (ll i = start; i <= n; ++i) {
    if ((i ^ x) < (y ^ i)) {
      ++count;
    }
  }

  cout << count << "\n";
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
