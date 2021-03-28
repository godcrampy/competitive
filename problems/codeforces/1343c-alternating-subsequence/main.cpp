#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll cmpZero(ll n) {
  if (n < 0) return -1;
  if (n > 0) return 1;
  return 0;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  // sort the buckets
  auto it1 = v.begin();
  auto it2 = v.begin() + 1;

  ll sum = 0;

  while (it1 != v.end()) {
    while (it2 != v.end() && cmpZero(*it1) == cmpZero(*it2)) {
      ++it2;
    }

    sum += *max_element(it1, it2);
    it1 = it2;
  }

  cout << sum << "\n";
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
