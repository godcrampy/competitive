#include <bits/stdc++.h>
#include <string.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll rightmostSet(ll n) {
  ll position = 1;
  ll m = 1;

  while (!(n & m)) {
    // left shift
    m = m << 1;
    position++;
  }
  return position;
}

void solve() {
  ll n, W;
  cin >> n >> W;

  vector<ll> v(64, 0);
  for (ll i = 0; i < n; ++i) {
    ll temp;
    cin >> temp;
    ++v[rightmostSet(temp) - 1];
  }

  vector<ll> size(0);

  for (ll i = 63; i >= 0; --i) {
    ll num = v[i];
    for (ll j = 0; j < num; ++j) {
      ll w = (1 << i);
      ll didFit = false;

      for (ll i = 0; i < size.size(); ++i) {
        if (w <= size[i]) {
          // fit
          size[i] -= w;
          didFit = true;
          break;
        }
      }

      if (!didFit) {
        size.push_back(W - w);
      }
    }
  }

  cout << size.size() << "\n";
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
