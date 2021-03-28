#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void find(const vector<pair<ll, ll>> &v, ll temp) {
  ll l = 0, r = v.size() - 1;

  while (l <= r) {
    ll m = l + (r - l) / 2;
    ll low = v[m].first;
    ll high = v[m].second;
    if (low <= temp && high >= temp) {
      cout << m + 1 << "\n";
      return;
    } else if (temp < low) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
}

void solve() {
  ll n;
  cin >> n;
  ll temp;
  vector<pair<ll, ll>> v(n);
  ll count = 1;
  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    v[i] = {count, count + temp - 1};
    count += temp;
  }

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    find(v, temp);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
